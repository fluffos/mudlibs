// Room: /chengdu/qingshidadao4.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "青石大道");
	set("long", @LONG
这里已是成都地界了。一条青石板铺成的路，比较宽敞。
道路两旁种的是整整齐齐的柳树。微风吹过沙沙做响。由于
这儿靠近成都城，来往的行人倒也不少。向西望去，可隐约
见到成都城的城墙。青石路东西延伸，东边通往。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "west" : __DIR__"gangdao",
                "east" : __DIR__"qingshidadao3",
	]));

	setup();
	replace_program(ROOM);
}

