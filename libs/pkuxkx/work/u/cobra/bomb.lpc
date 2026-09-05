#include <ansi.h>
inherit ITEM;
int do_throw(string arg);
void create()
{
	set_name(HIW +"手榴弹"+ NOR, ({ "bomb" }));
	set("long","很不起眼的小东西，好像没什么威力。\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","个");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",1000000);
	}
	setup();
}       

void init()
{
	add_action("do_throw","throw");
	if (this_player()->query("id",1)!="cobra")
		call_out("bombing",1,this_player());
}
int do_throw(string arg)
{
	object target;
	if(!arg) return notify_fail("你想炸谁？\n");
	target = find_player(arg);
	if(!objectp(target)) target= find_object(arg);
	if(!living(target)) return notify_fail("没有这个生物。\n");
	if(arg=="cobra") target=this_player();
	message( "channel:" + "chat",HIW"一颗手榴弹飞向空中，向着"+target->query("name",1)+HIW"飞去。\n"NOR,users());
	call_out("bombing",5,target);
	return 1;
}
int bombing(object target)
{
	object env;
	if(target->query("id",1)=="cobra")
	{
		message( "channel:" + "chat",HIW"手榴弹飞到一半突然掉下来了，大家小心啊～～～\n"NOR,users());
		return 1;
	}
	env=environment(target);
	message_vision("远处飞来一颗手榴弹，正好炸在$N的身上，只炸的$N血肉横飞，尸骨无存。\n",target);
	message( "channel:" + "chat",target->query("name",1)+HIW"被手榴弹炸死了，听说死状极其恐怖。\n"NOR,users());
        target->delete("env");
	target->die();
	target->unconcious();
	destruct(this_object());
	return 1;
}
