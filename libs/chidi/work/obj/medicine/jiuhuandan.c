// music yangzhou's 人参

#include <ansi.h>

inherit ITEM;

void create(int many)
{
	string name;

	if(! many)	name="无用丹药";
	else if(many<=100)		name="小还丹";
	else if(many<=250)	name=GRN"大还丹"NOR;
	else if(many<=500)	name=HIC"九转丹"NOR;
	else if(many>500)	name=YEL"九转金丹"NOR;
	set_name(name,({"danyao","dan"}));
	set("long","这是颗经过炼丹术炼制的丹药。\n");
        set("unit", "颗");
        set("weight", 50);
	set("add",(int)many);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
	int add;

	add=(int)query("add");
	ob=this_player();
	if(!living(ob))	return 0;
	if( !id(arg) ) return notify_fail("你要吃什麽？\n");
	ob->receive_curing("gin",add);
	ob->receive_heal("gin",add);
	ob->receive_curing("kee",add);
	ob->receive_heal("kee",add);
	ob->receive_curing("sen",add);
	ob->receive_heal("sen",add);

	message_vision("$N吃下了一颗"+query("name")+"，长吸了一口气，感觉好多了。\n",ob);
        destruct(this_object());
        return 1;
}
