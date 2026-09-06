#include "../priest.h"

#define MEDITATE_LEVEL 8

status
meditate_cmd(object who, object sym, string str)
{
    object tranz;
    int amount;

    if(!str || sscanf(str,"%d",amount)!=1)
	return notify_fail("Illegal argument(s).\n"),0;

    if(amount>300 || amount<10)
	return notify_fail("Illegal value. Must be 10..300.\n"),0;

    if(who->is_fighting())
	return notify_fail("You didn't really think you could do \
that while fighthing?\n"),0;

    if(who->query_hp()-amount <= 20)
	return notify_fail("To meditate that long would make you \
nearly unconscious!\n"),0;

    if(who->query_hp()<0)
	return notify_fail("You can't do that while unconscious.\n"),0;

    if(who->query_level()<MEDITATE_LEVEL)
	return notify_fail("Your mind still needs training before \
you can meditate.\n"),0;

    who->tell_me("You sit down, closing your eyes. You empty \
your mind, making yourself one with peace.");
    environment(who)->tell_here(":%<me.capname>% sits down, assuming \
the position for meditating.",0,0,who,who,0,0);

    tranz=clone_object(PRIEST_OBJ_DIR "trance");
    move_object(tranz,who);
    tranz->start_medit(amount);
    return 1;
}
