// city_jail.c
// Modified by snowman 21/05/2000

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
      	string room;
      	
      	if ( !stringp(room = base_name(environment(me))) )
      		return 0;
      		
      	if (!duration || duration < 1){
      		if ( room != "/d/city/dalao" )
      			return 0;
      		me->move("/d/city/chmiao");
                message("vision",HIW "\n只听见二、三个人的脚步声向着这边走来。扔下一个五花大绑的家伙后，转身离开了！\n\n" NOR, environment(me), me);
                tell_object(me, HIW "只觉腿脚无力，被人拖着扔进了监狱。\n" NOR);
                me->set("startroom", "/d/city/chmiao");
                return 0;
        }
     
        if ( room !="/d/city/dalao" ) {           
                message_vision(HIR "\n突然冲出来一大群狱卒，指着$N喊道：“看你这逃犯还能逃到哪儿去！”\n"
				"接着便是乱棒齐下，顿时将$N打得昏死过去......\n" NOR, me);
                me->unconcious();
                message_vision("狱卒们扛着晕死过去的$N，急匆匆的走了。\n", me);
                me->set("eff_qi", 1);
                me->set("qi", 1);
                me->apply_condition("city_jail", me->query_condition("city_dail") + 10 +(random(20)) );
                me->move("/d/city/dalao");
                message("vision", HIW "只听见监狱的甬道中二、三个人的脚步声音，向着这边走来。\n"
                        "你定睛一看，原来是一个五花大绑的家伙从铁门外被扔了进来！\n" NOR, environment(me), me);
        }
        me->apply_condition("city_jail", duration - 1);
        return 1;
}

string query_type(object me)
{
        return "jail";
}


