#include <std.h>
#include <halloween.h>

inherit ARMOUR;

void create()
{
 ::create();
 set_name("ruby slippers");
 set_short("%^RED%^A pair of ruby slippers");
 set_long("These ruby slippers glisten in the moonlight. They are very "
          "small and dont seem to fit you");
 set_id( ({ "ruby slippers", "pair of ruby slippers", "slippers" }) );
 set_mass(10);
 set_ac(1);
 set_type("slippers");
 set_limbs( ({ "head" }) );
 set_no_clean(1);
}

void init()
{
 ::init();
 add_action("wear", "wear");
}

int wear(string str)
{
 if (present(str, this_player())!=this_object()) return 0;
 if (this_player()->query_stats("constitution") < 1000)
   {
    write("You try to put the slippers on but fail.\n");
    return 1;
   }
 return 0;
}
