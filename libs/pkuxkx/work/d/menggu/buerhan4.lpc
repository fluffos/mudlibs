inherit ROOM; 
#include <ansi.h>
string look_shi();

void create() 
{ 
        set("short", HIW"主峰"NOR);
        set("long", @LONG
这里是不儿罕山的主峰，终年积雪，也是斡难河的源头。一块巨大晶状岩石
(shi)仿佛天外之物矗立在主峰正中。
LONG
        );
	
        set("exits", ([ "southdown" : __DIR__"buerhan3",
                        "west" : __DIR__"buerhan6",
                        "northdown": __DIR__"buerhan5",
]));
        set("outdoors", "menggu_e");
		set("item_desc",
        ([
        "shi":(:look_shi:),
        ]));
		setup();
}

string look_shi()
{
	object me=this_player(),record=load_object(__DIR__"zeiwo");
	string msg;
	int exp,other;
	msg=HBCYN+HIW+"蒙古区域主线QUESTs\n\n"+NOR;
	msg+=HIC+"【大漠风云】"+NOR+"：";
	if (me->query("shediaoquest/dmfy/endtime"))
	{
		msg+="√";
	}
	else
	{
		msg+="……";
	}
	msg+=HIC+"\n【拜师哲别】"+NOR+"：";
	if (me->query("shediaoquest/zhebie")>=2)
	{
		msg+="√";
	}
	else
	{
		msg+="……";
	}
	msg+=HIC+"\n【射雕英雄】"+NOR+"：";
	if (me->query("shediaoquest/shediao"))
	{
		msg+="√";
	}
	else
	{
		msg+="……";
	}
	msg+=HIC+"\n【悬崖传功】"+NOR+"：";
	if (me->query("shediaoquest/mayu")==2)
	{
		msg+="√";
	}
	else
	{
		msg+="……";
	}
	msg+=HIC+"\n【金刀驸马】"+NOR+"：";
	if (me->query("shediaoquest/jdfm"))
	{
		msg+="√";
	}
	else
	{
		msg+="……";
	}
	msg+=HBWHT+RED+"\n蒙古区域支线QUESTs\n\n"+NOR;
	msg+=HIW+"【初识蒙古】"+NOR+"：";
	if (me->query("mengguquest/intro"))
	{
		msg+="√";
	}
	else
	{
		msg+="开启地点：蒙古入口";
	}
	msg+=HIW+"\n【一枝花的心事】"+NOR+"：";
	if (me->query("mengguquest/xinshi"))
	{
		msg+="√";
	}
	else
	{
		msg+="开启地点：益兰州附近";
	}
	msg+=HIW+"\n【逍遥的烦恼】"+NOR+"：";
	if (me->query("mengguquest/alucar_finish"))
	{
		msg+="√";
	}
	else
	{
		msg+="开启地点：绿洲附近";
	}
	msg+=HIW+"\n【火狐狸】"+NOR+"：";
	if (me->query("mengguquest/hunter_finish"))
	{
		msg+="√";
	}
	else
	{
		msg+="开启地点：益兰州广场附近";
	}
	msg+=HIW+"\n【草原借箭】"+NOR+"：";
	if (me->query("mengguquest/arrow"))
	{
		msg+="√";
	}
	else
	{
		msg+="开启地点：桑昆部落附近";
	}
	msg+=HIW+"\n【寻隐者不遇】"+NOR+"：";
	if (me->query("mengguquest/yinzhe_finish"))
	{
		msg+="√";
	}
	else
	{
		msg+="开启地点：不儿罕山南麓山谷附近";
	}
	msg+="\n\n\n";
	msg+=HBMAG+HIW+"清剿马贼\n"+NOR;
	record->restore();
	exp=record->query("reward_for_exp/"+me->query("id")+"/points");
	other=record->query("reward_for_others/"+me->query("id")+"/points");
	msg+="【功绩】："+HIW+chinese_number(exp)+NOR+"点\t【赏金】："+HIW+MONEY_D->money_str(other)+NOR+"\n";
	if (me->query("statistic/menggu_mazei/robber_kills"))
	{
		msg+="总计杀死"+chinese_number(me->query("statistic/menggu_mazei/robber_kills"))+"个马贼。\n";
	}
	msg+="\n\n\n";
	return msg;
}