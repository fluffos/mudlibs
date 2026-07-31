// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

inherit ROOM;

void create()
{
	set("short", "树洞下");
	set("long", @LONG
这是老槐树底部，四周光线昏暗，人影晃晃，似乎有几个黑暗的洞口
在你身边，通向四面八方。  一位老乞丐大咧咧地坐在正中的地上。不经
意中你发现墙壁上画着幅粗糙的路线草图（map）。
LONG
	);

	set("exits", ([
		"up":__DIR__"inhole",
"down":__DIR__"chuchang",
//		"down":__DIR__"chuchang",
		"2":__DIR__"zlandao1",
	]));

	set("item_desc",([ "map" : 
		"出口二：通往竹林。\n" 
	]));

	set("objects",([
		CLASS_D("gaibang") + "/liang" : 1,
	]));

	setup();
	replace_program(ROOM);
}



