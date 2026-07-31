 inherit ROOM;
void create()
{
        set("short", "薛记老号");
        set("long", @LONG
这包子铺已经在这里几十年了，自开张后就没换过门面，布置还是那么简陋，
屋子里面仅有的几张方桌和长凳都已经看不出原来的颜色。肮脏而残破的碗筷零乱
地散落在桌面上，墙角里随便扔着几支脏稀稀的筷子，上面已结满蜘蛛网。几只苍
蝇盲目地飞来飞去，为这死气沉沉的店堂添了几分生气。
LONG
        );
        set("exits", ([
                "east" : __DIR__"nwind5",
        ]));
        set("objects", ([
                __DIR__"npc/lifeseller": 1,
        ]) );
        set("coor/x",-10);
        set("coor/y",50);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}
