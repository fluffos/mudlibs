
inherit F_CLEAN_UP;
#include <ansi.h>
#include <dbase.h>
#include <origin.h>

int quest_give (object me, object who, object ob)
{
  if("/adm/daemons/questd"->quest_reward(me,who,ob))return 1;
  if("/cmds/usr/quest"->accept_object(me,who,ob))return 1;
      return 0;
}

string quest_ask (object me, object who, string topic)
{
    return 0;
}

void quest_kill (object me)
{
        return;
}

