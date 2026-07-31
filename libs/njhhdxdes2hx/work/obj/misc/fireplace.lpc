// fireplace.c

inherit ITEM;

void create()
{
	set_name("火炉", ({ "fireplace" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个煎药用的火炉，里面烧著红红的炭火。\n");
		set("no_get", "这个火炉被固定在地上，拿不起来。\n");
		set("unit", "个");
		set("weight", 8000);
		set("value", 700);
	}
	set_max_encumbrance(9000);
}

void insert_object(object ob)
{
	if( ob->to_burn() ) return;

	seteuid(getuid());
	switch( (string)ob->query("material")) {
		case "cloth":
		case "paper":
			message("vision", ob->name() + "著了火，很快地烧掉了。\n", environment() );
			message("vision", ob->name() + "著了火，很快地烧掉了。\n", this_object() );
			destruct(ob);
			return;
		default:
			return;
	}
}
