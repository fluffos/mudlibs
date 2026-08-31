#include <std.h>
inherit OBJECT;

int windows;

string check_windows();
void check_long();
int init_limo(string str);

string check_windows() {
   string str="The windows are rolled ";
   if (!windows) str += "up.";
   else str += "down.";
   return str;
}

void create() {
 ::init();
   set_name("limo");
   set_short("a long black limo");
   set_long("The long black limo has shaded windows. "+check_windows()+
      " The limo looks very expensive.");
   set_value(0);
}

void check_long() {
   set_long("The long black limo has shaded windows. "+check_windows()+
      " The limo looks very expensive.");
}

int get() { return 0; }

int init_limo(string str) {
   object ob;
   if (!str || str != "limo") return 0;
   ob = (object)"/wizards/inferno/room/limo_room";
   write(ob->query_short());
   return 1;
}

void init() {
 ::init();
   add_action("init_limo", "start");
}
