
// poyi.c 破僧衣
// xueer

inherit ITEM;

void init();
void create()
{
	object me;
	string name,new_name;
	me=this_player();
	name = me->query("id")+"_sengyi";
	new_name = me->query("name")+"要清扫的东西";
	set_name("破僧衣", ({"po sengyi","sengyi",name}) );
	set_weight(30);
	set("unit", "件");
	set("long", "这是一件穿破了的僧衣, 它是"+new_name+"。\n");
	set("no_get",1);
//	  set("value", 10);
	setup();
}