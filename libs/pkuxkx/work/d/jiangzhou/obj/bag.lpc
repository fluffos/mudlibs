// By Zine

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"破米袋"NOR, ({ "po midai", "midai","dai" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
        set("long", "这是一个破米袋，如果在八角亭地面摩擦(ca)，会发出奇怪的声响。\n");
		set("value", 0);
        set("jiangnan",1);
		set("material", "cloth");
             }
       setup();
}

void init()
{
    add_action("do_ca", "ca");
}

int do_ca()
{
    object ob=this_player();
    object where=environment(ob);
    if (base_name(where)=="/d/jiangzhou/ting")
    {
        message_vision(BLU"$N发出了奇怪的声响，如鬼魅的叫声一般。\n"NOR,ob);
        return 1;
    }
}