// 放逐岛npc 普通
// Created by kuku@sjsh 2003.8

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("猛虎", ({"meng hu", "tiger"}));        
        set("title","野兽");
        set("gender", "男性" );
        set("taskguai",1);
        set("age", 45);
        set("per", 30);
        set("str", 30);
        set("long","一只在岛上修炼多年业已成精的猛虎。\n");
        set("combat_exp", 50000000);
        set("daoxing", 50000000);
        set_skill("literate", 300);
        set_skill("unarmed", 400+random(150));
        set_skill("force", 400+random(150));
        set_skill("lengquan-force", 400+random(150));
        set_skill("dengxian-dafa", 400+random(150));
        set_skill("bawang-qiang", 400+random(150));
        set_skill("jinglei-mace",400+random(150));
        set_skill("mace",400+random(150));
        set_skill("axe", 400+random(150));
        set_skill("dodge", 400+random(150));
        set_skill("parry", 400+random(150));
        set_skill("sanban-axe", 400+random(150));
        set_skill("bawang-qiang", 400+random(150));
        set_skill("spells", 400+random(150));
        set_skill("baguazhou", 400+random(150));
        set_skill("spear", 400+random(150));
        set_skill("yanxing-steps", 400+random(150));
        set_skill("changquan",400+random(150));
        map_skill("force", "lengquan-force");
        map_skill("spells", "baguazhou");
        map_skill("axe", "sanban-axe");
        map_skill("parry", "sanban-axe");
        map_skill("dodge", "yanxing-steps");
        map_skill("spear", "bawang-qiang");
        map_skill("mace", "jinglei-mace");
        map_skill("unarmed", "changquan");

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
        create_family("将军府",2 , "弟子");        
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
                killer->add("impurity",-1);             
                tell_object(killer,HIR"你觉得自己的罪孽在逐渐的消失。\n" NOR); 
        }
        killer->add("fz_kgnum",1);
}
