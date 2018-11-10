create table player_images(
    player_no int unsigned not null,
    data mediumblob,
    foreign key(player_no) references player(player_no) on delete cascade
);
