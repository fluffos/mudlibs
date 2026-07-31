
// shuye.c 树叶
// xueer

inherit ITEM;

void init();
void create()
{
	object me;
	string name,new_name;
	me=this_player();
	name = me->query("id")+"_shuye";
	new_name = me->query("name")+"要清扫的东西";
	set_name("树叶", ({"shu ye","shuye",name}) );
	set_weight(10);
	set("unit", "片");
	set("long", "这是一片枯黄的小树叶, 它是"+new_name+"。\n");
	set("no_get",1);
//	  set("value", 10);
	setup();
}