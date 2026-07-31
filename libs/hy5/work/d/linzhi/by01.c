// Room: /d/linzhi/by01.c

inherit ROOM;

void create()
{
	set("short", "镇东斜街");
	set("long", @LONG
这里是八一镇镇东斜街，在街北面的帐房是一家八一当铺，南
面帐房是一家水果店。街面上行人不多，只有几个小孩儿在一边
玩耍。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"bye",
  "west" : __DIR__"by02",
  "south" : __DIR__"fruitshop",
  "north" : __DIR__"silkshop",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/girl" : 2,  	
]));

        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
