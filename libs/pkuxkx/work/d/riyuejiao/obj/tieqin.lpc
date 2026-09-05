// tieqin  铁琴

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("铁琴", ({ "tie qin", "qin" }));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "这是一张铁制的瑶琴，颜色暗旧。你可以弹(play)它。\n");
		set("value", 50000);
		set("material", "iron");
		set("music", "qin");
		set("wield_msg", "$N拿出一张$n，双手抱住，微微一笑。\n");
		set("unwield_msg", "$N将手中的$n轻轻地放下。\n");
	}
	init_sword(15);
	setup();
}

void init()
{
        add_action("do_play", "play");
}

int do_play(string arg)
{
        if (!id(arg))
                return notify_fail("你要演奏什么？\n");
        switch( random(3) ) {
                case 0:
                        say(this_player()->name() + "一挽袖子，故作风雅地弹起琴来，但却不成调子，只听得四周的麻雀乌鸦都随着琴声一唱一和，甚是嘈杂。\n");
			write(this_player()->name() + "一挽袖子，故作风雅地弹起琴来，但却不成调子，只听得四周的麻雀乌鸦都随着琴声一唱一和，甚是嘈杂。\n");

                        break;
                case 1:
                        say(this_player()->name() + "盘膝坐下，拿出古琴调了调弦，便如行云流水一般地演奏开来，忽如空山鸟语，忽如百鸟朝凤，忽而安祥平和，忽而剑拔弩张，令人为之倾倒。\n");
			write(this_player()->name() + "盘膝坐下，拿出古琴调了调弦，便如行云流水一般地演奏开来，忽如空山鸟语，忽如百鸟朝凤，忽而安祥平和，忽而剑拔弩张，令人为之倾倒。\n");
                        break;
                case 2:
                        say(this_player()->name() + "拿出一张古琴，悠然地弹了起来。那幽怨琴声似乎在诉说一个久远的故事，让人黯然神伤。\n");
			write(this_player()->name() + "拿出一张古琴，悠然地弹了起来。那幽怨琴声似乎在诉说一个久远的故事，让人黯然神伤。\n");
                        break;
        }
        return 1;
}

