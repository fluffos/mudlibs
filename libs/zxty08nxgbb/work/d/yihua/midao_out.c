#include <ansi.h>
inherit ROOM;
 
int do_pick(string arg) ;

void create()
{
        set("short", "密洞");
        set("long",@LONG
你正处在一个密洞中。这里光线很暗，只能隐隐约约看出地上有些其花异草。
花丛之中的一块石头上好象放着一个宝匣(xia)。 你突然闻到一股奇异的香味，你
真不知道你在什么地方了。
LONG);   
        set("item_desc", ([
        "xia" : @TEXT
你仔细看了一下石匣，发现里面似乎放着两本书，似乎可以试着拿出来
(pick book)。
TEXT
    ]) );
        set("exits", ([
  "out"  : __DIR__"midao",
  "west"   : __DIR__"xiaojing2",
]));
        set("objects", ([
        __DIR__"npc/huawuque" : 1,
    ]) );    

        setup();
}
void init()
{
            add_action("do_pick","pick");
}
void reset()
{
        ::reset();
        set("get_available" , 2);
}

int do_pick(string arg)
{
       object me,obj;

       me = this_player();
       if( !arg || arg!="book" )
              return notify_fail("你要取什么?\n");
obj=present("hua wuque",environment(me));
if(obj && living(obj))
        
       {
        message_vision(YEL"花无缺说到：没有宫主的同意怎么能拿呢？"
                       "除非我死了！\n" NOR,me);
        return 1 ;
       }
       if ( query("get_available") )  {
       obj = new (__DIR__"obj/yihuapu");
       obj->move(me);
       obj = new (__DIR__"obj/yifengjianpu");
       obj->move(me);
       add("get_available", -2);
       message_vision("$N从宝匣中取出两本书。\n",me );
       }
       else
       return notify_fail("秘籍已经被别人捷足先登了。\n");
       return 1;
}

