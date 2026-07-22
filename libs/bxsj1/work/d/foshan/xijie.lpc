// Room: /d/fuoshan/xijie.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "佛山西街");
	set("long", @LONG
这是一条宽阔的青石板街道，人来人往，非常热闹，东面是佛山的中
央广场。南面隐隐传来喧哗声，几个打手凶神恶煞地站在两扇金边黑漆的
大门前。
LONG
	);
        set("outdoors","佛山");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"duchang",
  "east" : __DIR__"guangchang",
  "west" : __DIR__"xijie2",
]));

        set("objects", ([
        __DIR__"npc/liumang" : 2,
]));

	set("coor/x",-10);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}
