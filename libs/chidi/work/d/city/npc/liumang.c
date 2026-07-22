// liumang.c 流氓

#include <ansi.h>
inherit BHNPC;
void create()
{
        set_name("流氓", ({ "liu mang", "liu" }));
        set("gender", "男性");
        set("age", 19);
        set("long", "他是一个成天游手好闲的流氓，长得倒是白白胖胖的，也许以前有过钱。\n");
        
        set("combat_exp", 1000);
        set("shen_type", -1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        setup();
        carry_object("/clone/misc/hic_cloth")->wear();
        add_money("silver",2);
}
/*
void init()
{
        object ob;
        ob = this_player();     
        ::init();
        if( interactive(ob) && !is_fighting() )
               {
                        remove_call_out("greeting");
                        call_out("greeting", 3, ob);
                }
}
void greeting(object ob)
{
   if( !ob || environment(ob) != environment() ) return;
     command("es " + HIM"\n
                "HIR" 江湖 "HIY"("HIG"IP: "HIW"61.132.93.196 "HIG"Port: "HIW"6666"HIY")\n
                 "HIC"12月18日全新开站，欢迎大家加入游戏！
                 新手奖励 200000 经验及200段读书识字和300级基本内功！
                 最完整的升官和帮派系统，还能离线练功,修建城堡,王朝战争等！！
                 
     "NOR);
}

*/
