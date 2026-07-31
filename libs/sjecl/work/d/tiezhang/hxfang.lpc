//hxfang.c 后厢房

inherit ROOM;
void create()
{
	set("short", "后厢房");
	set("long", @LONG
这是大厅后面的一个小房间，虽然也是岩石砌成，但布置的非常舒适。四
壁用挂毯遮住，不露一点石壁的痕迹。屋内转圈摆放了一些椅子，上面铺着厚
厚的软垫，坐上去一定很舒适。这里是帮主处理帮中日常事务的地方。后面通
向后花院。
LONG
	);
	set("exits", ([
		"north" : __DIR__"hhyuan-1",
		"south" : __DIR__"wztang",
	]));
	set("objects", ([
		CLASS_D("tiezhang/qqren") : 1,
		__DIR__"npc/yahuan" : 1,
	]));
	setup();
}
