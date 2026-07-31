// cracked by vikee 2/09/2002   vikee@263.net
// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "背阴山后");
  set ("long", @LONG

这里是阴司背阴山下，周围一片荒凉，不见草木，一片寂静中
只有阴风呼呼地刮着。山脚下淡发红光鬼焰，传说中的阴司十
八层地狱就在那里。从没有人从那里活着出去。


LONG);


  setup();
}
void init()
{
	add_action("do_get","eat");
	add_action("do_get","drink");
	add_action("do_get","kill");
        add_action("do_get","fight");
        add_action("do_get","cast");
        add_action("do_get","bian");
        add_action("do_get","fly");
        add_action("do_get","perform");
        add_action("do_get","steal");
	add_action("do_look", "look");
	add_action("do_exert", "exert");
}
int do_look(string arg)
{
	if( !arg ) {
		tell_object(this_player(),
"\n这里便是阎罗殿下的十八层地狱了，很少有人能从这里活着出去。\n\n");
		return 1;
	}
	command("look");
}
int do_exert(string arg)
{
	if( !arg )
		return notify_fail("你要用内功做什么？\n");
	if( arg!="heal"){
		command("exert");
		return 0;
	}
	tell_object(this_player(),"这里不能疗伤。\n");
	return 1;
}
int do_get(string arg)
{
	return 1;
}
