 // apstone, inc. c 1998
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("李豹", ({ "lee", "lee bao" }) );
        set("long","新疆的最大的盐行老板，人家都称他为＂李老大＂\n");
        set("gender","男性");
        set("age", 39);
        set("combat_exp", 100000);
        set_skill("unarmed",100);
        set("chat_chance", 15);
        set("chat_msg", ({
                "李豹道：缺银子花么？帮我装盐（work），一马车一两银子！\n",
                "李豹指着你：别偷懒，快干活！\n",
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        ::init();
        add_action("do_work", "work"); 
}
int do_work(string arg)
{
        object ob;
        object me;
        me = this_player();
if(me->is_busy()) return notify_fail("你的动作还没有完成，不能工作。\n");
message_vision("$N结束装满了一车盐，可人也累的要死\n",me);
me->receive_wound("jing",30);
me->receive_wound("qi",30);
ob = new("/clone/money/silver");
ob->move(me);
message_vision("李豹干笑了两声，对$N说：这是你的工钱。\n", me);
me->start_busy(2);
return 1;
}     
