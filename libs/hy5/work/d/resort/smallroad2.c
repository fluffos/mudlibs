 inherit ROOM;
void create()
{
        set("short", "羊肠小道");
        set("long", @LONG
一条被在恰克卜里山中砍柴的樵夫踏出的小道弯弯曲曲的向北面的
山幽伸展。道旁的茅草高达五尺，遮住了天光。山幽中的一切都显的阴
森幽暗。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"smallroad",
  "north" : __DIR__"smallroad3",
]));
        set("outdoors", "resort"); 
        set("coor/x",-1190);
        set("coor/y",10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
