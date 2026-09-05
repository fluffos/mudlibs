//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;
int do_pull(string arg);
void create()
{
			set("short", "崖顶");
  		set("long", @LONG
这里是老秃峡的峡顶。到处土匪遍布。这里有一个机关（jiguan）和几个麻
袋（madai）。
LONG
        );
			set("exits", ([ 
  			"down" : __DIR__"laotuxia2",	
   		]));
        set("item_desc", ([
        "jiguan" : "这是控制峡谷巨石的机关，可以轻松的拉（pull）起巨石。\n",
        ]));
			set("objects",([
//     __DIR__"obj/madai":2,
//     __DIR__"npc/tufei":12,
        ]));
      set("outdoors", "tiezhang");
			setup();

}
void init()
{
  		add_action("do_jump", "jump");
}

int do_pull(string arg)
{
			object me=this_player();
			if(arg !="jiguan") return 0;
//以下是开启机关的代码
			return 1;
}
