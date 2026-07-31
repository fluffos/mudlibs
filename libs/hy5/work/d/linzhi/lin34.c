// Room: /d/linzhi/lin34.c

inherit ROOM;

void create()
{
	set("short", "德兴藤网桥");
	set("long", @LONG
你走在德兴藤网桥上，桥随着人的重力和河风吹送，不时地
摇晃着，而且左右晃悠幅度极大。猛然你脚下一滑，一只脚从网
格中滑空，你急忙双手死死拉住藤网，借力慢慢把脚收了上来。
你不禁出了一身冷汗。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin33",
  "west" : __DIR__"lin35",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3400);
	setup();
	replace_program(ROOM);
}
