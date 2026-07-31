// robber1 for dart

#include <ansi.h>
inherit NPC;
#include "mgb2.h"
void create()
{
        set_name("中原败类",({"menggu gaoshou"}));
        set("long","这是一位投靠蒙古的中原武功高手。\n");
        set("gender", "男性" );
        set("age", random(30)+14);

        set("vendetta/authority", 1);
        set("attitude", "peaceful");
        set("bellicosity", 100000);
         set("max_qi", 6000);
         set("eff_qi", 6000);
         set("qi", 6000);
        set("max_jing", 6200);
        set("jing", 6200);
        set("neili", 6000);
        set("max_neili", 5000);
        set("jiali", 50);
        set("shen_type", -10);
        set("combat_exp", 600000);
	set_skill("force", 100);		// 基本内功
	set_skill("beiming-shengong", 100);	// 北冥神功
	set_skill("finger", 120);		// 基本指法
	set_skill("six-finger", 120);		// 六脉神剑
	set_skill("dodge", 150);		// 基本躲闪
	set_skill("lingboweibu", 150);		// 凌波微步
	set_skill("parry", 180);			// 基本招架
        set_skill("kurong-changong", 301);	// 北冥神功

	map_skill("force", "kurong-changong");
	map_skill("dodge", "lingboweibu");
	map_skill("unarmed", "six-finger");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	prepare_skill("finger","six-finger");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
                (: perform_action, "dodge.lingbo" :),
                (: perform_action, "unarmed.liumaijingshen" :),
                (: perform_action, "unarmed.qi" :),
                (: perform_action, "unarmed.zongheng" :),
                (: perform_action, "dodge.lingbo" :),
				(: perform_action, "unarmed.liumaijingshen" :),
				(: perform_action, "unarmed.qi" :),
				(: perform_action, "unarmed.zongheng" :),
                 (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
	}) );

        set_temp("apply/damage", 50);
        set_temp("apply/defense", 50);
                set_temp("apply/attack", 50);
        set_temp("apply/armor", 50);

        setup();
//        carry_object(__DIR__"wandao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void do_change(object ob)
{
      object me;
      mapping hp_status, skill_status;
      string *sname;
      int i, temp;
      me = this_object();

//       ob = this_player();


      if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);
                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
      }

      if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname  = keys(skill_status);
                temp = skill_status[0];
                for(i=0; i<sizeof(skill_status); i++) {
		  if(sname[i]=="force")i++;
if (i>0 && i <sizeof(skill_status))
{
                  if (skill_status[sname[i]] >= temp)
                  { temp = skill_status[sname[i]];}
              }
        }
} else temp=(int)ob->query("force",1);

/*if (!ob->query_skill("force",1))
{
temp=10;
}else
temp=ob->query_skill("force",1);
*/
        me->set_skill("force", temp*2/3);
        me->set_skill("beiming-shengong",temp*2/3);
        me->set_skill("finger",temp*2/3);
        me->set_skill("six-finger", temp*2/3);
        me->set_skill("dodge", temp*2/3);
        me->set_skill("parry", temp*2/3);
        me->set_skill("lingboweibu", temp*2/3);
        me->set_skill("shenkong-xing", temp*2/3);
        me->set_skill("parry", temp*2/3);
        me->set_skill("unarmed", temp*2/3);
        me->set_skill("kurong-changong", temp*2/3);

	me->map_skill("force", "beiming-shengong");
	me->map_skill("dodge", "lingboweibu");
	me->map_skill("parry", "six-finger");
	me->map_skill("finger", "six-finger");
        me->map_skill("unarmed","six-finger");
	me->prepare_skill("finger","six-finger");
        me->set_temp("apply/damage", 50);
        me->set_temp("apply/defense", 20);
        me->set_temp("apply/armor", 50);
set_temp("apply/attack", 20);
if (random(20)>15)
{
        me->set_temp("apply/attack", 20);
        me->set_temp("apply/defense", 20);
        me->set_temp("apply/armor", 50);
        me->set_temp("apply/damage", 50);
}





/* copy hp */

