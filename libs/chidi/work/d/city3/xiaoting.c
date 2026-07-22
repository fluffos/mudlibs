//bye enter

inherit ROOM;

void create()
{
        set("short", "小亭");
        set("long",@LONG
这里是个修筑精致的小亭，游人们到了这里，总喜欢进来
乘凉，这里凉风习习，且可抚览府河美景，不亦快哉！
LONG
        );

        set("exits", ([
                "southwest" : __DIR__"funanhe2",
            ]));
        setup();
        replace_program(ROOM);       
}


