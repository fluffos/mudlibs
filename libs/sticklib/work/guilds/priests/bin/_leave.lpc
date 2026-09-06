#include "../priest.h"

status
leave_cmd(object who, object sym, string s) {
    object staff;
    string me_tell, other_tell;

    if(!s) return 0;
    staff = present(s, who);
    if(!staff || !staff->is_priest_staff())
	return notify_fail("Leave what?"),0;

    if(who->query_weapon() == staff) {
	who->unwield(staff,1);
	// Should we inform the player??
    }
    move_object(staff, environment(who));
    who->tell_me("You gently leave your staff on the ground.");
    environment(who)->tell_here(":%<me.capname>% leaves %<me.possessive>% "
      +staff->query_staff_name()+" on the ground.",0,0,who,who,0,0);
    who->add_weight(staff->query_weight());
    return 1;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
