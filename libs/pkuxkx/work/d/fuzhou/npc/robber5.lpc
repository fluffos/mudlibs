// robber1 for dart
//gemini改于2000.4.4 使得复制时不参考literate等级

#include <ansi.h>
inherit NPC;
#include "robber.h"
void exer();
void create()
{ 
        set_name(HIC"劫匪"NOR,({"cart robber","robber"}));
        set("title","拦路抢劫");
        set("long","这是一位桃花岛弃徒。\n");
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

        create_family("桃花岛",3,"弟子");
        set_skill("force", 80); 
        set_skill("throwing", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("yuxiao-jian", 300);
        set_skill("fuxue-shou", 300); 
        set_skill("tanzhi-shengong", 300);  
        set_skill("finger", 300); 
        set_skill("hand",300);
        set_skill("music",300);
        set_skill("dodge", 300);
        set_skill("cuff", 300);
        set_skill("sword", 300);
        set_skill("parry", 300);
        set_skill("force", 300);
        set_skill("luoying-shenfa", 300);
        set_skill("bihai-shengong", 300);
        map_skill("force","bihai-shengong");
        map_skill("sword","yuxiao-jian");
        map_skill("hand", "fuxue-shou");  
        map_skill("dodge","luoying-shenfa");
        map_skill("parry","yuxiao-jian");
        map_skill("finger", "tanzhi-shengong");
        prepare_skill("finger", "tanzhi-shengong");
        prepare_skill("hand", "fuxue-shou");
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
    object obj; 
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
    command("perform sword.chan" + target->query("id"));    
    switch( random(6) )
        {
            case 0:
            command("unwield jian");
            command("perform hand.fuxue " +target->query("id"));
            command("wield jian");
            break;
            case 1:
                obj = new("/d/taohuadao/obj/shizi");
                obj->move(this_object());
                command("perform finger.tan " +target->query("id"));
                break;
            case 2:
                obj = new("/d/taohuadao/obj/shizi");
                obj->move(this_object());
                command("perform finger.tan " +target->query("id"));
                break;
            break;  
            case 3:
            command("perform sword.zouxiao " +target->query("id"));
            break;  
            case 4: 
            command("perform sword.xiaohua " +target->query("id"));
            break; 
            case 5:
            command("perform sword.xiaohua " +target->query("id"));
            break; 
        }
}


