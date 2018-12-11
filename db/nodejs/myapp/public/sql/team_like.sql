create table team_like(
    team_no tinyint unsigned not null,
    nickname varchar(30) not null,
    user_no int unsigned not null,
    time DATETIME default current_timestamp on update current_timestamp,
    foreign key(team_no) references team(team_no) on delete cascade,
    foreign key(user_no) references user(user_no) on delete cascade
) DEFAULT CHARSET=utf8;

