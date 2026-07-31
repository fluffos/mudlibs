#include <ansi.h>

inherit ROOM;

void home( object ob,object obj ) ;

void create()
{
    set("short", "海滩");
    set("long", @LONG
这里就是神龙岛了。南边是一望无际的大海；往北则是一片灌木林。
岛上的空气似乎又热又闷, 咸湿的海风中带着一股腥臭, 又夹杂了一缕奇
特的花香, 闻起来十分怪异。海边泊着一艘大船(chuan)。
LONG );

    set("item_desc", ([
        "chuan" : "这是神龙岛对外联系的大船。岛上的客人或弟子只要\n"
                  "上船(enter)就可以回中原。\n",
    ]));
    set("exits",([
        "south" :__DIR__"treen1",
        "north" :__DIR__"lin1",
        "east" :"/quest/menpaijob/shenlong/dian",
    ]));
	set("objects", ([
		"quest/skills2/wunon/yu/yutan" : 3,
	])); 

    set("outdoors", "shenlong");
    setup();
}

void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob,obj ;
    string dir;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    message_vision("船夫一见有人上船，忙叫了一声：开船喽！\n", ob);
    message_vision("船夫升起帆，船就向西方航行。\n", ob);
obj=present(ob->query("id")+" "+"wulin renwu", environment(ob));
if (obj) obj->move(__DIR__"dahai");
    ob ->move(__DIR__"dahai") ;
    tell_object(ob, BLU "你在海上航行了很久很久.......\n" NOR ) ;
    call_out("home", 10 , ob,obj );
    return 1 ;
}
void home( object ob,object obj )
{
  tell_object(ob , "大船终于抵达了中原的一个繁华城市。你走下船来。\n" ) ;
  if (ob) ob->move ("/d/tanggu/gangkou");
  if (obj) obj->move("/d/tanggu/gangkou");
}