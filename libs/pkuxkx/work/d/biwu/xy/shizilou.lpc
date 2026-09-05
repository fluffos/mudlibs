// Room: /clone/misc/shizilou.c
// Date: by jason(尔好啊) Tue Nov 17 15:44:29 2009
// edit by zine 21 Aug 2010
inherit "/biwu/biwuroom1";

void create()
{
	set("short", "狮子楼");
	set("long", @LONG
这是一座巨大的箭楼，刹那之间，你仿佛回到那个金戈铁马的年代，眼前似
乎一队队的士兵们正忙碌的准备着什么。一面绣着青色巨龙的战旗迎风招展。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"easttower",
	]));
	set("flag","苍龙旗");
	set("default_flag_hp",5);
	set("flag_hp",5);		
	setup();
}

void init()
{
    this_player()-> delete_temp("xiangyang/pushed");
	::init();
}