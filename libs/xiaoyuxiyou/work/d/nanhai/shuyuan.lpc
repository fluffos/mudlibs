//Cracked by Roath
// Room: /d/nanhai/shuyuan
inherit ROOM;

void create_book()
{
	object book;
	remove_call_out("create_book");
	if( !present("book",this_object()) )
	{
		book = new("/d/obj/book/san");
		book->move(this_object());
	}
	if( !present("jingang",this_object()) )
	{
		book = new("/d/obj/book/jingang");
		book->move(this_object());
	}
	if( !present("staff book",this_object()) )
	{
		book = new("/d/obj/book/staffbook");
		book->move(this_object());
	}
	call_out("create_book",1800);
}

void create ()
{
  set ("short", "书院");
  set ("long", @LONG

这里就是普陀山书院，书架上摆着无数书籍。普陀山门人弟子
中有来提高基本读书识字的，更多的是来钻研佛经修练佛法的，
以期早日修得正果。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zoulang",
]));
  set("objects", ([ /* sizeof() == 3 */
 	__DIR__"npc/shami" : 1,
  ]));
  set("light_up", 1);
  setup();
  remove_call_out("create_book");
  call_out("create_book",5);
}