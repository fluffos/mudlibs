// lingzhi.c Ç§ÄêÁéÖ¥
//ĞÇĞÇ(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "mo");

}
void create()
{
        set_name(HIM"°¢±¦"NOR, ({"amy"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
set("value", 100)
;
                set("unit", "¸ö");

;
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
        return notify_fail("ÄãÒªÃşÊ²Ã´£¿\n");
        this_player()->start_busy(20);
        this_player()->add("potential",1000);
         this_player()->add("score",20000)
;
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
