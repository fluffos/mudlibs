#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
   set("short", "The Slums");
  set("long", @ENDTEXT
You enter a large alley inbetween two poorly maintained
buildings.  You see about 30 to 40 poor slobish smelly
degenerates and as soon as you enter they all rush up to you
begging for you to spare them a few coins.  
ENDTEXT
);
  set( "exits", ([
 "town" : START,
/*to all wizzes and (admin)s, this is my first room and*/
/* i dont know where it might go, but you might be able*/
/*to find a place.  I suggest that it goes into a spot*/
/*that is untaken in the "hive ward" such as a section*/
/*where no n or s exits exist.  also if you have a correction*/
/*suggestion, etc tell me!!!*/
  ]) );
  set("item_desc", ([
 ]) );
}


