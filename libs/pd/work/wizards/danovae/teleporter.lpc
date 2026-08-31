#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("teleporter");
   set_id( ({ "teleporter","device" }) );
   set_short("A Teleporter");
   set_long(
     "A device used to move yourself around."
   );
   set_curr_value("gold",0);
   set_mass(10000);
   set_prevent_get("How do you propose to do that?");
}
void init() {
   ::init();
   add_action("teleport","teleport");
   add_action("read","read");
}

int read(string str) {
   if(!str) { return notify_fail("Read what?\n"); }
   if(str == "plate") {
     say(this_player()->query_cap_name()+" reads the metal plate.");
     write("----------------------------------------");
     write("   Aekari                  Radyne       ");
     write("   Caelum                  Phascina     ");
     write("   Tirun                   Lodos        ");
     write("----------------------------------------");
     write("        Choose A Destination  ");
     write(" ");
   }
   return 1;
}

int teleport(string str) {
   if(!str) { return notify_fail("Teleport to where?\n"); }
   if(str == "to aekari") {
   this_player()->set_paralyzed(20);
   write("You step onto the teleporter.");
   say(this_player()->query_cap_name()+" steps onto the teleporter.");
   call_out("tpa",3);
}
   if(str == "to tirun") {
   this_player()->set_paralyzed(20);
   write("You step onto the teleporter.");
   say(this_player()->query_cap_name()+" steps onto the teleporter.");
   call_out("tpa2",3);
}


}




void tpa() {
   write("The crystals on the teleporter start to %^BOLD%^%^CYAN%^glow%^RESET%^ and %^BOLD%^%^MAGENTA%^pulse%^RESET%^ with energy.");
   say("The crystals on the teleporter start to %^BOLD%^%^CYAN%^glow%^RESET%^ and %^BOLD%^%^MAGENTA%^pulse%^RESET%^ with energy.");
   remove_call_out("tpa");
   call_out("tpb",4);
   this_player()->move("/d/aekari/room/ca1");
}

void tpa2() {
   write("The crystals on the teleporter start to %^BOLD%^%^CYAN%^glow%^RESET%^ and %^BOLD%^%^MAGENTA%^pulse%^RESET%^ with energy.");
   say("The crystals on the teleporter start to %^BOLD%^%^CYAN%^glow%^RESET%^ and %^BOLD%^%^MAGENTA%^pulse%^RESET%^ with energy.");
   remove_call_out("tpa2");
   call_out("tpb",4);
   this_player()->move("/d/tirun/square");
}

void tpb() {
   write("%^BOLD%^%^BLACK%^A dark wind begins to spiral around you.%^RESET%^");
   say("%^BOLD%^%^BLACK%^A vortex of dark wind spirals around the area.%^RESET%^");
   remove_call_out("tpb");
   call_out("tpc",5);
}

void tpc() {
   write("%^MAGENTA%^A beam of pure energy engulfs you, as you feel yourself fade into nothingness.%^RESET%^");
   say("%^MAGENTA%^A beam of light streaks down and fades away leaving only a darkened shell of a being.%^RESET%^");
   remove_call_out("tpc");
   call_out("tpd",5);
}

void tpd() {
   write("%^CYAN%^You arrive at your destination in a single flash of light.%^RESET%^");
   say("%^BOLD%^%^CYAN%^"+ this_player()->query_cap_name()+" arrives in a single flash of light.%^RESET%^");
   remove_call_out("tpd");
}




