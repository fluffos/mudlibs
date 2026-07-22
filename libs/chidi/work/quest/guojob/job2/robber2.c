// robber1 for dart

#include <ansi.h>
inherit BHNPC;
#include "mgb2.h"
void create()
{ 
        set_name("蒙古将领",({"menggu jiangling","jiangling"}));
        set("long","这是一位侵犯中原的蒙古将领。\n");
        set("gender", "男性" );
        set("age", random(30)+14);
        
        set("vendetta/authority", 1);
        set("attitude", "peaceful");    
        set("bellicosity", 100000);
         set("max_qi", 50000);
         set("eff_qi", 50000);
         set("qi", 50000);
        set("max_jing", 50000);
        set("jing", 50000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("jiali", 50);
        set("shen_type", -10);
        set("combat_exp", 100000000);
        set("is_guojob",1);        
        set_skill("force", 800); 
        set_skill("unarmed", 800);
        set_skill("dodge", 800);
        set_skill("parry", 800);
        setup();
      carry_object(__DIR__"wandao")->wield();
        carry_object(__DIR__"tiejia")->wear();  
}

void do_change(object ob)
{
      object me;
      mapping hp_status, skill_status;
      string *sname;
      int i, temp;
      me = this_object();
      ob = this_player(); 
      
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
                  if(sname[i]=="force" || sname[i]=="literate") continue;
                  if (skill_status[sname[i]] >= temp)
                  { temp = skill_status[sname[i]]/4;}
              }
        }
        if( temp < 10 ) temp = 10;      

        me->set_skill("wuhu-duanmendao", temp-random(100));
        me->set_skill("unarmed",temp-random(100));
        me->set_skill("xianglong-zhang",temp-random(100));
        me->set_skill("dodge", temp-random(100));
        me->set_skill("blade", temp-random(100));
        me->set_skill("parry", temp-random(100));

        me->map_skill("blade","wuhu-duanmendao");
        me->map_skill("parry","wuhu-duanmendao");
        me->map_skill("unarmed","xianglong-zhang");
        prepare_skill("unarmed", "xianglong-zhang");



/* copy hp */

        hp_status = ob->query_entire_dbase();
        me->set("str", hp_status["str"]+random(2));
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]+random(2));
        me->set("dex", hp_status["dex"]+random(10));
        me->set("combat_exp",hp_status["combat_exp"]/2);
        me->set("max_qi",    hp_status["max_qi"]/2);
        me->set("eff_qi",    hp_status["max_qi"]/2);
        me->set("qi",        hp_status["max_qi"]/2);
        me->set("max_jing",  hp_status["max_jing"]/2);
        me->set("eff_jing",  hp_status["eff_jing"]/2);
        me->set("jing",      hp_status["eff_jing"]/2);
        me->set("jingli", hp_status["max_jingli"]/2);
        me->set("neili",     hp_status["max_neili"]/2);   
        return;
}

void die()
{
            object ob;
            object robber;
            object room;
            ob=query_temp("last_damage_from");
            if( !ob = query_temp("last_damage_from") ) return;
            room = environment(ob);   

            if( ob->query_temp("guo_shoucheng/start_job") == 1
                && ob->query_temp("guo_shoucheng/killed_mgb")<40 )
                   ob->add_temp("guo_shoucheng/killed_mgb",2);
                else
                if( ob->query_temp("guo_shoucheng/help_killed")<30 )
                   ob->add_temp("guo_shoucheng/help_killed",2); 
            switch( random(3) ) 
            {
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
                        robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
                        ob->kill_ob(robber);
                        break;
                        }       
                   if( ob->query_temp("guo_shoucheng/start_job") == 1 )
                   robber->set("ygjg",ob);
                   message_vision("$N扑在地上挣扎了几下，口中喷出几口"HIR"鲜血"NOR"，死了！\n",this_object());
                   destruct(this_object());
            return;
}

