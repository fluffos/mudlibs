 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山洞秘道");
        set("long", @LONG
一过冰河，外面喧嚣的声音在这里再也不闻丝毫，洞内没有照明
的东西，但透过洞口的光线却足以使你看清附近的情况。洞很深，似
乎是在天然的基础上加人工建成的，再向里黑暗笼罩了一切，你什么
都看不到了。
LONG
        );
        set("exits", ([ 
          "north" : __DIR__"midao2",
          "west" : "/d/laowu/street4"
        ]));
        set("coor/x",100);
        set("coor/y",12050);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
