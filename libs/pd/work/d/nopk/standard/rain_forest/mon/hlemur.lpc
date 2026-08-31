#include <rain.h>
#include <std.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("lemur");
   set_id( ({ "lemur", "fat lemur"}) );
   set_short("A huge  %^BOLD%^%^WHITE%^s%^BLACK%^t%^WHITE%^r%^BLACK%^i%^WHITE%^p%^BLACK%^e%^WHITE%^d%^RESET%^ %^RED%^lemur%^RESET%^");
   set("aggressive", 5);
   set_level(8);
   set_long("This lemur is white with black stripe and is HUGE.");
   set_gender("male");
   set_body_type("human");
   set_race("Lemur");
   new(WEA"lteeth")->move(this_object());
   this_object()->force_me("wield fangs");
  }
