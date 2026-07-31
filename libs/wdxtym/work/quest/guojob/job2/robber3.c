// robber1 for dart

#include <ansi.h>
inherit NPC;
#include "mgb2.h"
void create()
{
        set_name("蒙古高手",({"menggu gaoshou"}));
        set("long","这是一位侵犯中原的蒙古武功高手。\n");
        set("gender", "男性" );
        set("age", random(30)+14);

        set("vendetta/authority", 1);
        set("attitude", "peaceful");
        set("bellicosity", 100000);
         set("max_qi", 5000);
         set("eff_qi", 5000);
         set("qi", 5000);
        set("max_jing", 5200);
        set("jing", 5200);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 50);
        set("shen_type", -10);
        set("combat_exp", 600000);

        set_skill("force", 180);
        set_skill("unarmed", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.kuangdao" :),
                //(: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "blade.resurrect" :),
                (: perform_action, "blade.chi" :),
                (: perform_action, "blade.shi" :),
                //(: perform_action, "blade.xue" :),
                (: perform_action, "blade.ying" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: exert_function, "fumozhou" :),
                (: exert_function, "fanchang" :),
	}) );


        setup();
        carry_object(__DIR__"wandao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void do_change(object ob)
{
      object me;
      mapping hp_status, skill_status;
      string *sname;
      int i, temp;
      me = this_object();

//      ob = this_player();


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
        me->set_skill("xue-dao", temp*2/3);
        me->set_skill("unarmed",temp*2/3);
        me->set_skill("xianglong-zhang",temp*2/3);
        me->set_skill("dodge", temp*2/3);
        me->set_skill("blade", temp*2/3);
        me->set_skill("parry", temp*2/3);
        me->set_skill("dashou-yin", temp*2/3);
        me->set_skill("shenkong-xing", temp*2/3);
        me->set_skill("longxiang", temp*2/3);
        me->set_skill("huntian-qigong", temp*2/3);

        me->set_skill("dashou-yin",temp*2/3);
        me->set_skill("xiangmo-chu", temp*2/3);
me->set_skill("mingwang-jian", temp*2/3);
me->set_skill("yujiamu-quan", temp*2/3);
me->set_skill("shenkong-xing", temp*2/3);
me->set_skill("lamaism", temp*2/3);
me->set_skill("xiangmo-chu", temp*2/3);

        me->map_skill("force", "longxiang");
        me->map_skill("dodge", "shenkong-xing");
        me->map_skill("hand", "dashou-yin");
        me->map_skill("parry", "xue-dao");
        me->map_skill("blade", "xue-dao");
        me->map_skill("sword", "mingwang-jian");
        me->map_skill("unarmed","xianglong-zhang");
		me->map_skill("cuff", "yujiamu-quan");
		me->map_skill("hand", "dashou-yin");
		me->prepare_skill("cuff", "yujiamu-quan");
		me->prepare_skill("hand", "dashou-yin");
        me->set_temp("apply/damage", 50);
if (random(8)==0)
{
        me->set_temp("apply/attack", 20);
        me->set_temp("apply/defense", 20);
        me->set_temp("apply/armor", 50);
        me->set_temp("apply/damage", 20);
}

//        me->map_skill("blade","wuhu-duanmendao");
//        me->map_skill("parry","wuhu-duanmendao");
        me->map_skill("unarmed","xianglong-zhang");
        //prepare_skill("unarmed", "xianglong-zhang");



/* copy hp */

me->set("qi",(ob->query("max_qi")));
me->set("eff_qi",(ob->query("max_qi")));
me->set("max_qi",(ob->query("max_qi")));
me->set("max_jing",(ob->query("max_qi")*3/4));
me->set("eff_jing",(ob->query("max_qi")*3/4));
me->set("jing",(ob->query("max_qi")*3/4));
me->set("max_neili",(ob->query("max_neili")*3/4));
me->set("neili",(ob->query("max_neili")*3/4));
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
        me->set_temp("apply/attack", 20);
        me->set_temp("apply/defense", 20);
        me->set_temp("apply/armor", 50);
        me->set_temp("apply/damage", 50);

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
                        ob->add_temp("killed_mgb",2);
                  }
                  else
                        ob->add_temp("help_killed",1);
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

