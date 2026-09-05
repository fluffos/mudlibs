// Room: /clone/misc/kuixinglou.c
// Date: by jason(尔好啊) Tue Nov 17 15:44:29 2009
// edit by zine 21 Aug 2010
inherit "/biwu/biwuroom1";

void create()
{
	set("short", "魁星楼");
	set("long", @LONG
这是一座嘹望楼。刹那之间，你仿佛回到那个金戈铁马的年代，眼前似乎有
几个淳朴的士兵向你笑了笑。一面绣着白色猛虎的战旗迎风招展。
LONG
	);

	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"westtower",
	]));
	set("flag","白虎旗");
	set("default_flag_hp",5);
	set("flag_hp",5);		
	setup();
}

void init()
{	
	this_player()-> delete_temp("xiangyang/pushed");
	::init();
}