#include <ansi.h>
void power_up();
void full_me(object me);

void kill_ob(object ob)
{
  set_temp("my_killer",ob);
  remove_call_out("check");
  call_out("check",1);
  remove_call_out("check2");
  call_out("check2",1);
  ::kill_ob(ob);
}

void powerup()
{
        object me = this_object();
        me->command("say 雅典娜，賜予我力量吧！\n"):
        me->command("say 小宇宙！爆發吧！\n");
        me->set("hp",query("max_hp"));
        me->set("mp",query("max_mp"));
        me->set("ap",query("max_ap"));
        me->clean_condition();
        return;
}

void check2()
{
        object me = this_object();
        int i;
        object *emery=me->query_emery();

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
                if(!interactive(emery[i]) )
                full_me(me);
        }

        remove_call_out("check2");
        call_out("check2",1);
        return;
}

void full_me(object me)
{
        me = this_object();
        me->set("hp",query("max_hp"));
        me->set("mp",query("max_mp"));
        me->set("ap",query("max_ap"));
        me->clean_condition();
        return;
}
