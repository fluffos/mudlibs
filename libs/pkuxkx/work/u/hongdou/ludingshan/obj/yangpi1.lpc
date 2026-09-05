// item: yangpi.c  碎羊皮
// hongdou 98/10/27

#include <ansi.h>
inherit ITEM;

inherit F_SAVE;
inherit F_AUTOLOAD;

void init()
{ 
    add_action("do_pin","pin");  
    add_action("do_kan","kan");
}

void create()
{
        set_name("碎羊皮", ({"yang pi", "pi"}));
        set_weight(100);
//        set_max_encumbrance(50000);
	set("no_get",1);
	set("np_drop",1);
	set("no_put",1);
	set("no_give",1);
	set("no_steal",1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一包从四十二章经里找到的碎羊皮。\n");
		set("unit", "包");
                set("material", "paper");
        }
}

int do_kan(string arg)
{
    object me=this_player();
    int i;  string str; 
    string *p=({HIR"正红"NOR,HIM"镶红"NOR,HIY"正黄"NOR,YEL"镶黄"NOR,
HIB"正蓝"NOR,HIC"镶蓝"NOR,HIW"正白"NOR,WHT"镶白"NOR});
    string jing="旗 经书";
    if(!id(arg)) return notify_fail("你要看什么?\n");
    write("这些碎羊皮中包括：\n");
    for (i=0;i<=7;i++)
    {
	if (me->query("42jing"+(i+1))>0)
        {
	   str=sprintf("     %s%s\n",p[i],jing);
	   write(str);   
	}
    }
    return 1;
}

int do_pin(string arg)
{
	object me = this_player();
	object obj=new("/u/hongdou/ludingshan/obj/baotu");
	int i,j=0;
        if (!id(arg))
                return notify_fail("你要干什么？\n");
	for (i=0;i<=7;i++)
	{
	    if(me->query("42jing"+(i+1))>0) j++;
	}
	tell_object(me,HIY"你开始拼凑碎羊皮......\n"NOR);
	if (j>=8)
	{
	    tell_object(me,HIY"\n你费了九牛二虎之力，终于将碎羊皮拼成了一幅地图。\n"NOR);
	    obj->move(me);
	    destruct(this_object());
	    return 1;
	}
	else 
	{
	    tell_object(me,HIC"\n你拼来拼去，总是拼不成功，看来碎羊皮还不够。\n"NOR);
	    return 1;
	}
}

string query_autoload()
{
        return query("name");
}
