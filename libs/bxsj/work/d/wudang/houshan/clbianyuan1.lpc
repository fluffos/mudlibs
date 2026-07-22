// Room : /d/wudang/clbinyuan1.c 丛林边缘
// By lius 99/8

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","丛林边缘");
        set("long", @LONG
前面已无路可寻，只有一片无边无垠的茂密丛林，风吹叶落“哗哗沙沙”
如歌似弦。弦歌声中，偶尔传来一两声丛林野兽凶残的呼啸，你怵然一惊，似
乎有些进退两难了。
LONG                           
        );
        set("outdoors", "武当");

        set("exits", ([               
            "northwest" : __DIR__"gudi",
        ]));
        setup();

}

void init()
{
         add_action("do_tou", ({"tou","zuan"}));
}

int do_tou(string arg)
{
         object me;
         me = this_player(); 
         if ( arg != "conglin" ) return 0;
  
         message_vision("$N哈哈一声朗笑，弹身投向丛林，钻了进去。\n", me);
         me->move(__DIR__"conglin"+(random(3)+1));
         tell_room(environment(me), me->name() + "从丛林边缘钻了进来。\n", ({ me }));
         return 1;
}

