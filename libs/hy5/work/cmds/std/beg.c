// beg.c

#include <ansi.h>
inherit F_CLEAN_UP;
#include "/quest/givegift.c"
int main(object me, string arg)
{
        string what, who;
        object ob, victim,obj;
        mapping myfam, vtfam;
        int sp, dp;

        object where = environment(me);

        seteuid(getuid());

        if ( (!(myfam = me->query("family")) || myfam["family_name"] != "丐帮"))
          return notify_fail("只有乞丐才能乞讨！\n");

        if( environment(me)->query("no_beg") || environment(me)->query("no_fight"))
                return notify_fail("这里不是你叫化子能来讨饭的地方！\n");

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
//         write("由于你没有心跳，请重新登陆!!\n");
        return notify_fail("由于你没有心跳，请重新登陆!!\n");
        }

        if( me->query_temp("begging") )
                return notify_fail("你已经在向人家乞讨了！\n");

        if( !arg || sscanf(arg, "%s from %s", what, who)!=2 )
                return notify_fail("指令格式：beg <物品> from <人物>\n");

        victim = present(who, environment(me));
        if( !victim || victim == me) return notify_fail("你想乞讨的对象不在这里。\n");
        if( !living(victim) || !objectp(victim)) return notify_fail("你要向谁乞讨？\n");
        if ( (vtfam = victim->query("family")) && vtfam["family_name"] == "丐帮" )
                return notify_fail("你不能向乞丐乞讨！\n");

        if( !wizardp(me) && wizardp(victim) ) return notify_fail("玩家不能向巫师乞讨。\n");

        if( me->is_fighting() )
                return notify_fail("一边打架一边要饭？你真是活腻了！\n");

        if( victim->is_fighting() )
                return notify_fail(victim->name() + "正在打架，没空理你！\n");
        if( victim->query_temp("no_kill") )
        return notify_fail("此人不能beg！\n");
   if( victim->query("hunmi",1))
        return notify_fail("他正昏着呢！用get吧\n");
   if( victim->query("disable_inputs",1))
        return notify_fail("他正被禁指令呢！\n");
    if(me->is_busy())
        return notify_fail("你现在正忙。\n");
    if( userp(victim) && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
    if( userp(victim) && victim->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
if(userp(victim) && victim->query("combat_exp")/3 > me->query("combat_exp") )
	return notify_fail("他比你强太多，你不敢动手。\n");

	if((int)victim->query("age") <= 19 && userp(victim))
		return notify_fail("为了世界更美好，放过小孩子吧.\n");
    if( userp(me) && userp(victim) && victim->query_condition("nokill")
    && !victim->query_condition("killer"))
        return notify_fail("那个人刚被杀过，放过他吧！\n");

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
	

        if (userp(victim) && !query_heart_beat(victim))
        {
         "/cmds/usr/quithy"->main(victim);
        return notify_fail("此人不能beg！\n");
//         write("此人不能beg！\n");
        }



        if( !victim->is_character() || victim->is_corpse() )
	return notify_fail("看清楚一点，那并不是活物。用get比较好。\n");

        if( victim->query("race") != "人类" )
                return notify_fail(victim->name() + "根本不是人，不会理你！\n");
//userp(obj)
        if( userp(victim) && me->query("age")<18 && me->query("combat_exp")<50000)
                return notify_fail(victim->name() + "是玩家，你的能力不足！\n");


        if( !ob = present(what, victim) ) {
                object *inv;
                inv = all_inventory(victim);
                if( !sizeof(inv) )
                        return notify_fail( victim->name() + "身上看起来没有什麽让你感兴趣的东西。\n");
                ob = inv[random(sizeof(inv))];
        }

        if ( ob->query("equipped") || ob->query("no_drop") )
                return notify_fail("这是那人的随身家伙，肯定不会给你。\n");

	if (ob->is_container() )
	{
                return notify_fail("这是个容器，肯定不会给你。\n");
	}

        if(ob->query("dynamic_quest"))
	{
               return notify_fail( victim->name() + "身上看起来没有什麽让你感兴趣的东西。\n");
	}

        if( ob->query("no_beg"))
        return notify_fail("这个东西，你讨不到的！\n");

   if( ob->is_character() || ob->is_corpse() )
   return notify_fail("那种东西不能偷的。\n");

        if( ob->query("no_get",1))
        return notify_fail("这个东西，你讨不到的！\n");

        sp = (int)me->query_skill("begging",1)/20 + (int)me->query("kar");
               
        if( sp < 1 ) sp = 1;
        dp = (int)victim->query("kar");

        tell_object(me, "你装出可怜巴巴的样子，慢慢地向" + victim->name() + "走过去，伸出双手，想要"
                        + ob->query("unit") + ob->name() +"...\n\n");
        tell_object(victim, me->name() + "可怜巴巴地向你慢慢走过来，伸出手，说道：" + RANK_D->query_respect(victim) + "行行好，给我"
                        + ob->query("unit") + ob->name() + "吧 ...！\n\n");
        message("vision", "只见" + me->name() + "装出可怜巴巴的样子，慢慢地向"
                + victim->name() + "走过去，\n伸出双手，说道："
                + RANK_D->query_respect(victim) + "，行行好吧 ...\n\n", environment(me), ({ me, victim}) );

        me->set_temp("begging", 1);
        ob->set("no_get",1);
        call_out( "compelete_beg", 3, me, victim, ob, sp, dp);
        return 1;
}

private void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
        int amount, begging_level;
       int exp,pot;
        object ob1;
        object where;
        if (!environment(me))return notify_fail("这个情况下不能beg了！\n");
        if (!me)  return notify_fail("你已经断线了！\n");
        if (!victim)  return notify_fail("那个人已经不在了！\n");
where= environment(me);
        me->delete_temp("begging");

        if( environment(victim) != environment(me) ) {
                tell_object(me, "太可惜了，你要乞讨的人已经走了。\n");
        if (!ob)  return notify_fail("那样东西已经不在了！\n");
        ob->set("no_get",0);
                return;
        }

        if( living(victim) && (random(sp+dp) > dp) )
        {
        if (!ob)  return notify_fail("那样东西已经不在了！\n");
                if ( ob->query("money_id") )
                {
                        amount = ob->query_amount();
                        if( amount < 5 )
                        {
                                tell_object(me, "看来还是走吧，这家伙身上已经没有多少油水可榨了。\n");
        ob->set("no_get",0);
                                return;
                        }

                        ob->set_amount(amount - amount/5);

                        ob1=new("/clone/money/" + ob->query("money_id"));
                        ob1->set_amount(amount/5);
                        ob1->move(me);
                        ob1->set("no_get",0);

                }
                else if( !ob->move(me) ) {
        if (!ob)  return notify_fail("那样东西已经不在了！\n");
                        ob->move(where);
                        tell_object(me, "你讨到一" + ob->query("unit") + ob->name()
                                + "，可是对你而言太重了，不得丢在地下。\n");
        ob->set("no_get",0);
                        return;
                }
               if (sizeof(all_inventory(me)) >= 40)
                {
                        tell_object(me, "眼看你就要得手，可惜身上的东"
                                    "西太多，实在拿不了了。\n");
                        return;
                }


                tell_object(me, victim->name() + "低头想了一会，又看了看你，摇摇头，叹了口气，丢给你一"
                                + ob->query("unit") + ob->name() + "。\n");
                tell_object(victim, "你看着" +  me->name() +"的可怜样，叹了口气，丢给他一"
                                + ob->query("unit") + ob->name() + "。\n");
// 下面防止潜能和技能达无限增长
      begging_level = me->query_skill("begging", 1);
   if (!me) return notify_fail("你已经断线了！\n");
      if ( (int)me->query("combat_exp") > (begging_level*begging_level*begging_level)/10)
         {
if (me->query_skill("begging"))
{
          me->improve_skill("begging", random(me->query("int")));
}
         }  else {
                 tell_object (me, "就这点经验值也去叫化？还是别去丢人了!\n");
        ob->set("no_get",0);
                  }
      if (( (int)me->query("potential")-(int)me->query("learned_points") < 100))
                me->add("potential",1);
                me->add("combat_exp",1);
        ob->set("no_get",0);
                if( random(sp) > random(dp))
                        message("vision", "你看到" + victim->name() + "冲着" + me->name() + "满脸不屑地摇摇头，"
                                + "丢给他一" + ob->query("unit")
                                + ob->name() + "！\n", environment(me), ({ me, victim }) );
                me->add("jing",-50);
        ob->set("no_get",0);
             //   me->add("eff_jing", -2);
		if (! me->is_busy())
		me->start_busy(6);
	if( userp(victim) && query_ip_name(victim)==query_ip_name(me) )
{
			message_vision(victim->name() + "看$N一眼，你我关系这么好，还来要我的东西。\n", me);

} else
{
exp=28+random(38);
pot=22+random(25);
  if( me->query("family/family_name") == "丐帮" )
{
if (!userp(victim))
{
addnl(me,"exp",exp);
}
}
}

        }
        else
        {
                if( random(sp) < random(dp) ) {
                        message_vision(victim->name() + "狠狠地瞪了$N一眼，喝道：滚！ $N吓了一跳，急忙扭头灰溜溜地走开了。\n", me);
                        me->add("begger", 1);
                        me->add("jing",-20);
        ob->set("no_get",0);
                        me->add("eff_jing", -3);
me->start_busy(3);
                        return;
                }

                tell_object(me, victim->name() + "扭过头去，对你理都不理。\n");
                tell_object(victim, "你扭过头去，对" + me->name() + "理都不理。\n");
                message("vision", victim->name() + "扭过头去，对" + me->name() +  "理都不理。\n",
                        environment(me), ({ me, victim }) );
if(ob)        ob->set("no_get",0);
                        me->add("eff_jing", -3);
                me->start_busy(3);

        }
}

int help(object me)
{
write(@HELP
指令格式 : beg <某物> from <某人>

HELP
    );
    return 1;
}

