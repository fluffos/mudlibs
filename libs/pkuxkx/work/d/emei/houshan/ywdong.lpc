// Room: /u/cuer/emei/ywdong.c

inherit ROOM;

void create()
{
	set("short", "药王洞");
	set("long", @LONG
这里就是峨嵋著名的药王洞了，一个很空旷的大洞
内，摆满了各种丹药和炉鼎，一个中年尼姑在指挥着众
人干活。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shandao4",
]));
	set("objects",([
       __DIR__"npc/jingci" : 1,
     ]));

	setup();
	replace_program(ROOM);
}
