#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"金佛"NOR,({"jin fo","fo"}));
	set_weight(4000);
	if(clonep())
		set_default_object(__FILE__);
        else 
        {
                set("unit", "尊");
                set("long","一尊被高僧开光过的金佛，表面佛光四溢，霞光隐隐，庄严肃穆。\n");
                set("value", 0);
                set("no_sell","这等紧要之物，岂可丢弃？\n");
                set("no_put","这等紧要之物，岂可丢弃？\n");
                set("no_steal","这等紧要之物，岂可丢弃？\n");
                set("no_give","这等紧要之物，岂可丢弃？\n");
                set("no_drop","这等紧要之物，岂可丢弃？\n");
                set("no_score","这等紧要之物，岂可丢弃？\n");
                set("no_get","这等紧要之物，岂可丢弃？\n");
	}
        setup();
}