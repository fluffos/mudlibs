#include <ansi.h>
#include <armor.h>
inherit FINGER;
void create()
{
        set_name(HIW"玉镯子"NOR,({ "yu zhuozi", "zhuozi" }));
        set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "付");
		set("long", "\n这是一付名贵的玉镯。\n");
		set("value", 500000); 
                set("unique", 1);
                set("treasure", 1);
                set("unequip_msg", "$N摘下手上的$n。\n");
                set("armor_prop/armor", 1);
	}
	setup();
}

int wear()
{
        object me = environment();
	int ret;
        message_vision("$N把一付" + this_object()->query("name") + "，戴在手上。", me);
        if (ret=::wear()) {
                if (me->query("gender") == "男性")
                        message_vision("男人家也要带玉镯，真是笑死人了。\n", me);
                else if (me->query("gender") == "女性")
                        message_vision("带上这付玉镯，$N显得更加俏丽！\n", me);
                else
                        message_vision("$N现在越发想东方不败了。\n", me);
        }
        return ret;
}
