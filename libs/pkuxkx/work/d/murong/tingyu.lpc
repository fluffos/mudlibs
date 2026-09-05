//tingyu.c
//by hehe
//2003.3.5

#include <ansi.h>
inherit ROOM;

void create()
{
   set("short", "听雨居");
   set("long", @LONG
这是个四面是窗的小木屋,龄空建在湖上，看上去
似乎并没有特别之处。木屋的中间放着一具瑶琴(qin)。
可能有点古怪.
LONG   );

   set("item_desc", ([
        "qin" : "这琴比之寻常七弦琴短了尺许，却有九根琴弦，颜色各不相同。\n"
                "不知道弹起来好不好听。\n",
   ]));

    set("exits", ([
		"south" : __DIR__"qroad5",
    ]));

    setup();
}

void init()
{
	add_action("do_tan", "tan");
	add_action("do_tan", "play");
	}

int do_tan (string arg)
{   object room;
    object ob = this_player();
    if (!arg||arg!="qin") return notify_fail("你要弹什么？\n");
    message_vision("$N轻轻的在琴上一拨，铛的一声，声音颇为宏亮。\n\n"
                   +"原来这弦是金属所制.....\n"
                   +"$N正诧异间，忽觉脚底一虚，身子往下直沉.....\n", ob );
    tell_object(ob, "\n.........................................\n" ) ;
    tell_object(ob, "\n.................................\n" ) ;
    tell_object(ob, "\n...........................\n" ) ;
    tell_object(ob, "\n.................\n" ) ;
    tell_object(ob, "\n.......\n" ) ;
    tell_object(ob, "\n你忍不住啊哟一声，便掉入了一个软绵绵的所在！只见自己已处在一只小船之中。\n\n" ) ;

    ob->move("/d/murong/qboat") ;

    return 1 ;
}



