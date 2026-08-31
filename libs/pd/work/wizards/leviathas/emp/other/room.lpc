// ::Inferno(11/11/00);    I'll admit: I had help from Seeker ;)
// This replaces /std/room.c in the emp.h header file.
// This file makes sure you look at all items in the room before you exit.
#include <std.h>
inherit ROOM;

mapping all_looks = ([ ]);

void create() {
 ::create();
}

int check_look(string str) {
   if (!str) return 0;  
   if (this_object()->id(str))
    if (!all_looks[this_player()->query_name()])
      all_looks[this_player()->query_name()] = ({ "sky", "blue moon", "sun",
         "moons", "moon", "laros", "green moon", "spyefel", "slayar", "red moon",
          str });
    else
      all_looks[this_player()->query_name()] += ({ str });
   return 0;
}


mapping query_all() { return all_looks; }
void init() {
 ::init();
   add_action("check_look", "look");
}

int use_exit()
{
 int i;
 string *str, *b;

 i = sizeof(str = this_object()->query_id());
 while(i--)
  {
   if (!(b = all_looks[this_player()->query_name()])) return 1;
   if (member_array(str[i], b)==-1)  return 1;
  }
 return ::use_exit();
}
