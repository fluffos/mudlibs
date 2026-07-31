 // thousand_hand.c
#include <ansi.h> 
inherit NPC;
void create()
{
        set_name("劲装少年" , ({ "guard", "young man" }) );
        set("long", "一个劲装少年，是负责山庄巡视的。\n");
        set("attitude", "friendly");
/*      set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500); */
        set("age", 18+random(10));
        set("gender", "男性" );
/*      set("str", 35);
        set("cor", 30);
        set("cps", 25);  */
        create_family("清平山庄", 1, "庄丁");
        set("combat_exp", 50000+random(50000));
        set_skill("dodge", 30+random(50));
        set_skill("unarmed", 50+random(30));
        set_skill("sword", 45+random(20));
        set_skill("qingpingsword", 30+random(30));
        set_skill("force", 60);
        set_skill("qingpingforce", 55);
        set_skill("chaos-steps", 54);
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengzijue" :),
        }) ); 
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}   
