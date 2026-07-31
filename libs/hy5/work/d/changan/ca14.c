// Room: /u/wsl/changan/ca14.c
// This is a room made by Wsl.

inherit ROOM;

void create()
{
	set("short", "百草堂");
	set("long", @LONG
一进门，你就看到对门的墙上挂着“百草堂”三个字的镶金牌匾
。旁边放着一个熬药用的炉子，四周散发着浓郁的药味，右边挂了一
个牌子（paizi）。
LONG
);
	set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "本店药品齐全，决不二价。
药品价目如下：
金创药：        五十两白银
养精丹：        二十两白银
另有奇药可定购。
",
]));
        set("objects", ([
           __DIR__"npc/huoji" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ca12",
]));

	setup();
	replace_program(ROOM);
}
