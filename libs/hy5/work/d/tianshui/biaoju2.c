// Room: /d/xiaozhen/biaoju2.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "镖局正厅");
	set("long", @LONG
这里是日月镖局的正厅，一张太师椅摆在正中央，椅子上坐
着总镖头，手持烟袋杆正在闭目沉思。墙上挂着几幅字画和一把
宝剑，东面有一扇铁门。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"biaoju",
		"east" : __DIR__"biaoju3",
]));
	set("objects",([
	__DIR__"npc/ri_header" : 1,
]));
	setup();
}