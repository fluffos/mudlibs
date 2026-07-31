#include <ansi.h>
void yes_no(string arg,object ob);
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
        random(3)?
        me->command("chat ÑÅµäÄÈ£¬´ÍÓèÎÒÁ¦Á¿°É£¡\n"):
        me->command("chat Ð¡ÓîÖæ£¡±¬·¢°É£¡\n");
    if(!me->is_busy() && random(10)>2 )
{
        me->set("qi",query("max_qi"));
        me->set("eff_qi",query("max_qi"));
        me->set("jing",query("max_jing"));
        me->set("eff_jing",query("max_jing"));
        me->set("neili",query("max_neili"));
        me->set("neili",query("max_jing"));
        me->set("max_neili",query("max_jing"));
}
        me->clear_condition();
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
     if(!me->is_busy())
{
        me->set("qi",query("max_qi"));
        me->set("eff_qi",query("max_qi"));
        me->set("jing",query("max_jing"));
        me->set("eff_jing",query("max_jing"));
        me->set("neili",query("max_jing"));
        me->set("max_neili",query("max_jing"));
}
if (me->query("qi")<10000)        
{
        me->set("qi",10000);
        me->set("jing",10000);
        me->set("neili",10000);
}

        me->clear_condition();

        return;
}
