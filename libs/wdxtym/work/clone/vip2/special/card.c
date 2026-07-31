
#include <ansi.h>

inherit ITEM;
inherit F_BANKER;


void create()
{
        set_name(HIY"储蓄卡"NOR, ({"chuxu ka"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "张");
		set("text" , "这是一张储蓄卡，你可以"ZJURL("cmds:cun")+ZJSIZE(20)+"存钱"NOR"，"ZJURL("cmds:qu")+ZJSIZE(20)+"取钱"NOR"，"ZJURL("cmds:check")+ZJSIZE(20)+"查账"NOR"\n");
		set("long",HIW+query("text") );
                set("value", 8000);
                set("no_put", 1);
                set("no_get", 1);
                set("no_drop", 1);
                set("no_give", 1);
		        set("yuanbao", 10);
	            set("dealer", "bank");
                set("no_sell", 1);
                set("no_steal", 1);
                set("material", "paper");
        }
        setup();
}

void init()
{
	add_action("do_check", "check");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "qu");
	delete_temp("busy");
}
cun;
qu;
check;
int query_autoload() { return 1; }