#include <std.h>
#include <roston.h>
inherit ROOM;

void create() {
   object oi;
   ::create();
   set_name("Dark Souls healing");
   set_items((["corpses"   : "%^ORANGE%^A pile of roting corpses",
               "blood"  : "%^RED%^Pools of blood all over"]));
   set_properties((["light":2, "night light":3, "no attack":1]));
   set_short("Dark Souls");
   set_long("%^BOLD%^%^BLACK%^This is where the members of the  "
            "D%^WHITE%^a%^BLACK%^r%^WHITE%^k%^BLACK%^ S%^WHITE%^o"
            "%^BLACK%^u%^WHITE%^l%^BLACK%^s come to heal the wounds "
            "from there great battle, This is also where they come to "
            "perpare for the battles. If you need help with anything "
            "that involes healing talk to %^WHITE%^Slayer%^BLACK%^ he "
            "will help you will your needs.%^WHITE%^The Spirits Watch "
            "You%^BLACK%^.%^RESET%^");

   set_exits( ([ "north" : DARKSOUL"room1"]));               


}

void reset(){
   ::reset();
   if(!present("slayer"))
   new(DARKSOUL"slayer")->move(this_object());
}

