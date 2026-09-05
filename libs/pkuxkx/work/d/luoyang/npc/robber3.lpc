//gemini改于2000.4.4 使得复制时不参考literate等级

#include <ansi.h>
inherit NPC;
#include "robber.h"
void exer();
void create()
{ 
        set_name(HIB"劫匪"NOR,({"cart robber","robber"}));
        set("title","拦路抢劫");
        set("long","这是一位星宿派弃徒。\n");
        set("gender", "男性" );
        set("bonus",1);
        set("age", random(30)+14);
        set("no_use/qiankun-danuoyi",1);        
        set("no_use/iron-cloth",1);        
        set("vendetta/authority", 1);
       	set("max_qi", 3000);
        set("eff_qi", 3000);
        set("qi", 3000);
        set("max_jing", 3000);
        set("jing", 3000);
        set("neili", 3000);
        set("max_neili", 2000);
        set("jiali", random(200));
        set("busy",1);
	//set("shen",-100);
        //set("shen_type", -10);
        set("combat_exp", 800000);

        set_skill("force", 80); 
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("tianshan-zhang", 300);
        set_skill("strike",300);
        set_skill("xingxiu-duzhang",300);
        set_skill("staff", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("zhaixinggong", 300);
        set_skill("force", 300);
        set_skill("huagong-dafa", 300);
        map_skill("force","huagong-dafa");

        map_skill("staff","tianshan-zhang");
        map_skill("dodge","zhaixinggong");
        map_skill("parry","tianshan-zhang");
        map_skill("strike","xingxiu-duzhang");
	prepare_skill("strike", "xingxiu-duzhang");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );

     
        setup();
        carry_object("/d/xingxiu/obj/bingpozhang")->wield();
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
	        carry_object("/d/xingxiu/npc/obj/bingpozhang")->wield();
        weapon=this_object()->query_temp("weapon");
        weapon->set("no_get",1);
		weapon->set("no_drop_to_room",1);
	switch( random(3) )
        {
            case 0:
            command("exert staff.handu " + target->query("id"));
             break;
            case 1:
            command("perform staff.handu " +target->query("id"));
            break;
            case 2:
            command("unwield zhang");
           command("perform strike.sandu " + target->query("id"));
            command("wield zhang");
            break;
        }
}
