// Room: /u/xiaozhen/yidao2.c

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
这是一条尘土飞扬的大驿道，路上人来人往。挑担子的、行
商的、赶着大车的马夫，络绎不绝，路边还有一些小商贩在叫卖，
非常热闹。不时还有两三骑快马边飞驰而过，扬起一路尘埃。南
面是天水镇，往北一直走就是边关大营。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yidao3",
  "south" : __DIR__"yidao1",
]));
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	set("objects",([
	__DIR__"npc/fruit_seller" : 1,
]));
	setup();
	replace_program(ROOM);
}
