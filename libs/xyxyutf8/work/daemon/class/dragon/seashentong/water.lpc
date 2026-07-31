#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	int damage,p;
	string msg,succ_msg,long,*name1,*name2;
	
	if( me->query_level()<30 )
		return notify_fail("你的人物等级不够。\n");
	if((int)me->query("mana")<500 )
        	return notify_fail("你的法力不够！\n");
	if((int)me->query("sen")<200 )
        	return notify_fail("你无法集中精力！\n");
	if( me->query("family/family_name")!="东海龙宫" 
 	 && me->query("chushi/chushi_longgong")!="yes" )
		return notify_fail("你不能使用这项技能！\n");
	if( me->query_skill("seashentong",1)<300 )
		return notify_fail("你的法术还不够熟练。\n");
	if( time()<me->query_temp("sea_water")+8 )
		return notify_fail("你刚刚召唤过神龙。\n");
	if( !target ) target = offensive_target(me);			
	if( !target
 	 || !target->is_character()
 	 || target->is_corpse()
 	 || target==me 
 	 || !me->is_fighting(target) )
		return notify_fail("你要引神龙袭击谁？\n");

	message_vision(HIM"$N"HIM"后退几步，口中念了几句咒文，大叫一声：“神龙何在？“\n"NOR,me);
	me->add("mana", -200);
	me->receive_damage("sen",100,me);
	me->set_temp("sea_water",time());
	if( random(me->query("max_mana")) < 50 ) 
        {
        	message_vision("$N口中念念有词。。。但什么也没有发生！\n"NOR,me);
        	return 1;
        }
	
	p = 0;
	if( me->query_skill("qiyu",2)>100 )
		p = (me->query_skill("qiyu",1)-100)/250+5;
        
	name1 = ({ "花皮", "金角", "金尾","银角"});
	name2 = ({ "背苍", "八爪", "虬髯","五爪",});
	long = name1[random(sizeof(name1))]+name2[random(sizeof(name2))]+"龙";
        msg = HIY"半空中呼地现出一条气势威猛的"+long+"，纵身一吐，一股奇寒无比的水柱喷向$n"HIY"！\n"NOR;
        succ_msg = HIR"结果$n"HIR"躲避不及，被水柱激个正着！\n"NOR;
        damage = me->query_skill("spells")/15;
	if( me->query_skill("qiyu",2)>100 )
		damage+= (me->query_skill("qiyu",1)-100)/250+50;
        
        me->set_temp("pfm_msg",1);
        me->add_temp("apply/spells_succ",p);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg,0,damage);
	me->set_temp("pfm_msg",0);

	if( me->query("daoxing")>=800000 )
	{	
		damage+= me->query("mana_factor")/10;
		long = name1[random(sizeof(name1))]+name2[random(sizeof(name2))]+"龙";
        	msg = HIW"半空中旋又呼地现出一条气势威猛的"+long+"，纵身一吐，又是一股奇寒无比的水柱喷向$n"HIW"！\n"NOR;
        	succ_msg = HIR"结果$n"HIR"躲避不及，被水柱激个正着！\n"NOR;
        	me->set_temp("pfm_msg",1);
        	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg,0,damage);
		me->set_temp("pfm_msg",0);
	}
	me->add_temp("apply/spells_succ",-p);
        return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        法术名称：双龙水柱
        法术所属：碧海神通
        法术效果：召唤神龙，以水柱攻击对手，带固定伤害的法术攻击
        	  当道行达到八百年，则追加一次神龙攻击
                  冷却 8 秒
        法术条件：
                  龙宫(出师)弟子
                  人物等级30级
                  法力500点，消耗200点  
                  精神200点，消耗100点
                  碧海神通300级
LONG;
me->start_more(str);
return 1;
}
