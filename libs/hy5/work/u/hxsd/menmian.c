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
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 83);
        //set("long", "一个穿着黑色夜行衣的人。\n");
        set("combat_exp", 5580000 + random(40000)); 
        set("attitude", "friendly");
        set_skill("force", 550);
        set_skill("sword", 550);
        set_skill("dodge", 550);
        set_skill("parry", 550);
        set_skill("cuff", 550);
        set_skill("blade", 550);
        set_skill("taizu-quan", 550);
        set_skill("qingmang-jian", 550); 
        set_skill("yijinjing",550);
		map_skill("dodge", "qingmang-jian");
        map_skill("sword", "qingmang-jian");
        map_skill("parry", "qingmang-jian");
        map_skill("blade", "qingmang-jian");
        map_skill("cuff", "taizu-quan");
        map_skill("force", "yijinjing");

        prepare_skill("cuff", "taizu-quan");         
        set("max_qi", 88450); 
        set("eff_jingli", 88400); 
        set("neili", 88700); 
        set("max_neili", 88700);
        set("jiali", 30);
        weapon = random(2)?"/clone/weapon/gangjian":"/clone/weapon/gangdao";
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
        ob->set_skill("sword", i);
        ob->set_skill("blade", i);
        ob->set_skill("cuff", i);
		ob->set_skill("dodge", i);
        ob->set_skill("parry", i);
        ob->set_skill("qingmang-jian", i);       
        ob->set_skill("taizu-quan", i); 
        set_skill("yijinjing",i);
		ob->set("max_qi", 2000+i*30); 
        ob->set("eff_jingli", me->query("eff_jingli")*2/3); 
        ob->set("max_neili", 1000+i*15); 
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

