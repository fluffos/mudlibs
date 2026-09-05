inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("兵器架", ({"bingqi jia", "jia"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "架");
		set("long", "一个兵器架，可以取用(qu)上面的刀，剑和枪等常用兵器。\n");
        set("material", "stone");
		set("value",30);
		set("no_get","勤练功是好事，连锅端吃相也太坏了吧？\n");
		// set("resource/water", 1);

    }
    setup();
}

void init()
{
	add_action("do_qu","qu");
}
int weapon_exist(object me)
{
	object *weapons;
	weapons=all_inventory(me);
	for (int i=0;i<sizeof(weapons);i++)
	if (weapons[i]->query("meng_weapon"))
	return 1;//身上有
	return 0;
}

int do_qu(string arg)
{
	string *legal_items=({"sword","blade","spear"});
	object ob,me= this_player();
	if (!arg||member_array(arg,legal_items)==-1)
	{
		tell_object(me,"你要取什么东西？sword, blade or spear?\n");
		return 1;
	}
	if (weapon_exist(me))
	{
		tell_object(me,"你不是拿着一件武器吗？\n");
		return 1;
	}
	ob=new(__DIR__+arg);
	ob->move(me);
	ob->set("meng_weapon",1);
	message_vision("$N从兵器架上拿下一件"+ob->query("name")+"。\n",me);
	tell_object(me,"似乎可以在这里尝试挥舞(huiwu)一下这件兵器。\n");
	return 1;
}
