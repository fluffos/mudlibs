// robber1 for dart
//gemini改于2000.4.4 使得复制时不参考literate等级

#include <ansi.h>
inherit NPC;
#include "robber.h"
void exer();
void create()
{ 
        set_name(HIR"劫匪"NOR,({"cart robber","robber"}));
        set("title","拦路抢劫");
        set("long","这是一位全真派弃徒。\n");
        set("gender", "男性" );
        set("bonus",2);
        set("zuoyou-hubo", 1);
        set("age", random(30)+14);
        set("no_use/qiankun-danuoyi",1);        
        set("no_use/iron-cloth",1);        
        set("pursuer", 1);
        set("bellicosity", 100000);
        set("max_qi", 3000);
        set("eff_qi", 3000);
        set("qi", 3000);
        set("max_jing", 3000);
        set("jing", 3000);
        set("neili", 2500);
        set("max_neili",2500);
        set("jiali", random(200));        
        set("busy",1);
	//set("shen",-100);
        //set("shen_type", -10);
        set("combat_exp", 900000);

        create_family("全真派",3,"弟子");
        set_skill("force", 80); 
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("tonggui-jian", 300);
        set_skill("quanzhen-jian", 300); 
        set_skill("yiyang-zhi", 300);  
        set_skill("finger", 300); 
        set_skill("unarmed",300);
        set_skill("kongming-quan",300);
        set_skill("dodge", 300);
        set_skill("cuff", 300);
        set_skill("sword", 300);
        set_skill("parry", 300);
        set_skill("force", 300);
        set_skill("fx-step", 300);
        set_skill("xiantian-gong", 300);
        map_skill("force","xiantian-gong");
        map_skill("sword","quanzhen-jian");
        map_skill("finger", "yiyang-zhi");  
        map_skill("dodge","fx-step");
        map_skill("parry","quanzhen-jian");
        map_skill("cuff", "kongming-quan");
        prepare_skill("cuff", "kongming-quan");
	set("zuoyou-hubo",1);
	set("jiali",300);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );

     
        setup();
        carry_object("/clone/weapon/changjian")->wield();
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
//    command("perform sword.tonggui" + target->query("id"));
	weapon = this_object()->query_temp("weapon");
	if (!weapon)
		carry_object("/d/pingxiwangfu/npc/obj/herosword")->wield();
        weapon=this_object()->query_temp("weapon");
        weapon->set("no_get",1);
		weapon->set("no_drop_to_room",1);
    command("perform sword.jianqi" + target->query("id"));    
    switch( random(7) )
        {
            case 0:
            command("unwield jian");
            command("perform cuff.hubo " +target->query("id"));
            command("wield jian");
            break;
            case 1:
            command("perform sword.sanqing " +target->query("id"));
            break;
            case 2:
            if (target->query("qi") > (target->query("max_qi")-100))
            	command("perform sword.qixing " + target->query("id"));
            break;  
            case 3:
            command("perform sword.jianzhen " +target->query("id"));
            break;  
            case 4:
             command("enable sword tonggui-jian");  
            command("perform sword.qixing " +target->query("id"));
            command("enable sword quanzhen-jian"); 
            break; 
            case 5:
            command("prepare none");  
            command("prepare yiyang-zhi");  
            command("perform finger.qiankun-yizhi " +target->query("id"));
            command("prepare none"); 
            command("prepare kongming-quan"); 
            break; 
            case 6:
            command("prepare none"); 
            command("prepare yiyang-zhi"); 
            command("perform finger.fuxue " +target->query("id"));
            command("prepare none"); 
            command("prepare kongming-quan");  
            break; 
        }
}


