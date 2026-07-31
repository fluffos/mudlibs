// Room: /d/xueting/work.c
// by pian

inherit ROOM;

void create()
{
	set("short", "工作站");
	set("long", @LONG
雪亭镇东北方是一个采矿场，这里是采矿场在村口的工作站。
一栋小小的木屋立在东边；旁边是一条上山的斜坡，路旁有一口井。
空地上停著几辆载满石料的车，往西是一条铺著大石板的路。一路
往山下延伸过去　
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
//	"northeast" : __DIR__"diggroom",
//"south" : "/d/oldpine/npath1",
	"west" : __DIR__"path5",
	"east" : __DIR__"palace_path1",
]));
	set("no_clean_up", 0);
	set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

	setup();
	replace_program(ROOM);
}
