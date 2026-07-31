// Room: /d/jingcheng/mzh3.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m民宅[2;37;0m");
	set("long", @LONG
这户人家在长安城里也算比较富裕的了。男主人常年经商在外，妻
子在家主持家务。如同长安城大多数人家一样，屋里供着南海观音
和关王爷的神像。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"baih3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yahuan" : 2,
        __DIR__"npc/oldwoman" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
