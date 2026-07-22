#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("破书", ({ "poshu" , "book"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "翻开来看时,里面都是白纸,什么都没写.\n");
		set("material", "paper");
	}
setup();
}
