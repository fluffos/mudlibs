// /u/beyond/obj/chahua.c
// this is made by beyond
// update 1997.6.30
#include <ansi.h>                     
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIR"抓破美人脸"NOR,({ "flower", "hua" }) );
         set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("value", 0);
                set("material", "plant");
                set("long", "这是一朵抓破美人脸。\n");
                set("wear_msg", "");
                set("unequip_msg", "$N摘下胸前的$n。\n");
                set("armor_prop/armor", 0);
        }
           
        setup();
}

int wear()
{
	object me = environment();
	int ret;

	message_vision("$N拿出一朵" + this_object()->query("name") + "，戴在胸前。", me);
	if (ret=::wear()) {
		if (me->query("gender") == "男性")
			message_vision("好一个风流少年郎！\n", me);
		else if (me->query("gender") == "女性")
			message_vision("好一个美丽俏佳娃！\n", me);
		else
			message_vision("好一个不三不四的家伙！\n", me);
	}
	return ret;
}
