 inherit ROOM;
void create()
{
        set("short", "侧厅");
        set("long", @LONG
屋子里排满了古松书架，松木散发出一阵阵清香，书架的间隔有大有
小，上面摆满了各色各样的书册，大大小小的瓶子，有的是玉，有的是石，
也有的是以各种不同的木头雕成的。这些东西摆满四壁，骤看似乎有些零
乱，再看来却又非常典雅，又别致，就算是个最俗的人，走进这间屋子来，
俗气都会被洗去几分。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"palace3",
                                ]));
        set("objects", ([
                __DIR__"obj/shelf" : 1,
                __DIR__"obj/vase" : 1,
                
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
   object item1, item2, table,vase;
   ::reset(); 
   table = present("shelf", this_object());
   inv = all_inventory(table);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/yawnbook");
      item1->move(table);
   }
   vase = present("vase", this_object());
   inv = all_inventory(vase);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/senyao");
      item1->move(vase);
      item1 = new(__DIR__"obj/keeyao");
      item1->move(vase);
      item1 = new(__DIR__"obj/ginyao");
      item1->move(vase);
   }
} 
