inherit NPC;
#include <command.h>
#include <ansi.h>
#include "huwei_target.h"

string* nm4 = ({      //女性专用
"爱","春","丹","芳","芬","凤","姑","红","虹","娇","娟",
"菊","兰","岚","丽","莉","莲","玲","琳","娜","琴","芹",
"倩","萍","婷","霞","香","艳","燕","英","瑛","玉","珍",
"珠",
});

string* nm4s = ({      //女性专用
"ai","chun","dan","fang","fen","feng","gu","hong","hong","jiao","juan",
"ju","lan","lan","li","li","lian","ling","lin","na","qin","qin",
"qian","ping","ting","xia","xiang","yan","yan","ying","ying","yu","zhen",
"zhu",
});

void auto_perform();
void create()
{
      	string weapon;
   	int i = random(sizeof(names));

        int j = random(sizeof(nm2));
        int k = random(sizeof(nm4));
        set_name(names[i]+nm2[j]+nm4[k], ({ids[i]+" "+nm2s[j]+nm4s[k],ids[i]}));
   	set("per",35);
        set("gender", "女性");
        set("age", random(20) + 15);
        set("str", random(10) + 21);
        set("con", random(10) + 21);
        set("int", random(10) + 21);
        set("dex", random(10) + 21);
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
	set("title",HIG"峨嵋派弟子"NOR);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("blade", 50);
        set_skill("literate", 100);
        set_skill("mahayana", 150);

        set_skill("jinding-mianzhang", 100);
        set_skill("tiangang-zhi", 100);
        set_skill("fuliu-jian", 100);
        set_skill("yanxing-dao", 100);
        set_skill("zhutian", 100);
        set_skill("linji-zhuang", 100);

        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian");
        map_skill("strike","jinding-mianzhang");
        map_skill("sword","fuliu-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","fuliu-jian");
	prepare_skill("finger","tiangang-zhi");

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
        weapon = random(2)?"/clone/weapon/changjian":"/clone/weapon/gangdao";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/armor/tiejia")->wear();
}

void auto_perform()
{
        object *enemy,target, weapon;
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
	            command("perform sword.miejian " + target->query("id"));
	             break;
	            case 1:
	            command("wield jian");
	            command("perform sword.fuliu " + target->query("id"));
	             break;
	            case 2:
	            command("unwield blade");
	            command("unwield jian");
	            command("perform finger.lingkong " +target->query("id"));
	            command("wield jian");
	            command("wield blade");
	             break;
             	}
	}
}
