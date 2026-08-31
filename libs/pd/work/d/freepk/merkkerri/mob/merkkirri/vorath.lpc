#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("vorath");
set_short("Vorath, a Kataan Master");
set_long("Vorath is the highest ranking Kataan within the golden city of Quixxiol and is in great favor with the queen.  Vorath's brutal efficiency and incredible skills have made him a legend among the Merkkirri people.");
set_id(({"vorath", "Vorath", "kataan", "kataan master", "gnoll", "merkkirri"}));
set_skill("magic attack", 250);
set_class("kataan");
set_skill("healing", 50);
set_alignment(-1000);
set_skill("faith", 250);
set_skill("magic defense",75);
set_stats("intelligence", 90);
set_stats("wisdom", 85);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
set_level(50);
set_emotes(10, ({"Vorath engulfs himself in %^BOLD%^BLACK%^dark%^RESET%^ flames.", "Vorath stands nearly motionless, a testiment to his rigorous discipline."}),0);
set_spell_chance(40);
set_spells(({"shadowburst", "hellfire", "absorb"}));
set_lang_prof("merkish", 10);
set_speech(50,"merkish",({"Demons awaken and empower me!", "The flames of Hell shall lick your wounds!", "For my Lord and for my Queen, die!"}),1);
new(MOB "kataanpike")->move(this_object());
command("wield warpike");

}
