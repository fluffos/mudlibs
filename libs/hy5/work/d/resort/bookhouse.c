 inherit ROOM;
void create()
{
        set("short", "藏书阁");
        set("long", @LONG
干干净净的书架上堆满了铁雪山庄的武功秘笈。这些秘笈是多情刀客铁少
和多情剑客雪蕊儿半生心血的结精。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"back_yard",
])); 
       set("objects", ([
                __DIR__"obj/book1" : 1,
                __DIR__"obj/book2" : 1,
                __DIR__"obj/book3" : 1,
                __DIR__"obj/book4" : 1,
                __DIR__"obj/book5" : 1,
                __DIR__"obj/book6" : 1,
                 __DIR__"obj/shelf" : 1, 
        ]) );
//      set("refresh_all_items", 1);
        set("coor/x",-1220);
        set("coor/y",70);
        set("coor/z",-10);
        setup();
}     
