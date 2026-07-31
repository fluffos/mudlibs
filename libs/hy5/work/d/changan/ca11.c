// Room: /d/changan/ca11.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
这里是长安守军驻扎地，一对官兵正在操练，两旁放置这一些剑
，长枪，刀之类的武器。你最好赶紧走开，不然被随便安个罪名关进
大牢可不是好玩的。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ca9",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/weibing" : 4,
]));

	setup();
	replace_program(ROOM);
}
