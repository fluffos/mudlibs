
create database mud;
use mud;


create table tmp_player (
id varchar(10) not null,
name varchar(12) binary not null,
email varchar(50),
dtime datetime,
station char(3) not null,
primary key (id),
unique index (name));

create table reg_player (
id varchar(10) not null,
name varchar(12) binary not null,
email varchar(50) not null,
station char(3) not null,
primary key (id),
unique index (name),
unique index (email));

create table pawn_tb (
id varchar(10) not null,
obj varchar(40) not null,
ptime int not null,
pshop varchar(30) not null,
pstamp text not null,
index (id),
index (ptime));

create table fail_cmds (
station varchar(15) not null,
cmd text not null,
index (station));
