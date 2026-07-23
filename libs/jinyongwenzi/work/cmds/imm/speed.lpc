// quit.c

#include <ansi.h>

int main(object me, string arg)
{
        int i,j;
        object ob;

        if(!arg)
                ob = me;
        else
                ob = present(arg, environment(me));

        if (wizardp(me)) {
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob || !me->visible(ob)) return notify_fail("你要察看谁的EXP状态？\n");
        } else if (ob != me)
                return notify_fail("只有巫师能察看别人的EXP状态。\n");
        
        i = (ob->query("combat_exp") - ob->query_temp("combat_exp")) * 60
                / (ob->query("mud_age") - ob->query_temp("mud_age"));

        j = (ob->query("mud_age") - ob->query_temp("mud_age"))/60;

        write(sprintf("%s 上次经验：%d，本次经验：%d，平均：%d/min, 上线时间为 %d min。\n",
                                geteuid(ob), ob->query_temp("combat_exp"),
                                ob->query("combat_exp"), i ,j));
        return 1;

}

int help(object me)
{
        write(@HELP
指令格式 : speed <id>

用此指令检查player的经验速度。
HELP
    );
    return 1;
}
