#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
    int i;
    object obj;

    if( !str || str == "")
        obj = me;
    else if ( !obj = present(str,environment(me)))
        return notify_fail("对象错误: 找不到"+str+"\n");
    
    tell_object(obj,HIR + this_player()->query("name") + "(" + this_player()->query("id")+ ")为你的身体恢复到了最佳状态。\n"NOR);
    obj = me;
    me->set("eff_qi",obj->query("max_qi"));
    me->set("qi",obj->query("max_qi"));
    me->set("eff_jing",obj->query("max_jing"));
    me->set("jing",obj->query("max_jing"));
    me->set("jingli",obj->query("max_jingli"));
    me->set("neili",obj->query("max_neili")*2);
    me->set("food",obj->max_food_capacity()*2);
    me->set("water",obj->max_water_capacity()*2);

    me->clear_condition();
    write(HIR"恢复成功。\n"NOR);
    return 1;
}

int help(object obj)
{
  write(@HELP
指令格式 : full

利用此指令可完全恢复生物的状态。
HELP
    );
    return 1;
}

