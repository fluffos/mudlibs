#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
这里是一个不大的山洞,借着外面透进来的阳光,你发现
在山洞的里面有一个石床，床上有一具骷髅,在骷髅的
旁边有一口铁锅,墙边放着一把锄头,也不知道有什么用。
 

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "out" : "/d/yandang/shanlu",
]));
        setup();
       set("item_desc", (  [
      "骷髅": "你远远的望着骷髅，发现这个骷髅已经死去很久了，很可怜的样子。\n",
      "石床": "在石床上只有一具骷髅.",
      "锄头": "这把锄头可以挖坑埋东西用。",
        ]) );

}
void init()
{
        add_action("do_mai", "mai");
        add_action("do_pick","pick");
        add_action("do_look","look");
        
}

int do_mai(string arg)
{
        object  me, lu;

        if( arg != "骷髅") 
                return notify_fail("你要埋什么？\n");
        me = this_player();
        if(me->query_temp("marks/mai"))

  return notify_fail("哪有那么多尸体让你埋。\n");
 

        me->set_temp("marks/mai", 1);
        message_vision("\n$N在地上挖了个坑，把骷髅埋了起来。\n", me);
        return 1;
}



int do_look(string arg)
{
        object  me, lu;

        if( arg != "石床") 
                return notify_fail("你要3看什么？\n");
        me = this_player();
        if(!me->query_temp("marks/mai"))

  return notify_fail("床上有一具骷髅。\n");
 

        message_vision("\n$N发现在石床上有一本从骷髅身上掉下来的破书。\n", me);
        return 1;
}

int do_pick(string arg)
{
       object me,lu;
         me = this_player();

       if(arg != "破书")
                 return notify_fail("你要拿什么？ \n");
         if(!me->query_temp("marks/mai"))
return 0;


         if(me->query_temp("marks/pili_book"))
       return 0;
        lu = new(__DIR__"obj/pili_book");
        lu->move(me);
       me->set_temp("marks/pili_book", 1);
        message_vision("\n$N小心翼翼的从床上捡起一本破书。\n", me);
        return 1;
}


