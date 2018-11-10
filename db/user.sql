create table user(
    user_no int unsigned not null AUTO_INCREMENT,
    id varchar(10) not null,
    password varchar(16) not null,
    nickname varchar(30) not null,
    favteam_no tinyint unsigned not null default 0,
    favplayer_no int unsigned not null default 0,
    primary key (user_no)
);
