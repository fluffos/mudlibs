// Room: /d/dali/duchang1.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月19日，北京时间：21时30分46秒。

inherit ROOM;

void create()
{
set("short", "赌坊");
	set("long", @LONG
有人说有人的地方就有赌场，看来一点也不错。这里是大理最大
的赌场，布置非常豪华,看样子这里的老板赚了不少。门口站着几个
标捍的打手，看来敢在这里捣乱的人不多。透过大门那厚厚的呢子布
不时传出侍女的娇笑声和庄家的吆喝声。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"duchang2",
  "east" : __DIR__"nandajie1",
]));

         set("objects", ([
                    __DIR__"npc/dashou" : 2,
        ]));
setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && this_player()->query("age")<18)
                return notify_fail("小毛孩子往这儿瞎凑合什么?!\n");
        return ::valid_leave(me, dir);
}
