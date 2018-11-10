create table team_images(
    team_no tinyint unsigned not null,
    image mediumblob,
    foreign key(team_no) references team(team_no) on delete cascade
);

