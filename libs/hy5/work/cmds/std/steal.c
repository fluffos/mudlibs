// steal.c

#include <ansi.h>
inherit F_CLEAN_UP;
#include "/quest/givegift.c"
int main(object me, string arg)
{
   string what, who;
   object ob, victim,obj;
   mapping myfam, vtfam;
   int sp, dp;

   if( environment(me)->query("no_fight")) return notify_fail("这里禁止行窃。\n");
   if( environment(me)->query("no_steal")) return notify_fail("这里禁止行窃。\n");

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
//         write("由于你没有心跳，请重新登陆!!\n");
        return notify_fail("由于你没有心跳，请重新登陆!!\n");
        }

   if( me->query_temp("stealing") )
      return notify_fail("你已经在找机会下手了！\n");

   if( !arg || sscanf(arg, "%s from %s", what, who)!=2 )
      return notify_fail("指令格式：steal <物品> from <人物>\n");

   victim = present(who, environment(me));
   if( !victim || victim==me) return notify_fail("你想行窃的对象不在这里。\n");
   if( !wizardp(me) && wizardp(victim) )
      return notify_fail("玩家不能偷巫师身上的东西。\n");

    if((int)victim->query("age") <= 19 && userp(victim))
        return notify_fail("为了世界更美好，放过小孩子吧.\n");
    if( userp(victim) && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
    if( userp(victim) && victim->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
//   if( !ob->is_character()  )
//	return notify_fail("看清楚一点，你只能从人身上偷东西。\n");

   if( !victim->is_character() || victim->is_corpse() )
	return notify_fail("看清楚一点，那并不是活物。用get比较好。\n");
if(userp(victim) && victim->query("combat_exp")/3 > me->query("combat_exp") )
	return notify_fail("他比你强太多，你不敢动手。\n");
   if( victim->query("race") != "人类" )
        return notify_fail(victim->name() + "根本不是人，用kill比较好！\n");


//免战系统
obj=victim;
        if (userp(me) && userp(obj)
         && obj->query_temp("nokill") )
        return notify_fail("那人启用了免战牌！\n");

        if (userp(me) && userp(obj)
         && me->query_temp("nokill") )
        return notify_fail("你启用了免战牌！\n");

    if( userp(me) && userp(obj) && obj->query_condition("nokill")
    && !obj->query_condition("killer"))
        return notify_fail("那个人刚被杀过，放过他吧！\n");
if( !living(obj) && userp(obj) && obj->query("combat_exp")/3 > me->query("combat_exp") )
	return notify_fail("你想要杀此人，但他比你强太多，你不敢动手。\n");


   if( victim->query_temp("no_kill") )
        return notify_fail("此人不能steal！\n");
   if( victim->query("hunmi",1))
        return notify_fail("他正昏着呢！用get吧\n");
    if(me->is_busy())
        return notify_fail("你现在正忙。\n");

   if( victim->query("disable_inputs",1))
        return notify_fail("他正被禁指令呢！\n");
        if (userp(victim) && !query_heart_beat(victim))
        {
         write("你想做什么！\n");
        return notify_fail("此人不能steal！\n");
//         write("此人不能steal！\n");
        }

   if( userp(victim) && me->query("age")<18 && me->query("combat_exp")<50000)
           return notify_fail(victim->name() + "是玩家，你的能力不足！\n");

    if( !ob = present(what, victim) )
   {
      object *inv;
      inv = all_inventory(victim);
      if( !sizeof(inv) )
         return notify_fail( victim->name() + "身上看起来没有什麽值钱的东西好偷。\n");
      ob = inv[random(sizeof(inv))];
   }
    if(ob->query("dynamic_quest"))
{
        return notify_fail( victim->name() + "身上看起来没有什麽值钱的东西好偷。\n");
}

   sp = (int)me->query_skill("stealing") * 5 + (int)me->query("kar") * 2
        - (int)me->query("thief") * 20;

   if ( (myfam = me->query("family")) && myfam["family_name"] == "丐帮" )
      sp = (int)me->query_skill("stealing") * 10 + (int)me->query("kar") * 5
           - (int)me->query("thief") * 20;

   if( sp < 1 ) sp = 1;

   if( me->is_fighting() )
   {
       sp /= 2;
       me->start_busy(3);
   }
   dp = (int)victim->query("jing") * 2 + (int)ob->weight()/25;
   if( victim->is_fighting() ) dp *= 10;
   if( ob->query("equipped") ) dp *= 10;

   write("你不动声色地慢慢靠近" + victim->name() + "，等待机会下手 ...\n\n");
   if( ob->query("no_get",1))
   return notify_fail("这个东西，你偷不到的！\n");
   if( ob->is_character() || ob->is_corpse() )
   return notify_fail("那种东西不能偷的。\n");

   me->set_temp("stealing", 1);
   ob->set("no_get",1);
   call_out( "compelete_steal", 3, me, victim, ob, sp, dp);

   return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp, int dp
)
{
   mapping myfam, vtfam;
   int steal_level;
       int exp,pot;
        if (!me)  return notify_fail("你已经断线了！\n");
        if (!victim)  return notify_fail("那个人已经不在了！\n");
   me->delete_temp("stealing");

   if( environment(victim) != environment(me) )
   {
      tell_object(me, "太可惜了，你下手的目标已经走了。\n");
      return;
   }
        if (!ob)  return notify_fail("那样东西已经不在了！\n");
        ob->set("no_get",0);
   if( !living(victim) || (random(sp+dp) > dp) )
   {
        if (!ob)  return notify_fail("那样东西已经不在了！\n");

      if( ob->query("no_steal") )
      {
         tell_object(me, "你摸到一" + ob->query("unit") + ob->name()
                       + "，可是你突然作贼心虚，居然不敢下手，真是可惜了。\n");
   ob->set("no_get",0);
         return;
      }

      if( ob->query("equipped") )
      {
         tell_object(me, "你摸到一" + ob->query("unit") + ob->name()
                       + "，可是那件东西,人家正用着呢。\n");
   ob->set("no_get",0);
            return;
      }
//	set_max_encumbrance(10000);
	if (ob->is_container() )
	{
	tell_object(me, "这是个容器,你偷不了的!\n");
   ob->set("no_get",0);
		return;
	}

        if (!ob)  return notify_fail("那样东西已经不在了！\n");


               if (sizeof(all_inventory(me)) >= 40)
                {
                        tell_object(me, "眼看你就要得手，可惜身上的东"
                                    "西太多，实在拿不了了。\n");
//                        ob->move(environment(me));
                        return;
                }

      if( !ob->move(me) )
      {
         tell_object(me, "你摸到一" + ob->query("unit") + ob->name()
                       + "，可是对你而言太重了，不得不放弃。\n");
   ob->set("no_get",0);
         return;
      }


      tell_object(me, HIW "得手了！\n\n" NOR);
   ob->set("no_get",0);
      tell_object(me, "你成功地偷到一" + ob->query("unit") + ob->name() + "！\n");
	if( userp(victim) && query_ip_name(victim)==query_ip_name(me) )
{
			message_vision(victim->name() + "看$N一眼，你我关系这么好，还来偷我的东西。\n", me);

} else
{
exp=18+random(30);
pot=15+random(12);
  if( me->query("family/family_name") == "丐帮")
{
if (!userp(victim))
{
exp=exp/2+5;
addnl(me,"exp",exp);

}
}
}

      steal_level = (int)me->query_skill("stealing",1);

      if( living(victim) )
      {
         if ((int)me->query("combat_exp") > (steal_level*steal_level*steal_level/10) )
         {
            me->improve_skill("stealing", random(me->query("int")));
         }
         else
         {
            tell_object(me," 就这点经验也要去偷？ \n");
         }
         if ( (myfam = me->query("family")) && myfam["family_name"] == "丐帮" )
         {
            if (( (int)me->query("potential") - (int)me->query("learned_points") < 100))
            {
               me->add("potential",1);
            }
//add by Java. Nov 16.1997
   if (!me) return notify_fail("你已经断线了！\n");
            me->start_busy(2);
            me->add("thief", 1);
            me->add("jing",-10);
            me->add("eff_jing",-4);

            me->add("combat_exp",1);
         }
      }

      if( random(sp) < dp/2 )
         message("vision", "你看到" + me->name() + "鬼鬼祟祟地从"
               + victim->name() + "身上偷走了一" + ob->query("unit")
               + ob->name() + "！\n", environment(me), ({ me, victim }) );
   }
   else
   {
      if( random(sp) > dp/2 )
      {
         tell_object(me, victim->name() + "不经意地一转头，你急忙将手缩了回去！\n"
            "还好，没有被发现。\n");
   ob->set("no_get",0);
         return;
      }
      tell_object(me, HIR "糟糕！你失手了！\n\n" NOR);
      message_vision("$N一回头，正好发现$n的手正抓着$P身上的" + ob->name() + "！\n\n"
            + "$N喝道：「干什么！」\n\n", victim, me);
   if (!me) return notify_fail("你已经断线了！\n");
   ob->set("no_get",0);
if (me->query_skill("stealing"))
{
      me->improve_skill("stealing", 1, 1);
}
      if( userp(victim) ) me->fight_ob(victim);
      else me->kill_ob(victim);
      me->start_busy(3);
      me->add("thief", 1);
      me->add("jing",-10);
      me->add("eff_jing",-4);
   }

}

int help(object me)
{
write(@HELP
指令格式 : steal <某物> from <某人>

这个指令让你有机会偷到他人身上的东西。成功了, 当然你就能获得
该样物品。可是, 马有失蹄, 人总有失风的时候, 当你失败时当然就
得付出代价, 至於是什么代价......靠你自己去发掘罗。
HELP
    );
    return 1;
}

