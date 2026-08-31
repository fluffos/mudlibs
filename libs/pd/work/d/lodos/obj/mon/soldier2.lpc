#include <std.h>
#include <lodos.h>
inherit MONSTER;

void create() {
 ::create();
   set_short("a readied soldier");
   set_id( ({ "soldier", "man" }) );
   set_name("soldier");
   set_level(21);
   set_long("The soldier stands attentive at his guard post.");
   set_body_type("human");
   set_race("gnome");
   set_gender("male");
   set_heart_beat(1);
   new(WEA"mstar")->move(this_object());
   this_object()->force_me("wield star");
}
