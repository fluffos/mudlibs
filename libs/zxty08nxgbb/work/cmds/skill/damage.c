#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        int nowtime = time();
        mapping quest;

         if(!me->query("tydamage"))
        return notify_fail(
               HIW"你还没有更新skill，要更新下吗？\n"NOR);

        write(
        HIW"===============================================================\n"NOR
       +HIG"            你目前装备的终级skill攻击力为：\n            "NOR
  +HIR+me->query("tydamage/sword")+NOR
+HIG"的剑法攻击力和"NOR+HIR+me->query("tydamage/blade")+NOR
       +HIG"的刀法攻击力！\n"NOR
       +HIG"            恭喜！\n"NOR+
        HIW"===============================================================\n"NOR);

        return 1;
}


 
int help(object me)
{
        write(@HELP
指令格式 : damage。
HELP
        );
        return 1;
}


