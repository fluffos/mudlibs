#include <std.h>
#include <metallicana.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Kobold Guard");
   set_id(({"guard", "Kobold Guard"}));
   set_short("A Stern Kobold Guard");
   set_long("The stands tall as he watchs over the surrondings. "
       "Battle scars cover most of his body, and his hair is long with "
       "a grey tinge starting to show through.");
   set_gender("male");
   set_race("kobold");
   set_body_type("human");
   set_level(37);
   new(WEP "barbed_whiplash")->move(this_object());
   force_me("wield whip");
   new(ARM "battle_armour")->move(this_object());
   force_me("wear armour");
}
