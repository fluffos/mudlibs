#include <std.h>
inherit WEAPON;

int can_unwield();
int can_wield();

void create() {
  ::create();

    set_name("jade cutlass");
    set_id( ({ "sword", "cutlass", "jade cutlass" }) );
    set_short("%^GREEN%^%^BOLD%^Jade%^RESET%^ cutlass");
    set_long("A cutlass made of pure jade. Captain Chestin "
    		 "forced a village of natives on some distant "
    		 "island to make it. It is the only known sword "
    		 "to be made of jade. It glows a soft green."
			 );
    set_type("blade");
    set_wc(10);
	set_ac(1);
    set_weight(44);
    set_curr_value("gold", 200 + random(35));
	set_wield((:can_wield:));
	set_unwield((:can_unwield:));
}

int can_unwield()
{
	set_wc(10);
	set_ac(1);	
	return 1;
}

int can_wield()
{
    if (this_player()->query_subclass() == "swashbuckler")
    {
        write("You grasp the cutlass with a sense a familiarity.");
        set_wc(17);
       	set_ac(2);
    }
    else
    {
		set_wc(10);
		set_ac(1);	
	}
    return 1;
}

int query_auto_load() 
{
	if(this_player()->query_level() < 45) return 0; 
	return 1; 
}

