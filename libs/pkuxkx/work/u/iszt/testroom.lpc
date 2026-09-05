#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", HIY"乾坤袋"NOR);
	set("long", @LONG
嘿嘿，进了这里你就别想自己出去了。
LONG);
	setup();
}
void init()
{
	add_action("do_none", "");
	this_player()->set("startroom", __FILE__);
	CHANNEL_D->do_channel(this_object(), "rumor",
		this_player()->name()+"陷身"HIY"乾坤袋"NOR"中出不来了！");
}

int do_none(string arg)
{
	string verb = query_verb();
	write("你想"+verb+"？没戏。\n");
	if(verb == "12345ssdlhlhmdzdzxztwhuan")
		this_player()->move("/d/city/guangchang");
	return 1;
}