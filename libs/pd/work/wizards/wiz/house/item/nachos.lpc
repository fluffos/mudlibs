#include <wiz.h>
inherit OBJECT;

string query_type() { return "food"; }

void init(){::init(); add_action("yummy","eat"); }

int yummy(string str) {
   if(!id(str)) return 0;
   if(environment(this_object()) != this_player()) {
      notify_fail("Get the nachos first.");
      return 0;
   }
      if(!this_player()->add_stuffed(this_player()->query_level())) {
         notify_fail("You are too full to eat that!");
         return 0;
      }
   this_player()->heal((this_player()->query_level())/2);
   write("mmmmm Nachos.....\n"
         "you spill a little cheese as you munch on your nachos.");
   say(this_player()->query_cap_name()+" spills some cheese off "+
       this_player()->query_title_gender()+" nachos.",
        this_player());
   remove();
   return 1;
}
