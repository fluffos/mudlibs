#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Deranged child");
   set_short("Deranged child");
   set_id(({"child", "monster"}));
   set_long("Just a child, till you look in his eyes...");
   set_level(55+random(10));
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_emotes(2,({ "A child wanders around looking for more playmates to bring to meet his mother. " }),0);

new(EQ"skullcap")->move(this_object());
force_me("wear cap");

new(EQ"cshirt")->move(this_object());
force_me("wear shirt");

new(EQ"cpants")->move(this_object());
force_me("wear pants");

new(EQ"hskull")->move(this_object());
force_me("wear skull");

new(EQ"wlboots")->move(this_object());
force_me("wear boots");

new(EQ"hgloves")->move(this_object());
force_me("wear gloves");

new(WEAP"shot")->move(this_object());
force_me("wield slingshot");

new(WEAP"shot")->move(this_object());
force_me("wield slingshot");
}
