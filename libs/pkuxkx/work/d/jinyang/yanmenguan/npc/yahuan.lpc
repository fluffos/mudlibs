//Zine xiaoyuanshan

#include <ansi.h>
inherit NPC;
void exer();
#include "yanmen_xiao_npc.h"

void create()
{ 
        set_name("丫鬟",({"ya huan","yahuan"}));
        set("long","她是萧夫人的丫鬟。\n");
        set("gender", "女性" );
        set("age", 18);
        set("per",35);
        set("int",25);
        set("con",25);
        set("dex",25);
        set("str",25);     
        set("max_qi", 60000);
        set("eff_qi", 60000);
        set("qi", 60000);
        set("max_jing", 9000);
        set("jing", 9000);
        set("neili", 9000);
        set("max_neili",9000);
        set("jiali", random(50));        
        set("combat_exp", 1000000);
        set_skill("literate",500);
        set_skill("cuff", 500); 
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("force", 500);
        set_skill("meinu-quan",500);
        set_skill("xianyun", 500);
        set_skill("yunu-xinfa", 500);
        map_skill("force","yunu-xinfa");
        map_skill("cuff", "meinu-quan");  
        map_skill("dodge","xianyun");
        map_skill("parry","meinu-quan");
        prepare_skill("cuff", "meinu-quan");
        set("chat_chance_combat", 150);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
        set("yanmen_npc",5);
        set("medicine",4);
        set("family/family_name","古墓派");
        set_temp("yanmen/permit",1);
        
     
        setup();
        carry_object("/clone/armor/tiejia")->wear();
        carry_object("/clone/weapon/jian")->wield();
        call_out("check_status",1);
}
void exer()
{
    object *enemy,target,weapon,weapon2;
    object obj;
    if (!living(this_object()))
    return;
    command("exert recover");
    enemy = query_enemy();
    target = enemy[random(sizeof(enemy))];
	weapon = this_object()->query_temp("weapon");
    weapon2 = this_object()->query_temp("secondary_weapon");
    command("exert xinjing");
	if (!weapon)
    {
        obj=new("/obj/gem/weapon");
        obj->gen_weapon(8,9900,9999,"sword");
        obj->move(this_object());
        command("wield all");
        weapon=this_object()->query_temp("weapon");
        weapon->set("no_get",1);
        weapon->set("no_drop_to_room",1);
    }
    if (!weapon2)
    {
        obj=new("/obj/gem/weapon");
        obj->gen_weapon(8,9900,9999,"sword");
        obj->move(this_object());
        command("wield all");
        weapon2 = this_object()->query_temp("secondary_weapon");
        weapon2->set("no_get",1);
        weapon2->set("no_drop_to_room",1);
    }
    
            command("unwield all");
            command("prepare none");
            command("enable cuff meinu-quan");
            command("enable parry meinu-quan");
            command("prepare cuff");
            command("perform cuff.shexin " +target->query("id"));
            command("wield all");
           
}


int continue_move()
{
    object ob=this_object();
    object env=environment(ob);
    if (env&&env->query("road_no")==1)
    {
        command("southwest");
    }
    if (env&&env->query("road_no")==2)
    {
        command("south");
    }
    if (env&&env->query("road_no")==3)
    {
        command("south");
    }
    if (env&&env->query("road_no")==4)
    {
        command("southwest");
    }
    if (env&&env->query("road_no")==5)
    {
        command("southeast");
    }
    if (env&&env->query("road_no")==6)
    {
        command("south");
    }
    if (env&&env->query("road_no")==7)
    {
        command("southeast");
    }
    if (env&&env->query("road_no")==9)
    {
        command("south");
    }
    if (env&&env->query("road_no")==11)
    {
        command("southwest");
    }
    if (env&&env->query("road_no")==13)
    {
        command("southwest");
    }
    if (env&&env->query("road_no")==14)
    {
        command("west");
    }
    ob->set("yanmen/last_go",time());
}