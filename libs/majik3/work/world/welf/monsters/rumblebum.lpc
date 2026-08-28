inherit MONSTER;

#include "../path.h";

create_monster ()
{
    set_name (({ "gnome", "drunk", "rumblebum" }));
    set_short ("An old gnome is sipping beer here");
    set_long (
      "Old Rumblebum has been drinking beer in Sunflower Tavern since it was opened."
      +" The cheery looking gnome has long tangled grey beard and foggy blue eyes."
      +" He's wearing colorful clothes and a pointed hat.\n");

    set_race ("gnome");
    set_levels (([ "caster" : 5 ]));
    set_gender (1);
    set_language ("ohrim");
    set_alignx (350);
    set_alignx (400);

    set_talk (({ "Nice ta meetcha. Heeh.",
	"Nice place this is... really. The beer is excellent I must tell ya.",
	"The name's Rumblebum. May I ask who you are?"}));

    set_emote (({ "Rumblebum farts loudly and sighs happily.",
	"The gnome drinks his beer with one gulp and smacks his lips.",
	"An odd smell surrounds the old gnome."}));


    add_money (random(5));
}
