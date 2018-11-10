var express = require('express');

var app=express();
app.set('view engine','jade');
app.set('views','./views');


app.use(express.static('public'));

app.get('/',function(req,res){


    res.send('<h1> Welcome to EPL DB </h1> <br></br> <body><img src="/logo.png"></body>');


});

app.get("/dynamic",function(req,res){
    var time=Date();
    var lis='';

    for(var i=0;i<5;i++){
        lis=lis+'<li>coding</li>';
    }

    
    var output=`<!DOCTYPE html>
        <html>
        <head>
        <meta charset="utf-8">
        <title></title>
        </head>
        <body>
        Hello,Dynamic!
        <ul>
        ${lis}
    </ul>

        ${time}
        </body>
        </html>`;
    res.send(output);
});
app.get("/login",function(req,res){
    res.send("Login please");
});


app.listen(3000,function(){
    console.log("connected 3000 port!");
});
