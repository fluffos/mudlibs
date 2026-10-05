// 放逐岛npc 头领
// Created by kuku@sjsh 2003.8

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("大野猪", ({"big pig", "head"}));        
        set("title", HIW"野猪头领"NOR);
        set("gender", "男性" );
        set("taskguai",1);
        set("age", 45);
        set("per", 30);
        set("str", 30);
        set("long","一头在岛上修炼多年业已成精的野猪，它是野猪的头领。\n");
        set("attitude", "aggressive");
        set("combat_exp", 80000000);
        set("daoxing", 80000000);
        set_skill("literate", 300);        
        set_skill("force", 600+random(150));
        set_skill("huomoforce", 600+random(150));
        set_skill("pingtian-dafa", 600+random(150));
        set_skill("spells", 600+random(150));
        set_skill("wuyue-spear", 600+random(150));
        set_skill("dali-bang",600+random(150));
        set_skill("dodge", 600+random(150));
        set_skill("parry", 600+random(150));     
        set_skill("spear", 600+random(150)); 
        set_skill("unarmed", 600+random(150));
        set_skill("moyun-shou", 600+random(150));        
        set_skill("moshenbu", 600+random(150));               
        map_skill("force", "huomoforce");
        map_skill("spells", "pingtian-dafa");        
        map_skill("parry", "wuyue-spear");
        map_skill("dodge", "moshenbu");
        map_skill("spear", "wuyue-spear");
        map_skill("unarmed", "moyun-shou");

        set("sen",5000);
        set("max_sen", 5000);
        set("kee",5000);
        set("max_kee", 5000);
        set("force", 8000); 
        set("max_force", 8000);        
        set("max_mana", 8000);
        set("mana", 8000);
        set("food",10000);
        set("water",10000);
        create_family("火云洞",2 , "弟子");        

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "spear","buhui" :),               
        }) );
        set_temp("apply/armor", 500);
        set_temp("apply/dodge", 500);

        setup();
        carry_object("/d/obj/drug/jinchuang");        
        carry_object("/d/obj/drug/hunyuandan");
        carry_object("/d/obj/weapon/spear/jinqiang")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}

void heart_beat() 
{                 
        object guai = this_object();         
        
        if ( !is_fighting() 
        && query("eff_kee") >= query("max_kee") / 2 
        && !query_skill("tonsillit",1)         
        && query("eff_kee") <  query("max_kee") ){ 
            set("eff_kee",query("max_kee")); 
            set("eff_sen",query("max_sen")); 
        } 
        if (query("kee") < query("eff_kee")-10 ) 
            command("exert recover"); 
        if (query("sen") < query("eff_sen")-10) 
            command("exert refresh"); 
        if (query("force") < query("max_force")/10) 
            command("cast transfer"); 
        
        ::heart_beat(); 
} 

void die()
{
        object killer;
        
        killer = this_object()->query_temp("last_damage_from"); 
        if(killer->query("impurity")>0){
                killer->add("impurity",-5);
                tell_object(killer,HIR"你觉得自己的罪孽在逐渐的消失。\n" NOR); 
        }
        killer->add("fz_kgnum",1);
}
