// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit F_CLEAN_UP;

#include "/adm/npc/npcneed.h"

int main(object me, string arg)
{
        object ob, *target;
        string bunch;
        int money, i, flag;
        mapping data;
        string *what, stuffid, stuffname;

        if (! arg || arg == "")
                return notify_fail("你要邀请谁加入你的帮会？\n");
                        
        if (! stringp(bunch = me->query("bunch/bunch_name")))
                return notify_fail("你没有参加任何帮会，无法邀请他人加入。\n");               
        
        flag = 0;
        
        if (intp(me->query("bunch/level")) &&
            (int)me->query("bunch/level") > 5)
                flag = 1;                       
                        
        if (me->query("id") == arg)
                return notify_fail("邀请自己？！\n");
                
        if (! objectp(ob = present(arg, environment(me))))
                return notify_fail("这儿有没这么个人。\n");
                
        if (! ob->is_character())
                return notify_fail("你只能邀请「人」加入你的帮会。\n");
                
        if (ob->query("bunch/bunch_name") == me->query("bunch/bunch_name"))
                return notify_fail(ob->query("name") + "已经是本帮弟兄了。\n");
                
        if (me->is_fighting() || me->is_busy())
                return notify_fail("你正忙着呢。\n");
                
        if (ob->is_fighting() || ob->is_busy())
                return notify_fail("对方正忙着呢。\n");
                
        if (! living(ob)) return notify_fail("你得先弄醒他再说。\n");       
                
        if (playerp(ob) && ! flag)
                return notify_fail("你无权邀请玩家加入「" + bunch + "」！\n");

        message_vision("$N邀请$n参加帮会「" + bunch + "」。\n", me, ob);
        
        if (! playerp(ob))        
        {
                if (! ob->query("bunch/zhengzhao") || ! ob->is_bunch_npc())
                        return notify_fail("看样子" + ob->query("name") +
                                "对你的帮会没有兴趣。\n");
                                
                if (sizeof(BUNCH_D->query_npcs(bunch)) > BUNCH_D->query_bunch_fame(bunch) / 500000)
                        return notify_fail("由于你的帮派声望不够，看样子" + ob->query("name") +
                                "对你的帮会没有兴趣。\n");
                                
                switch (ob->query("bunch/zhengzhao"))  
                {
                case 1: 
                        if ((! stringp(bunch = ob->query("bunch/bunch_name")) ||
                            ob->query("bunch/zhongcheng") < me->query("meili")) &&
                            ob->query("qi") * 100 > ob->query("max_qi") * 80) 
                        {
                                message_vision("$N对$n说道：“即是如此，你我不如切磋(qiecuo)一下武功如何？”\n",
                                               ob, me);
                                ob->set_temp("invite/target", me);
                                return 1;
                        }
                        message_vision("$N冲着$n笑道：“我可不敢高攀贵帮啊。”\n", ob, me);
                        return 1;
                        
                case 2: 
                        if (! (bunch = ob->query("bunch/bunch_name")) ||
                            ob->query("bunch/zhongcheng") < me->query("meili"))    
                        {
                                money = ob->query("combat_exp") / 1000;
                                
                                if (money < 1) money = 1;
                                
                                money = money * 1000;
                                message_vision("$N「嘿嘿」了几声，对$n道：“" +
                                               chinese_number(money / 1000) + "两黄金，少一个子也不行。　盶n",
                                               ob, me);
                                ob->set_temp("invite/target", me);
                                ob->set_temp("invite/money", money);
                                return 1;
                        }
                        message_vision("$N冲着$n笑道：“我可不敢高攀贵帮啊。”\n", ob, me);
                        return 1;
                        
                case 3: 
                        if (! (bunch = ob->query("bunch/bunch_name")) 
                        ||  ob->query("bunch/zhongcheng") < me->query("meili"))    
                        {
                                data = ob->query_temp("invite/target");
                                
                                if (! mapp(data)) data = ([]);
                                
                                target = keys(data);
                                
                                if (member_array(me->query("id"), target) != -1) 
                                {
                                        sscanf(data[me->query("id")], "%s:%s", stuffid, stuffname);
                                        message_vision("$N对$n大声道：我不是说过了吗？把" +
                                                       stuffname + "(" + stuffid + ")给我找来！\n",
                                                       ob, me);
                                        return 1;
                                }
                                
                                if (sizeof(target) >= 4)           
                                {
                                        message_vision("$N笑道：承蒙大家看得起，" +
                                                       RANK_D->query_respect(ob) + "不胜感激。\n",
                                                       ob);
                                        return 1;
                                }
                                
                                what = keys(npcneed);
                                stuffid = what[random(sizeof(what))];
                                stuffname = npcneed[stuffid];
                                data[me->query("id")] = stuffid + ":" + stuffname;
                                ob->set_temp("invite/target", data);
                                message_vision("$N冲着$n道：只要你能在三分钟之内把" +
                                               stuffname + "(" + stuffid + ")" +
                                               "给我找来，一切好商量。\n",
                                               ob, me);
                                               
                                // remove_call_out("delete_target");
                                call_out("delete_target", 180, ob, me->query("id"));
                                return 1;
                        }
                        message_vision("$N冲着$n笑道：“我可不敢高攀贵帮啊。”\n", ob, me);
                        return 1;
                }
        } else    
        {
                tell_object(ob, "如果你愿意加入对方的帮会，请使用 jiaru " + me->query("id") + "。\n");
                ob->set_temp("invite/target", me);
                return 1;
        }
}

void delete_target(object npc, string name)
{
        mapping data;
        
        if (! objectp(npc)) return;
        
        data = npc->query_temp("invite/target");
        
        if (! mapp(data))   return;
        
        map_delete(data, name);
        npc->set_temp("invite/target", data);
}


int help(object me)
{
        write(@HELP
指令格式：invite | yaoqing <某人>
这个指令用来邀请某人加入你的帮会。某人可以是玩家或是可征招的ＮＰＣ。
注意：邀请玩家加入帮会，你必须是在帮会中是有身份的人。

相关指令：join
HELP
        );
        return 1;
}



