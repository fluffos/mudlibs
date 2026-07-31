// Room: /d/hainan/outtree.c

inherit ROOM;

void create()
{
	set("short", "桃花林外");
	set("long", @LONG
眼前是一片桃花林,粉色的花瓣和翠绿的树叶使人浮想联翩,斑驳的
树皮,虬曲的树枝,无不显示出这片林子的年久,在林边的乱草丛中,你发现
一块快腐烂了的木板.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("item_desc", ([ /* sizeof() == 1 */
  "木板" : "从其腐烂程度来看,已经躺在这好久了,上面依稀能看到用指力划出
的几个字'外人止步,禁止进入',在另一面,刻着'谢绝参观',指力雄劲,显
然与前面柔婉的笔法不同.
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"dtotree",
  "north" : __DIR__"taotree1",
]));

	setup();
	replace_program(ROOM);
}
