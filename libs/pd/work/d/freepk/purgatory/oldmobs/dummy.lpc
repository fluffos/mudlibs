#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("dummy");
   set_short("dummy");
   set_id(({"monster"}));
   set_long("dummy");
   set_level(25+random(15));
   set("aggressive", 25);
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_emotes(2,({ "you are pretty weird" }),0);


new(EQ"skeletoncloak")->move(this_object());
force_me("wear leggings");

new(EQ"skeletonboots")->move(this_object());
force_me("wear boots");

new(EQ"slime")->move(this_object());
force_me("wear slime");

new(EQ"eyeearrings")->move(this_object());
force_me("wear earrings");
}
