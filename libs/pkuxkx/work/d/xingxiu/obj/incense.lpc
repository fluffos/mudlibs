#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY"残香"NOR, ({ "xiang","incense"}));
	set_weight(200);
    set("value",0);
    set("no_give",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_store",1);
    set("no_pawn",1);
    set("is_xiang",1);
    set("basic_xiang_bonus",1+random(4));
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一支残香，不知道有什么用途。\n");
			set("unit", "支");
		}
}

int phase()
{
    object ob=this_object();
    ob->add("is_on",1);
    if (ob->query("is_on")>=720)
    {
        message_vision("$N彻底燃尽了！\n",ob);
        destruct(ob);
        return 1;
    }
    else if (ob->query("is_on")==600)
    {
        ob->set_name(HIW"残香"NOR, ({ "xiang","incense"}));
        ob->set("xiang_bonus",4);
        message_vision("$N的颜色变了变。\n",ob);
        return 1;
    }
    else if (ob->query("is_on")==480)
    {
        ob->set_name(HIR"残香"NOR, ({ "xiang","incense"}));
        ob->set("xiang_bonus",3);
        message_vision("$N的颜色变了变。\n",ob);
        return 1;
    }
    else if (ob->query("is_on")==240)
    {
        ob->set_name(HIC"残香"NOR, ({ "xiang","incense"}));
        ob->set("xiang_bonus",2);
        message_vision("$N的颜色变了变。\n",ob);
        return 1;
    }
    else if (ob->query("is_on")==60)
    {
        ob->set_name(YEL"残香"NOR, ({ "xiang","incense"}));
        ob->set("xiang_bonus",1);
        message_vision("$N的颜色变了变。\n",ob);
        return 1;
    }
    remove_call_out("phase");
    call_out("phase",60);
    return 1;
}

int dian(object ob)
{
    object me=this_object();
    if (me->query("dian")&&userp(environment(me)))
    {
        tell_object(environment(me),me->query("name")+"已经被点燃了。\n");
        return 1;
    }
    else if (ob)
    {
        message_vision("$N小心翼翼地点燃了$n。\n",ob,me);
    }
    else
    {
        message_vision("$N被点燃了。\n",me);
    }
    me->set("dian",1);
    remove_call_out("phase");
    call_out("phase",1);
    return 1;
}