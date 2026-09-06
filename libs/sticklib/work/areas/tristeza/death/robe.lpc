#include <armour.h>

void
create_armour()
{
    set_name("black hooded robe");
    set_type("armour");
    set_short("black hooded robe");
    set_long(
      "A black hooded robe with numerous pockets. It wouldn't certainly fit you "+
      "very well however. It seems to have been tailored for a very lean "+
      "customer. VERY lean indeed...");
    set_id("deaths_item");
    set_ac(5);
    set_weight(12);
    set_value(5000);
}

void
init_armour()
{
    if(this_player() && !this_player()->query_npc())
	call_out("check_me",2);
}
check_me() {
    remove_call_out("check_me");
    if(environment())
	check_env(environment());
    call_out("check_me",2);
}
check_env(ob) {
    if(!living(ob) && environment(ob))
	check_env(environment(ob));
    if(!environment(ob))
	self_dest();
    if(living(ob)) {
	string dummy;
	if ( strstr(object_name(environment(ob)),"/death/")==-1)
	    self_dest();
    }
}
self_dest() {
    environment()->tell_here(
      "The black robe flares for a moment and disintegrates.");
    destruct(this_object());
}
