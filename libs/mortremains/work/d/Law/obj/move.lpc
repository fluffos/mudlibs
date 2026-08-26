#include <mudlib.h>

inherit OBJECT;


void create() {
   set("prevent_get", 1);
   set("prevent_insert", 1);
   set("prevent_clean", 1);
   set("prevent_drop", 1);
   set("prevent_give", 1);
   set("no_clean", 1);
}
void init() {
   add_action("go", "go");
}

int go(string str){
   if (str == "west") {
     write("Your feet get confused!\n");
     move(TP->("east"));
   return 1;
}
if (str == "east") {
     write("Your feet get confused!\n");
     TP->move("north");
   return 1;
 }
if (str == "northwest") {
     write("Your feet get confused!\n");
     TP->move("south");
   return 1;
 }
return 1;
}
