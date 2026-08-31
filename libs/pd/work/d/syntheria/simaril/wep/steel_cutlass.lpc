#include <std.h>
inherit WEAPON;

int can_unwield();
int can_wield();

void create() {
  ::create();

    set_name("steel cutlass");
    set_id( ({ "sword", "cutlass", "steel cutlass" }) );
    set_short("Steel cutlass");
    set_long("This curved blade is a pirate's favorite weapon. "
			 "This cutlass seems to be slightly worn, but is still sharp. "
			 "The hilt of the blade looks to be made of gold. "
			 "It is possible this sword is stolen property.");
    set_type("blade");
    set_wc(12);
	set_ac(1);
    set_weight(44);
    set_curr_value("gold", 40 + random(25));
	set_wield((:can_wield:));
	set_unwield((:can_unwield:));
}

int can_unwield()
{
	set_wc(13);
	set_ac(1);	
	return 1;
}

int can_wield()
{
    if (this_player()->query_subclass() == "swashbuckler")
    {
        write("You grasp the cutlass with a sense a familiarity.");
        set_wc(15);
       	set_ac(2);
    }
    else
    {
		set_wc(13);
		set_ac(1);	
	}
    return 1;
}

int query_auto_load() 
{
	if(this_player()->query_level() < 35) return 0; 
	return 1; 
}

