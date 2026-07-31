//Cracked by Roath
// fear 2002/1/31
#include "ansi.h"
// #include <weapon.h>
// inherit HAMMER;
inherit ITEM;

string* titles = ({
        "±´¿Ç",
        "±´¿Ç",
        "±´¿Ç",
        "±´¿Ç",
        "±´¿Ç",
        "±´¿Ç",
        "±´¿Ç",
        "±´¿Ç",
        "±´¿Ç",
        "±´¿Ç",
});

void create()
{
        int i;
        i = random(sizeof(titles));
        if (i<2)
        set_name(HIW+titles[i]+NOR, ({ "sea shell", "shell"}));
        else if (i<4)
        set_name(HIM+titles[i]+NOR, ({ "sea shell", "shell" }));
        else if (i<6)
        set_name(HIR+titles[i]+NOR, ({ "sea shell", "shell" }));
        else if (i<8)
        set_name(HIB+titles[i]+NOR, ({ "sea shell", "shell" }));
        else
        set_name(HIY+titles[i]+NOR, ({ "sea shell", "shell" }));

        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("long", "ÕâÊÇÒ»¸öÑÕÉ«ÏÊÑÞµÄ±´¿Ç¡£\n");
                set("value", 15000+random(15000));
                set("material", "stone");
        }
        setup();
}

void init()
{
        add_action("do_blow","blow");
}

int do_blow(string arg)
{
        object me = this_player();
        object shell = present("shell", me);
		string* msg;

        if ( !arg|| arg != "shell" ) 
           return notify_fail("ÄãÒª´µÊ²Ã´£¿\n");

        if (this_player()->is_busy())
           return notify_fail("ÄãÕýÃ¦×ÅÄØ£¡\n");

		msg = ({
				HIM"$NÄÃÆð"NOR + (string)shell->query("name") +HIM"£¬·ÅÔÚ×ì±ßÒ»´µ£¬Á¢¿ÌÏìÆðÃÀÃî×íÈËµÄÒôÀÖ¡£"NOR,
					});
        me->start_busy(1);

        message_vision("\n"+ msg[random(sizeof(msg))] +"\n" , me);
        return 1;
}
