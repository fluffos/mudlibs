// Room: /d/japan/haigang
inherit ROOM;
#include <ansi.h>
void create()
{
  set ("short", "海港");
  set ("long", @LONG
面对着波涛汹涌的日本海,这个海港显得十分平静,高大的双桅木船
挤满了这片海域,大多是各类的渔船,有许多式样奇特的船只,显然是从外
国而来的.有舟船可以通往高丽(chuan) 十分方便。向西方去有船直达泉州。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road",
  	"west"       : "/d/quanzhou/haigang",
]));
        set("objects", ([ /* sizeof() == 1 */
               __DIR__"npc/man" : 2,
            ]));
	set("item_desc", ([
                "chuan" : "一条大海船。出远海没这样的船可不行。\n",
	]));            
  set("outdoors", "japan");
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
    message_vision("船夫升起帆，船就向西北方航行。\n", ob);
obj=present(ob->query("id")+" "+"wulin renwu", environment(ob));
if (obj) obj->move("/d/taohua/dahai");
    ob ->move("/d/quanzhou/dahai") ;
    tell_object(ob, BLU "你在海上航行了很久很久.......\n" NOR ) ;
    call_out("tpenghu", 10 , ob,obj );
    return 1 ;
}
void tpenghu(object ob,object obj )
{
    tell_object(ob , "大船终于抵达了高丽。你走下船来。\n" ) ;
    ob->move ("/d/gaoli/gangkou") ;
if (obj) obj->move("/d/gaoli/gangkou");       
}

