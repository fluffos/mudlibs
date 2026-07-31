// gaibang-bag.c
#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
	set_name(YEL "布袋" NOR,({"budai","bag"}));
        set_weight(20);
        set_max_encumbrance(100);
        set("long","丐帮级别的象征！\n");
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

