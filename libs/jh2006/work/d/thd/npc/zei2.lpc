// NPC: daomu-one.c
// Created by Numa 19990914

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include <ansi.h>
#include "skill.h"
#include "r_obj.h"

void create()
{
        object armor;
        set_name("盗墓贼", ({ "daomu zei", "daomu", "zei" }) );
        set("gender", "男性");
        set("age", 25+random(15));
        set("long","这家伙刚盗墓成功,累的满头大汉,但掩饰不住盗墓成功的喜悦。\n");
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
        if (clonep()){
                        armor = new("/clone/armor/armor/cloth");
                armor->move(this_object());
                armor->wear();
        }
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
        
        if (ob->query_temp("thd/dojob"))
        {
// 判断 player
        if (me->query_temp("target")!=ob->query("id"))
                {
                        command("look " + ob->query("id"));
                        say( "盗墓贼恨恨的骂道: 刚才那小子跑哪里去了？!\n");
                        say( "盗墓贼急急忙忙离开了。\n");
                        destruct(me);
                        return;
                }
                if (!me->query_temp("skillset"))
                {
                        say( "盗墓贼对着你「嘿嘿」笑了两声,说道：你这个" + RANK_D->query_rude(ob)
                                        + "，既然被你发现了,那我就不客气了。\n");
                        ob->start_busy(random(2));
                        remove_call_out("dest");
                        call_out("dest",300);
                        remove_call_out("do_kill");
                        call_out("do_kill", 0, me, ob);
                }
                else
                {
                        say ( "盗墓贼狠狠的瞪着你，大叫：想跑？接招！\n");
                        remove_call_out("dest");
                        call_out("dest",300);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 0, ob);
                }
        }
        else
        {
                command("look " + ob->query("id"));
                say( "盗墓贼恨恨的骂道: 居然有人在里面,只好下次再来了!\n");
                destruct(me);
        }
}

int do_kill(object me,object ob)
{
        object clone_obj;
        mapping killerskill1;
        int number,number_t,k_qi,k_neili,k_jing, j, k;
        string t_force,t_dodge,t_obj;
        number = (int)ob->query("max_pot");
        number = number - 100;
        k_qi = (int)ob->query("max_qi") + random((int)ob->query("max_qi") / 20 + 20);
        k_jing = (int)ob->query("max_jing");
        k_neili = (int)ob->query("max_neili") + random((int)ob->query("max_qi") / 20 + 20);
        j = (int)ob->query("dex");
        k = (int)ob->query("str");

        killerskill1 = skill2[random(sizeof(skill2))];
        number = (int)(number + random(5) - random(10));
// 随机 skill set
        number_t = number - 10;
        if (number > 300) number = 300;

//add log to /log/thdjob
        if (number > ((int)ob->query("max_pot")-100))   
	log_file("thdjob",sprintf("%s %s(%s) 守墓任务，盗墓贼等级是 %d，本人等级是 %d。\n",
        ctime(time()),ob->name(1),ob->query("id"),number,(int)ob->query("max_pot")-100));

//add by river 
        if( ob->query("thdjob") > 200 ){
          me->set("dex", ob->query("dex"));
          me->set("str", ob->query("str"));
          me->set("con", ob->query("con"));
        }

//set killer's skill
        t_force = k_force[random(sizeof(k_force))];
        t_dodge = k_dodge[random(sizeof(k_dodge))];       
        me->set_skill("force",number_t + random(5));
        me->set_skill("dodge",number_t + random(5));
        me->set_skill("parry",number_t + random(5));
        me->set_skill(t_force,number_t + random(5));
        me->set_skill(t_dodge,number_t + random(5));
        me->set_skill(killerskill1["t_skill"],number_t + random(5));
        me->set_skill(killerskill1["b_skill"],number_t + random(5));
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
        me->set("jiali", k_neili / 40);
        me->set("combat_exp",ob->query("combat_exp")* 7/6);
        me->set_temp("skillset",1);
// call random object in Npc
        t_obj = r_obj[random(sizeof(r_obj))];
        clone_obj = new(__DIR__"obj/" + t_obj );
        clone_obj->set_temp("thdjob",ob->query("id"));
        clone_obj->move(me);
        
// kill player        
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, ob);
        return 1;
}

void dest()
{
        object me,ob;
        ob = this_player();
        me = this_object();
        write(me->query("name")+"突然大声嚷道：哎呀，不跟你在这里斗了，过会黄老邪来了可就不好惹了！\n");  
        write(me->query("name")+"急急忙忙离开了。\n");
        ob->delete_temp("thd/dojob");
        destruct(me);
}
