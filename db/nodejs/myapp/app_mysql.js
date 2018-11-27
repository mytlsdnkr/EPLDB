var express=require('express');
//var multer=require("multer");
var mysql=require('mysql');
var app=express();
var cookieParser=require('cookie-parser');
var bodyparser=require("body-parser");
var session = require('express-session');
var MySQLStore = require('express-mysql-session')(session);
var connection = mysql.createConnection({
    host : 'localhost',
    user : 'park',
    password : 'cjswo9488',
    database : 'epldb',
    port : 3306

});
connection.connect();

app.use(bodyparser.urlencoded({extended:false}));
app.use(express.static('public'));
app.use(cookieParser());

var options = {
	host	: 'localhost',
	port	: 3306,
	user	: 'park',
	password: 'cjswo9488',		//데이터베이스 접근 비밀번호
	database: 'epldb'		//데이터베이스의 이름
};
var sessionStore = new MySQLStore(options);

app.use(session({
	secret: '12sdfwerwersdfserwerwef', //keboard cat (랜덤한 값)
	resave: false,
	saveUninitialized: true,
    maxAge: 20000,
	store: sessionStore
}));

var sqlforfresh='select * from user where user_no=? '
app.locals.pretty=true;
app.set('views','./epl');//template 엔진 사용
app.set('view engine','jade');//template엔진으로 jade 사용

app.get("/",function(req,res){
    var sql='set global validate_password_policy=low';
    connection.query(sql,function(err,rows,fields){
        if(!err){

            res.render('welcome');
        }else{
            console.log(err);
        }
        
    })

})
app.get('/register',function(req,res){
    res.render('register');
})
app.get('/password_check',function(req,res){
    res.render('passwordconfirm');


})


app.get('/idcheck',function(req,res){
    res.render('idcheck')
});

app.post('/idcheck',function(req,res){
    var id=req.body.id;
    var sql='select * from user';
    var existed=0;

    connection.query(sql,function(err,rows,fields){
        if(err){
            console.log(err);
        }
        for(var i=0;i<rows.length;i++){
            if(rows[i].id==id){
                existed=1;
            }
        }
        if(existed==1){
            res.render("idcheck",{id:id,msg:"다른아이디를 사용하세요."})
        }else{
            res.render("idcheck",{id:id,isOk:existed,msg:'사용 가능한 아이디입니다.'})
        }
    })
})
app.get('/team',function(req,res){
    sess=req.session;

    if(sess.nickname){

        var sql='select team_name_en from team';

        connection.query(sql,function(err,rows,fields){
            if(!err){
                var sqlforfresh='select * from user where user_no=? '
                connection.query(sqlforfresh,[sess.user_no],function(errforfresh,rowsforfresh,fieldsforfresh){
                    if(!errforfresh){
                        sess=req.session;
                        sess.favteam_no=rowsforfresh[0].favteam_no;
                        sess.favplayer_no=rowsforfresh[0].favplayer_no;
                        sess.desc_no=rowsforfresh[0].desc_no;

                         var space=" ";
                         res.render('team',{sess:sess,space:space,team_name_en:rows[0].team_name_en});
                    }else{
                        console.log("this is errforfresh:"+errforfresh);
                    }
                })

            }
            else{
                console.log(err);
            }

        })
    }else{
        res.redirect('/');
    }

})

app.get('/logout',function(req,res){

    req.session.destroy(function(err){
        if(err){
            console.log(err);
        }else{
            delete req.session;
            res.clearCookie('epldb');
            res.redirect('/');
        }
    })
    }
)

