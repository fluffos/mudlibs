// hit.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;
         int att;

	if( environment(me)->query("no_fight") )
		return notify_fail("这里禁止战斗。\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻击谁？\n");

        if (me->is_busy())
            return notify_fail("你正忙着呢！\n");
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

         if (obj->query("uni_target"))
            if (obj->query("uni_target") != me)
                return notify_fail("对方不愿和你较量。\n");

  if ( sscanf(base_name(environment(me)),"/d/%*s") &&
       !sscanf(base_name(environment(me)),"/d/wizard/%*s") &&
       userp(me) )
  {
    if ( userp(obj) && me->query("xiuxian_player") )
      return notify_fail("你已经退隐江湖，还是不要再惹江湖上的恩恩怨怨。\n");

    if ( userp(obj) && obj->query("xiuxian_player") )
      return notify_fail("对方已经退隐江湖，你还忍心打搅他的清修？\n");
  }
	 
        if( (me->query("age") < 15) && userp(obj) )
                return notify_fail("你还小，人世间的钩心斗角、自相残杀还是别学的好\n");	

/*
	if( obj->is_fighting(me) )
		return notify_fail("加油！加油！加油！\n");
*/
           if(obj->query("no_fight"))
                  return notify_fail("攻击他对你没有一点好处！！！\n");

	if( me->query_temp("hitting") )
		return notify_fail("加油！加油！加油！\n");

	if( !living(obj) )
	{
		me->add_temp("hit_fainted",1);
		if (me->query_temp("hit_fainted") == 5)
		{

			me->delete_temp("hit_fainted");
		}
		return notify_fail(obj->name() + "已经这样了你还要打，过分了点吧？\n"); 
	}

	if(obj==me)	return notify_fail("打自己？别这么想不开。\n");
	if(sizeof(me->query_enemy())>=30)   
		return notify_fail("江湖之中树敌太多，万子太大，不一定是好事。\n");
	if( userp(obj) ) {
		message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);
//先出手的做个标记，被杀的话杀人者不增加杀气，by all@2015/1/21
		if (!environment(obj)->query("no_die") && !(obj->query("attack_player/id")==me->query("id") && time()-obj->query("attack_player/time")<300)
		&& !(me->query("attack_by_player/id")==obj->query("id") && time()-me->query("attack_by_player/time")<300))
		{
		me->set("attack_player/id",obj->query("id"));
		me->set("attack_player/time",time());
		obj->set("attack_by_player/id",me->query("id"));
		obj->set("attack_by_player/time",time());		
		}		
                 me->fight_ob(obj);
                 obj->fight_ob(me);
		me->set_temp("hitting");
//                 remove_call_out("do_hit");
//                 call_out("do_hit", 1, me, obj);
		return 1;
	}
	
	if( obj->query("can_speak") ) {
		message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);
		
				
		if(obj->accept_hit(me) ) 
			return 1;
			
		me->fight_ob(obj);
//                obj->fight_ob(me);
//added by advent 
//hit会造成小几率叫杀
                switch((string)obj->query("attitude"))
                {
                    case "aggressive ":
                      att=0;
                      break;
                    case "heroism ":
                      att=1;
                      break;
                    case "friendly ":
                      att=4;
                      break;
                    case "peaceful ":
                      att=8;
                      break;
                    default:
                      att=4;
                      break;
                 }
                                
                if (random(att+(int)me->query("kar")/2+(int)me->query_int()/10)>0)
                {
                  obj->fight_ob(me);
                }
                else
                {
                  message_vision(HIR"\n$n红着眼睛对$N大喝一声：“我跟你拼了！”\n\n"NOR, me, obj);
                  obj->kill_ob(me);
                }
//added end
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

void do_hit(object me, object obj)
{
	if(objectp(present(obj, environment(me)))) {
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
                  me->fight_ob(obj);
                  obj->fight_ob(me);
	}
	me->delete_temp("hitting");
	return;
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
 
