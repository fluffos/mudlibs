//liwu  北侠满月彩蛋(弥月之喜套装)
//Made By westernd
//2015-03
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("北侠满月彩蛋",({"cai dan","egg"}));
        set("long","这个是庆祝北侠满月的彩蛋,好像有什么东西在里面(open)?\n");
        set("unit","个");
	    set("no_drop",1);
        set("no_get",1);
        set("value",0);
        set("no_store",1);
       setup();
}

void init()
{
    add_action("do_open","open");
}

int do_open(string arg)
{
    object me;
	object p;
    me = this_player();
    if (!arg)  return notify_fail("你打开什么？\n");
    if((arg=="cai dan") || (arg=="egg")) 
    {
		p=new("obj/taozhuang/manyue/fengman");
   		p->move(me);
        tell_object(me, "你发现了一只丰满之弥戒指。\n");
		p=new("obj/taozhuang/manyue/taijia");
   		p->move(me);
        tell_object(me, "你发现了一只太甲之月戒指。\n");
        destruct(this_object());
     }
     return 1;
}
