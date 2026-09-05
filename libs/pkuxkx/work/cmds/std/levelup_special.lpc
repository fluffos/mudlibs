//升级特技 by yhzzyahoo@pkuxkx
//修改一些特技升级的前置
#include <ansi.h>
inherit F_CLEAN_UP;

string *specialsk=({
        "intellect","energy","constitution","chainless","perceive","sociability","lucky",
        "greedy","agile","might","corporeity","ironskin","spirituality","athanasy","health"
});
string *specialsk2=({
        "聪明睿智","聚精会神","镇蕴七星","金蝉脱壳","传音搜魂","长袖善舞","洪福齐天",
        "饕餮之力","身轻如燕","力大无穷","固本培元","铜皮铁骨","灵气逼人","凤凰涅磐","气息悠长",
});      
    
int main(object me, string arg)
{
    string msg;
	int now_pot;
    int i;
	int lv_sucess;
    if(me->is_busy())   return notify_fail("你正忙着呢...\n");
	if(!arg || sizeof(arg) == 0)
		return notify_fail("请输入正确的参数\n");
	if (arg=="-h")
	{
		tell_object(me,"你的升级点数为："+me->query("special/levelup_point")+"点。\n");  
		return 1;
	}
	now_pot=to_int(me->query("potential") - me->query("learned_points"));
    if(me->query("special/levelup_point") < 1)  
        return notify_fail("你升级次数不足，无法升级！\n");
    if(me->query("balance") <= 50000000)  
        return notify_fail("你的存款不足，需要至少5000gold才能升级！\n");
	if(me->query("repute") < 5000000)
		return notify_fail("你的声望不足，需要至少500万声望才能升级特技！\n");
	if (now_pot<1000000)
	{
		return notify_fail("你的潜能不足，需要至少100万潜能才能升级！\n");
	}
    if(!me->query("special_skill/"+arg))
         return notify_fail("你只能升级你已有的特殊技能！\n");
	if (!me->query("special_level/"+arg))
	{
		me->set("special_level/"+arg,1);
	}
	
	lv_sucess=0;

	switch (arg)
	{
	case "agile":
		switch (me->query("special_level/agile"))
		{
		case 1:
			if (me->query("special_skill/chainless")&&(me->query("special_level/chainless")))
			{
				me->add("special_level/agile",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要金蝉脱壳的支持。\n");
			}
		break;
		case 2:
				me->add("special_level/agile",1);
				lv_sucess=1;
		break;
		case 0:
			me->set("special_level/"+arg,1);
			return notify_fail("升级没有成功，请重试。\n");
		break;
		default:
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		break;
		}

	break;
	case "chainless":
		switch (me->query("special_level/chainless"))
		{
			case 1:
				if ((me->query("special_skill/agile"))&&(me->query("special_level/agile")))
				{
					me->add("special_level/chainless",1);
					lv_sucess=1;
				}
				else
				{
					return notify_fail("您这个特殊技能升级需要身轻如燕等级一的支持。\n");
				}
			break;
			case 2:
				if (me->query("special_skill/agile")&&(me->query("special_level/agile")>1))
				{
					me->add("special_level/chainless",1);
					lv_sucess=1;
				}
				else
				{
					return notify_fail("您这个特殊技能升级需要身轻如燕等级二的支持。\n");
				}

			break;
			case 3:
				if ((me->query("special_skill/energy"))&&(me->query("special_level/energy")>0))
				{
					me->add("special_level/chainless",1);
					lv_sucess=1;
				}
				else
				{
					return notify_fail("您这个特殊技能升级需要聚精会神等级二的支持。\n");
				}

			break;
			case 0:
				me->set("special_level/"+arg,1);
				return notify_fail("升级没有成功，请重试。\n");
			break;
			default:
				return notify_fail("您这个特殊技能已经升级到最高级了。\n");
			break;
		}
	break;
	case "might":
		switch (me->query("special_level/might"))
		{
		case 1:
			if ((me->query("special_skill/greedy"))&&(me->query("special_level/greedy")))
			{
				me->add("special_level/might",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要饕餮之力的支持。\n");
			}
		break;
		case 2:
			if ((me->query("special_skill/greedy"))&&(me->query("special_level/greedy")>1))
			{
				me->add("special_level/might",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要饕餮之力等级二的支持。\n");
			}
		break;
		case 3:
			if (me->query("special_skill/spirituality"))
			{
				me->add("special_level/might",1);
				lv_sucess=1;
			}

		break;
		case 0:
			me->set("special_level/"+arg,1);
			return notify_fail("升级没有成功，请重试。\n");
		break;
		default:
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		break;
		}
	break;
	case "lucky":
		switch (me->query("special_level/lucky"))
		{
		case 1:
			if ((me->query("special_skill/sociability"))&&(me->query("special_level/sociability")))
			{
				me->add("special_level/lucky",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要长袖善舞的支持。\n");
			}
		break;
		case 0:
			me->set("special_level/"+arg,1);
			return notify_fail("升级没有成功，请重试。\n");
		break;
		default:
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		break;
		}
	break;
	case "greedy":
		if (me->query("special_level/greedy")>2)
		{
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		}
		else
		{
			me->add("special_level/greedy",1);
			lv_sucess=1;
		}
	break;
	case "athanasy":
		switch (me->query("special_level/athanasy"))
		{
		case 1:
				me->add("special_level/athanasy",1);
				lv_sucess=1;
		break;
		case 2:
			if ((me->query("special_skill/spirituality"))&&(me->query("special_level/spirituality")))
			{
				me->add("special_level/athanasy",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要灵气逼人的支持。\n");

			}

		break;
		case 0:
			me->set("special_level/"+arg,1);
			return notify_fail("升级没有成功，请重试。\n");
		break;
		default:
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		break;
		}	
	break;
	case "health":
		if (me->query("special_level/health")<3)
		{
			me->add("special_level/health",1);
			lv_sucess=1;
		}
		else
		{
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");

		}

	break;
	case "energy":
		switch (me->query("special_level/energy"))
		{
		case 1:
			if (me->query("special_skill/intellect"))
			{
				me->add("special_level/energy",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要聪明睿智的支持。\n");
			}
		break;
		case 0:
			me->set("special_level/"+arg,1);
			return notify_fail("升级没有成功，请重试。\n");
		break;
		default:
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		break;
		}

	break;	
	case "ironskin":
		if (me->query("special_level/ironskin")<3)
		{
			me->add("special_level/ironskin",1);
			lv_sucess=1;
		}
		else
		{
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");

		}
	break;
	case "corporeity":
		switch (me->query("special_level/corporeity"))
		{
		case 1:
			if ((me->query("special_skill/constitution"))&&(me->query("special_level/constitution")))
			{
				me->add("special_level/corporeity",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要镇蕴七星的支持。\n");
			}
		break;
		case 0:
			me->set("special_level/"+arg,1);
			return notify_fail("升级没有成功，请重试。\n");
		break;
		default:
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		break;
		}
	break;
	case "intellect":
		if (me->query("special_level/intellect")>1)
		{
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		}
		else
		{
			me->add("special_level/intellect",1);
			lv_sucess=1;
		}
	break;	
	case "perceive":
		if (me->query("special_level/perceive")>1)
		{
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		}
		else
		{
			me->add("special_level/perceive",1);
			lv_sucess=1;
		}
	break;
	default:
        tell_object(me,"这个特殊技能无法升级。\n");  
	break;

	}
	if (lv_sucess)
	{
		me->add("special/levelup_point",-1);
	    me->add("repute",-300000);
		me->add("balance",-50000000);
		me->add("potential",-1000000);
		me->save();
		i = member_array(arg,specialsk);
		tell_object(me,"个人特殊技能"HIR+specialsk2[i]+"("+specialsk[i]+")"+NOR"升级完毕，现有等级"+chinese_number(me->query("special_level/"+arg))+"级。\n");  
	}
	else
	{
		return notify_fail("升级没有成功，请重试。\n");
	}
    return 1;

}		

int main_bak(object me, string arg)
{
    string msg;
	int now_pot;
    int i;
	int lv_sucess;
    if(me->is_busy())   return notify_fail("你正忙着呢...\n");
	if(!arg || sizeof(arg) == 0)
		return notify_fail("请输入正确的参数\n");
	if (arg=="-h")
	{
		tell_object(me,"你的升级点数为："+me->query("special/levelup_point")+"点。\n");  
		return 1;
	}
	now_pot=to_int(me->query("potential") - me->query("learned_points"));
    if(me->query("special/levelup_point") < 1)  
        return notify_fail("你升级次数不足，无法升级！\n");
    if(me->query("balance") <= 50000000)  
        return notify_fail("你的存款不足，需要至少5000gold才能升级！\n");
	if(me->query("repute") < 5000000)
		return notify_fail("你的声望不足，需要至少500万声望才能升级特技！\n");
	if (now_pot<1000000)
	{
		return notify_fail("你的潜能不足，需要至少100万潜能才能升级！\n");
	}
    if(!me->query("special_skill/"+arg))
         return notify_fail("你只能升级你已有的特殊技能！\n");
	if (!me->query("special_level/"+arg))
	{
		me->set("special_level/"+arg,1);
	}
	
	lv_sucess=0;

	switch (arg)
	{
	case "agile":
		switch (me->query("special_level/agile"))
		{
		case 1:
			if (me->query("special_skill/chainless")&&(me->query("special_level/chainless")))
			{
				me->add("special_level/agile",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要金蝉脱壳的支持。\n");
			}
		break;
		case 2:
			if ((me->query("special_skill/ironskin"))&&(me->query("special_level/ironskin")>1))
			{
				me->add("special_level/agile",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要铜皮铁骨等级二的支持。\n");

			}

		break;
		case 0:
			me->set("special_level/"+arg,1);
			return notify_fail("升级没有成功，请重试。\n");
		break;
		default:
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		break;
		}

	break;
	case "chainless":
		switch (me->query("special_level/chainless"))
		{
			case 1:
				if ((me->query("special_skill/agile"))&&(me->query("special_level/agile")))
				{
					me->add("special_level/chainless",1);
					lv_sucess=1;
				}
				else
				{
					return notify_fail("您这个特殊技能升级需要身轻如燕等级一的支持。\n");
				}
			break;
			case 2:
				if (me->query("special_skill/agile")&&(me->query("special_level/agile")>1)&&
					me->query("special_skill/lucky")&&(me->query("special_level/lucky")>1))
				{
					me->add("special_level/chainless",1);
					lv_sucess=1;
				}
				else
				{
					return notify_fail("您这个特殊技能升级需要身轻如燕等级二以及洪福齐天等级二的支持。\n");
				}

			break;
			case 3:
				if ((me->query("special_skill/energy"))&&(me->query("special_level/energy")>0))
				{
					me->add("special_level/chainless",1);
					lv_sucess=1;
				}
				else
				{
					return notify_fail("您这个特殊技能升级需要聚精会神等级二的支持。\n");
				}

			break;
			case 0:
				me->set("special_level/"+arg,1);
				return notify_fail("升级没有成功，请重试。\n");
			break;
			default:
				return notify_fail("您这个特殊技能已经升级到最高级了。\n");
			break;
		}
	break;
	case "might":
		switch (me->query("special_level/might"))
		{
		case 1:
			if ((me->query("special_skill/greedy"))&&(me->query("special_level/greedy")))
			{
				me->add("special_level/might",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要饕餮之力的支持。\n");
			}
		break;
		case 2:
			if ((me->query("special_skill/greedy"))&&(me->query("special_level/greedy")>1))
			{
				me->add("special_level/might",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要饕餮之力等级二的支持。\n");
			}
		break;
		case 3:
			if ((me->query("special_skill/spirituality"))&&(me->query("special_level/spirituality")))
			{
				me->add("special_level/might",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要灵气逼人的支持。\n");

			}

		break;
		case 0:
			me->set("special_level/"+arg,1);
			return notify_fail("升级没有成功，请重试。\n");
		break;
		default:
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		break;
		}
	break;
	case "lucky":
		switch (me->query("special_level/lucky"))
		{
		case 1:
			if ((me->query("special_skill/sociability"))&&(me->query("special_level/sociability")))
			{
				me->add("special_level/lucky",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要长袖善舞的支持。\n");
			}
		break;
		case 0:
			me->set("special_level/"+arg,1);
			return notify_fail("升级没有成功，请重试。\n");
		break;
		default:
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		break;
		}
	break;
	case "greedy":
		if (me->query("special_level/greedy")>2)
		{
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		}
		else
		{
			me->add("special_level/greedy",1);
			lv_sucess=1;
		}
	break;
	case "athanasy":
		switch (me->query("special_level/athanasy"))
		{
		case 1:
			if ((me->query("special_skill/intellect"))&&(me->query("special_level/intellect")))
			{
				me->add("special_level/athanasy",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要聪明睿智的支持。\n");
			}
		break;
		case 2:
			if ((me->query("special_skill/constitution"))&&(me->query("special_level/constitution")))
			{
				me->add("special_level/athanasy",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要镇蕴七星的支持。\n");

			}

		break;
		case 0:
			me->set("special_level/"+arg,1);
			return notify_fail("升级没有成功，请重试。\n");
		break;
		default:
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		break;
		}	
	break;
	case "health":
		if (me->query("special_level/health")<3)
		{
			me->add("special_level/health",1);
			lv_sucess=1;
		}
		else
		{
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");

		}

	break;
	case "energy":
		switch (me->query("special_level/energy"))
		{
		case 1:
			if (me->query("special_skill/intellect"))
			{
				me->add("special_level/energy",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要聪明睿智的支持。\n");
			}
		break;
		case 0:
			me->set("special_level/"+arg,1);
			return notify_fail("升级没有成功，请重试。\n");
		break;
		default:
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		break;
		}

	break;	
	case "ironskin":
		if (me->query("special_level/ironskin")<3)
		{
			me->add("special_level/ironskin",1);
			lv_sucess=1;
		}
		else
		{
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");

		}
	break;
	case "corporeity":
		switch (me->query("special_level/corporeity"))
		{
		case 1:
			if ((me->query("special_skill/constitution"))&&(me->query("special_level/constitution")))
			{
				me->add("special_level/corporeity",1);
				lv_sucess=1;
			}
			else
			{
				return notify_fail("您这个特殊技能升级需要镇蕴七星的支持。\n");
			}
		break;
		case 0:
			me->set("special_level/"+arg,1);
			return notify_fail("升级没有成功，请重试。\n");
		break;
		default:
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		break;
		}
	break;
	case "intellect":
		if (me->query("special_level/intellect")>1)
		{
			return notify_fail("您这个特殊技能已经升级到最高级了。\n");
		}
		else
		{
			me->add("special_level/intellect",1);
			lv_sucess=1;
		}
	break;	
	default:
        tell_object(me,"这个特殊技能无法升级。\n");  
	break;

	}
	if (lv_sucess)
	{
		me->add("special/levelup_point",-1);
	    me->add("repute",-300000);
		me->add("balance",-50000000);
		me->add("potential",-1000000);
		me->save();
		i = member_array(arg,specialsk);
		tell_object(me,"个人特殊技能"HIR+specialsk2[i]+"("+specialsk[i]+")"+NOR"升级完毕，现有等级"+chinese_number(me->query("special_level/"+arg))+"级。\n");  
	}
	else
	{
		return notify_fail("升级没有成功，请重试。\n");
	}
    return 1;

}

int help(object me)
{
        write(@HELP
指令格式 : levelup_special <特技id>/-h

这个指令将一个已有特技升级，增强此特技效果，有些特技
可能需要一些前置条件，另外，还需花费5000gold，30万声望
和100万潜能，需要500万声望支持。
-h为查询升级点数命令。

see also : help special / help kungfu-special
HELP
    );
    return 1;
}

