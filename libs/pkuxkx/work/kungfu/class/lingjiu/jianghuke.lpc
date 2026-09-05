inherit NPC;
#include <ansi.h>
#include "huwei_target.h"

void auto_perform();
void create()
{
      	string weapon;
   	int i = random(sizeof(names));
        int j = random(sizeof(nm2));
        int k = random(sizeof(nm3));

        set_name(names[i]+nm2[j]+nm3[k], ({ids[i]+" "+nm2s[j]+nm3s[k],ids[i]}));
	set("per", random(26) + 10);
        set("gender", "男性");
        set("age", random(20) + 25);
        set("str", random(10) + 21);
        set("con", random(10) + 21);
        set("int", random(10) + 21);
        set("dex", random(10) + 21);
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("blade", 50);
        set_skill("finger", 50);
         set_skill("whip", 50);
         set_skill("riyue-bian", 100);
	set_skill("nianhua-zhi", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("wuying-jian", 100);

	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "hunyuan-yiqi");
	map_skill("parry", "nianhua-zhi");
	map_skill("sword", "wuying-jian");
        map_skill("whip", "riyue-bian");
	prepare_skill("finger", "nianhua-zhi");
	set("title",HIW"少林派弟子"NOR);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 20+random(30));

        set("no_steal",1);
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
         weapon = random(2)?"/clone/weapon/changjian":"/d/gumu/obj/changbian";
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

	if (random(5)>0)
	{
        	switch( random(5) )
        	{
            		case 0:
            		command("wield jian");
            		command("perform sword.wuying " + target->query("id"));
		        break;	
            		case 1:
             		case 2:
            		command("unwield jian");
             		command("unwield bian");
            		command("perform finger.fuxue " +target->query("id"));
            		command("wield jian");
             		command("wield bian");
             		break;
             		case 3:
             		case 4:
             		command("wield bian");
             		command("perform whip.chan " + target->query("id"));
              		break;
             	}
	}
}
