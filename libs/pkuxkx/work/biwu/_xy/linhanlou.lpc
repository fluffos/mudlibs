// Room: /clone/misc/linhanlou.c
// Date: by jason(尔好啊) Tue Nov 17 15:44:29 2009
// edit by zine 21 Aug 2010
inherit "/biwu/biwuroom1";

void create()
{
	set("short", "临汉楼");
	set("long", @LONG
这是一座门楼，北眺汉江。刹那之间，你仿佛梦回那个金戈铁马的年代，一
个身披战甲的将军正面色凝重的观察着北方。一面绣着巨大黑色玄龟的战旗迎风
招展。
LONG
	);

	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
		"east" : __DIR__"northtower",
	]));
	set("flag","玄武旗");
	set("default_flag_hp",5);
	set("flag_hp",5);		
	setup();
}


void init()
{
    this_player()-> delete_temp("xiangyang/pushed");
	::init();
}