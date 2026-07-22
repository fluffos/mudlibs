#pragma save_binary
// Room: /d/green/station1.c

inherit ROOM;

void create()
{
	set("coor",({80,4870,10}));
	set("short", "工作站");
	set("long",
"这里是采石场的工作站，几间矮小的房舍延著山壁建造。靠南的\n"
"山边有一间马房，旁边还堆著山一般的乾草饲料，几辆运输用的\n"
"车子停在旁边。往北看去是采石场的空地往南是一条由石板铺成\n"
"的小斜坡，通往村前的工作站。西边不远处有一栋看来相当特别\n"
"的房舍。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/green/field1",
  "southwest" : "/d/green/work1",
]));
	set("outdoors", "green");
	set("objects", ([
	"/d/green/npc/worker2" :2,
	]) );

	setup();
	replace_program(ROOM);
}
