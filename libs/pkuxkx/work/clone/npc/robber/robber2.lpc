//gemini改于2000.4.4 使得复制时不参考literate等级

#include <ansi.h>
inherit NPC;
#include "robber.h"
void exer();
void create()
{ 
        set_name(HIW"蒙面人"NOR,({"mengmian ren","robber"}));
        set("long","这是一位武当派弃徒。\n");
        set("gender", "男性" );
        set("bonus",1);
        set("age", random(30)+14);
        set("no_use/qiankun-danuoyi",1);        
        set("no_use/iron-cloth",1);        
        set("vendetta/authority", 1);
        set("max_qi", 5000);
        set("eff_qi", 5000);
        set("qi", 5000);
        set("max_jing", 3000);
        set("jing", 3000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("busy",1);
        set("jiali", random(200));
	set("shen",-100);
        set("shen_type", -10);
        set("combat_exp", 700000);

        set_skill("force", 80); 
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("taiji-jian", 300);
        set_skill("hand",300);
        set_skill("cuff",300);
        set_skill("taiji-quan",300);
        set_skill("dodge", 300);
        set_skill("sword", 300);
        set_skill("parry", 300);
        set_skill("tiyunzong",300);
        set_skill("force", 300);
        set_skill("taiji-shengong", 300);
        map_skill("force","taiji-qigong");

        map_skill("sword","taiji-jian");
        map_skill("dodge","tiyunzong");
        map_skill("parry","taiji-jian");
        map_skill("cuff","taiji-quan");
        prepare_skill("cuff", "taiji-quan");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );

     
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/armor/tiejia")->wear();
        call_out("start_attact",5,this_object());
}
void exer()
{
    object *enemy,target,weapon;

    command("exert powerup");
    command("exert recover");
    if (this_object()->query("busy"))
    	return;
    enemy = query_enemy() - ({ 0 });
    target = enemy[random(sizeof(enemy))];
	weapon = this_object()->query_temp("weapon");
	if (!weapon)
		carry_object("/d/pingxiwangfu/npc/obj/herosword")->wield();
        weapon=this_object()->query_temp("weapon");
        weapon->set("no_get",1);
    switch( random(3) )
        {
            case 0:
            command("exert force " + target->query("id"));
             break;
            case 1:
            command("perform sword.chan " +target->query("id"));
            break;
            case 2:
            command("unwield jian");
            command("perform cuff.zhen " + target->query("id"));
            command("wield jian");
            break;
        }
}

