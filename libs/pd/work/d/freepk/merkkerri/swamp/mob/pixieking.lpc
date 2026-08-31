#include <std.h>
#include <swamp.h>
inherit MONSTER;

void create() {
::create();
set_name("king");
set_short("pixie king");
set_long("An ancient pixie with long white hair and an even longer beard.  The pixie king appears quite full of himself and yet acts in only in jest.  The swamp pixies despise the Merkkirri and are actually quite peaceful in nature.");
set("aggressive", 0);
set_id(({"king", "pixie",}));
set_skill("magic attack", 300);
set_class("monk");
set_subclass("light");
set_alignment(800);
set_skill("faith", 300);
set_skill("melee", 300);
set_stats("intelligence", 120);
set_stats("wisdom", 120);
set_race("pixie");
set_body_type("faerie");
set_gender("male");
set_emotes(10, ({"The king tells an amusing joke and falls down laughing.", "The king invites you to listen to his stories.", "The king tells about how he once met the dragon Tiamat here in the swamp.", "The king tells the story of how the horn of blasting came into his possession."}),0);
set_spell_chance(40);
set_spells(({"strike", "snapkick", "faithbomb"}));
set_lang_prof("merkish", 10);
set_level(60);
new(MOB "leafmail")->move(this_object());
command("wear leafmail");
if(random(100) > 74)
new(MOB "horn")->move(this_object());
}
