 inherit ROOM;
void create()
{
        set("short", "密道");
        set("long", @LONG
道边高达丈许的灌木丛形成了天然的屏障，再加上地势渐低，
无人可以猜到此路倒底通向何方。前面居然出现了一个山洞。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"smallroad4",
  "west" : __DIR__"cave_tunnel",
]));
        set("outdoors", "resort"); 
        set("coor/x",-1200);
        set("coor/y",30);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}        
