
// card4.c

inherit ITEM;

void create()
{
    set_name("比武令牌", ({"biwu card","card"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
     "这可是由天神阿波罗亲自签发的比武令牌,只有拥有它，你才可以自由出入天下第一广场\n");
	set("unit", "块");
	set("weight", 10);
set("no_get",1);
set("no_drop",1);
}
}

