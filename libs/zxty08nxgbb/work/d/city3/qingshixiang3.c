//bye enter

inherit ROOM;

void create()
{
        set("short", "青石巷头");
        set("long",@LONG
你来到青石巷的尽头，往北就是成都大户温家的府邸，听
说那里的人不怎么喜欢生人打扰，你还是快点离开吧。
LONG
        );

        set("exits", ([
                "west" : __DIR__"qingshixiang2",
                "north" : __DIR__"wenzai/gate",
            ]));
        setup();
        replace_program(ROOM);       
}