app.get('/team/:id',function(req,res){
    sess=req.session;
    if(sess.nickname){

        var i=0;
        var name_en=new Array();
        var sql='select * from team where team_no=?';
        var sql1='select name_en from player where team_no=?';
        var sql2='select user_no,description,time,nickname from team_comment where team_no=? order by time DESC';
        var length;
        var space=" ";
        connection.query(sql1,[req.params.id],function(err,rows1,fields){
            if(!err){
                for(i=0;i<rows1.length;i++){
                    name_en[i]=rows1[i].name_en;
                }
                length=rows1.length;


                connection.query(sql,[req.params.id],function(err1,teaminfo,fields){
                    if(!err1){
                        connection.query(sql2,[req.params.id],function(err2,descriptioninfo,fields){
                        if(!err2){
                            var sqlforfresh='select * from user where user_no=?'; 
                            connection.query(sqlforfresh,[sess.user_no],function(errforfresh,rowsforfresh,fieldsforfresh){
                            if(!errforfresh){
                                sess=req.session;
                                sess.favteam_no=rowsforfresh[0].favteam_no;
                                sess.favplayer_no=rowsforfresh[0].favplayer_no;
                                sess.desc_no=rowsforfresh[0].desc_no;
                                resultlen=descriptioninfo.length;
                                res.render('teaminfo',{length:length,space:space,sess:sess,teaminfo:teaminfo[0],descriptioninfo:descriptioninfo,resultlen:resultlen,i:req.params.id,name_en:name_en});
                        }else{
                            console.log("this is errforfresh:"+errforfresh);
                        } 
                            })




                    }else{
                        console.log("this is err2:"+err2);
                    }
                })


            }else{
                console.log("this is err1:"+err1);
            }
        })


            

       
    }else{
        console.log("this is err:"+err);
    }
        })
    
    }else{
        res.redirect('/');

    }
})
        

        
app.post('/team/:id',function(req,res){
    sess=req.session;
    if(sess.nickname){
        if(req.body.reply){

        var description=req.body.reply;
        var team_no=req.params.id;

        var sql='insert into team_comment (team_no,user_no,description,nickname) values (?,?,?,?)';

        connection.query(sql,[team_no,sess.user_no,description,sess.nickname],function(err,rows,fields){
            if(!err){
                console.log(sess.nickname+"님이 댓글을 달았습니다.");
                var sql1='update user set desc_no=desc_no+1 where user_no=?';
                    connection.query(sql1,[sess.user_no],function(err1,rows1,fields){
                        if(err1){
                            console.log(err);
                        }else{
                            res.redirect('/team/'+team_no);
                            sess=req.session;
                            sess.desc_no++;
                            console.log(sess.nickname+"님의 댓글 개수가 업데이트 되었습니다.");
                        }
                    });

            }else{
                console.log(err);
            }
        })
        }else{
            var like=req.body.like;
            var team_no=req.params.id;
            var sql='insert into team_like(team_no,user_no,nickname) values(?,?,?)';
            connection.query(sql,[team_no,sess.user_no,sess.nickname],function(err,rows,fields){
                if(!err){
                    var sql1='update team set like_no=like_no+1 where team_no=?';
                    connection.query(sql1,[team_no],function(err1,row1,fields1){
                        if(!err1){

                            console.log(sess.nickname+"님이 좋아요를 눌렀습니다.");
                            var sql2='update user set favteam_no=favteam_no+1 where user_no=?';
                            connection.query(sql2,[sess.user_no],function(err2,rows2,fields){
                        if(!err2){
                            res.redirect('/team/'+team_no);
                            sess=req.session;
                            sess.favteam_no++;
                            console.log(sess.nickname+"님의 팀 좋아요 개수가 업데이트 되었습니다.");
                        }else{
                            console.log(err2);
                        }
                    })
                        }else{
                            console.log(err1);
                        }
                    })
                }else{
                    console.log(err);
                }
            })

        }


    }else{
        res.redirect('/');
    }

})

