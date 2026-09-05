// taohuadao/zoulang5 走廊
// Made By:pingpang
inherit ROOM;

void create()
{
         set("short", "走廊");
        set("long", @LONG
这是一条长廊,里面穿梭着来往的归云庄众。
LONG);
         set("exits", ([ /* sizeof() == 4 */
         "east" : __DIR__"fanting",
	 "west" : __DIR__"liangongfang",
	 "south": __DIR__"chaifang",
	 "north" : __DIR__"purendi",
                  ]));
	set("objects",([__DIR__"npc/zhuangpu":1,__DIR__"npc/kid":2,]));
	setup();
	replace_program(ROOM);
}
