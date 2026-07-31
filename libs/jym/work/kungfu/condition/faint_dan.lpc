#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int i;
	string *cmds = ({"drop all", "boss", "jifa force none", "jifa dodge none", "jifa parry none", "jiali 0", "jiajing 0", "remove all", "bei none", "to chat", "quit"});
        seteuid(ROOT_UID);
        me->apply_condition("faint_dan", duration - 1);
        i = random(sizeof(cmds));
        me->force_me(cmds[i]);
        if(wizardp(me)) tell_object(me, "command " + cmds[i] + " started!\n");

        if( duration < 1 )
        {
                return 0;
        }
        return 1;
}


