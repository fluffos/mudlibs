
// feizhi.c 废纸
// xueer

inherit ITEM;

void init();
void create()
{
	object me;
	string name,new_name;
	me=this_player();
	name = me->query("id")+"_feizhi";
	new_name = me->query("name")+"要清扫的东西";
	set_name("废纸", ({"fei zhi","zhi",name}) );
	set_weight(10);
	set("unit", "张");
	set("long", "这是张废弃的纸, 它是"+new_name+"。\n");
	set("no_get",1);
//	  set("value", 10);
	setup();
}