// jinghun.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

nosave string *xue = ({
"中府穴","商阳穴","承泣穴","胸乡穴",
"尺泽穴","合谷穴","下关穴","服哀穴",
"云门穴","迎香穴","梁门穴","血海穴",
"列缺穴","天鼎穴","梁丘穴","三阴交穴",
"太渊穴","曲池穴","足三里穴","阴陵泉穴",
"通里穴","天宗穴","睛明穴","涌泉穴",
"神门穴","听宫穴","攒竹穴","复溜穴",
"青灵穴","肩贞穴","天柱穴","然谷穴",
"极泉穴","肩中俞穴","膏肓穴","陰谷穴",
"灵海穴","肩外俞穴","承山穴","太溪穴",
"曲泽穴","外关穴","听会穴","期门穴",
"中冲穴","支沟穴","阳白穴","大敦穴",
"劳宫穴","耳门穴","风池穴","行间穴",
"内关穴","翳风穴","肩井穴","太冲穴",
"间使穴","丝竹空穴","风市穴","中封穴",
"会阴穴","五枢穴","筑宾穴","金门穴",
"阴交穴","维道穴","府舍穴","阳交穴",
"气冲穴","大横穴","正营穴","中注穴",
"天突穴","承灵穴","幽门穴","天寥穴",
"商曲穴","百会穴","照海穴","跗阳穴",
"长强穴","檀中穴","交信穴","审脉穴",
"命门穴","中极穴","仆参穴","至阳穴",
"关元穴","巨骨穴","神柱穴","气海穴",
"地仓穴","大椎穴","神阙穴"
"中脘穴","风府穴","天突穴","腰阳关穴"
});

int perform(object me, object target)
{
        string msg,str;
        int damage,t,i;
        
	if( me->query_level()<8 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query("family/family_name") != "方寸山三星洞" 
	 && me->query("chushi/chushi_fangcun")!="yes" )
	 	return notify_fail("此乃菩提秘技。\n");
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me 
 	|| !me->is_fighting(target) )
                return notify_fail("你要对谁施展『惊魂一指』？\n");
        if(!me->is_fighting(target))
                return notify_fail("『惊魂一指』只能在战斗中使用！\n");           
	if(target->is_busy())
                return notify_fail(target->query("name")+"已经不能动弹了。。。\n");  
        if((int)me->query_skill("puti-zhi",1) < 80)
                return notify_fail("你的『菩 提 指』等级不够！\n");
        if((int)me->query("force") < 200 )
                return notify_fail("你的内力不够200点！\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("你无法集中精神！\n");

        me->add("force", -80);
        me->receive_damage("sen", 20);
        msg = HIY"$N"HIY"身影如旋风般舞动，指风破空之声嗤嗤不绝袭向$n"HIY"各处要穴。\n"NOR;
        message_vision(msg, me, target);
        i = me->query_skill("puti-zhi",1)/50;
        if( i>3 )
        	i = 3;	
        while(i--)
        {
        	if( !me || !target || !living(me) 
        	 || !me->is_fighting(target) )
			break;
		str = xue[random(sizeof(xue))];
		msg = HIY"“嗖”一道指风射向$n"HIY+str+"！\n"NOR;
		me->set_temp("pfm_msg",1);	
		damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg);
		me->set_temp("pfm_msg",0);
		if( damage>0 )
		{
			message_combatd("$n只觉"+str+"一麻！\n",me,target);
			target->start_busy((int)target->query_busy()+2);
		}	
        }
        me->start_busy(1);
        return 1;
}

int help(object me)
{
	string str;
	if( !me )      
		return 0;
str = @LONG
        外功名称：惊魂一指
        外功所属：菩 提 指
        外功效果：连续打击对方穴道，每次命中增加对方busy 2秒
        	  最多攻击3次
                  自身busy 1 秒
        外功条件：
        	  人物等级8级
        	  方寸(出师)弟子
        	  菩提指80级	
                  内力200点，消耗80点
                  精神100点，消耗20点
LONG;
	me->start_more(str);
	return 1;
} 