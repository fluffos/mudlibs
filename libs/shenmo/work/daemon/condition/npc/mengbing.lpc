#include <ansi.h>
inherit NPC;

int do_copy(object me,int maxpot,int type);

void create()
{
      string weapon;
        set_name("蒙古大汉", ({ "menggu dahan","dahan"}));
        set("gender", "男性");
        set("age", random(20) + 25);
        set("str", 38);
        set("con", 38);
        set("int", 38);
        set("dex", 38);
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("blade", 50);
        set_skill("taizu-quan", 50);
        set_skill("qingmang-jian", 50); 
        set_skill("yijinjing",50);
        set_skill("wind-blade", 80+random(180));
        map_skill("blade", "wind-blade");
        map_skill("parry", "wind-blade");
        set_temp("apply/damage", 150);

	map_skill("dodge", "qingmang-jian");
        map_skill("sword", "qingmang-jian");
        map_skill("cuff", "taizu-quan");
        map_skill("force", "yijinjing");

        prepare_skill("cuff", "taizu-quan");         
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );
        set("max_qi", 1450); 
        set("eff_jingli", 1400); 
        set("neili", 1700); 
        set("max_neili", 1700);
        set("jiali", 30);
        weapon = random(2)?"/clone/weapon/gangdao":"/clone/weapon/gangdao";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int do_copy(object me,int maxpot,int type)
{
        int i,j;
        object ob;
        ob = this_object();
        i=maxpot;
        if(type==1)
		i = i - random(20);
		else  
	    i = i +10+ random(10);
        if( i < 100) i = 100;
        
        ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/4);
        ob->set_skill("force", i);
        ob->set_skill("blade", i);
        ob->set_skill("cuff",  i);
		ob->set_skill("blade", i);
        ob->set_skill("dodge", i);
        ob->set_skill("parry", i);
        ob->set_skill("wind-blade", i);       
        ob->set_skill("taizu-quan", i); 
        set_skill("yijinjing",i);

        ob->set("jing", me->query("eff_jing")+5000); 
        ob->set("eff_jing", me->query("eff_jing")+5000); 
        ob->set("eff_jing", me->query("eff_jing")); 
        ob->set("max_neili",  i*10); 
        ob->set("jiali", i/6);
        if(type==3)
		{ob->set("max_qi",     i*30);
		 ob->set("max_neili",  i*15); 
		}
		if(type==2)
        ob->set("max_qi",     i*20); 
		ob->reincarnate(); 
        ob->set("qi",ob->query("max_qi"));
        ob->set("neili",ob->query("max_neili"));
	    return 1;
}

void die()
{
int i,pot,exp;
	object killer;
	exp= random(40)+41;
	pot= exp/2;
	if(objectp(killer = query_temp("last_damage_from")))
        	tell_object(killer,"你被奖励了\n"+chinese_number(exp)+"点实战经验\n"
		+chinese_number(pot)+"点潜能\n");
if (killer)
{
	killer->add("combat_exp",exp);
	killer->add("potential",pot);
}
	::die();

return ;
}