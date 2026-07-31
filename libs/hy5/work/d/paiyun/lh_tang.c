// Room: /d/paiyun/lh_tang.c

inherit ROOM;

void create()
{
	set("short", "龙虎堂");
	set("long", @LONG
龙虎堂是排云寨的军机要地，大堂尽头是一块屏风，屏风上
一条金蛟龙张牙舞爪，屏风前正中一把金交椅，椅上一张吊额猛
虎皮，椅前一大张厚茸地毯，两边是十二张金交椅，靠墙边放的
是兵器架，一十八般兵器样样俱全，整个龙虎堂内一派肃杀的氛
围。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dayuan",
]));

	set("no_steal",1);
	set("objects",([
	__DIR__"npc/liguang" : 1,
	__DIR__"npc/fei_tou" : 2,
]));

	setup();
	replace_program(ROOM);
}
