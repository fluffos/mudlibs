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
        set("dex", 23);
        //set("long", "一个穿着黑色夜行衣的人。\n");
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
        set_skill("wind-blade", 80+random(180));
     set_skill("necromancy", 80);
        set_skill("xiaowuxiang", 80);
        set_skill("force", 80);
        set_skill("longxiang", 80);
        set_skill("dodge", 50);
        set_skill("shenkong-xing", 80);
        set_skill("unarmed", 80);
        set_skill("yujiamu-quan", 80);
        set_skill("parry", 80);
        set_skill("cuff", 80);
        set_skill("sword", 80);
        set_skill("mingwang-jian", 80);
        set_skill("lamaism", 50);
        set_skill("literate", 80);
        set_skill("hammer", 80);
        set_skill("riyue-lun", 80);
	set_skill("dashou-yin", 80);
        set_skill("staff", 80);
        set_skill("xiangmo-chu", 80);
        set_skill("magic", 80);
        set_skill("kwan-yin-spells", 80);
set_skill("xue-dao", 80);


        map_skill("magic", "kwan-yin-spells");
        map_skill("cuff", "yujiamu-quan");
        map_skill("hand", "dashou-yin");
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");
        map_skill("hammer", "riyue-lun");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");    
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
(: perform_action, "blade.resurrect" :),
(: perform_action, "blade.chi" :),
(: perform_action, "blade.shi" :),
(: perform_action, "blade.xue" :),
(: perform_action, "blade.ying" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

        set("max_qi", 450); 
        set("eff_jingli", 400); 
        set("neili", 700); 
        set("max_neili", 700);
        set("jiali", 30);
        weapon = random(2)?"/clone/weapon/gangdao":"/clone/weapon/gangdao";
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
        ob->set_skill("xue-dao", i);       
        ob->set_skill("longxiang", i); 
        ob->set_skill("yijinjing",i);
   
        ob->set_skill("taizu-quan", i); 
        ob->set_skill("yujiamu-quan", i);
        ob->set_skill("parry", i);
        ob->set_skill("cuff", i);
        ob->set_skill("sword",i);
        ob->set_skill("mingwang-jian", i);
        ob->set_skill("lamaism", i);
        ob->set_skill("literate", i);
	ob->set_skill("dashou-yin", i);
        ob->set_skill("magic", i);
        ob->set_skill("longxiang", i);
        ob->set_skill("shenkong-xing", i);
        ob->set_skill("kwan-yin-spells", i);
	
        ob->set("max_qi",     me->query("max_qi")); 
        ob->set("max_jing", me->query("max_jing")); 
        ob->set("max_neili",  me->query("max_neili")); 
        ob->set("qi",     me->query("max_qi")); 
        ob->set("jing", me->query("max_jing")); 
        ob->set("neili",  me->query("max_neili")); 

        ob->set("eff_qi",     me->query("max_qi")); 
        ob->set("eff_jing", me->query("max_jing")); 
        ob->reincarnate(); 
		call_out("do_back", 200,  ob);  
        return 1;
}
int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"匆匆忙忙的离开了。\n", ({me}));	
  destruct(me); 
  return 1;
}

