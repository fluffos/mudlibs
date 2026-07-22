// NPC: killer5.c
// Created by Numa 

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include <ansi.h>
#include "skill.h"

void create()
{
        set_name("王长老", ({ "wang zhanglao","wang" }) );
        set("gender", "男性");
        set("age", 25+random(15));
        set("title",HIY"日月神教 "HIC"长老"NOR);
        set("long","他就是魔教三长老之一的王长老。\n");
        set("shen", -100);
        set("int",30+random(5));
        set("con",30+random(5));
        set("dex",30+random(5));
        set("combat_exp", 1500000);
        set("shen_type", -1);
        set("attitude", "peaceful");
        set("max_qi",8200);
        set("max_jing",8200);
        set("neili",8000);
        set("jiali", 100);
        set("max_neili",8000);
        set("score", 10000);
        
        set_skill("force", 100); 
        set_skill("dodge", 100);
        set_skill("parry", 100);

        setup();
//          carry_object(ARMOR_D("armor/cloth"))->wear();
}

void init()
{
        object ob;
        
        ::init();
        
        if( interactive(ob = this_player()) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        object me = this_object();
        
        if (!ob || !present(ob, environment())) return;
// 判断 player        
        if (ob->query_temp("hostage/job_3") == 2
        &&  me->query_temp("target") == ob->query("id"))
        {
                command("look " + ob->query("id"));
                command("say " + RANK_D->query_rude(ob) + "，看你往哪里跑！！！");
                ob->start_busy(random(2));
                remove_call_out("do_kill");
                call_out("do_kill", 0, me, ob);
        }
}

int do_kill(object me,object ob)
{
        mapping killerskill1;
        int number,number_t,k_qi,k_neili,k_jing, j, k;
        string t_force,t_dodge;

        number = (int)ob->query("max_pot");
        number = number-100;
        k_qi = (int)ob->query("max_qi") + random((int)ob->query("max_qi") / 10 + 500);
        k_jing = (int)ob->query("max_jing");
        k_neili = (int)ob->query("max_neili") + random((int)ob->query("max_qi") / 10 + 500);
        j = (int)ob->query("dex");
        k = (int)ob->query("str");

        killerskill1 = skill2[random(sizeof(skill2))];
        number = (int)(number - random(10));
// 随机 skill set
        number_t = number - 10;

//set killer's skill
        t_force = k_force[random(sizeof(k_force))];
        t_dodge = k_dodge[random(sizeof(k_dodge))];       
        me->set_skill("force",number_t + random(15));
        me->set_skill("dodge",number_t + random(15));
        me->set_skill("parry",number_t + random(15));
        me->set_skill(t_force,number_t + random(15));
        me->set_skill(t_dodge,number_t + random(15));
        me->set_skill(killerskill1["t_skill"],number_t + random(15));
        me->set_skill(killerskill1["b_skill"],number_t + random(15));
// set killer's  skill maps
        me->map_skill("force",t_force);
        me->map_skill("dodge",t_dodge);
        me->map_skill("parry",killerskill1["t_skill"]);
        me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
// set killer's skill prepares
        me->prepare_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
// copy entire dbase values
        me->set("max_qi",k_qi);
        me->set("eff_qi",k_qi);
        me->set("qi",k_qi);
        me->set("max_jing",k_jing);
        me->set("eff_jing",k_jing);
        me->set("jing",k_jing);
        me->set("max_neili",k_neili);
        me->set("neili",k_neili);
        me->set("combat_exp",ob->query("combat_exp"));
        me->set_temp("skillset",1);
        
// kill player        
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, ob);
        return 1;
}
/*
void dest()
{
        object me,ob;
        ob = this_player();
        me = this_object();

        write(me->query("name")+"急急忙忙离开了。\n");
        destruct(me);
}
*/

int accept_fight(object ob)
{
        command("say " + RANK_D->query_rude(ob) + "，你别妨碍我办事。");
        return 0;
}

void die()
{
        object ob = this_object(),me;
//        int i,j;
        
        me = query_temp("last_damage_from");

        if (me->query("id") != ob->query_temp("target"))
        {
                ob->revive(1);
                command("say 好，既然有" + me->name(1) + "帮你，我就不拦你了！");
                destruct(ob);
                return;
        }
        else
        {
        	ob->revive(1);
        	command("say 既然你武功高强，我也没办法拦你了，你走吧。");
        	command("escape");
/*        	if(random(2)==1)
        	{
        		i = 90 
                  	  + random((int)ob->query_skill("force")/10)
                  	  + random((int)me->query("age",1));
                  	if (i<100) i = 100;
                  	if (i>200) i = 200;
                	j = i/4 + random(i/4);  
        		tell_object(me,"你经过这场打斗，得到了" + chinese_number(i) + "点经验和" + chinese_number(j) + "点潜能的奖励。\n");
        	}
*/
		me->add_temp("hostage/kill3",1);
		
       		destruct(ob);
       		return;
	}
	        
        ::die();
}
