inherit NPC;
#include <ansi.h>
#include "huwei_target_for_mingjiao.h"
//复制玩家能力函数
void auto_perform();

void create()
{
      	string weapon;
	//随机姓名
   	int i = random(sizeof(names));
        int j = random(sizeof(nm2));
        int k = random(sizeof(nm3));

        set_name(names[i]+nm2[j]+nm3[k], ({ids[i]+" "+nm2s[j]+nm3s[k],ids[i]}));
	set("per", random(26) + 10);
        set("age", random(20) + 25);
        set("str", random(10) + 21);
        set("con", random(10) + 21);
        set("int", random(10) + 21);
        set("dex", random(10) + 21);
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
        set("title",HIY"明教弟子"NOR);     
// 明教npc可以使用挪移
        set("no_use/qiankun-danuoyi",0);
        set_skill("jiuyang-shengong", 300);
	set_skill("dodge", 150);
        set_skill("datengnuo-bufa", 300);
        set_skill("strike", 200);
        set_skill("hanbing-zhang", 300);
       	set_skill("claw",200);
	set_skill("parry", 200);
	set_skill("sword", 200);
        set_skill("shenghuo-shengong", 300);
       	set_skill("blade", 200);
        set_skill("qiankun-danuoyi", 300);
        set_skill("medical-skill", 250);
	set_skill("literate", 100);

        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "datengnuo-bufa");
        map_skill("strike", "hanbing-zhang");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("sword", "shenghuo-shengong");

        prepare_skill("strike", "hanbing-zhang");
        set("no_steal",1);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
//         set_temp("apply/armor", 200);
//        set_temp("apply/damage", 20+random(30));
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
        set("jiali", 1);
	//随机两种武器
        weapon = ("/clone/weapon/changjian");
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
                switch( random(4) )
        	{
	            case 0:
	            command("wield jian");
                    command("perform sword.fenxin " + target->query("id"));
	             break;
	            case 1:
	            command("unwield blade");
                    command("perform dodge.tisha " +target->query("id"));
	            command("wield dao");
	             break;
	            case 2:
	            command("unwield jian");
                    command("perform strike.shixue " +target->query("id"));
	            command("wield jian");
	             break;
                    case 3:
                    command("enable parry shenghuo-shengong");
                    command("emote 圣火神功运用越来越快,心魔大盛,已经无法驾驭乾坤大挪移");
                     break;
             }
	}
}
