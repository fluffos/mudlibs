#include <ansi.h>
//inherit NPC;
inherit NPC;

int estate();
void create()
{
        set_name("马方中",({"ma fangzhong","ma"}));
        set("title","与世无争");
        set("long","
马方中这个人就象他的名字一样，方方正正，规规矩矩，从出生到现在，
从来没有做过任何一件令人觉得惊奇意外的事。别人觉得应该成亲的时候，
他就成了亲，别人觉得应该生儿育女的时候，他就不多不少生了两个。种
花是他最大的嗜好。\n");
        
        set("gender","男性");
        set("group","ma");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        set("marry","马月云");
        set("marry_name","ma yueyun");
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",8500000);  
        set("attitude", "friendly");
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
           "老伯": "老伯是我的兄弟，我的朋友，也是我的父母，若没有他，我在十六岁
的时候已经被人杀死了。",
                "孙玉伯":       "老伯是我的兄弟，我的朋友，也是我的父母，若没有他，我在十六岁
的时候已经被人杀死了。",
        ]));
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(30) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                "\n天高气爽，风吹在身上，不冷也不热。马方中还在院子里流连着，舍不得回
房睡觉。\n",
        }) );                   
        
//        auto_npc_setup();("wang",300,200,0,"/obj/weapon/","fighter_u","nine-moon-claw",1);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
 
}  
