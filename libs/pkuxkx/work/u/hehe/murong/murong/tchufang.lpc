//tchufang.c
//by hehe
//2003.1.15

inherit ROOM;

int serve();

void create()
{
        set("short", "厨房");
        set("long", @LONG
这里是听香水榭的厨房，专为阿朱姑娘提供别致的点心(serve)。慕容氏
先辈为皇室,所以即使是下人们的伙食，也极为精致。你可以在这里大快朵颐。
LONG
        );
        set("exits", ([
                "north" : __DIR__"tingxiang",
        ]));
          set("objects", ([
                   __DIR__"npc/laogu" : 1,
			]));
        setup();
        replace_program(ROOM);
}

