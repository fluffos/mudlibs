// chunyang.c 纯阳祖师

#include <ansi.h>
string ask_me();

inherit NPC;
inherit F_MASTER;

void create()
{
     set_name(HIW"纯阳祖师"NOR, ({"master chunyang", "master"}));
       set("long", "天一宫创教人，四百年前曾一人之力灭尽中土妖魔。\n");
       set("title", HIC"天一宫"NOR);
       set("per", 40);
       set("str", 60);
       set("gender", "男性");
       set("age", 40);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老祖师");
       set("max_kee", 20000);
       set("max_gin", 100);
       set("max_sen", 20000);
       set("force", 6000);
       set("max_force", 6000);
       set("force_factor", 240);
       set("max_mana", 4000);
       set("mana", 5000);
       set("mana_factor", 300);
       set("combat_exp", 8000000);
       set("daoxing", 8000000);

     

        create_family("三界山", 1, "蓝");
        
        set("inquiry", ([
        "name"     : "老夫乃天一宫创派人——郭纯阳。\n",
        "here"     : "此乃天一仙府也，能进来，也算你福泽不浅。\n",

        ]));
        
        set("time", 1);
        
        setup();
        carry_object("/d/xiyou/sanjie/obj/xuantian"); 
        carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
         carry_object("/d/xiyou/sanjie/obj/zhaoyangjian.c")->wield();
}
