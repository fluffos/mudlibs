//Room: /d/foshan/youtiaopu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","油条铺");
	set("long",@LONG
这家烧饼油条铺是新开张的。铺面不大，正中央摆了一个大炸
锅和一个烤炉。
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"street4",
	]));
	setup();
}

