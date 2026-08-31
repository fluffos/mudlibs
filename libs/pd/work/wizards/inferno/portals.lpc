#include <std.h>
inherit ROOM;

void create() {
 object ob;
 ::create();
   set_property("no teleport", 1);
   set_short("Inferno's Hall of Portals");
   set_long(
     "You are in a circular tower-like room leading both up and down. "
     "Many portals and rifts shimmer in and out of existance all around "
     "you. The walls are made of a dull black stone, that does not seem "
     "to reflect light."
   );
   set_items(([
     ({ "rift", "rifts", "portal", "portals" }) :
        "There are many different rifts and portals. <hall [class_type]> "
        "will take you to a class hall in Sindarii. <town [town_name]> "
        "will take you to the square of a listed town. If a town is not "
        "listed, please tell Inferno so it can be.",
     "walls" : "They are a dull black",
     "towns" : "Sindarii, Lodos, Roston, Arlon, Merkkirri, Quixxiol"
   ]));
   set_exits(([
     "down" : "/wizards/inferno/workroom",
     "<town [town_name]>" : "/get/a/life",
     "<hall [class_name]>" : "/get/a/life",
     "up" : "/wizards/inferno/mirrors"
   ]));
}

int hall(string str) {
   if (!str) return 0;
   switch(str) {
     case "rogue":
     case "mage":
     case "child":
     case "monk":
     case "kataan":
     case "cleric":
     case "wanderer":
     case "fighter":
       break;
     default:
       return notify_fail("That class is not listed.");
   }
   this_player()->move_player("/d/standard/"+str+"_hall", str+" hall");
   return 1;
}

int town(string str) {
   string file;
   if (!str) return 0;
   switch(str) {
     case "lodos": file = "/d/lodos/square"; break;
     case "sindarii": file = "/d/standard/square"; break;
     case "roston": file = "/wizards/detach/roston/roston"; break;
     case "arlon": file = "/d/arlon/room/square"; break;
     case "merkkirri": file = "/wizards/asmodeus/jungle/merkkirri/msquare"; break;
     case "quixxiol": file = "/wizards/asmodeus/jungle/gcity/gcity6"; break;
     default: return notify_fail("That town is not listed.");
   }
   this_player()->move_player(file, str);
   return 1;
}

void init() {
 ::init();
   add_action("hall", "hall");
   add_action("town", "town");
}
