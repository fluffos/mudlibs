// Room: /d/hainan/haibian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "海边");
	set("long", @LONG
眼前就是一望无际的大海,身后是陡峭壁立的石壁.不远处的海水
中,一块巨石特别引人注目,上面刻了'天涯海角'四字.
有船(chuan) 可以去安南。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shatan",
]));
	set("item_desc", ([
                "chuan" : "一条大海船。(enteran)可以到安南.出远海没这样的船可不行。\n",
	]));
  set("valid_startroom", 1);
	set("objects", ([ /* sizeof() == 1 */
"quest/skills2/wunon/yu/yutan" : 5,      
  __DIR__"npc/yuwen.c" : 1,
]));

	setup();
//	replace_program(ROOM);
}

void init()
{
    add_action("do_enter", "enteran");
}

int do_enter (string arg)
{
    object ob ;
    string dir;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
         return 1 ;
       }
//    tell_object(this_player() , "开船了？\n" ) ;
    ob = this_player();
    message_vision("船夫一见有人上船，忙叫了一声：开船喽！\n", ob);
    message_vision("船夫升起帆，船就向西南方航行。\n", ob);
    ob ->move("/d/quanzhou/dahai") ;
    tell_object(ob, BLU "你在海上航行了很久很久.......\n" NOR ) ;
    call_out("tpenghu", 10 , ob );
    return 1 ;
}
void tpenghu(object ob )
{
    tell_object(ob , "大船终于抵达了安南。你走下船来。\n" ) ;
    ob->move ("/d/annan/matou") ;
}

