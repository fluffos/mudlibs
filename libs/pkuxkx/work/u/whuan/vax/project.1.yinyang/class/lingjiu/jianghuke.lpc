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
    	set("gender", "男性" );//性别与上面对应
        set("age", random(20) + 25);
        set("age", random(20) + 25);
        set("str", random(10) + 21);
        set("con", random(10) + 21);
        set("int", random(10) + 21);
        set("dex", random(10) + 21);
        set("combat_exp", 800000 + random(400000)); 
        set("attitude", "friendly");
        set("zuiquanpf",random(5)+1);
		
	apply_condition("drunk",100+random(100));
	set("shaqi",100);
	set("title",HIG"江湖客"NOR);        
	set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("blade", 50);
        set_skill("zui-quan", 50);
        set_skill("qingmang-jian", 50); 
        set_skill("xiake-shengong",50);
        set_skill("kuai-dao", 80+random(180));
        map_skill("blade", "kuai-dao");
        map_skill("parry", "kuai-dao");
        set_temp("apply/attack", 150);
        set_temp("apply/damage", 50);

	map_skill("dodge", "qingmang-jian");
        map_skill("sword", "qingmang-jian");
        map_skill("cuff", "zui-quan");
        map_skill("force", "xiake-shengong");

        prepare_skill("cuff", "zui-quan");         
        set("no_steal",1);
        set("chat_chance_combat", 90);
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
        weapon = random(2)?"/clone/weapon/gangdao":"/clone/weapon/changjian";
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
        weapon = this_object()->query_temp("weapon");
        weapon->set("no_get",1);
        
        if (random(3)>0) {
	        switch( query("zuiquanpf") )
	        {
	            case 1:
	            command("unwield jian");
	            command("unwield dao");
	            command("perform cuff.lhzj " + target->query("id"));
	            command("wield jian");
	            command("wield dao");
	             break;
	            case 2:
	            command("unwield jian");
	            command("unwield dao");
	            command("perform cuff.zsms " + target->query("id"));
	            command("wield jian");
	            command("wield dao");
	             break;
	            case 3:
	            command("unwield jian");
	            command("unwield dao");
	            command("perform cuff.zxhc " + target->query("id"));
	            command("wield jian");
	            command("wield dao");
	             break;
	             }
	}
}