app.post('/:team_no/player/:id',function(req,res){
    sess=req.session;
    if(sess.nickname){
        if(req.body.reply){

        var description=req.body.reply;
        var team_no=req.params.id;

        var sql='insert into player_comment (player_no,user_no,description,nickname) values (?,?,?,?)';

        connection.query(sql,[req.params.id,sess.user_no,description,sess.nickname],function(err,rows,fields){
            if(!err){
                console.log(sess.nickname+"님이 댓글을 달았습니다.");
                var sql1='update user set desc_no=desc_no_1 where user_no=?';
                    connection.query(sql1,[sess.user_no],function(err1,rows1,fields){
                        if(err1){
                            console.log(err);
                        }else{
                            res.redirect('/'+team_no+'/player/'+req.params.id);
                            sess=req.session;
                            sess.desc_no++;
                            console.log(sess.nickname+"님의 댓글 개수가 업데이트 되었습니다.");
                        }
                    });

            }else{
                console.log(err);
            }
        })
        }else{
            var team_no=req.params.id;
            var sql='insert into player_like(player_no,user_no,nickname) values(?,?,?)';
            connection.query(sql,[team_no,sess.user_no,sess.nickname],function(err,rows,fields){
                if(!err){
                    var sql1='update player set like_no=like_no+1 where player_no=?';
                    connection.query(sql1,[req.params.id],function(err1,rows1,fields){
                        if(!err1){

                            console.log(sess.nickname+"님이 좋아요를 눌렀습니다.");
                            var sql2='update user set favplayer_no=favplayer_no+1 where user_no=?';
                            connection.query(sql2,[sess.user_no],function(err2,rows2,fields){
                        if(!err2){
                            res.redirect('/'+team_no+'/player/'+req.params.id);
                            sess=req.session;
                            console.log(sess.nickname+"님의 좋아요 개수가 업데이트 되었습니다.");
                        }else{
                            console.log("this is err2:"+err2);
                        }
                    })
                        }else{
                            console.log("this is err1:"+err1);
                        }



                    })
                }else{
                    console.log("this is err:"+err);
                }
            })

        }


    }else{
        res.redirect('/');
    }

})
app.get('/:team_no/player/:id',function(req,res){
        sess=req.session;
    if(sess.nickname){
        var resultlen;

        var team_name_kr;
        var sql='select player_no from player where team_no=?';
        var sql1='select * from player where player_no=?';
        var sql2='select team_name_kr from team where team_no=?';
        var sql3='select user_no,description,time,nickname from player_comment where player_no=? order by time DESC';
        var space=" ";
        connection.query(sql,[req.params.team_no],function(err4,player_no,fiels){
            if(!err4){
                var id;
                var player_len=player_no.length;
                var startplayer_no=player_no[0].player_no;
                var lastplayer_no=startplayer_no+player_len;
                var paramid=req.params.id;
                paramid*=1;
                id=startplayer_no+paramid-1;
        connection.query(sql1,[id],function(err,rows,fields){
            if(!err){
                connection.query(sql2,[req.params.team_no],function(err1,rows1,fields){
                    if(!err1){
                        team_name_kr=rows1[0].team_name_kr
                        connection.query(sql3,[id],function(err2,descinfo,fields){
                            if(!err2){
                var sqlforfresh='select * from user where user_no=? '
                connection.query(sqlforfresh,[sess.user_no],function(errforfresh,rowsforfresh,fieldsforfresh){
                    if(!errforfresh){
                        sess=req.session;
                        sess.favteam_no=rowsforfresh[0].favteam_no;
                        sess.favplayer_no=rowsforfresh[0].favplayer_no;
                        sess.desc_no=rowsforfresh[0].desc_no;
                        resultlen=descinfo.length;
                        res.render('playerinfo',{startplayer_no:startplayer_no,player_len:player_len,team_no:req.params.team_no,i:req.params.id,space:space,sess:sess,playerinfo:rows,team_name_kr:team_name_kr,descinfo:descinfo,resultlen:resultlen})

                    }else{

                        console.log("this is errforfresh:"+errforfresh);

                    }
                })
                               
                            
                            }else{

                                console.log("this is err2:"+err2);
                            }
                        })

                    }else{
                                console.log("this is err1:"+err1);
                    }
                })
                
            }else{
                console.log("this is err:"+err);
            }

            })
            }else{

                console.log("this is err4:"+err4);
            }
          
            
        })
    }else{
        res.redirect("/");
    } 
        
    
})
app.get("/login",function(req,res){

        res.redirect("/team");


    })
app.post("/login",function(req,res){
    var id=req.body.id;
    var password=req.body.password;
    var sql='select * from user where password=password(?)';
    var existed=0;
    var nickname='';
    var i;

    connection.query(sql,[password],function(err,rows,fields){
        if(!err){

        for(i=0;i<rows.length;i++){
            if(rows[i].id==id){
                existed=1;
                sess=req.session;
                sess.nickname=rows[i].nickname;
                sess.id=id;
                sess.user_no=rows[i].user_no;
                sess.favteam_no=rows[i].favteam_no;
                sess.favplayer_no=rows[i].favplayer_no;
                sess.desc_no=rows[i].desc_no;
                res.redirect("/team");
            }else{
                res.redirect('/');
            }
        }
        }else{
            console.log(err);
        }



        


    })


})
app.post("/register",function(req,res){
    var nickname=req.body.nickname;
    var id=req.body.id;
    var password=req.body.password;

    var sql='INSERT INTO user (nickname,id,password) values (?,?,password(?))';

    if(id && password && nickname){
        connection.query(sql,[nickname,id,password],function(err,rows,fields){
            if(err){
                console.log(err);
            }else{
                res.render('welcome',{id:id,msg:"로그인 하세요"});
                console.log(nickname+"님이 새로 가입했습니다.");
            }
        })
    }

})





app.listen(3000,function(){
    console.log("Connected 3000 port");
})


