// Room: /clone/misc/zhongxuanlou.c
// Date: by jason(尔好啊) Tue Nov 17 15:44:29 2009
// edit by zine 21 Aug 2010
inherit "/biwu/biwuroom1";

void create()
{
	set("short", "仲宣楼");
	set("long", @LONG
这是一座烽火楼，烽火并未燃尽，依然向故国传递着不屈的呐喊。一刹那之
间，你仿佛回到那个金戈铁马的年代，眼前似乎一队队的士兵们正忙碌的准备着
什么。一面绣着红色朱雀的战旗迎风招展。
LONG
	);

	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
		"west" : __DIR__"southtower",
	]));
	set("flag","朱雀旗");
	set("default_flag_hp",5);
	set("flag_hp",5);		
	setup();
}

void init()
{
    this_player()-> delete_temp("xiangyang/pushed");
	::init();
}