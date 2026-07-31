
// xshizi.c 小石子
// xueer

inherit ITEM;

void init();
void create()
{
	object me;
	string name,new_name;
	me=this_player();
	name = me->query("id")+"_shizi";
	new_name = me->query("name")+"要清扫的东西";
	set_name("小石子", ({"xiao shizi","shizi",name}) );
	set_weight(20);
	set("unit", "颗");
	set("long", "这是颗路边的小石子, 它是"+new_name+"。\n");
	set("no_get",1);
//	  set("value", 10);
	setup();
}