//Zine xiaoyuanshan

#include <ansi.h>
inherit NPC;
void exer();
#include "yanmen_xiao_npc.h"

void create()
{ 
        set_name("萧夫人",({"xiao furen","xiao","furen"}));
        set("long","她是萧远山的夫人，巾帼不让须眉。\n");
        set("gender", "女性" );
        set("zyhb", 1);
        set("age", 28);
        set("per",40);
        set("int",45);
        set("con",35);
        set("dex",45);
        set("str",35);
        set("no_use/qiankun-danuoyi",1);        
        set("no_use/iron-cloth",1);        
        set("max_qi", 180000);
        set("eff_qi", 180000);
        set("qi", 180000);
        set("max_jing", 30000);
        set("jing", 30000);
        set("neili", 40000);
        set("max_neili",40000);
        set("jiali", 200+random(200));        
        set("combat_exp", 10000000);
        set_skill("literate",500);
        set_skill("cuff", 500); 
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("force", 500);
        set_skill("meinu-quan",500);
        set_skill("xianyun", 500);
        set_skill("yunu-xinfa", 500);
        set_skill("hand",500);
        set_skill("strike",500);
        set_skill("sword",500);
        set_skill("sanwu-shou",500);
        set_skill("chilian-shenzhang",500);
        set_skill("xuantie-jian",500);
        set_skill("jiuyin-shengong",500);
        set_skill("poison",500);
        map_skill("force","yunu-xinfa");
        map_skill("hand","sanwu-shou");
        map_skill("strike","chilian-shenzhang");
        map_skill("cuff", "meinu-quan");  
        map_skill("dodge","xianyun");
        map_skill("parry","xuantie-jian");
        map_skill("sword","xuantie-jian");
        prepare_skill("cuff", "meinu-quan");
        set("chat_chance_combat", 150);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
        set("yanmen_npc",4);
        set("medicine",10);
        set("family/family_name","古墓派");
        set_temp("yanmen/permit",1);
        set("赤炼五毒",1);
        set("special_skill/chainless", 1);
        set("special_skill/agile", 1);
        set("special_skill/energy",1);
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
    command("special chainless");
    command("special agile");
    command("qudu");
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
    switch( random(4) )
        {
            case 0:
            command("wield all");
            command("enable parry xuantie-jian");
            command("perform sword.xiongyong " +target->query("id"));
            break;
            
            case 1:
            command("unwield all");
            command("prepare none");
            command("enable cuff meinu-quan");
            command("enable parry meinu-quan");
            command("prepare cuff");
            command("perform cuff.shexin " +target->query("id"));
            command("wield all");
            break;  
            
            case 2:
            command("unwield all");
            command("prepare none");
            command("prepare strike");
            command("prepare hand");
            command("perform strike.wudu");
            command("wield all");
            break;
            case 3:
            command("unwield all");
            command("prepare none");
            command("prepare strike");
            command("prepare hand");
            command("perform hand.sanbu");
            command("wield all");
            break;
        }
           
}

int chalu(object ob)
{
    object ctrl=load_object("/d/jinyang/yanmenguan/center");
    object env=environment(ob);
    object xiao=ctrl->query("yanmen/xiao");
    if (environment(xiao)==env)
    {
        command("consider");
        command("nod");
        message_vision("在场众人决定分头保护萧远山和$N。\n",ob);
    }
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
        call_out("chalu",3,ob);
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
    gene_enemy(ob);
    ob->set("yanmen/last_go",time());
}