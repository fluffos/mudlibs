// Room: /d/linzhi/inn01.c

inherit ROOM;

void create()
{
	set("short", "客店正厅");
	set("long", @LONG
这里是客店的正厅，里面整齐的摆放着桌椅。一些客人正在
饮酒吃饭。厅角柜台后面一个掌柜模样的人正在低头算帐，几个
小二正忙着沏茶倒水。东西两侧各有一个楼梯通向楼上。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"inn",
  "eastup" : __DIR__"inn03",
  "westup" : __DIR__"inn04",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/dawa" : 1,  	
]));
	setup();
	replace_program(ROOM);
}
