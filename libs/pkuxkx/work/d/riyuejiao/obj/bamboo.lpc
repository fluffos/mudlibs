//create by zine Aug 28 2010
#include <ansi.h>


inherit ITEM;

void create()
{	
	set_name(HIG"大竹子"NOR, ({ "zhu zi", "bamboo"}));
	set_weight(100);
	set("long", "一根长长的竹子。\n");
	set("unit", "根");
    set("no_get",1);
	set("value", 1);
    set("remain",2+random(2));
	setup();
    call_out("dest",300);
}

int dest()
{
    destruct(this_object());
    return 1;
}

void init()
{
    add_action("do_xiao","xiao");
}

int do_xiao()
{
    object me=this_player();
    object kd,zt;
    int i,count=0;
    object *all=all_inventory(me);
    if (!me->query("rynewbiejob/zhulou/start"))
        {
            tell_object(me,"你想干什么呢？\n");
            return 1;
        }
    if (!present("kan dao",me))
    {
        tell_object(me,"要削竹子，你得找一把砍刀来才趁手。\n");
        return 1;
    }
    kd=present("kan dao",me);
    if (!kd->query("is_kandao"))
    {
        tell_object(me,"要削竹子，你得找一把砍刀来才趁手。\n");
        return 1;
    }
    if (!kd->query("equipped"))
    {
        tell_object(me,"刀要拿起来才有用。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("is_zhutiao"))
        {
            count=count+1;
        }
    }
    if (count>9)
    {
        tell_object(me,"你身上有太多竹条，再多拿不动了。\n");
        return 1;
    }
    message_vision("$N削下了一段竹条。\n",me);
    zt=new(__DIR__"bamboo2");
    zt->move(me);
    me->add_busy(1+random(2));
    this_object()->add("remain",-1);
    if (this_object()->query("remain")<1)
    {
        message_vision("大竹子被$N削得一丝不剩了。\n",me);
        destruct(this_object());
    }
    return 1;
}