#include "../priest.h"

status
rid_cmd(object who, object sym, string s)
{
    object staff;

    if(!s) return notify_fail("Get rid of what?\n"),0;
    staff = STAFF_D->query_staff(who);
    if(!staff || (environment(staff) != who))
	return notify_fail("Get rid of what?\n"), 0;
    who->tell_me(
      "You decide you don't need your staff for a while now.\n\
You concentrate, and send staff flying up towards the sky. \
Its speed increases rapidly, and as it is just a small point in the \
sky, it suddenly disappears.");
    environment(who)->tell_here(":%<me.capname>% sends %<me.possessive>% \
staff flying towards the sky. The speed of staff increases rapidly, and \
as it is just a small point in the sky, it suddenly disappears.",
      0,0,who,who,0,0);
    destruct(staff);
    return 1;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
