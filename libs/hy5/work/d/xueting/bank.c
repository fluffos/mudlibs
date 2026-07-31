// bank  钱庄

#include <ansi.h>

inherit BANK;
void create()
{
	set("short", "安记钱庄");
        set("long", @LONG
这是一间素来以公平信用著称的钱庄，钱庄的老板还是个曾经
中过举人的读书人，你可以看到钱庄里里外外都打扫得乾乾净净，
一个胖胖的中年人坐在柜台後面，柜台上放著一块牌子(sign)，往
东是通往雪亭镇大街的大门。
LONG
        );
/*
        set("night_long",@LONG
这里就是长安著名的黄记钱庄，单从外表看就气派不凡。虽
说现在已经打烊了，可四处收拾得利利落落，一丝不苟。
LONG
);
*/
        set("item_desc", ([ /* sizeof() == 2 */
	"sign" :  "
安记钱庄        目前提供的服务有：
================================
huan            兑换钱币
cunqian         存钱
quqian          取钱
chazhang        查帐
zhuan		转账
=================================
",
]));
        set("no_beg", 1);

       set("objects",([
        	__DIR__"npc/banker" :1,        
        ]));
	set("exits", ([
                "east"            : __DIR__"guangchang_n", ]) );
        setup();
}
/*
void open_close_door(string msg,object user)
{
	object ob = present("huang shengfa",this_object());

	if(!msg || !user)
		return;
	if( msg == "begin_day")
	{
		if(ob)
			tell_object(user,CYN"黄老板对你一抱拳说道：鄙庄开始营业了！！"+
			RANK_D->query_respect(user)+"有什么要办理的敬请吩咐。\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"开始营业了。\n"NOR);
		return;
	}

	else if( msg == "begin_night")
	{
		if(ob)
			tell_object(user,CYN"黄老板对你说道：鄙庄要休息了，您有什么要办理的事务请明天再来吧。\n"NOR);
		else
			tell_object(user,CYN ""+query("short")+"打烊了。\n"NOR);
		return;
	}
}
*/
