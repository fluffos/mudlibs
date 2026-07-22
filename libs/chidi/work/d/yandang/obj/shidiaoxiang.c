inherit ITEM;

void create()
{
	set_name("石雕像", ({ "shidiao" , "xiang"}) );
	set_weight(500000);
	set("no_get",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "尊");
		set("long", "一尊石雕佛像,不过脑袋不知给谁搬了去.\n");
		set("value", 1);
             set("no_drop",1);
		set("material", "stone");
	}
setup();
}
