#include <std.h>
inherit OBJECT;
int rounds;
 
void create() {
  ::create();
  rounds = this_player()->query_level()/2;
  set_name("crazie");
  set_heart_beat(1);
  set_short("");
  set_long("blah");
  set_weight(0);
  set_value(0);
  set_id(({"nocast object"}));
}
void init() {
  ::init();
  add_action("disease","disease");
call_out("byebye",rounds);	
}
int disease(string str) 
{
	if (!str)
	{
		return 1;
	}
	else
	write("%^BLACK%^%^BOLD%^You are still building the negative energies in your body.");
	return 1;
}
int byebye()
{
	write("%^BLUE%^%^BOLD%^You feel able to cast your disease spell again.");
    this_object()->remove();
    if(this_object()) destroy(this_object());
	return 1;
}
