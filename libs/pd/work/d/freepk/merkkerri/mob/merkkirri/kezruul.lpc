#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("kezruul");
set_short("Kezruul, demonic servant of Treggeth");
set_long("Kezruul is a demon bound and sworn to protect Treggeth.  This was a gift from the Merkkirri ruler.");
set("aggressive", 16);
set_id(({"kezruul", "demon"}));
set_skill("magic attack", 150);
set_class("clergy");
set_subclass("kataan");
set_skill("healing", 50);
set_alignment(-1000);
set_skill("faith", 150);
set_skill("magic defense",75);
set_stats("intelligence", 55);
set_stats("wisdom", 60);
set_race("demon");
set_body_type("demon");
set_gender("neuter");
set_emotes(10, ({"The demon Kezruul shrieks at you.", "Kezruul cracks its knuckles while staring boldly at you."}),0);
set_spell_chance(30);
set_spells(({"demonbolt", "shadowburst"}));
set_lang_prof("merkish", 10);
set_speech(50,"merkish",({"My lord will have less mercy on you than I...", "Death will be the most pleasurable part of your fate!", "Feel the powers of Hell upon you!"}),1);
if(random(100) < 3)
new(MOB "blackdiamond")->move(this_object());
set_level(30);
   new(MOB"bola")->move(this_object());
   command("wield bola");

}
