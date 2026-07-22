#include <combat.h>
#include <ansi.h>
inherit COMBINED_ITEM;

void destruct_me(object where, object me)
{
object seal;
if( seal=new("/obj/paper_seal"))
        seal->move(where);
message_vision("$N手中的$n突发红光，符咒渐渐淡去不见了。\n",where,me);
if ( me->query_amount()>1 )  me->add_amount(-1);
else destruct(me);
}

void init()
{
object me = this_object();
object where = environment();

if (userp(where))
        {
        if (me->query("owned"))
                {
                if (me->query("owned")!=where->query("id"))
                        call_out("destruct_me",1,where,me);
                }
        else    me->set("owned",where->query("id"));
        }
}

void invocation(object me)
{
int i;
if ( !me )   return;
i = COMBAT_D->skill_power(me,"spells",SKILL_USAGE_ATTACK);
this_object()->set("ap",i);
return;
}

int ji (string target)
{
object seal = this_object ();
object me = this_player();
string name=seal->query("name");
object victim;

if (!target)
        return notify_fail("你想对谁祭"+name+"？\n");
if( time()<me->query_temp("jjf_ji_seal")+5 )
        return notify_fail("你刚刚祭过符咒，还是先歇歇吧。\n");
if( time()<(int)me->query_temp("no_cast")+me->query_temp("no_cast_time") )
        return notify_fail("你现在不能用魔法！\n");

victim=present(target,environment(me));
seal->ji_ob(victim);
return 1;
}

int err_msg(string arg)
{
write(arg);
return 1;
}
