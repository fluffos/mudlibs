#
# User groups, for distribution lists
#
drop table if exists list;
create table list (
   lid int(10) not null auto_increment,
   name tinytext,
   primary key (lid)
);

## Group for all mud administration
insert into list values(NULL,"admin");

## Group for all mud wizards (admin and non-admin)
insert into list values(NULL,"wizards");

# Also a dummy group, 'all' that mails everyone, but
# may only be mailed to by members of 'admin'

#
# Connects users to groups they are subscribed to
#
drop table if exists subscription;
create table subscription (
   uid int(10),
   lid int(10)
);

#
# An actual mail message (or im or memo...)
#
drop table if exists message;
create table message (
   id int(10) not null auto_increment,
   uid int(10),
   folder set("inbox","im","memo","saved","trash"),
   status set("new","unread","read","replied","deleted"),
   sid int(10),   # uid of sender
   sent datetime, # time the message was sent
   subject tinytext,
   body text,     # body of message
   primary key (id)
);
