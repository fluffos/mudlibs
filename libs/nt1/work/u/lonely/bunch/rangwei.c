// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string banghui;
        object ob;
        
        seteuid(getuid()); 
        
        if (! stringp(me->query("bunch/bunch_name")) || (int)me->query("bunch/level") != 9)
                return notify_fail("只有帮会的帮主才能使用这条指令。\n");
                
        banghui = me->query("bunch/bunch_name");
        
        if (me->is_fighting() || me->is_busy())
                return notify_fail("你正忙着呢。\n");
                
        if (! arg)
                return notify_fail("你要让位给谁？\n");
                
        if (me->query("id") == arg)
                return notify_fail("让位给自己？有必要吗？\n");
                
        if (! ob = present(arg, environment(me)))
                return notify_fail("这儿没有这么个玩家。\n");
                
        if (! playerp(ob))
                return notify_fail("你只能让位给玩家。\n");
                
        if (ob->query("bunch/bunch_name") != banghui)
                return notify_fail("你只能让位给本帮会的玩家。\n");
                
        if (ob->is_fighting() || ob->is_busy())
                return notify_fail("对方正忙着呢。\n");                
        
        BUNCH_D->set(banghui + "/bangzhu", ob->query("id"));
        BUNCH_D->save();
        
        ob->set("bunch/level", 9);
        ob->set("bunch/title", "帮主");
        me->set("bunch/title", "老帮主");
        me->set("bunch/level", 10);
        ob->save();
        me->save();
        message_vision("$N将帮会「" + banghui + "」的帮主之位让位给了$n。\n", me, ob);
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式：rangwei <某人>
这个指令为帮主专用，用来将帮主之位让位给他人。
前提是某人必须为本帮帮众。
HELP
        );
        return 1;
}


