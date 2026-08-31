#include <std.h>
inherit ROOM;

void create() {
   object oi;
   ::create();
   set_name("Dark Souls selling");
   set_items((["corpses"   : "%^ORANGE%^A pile of roting corpses",
               "blood"  : "%^RED%^Pools of blood all over"]));
   set_properties((["light":2, "night light":3, "no attack":1]));
   set_short("Dark Souls");
   set_long("%^BOLD%^%^BLACK%^This is where the members of the "
            "D%^WHITE%^a%^BLACK%^r%^WHITE%^k%^BLACK%^ S%^WHITE%^o"
            "%^BLACK%^u%^WHITE%^l%^BLACK%^s come to sell of there "
        "collections of thier battles. Anubis stands in the middle "
"of the room watin to buy or sell you anything you need, or want. "
"%^BOLD%^%^WHITE%^Death fills the room.");

   set_exits( ([ "west" : "/wizards/detach/roston/guild/room1"]));               


}

reset() {
   ::reset();
   if(!present("anubis"))
   new("/wizards/detach/roston/guild/annubis")->move(this_object());
}

