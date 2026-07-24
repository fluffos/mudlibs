#include <ansi.h>
inherit NPC;

int do_copy(object me,int maxpot);
int do_back(object me);

void create()
{
      string weapon;
        set_name("蒙面人", ({ "mengmian ren","ren"}));
        set("gender", "男性");
        set("age", random(30) + 25);
        set("str", 53);
        set("con", 66);
        set("int", 50);
        set("dex", 53);
        //set("long", "一个穿着黑色夜行衣的人。\n");
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
	set_skill("taiji-shengong", 300);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 300);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("array",100);
	set_skill("taoism", 250);
	set_skill("blade", 150);
	set_skill("shiren-jianfa", 150);
	set_skill("shiren-quanfa", 150);
	set_skill("wuxing-dun", 150);
	map_skill("unarmed", "shiren-quanfa");
	map_skill("parry", "shiren-jianfa");
	map_skill("blade", "shiren-jianfa");
	map_skill("dodge", "wuxing-dun");
	if (random(2)==0)
	map_skill("parry", "shiren-quanfa");
	map_skill("force", "taiji-shengong");

        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 100);
        set("eff_qi", 6500); 
        set("qi", 6500); 
        set("max_qi", 6500); 
        set("eff_jing", 6500); 
        set("jing", 6500); 
        set("max_jing", 6500); 
        set("eff_jingli", 6000); 
        set("neili", 5000); 
        set("max_neili", 5000);
        set("jiali", 50);
        weapon = random(2)?"/quest/weiguo/japan/obj/japanblade":"/quest/weiguo/japan/obj/japanblade";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int do_copy(object me,int maxpot)
{
        int i,j;
        object ob;
        ob = this_object();
        i=maxpot;
        i = i +10+ random(10);
        if( i < 100) i = 100;
        
        ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/4);
        ob->set_skill("force", i);
        ob->set_skill("dodge", i);
        ob->set_skill("unarmed", i);
        ob->set_skill("sword", i);
        ob->set_skill("blade", i);
        ob->set_skill("cuff", i);
		ob->set_skill("dodge", i);
        ob->set_skill("parry", i);
        ob->set_skill("qingmang-jian", i);       
        ob->set_skill("taizu-quan", i); 
        ob->set_skill("yijinjing",i);
        ob->set_skill("taiji-shengong", i);       
        ob->set_skill("shiren-jianfa", i); 
        ob->set_skill("shiren-quanfa", i); 
        ob->set_skill("wuxing-dun", i);  
		ob->set("max_qi", 3000+i*30); 
        	ob->set("eff_qi", 3000+i*30); 
        	ob->set("qi", 3000+i*30); 
        ob->set("jing", me->query("eff_jing")+3000); 
        ob->set("eff_jing", me->query("eff_jing")+3000); 
        ob->set("eff_jingli", me->query("eff_jingli")+3000); 
        ob->set("max_neili", 5000+i*30); 
        ob->set("jiali", i/6);
        ob->reincarnate(); 
        ob->set("qi",ob->query("max_qi"));
        ob->set("neili",ob->query("max_neili"));
		call_out("do_back", 200,  ob);  
        return 1;
}
int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"匆匆忙忙的离开了。\n", ({me}));	
  destruct(me); 
  return 1;
}

