//bye enter

inherit ROOM;

void create()
{
        set("short", "茶馆二楼");
        set("long", @LONG
到这里饮茶的人都是高雅之士,说话都不大声,相互交谈
着各方面的心得。推开窗户,眺目远望,成都美丽宜人的风光
尽收眼底,徐徐微风,吹拂着你的脸,再饮一口上等的"龙湖翠"
悠哉,妙哉!
LONG
        );

        set("exits", ([
                "down" : __DIR__"chaguan",
        ]));
        set("objects", ([
                __DIR__"obj/chair" : 3,
        ]));

        setup();
        replace_program(ROOM);
}


