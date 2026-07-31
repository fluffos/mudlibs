//      shanmen.c 雪山寺山门
inherit ROOM;
void create()
{
	set("short", "雪山寺山门");
	set("long", @LONG
这里是大轮寺的山门，门前是络绎不绝的进香朝圣的
信徒，有的甚至来自乌丝藏西南的波丝。山门(gate)前站
了个手持法器的葛伦布在维持秩序，东方是一条青石板铺
成的山路。
LONG );
	set("outdoors", "xueshan");
	set("exits", ([
		"north"    : __DIR__"guangchang",
		"eastdown" : "/d/xuedao/nroad4",
	]));
	set("item_desc", ([
		"【大门】" : "两扇厚厚的铜色大门，非合数人之力，是难以推动的。\n",
	]));
	set("objects", ([
		CLASS_D("xueshan")+"/gelunbu": 1,
		"/d/wudang/npc/guest": 2,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object glb;

	if (dir == "north" &&
	    objectp(glb = present("ge lunbu", this_object())))
	{
		return glb->permit_pass(me, dir);
	}

	return ::valid_leave(me, dir);
}

