// baling/edao1
// Room in 巴陵
inherit ROOM;

void create()
{
	set("short", "杨树林");
	set("long", @LONG
这里是一片杨树林中开辟的一空地。由于游人稀少，这里显得十分
幽静，高大的杨树挡住了刺眼的阳光，为人们提供了一个天然的休息场
所。
LONG
	);

	set("exits", ([
                "northup" : __DIR__"shanyanan",
                "south" : __DIR__"shulin1",
	]));

 
        set("objects", ([
		__DIR__"npc/she" : 4
	]));
	set("outdoors", "yuyang");
	setup();
	replace_program(ROOM);
}


