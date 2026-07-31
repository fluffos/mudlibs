 inherit ROOM;
void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
一条看起来很不起眼的土路，但在它千年的历史中，曾经吞食了
无数人的性命，将他们的白骨吐在道路两旁。它看起来是那么的不起
眼，似乎一个三岁的孩子都可以将其踩在脚下。
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"sichou4",
  "southeast" : __DIR__"heimiao",
]));
        set("objects", ([
        __DIR__"npc/police1" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1010);
        set("coor/y",2010);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
