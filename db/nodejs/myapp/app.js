var express = require('express');
var app=express();

app.get('/',function(req,res){
    res.send("Hello home page");
    
});


app.get('/login',function(req,res){
    res.send("Login please");
});


app.listen(8000,function(){
    console.log("Connected 8000 port!");
});
