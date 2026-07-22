 //XXDER
inherit ROOM;
void create()
{
        set("short", "寝室");
        set("long", @LONG
这里是方宝玉的住所，因为白家上下只此一脉，所以分外宠爱，屋内陈设
皆是上上之选，更有书柜一个，内藏诸子百家，此子年不过十二，可读书如此
之多，与一般孩童迥异，日后必成大器。书柜旁是一扇窗子，窗台上摆了一个
白玉花瓶。
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
      "down" : __DIR__"xting",
   ])); 
   set("objects", ([
      __DIR__"obj/bookcase": 1,
      __DIR__"obj/vase": 1,
   ]) );
   set("coor/x",170);
        set("coor/y",1990);
        set("coor/z",10);
        setup();
        
} 
void reset()
{
   object *inv;
   object item1, item2, bookcase;
   ::reset(); 
   bookcase = present("bookcase", this_object());
   inv = all_inventory(bookcase);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/books");
      item1->move(bookcase);
      item2 = new(__DIR__"obj/books");
      item2->move(bookcase);
   }
}    
