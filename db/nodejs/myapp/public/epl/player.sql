create table player(
    player_no int unsigned not null AUTO_INCREMENT,
    team_no tinyint unsigned not null,
    back_no tinyint unsigned not null,
    name_en varchar(60) not null,
    name_kr varchar(60) not null,
    country varchar(30) not null,
    birthday varchar(30) not null,
    like_no int not null default 0,
    position varchar(20) not null,
    height int not null default 0,
    weight int not null default 0,
    primary key (player_no),
    foreign key (team_no) references team(team_no) on delete cascade
) DEFAULT CHARSET=utf8;
