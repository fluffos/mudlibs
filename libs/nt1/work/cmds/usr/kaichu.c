// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string bunch;

        if (! arg || arg == "")
                return notify_fail("指令格式：kaichu <玩家id>\n");
                
        if (! stringp(bunch = me->query("bunch/bunch_name")))
        {
                write("你现在还没有加入任何帮派呢。\n");
                return 1;
        }
        
        if (me->query("bunch/level") != 9)
        {
                write("只有帮主才有权利开除某人出帮会！\n");
                return 1;
        }
        
        if (arg == me->query("id"))
        {
                write("开除自己？你还不如解散你的帮派！\n");
                return 1;
        }        

        if (! objectp(ob = find_player(arg)))
        {
                ob = UPDATE_D->global_find_player(arg);

                if (! objectp(ob))
                { 
                        write("没有这个玩家。\n");
                        return 1;
                } 
        
                if (ob->query("bunch/bunch_name") != bunch)
                {
                        UPDATE_D->global_destruct_player(ob);                                                      
                        write("他不是你的帮派中人，你无权开除他！\n");    
                        return 1;                   
                        
                }         
        }               

        CHANNEL_D->do_channel(this_object(), "rumor",
                        "听说" + ob->query("name") + "(" + arg + ")" +
                        "被帮派『" + bunch + "』给开除了。");
                        
        BUNCH_D->add_bunch_fame(bunch, -ob->query("weiwang") / 2); 
        ob->add("weiwang", -ob->query("weiwang") / 10);
        
        UPDATE_D->clear_user_data(arg, "bunch");
        UPDATE_D->global_destruct_player(ob);    
        return 1;
}      
