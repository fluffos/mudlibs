// /d/dali/xiaolu
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "青石路" );
        set("long", @LONG
一条青石大道，青石铺成，平坦宽阔，抬头向东一看，前面的城门
清晰可见。

LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"dxiaolu1", 
                "east"  :"/d/kunming/xiaoximen",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
