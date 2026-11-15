// smash.c

// Modified by mxzhao 

inherit F_CLEAN_UP;


#include <command.h>

int help(object me);
 
int main(object me, string arg)
{
        object ob;

        if (!arg)
        {
                return help(me);
        }

	  if (wiz_level(me) < 3)
                return notify_fail("无法使用。\n");


        ob = present(arg, environment(me));

        if (!ob)
        {
                return notify_fail("找不到这个生物。\n");
        }

        message_vision(HIY "$N高举双手大喝：去死吧！\n"
                "\n" HIY
                "只见晴天一道闪电．．．．．．\n"
                "\n" HIB
                "         ———————\n" HIW
                "               /\n"
                "              /\n"
                "             /\n"
                "             ——\n"
                "                /\n"
                "               /\n"
                "              /\n"
                "\n" HIB
                "不偏不倚地击中$n, 将$n化为一堆灰烬。"NOR"\n", me, ob);
	if (wiz_level(me) < wiz_level(ob))
        {
                message_vision(HIM "\n$N" HIM "身上冒着缕缕青烟，"
                                       "却没有半点事情。"NOR"\n""\n",
                                       ob);
                return 1;
        }
        ob->set_temp("last_damage_from", "被闪电劈");
        ob->die();

        message_vision(HIG "$N仰天大笑：“哈哈哈，哈哈哈... 好爽，爽！爽！爽！”"NOR"\n",me );
        
        //EMOTE_D->do_emote(me, "innocent", me->query("id"));

        return 1;
}
 
int help(object me)
{
   write(@HELP
指令格式: smash <生物>
 
hehehehehe...........

HELP
   );
   return 1;
}
