// mirror.c     镜子
// by bing

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW +"镜子"+ NOR, ({ "jingzi" }));
        set("long","一块神通广大的魔镜！\n");
        set_weight( 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("no_give_user",1);
                set("value",100000);
                set("no_drop", "这东西不能扔。\n");
                set("no_steal", 1);
                set("no_sell",1);
                set("no_pawn",1);
                set("value",1000000);
                set("material", "gold");
        }
        setup();
}       

void init()
{
        add_action("do_zhao","zhao");
}

int do_zhao()
{
        int i,j,number,data;
        string msg;
        object me,user, *users;
        me = this_player();
        users = users();

        number = 1;
        data = 0;

        j = random(6);
        if (j == 0)
        {
                message_vision("$N对着镜子说「镜子镜子，这个世界上现在谁最美？」\n",me);
                for(i=0; i<sizeof(users); i++) {
                        if( users[i]->query("per")>data && wiz_level(users[i])==0)
                        {
                                data = users[i]->query("per");
                                user = users[i];
                        }
                        if( users[i]->query("per")>me->query("per") && wiz_level(users[i])==0)
                                number++;

                }
                if (user != me)
                        msg = "镜子对$N说道：「这个世界上现在" + user->query("name") + "最美，你呀只能排第" + number + "。」\n";
                else msg = "镜子对$N说道：「这个世界上现在你最美，你就是这个世界上最美的人。」\n";
        }
        
        if (j == 1)

        {
                message_vision("$N对着镜子说「镜子镜子，这个世界上现在谁最富有？」\n",me);
                for(i=0; i<sizeof(users); i++) {
                        if( users[i]->query("balance")>data && wiz_level(users[i])==0) 
                        {
                                data = users[i]->query("balance");
                                user = users[i];
                        }
                       if( users[i]->query("balance")>me->query("balance") && wiz_level(users[i])==0 )
                                number++;

                }
                if (user != me)
                        msg = "镜子对$N说道：「这个世界上现在" + user->query("name") + "最富有，你呀只能排第" + number + "。」\n";
                else msg = "镜子对$N说道：「这个世界上现在你最富有，你就是这个世界上最富有的人。」\n";
        }

        if (j == 2)
        {
                message_vision("$N对着镜子说「镜子镜子，这个世界上现在谁最强？」\n",me);
                for(i=0; i<sizeof(users); i++) {
                        if( users[i]->query("combat_exp")>data && wiz_level(users[i])==0 ) 
                        {
                                data = users[i]->query("combat_exp");
                                user = users[i];
                        }
                        if( users[i]->query("combat_exp")>me->query("combat_exp") && wiz_level(users[i])==0)
                                number++;

                }
                if (user != me)
                        msg = "镜子对$N说道：「这个世界上现在" + user->query("name") + "最强，你呀只能排第" + number + "。」\n";
                else msg = "镜子对$N说道：「这个世界上现在你最强，你就是这个世界上最强的人。」\n";
        }
                if (j == 3)
        {
                message_vision("$N对着镜子说「镜子镜子，这个世界上现在谁内力最高？」\n",me);
                for(i=0; i<sizeof(users); i++) {
                        if( users[i]->query("max_neili")>data && wiz_level(users[i])==0 ) 
                        {
                                data = users[i]->query("max_neili");
                                user = users[i];
                        }
                        if( users[i]->query("max_neili")>me->query("max_neili") && wiz_level(users[i])==0)
                                number++;

                }
                if (user != me)
                        msg = "镜子对$N说道：「这个世界上现在" + user->query("name") + "的内力最高，你呀只能排第" + number + "。」\n";
                else msg = "镜子对$N说道：「这个世界上现在你的内力最高，你就是这个世界上内力最高的人。」\n";
        }
                if (j == 4)
        {
                message_vision("$N对着镜子说「镜子镜子，这个世界上现在谁的精力最高？」\n",me);
                for(i=0; i<sizeof(users); i++) {
                        if( users[i]->query("max_jingli")>data && wiz_level(users[i])==0 ) 
                        {
                                data = users[i]->query("max_jingli");
                                user = users[i];
                        }
                        if( users[i]->query("max_jingli")>me->query("max_jingli") && wiz_level(users[i])==0)
                                number++;

                }
                if (user != me)
                        msg = "镜子对$N说道：「这个世界上现在" + user->query("name") + "的精力最高，你呀只能排第" + number + "。」\n";
                else msg = "镜子对$N说道：「这个世界上现在你的精力最高，你就是这个世界上精力最高的人。」\n";
        }
                if (j == 5)
        {
                message_vision("$N对着镜子说「镜子镜子，这个世界上现在谁最老？」\n",me);
                for(i=0; i<sizeof(users); i++) {
                        if( users[i]->query("age")>data && wiz_level(users[i])==0 ) 
                        {
                                data = users[i]->query("age");
                                user = users[i];
                        }
                        if( users[i]->query("age")>me->query("age") && wiz_level(users[i])==0)
                                number++;

                }
                if (user != me)
                        msg = "镜子对$N说道：「这个世界上现在" + user->query("name") + "最老，你呀只能排第" + number + "。」\n";
                else msg = "镜子对$N说道：「这个世界上现在你最老，你就是这个世界上最老的人。」\n";
        }
        message_vision(msg,me);
 
        return 1;
}
