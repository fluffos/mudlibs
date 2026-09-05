// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;

	if( environment(me)->query("no_fight") )
		return notify_fail("这里禁止战斗。\n");

        if (me->is_busy())
            return notify_fail("你正忙着呢！\n");


	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻击谁？\n");

	if( !obj->is_character() )
	{
		if (obj->is_mazei())
		{
			return notify_fail("如果要攻击这队马贼，请用kill命令。\n");
		}
		return notify_fail("看清楚一点，那并不是生物。\n");
	}
	if (obj->query("bihua"))
		return notify_fail(obj->query("name") + "正在比武，你不能帮忙。\n");

	if( obj->is_fighting(me) )
		return notify_fail("加油！加油！加油！\n");

           if (obj->query("uni_target"))
              if (obj->query("uni_target") != me)
                  return notify_fail("对方不愿和你较量\n");

  if ( sscanf(base_name(environment(me)),"/d/%*s") &&
       !sscanf(base_name(environment(me)),"/d/wizard/%*s") &&
       userp(me) )
  {
    if ( userp(obj) && me->query("xiuxian_player") )
      return notify_fail("你已经退隐江湖，还是不要再惹江湖上的恩恩怨怨。\n");

    if ( userp(obj) && obj->query("xiuxian_player") )
      return notify_fail("对方已经退隐江湖，你还忍心打搅他的清修？\n");
  }

	if( !living(obj) )
		return notify_fail(obj->name() + "已经无法战斗了。\n"); 
            if(obj->query("no_fight"))
                return notify_fail("攻击他对你没什么好处！！！\n");

	if(obj==me)	return notify_fail("你不能攻击自己。\n");
      	if(sizeof(me->query_enemy())>=30)
	      	return notify_fail("江湖之中树敌太多，万子太大，并不是好事。\n");

	if( userp(obj) && (object)obj->query_temp("pending/fight")!=me ) {
		message_vision("\n$N对著$n说道：" 
			+ RANK_D->query_self(me) 
			+ me->name() + "，领教"
			+ RANK_D->query_respect(obj) + "的高招！\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "取消了和你比试的念头。\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL "如果你愿意和对方进行比试，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 fight 指令。\n" NOR);
		write(YEL "由于对方是由玩家控制的人物，你必须等对方同意才能进行比试。\n" NOR);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N对著$n说道：" 
			+ RANK_D->query_self(me) 
			+ me->name() + "，领教"
			+ RANK_D->query_respect(obj) + "的高招！\n\n", me, obj);

		notify_fail("看起来" + obj->name() + "并不想跟你较量。\n");
		if( !userp(obj) && !obj->accept_fight(me) ) return 0;

		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N大喝一声，开始对$n发动攻击！\n\n", me, obj);
		me->fight_ob(obj);
                if( obj == me->query_temp("created_pet") )
                        obj->fight_ob(me);
                else
                        obj->kill_ob(me);
	}

	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : fight <人物>
 
这个指令让你向一个人物「讨教」或者是「切磋武艺」，这种形式的战斗纯粹是
点到为止，因此只会消耗体力，不会真的受伤，但是并不是所有的  NPC 都喜欢
打架，因此有需多状况你的比武要求会被拒绝。
 
其他相关指令: kill

PS. 如果对方不愿意接受你的挑战，你仍然可以迳行用 kill 指令开始战斗，有
    关 fight 跟 kill 的区分请看 'help combat'.
HELP
    );
    return 1;
}
 
