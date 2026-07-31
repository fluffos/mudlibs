#include <ansi.h>
inherit NPC;   
void create() 
{ 
        set_name("双双", ({ "shuang shuang","shuang" }) );
        set("gender", "女性"); 
        set("age", 19);
        set("title", "盲女");
    set("long","她的手臂细而纤弱，就象是个孩子，甚至比孩子还要瘦小。她的眼睛很大，但\n却灰蒙蒙的全无光彩，她是个瞎子。她的脸更奇怪，那并不是丑陋，也没有残\n缺，却象是一个拙劣工匠所制造出的美人面具，一个做得扭曲变了形的美人面\n具。这个可以令高立不惜为她牺牲一切的美人，不但是个发育不全的畸形儿，\n而且还是个瞎子。 。\n");
    set("combat_exp", 15000);
        set("attitude", "friendly"); 
        setup(); 
        carry_object("/clone/misc/cloth")->wear(); 
        this_object()->disable_player(" <昏迷不醒>");
        this_object()->set_temp("is_unconcious",1);
        set_temp("block_msg/all", 1);
       // COMBAT_D->announce(this_object(), "unconcious");
}   
