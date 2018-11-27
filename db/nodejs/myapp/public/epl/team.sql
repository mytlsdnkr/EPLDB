create table team(
    team_no tinyint unsigned not null AUTO_INCREMENT,
    comment_no int unsigned not null default 0,
    team_name_en varchar(50) not null,
    team_name_kr varchar(50) not null,
    manager_en varchar(50) not null,
    manager_kr varchar(50) not null,
    stadium varchar(50) not null,
    win_no tinyint not null default 0,
    like_no int unsigned not null default 0,
    primary key(team_no)
) DEFAULT CHARSET=utf8;
