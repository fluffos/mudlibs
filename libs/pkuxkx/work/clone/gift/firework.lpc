//2010年春节礼物，需要相应修改/feature/dbase.c，礼物到期（正月十五）后需将dbase.c改回原版本，否则会浪费系统资源
#include <ansi.h>

inherit ITEM;

string *names = ({
        HIR"火箭弹"NOR,
        HIY"钻天老鼠"NOR,
        HIM"钻天猴"NOR,
        HIC"仙女散花"NOR,
        HIB"满天星"NOR,
        HIW"火树银花"NOR,
        HIY"金碧辉煌"NOR,
        HIY"天上人间"NOR,
        
});
string *wishes = ({
	"春节快乐，虎年虎虎生威！\n" NOR,
	"春节快乐，happy new year！\n"NOR,
	"年年好运,运道齐天,天天幸福 ,福海无边!\n"NOR,
	"年年健康围身绕，月月薪水涨钞票，周周双休乐逍遥，天天美梦好睡觉!\n"NOR,
	"虎年财源滚滚，艳福多多，妻妾成群，儿孙满堂。东摸西吻浅呻吟，左拥右抱美人笑，羡煞韦小宝妒坏西门庆!\n"NOR,
	"虎年快乐，洋洋得意，晦气扬长而去，好运扬眉吐气，阳春白雪漂亮，洋洋洒洒纳福，万事阳关大道！\n"NOR,
});
string *colors = ({
	HIR,
	HIG,
	HIW,
	HIB,
	HIM,
	HIC,
	HIW,
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
    if (me->query_temp("firing2010")) return notify_fail("你正在放烟花呢！\n");
    if((arg=="yan hua") || (arg=="hua")|| (arg=="firework")) 
    {
    	if (this_object()->query("buyer") != me->query("id"))
    		return notify_fail("你从怀里取出焰火，刚想放，忽然想起这支烟花不是你买的，红了红脸，又偷偷放回怀中。\n");
        message_vision(HIR"\n$N把一枚" + this_object()->query("name") + HIR + "放在地上，小心翼翼地点燃引信，立刻躲到一边，满脸期待的样子。\n"NOR,me);
        this_object()->move(VOID_OB);
        me->set_temp("firing2010",1);
        call_out("fire",3,me);
     }
     else return notify_fail("你要放什么？\n");
     return 1;
}

int fire(object me)
{
	if (!me) return 1;
	message_vision(HIR"引信燃尽，" + this_object()->query("name") + HIR + "噌地一声腾空而起，直蹿云霄，\n紧接着爆出" + HIG + "五" + HIY + "彩" + HIW + "斑" + HIM + "斓" + HIR + "的火花，将美丽的夜空点缀得绚丽多彩，也映亮了你喜庆的笑容。\n"NOR,me);
	shout(HIR+me->query("name") + "祝大家" + colors[random(sizeof(colors))] + wishes[random(sizeof(wishes))]);
	call_out("gift",2,me);
	return 1;
}

int gift(object me)
{
	int number,i;
	string type,msg,shoutmsg;
	if (!me) return 1;
	number = random(30) + 1;
	me->set("bonus2010/2010festival",number);
	if (random(4))
	{
		if (random(2))
		{
			me->set("bonus2010/2010type","combat_exp");
			type = "经验";
		}
		else {
			me->set("bonus2010/2010type","potential");
			type = "潜能";
		}
		msg = BLK + HIG + "恭喜！你获得了北侠新春" + HIR + type + HIG + "红包，获一百点以上" + type + HIG + "奖励时额外增加百分之" + HIR + CHINESE_D->chinese_number(number) + HIG + "！\n"+NOR; 
	} else {
		me->set("bonus2010/2010type","magic");
		type = "掉宝率";
		msg = BLK + HIG + "恭喜！你获得了北侠新春" + HIR + type + HIG + "红包，" + type + HIG + "额外增加百分之" + HIR + CHINESE_D->chinese_number(number) + HIG + "！\n"+NOR; 
	}
	if (random(50)==1)
	{
		me->set("bonus2010/2010type","all");
		type = "全能";
		msg = BLK + HIG + "恭喜！你获得了北侠新春" + HIR + type + HIG + "红包，掉宝率及获一百点以上经验或潜能奖励时额外增加百分之" + HIR + CHINESE_D->chinese_number(number) + HIG + "！\n"+ NOR; 
		shoutmsg = BLK + REV + HIR + me->query("name") + "获得北侠新春全能红包！\n" + NOR;
	}
	if (random(50)==1)
	{
		me->set("bonus2010/2010festival",50);
		number = 50;
		msg = BLK + HIG + "恭喜！你获得了北侠新春" + HIR +  "巨额" + HIG + "红包，" + type + HIG + "奖励额外增加百分之" + HIR + CHINESE_D->chinese_number(number) + HIG + "！\n"+NOR; 
		shoutmsg = BLK + REV + HIR + me->query("name") + "获得北侠新春巨额红包！\n" + NOR;
		if (type=="全能")
		{
			msg = BLK + HIG + "恭喜！你获得了北侠新春" + HIR +  "巨额全能" + HIG + "红包，掉宝率及获一百点以上经验或潜能奖励时额外增加百分之" + HIR + CHINESE_D->chinese_number(number) + HIG + "！\n"+NOR; 
			shoutmsg = BNK + BLK + REV + HIR + me->query("name") + "获得北侠新春巨额全能红包！\n" + NOR;			
		}
	}
	log_file("2010hongbao",me->query("id") + "获得百分之" + CHINESE_D->chinese_number(number) + "的" + type + "红包。\n");
	tell_object(me,msg);
	tell_object(me,HIY + REV + HIR  + "烟花销售小姐温馨提示：『获得此红包并不是说你目前的经验或潜能会增长，\n而是在腊月三十到正月十五期间做任务得到的相应奖励会额外增加！』\n" + NOR);
	tell_object(me,HIY + REV + HIR + "烟花销售小姐想了想还是不放心，又说：『如果再放焰火，会获得新的红包，本次红包会失效，不会累积，请一定注意！』\n" + NOR);
	tell_object(me,HIY + REV + HIR + "烟花销售小姐说道：『我已经尽了提醒的义务，要是你没仔细看错过了想要的红包可不要怪我哦！』\n" + NOR);
	CHANNEL_D->do_channel(this_object(),"rumor","听说" + me->query("name") + "获得了增加额外奖励百分之" + HIR + CHINESE_D->chinese_number(number) + HIM + "的" + HIR + type + HIM + "红包！\n");
	me->delete_temp("firing2010");
	shout(shoutmsg);
    destruct(this_object());	
	return 1;
	
}

