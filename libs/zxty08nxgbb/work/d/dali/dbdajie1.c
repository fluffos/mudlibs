// Room: /d/dali/dbdajie1.c
// Data: 一天(not)
// Time: 公元：1999年4月21日，北京时间：17时46分27秒。

inherit ROOM;

void create()
{
	set("short", "朝阳路");
	set("long", @LONG
这里是大理皇宫东面的朝阳路。由于邻近皇宫的缘故这里显得热
闹而有整然。大街由大理特产的大理石铺成，周围店辅林立，各地的
商人，游客络绎不绝，卖买声此起彼落。好一片繁华的景象。
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"dbdajie2",
  "west" : __DIR__"jiulou.c",
  "east" : __DIR__"qianzhuang",
  "south" : __DIR__"dongdajie1",
]));

        set("objects", ([
                                __DIR__"npc/jieba" : 1,
        ]));

	setup();
}
