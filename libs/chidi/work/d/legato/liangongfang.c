inherit ROOM;

void create()
{
      set("short", "练功房");
      set("long", @LONG
这里是山庄的练功房，里面暗淡无光，不知有多大，只可见几个山庄
陪练弟子站在你面前...
LONG
      );

      set("objects", ([
               "/d/yandang/boj/lingzhi": 1,
      ]));

      set("exits", ([
            "west"   : __DIR__"bank",
      ]));

      setup();
      replace_program(ROOM);
}

