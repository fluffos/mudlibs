drop table if exists saveload;
create table saveload (
    oid   int(12) not null,
    data  mediumtext,
    primary key (oid)
);
