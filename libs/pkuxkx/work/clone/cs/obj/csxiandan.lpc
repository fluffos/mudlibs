// csxiandan.c 仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "六味地黄丸" NOR, ({ "dan", "xian dan", "xiandan" }) );
	set_weight(200);
	if(clonep())
		set_default_object(__FILE__);
	else 
	{
                set("long", "一颗黄色的丸子，不知道能不能吃。\n");
                
                set("no_store", 1);
                set("no_drop", 1);
                set("no_pawn", 1);
                set("no_put", 1);
                set("no_get", 1);
                set("value", 0);
		set("unit", "颗");
	}
	setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;
	string msg;
	int addexp;
	mapping skills;
	string skill;
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        me = this_player();
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() + "。\n", me);
        if(query("owner") != me || environment() != me || random(me->query_temp("csxiandan")) > 20)
        	tell_object(me, "不过你觉得好像没什么作用。\n");
        else
        {
        	me->add_temp("csxiandan", 1);
        	tell_object(me, HIG "你感觉顿感舒泰无比。\n"NOR);
        	
        	//增加后天属性
        	if(random(me->query("combat_exp")) < random(1000000) )	//经验越高，奖励属性几率越低
        	{
        		//1/2的几率给悟性
			switch(random(6))
	        	{
	       		case 0:
	       			me->add_temp("apply/strength", 1);
	       			msg = "膂力";
	       			break;
	       		case 1:
	       		case 2:
	       		case 3:
	       			me->add_temp("apply/intelligence", 1);
	       			msg = "悟性";
	       			break;
	       		case 4:
	       			me->add_temp("apply/constitution", 1);
	       			msg = "根骨";
	       			break;
	       		case 5:
	       			me->add_temp("apply/dexerity", 1);
	       			msg = "身法";
	       			break;	       			
	        	}
	        	tell_object(me, "你的"HIC + msg + NOR"增加了！\n"NOR);   
	        }
	        
	        //增加exp, pot, repute
	        if(random(me->query("exp/cs")) < 10000000)
	        {
	        	addexp = me->query("combat_exp");
	        	addexp = sqrt(addexp);
		        if(addexp > 5000)
		        	addexp = 5000 + sqrt(addexp);
	       		addexp = random(addexp * 2);
		        me->add("combat_exp", addexp);
	        	me->add("exp/cs", addexp);
		        me->add("potential", addexp / 3);
		        me->add("pot/cs", addexp / 3);
		        addexp = random(addexp);
		        me->add("repute", addexp);
		        tell_object(me, "你的经验、潜能和江湖声望增加了！\n"NOR);
		}
	        
	        //增加skill
	        if(mapp(skills = me->query_skills()))
	        {
	        	//30 skill, 40 fy, 50 int, 增加功夫的几率是2.7%
	        	if(sizeof(skills) * (me->query_kar() + me->query("int")) > random(100000))
	        	{
	        		skill = keys(skills)[random(sizeof(skills))];
	        		if(!SKILL_D(skill)->valid_enable("force"))
	        		{	
	        			tell_object(me, "你突然领悟到了"+to_chinese(skill)+"的精髓所在。\n");
	        			tell_object(me, HIC"你的"+to_chinese(skill)+"进步了！\n"NOR);
	        			skills[skill]++;
	        		}
	        	}
	        }
	        
	        //一定的几率晕倒
	        if(random(me->query_temp("csxiandan")) > random(10))
	        {
	        	message_vision("$N\"呃\"的一声，打了一个饱嗝，赶紧松了一下裤带。\n", me);
	        	if(random(me->query_temp("csxiandan")) > 20)
	        	{
	        		tell_object(me, "突然一阵剧痛传来，你感觉到胃已经被撑爆了！\n");
	        		me->delete_temp("last_damage_from");
	        		me->unconcious();
	        	}
	        }	
        }
        destruct(this_object());
	return 1;
}

