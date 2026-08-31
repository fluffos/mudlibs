#include <std.h>
inherit OBJECT;
int filled = 0;
int stre = 0;
string type;
void create() {
    ::create();
    set_id(({ "flask" }));
    set_name("flask");
    set_long("An old metal flask used by the dock worker Achray. He often tries to sneak sips from it while working at the Simaril docks. It appears to be empty, perhaps you could fill it with something.");
    set_short("flask");
    set_weight(1);
	set_curr_value("gold", 3 + random(3));
}

void init() {
	::init();
		add_action("fill_up", "fill");
		add_action("sneak_sip", "sip");
}

int sneak_sip(string str)
{
  	if(!str) return notify_fail("Sip what?\n");
  	if(str != "from flask")
  		return notify_fail("sip from what?\n");
   	if(this_player()->query_current_attacker()) {
      return notify_fail("You are too busy to sneak a sip right now!\n");
   	}

   	if(environment(this_object()) != this_player()) {
      notify_fail("You must get it first.\n");
      return 0;
   	}
   	if(this_player()->query_disable())
      return notify_fail("You are too busy to sneak a sip right now!\n");
   	
   	if(filled == 0)
   		return notify_fail("The flask is empty!\n");
   	
	if(type == "soft drink") 
   	{
      if(!this_player()->add_quenched(stre)) 
	  {
         notify_fail("You are too bloated to drink that!\n");
         return 0;
      }
   	}	
   	else if(type == "caffeine") {
      if((int)this_player()->query_intox() > (stre*9)) {
         return notify_fail("You do not feel the need for that right now.\n");
         }
      if(!this_player()->add_quenched(stre)) {
         return notify_fail("You are too bloated to drink that!\n");
         }
      this_player()->add_intox(-(stre/2));
   	}
   	else if(type == "alcoholic") {
      if(!this_player()->add_intox(stre)) {
         return notify_fail("You are just about to pass out as it is.\n");
         }
   	}
   	this_player()->heal(stre*2);
   	this_player()->set_disable();
	write("You sneak a sip from the flask.");	
	filled--;
	if(filled == 0)
		set_long("An old metal flask used by the dock worker Achray. He often tries to sneak sips from it while working at the Simaril docks. It appears to be empty, perhaps you could fill it with something.");
   	return 1;
	
}

int fill_up(string str)
{
	string dr;
	object drink;
	if(!str) return notify_fail("Fill what?\n");
	if(!sscanf(str, "flask with %s", dr))
	{
		return notify_fail("Fill flask with what?\n");	
	}

	if(!drink = present(dr, this_player()))
		return notify_fail("Fill the flask with that?\n");	
	if(!drink->query_type())
		return notify_fail("You can not fill the flask with that!\n");
	if(!present(drink->query_name(), this_player()))
	{
		return notify_fail("You do not have that drink!\n");
	}
	if(filled > 0)
		return notify_fail("There is already liquid in the flask.\n");
		
	stre = drink->query_strength();
	type = drink->query_type();
	filled = 5;
	message("info", "You pour the " +drink->query_name()+
					" into the flask.", this_player());
	drink->clone_empty(this_player());
	drink->remove();
	set_long("An old metal flask used by the dock worker Achray. He often tries to sneak sips from it while working at the Simaril docks. It appears to have some kind of liquid in it.");
	return 1;
}
