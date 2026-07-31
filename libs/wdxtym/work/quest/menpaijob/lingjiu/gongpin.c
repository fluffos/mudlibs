inherit ITEM;

void create()
{
	set_name("贡品", ({ "gong pin" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一盒贡品。\n");
//		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_get",1);
    	        set("no_steal",1);
		set("no_put",1);
                set("yuer",1);	
		set("unit", "盒");
		set("value", 0);
	}
}
