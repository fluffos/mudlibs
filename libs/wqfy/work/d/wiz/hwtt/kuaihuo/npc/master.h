#include <dbase.h>
#include <login.h>
#include <ansi.h>
int prevent_learn(object me, string skill)
{
	mapping 	my_family, family;
        int task,oldtask, mylvl, lvl;
	task= me->query("TASK");
	oldtask = me->query("OLDTASK");
	lvl = this_object()->query_skill(skill, 1);
	mylvl = me->query_skill(skill, 1);
       if( mylvl *5 > task - oldtask ) {
			message_vision("$N神色间似乎对$n不是十分信任，\n也许是认为$p江湖阅历太浅...。\n", this_object(), me );
                        command("say 嗯 .... \n师父先教你这些，你自己再练练吧。");
                        return 1;
                }
 
        return 0;
}

