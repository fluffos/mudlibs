 inherit ROOM;
void create()
{
        set("short", "城西小路");
        set("long", @LONG
一条小路弯弯曲曲向南延伸。路的旁边是风云城的护城河，河的另外一边就
是高大的风云城城墙了。从这里可以看到城墙上值勤的士兵在站岗。河堤上长满
了绿草。微风拂来，一股的泥土的气息。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" :__DIR__"fywest",
  "southeast" : __DIR__"sroad2",
]));
        set("outdoors", "fengyun");
            replace_program(ROOM);
        set("coor/x",-160);
        set("coor/y",-50);
        set("coor/z",0);
        setup();
}   
