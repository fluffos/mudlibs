// hitall.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj,ob,* inv;
       int att;
        int i;
        if( environment(me)->query("no_fight") )
                return notify_fail("这里禁止战斗。\n");

        if (me->is_busy())
            return notify_fail("你正忙着呢！\n");

        inv=all_inventory(environment(me));

        if(!arg && sizeof(inv) == 0 )
                return notify_fail("你想攻击谁？\n");
 
        if(arg && !objectp(ob = present(arg, environment(me))))
                return notify_fail("你想攻击谁？\n");

        if(arg && !ob->is_character() )
		{
			if (ob->is_mazei())
			{
				return notify_fail("如果要攻击这队马贼，请用kill命令。\n");
			}
			return notify_fail("看清楚一点，那并不是生物。\n");
		}


        if(ob==me)      return notify_fail("打自己？别这么想不开。\n");
        
   for(i=0;i<sizeof(inv);i++)
      { 
         if(sizeof(me->query_enemy())>=20)
        return notify_fail("江湖之中树敌太多，万子太大，并不是好事。\n");
        obj=inv[i];
        if(!obj->is_character() || userp(obj) )
                continue;                        
		if(!me->visible(obj)) continue;
        if (obj->query("uni_target"))
            if (obj->query("uni_target") != me)
                continue;
        if(obj == me)
                continue;
        if (obj->query("no_fight"))
                continue;
        if( obj == me->query_temp("created_pet") )
                continue;
        if(arg && !obj->id(arg) )
                continue;                 
        if (obj->query("bihua"))
            {
                write(obj->query("name") + "正在比武，你不能帮忙。\n");
                continue;
            }
        if( obj->is_fighting(me) )
            {             
                write("加油！加油！加油！\n");
                continue;
            }
        if( me->query_temp("hitting") )
            {
                write("加油！加油！加油！\n");
                continue;
            }
        if( !living(obj) ) continue;
        if( obj->query("can_speak") ) {
                message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj); 
		
		if(obj->accept_hit(me) ) 
			continue;
			                
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
                obj->kill_ob(me);
        }
      }
      return 1;
}

