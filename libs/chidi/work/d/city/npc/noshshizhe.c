inherit BHNPC;

#include <ansi.h>
#include <localtime.h>

mapping giftday	= ([
	"2M7D" : "/clone/gift/gift/nosh.c",
	"2M8D" : "/clone/gift/gift/nosh.c",
        "2M9D" : "/clone/gift/gift/nosh.c",
        "2M10D" : "/clone/gift/gift/nosh.c",
        "2M11D" : "/clone/gift/gift/nosh.c",
]);

string ask_liwu();

void create()
{
	set_name(HIR"礼物使者"NOR, ({ "nosh shizhe", "nosh" }));
	set("nickname", HIY"美林小厨"NOR);
	set("gender", "男性" );
	set("age", 18);
	set("long", YEL"四大皆空，坐片刻无分你我。\n两头是路，吃一杯各奔东西。\n"NOR);
	set("shen_type", 1);
	set("combat_exp", 999999999);
	set("str", 300);
	set("dex", 300);
	set("con", 300);
	set("int", 30);
	set("per", 30);
	set("attitude", "friendly");
	set("max_qi", 100000);
	set("neili", 100000);
	set("jingli",21000000);
	set("score", 100000);

	set("inquiry", ([
		"点心" : (: ask_liwu :),
		"节日" : (: ask_liwu :),
		"gift" : (: ask_liwu :),
		"喜庆" : (: ask_liwu :),
		"nosh" : (: ask_liwu :),
        ]));
	setup();
}

void init()
{
	::init();
}

string ask_liwu()
 {
	 int iMonth, iDay;
	 string strTime, strGift, strTemp, strRtn;
	 object me, gift;

	 me		= this_player();
	 iDay	= localtime(time())[LT_MDAY];
	 iMonth	= localtime(time())[LT_MON] + 1;

	 strTime	= (string)iMonth + "M" + (string)iDay + "D";
	 if(stringp(strGift = giftday[strTime]))
	 {
		 strGift	= giftday[strTime];
		 strTemp	= "clygiftrobot/" + strTime;
		 if( (int)me->query(strTemp) > 0 )
			 strRtn	= "一次节日只能领一次礼物喔！\n";
		 else
		 {
			 me->delete("clygiftrobot");
			 me->set(strTemp, 1);
			 gift	= new(strGift);
			 gift->move(me);

			 strRtn	= "来尝一个小礼物吧！节日快乐喔！\n";
		 }
	 }
	 else
		 strRtn	= "今天是什么节日捏？有新节日出现请通知Wiz喔！\n";

	 return strRtn;
}
