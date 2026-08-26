#include <mudlib.h>
#include <config.h>

inherit PRIVATE_ROOM;

void create() {
  ::create();
  seteuid(getuid());

  set("short", "Blood's domain");

  set("c_long", @EndLong
This room belongs to blood, whom you think might be nuts
computers, disks cdroms, hard drives, and every other component 
that has to do with computers and is known to man and some unknown
ly scattered about the room wherever there is space
Alarge oak desk finely carved with gold trim sits at the back wall
and a comfortable bed that looks like it hasn't been used once is to the left of it
a sign whirls around the room in techno color saying
if you don't belong here get the fuck out!
thats it.
EndLong
   );
  set("exits", ([
    "void" : VOID,
    "start" : START,
  ]) );
}


void init() {
  ::init();    //This is VERY important!
}
