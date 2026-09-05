//Zine xiaoyuanshan

#include <ansi.h>
inherit NPC;
void exer();
#include "yanmen_xiao_npc.h"

void create()
{ 
        set_name("萧福",({"xiao fu","xiao","fu"}));
        set("long","他是萧远山的老管家。\n");
        set("gender", "男性" );
        set("zyhb", 1);
        set("age", 54);
        set("int",30);
        set("con",30);
        set("dex",30);
        set("str",30);
        set("max_qi", 40000);
        set("eff_qi", 40000);
        set("qi", 40000);
        set("max_jing", 10000);
        set("jing", 10000);
        set("neili", 5000);
        set("max_neili",5000);
        set("jiali", random(100));        
        set("combat_exp", 3000000);
        set_skill("luohan-quan", 500);
        set_skill("literate",500);
        set_skill("cuff", 500); 
        set_skill("buddhism",2000);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("force", 500);
        set_skill("hunyuan-yiqi", 500);
        set_skill("canhe-zhi",500);
        set_skill("halberd",500);
        set_skill("leizhendang",500);
        map_skill("force","hunyuan-yiqi");
        map_skill("cuff", "luohan-quan");  
        map_skill("dodge","yanling-shenfa");
        map_skill("parry","luohan-quan");
        map_skill("halberd","leizhendang");
        prepare_skill("cuff", "luohan-quan");
        set("chat_chance_combat", 150);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
        set("yanmen_npc",2);
        set("medicine",5);
        set("family/family_name","少林派");
        set("yanqing",1);
        set_temp("yanmen/permit",1);
        
     
        setup();
        carry_object("/clone/armor/tiejia")->wear();
        carry_object("/clone/weapon/fangtianji")->wield();
        carry_object("/clone/weapon/fangtianji")->wield();
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
    command("exert powerup");
    command("exert yihun "+target->query("id"));
	if (!weapon)
    {
        obj=new("/obj/gem/weapon");
        obj->gen_weapon(8,9900,9999,"halberd");
        obj->move(this_object());
        command("wield all");
        weapon=this_object()->query_temp("weapon");
        weapon->set("no_get",1);
        weapon->set("no_drop_to_room",1);
    }
    if (!weapon2)
    {
        obj=new("/obj/gem/weapon");
        obj->gen_weapon(8,9900,9999,"halberd");
        obj->move(this_object());
        command("wield all");
        weapon2 = this_object()->query_temp("secondary_weapon");
        weapon2->set("no_get",1);
        weapon2->set("no_drop_to_room",1);
    }
    
            command("wield all");
            command("perform halberd.leishen " +target->query("id"));
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
        command("southwest");
    }
    if (env&&env->query("road_no")==8)
    {
        command("south");
    }
    if (env&&env->query("road_no")==10)
    {
        command("southwest");
    }
    if (env&&env->query("road_no")==12)
    {
        command("south");
    }
    if (env&&env->query("road_no")==14)
    {
        command("west");
    }
    ob->set("yanmen/last_go",time());
}