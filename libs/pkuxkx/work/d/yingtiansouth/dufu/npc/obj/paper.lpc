inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIW"旧纸"NOR, ({"jiu zhi","zhi","paper"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else 
    {
            set("long", "这是一页写满小楷的纸。\n");
            set("unit", "页");
            set("value", 5);
    }
	setup();
}
int is_MZJ_PASSWD()
{
	return 1;
}
void init()
{
	add_action("do_duizhao","duizhao");
}
int do_duizhao()
{
	object me=this_player();
	if (!me->query_temp("mzj/answer")||query("owner")!=me)
	{
		message_vision("$N前后看了几遍这页纸，却毫无头绪。\n",me);
		return 1;
	}
	if (!query("info"))
	{
		message_vision("$N看了半天，却发现$n上的字迹被水弄糊了。\n",me,this_object());
		return 1;
	}
	message_vision("$N背着众人，悄悄地打开了$n。\n",me,this_object());
	write(query("info"));
	return 1;
}
