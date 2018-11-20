create table team_comment(
    team_no tinyint unsigned not null,
    user_no int unsigned not null,
    description text(300) not null,
    time DATETIME default current_timestamp on update current_timestamp,
    foreign key(team_no) references team(team_no) on delete cascade,
    foreign key(user_no) references user(user_no) on delete cascade
);
