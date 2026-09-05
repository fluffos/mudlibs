//taiji.c
//加入武当大招效果
#include <ansi.h>

string exert_name(){ return HIG"太极护体"NOR; }

int exert(object me)
{
        int skill,lv_times,xuli_dmg,cd_time;
        string msg;
		string tj_msg;

		if(me->query("safari_skill/wd_taiji"))
		{
			tj_msg = "太极蓄力";
		}
		else
		{
			tj_msg = "太极护体";
		}

        if (!me->is_fighting())
		{
               return notify_fail("你必须在战斗中才能运用"+tj_msg+"。\n");
		}
        if (me->query_temp("tjht"))
                return notify_fail("你已在运用太极"+tj_msg+"了。\n");

        if (me->query_skill("taiji-shengong",1) < 180
            || me->query_skill("force",1) < 180
            || me->query_skill("taoism",1) < 180 )
                return notify_fail("以你目前的修为来看，还不足以运用"+tj_msg+"！\n");

        if (userp(me) && me->query_skill_mapped("force") != "taiji-shengong")
		{

                return notify_fail("你的内功不对，根本不能使出「"+tj_msg+"」。\n");
		}
   
        if (userp(me) && me->query_skill_mapped("cuff") != "taiji-quan")
                return notify_fail("太极之「"+tj_msg+"」诀窍必须在激发太极拳的情况下才能使用。\n");
                
        if (me->query("max_neili") < 2500)
                return notify_fail("你的内力修为不够运用"+tj_msg+"所需！\n");
                
        if (me->query("neili") < 500)
                return notify_fail("你的内力不够运用"+tj_msg+"所需！\n");
			if ( me->query("family/family_name")!="武当派")
			{
				return notify_fail("你不是武当弟子，无法使用"+tj_msg+"。\n");
			}

		if (me->query("safari_skill/wd_taiji") && me->query_skill("taiji-shengong",1)>500)
		{

			if (time() < me->query_temp("taiji_xuli_cdtime"))
			{
                return notify_fail("你距离上次蓄力时间太短，精力尚未平复。\n");	
			}
	        skill = me->query_skill("taiji-shengong", 1);
			lv_times=skill/75;
			lv_times /=(1+me->query("chushi/done")+me->query("betrayer"));
			if (lv_times > 35)
			{
				lv_times = 35;
			}
			xuli_dmg = (int)(skill/50);
			xuli_dmg /= (1+me->query("chushi/done")+me->query("betrayer"));
			if (xuli_dmg > 55)
			{
				xuli_dmg = 55;
			}
			me->set_temp("tjht", lv_times);//最大可叠加次数
			me->set_temp("taiji_xuli",0);
			cd_time = 20+(me->query("chushi/done")+me->query("betrayer"))*10;
			me->set_temp("taiji_xuli_cdtime",time()+cd_time);
	        msg = MAG "\n$N默运内功，将「太极」的极限发挥出来，一股内力运转于周身，脸上渐渐显出紫色的流光！\n" NOR;
			me->set_temp("active_force_buffer/taiji-shengong.taiji/name", "太极蓄力");                                  //buff名称
			me->set_temp("active_force_buffer/taiji-shengong.taiji/last_time", time() + lv_times*5+3 );                //持续时间
			me->set_temp("active_force_buffer/taiji-shengong.taiji/effect1", "战斗中持续增加太极的威力");                     //效果描述1   
	        call_out("checking1", 3, me, xuli_dmg);
		}
		else
		{
			skill = me->query_skill("taiji-shengong", 1) + me->query_skill("taoism", 1);
	        msg = MAG "\n$N默运内功，将「太极」的极限发挥出来，一股内力运转于胸口大穴之上，确保心脉不死，脸上渐渐显出紫色的流光！\n" NOR;
	        me->add_temp("tjht", skill/5);
			me->set_temp("active_force_buffer/taiji-shengong.taiji/name", "太极护体");                                  //buff名称
			me->set_temp("active_force_buffer/taiji-shengong.taiji/last_time", time() + (skill/5+1)*3 );                //持续时间
			me->set_temp("active_force_buffer/taiji-shengong.taiji/effect1", "战斗中持续恢复气血");                     //效果描述1   
		    call_out("checking", 1, me);

		}
	    me->add("neili", -300);
        message_vision(msg, me);
        me->start_busy(1); 
                
        return 1;
}

void checking(object me)
{
        if ( !me ) return;
        else if (me->is_ghost() || !living(me)){
                me->delete_temp("active_force_buffer/taiji-shengong.taiji");
                me->delete_temp("tjht");
        }        
        else if (!me->is_fighting() || me->query("neili") < 500 || me->query_temp("tjht") <= 0 ) {
                message_vision(MAG "\n$N吐出一口淤气，脸上的紫色的流光也渐渐消失了。\n" NOR, me);
                me->delete_temp("active_force_buffer/taiji-shengong.taiji");
                me->delete_temp("tjht");
        }       
        else if(me->query("eff_qi") < me->query("max_qi")/4*3){
                me->add("neili", -50);
                me->receive_curing("qi", 10 + (int)me->query_skill("taiji-shengong")/5 );
                me->add("qi", 30 + (int)me->query_skill("taiji-shengong")/5 );
                if( (int)me->query("qi") > (int)me->query("eff_qi") ) 
                        me->set("qi", (int)me->query("eff_qi"));
                me->add_temp("tjht",-1);
                message_vision(MAG "$N全身紫光流动，将伤口处的流血自动止住了！\n" NOR, me);
                call_out("checking", 3, me);
        }        
        else 
        {
                me->add_temp("active_force_buffer/taiji-shengong.taiji/last_time", 3 );
                call_out("checking", 3, me);
        }
        
        return;
}


void checking1(object me, int xuli_dmg)
{
    if ( !me ) return;
    else if (me->is_ghost() || !living(me))
	{
          me->delete_temp("active_force_buffer/taiji-shengong.taiji");
          me->delete_temp("tjht");
		  me->delete_temp("taiji_xuli");
    }        
    else if (!me->is_fighting() || me->query("neili") < 500 || me->query_temp("tjht") <= 0 ) 
	{
          message_vision(MAG "\n$N吐出一口淤气，脸上的紫色的流光也渐渐消失了。\n" NOR, me);
          me->delete_temp("active_force_buffer/taiji-shengong.taiji");
          me->delete_temp("tjht");
		  me->delete_temp("taiji_xuli");

    }       
    else if (me->query_temp("active_force_buffer/taiji-shengong.taiji"))
	{
          me->add("neili", -50-xuli_dmg);
          me->add_temp("tjht",-1);
		  me->add_temp("taiji_xuli",xuli_dmg);
//		  write("蓄力值:"+me->query_temp("taiji_xuli")+"\n");
          message_vision(MAG "$N全身紫光流动，将太极的劲力渐渐积蓄起来！\n" NOR, me);
          call_out("checking1", 5, me,xuli_dmg);
    }        
    else 
    {
          message_vision(MAG "\n$N一口气散去，脸上的紫色的流光也渐渐消失了。\n" NOR, me);
          me->delete_temp("active_force_buffer/taiji-shengong.taiji");
          me->delete_temp("tjht");
		  me->delete_temp("taiji_xuli");
    }
        
        return;
}
