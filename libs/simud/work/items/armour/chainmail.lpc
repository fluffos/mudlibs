#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(1000)
NAME( "chainmail" )
ALT_NAME( ({"mail","suit","armour","armor"}) )
DISTANT( "a suit of chainmail" )
LOOK( "This is a shirt of armour made by interlocking links of iron "+
      "chain together. You might be able to get some use out of it "+
      "by wearing the durned thing and hoping that it stops swords "+
      "from cutting you wide open.")
SPECIFIC( "the chainmail" )
PLURAL( "suits of chainmails" )
TYPE( "armour" )
WEIGHT( 11300 ) // 11.3 kg =~ 25 lbs
TASTE( "It tastes like Cheerios." )

void create() {
   ::create();
   set_base_ac(27);
   set_ac_mod( (["edged":10,"piercing":2,"electric":-20]) );
   set_requirement( (["str":13]) );
   set_armour_type( "armour" );
   set_flexible(1);
   set_size(20);
   set_body_parts(BP_TORSO);
}

int query_use_bonuses()
{
   return (query_worn());
}

int query_dex_bonus()
{
   return -2/3;
}

mapping query_aspects() {
   return ([ C_CLOTHING, C_SHIRT, C_METAL, C_IRON, C_CHAIN ]);
}
