 inherit ROOM;
void create()
{
        set("short", "没有名字的地方");
        set("long", @LONG
这里是个很奇怪的地方。在残秋，这地方还是温暖如春；在深夜，
这个地方还是光亮如昼。这里有酒，却不是酒楼；有赌，却不是赌场；
有随时可以陪你做任何事的女人，却也不是妓院。这地方根本没有名
字，却是附近几百里最有名的地方。大厅中摆着十八张桌子，无论你
选择哪一张桌子坐下来，你都可以享受到最好的酒菜。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"beimen",
  "south" : __DIR__"bazha",
]));
        set("objects", ([
//        __DIR__"npc/hong" : 1,
        __DIR__"npc/hua" : 1,
                        ]) );
     
        
        set("coor/x",-1120);
        set("coor/y",2100);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
