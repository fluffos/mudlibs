// sanjie tianyifu.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "禁地");
  set ("long", @LONG
	
这里突然一亮，看见在石壁上有个很大的八卦，八卦中还有
一个小洞口(hole)，不知道放什么东西进去，看来这的确有
机关。
LONG);
  set("item_desc", ([
  "hole" : "洞中似乎是个机关，一个八卦般大小，能放(insert)下什么东西。\n",
]));
  set("exits", ([ 
  "southwest" : __DIR__"tianyidong4",
  "southeast" : __DIR__"tianyidong5",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/qiuxuke": 1 ]) );
  setup();
}
void init()
{
	add_action("do_insert", "insert");
}
int do_insert(string arg)
{
        object enterroom, ob, me;
	me=this_player();
	if( !arg )
		return notify_fail("你要放什么东西？\n");

        if( !arg || arg!="fuxi bagua" || !(ob=present(arg, me)) || ob->query("name")!=HIC"伏曦八卦"NOR )
		return notify_fail("似乎孔中放不下这个东西。\n");


        if( !(enterroom = find_object(__DIR__"tianyifu")) )
            enterroom = load_object(__DIR__"tianyifu");
        if( enterroom = find_object(__DIR__"tianyifu") ) 
        {
                set("exits/enter", __DIR__"tianyifu");
                message_vision("$N将$n塞入小孔，只听喀喀几声，八卦图发生了变化，露出向下一个通口。\n", me, ob);
                message("vision", "大石被人从外推开了。。\n", enterroom );
		enterroom->set("exits/out", __DIR__"tianyidong6");
		destruct(ob);
        call_out("close_down", 10);
	}
	return 1;
}

void close_down()
{
        object enterroom;

        message("vision", "墙壁轰地又回到原位。\n", this_object() );
        if( enterroom= find_object(__DIR__"tianyifu")) {
        message("vision", "墙壁轰地又回到原位。\n", enterroom);
        enterroom->delete("exits/out");
        }

        delete("exits/enter");

}