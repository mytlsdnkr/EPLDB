create table team(
    team_no tinyint unsigned not null AUTO_INCREMENT,
    comment_no int unsigned not null default 0,
    team_name_en varchar(30) not null,
    team_name_kr varchar(15) not null,
    manager_en varchar(20) not null,
    manager_kr varchar(20) not null,
    like_no int unsigned not null default 0,
    primary key(team_no)
);
