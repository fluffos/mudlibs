// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

string *course_list = COURSES;
inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Chronos's School of Coding and Assorted Magicks.");
  set("long", @ENDLONG
You stand in a grand hall in the center of Chronos's School of Coding and
Assorted Magicks.
A sign adorns a wall here, catching your eye.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  ]) );
  set("item_desc", ([
    "sign" : "You could maybe even read it if you tried.\n",
  ]) );
  ::create();
}

void init() {
  add_action("list", "list") ;
  add_action("read", "read");
  add_action("evaluate", "evaluate") ;
}

int read(string str) {
  if (!str) {
    write("Read what?\n");
    return 1;
  }
  if (str != "sign") write("You feel compelled to read the sign instead..\n");
  write(@ENDSIGN
You read:

        Welcome to Chronos's School of Coding and Assorted Magicks.

                  -      ---------------------     -

        We have many courses available, both for the utmost novice and
        seasoned coders alike.

        Commands here are as follows:
        ---------------------------------------------------------------
        evaluate            - Have your training record evaluateuated.

ENDSIGN
  );
  say(TPN+" stares intently at the sign on the wall for a moment.\n");
  return 1;
}

int evaluate(string str) {
  string * courses;
  int i,x,y;
  write("You feel as though you are being thoroughly examined..\n");
  x = (int)TP->query("csCam");
  if (!x || x == 0) {
    write("You haven't completed any courses here yet!\n");
    return 1;
  }
  i = MAX_COURSE_NUM ;
  while(i!=0) {
    if (x>=i) {
   courses += ({ course_list[y] }) ;
      x = x - i ;
    }
    y++;
    i = i / 2 ;
  }
  for (y=0;y<sizeof(courses);y++) {
    write ("You have completed '"+courses[y]+"'.\n") ;
  }
  return 1;
}

int list(string str) {
  int i;
  write("The following courses are available right now:\n\n") ;
  for (i=0;i<sizeof(COURSES);i++)
    write("  - "+(i+1)+" - "+COURSES[i]+"\n");
  return 1;
}
  


