#include <ansi.h>

inherit NPC; 
//inherit SMART_NPC;

void create()
{ 
        set_name("薛斌",({"xuebin"}));
        set("title",YEL"好汉庄老庄主"NOR);
        set("long", "薛斌抬起手掩住嘴，轻轻地咳嗽着，阳光照在他身上，虽然还只不过是刚升起来的
阳光，但在他感觉中，却好像是夕阳。他自己却连夕阳无限好的时光都已过去，他
的生命已到了深夜。。\n");
        set("age",59);
        set("ill_boss",5);
        set("combat_exp", 5500000);
        set("attitude", "friendly");
                set("reward_npc", 1);
       set("difficulty", 20);
              set("no_busy", 9);


        
                set("class","knight");
        set_skill("unarmed", 180);

        set_skill("axe", 200);
        set_skill("literate", 140);
        set_skill("dodge", 140);

        set_skill("parry", 160);
        set_skill("force", 200);

        
        set("no_fly",1);
        
        //set("resistance/gin",30);
        //set("resistance/kee",50);
        //set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//         defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        

         
    
        //auto_npc_setup();("xuebin",200,180,1,"/obj/weapon/","fighter_w","xuanyuan-axe");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}  
