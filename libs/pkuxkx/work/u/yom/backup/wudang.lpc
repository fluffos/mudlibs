inherit NPC;
#include <ansi.h>
#include "huwei_target.h"
//复制玩家能力函数
void auto_perform();

void create()
{
      	string weapon;
	//随机姓名
   	int i = random(sizeof(names));
  	set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({ids[i]}));
	set("per", random(26) + 10);
        set("age", random(20) + 25);
        set("str", random(10) + 21);
        set("con", random(10) + 21);
        set("int", random(10) + 21);
        set("dex", random(10) + 21);
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
	set("title",HIY"武当派弟子"NOR);     
	set_skill("taiji-shengong", 300);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 300);
	set_skill("cuff", 200);
	set_skill("taiji-quan", 300);
       	set_skill("claw",200);
       	set_skill("taiji-zhao",300);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 300);
       	set_skill("blade", 200);
       	set_skill("taiji-dao", 300);
	set_skill("taoism", 250);
	set_skill("literate", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("claw", "taiji-zhao");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("blade", "taiji-dao");
	prepare_skill("cuff","taiji-quan");

        set("no_steal",1);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 20+random(30));
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
        set("eff_qi", 4500); 
        set("qi", 4500); 
        set("max_qi", 4500); 
        set("eff_jing", 4500); 
        set("jing", 4500); 
        set("max_jing", 4500); 
        set("eff_jingli", 4000); 
        set("neili", 5000); 
        set("max_neili", 5000);
        set("jiali", 30);
	//随机两种武器
        weapon = random(2)?"/clone/weapon/changjian":"/clone/weapon/gangdao";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/armor/tiejia")->wear();
}

void auto_perform()
{
        object *enemy,target;
        object weapon;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
	command("exert powerup");
	command("exert recover");
	
	weapon = this_object()->query_temp("weapon");
	if (!weapon)
		carry_object("/d/pingxiwangfu/npc/obj/herosword")->wield();
        if (random(3)>0)
	{
        	switch( random(3) )
        	{
	            case 0:
	            command("wield jian");
	            command("perform sword.chan " + target->query("id"));
	             break;
	            case 1:
	            command("unwield blade");
	            command("perform cuff.zhen " +target->query("id"));
	            command("wield dao");
	             break;
	            case 2:
	            command("unwield jian");
	            command("perform cuff.zhen " +target->query("id"));
	            command("wield jian");
	             break;
             }
	}
}
