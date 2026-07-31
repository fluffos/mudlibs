// /d/dali/xiaolu2
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "青石路" );
        set("long", @LONG
一条青石大道，青石铺成，平坦宽阔，往西去，可以到达大理
城，来往与大理和昆明的人都得从这条路通过。

LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "east" : __DIR__"dxiaolu", 
                "west"  :__DIR__"changting",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
