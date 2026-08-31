#include <std.h>
#include <guild.h>
inherit "/std/guild/portal";
void create() {
    ::create();
    set_location("/d/guilds/AoD/helgrath/portal");
    set_enter("pool");
    set_name("scrying room");
    set_short("scrying room");
    set_long("%^BOLD%^%^BLACK%^Dank, damp air blankets this room, one of many "
      "in a vast underground network.  Ancient steps, cracked with age, lead "
      "down to a pool of %^CYAN%^cr%^WHITE%^y%^CYAN%^st%^WHITE%^al c%^CYAN%^lea"


      "%^WHITE%^r w%^CYAN%^a%^WHITE%^te%^CYAN%^r%^RESET%^.%^BOLD%^%^BLACK%^A "
      "soft white light eminates from somewhere beneath the water, reflected "
      "upon the stone walls above.  Five pillars of stone stand as sentinels, "
      "surrounding the pool.  Barely discernable carvings, faded with age, "
      "cover the pillars.  %^RESET%^%^GREEN%^Moss %^BOLD%^%^BLACK%^creeps "
      "along the walls, covering torches long forgotten.  Many tunnel "
      "entrances line the walls, grand arches forming above them with statues "
      "of demons and gargoyles perched about.  The tunnels themselves stretch "
      "away into utter darkness.  Strangely enough music can be heard, it's "
      "source unknown...%^RESET%^"
    );
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );

    set_exits(([ "up":AoD"pray", ]));
    set_listen("music", "%^BOLD%^%^RED%^Carved in hate, carved in hate\n "
      "War is insane\n"
      "Everywhere, everywhere\n"
      "Blood and disgrace\n"
      "Look around, look around\n"
      "Apocalypse now!!\n"
      "Terminate, terminate\n"
      "With extreme hate\n"
      "Bring it!\n"
      "Who da cap fit, who da cap fit\n"
      "You know what I mean\n"
      "All your envy, all your envy\n"
      "I'll make you bleed\n"
      "Why don't you go away, why don't you go away\n"
      "And never come back no more\n"
      "Cut throat, cut throat\n"
      "Fuck off!!!\n"
      "Why don't you go away, why don't you go away\n"
      "Never come back no more\n"
      "Cut throat scum\n"
      "You don't have a soul...\n"
      "Fuck off%^RESET%^.\n");
    set_items( ([
	({"steps"}):"Ancient and cracked with age, these steps lead down "
	"to the pool.",
	({"pool"}):"You feel impelled to walk closer and peer into the water.",
	({"light", "white-light"}):"Soothing white light dances upon the water,"


	" reflecting upon the surrounding walls.",
	({"pillars"}):"Massive stone pillars with strange designs etched into "
	"them.",
	({"torches"}):"Dead, and forgotten.", 
	({"tunnels"}):"Many tunnels lead away into darkness...", 
	({"arches"}):"Leering images of demons and gargoyles line the arches..."


      ]));
}
