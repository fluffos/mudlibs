// Room: /d/xueting/wstreet1.c

inherit ROOM;

void create()
{
	set("short", "雪亭街道");
	set("long", @LONG
这里是雪亭镇广场西边的街道，往北是一间客栈，不过这个方
向没有入口。南边一间青瓦屋，门口清扫得乾乾净净，似是家私塾
模样，往西的街道十分宽敞，路上还有车马经过压出来的沟痕。
LONG
	);
        set("outdoors", " xueting ");
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"school",
	"west"  : __DIR__"wstreet2",
	"east"  : __DIR__"guangchang_sw",
]));
	set("no_clean_up", 0);
	set("outdoors","xueting");

	setup();
	replace_program(ROOM);
}
