#include <ansi.h>
inherit ITEM;

void create()
{
        set_weight(100);
        set_name(HIB "¶Ï³¦É¢" NOR, ({"duanchang san", "duanchang", "san"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Æ¿");
                set("long", HIB "ÕâÊÇÒ»Æ¿Ä«ÂÌÉ«µÄ¾ç¶¾·ÛÄ©£¬¿ÉÉ±ÈËÓÚÎÞÐÎ¡£\n" NOR);
                set("value", 50);
		set("poison_type", "poison");
                set("can_pour", 1);
                set("can_daub", 1);
                set("can_drug", 1);
                set("poison", ([
                        "level" : 200,
                        "id"    : "he tieshou",
                        "name"  : "¶Ï³¦É¢¾ç¶¾",
                        "duration": 15,
                ]));
                set("no_sell", 1);
		set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        message_vision("$NÒ»Ñö²±£¬½«¶Ï³¦É¢µ¹ÈëÁË×ìÖÐ¡£\n", me);
        me->set("can_perform/lunhui-jian/hui", "1");
        destruct(this_object());
        return 1;
}
