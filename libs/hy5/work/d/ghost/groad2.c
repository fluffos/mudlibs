 inherit ROOM;
void create()
{
        set("short", "弯曲小路");
        set("long", @LONG
路的两旁，有各式各样的树木，还有些不知名的花草。在阳光普
照的时候，这山谷一定很美。可是这山谷里是不是也有阳光普照的时
候？
LONG
        );
        set("exits", ([
                "northwest" : __DIR__"groad1",
                "northeast" : __DIR__"groad3",
        ]));
        set("coor/x",-1150);
        set("coor/y",-110);
        set("coor/z",-20);
        setup();
replace_program(ROOM); 
}      
