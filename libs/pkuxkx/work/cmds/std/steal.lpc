// steal.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp,flag=0,assist=0;

    if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
		notify_fail("指令格式：steal <物品> from <人物>\n");

	victim = present(who, environment(me));
	if( !victim || victim==me) return notify_fail("你想行窃的对象不在这里。\n");
    if (victim==me->query_temp("gbnewbiejob/target"))
    {
        flag+=1;
    }
    if (ob=present(what,victim))
    {
        if (ob==me->query_temp("gbnewbiejob/theitem"))
        {
            flag+=1;
        }
    }
        if( (environment(me)->query("no_steal") || environment(me)->query("no_fight"))&&flag!=2)
		return notify_fail("这里禁止行窃。\n");
        if (me->is_busy())
            return notify_fail("你正忙着呢！\n");


	if( me->query_temp("stealing") )
		return notify_fail("你已经在找机会下手了！\n");

	
         if (victim->query("uni_target")&&flag!=2)
            if (victim->query("uni_target") != me)
                return notify_fail("你偷偷摸摸想行窃，"+victim->name()+"狠狠瞪了你一眼，吓得你把手缩了回来。\n");
	if( !wizardp(me) && wizardp(victim) )
                 return notify_fail("这人身上好象没什么值钱的东西！！！\n");
           if(victim->query("no_steal"))
                 return notify_fail("这家伙身上没什么值钱的东西！！！\n");

  if(userp(me) && me->query("jingli")<=50)
              return notify_fail("你的精力不够，不能行窃！\n");
  if (userp(me)&&ob &&ob->query("gb_newbie")&&ob!=me->query_temp("gbnewbiejob/theitem"))
              return notify_fail("偷这样东西恐怕会给你带来杀身之祸！\n");
  if(userp(me)) me->add("jingli",-50);    //加入精力限制防止玩家捣乱

	if( !ob = present(what, victim) ) {
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "身上看起来没有什麽值钱的东西好偷。\n");
		ob = inv[random(sizeof(inv))];
	}
    if (time()-me->query_temp("steal_assist")<90+random(30))//丐帮新手道具
    {
        assist=1;
    }
	sp = (int)me->query_skill("stealing") * 5 + (int)me->query("kar") * 2
		- (int)me->query("thief") * 20;

        if ( (myfam = me->query("family")) && myfam["family_name"] == "丐帮" )
	sp = (int)me->query_skill("stealing") * 10 *(assist+1) + (int)me->query("kar") * 5 * (assist+1)
		- (int)me->query("thief") * 20;
        
    if(flag == 2)//newbie task
    {
        //新手任务不受steal 标志的影响。
        sp += (int)me->query("thief") * 20;
    }

    if (me->query("gaibangnewbiejobdone"))
    {
        sp = sp * 2;
    }

	if( sp < 1 ) sp = 1;
    if (me->query("gbnewbiejob/start")=="steal"&&
        ob->query("name")==me->query_temp("gbnewbiejob/item")
        &&sp<dp*7/10)
    {
        sp=dp*7/10;
    }
	if( me->is_fighting() ) {
		sp /= 2;
		me->start_busy(3);
	}
	dp = (int)victim->query("jing") * 2 + (int)ob->weight()/25;
	if( victim->is_fighting() ) dp *= 10;
	if( ob->query("equipped")&&!me->query("gaibangnewbiejobdone") ) dp *= 10; //做完新手任务，偷东西加概率

	write("你不动声色地慢慢靠近" + victim->name() + "，等待机会下手 ...\n\n");

	me->set_temp("stealing", 1);
	if (userp(me) && userp(victim))
	{
//先出手的做个标记，被杀的话杀人者不增加杀气，by all@2015/1/21
		if ( !environment(victim)->query("no_die") && !(victim->query("attack_player/id")==me->query("id") && time()-victim->query("attack_player/time")<300)
		&& !(me->query("attack_by_player/id")==victim->query("id") && time()-me->query("attack_by_player/time")<300))
		{
		me->set("attack_player/id",victim->query("id"));
		me->set("attack_player/time",time());
		victim->set("attack_by_player/id",me->query("id"));
		victim->set("attack_by_player/time",time());		
		}			
	}			
	call_out( "compelete_steal", 3, me, victim, ob, sp, dp);

	return 1;
}

protected void compelete_steal(object me, object victim, object ob, int sp, int dp)
{
	mapping myfam, vtfam;
	mixed no_steal; //added by whuan 

	if (!me)	return;
	me->delete_temp("stealing");
	

	if( (!victim) || ( environment(victim) != environment(me) )) {
		tell_object(me, "太可惜了，你下手的目标已经走了。\n");
		return;
	}
	if (!ob) {
		tell_object(me,"你要偷的东西已经不存在了。\n");
		return;
	}
    no_steal=(ob->query("no_steal") ||
              ob->query("no_get") ||
              ob->query("no_drop") ||
              ob->query("no_give") ||
              ob->query("no_give_user") ||
              ob->query("gem_ob_autoloaded")) ; 

    if( (!living(victim) && !no_steal) || 
        (random(sp+dp) > dp && !no_steal && (me->query("combat_exp")>victim->query("combat_exp")/6 ||
            (me->query("gbnewbiejob/start")=="steal"&&ob->query("name")==me->query_temp("gbnewbiejob/item")))) ) 
    {
        if( !ob->move(me) ) 
        {
            tell_object(me, "你摸到一" + ob->query("unit") + ob->name() 
            + "，可是对你而言太重了，不得不放弃。\n");
            return;
        }
        tell_object(me, HIW "得手了！\n\n" NOR);
        tell_object(me, "你成功地偷到一" + ob->query("unit") + ob->name() + "！\n");

        if (living(victim) && !userp(victim) ) 
        {
            me->improve_skill("stealing", random((dp/400 + 1)*(me->query("int"))));
            if ( (myfam = me->query("family")) && myfam["family_name"] == "丐帮" ) 
            {
                me->add("potential",1);
                me->add("combat_exp",1);
                ob->set("stealby",me->query("id"));
                ob->remove_call_out("dest_gb_newbie_item");
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
            return;
        }
        if (stringp(no_steal)) tell_object(me, no_steal);
        tell_object(me, HIR "糟糕！你失手了！\n\n" NOR);
        message_vision("$N一回头，正好发现$n的手正抓着$P身上的"+ob->name() + "！\n\n"
                       + "$N喝道：「干什么！」\n\n", victim, me);
        me->improve_skill("stealing", 1, 1);

        if( userp(victim) ) victim->fight_ob(me);
        else if (victim==me->query_temp("gbnewbiejob/target")&&ob==me->query_temp("gbnewbiejob/theitem"))
            victim->fight_ob(me);
        else
            victim->kill_ob(me);

        me->fight_ob(victim);
        me->start_busy(3);
        me->add("thief", 1);
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

