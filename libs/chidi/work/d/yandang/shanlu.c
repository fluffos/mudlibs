// Room: /d/yandang/shanlu.c

inherit ROOM;

void create()
{
	set("short", "朝阳嶂");
	set("long", @LONG
朝阳嶂全长四百余米,嶂壁曲突如缕,应物象形,风景如画.在嶂的
南侧,有一山洞(dong),洞旁有一岩形似马首,有鼻孔下垂,俗称马鼻岩.
其左侧,有五块相连的碑形大岩排列期间,称为'五碑岩'.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "dong" : "洞向东开张,状如半瓢,光洁明敞.洞顶有泉从洞口下洒,称'珠
箔泉',四周松柏蓊翳景色宜人.
",
]));
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shanlu2",
  "eastdown" : __DIR__"shanxia",
]));

	setup();
	replace_program(ROOM);
}
