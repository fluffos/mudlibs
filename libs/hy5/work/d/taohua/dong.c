#include <ansi.h>

inherit ROOM;
 
int do_pick(string arg) ;

void create()
{
        set("short", "山洞");
        set("long",@LONG
你正处在一个小山洞中。这里光线很暗，只能隐隐约约看出地上有一堆
干草。干草上好象放着一个石匣(xia)。 你突然闻到一股难闻的气味，显然
是有人长期住在这里却不打扫的缘故。
LONG);   
        set("item_desc", ([
        "xia" : @TEXT
你仔细看了一下石匣，发现里面似乎放着一本书，似乎可以试着拿出来(pick book)。
TEXT ]) );
        set("exits", ([
            "out"  : __DIR__"dongkou",
        ]));
//	set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_pick","pick");
}

int do_pick(string arg)
{
       object me,obj;

       me = this_player();
       if( !arg || arg!="book" )
              return notify_fail("你要拿什么?\n");
       if ( !me->query("jiuyin/full") && me->query("jiuyin/shang") && !present("jiuyin shangjuan", me) )  {
              obj = new ("/clone/book/jiuyin-shang");
              obj->move(me);
              message_vision("$N从石匣中取出一本书。\n",me );
message("channel:rumor", MAG"【谣言】某人："+this_player()->query("name")+"拿到九阴真经上卷啦。\n"NOR, users());
       }
       else
              return notify_fail("你要拿起那本书，却发现你看花了眼，其实那里什么都没有。\n");
       return 1;
}
