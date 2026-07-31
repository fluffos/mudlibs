#include <ansi.h>
inherit SSERVER;

int valid_cast(object me)
{
	int t = me->query_skill("bubu-shenglian",1);
	if(me->query("family/family_name") != "南海普陀山")
        	return notify_fail("不是佛门弟子,不懂这佛门奥义！\n");
	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");        
        if( (int)me->query("mana") < 100 )
                return notify_fail("你的法力不够了！\n");
	t = 60-t/30;
	if( t>3 )
		t = 3;
	if( time()<me->query_temp("last_huicheng")+t )
		return notify_fail("你刚刚召唤过莲台宝座。\n");
	return 1;
}	

int cast(object me, object target)
{       
	string str;
	int i;
	
	if( !valid_cast(me) )
		return 0;
	if( me->is_fighting() )
		return notify_fail("战斗中不能使用。\n");
	if( me->is_no_move() )
		return notify_fail("你现在动弹不得。\n");
	if( environment(me)->query("no_huicheng") )
		return notify_fail("这里不能使用回城诀。\n");
	i = me->query_skill("buddhism",1);
	i/= 15;
	if( i<1 ) i = 1;
	if( i>9 ) i = 9;			
        message_vision("$N喃喃地念了几句咒语。\n", me);
        me->add("mana", -50);
        if( random(me->query("max_mana")) < 20 ) {
                message("vision", "但是什么也没有发生。\n",environment(me));
                return 1;
        }
	message_vision(HIY"只见$N"HIY"足下生出一朵"+chinese_number(i)+"品金莲，祥云阵阵，径往南海而去。。。。\n\n"NOR,me);
	me->set_temp("last_huicheng",time());
        if( me->is_fighting() )
        	me->start_busy(5);
        me->move("/d/nanhai/guangchang",2);
        message("vision",HIY"\n\n一朵"+chinese_number(i)+"品金莲从头而降，"+me->name()+HIY"从上面走了下来。\n\n"NOR,environment(me),({me}));
        tell_object(me,HIC"\n你借莲台宝座回到了师门。\n"NOR);
        return 3;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：足下生莲
        法术所属：大乘佛法
        法术效果：返回师门
        	  战斗中不能使用
        法术条件：
                  普陀弟子
        	  人物等级5级
                  法力100点，消耗50点
                  
STR;
        me->start_more(str);
        return 1;
}