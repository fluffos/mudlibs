// Room: /u/xiaozhen/jiyuan.c

inherit ROOM;

void create()
{
	set("short", "畅春园");
	set("long", @LONG
这里是方圆百里唯一的一家妓院，屋里到处张灯结彩，香气
扑鼻，几位妖娆的姑娘坐在旁边，不时的冲你嬉笑。这里虽然没
有南方娇娃，但北地胭脂也别有丰韵，楼上不时地传来阵阵打情
骂俏的声音。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"jiyuan2",
  "east" : __DIR__"nroad1",
]));
	set("no_clean_up", 0);

	set("objects",([
	__DIR__"npc/guinu" : 1,
]));

	
	setup();
}

int valid_leave(object ob,string dir)
{
	string day_night;
	int time;


	return ::valid_leave(ob,dir);
}