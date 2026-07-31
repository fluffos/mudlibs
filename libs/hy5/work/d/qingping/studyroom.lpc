 //XXDER
inherit ROOM;
void create()
{
        set("short", "书房");
        set("long", @LONG
这里就是白三空的书房，里面足足两柜的书，白三空武功修为已臻化境，
没想道于文一道，也如此精深，室内墙上挂了几幅字画，画不知出自何人的手
笔，那几幅字却似白三空的亲笔。屋内靠墙处有一张红木书桌，书桌前摆了一
张椅子。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
      "south" : __DIR__"garden",
   ])); 
   set("item_desc", ([
      "writing": "只见字迹刚中带柔，宛如行云流水一气呵成。\n",
      "字": "只见字迹刚中带柔，宛如行云流水一气呵成。\n",
   ]) ); 
   set("objects", ([
      __DIR__"obj/desk": 1,
      __DIR__"obj/wall": 1,
      __DIR__"npc/qingm" : 1,
   ]) ); 
        set("coor/x",170);
        set("coor/y",2010);
        set("coor/z",0);
        setup();
}
void reset()
{
   object *inv;
   object item1, item2, desk, wall;
   ::reset(); 
   desk = present("desk", this_object());
   wall = present("wall", this_object());
   inv = all_inventory(desk);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/letter");
      item1->move(desk);
      item2 = new(__DIR__"obj/bag");
      item2->move(desk);
   }
   inv = all_inventory(wall);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/kite");
      item1->move(wall);
   }
}      
