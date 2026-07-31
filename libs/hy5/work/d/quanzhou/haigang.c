// Room: /d/quanzhou/haigang.c
// Date: May 7, 96   Jay
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "海港");
	set("long", @LONG
这里是出海的必经之地，泉州号称东方第一大港，是
海上丝绸之路的起点，舟船(chuan) 十分方便。
LONG );
	set("exits", ([
                "west" : __DIR__"zhongxin",
                "south" : "/d/hainan/tohaitan",

	]));
	set("item_desc", ([
                "chuan" : "一条大海船。出远海没这样的船可不行。\n",
	]));
	set("objects", ([
		__DIR__"npc/boy": 2,
		__DIR__"npc/girl": 1,
		"/d/mingjiao/npc/changjinpeng": 1,
//"/d/lingshedao/npc/yinli": 1,
		"quest/skills2/wunon/yu/yutan" : 3,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
//	replace_program(ROOM);
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
    message_vision("船夫升起帆，船就向东方航行。\n", ob);
		obj=present(ob->query("id")+" "+"wulin renwu", environment(ob));
        if (obj) obj->move (__DIR__"dahai");
    ob ->move(__DIR__"dahai") ;
    tell_object(ob, BLU "你在海上航行了很久很久.......\n" NOR ) ;
    call_out("tpenghu", 10 , ob,obj );
    return 1 ;
}
void tpenghu(object ob,object obj )
{
    tell_object(ob , "大船终于抵达了大海中一个大岛屿。你走下船来。\n" ) ;
    ob->move (__DIR__"penghu") ;
if (obj) obj->move(__DIR__"penghu");      
}
