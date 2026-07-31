// gaibang-bag.c
#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
	set_name(YEL "布袋" NOR, ({"budai", "bag"}));
        set_weight(20);
        set_max_encumbrance(200);
        set("no_get",1);
        set("long","丐帮级别的象征！\n");
        set("no_drop","这是丐帮信物不能随便丢弃!!!\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "布");
        }
}

string query_autoload()
{
        return query("name");
}

void autoload()
{
}

