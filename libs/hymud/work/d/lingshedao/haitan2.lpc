//Room:/d/lingshedao/haitan2.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "海滩");
        set("long", @LONG
这是一片平坦的海滩,眼前是蔚蓝的大海.海滩边上
停有一只小船(boat),远处停有一艘巨大的战舰.
LONG);
        set("exits", ([
                "southwest"    : __DIR__"lsroad5",
       ]));
        set("item_desc",([
               "boat" : "可以enter进入小船.\n",
        ]) );       
               
        set("no_clean_up",0);
        set("outdoors","lingshedao");
        setup();
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter()
{
        object ob=this_player();
        message_vision("$N走进小船,将船驶向茫茫大海....\n",ob);
        ob->move("/d/taohua/dahai");
        tell_object(ob,BLU"你在海上航行了很久很久.......\n" NOR );
        call_out("go_quanzhou",10,ob);
        return 1;
}

void go_quanzhou(object ob)
{
       tell_object(ob,"船终于靠在了一个海港上.你急忙跳下了船.\n");
       ob->move("/d/quanzhou/haigang");
}
