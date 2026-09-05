
// by yuer
// quest.c

inherit F_CLEAN_UP;

#include <ansi.h>
#include <dbase.h>
#include <origin.h>

void create()
{
        seteuid(getuid());
}

int quest_give (object me, object who, object ob)
{
   if (!me->query("quest") || me->query("quest/type")!="give")	 
     return 0;
   if (me->query("quest/name") != who->query("name") ||
            me->query("quest/id")   != who->query("id"))
     return 0;

   if (me->query("quest/objname") != ob->query("name") ||
            me->query("quest/objid") != ob->query("id"))
     return 0;

   me->set("quest/finish",1);
   return 1;
}


void quest_kill(object me,object killer)
{

   if (! killer)
     return;
   if (!killer->query("quest") || killer->query("quest/type")!="kill")	 
     return ;
   if (killer->query("quest/name") != me->query("name") ||
            killer->query("quest/id")   != me->query("id"))
     return ;
   
   killer->set("quest/finish",1);
}

