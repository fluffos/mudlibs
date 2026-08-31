#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("avatar");
set_short("An avatar of Asmodeus");
set_long("%^BOLD%^MAGENTA%^Standing before you is an avatar of the mightly demon lord Asmodeus.  The avatar takes the form of a black demon that is comprised of a black void and seems to distort nearby reality.%^RESET%^");
set("aggressive", 0);
set_id(({"avatar", "avatar of asmodeus", "asmodeus", "god"}));
set_skill("magic attack", 500);
set_class("cleric");
set_skill("healing", 500);
set_alignment(-2000);
set_skill("faith", 500);
set_stats("intelligence", 175);
set_stats("wisdom", 200);
set_race("god");
set_body_type("demon");
set_gender("male");
set_emotes(10, ({"%^RED%^Asmodeus says:%^RESET%^ You have done well. The path of the demon is not easy. Now surrender your soul to me..."}),0);
set_spell_chance(40);
set_spells(({"paralyze", "faithbomb", "wound", "rapture", "cure avatar"}));
set_level(100);

}
