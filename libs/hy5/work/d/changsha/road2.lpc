// /d/zhuojun/road2.c
// Room in 涿郡
// modify by yang

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。虽然现今天下大乱，但是四周还
是人来人往。挑担子的、行商的、赶着大车的马夫，熙熙攘攘，非常热
闹。不时还有两三骑快马从身边飞驰而过，扬起一路尘埃。马上的人个
个身着劲装，衣甲鲜明，有的还随身佩带着刀剑。看来都是些习武的江
湖人。道路两旁是整整齐齐的杨树林。
LONG );
	set("exits", ([
//		"north": "/d/yuyang/edao14",
		"west" : __DIR__"road3",
		"east" : __DIR__"road1",
//		"south" : "/d/xucheng/dadao1",
	]));
       set("objects",([
                __DIR__"npc/shang" : 1,
        ]));
	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



