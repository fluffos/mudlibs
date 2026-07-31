 inherit ROOM;
void create()
{
        set("short", "玉室");
        set("long", @LONG
推开一扇小门，眼前突然大亮，只见一道阳光从上面数十丈高处的壁
缝里照射进来。阳光照正之处，是一间玉室，看来当年建造者依着这道天
然光线，在山中度准位置，开凿而成。石室中有玉床、玉桌、玉椅，都雕
刻得甚是精致。
LONG
        );
        set("exits", ([ 
                "southeast" : __DIR__"palace4",
        ]));
        set("objects", ([
                __DIR__"obj/table" : 1,
                __DIR__"npc/baiyi" : 2,
        ]) );
        set("item_desc", ([
                "玉床": "一张白玉床。\n",
                "玉桌": "一张白玉桌(table)，桌上还放着几只碎瓷青花碗(Bowl)。\n",
                "玉椅": "一把白玉椅。\n",
                "bed": "一张白玉床。\n",
                "table": "一张白玉桌(table)，桌上还放着几只碎瓷青花碗(Bowl)。\n",
                "desk": "一张白玉桌(table)，桌上还放着几只碎瓷青花碗(Bowl)。\n",
                "chair": "一把白玉椅。\n",
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void reset()
{
   object *inv;
   object item1, item2, table;
   ::reset(); 
   table = present("table", this_object());
   inv = all_inventory(table);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/bowl");
      item1->move(table);
      item2 = new(__DIR__"obj/bowl");
      item2->move(table);
   }
}      
