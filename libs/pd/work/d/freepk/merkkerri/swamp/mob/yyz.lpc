#include <swamp.h>
#include <std.h>
inherit MONSTER;
int newbody();

void create() {
::create();
set_name("Yyz");
set_short("%^BOLD%^BLUE%^Yyz, the Guardian of the Dark%^RESET%^");
set_long("Before there was Yyz, there was none.  He was the first and shall always be.  It was his failed quest for immortality that left him a cruel hybrid of life and death.  Now it is he who guards the dark.\n**Yyz is a very powerful adversary.**");
set("aggressive", 0);
set_id(({"Yyz", "yyz", "lich", "undead", "guardian"}));
set_skill("magic attack", 500);
set_class("mage");
set_subclass("necromancer");
set_alignment(-1000);
set_skill("necromancy", 500);
set_stats("intelligence", 175);
set_stats("wisdom", 200);
set_race("lich");
set_body_type("lich");
set_gender("male");
set_emotes(10, ({"Icey %^BLUE%^blue%^RESET%^ eyes peer at you from within Yyz's hood.", "The lich moves with slow precision."}),0);
set_spell_chance(40);
set_spells(({"soulburn", "chaoswave", "chilltouch", "deathtouch", "blast"}));
set_lang_prof("merkish", 10);
set_speech(50,"merkish",({"Asmodeus favors me.  Your death is unavoidable
now...", "My power is infinate!", "Wretched creature!"}),1);
set_level(85);
set_die((: newbody() :));

}

int newbody() {
   tell_room(environment(this_object()),
   "Yyz disappears without a trace!\nYou wonder if you really kill him...", ({ }));

this_object()->remove();
   return 0;
}
void init()   
{
 ::init();
}

void catch_tell(string str) {
   string person;
   if (!sscanf(lower_case(str), "%s dies a horrible death.", person)) return;
   if (!find_player(person)) return;
message("info", "%^BOLD%^BLACK%^Yyz shouts:%^RESET%^ "+capitalize(person)+" is a fool to challenge me!",
users());
}
