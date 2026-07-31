//bye enter

inherit ROOM;

void create()
{
        set("short", "石拱桥");
        set("long",@LONG
这里充分地显示着天府之国那种独特仅有的风格，园拱
形的小桥横跨纵贯成都的府南河。桥下的流水被浮萍染成
爱人的翠绿。偶尔一两只轻舟划过，带动着河边的莲藕随
波而动。往西就可以到南大街了。 
LONG
        );

        set("outdoors", "/d/chengdu");

        set("exits", ([
                "west" : __DIR__"nanjie",
                "northeast" : __DIR__"funanhe3",
            ]));
        setup();
        replace_program(ROOM);       
}


