// Room: /u/diabio/feitian/feitian/haigang.c
inherit ROOM;

void create()
{
  set ("short", "海港");
  set ("long", @LONG
这里是京都唯一通往外地的海港,不过眼见之处是一片废墟.
这是幕府的部队为了能安全撤出而放的火.不过那边似乎有船
可以走，船上的人正在大声吆喝~~~要去东土的快点上船啊.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guangchang",
]));
  set("outdoors", "feitian");
  setup();
}
void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob ,room;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "你要 上哪里去？\n" ) ;
         return 1 ;
       }
    if (!room=find_object("/d/taohua/dahai"))
    room=load_object("/d/taohua/dahai");
    ob = this_player () ;
    message_vision("船老大一见有人上船，忙叫了一声：开船喽！\n", ob);
    message_vision("船夫升起帆，船就向东土行去。\n", ob);
    ob ->move(room) ;
    tell_object(ob, BLU "你在海上航行了很久很久.......\n" NOR ) ;
    call_out("rfeitian", 10 , ob );
    return 1 ;
}

void rfeitian( object ob )
{
    if (!ob || ob->is_ghost()) return;
  tell_object(ob , "船航行了这么久终于抵达了一个到达了东土泉洲。\n" ) ;
  ob->move ("/d/quanzhou/haigang.c") ;
}
