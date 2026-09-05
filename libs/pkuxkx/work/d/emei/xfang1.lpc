// Room: /u/cuer/emei/xfang1.c

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
这里是一间普普通通的厢房，是峨嵋派四代俗家弟子
贝锦仪的休息室。这里房间宽敞明亮，东西不多，很朴素，
但一切都是有条有理，一尘不染。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dlang1",
]));
	set("objects",([
          __DIR__"npc/bjyi" : 1,
              ]));

	setup();
	replace_program(ROOM);
}
