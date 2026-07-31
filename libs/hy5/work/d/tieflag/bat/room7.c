 inherit ROOM;
void create()
{
        object con,item;
        set("short", "储藏室");
        set("long", @LONG
这是一间储藏室，乱七八糟的东西堆成了山。各种箱子柜子里堆满了杂物。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room6",
  "east" :__DIR__"dating",
]));
    set("objects", ([
      __DIR__"obj/woodcase": 1,
      __DIR__"obj/qidrug" : 1,
  ]) );
      set("coor/x",3260);
        set("coor/y",30);
        set("coor/z",-30);
        setup();
      con = present("woodcase",this_object());
      item = present("bat drug",this_object());
      item->set_amount(3);
      item->move(con);
}  
