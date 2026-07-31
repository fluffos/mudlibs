// Cmd:  zhua.c
// Created by Numa 1999-12-10

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, obj;
        int runner;
        
        if (!arg)
                return notify_fail("指令格式： zhua <某人>。\n");
        if( sscanf(arg, "%s with %d", arg, runner) != 2 ) 
              runner = 3;
        	
        obj = present(arg, environment(me));
        if(!obj)
                obj = present(arg, me);
        if(!obj)
                obj = find_player(arg);
        if(!obj || !me->visible(obj))
                obj = find_object(resolve_path(me->query("cwd"), arg));
        if("me" == arg)
                obj = me;
        if(!obj)
                return notify_fail("找不到指定的物件。\n");

        ob = new("/clone/npc/antirobot"+runner);
        ob->test_robot(obj);
        tell_object(me,HIY + obj->name(1)+HIY"("+capitalize(obj->query("id"))+")已经照您的吩咐送去审查了。\n");
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : zhua <某人> with <1|2|3>

此指令可让你让某个玩家接受机器人抽查。
zhua xxx with 1-3 的数字表示用哪个antirobot去测试。
HELP
    );
    return 1;
}

