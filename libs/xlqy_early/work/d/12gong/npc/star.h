#include <ansi.h>
void yes_no(string arg,object ob);
void power_up();
void full_me(object me);

void kill_ob(object ob)
{
object killer;
killer=query_temp("my_killer");
  set_temp("my_killer",ob);
if(killer)
{
if(killer != ob)
full_me(this_object());
}
  remove_call_out("check");
  call_out("check",1);
  remove_call_out("check2");
  call_out("check2",1);
  ::kill_ob(ob);
}


void powerup()
{
        object me = this_object();
        random(2)?
        me->command_function("chat 雅典娜，赐予我力量吧！\n"):
        me->command_function("chat 小宇宙！爆发吧！\n");
        me->set("kee",query("max_kee"));
        me->set("eff_kee",query("max_kee"));
        me->set("sen",query("max_sen"));
        me->set("eff_sen",query("max_sen"));
        me->set("force",query("max_force"));
        me->set("mana",query("max_mana"));
        me->clean_condition();
        return;
}
void check2()
{
        object me = this_object();
        int i;
object *emery=me->query_enemy();

        if( sizeof(emery)==0 )
        {
        remove_call_out("check2");
        full_me(me);
        return ;
        }

        if( !me->is_fighting() )
        {
        full_me(me);
        remove_call_out("check2");
        return ;
        }


        for(i=0;i<sizeof(emery);i++)
        {
 if(!emery[i] || !interactive(emery[i])||environment(emery[i])!=environment(this_object()) )
                full_me(me);
        }

        remove_call_out("check2");
        call_out("check2",1);
        return;
}

void full_me(object me)
{
        me = this_object();
        me->set("kee",query("max_kee"));
        me->set("eff_kee",query("max_kee"));
        me->set("sen",query("max_sen"));
        me->set("eff_sen",query("max_sen"));
        me->set("force",query("max_force"));
        me->set("mana",query("max_mana"));
        me->clean_condition();
        return;
}
void unconcious()
{
die();
}
