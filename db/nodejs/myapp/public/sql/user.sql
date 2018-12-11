create table user(
    user_no int unsigned not null AUTO_INCREMENT,
    id varchar(30) not null,
    password varchar(60) not null,
    nickname varchar(30) not null,
    desc_no int unsigned not null default 0,
    favteam_no tinyint unsigned not null default 0,
    favplayer_no int unsigned not null default 0,
    primary key (user_no)
) DEFAULT CHARSET=utf8;