me->set("qi",(ob->query("max_qi")));
me->set("eff_qi",(ob->query("max_qi")));
me->set("max_qi",(ob->query("max_qi")));
me->set("max_jing",(ob->query("max_qi")));
me->set("eff_jing",(ob->query("max_qi")));
me->set("jing",(ob->query("max_qi")));
me->set("max_neili",(ob->query("max_neili")));
me->set("neili",(ob->query("max_neili")));

        hp_status = ob->query_entire_dbase();

        me->set("str", hp_status["str"]+random(2));
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]+random(2));
        me->set("dex", hp_status["dex"]+random(10));
        me->set("combat_exp",hp_status["combat_exp"]*5/4);
        me->set("ygjg",ob);
        me->set("max_qi",    hp_status["max_qi"]*3/4);
	me->set("eff_qi",    hp_status["max_qi"]*3/4);
	me->set("qi",        hp_status["max_qi"]*3/4);
	me->set("max_jing",  hp_status["max_jing"]*3/4);
	me->set("eff_jing",  hp_status["eff_jing"]*3/4);
	me->set("jing",      hp_status["eff_jing"]*3/4);
	me->set("max_neili", hp_status["max_neili"]*3/4);
	me->set("neili",     hp_status["max_neili"]*3/4);
if (!ob->query_skill_mapped("force"))
{
me->set("qi",(ob->query("max_qi")));
me->set("eff_qi",(ob->query("max_qi")));
me->set("max_qi",(ob->query("max_qi")));
me->set("max_jing",(ob->query("max_jing")));
me->set("eff_jing",(ob->query("max_jing")));
me->set("jing",(ob->query("max_jing")));
}
if ((int)ob->query_skill("jiuyin-zhengong",1)>480)
{
me->set("qi",(ob->query("max_qi")));
me->set("eff_qi",(ob->query("max_qi")));
me->set("max_qi",(ob->query("max_qi")));
me->set("max_jing",(ob->query("max_qi")));
me->set("eff_jing",(ob->query("max_qi")));
me->set("jing",(ob->query("max_qi")));
        me->set("str", ob->query("str"));
        me->set("int", ob->query("int"));
        me->set("con", ob->query("con"));
        me->set("dex", ob->query("dex"));
        me->set_temp("apply/attack", 200);
        me->set_temp("apply/defense", 200);
        me->set_temp("apply/armor", 500);
        me->set_temp("apply/damage", 500);

}

}

void die()
{
            object ob;
              object robber;
              object room;
             ob=query_temp("last_damage_from");
if (!ob) return;
if (ob)
{
               room = environment(ob);

                  if(ob->query_temp("start_job")==1)
                  {
                        ob->add_temp("killed_mgb",3);
                  }
                  else
                        ob->add_temp("help_killed",2);
            if( !ob->query_temp("job_over"))
{
                 switch( random(5) ) {
                        case 0:
                        message_vision(HIR"城下又爬上来一个蒙古兵士。\n" NOR,ob);
                        robber=new(__DIR__"robber1");
                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        case 1:
                        message_vision(HIR"城下又爬上来一个蒙古将领。\n" NOR,ob);
                        robber=new(__DIR__"robber2");
                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        case 2:
                        message_vision(HIR"城下又爬上来一个蒙古高手。\n" NOR,ob);
                        robber=new(__DIR__"robber3");
        if( (int)ob->query_skill("shenzhao-jing",1)>100)
{
robber=new(__DIR__"robber4");
}
        if( (int)ob->query("jiuyin-zhengong",1)>100)
{
robber=new(__DIR__"robber4");
}
        if( (int)ob->query_skill("anranxiaohun-zhang",1)>100)
{
robber=new(__DIR__"robber4");
}
        if( (int)ob->query("combat_exp",1)>3500000)
{
robber=new(__DIR__"robber4");
}

                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        case 3:
                        message_vision(HIR"城下又爬上来一个蒙古兵士。\n" NOR,ob);
                        robber=new(__DIR__"robber1");
                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        case 4:
                        message_vision(HIR"城下又爬上来一个蒙古将领。\n" NOR,ob);
                        robber=new(__DIR__"robber2");
                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        }
}
}
              message_vision("$N扑在地上挣扎了几下，口中喷出几口"HIR"鲜血"NOR"，死了！\n",this_object());
                   destruct(this_object());
            return;
}

