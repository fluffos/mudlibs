#include <ansi.h>

inherit ITEM;

string *names = ({
        HIR"火箭弹"NOR,
        HIY"钻天老鼠"NOR,
        HIM"钻天猴"NOR,
        HIC"仙女散花"NOR,
        HIB"满天星"NOR,
        HIW"火树银花"NOR,
});


void init()
{
        add_action("do_fire", "fire");
}

void create()
{
        set_name( names[random(sizeof(names))] , ({ "yan hua","hua","firework" }) );
        set("unit", "枚");
        set("long", HIC"这是一枚神奇的烟花，用来在新春佳节燃放(fire)。\n"NOR);
        set("value",0);
        set("no_store",1);
        setup();
}

int do_fire(string arg)
{
    object me;
    me = this_player();
    if (!arg)  return notify_fail("你要放什么？\n");
    if((arg=="yan huo") || (arg=="huo")|| (arg=="firework")) 
    {
    	if (this_object()->query("buyer") != me->query("id"))
    		return notify_fail("你从怀里取出焰火，刚想放，忽然想起这支烟花不是你买的，红了红脸，又偷偷放回怀中。\n");
        message_vision(HIR"\n$N把一枚" + this_object()->query("name") + HIR + "放在地上，小心翼翼地点燃引信，立刻躲到一边，满脸期待的样子。\n"NOR,me);
        this_object()->move(VOID_OB);
        call_out("fire",3,me);
     }
     return 1;
}

int fire(object me)
{
	message_vision(HIR"引信燃尽，" + this_object()->query("name") + HIR + "噌地一声腾空而起，直蹿云霄，\n紧接着爆出五彩斑斓的火花，将美丽的夜空点缀得绚丽多彩，也映亮了你喜庆的笑容。\n"NOR,me);
	shout(HIR+me->query("name") + "祝大家春节快乐，鼠年吉祥！\n" + NOR);
	call_out("gift",2,me);
	return 1;
}

int gift(object me)
{
	int number;
	string type,msg,shoutmsg;
	number = random(30) + 1;
	me->set("bonus2007/2007festival",number);
	if (random(2))
	{
		me->set("bonus2007/2007type","combat_exp");
		type = "经验";
	}
	else {
		me->set("bonus2007/2007type","potential");
		type = "潜能";
	}
	msg = BLK + HIG + "恭喜！你获得了北侠新春" + HIR + type + HIG + "红包，获一千点以上" + type + HIG + "奖励时额外增加百分之" + HIR + CHINESE_D->chinese_number(number) + HIG + "！\n"+NOR; 
	if (random(500)==1)
	{
		me->set("bonus2007/2007type","all");
		type = "全能";
		msg = BLK + HIG + "恭喜！你获得了北侠新春" + HIR + type + HIG + "红包，获一千点以上经验或潜能奖励时额外增加百分之" + HIR + CHINESE_D->chinese_number(number) + HIG + "！\n"+ NOR; 
		shoutmsg = HIR + me->query("name") + "获得北侠新春全能红包！\n" + NOR;
	}
	if (random(500)==1)
	{
		msg = BLK + HIG + "恭喜！你获得了北侠新春" + HIR +  "巨额" + HIG + "红包，获一千点以上" + type + HIG + "奖励时额外增加百分之" + HIR + CHINESE_D->chinese_number(number) + HIG + "！\n"+NOR; 
		shoutmsg = HIR + me->query("name") + "获得北侠新春巨额红包！\n" + NOR;
		me->set("bonus2007/2007festival",50);
		if (type=="全能")
		{
			msg = BLK + HIG + "恭喜！你获得了北侠新春" + HIR +  "巨额全能" + HIG + "红包，获一千点以上经验或潜能奖励时额外增加百分之" + HIR + CHINESE_D->chinese_number(number) + HIG + "！\n"+NOR; 
			shoutmsg = BLK + REV + HIR + me->query("name") + "获得北侠新春巨额全能红包！\n" + NOR;			
		}
	}
	tell_object(me,msg);
	shout(shoutmsg);
    destruct(this_object());
	return 1;
	
}