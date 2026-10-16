// mmnz.h

#include <ansi.h>
void init()
{
        object name1;
        object ob = this_player();
        object me = this_object();
        name1 = ob->query("id");        

        ::init();

       if (interactive(ob) 
        && !environment(ob)->query("no_fight")
        && !(me->query_temp("mmnz") != name1 )
        && ob->query_temp("gm/job") 
        && ob->query_condition("gm_job")) {
         me->set_temp("apply/attack",  random(30));
         me->set_temp("apply/dodge",  random(50)); 
       if (!me->query_temp("skillset")) {
         command("say " +"既然被你发现小女子的踪迹，拿命来吧！");        
         ob->start_busy(4);
         remove_call_out("dest");
         call_out("dest",360);
         me->set_leader(ob);
         remove_call_out("do_clone");
         call_out("do_clone", 0, me, ob);
         }
       else {
         command("say 想跑？既然被你发现小女子的踪迹，拿命来吧！");  
         ob->start_busy(1);
         me->set_leader(ob);
         remove_call_out("dest");
         call_out("dest",360);
         remove_call_out("kill_ob");
         call_out("kill_ob", 0, ob); 
         }
   } 
}       

int do_clone(object me, object ob)
{
//        object weapon;
        mapping killerskill1;
        int number,k_qi,k_neili,k_jing,j, k;
        string t_force,t_dodge;
        number = (int)ob->query("max_pot");
        number = number-115;
        k_qi = (int)ob->query("max_qi");
        k_jing = (int)ob->query("max_jing");
        k_neili = (int)ob->query("max_neili");
        j = (int)ob->query("dex");
        k = (int)ob->query("str");

        me->set("dex", j*7/5);
        me->set("str", k*7/5);
  
        killerskill1 = skill1[random(sizeof(skill1))];
        t_force = k_force[random(sizeof(k_force))];
        t_dodge = k_dodge[random(sizeof(k_dodge))];       

        me->set_skill("force",number);
        me->set_skill("dodge",number);
        me->set_skill("parry",number);
        me->set_skill(t_force,number);
        me->set_skill(t_dodge,number);
        me->set_skill(killerskill1["t_skill"],number);
        me->set_skill(killerskill1["b_skill"],number);

        me->map_skill("force",t_force);
        me->map_skill("dodge",t_dodge);
        me->map_skill("parry",killerskill1["t_skill"]);
        me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
       
        me->prepare_skill(killerskill1["b_skill"],killerskill1["t_skill"]);

        me->set("max_qi",k_qi*2/3);
        me->set("eff_qi",k_qi*2/3);
        me->set("qi",k_qi*2/3);
        me->set("max_jing",k_jing*2/3);
        me->set("eff_jing",k_jing*2/3);
        me->set("jing",k_jing*2/3);
        me->set("max_neili",k_neili*2/3);
        me->set("neili",k_neili*2/3);
        me->set("combat_exp",ob->query("combat_exp"));

        me->set_temp("skillset",1);       
        me->set_leader(ob);
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, ob); 
        return 1;
}

void dest()
{
       object me,ob;
       ob = this_player();
       me = this_object();

       write(me->query("name")+"柳眉一蹙道：下次不要再让我遇见你。\n",me);  
       write(me->query("name")+"一个转身，飘身离去。\n",me);  

       destruct(this_object());
} 

