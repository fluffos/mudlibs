#include <ansi.h>
inherit NPC;

int do_copy(object me);
int do_back(object me);

void create()
{
      string weapon;
        set_name("明教弟子", ({ "mingjiaodizi"}));
        set("gender", "男性");
        set("age", random(10) + 25);
        set("no_quest", 1);
        set("str", 33);
        set("con", 26);
        set("int", 20);
        set("dex", 60);
        set("long", "明教的弟子。\n");
        set("combat_exp", 1080000 + random(4000000)); 
        set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
     set_skill("jiuyang-shengong", 100);
    set_skill("qiankun-danuoyi", 100);
    set_skill("qishang-quan", 100);
    set_skill("shenghuo-shengong", 100);
    set_skill("taiji-quan",150);
    set_skill("taiji-jian",150);
    set_skill("taiji-dao",150);
    set_skill("shenghuo-ling",300);

    map_skill("force", "shenghuo-shengong");
    map_skill("dodge", "qiankun-danuoyi");
    map_skill("unarmed", "qishang-quan");
    map_skill("cuff", "qishang-quan");
    map_skill("hand", "taiji-quan");
    map_skill("sword","shenghuo-ling");
    map_skill("parry","shenghuo-ling");
    map_skill("blade","taiji-dao");
        set("max_qi", 1450); 
        set("eff_jingli", 1400); 
        set("neili", 1700); 
        set("max_neili", 1700);
        set("jiali", 30);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
//                (: perform_action, "sword.duo" :),
                (: perform_action, "sword.tougu" :),
//                (: perform_action, "sword.xiyanling" :),
                (: perform_action, "sword.yinfeng" :),                
                (: perform_action, "sword.yinfeng" :),                
                (: perform_action, "sword.yinfeng" :),                
                (: command("unwield jian") :),
                (: command("wield jian") :),
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );
        weapon = "/clone/weapon/gangjian";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void die()
{
int i,pot,exp;
	object killer;
	exp= random(50)+50;
	pot= exp*2/3;

	if(objectp(killer = query_temp("last_damage_from")))
        	tell_object(killer,"你被奖励了\n"+chinese_number(exp)+"点实战修为\n"
		+chinese_number(pot)+"点潜能\n");
if (userp(killer))
{
if(killer->query_temp("rob_start")) 
{
killer->add_temp("emjob2",1);		
}
	killer->add("combat_exp",exp);
	killer->add("potential",pot);
}
	::die();

return ;
}
int checking(object ob, object me)
{
	if(!me || !present(me, environment())) do_back(ob);
	else call_out("checking", 2, ob, me);
        return 1;
}

int do_copy(object me)
{
        int i;
        object ob;
        ob = this_object();

      if(!me->query_temp("xx_rob")){
      	   do_back(me);
      	   return 0;
      	   }
        message_vision(HIR"突然从队伍后窜出一个$N，二话不说就扑向了$n！\n"NOR, ob, me);
        me->add_temp("biaoshi", 1);
        
        ob->set("combat_exp",me->query("combat_exp") * 3 / 4);
        ob->set("max_qi",me->query("max_qi") * 3 / 4);
        ob->set("eff_qi",me->query("max_qi") * 3 / 4);
        ob->set("qi",me->query("max_qi") * 3 / 4);
        ob->set("max_jingli",me->query("max_jingli") * 3 / 4);
        ob->set("eff_jingli",me->query("max_jingli") * 3 / 4);
        ob->set("jingli",me->query("max_jingli") * 3 / 4);
        ob->set("max_neili",me->query("max_neili") * 3 / 4);
        ob->set("neili",me->query("max_neili") * 3 / 4);
        if (me->query_skill("force",1))
{
        ob->set_skill("force", me->query_skill("force",1));
        ob->set_skill("jiuyang-shengong", me->query_skill("force",1)* 2 / 4);
        ob->set_skill("qiankun-danuoyi", me->query_skill("force",1)* 2 / 4);
        ob->set_skill("qishang-quan", me->query_skill("force",1)* 2 / 4);
        ob->set_skill("shenghuo-shengong",me->query_skill("force",1)* 2 / 4);
        ob->set_skill("dodge", me->query_skill("force",1)* 2 / 4); 
        ob->set_skill("sword", me->query_skill("force",1)* 2 / 4); 
        ob->set_skill("taiji-quan", me->query_skill("force",1)* 2 / 4); 
        ob->set_skill("parry",me->query_skill("force",1)* 2 / 4); 
        ob->set_skill("shenghuo-ling", me->query_skill("force",1)* 2 / 4);
 }
        if (me->query_skill("force",1))
{
if (random(20)>18)
{
        ob->set_skill("force", me->query_skill("force",1));
        ob->set_skill("jiuyang-shengong", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("qiankun-danuoyi", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("qishang-quan", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("shenghuo-shengong",me->query_skill("force",1)* 3 / 4);
        ob->set_skill("dodge", me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("sword", me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("taiji-quan", me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("parry",me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("shenghuo-ling", me->query_skill("force",1)* 3 / 4);
}
}

        ob->kill_ob(me);
	 me->kill_ob(ob);
        checking(ob, me);    
        call_out("do_back", 350,  ob);  
        return 1;
}


int do_back(object me)
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "侠客走了出去，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
}
