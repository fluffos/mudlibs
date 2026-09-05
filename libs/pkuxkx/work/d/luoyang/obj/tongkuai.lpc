//铜块 zine Oct 16 2010
inherit ITEM;
#include <ansi.h>
void create()
{
        string* color=({BLU,GRN});
        
        set_name(color[random(sizeof(color))]+"铜块"NOR, ({"tong kuai", "kuai", "copper block" }));
        set_weight(20);
		set("is_copperBlock",1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块锈迹斑斑的铜锭，似乎蕴含着某种力量。\n");
                set("unit", "块");
                set("value", 0);
                set("available", 10);
             }
        setup();
        call_out("dest",7200);

}

int dest()
{
    message_vision("$N上的锈斑在空气中迅速扩大，片刻之后，化为无形。\n",this_object());
    destruct(this_object());
    return 1;
}

