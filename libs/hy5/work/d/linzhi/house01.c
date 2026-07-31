// Room: /d/linzhi/house01.c

inherit ROOM;

void create()
{
	set("short", "藏民帐房");
	set("long", @LONG
这是一间普通的藏民帐房，里面摆设很简单，地上铺着羊毛
织成的地毯，靠门帘的右边摆着一个木质桌台，上面放着一身羊
皮楚巴，桌边上放着一盆清水。你要是渴了，不妨在这噌点水喝。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"by02",
]));

  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/man" : 1,  	
]));
        set("resource/water", 1); 
	setup();
	replace_program(ROOM);
}
