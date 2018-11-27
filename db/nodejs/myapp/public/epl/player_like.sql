create table player_like(
    player_no int unsigned not null,
    nickname varchar(30) not null,
    user_no int unsigned not null,
    time DATETIME default current_timestamp on update current_timestamp,
    foreign key(player_no) references player(player_no) on delete cascade,
    foreign key(user_no) references user(user_no) on delete cascade
) DEFAULT CHARSET=utf8;

