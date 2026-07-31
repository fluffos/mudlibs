// baling/edao1
// Room in 巴陵
inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
你顺着峡谷艰难的走着，来到一片杨树林，茂密树林把阳光都遮住
了，一条弯弯折折的小路不知通向哪里。
LONG);

	set("exits", ([
                "west" : __DIR__"xiagu",
	]));

 	set("outdoors", "baling");
        set("objects", ([
		__DIR__"npc/she" : 2
	]));
	setup();
	replace_program(ROOM);
}


