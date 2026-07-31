// bee2.h

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
        && !(me->query_temp("gm/caimi") != name1)){
         me->set_temp("apply/attack",  random(50));
         me->set_temp("apply/dodge",  random(50)); 
       if (!me->query_temp("skillset1")){
         ob->start_busy(1);
         remove_call_out("dest");
         call_out("dest",240);
         me->set_leader(ob);
         remove_call_out("do_clone");
         call_out("do_clone", 0, me, ob);
         call_out("waiting", 1, me);
         }
       else {
         ob->start_busy(1);
         me->set_leader(ob);
         remove_call_out("dest");
         call_out("dest",240);
         remove_call_out("kill_ob");
         call_out("kill_ob", 0, ob); 
         }
   } 
}       

int do_clone(object me, object ob)
{
        int k_qi,k_jing;
        k_qi = (int)ob->query_max_hp();
        k_jing = (int)ob->query_max_jing();
        
        me->set("max_qi",k_qi*2/3);
        me->set("eff_qi",k_qi*2/3);
        me->set("qi",k_qi*2/3);
        me->set("max_jing",k_jing*2/3);
        me->set("eff_jing",k_jing*2/3);
        me->set("jing",k_jing*2/3);
        me->set("combat_exp",ob->query("combat_exp")*2/3);

        me->set_temp("skillset1",1);   
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

       write(me->query("name")+"拍拍翅膀，转身飞走了。\n",me);
       destruct(this_object());
}

