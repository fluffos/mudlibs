#include <std.h>
#include <lodos.h>
inherit MONSTER;

void create() {
 ::create();
   set_short("a glowering soldier");
   set_id( ({ "soldier", "man" }) );
   set_name("soldier");
   set_level(19);
   set_long("The soldier stands at his guard.");
   set_body_type("human");
   set_race("gnome");
   set_gender("male");
   new(WEA"hammer")->move(this_object());
   this_object()->force_me("wield hammer");
}
