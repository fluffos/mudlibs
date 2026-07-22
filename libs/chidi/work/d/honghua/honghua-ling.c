inherit ITEM;

void create()
{
        set_name( "红花令", ({ "honghua_ling"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
                set("long", "这是一块绿油油的竹牌，上书红花令三个大字，是红花会至高无上的令牌\n");
		set("value", 100000);
		set("material", "iron");
	}
	setup();
}

void init()
{
        call_out("dest", 1800);
}

void dest()
{
	destruct(this_object());
}
