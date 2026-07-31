// Room: /d/dali/huanggong10.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：21时27分26秒。

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
这里是御书房前的一大片广场。皇帝散朝后经常要来书房看
书，因此这里的侍卫戒备禁严，一点也不敢大意。
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huanggong5",
  "eastup" : __DIR__"huanggong12",
]));

	setup();
}

