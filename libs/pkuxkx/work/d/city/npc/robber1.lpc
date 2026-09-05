// robber1 for dart
//gemini改于2000.4.4 使得复制时不参考literate等级

#include <ansi.h>
inherit NPC;
#include "robber.h"
void exer();
void create()
{ 
        set_name(HIY"劫匪"NOR,({"cart robber","robber"}));
        set("long","这是一位丐帮叛徒。\n");
        set("title","拦路抢劫");
        set("gender", "男性" );
        set("bonus",1);
        set("age", random(30)+14);
        set("no_use/qiankun-danuoyi",1);        
        set("no_use/iron-cloth",1);        
        set("vendetta/authority", 1);
        set("bellicosity", 100000);
        set("max_qi", 5000);
        set("eff_qi", 5000);
        set("qi", 5000);
        set("max_jing", 900);
        set("jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
	//set("shen",-100);
        //set("shen_type", -10);
        set("combat_exp", 600000);
	set("busy",1);
        set_skill("force", 80); 
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("dagou-bang", 80);
        set_skill("unarmed",80);
        set_skill("xianglong-zhang",80);
        set_skill("dodge", 80);
        set_skill("staff", 80);
        set_skill("sword", 80);
        set_skill("parry", 80);
        set_skill("strike", 80);
        set_skill("force", 80);
        set_skill("huntian-qigong", 80);
        map_skill("force","huntian-qigong");
        map_skill("staff","dagou-bang");
        map_skill("dodge","xiaoyaoyou");
        map_skill("parry","dagou-bang");
        map_skill("unarmed","xianglong-zhang");
        map_skill("strike", "xianglong-zhang");
        prepare_skill("strike", "xianglong-zhang");
	set("leiting",1);
	set("jiali",300);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
     
        setup();
        carry_object("/kungfu/class/gaibang/yuzhu_zhang")->wield();
        carry_object("/clone/armor/tiejia")->wear();
        call_out("start_attact",5,this_object());
        call_out("dest",900);
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
		carry_object("/kungfu/class/gaibang/yuzhu_zhang")->wield();
        weapon=this_object()->query_temp("weapon");
        weapon->set("no_get",1);
		weapon->set("no_drop_to_room",1);
    switch( random(2) )
{
    case 0:
    command("perform staff.chan " + target->query("id"));
    break;
    case 1:
    if (random(100)>95)
    {
     command("unwield zhu");
    command("perform strike.leiting " + target->query("id"));   
     command("wield zhu");
	}
    break;
}
}
