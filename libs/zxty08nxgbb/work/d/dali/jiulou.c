// Room: /d/dali/jiulou.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月21日，北京时间：17时32分17秒。

inherit ROOM;

void create()
{
	set("short", "曼陀酒楼");
	set("long", @LONG
这是一间充满异国风情的酒楼，比起中原酒楼的精雅，这里显得
粗旷而实用，提供一些简单的食物和酒水。来往的都是一些来匆匆忙
忙的生意人，偶然也有几个武林中人在这里打尖，补充一下食物和水
就上路了。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mantuo" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dbdajie1",
]));

	setup();
}

