// Room: /d/yandang/tianzhu.c

inherit ROOM;

void create()
{
	set("short", "天柱峰");
	set("long", @LONG
天柱峰高266米,色摆体圆,立地擎天,气势磅礴.峰北侧的摩崖'辟立
千仞'和'天不塌,赖以柱其间',形象而有生动地刻划出此峰的独特,从此
向下,就到卧龙谷.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 3 */
  "northdown" : __DIR__"shimeng",
  "south" : __DIR__"tieqiao4",
  "westdown" : __DIR__"wulonggu",
]));

	setup();
	replace_program(ROOM);
}
