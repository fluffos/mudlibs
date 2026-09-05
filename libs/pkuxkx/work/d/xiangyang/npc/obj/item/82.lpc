#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(YEL"九转熊胆丸"NOR, ({"shanling wan","wan"}));
        set("unit", "颗");
        set("long", "这是一粒世间罕见的灵药,吃后可以起死回生，有长生不老。\n");
        set("value", 8000);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("你要吃什么？\n");
        if((int)this_player()->query("shen")>0)
        {
        this_player()->add("max_neili",10); 
        this_player()->add("max_jingli",15); 
        this_player()->add("shen",-1000);
        message_vision("$N吃下了一粒丸药,畅快极了.\n可是心里确突然想到了老猎户,一阵自责涌上心头.",this_player());
        destruct(this_object());
	return 1;
        }
        else
        {
        this_player()->add("max_neili",10); 
        this_player()->add("max_jingli",15);
        this_player()->add("shen",1000); 
        message_vision("$N吃下了一粒丸药,畅快极了.\n可是心里确突然想到了老猎户,奇怪,看来$N的良知尚未泯灭.",this_player());
        destruct(this_object());
	return 1;
        }
}

