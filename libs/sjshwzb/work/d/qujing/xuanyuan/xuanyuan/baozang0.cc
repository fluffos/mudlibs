inherit ROOM;

void create ()
{
  set ("short", "古墓宝藏");
  set ("long", @LONG
黄金，白银，珍珠，玛瑙，夜明珠……
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"baozang",
  "south" : __DIR__"maze12",
]));  
  set("objects", ([
  ]));
  setup();
}

void init()
{
    object gold,book;
    gold = new ("/obj/money/gold");
//    gold->set_amount(500);
  //  gold->move("/d/xuanyuan/baozang0");             
    book= new("/d/obj/book/needlebook");
    book->move("/d/xuanyuan/baozang0");
}                                                                                         
