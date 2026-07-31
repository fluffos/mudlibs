 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("中年和尚", ({ "shaolin monk", "monk"}) );
        create_family("东林寺", 20, "弟子");
        set("gender", "男性" );
        set("class", "shaolin");
        set("age",random(20)+ 32);
        set("nickname",HIY"棍僧"NOR);
        set("long", "这是东林寺的棍僧。\n");
        set("vendetta_mark","shaolin");
        set("combat_exp", 4000000);
        set("cps",80);
        set("attitude", "friendly");
        
        set_skill("staff", 150);
        set_skill("pudu-zhang",200);
        set_skill("move",200);
        set_skill("dodge",200);
        set_skill("force",200);
        set_skill("parry",200);
        set_skill("unarmed",200);
        set_skill("jingang-quan",200);
        map_skill("unarmed","jingang-quan");
        map_skill("staff", "pudu-zhang");
        map_skill("parry", "pudu-zhang");
        map_skill("dodge","shaolin-shenfa");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                name()+"笑道：在东林寺撒野？\n",
                (: perform_action, "staff.hequhecong" :),
        }) );
        
        set("neili",1000);
        set("max_neili",1000);
   set("force_factor",40);
        set("mana", 500);
        set("max_mana", 500);
        
        set("resistance/sen",10);
        set("resistance/gin",10);
        set("resistance/kee",10);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"头一偏，整个人差点睡倒在地上。\n",
                name()+"神色端庄，口中振振有辞。\n",
                name()+"双眼微闭，嘴唇微动。。。\n",
                name()+"全身就像一块石头一样，一动不动。\n"
        }) );
        setup();
        carry_object(__DIR__"obj/monk20_cloth")->wear();
        carry_object(__DIR__"obj/stick")->wield();
}   
