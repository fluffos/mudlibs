#include <ansi.h>
void init()
{
	add_action("do_yanjiu","yanjiu");
}
int do_yanjiu()
{
	object me=this_player(),ob=this_object();
	string mark=query("EnhanceMark");
	if (me->query(mark))
	{
		tell_object(me,"你已经掌握了处理"+ob->query("EnhanceMaterial")+"之材的方法，现在这个对你意义不大了。\n");
	}
	else
	{
		me->set(mark,1);
		tell_object(me,HIG+"恭喜！你彻底掌握了处理"+ob->query("EnhanceMaterial")+HIG+"之材的方法！\n"+NOR);
		message_vision(HIY+"$N"+HIY+"化成纸屑，飘散在风中。\n"+NOR,this_object());
		destruct(this_object());
	}
	return 1;
}
