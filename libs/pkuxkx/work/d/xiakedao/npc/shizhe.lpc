// Xiakedao NPC
// modified by aiai on 6/28/1999
// 侠客岛之 "黄衫使者"

#include <ansi.h>


inherit NPC;

void consider();
void heal();

void create()
{
	set_name(HIY"侠客岛使者"NOR, ({"shi zhe", "shi", "zhe"}));
        set("gender", "男性");
	set("age", 30);
	set("long", 
		"\n");
	set("attitude", "peaceful");
	set("shen_type", 1);
        set("str", 30);
        set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("chat_chance", 10);
 	set("chat_msg", ({
                (: heal :),
        }));

       
	set("max_qi", 2000);
        set("max_jing",2000);
        set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 200);
	
	set("combat_exp", 500000);
	set("score", 5000);
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
        	
	set_skill("parry",150);
	set_skill("force", 150);
	set_skill("strike", 150);
	set_skill("xiake-strike", 150);
	set_skill("dodge", 150);
	set_skill("xiake-shenfa", 150);
	set_skill("xiake-shengong",150);
	set_skill("xiake-jianfa",150);
	set_skill("sword",150);
	set_skill("throwing",150);
	map_skill("strike", "xiake-strike");
	map_skill("dodge", "xiake-shenfa");
	map_skill("force","xiake-shengong");
	map_skill("sword","xiake-jianfa");
	map_skill("parry","xiake-jianfa");
	prepare_skill("strike", "xiake-strike");

	create_family("侠客岛",4,"使者");
	
	setup();
//	carry_object("")->wield();
//      carry_object("")->wear();
}


void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        switch( random(2) )
        {
            case 0:
            	command("perform  " + target->query("id"));
             	break;
            case 1:
                command("perform  " + target->query("id"));
             	break;
             }
}

void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 200");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}


