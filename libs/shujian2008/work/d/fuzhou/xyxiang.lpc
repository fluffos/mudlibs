// Room: /d/fuzhou/xyxiang.c 向阳巷
// Lklv 2001.9.6
inherit ROOM;

void create()
{
	set("short", "向阳巷");
	set("long", @LONG
这是一条小巷，没有什么行人，巷口有几个穷汉在晒太阳。附近的居民不
多，大多是没有什么钱的穷人在这里住。前一阵子海港上来了一群乞丐，在那
里成立了丐帮的福州分舵，所以附近的乞丐好象也比以前多了起来。北面是一
座白色小桥，东面是一个荒废的宅院。立在门口的石碑已经破损，仔细看可以
看见上面刻有“费园”两个字。人们都把这个宅院叫做废园。
LONG
	);

	set("exits", ([
        	"south" : __DIR__"xyxiang2",
        	"east" : __DIR__"feiyuan",
                "north" : __DIR__"shiqiao",
	]));

	set("objects", ([
                __DIR__"npc/poorman":2,
	]));

	set("outdoors", "福州");
	setup();
}
