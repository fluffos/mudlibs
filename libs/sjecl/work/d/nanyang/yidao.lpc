// Room: /d/nanyang/yidao.c
// Lklv Modify 2001.10.10

inherit ROOM;
void create()
{
	set("short", "驿道");
	set("long", @LONG
这是南阳府境内的一条驿道。路上人来人往，尘土飞扬。不时有两三骑快
马飞驰而过，扬起一路尘埃。马上的人个个身着劲装，衣甲鲜明，有的还随身
佩带着刀剑。看来都是些习武的江湖人。道路两旁是整整齐齐的杨树林。从这
里向北一直走就是南阳城了。
LONG
	);
	set("outdoors", "南阳");
	set("exits", ([
	        "south" : "/d/xiangyang/henanroad2",
		"north" : __DIR__"yidao1",
		"east" : __DIR__"xiaolu2",
	]));
        set("objects", ([
                NPC_D("poorman") : 1,
	]));
	setup();
}
