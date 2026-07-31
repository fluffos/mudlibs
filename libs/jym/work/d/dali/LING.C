//Cracked by Kafei
//final
// Room: /d/newdali/ling.c

inherit ROOM;

void create()
{
	set("short", "黑龙岭");
	set("long", @LONG
黑龙岭上有红梅二株，干已剥蚀贻尽，仅存枯皮，古质斑斓，横卧于地，离
奇乔异，如骄龙，如横峰，而花朵攒躜，又如锦片，如火球，清芳袭人，不知植
自何代，相传以为唐梅，疑或然也。西南面就是黑龙潭。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ 
		"north" : __DIR__"quan1",
		"southeast" : __DIR__"maze1",
		"northwest" : __DIR__"droad4",
		]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
