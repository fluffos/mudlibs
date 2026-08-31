#include <std.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("fly");
   set_id( ({ "fly", "a fly" }) );
   set_short("a fly");
   set("aggressive", 150);
  set_level(10);
   set_long("The fly is HUGE.  It flies around, landing occasionally, "
	"to drink from some moist plant.  It is very dirty and most "
	"likely diseased.");
    set_body_type("insctwgd");
   set("race", "fly");
   if(random(2) == 0) set_gender("male"); else
   set_gender("female");
}
void heartbeat()
{
   int ctr;
   ::heartbeat();

   ctr=1;

   if ( ctr >=5 )
   {
      add_hp(1500);
      ctr=1;
   }
   else
      ctr++;
}
