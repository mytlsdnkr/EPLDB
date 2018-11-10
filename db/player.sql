create table player(
    player_no int unsigned not null AUTO_INCREMENT,
    team_no tinyint unsigned not null,
    name_en varchar(30) not null,
    name_kr varchar(30) not null,
    country_en varchar(20) not null,
    country_kr varchar(20) not null,
    birthday date not null,
    like_no int not null default 0,
    height tinyint not null,
    weight tinyint not null,
    primary key (player_no),
    foreign key (team_no) references team(team_no) on delete cascade
);
