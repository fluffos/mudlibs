//Created by whuan@pkuxkx
//投名状任务之藏宝箱
#include <ansi.h>
inherit ITEM;

void create()
{
    	set_name("藏宝箱", ({ "cangbao xiang", "xiang", "box" }));
     	set_weight(500);
			set_max_encumbrance(5000);
			if( clonep() )
					set_default_object(__FILE__);
			else 
			{
        set("unit", "口");
        set("long", "这是一口沉重的大箱子，看样子里面装着不少好东西，上面有一个封条，写着铁掌帮几个字。"
        +"\n看起来打开并不容易，必须掌握开启(unseal)之法才能打开。\n");
        set("value", 100);
        set("material", "wood");
			}
			setup();
}

void init()
{
    	add_action("do_unseal","unseal");
}

int do_unseal()
{
    object me, ob, obj;
    me= this_player();
    ob= this_object();
		if (me->is_busy())
		{
			tell_object(me,"你先忙完自己的事情再说吧。\n");
			return 1;
		}	

    if (ob->query("owner")!=me->query("id"))
    {
    	tell_object(me,"你没有掌握开启之法，无法打开这个箱子。\n");
    	return 1;
    }
    write("\n你心中默念开启的方法，一边慢慢地尝试。\n只听~~嘎吱~~一声，藏宝箱的盖子打开了......\n");
    me->set_busy(1);
    obj = new(__DIR__"baowu");
    obj->set("owner",me->query("id"));
    obj->move(me);
    write(HIW"你欣喜的从宝箱中拿出镇山之宝，藏在怀中，顺势一脚把宝箱踢到路边。\n");
		destruct(ob);
    return 1;
}

void destme()
{
		    remove_call_out("dest");
			  call_out("dest", 1200, this_object());  
}
void dest(object me)
{
       message_vision("一阵风吹过，$N裂成了数片！\n",me);       
       destruct(me);
       return;
}
