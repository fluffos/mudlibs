// cloth.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	int lvl;
	set("armor_type", TYPE_CLOTH);
	lvl = this_object()->query("level");
	if( lvl<1 )  lvl = 1;
	if( lvl>20 ) lvl = 20;
	delete("armor_prop/armor");
	set("armor_prop/combat_def",7+lvl);
	set("armor_prop/spells_def",7+lvl);
}

void init()
{
	add_action("do_tear", "tear");
}

int do_tear(string str)
{
	object ob;

	if( !id(str) ) return 0;

	if( (string)query("material") != "cloth" )
		return notify_fail("你只能撕布料的衣服。\n");

	if( (int)query("teared_count") >= 4 )
		return notify_fail( name() + "的袖口，下面已经没有多余的布可撕了。\n");

	message_vision("$N从" + name() + "撕下一条布条。\n", this_player() );
	add("teared_count", 1);
	set("armor_prop/combat_def",-1);
	set("armor_prop/spells_def",-1);
	ob = new("/obj/bandage");
	ob->set_name("从" + name() + "撕下的布条", ({ "cloth piece", "piece", "cloth" }) );
	if( !ob->move(this_player()) )
		ob->move(environment(this_player()));
	return 1;
}
