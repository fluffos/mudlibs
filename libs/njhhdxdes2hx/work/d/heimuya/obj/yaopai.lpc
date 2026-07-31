// marry_card.c
#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
        set_name(HIR "日"+HIB"月"+HIY "神教"NOR +"腰牌",({"yaopai","pai"}));
        set_weight(20);
          set("no_get",1);
	set("long","一块魔教腰牌,是用精铜打造的\n");
        set("no_drop","这是圣教的信物不能随便丢弃!!!\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("material", "铜");
        }
}

void init()
{
add_action("do_cha", "chashi");
}

int do_cha(string arg)
{
        if (!arg) {
                     write( MAG "你又将腰牌檫了一遍。\n" NOR);
                   }         
        return 1;
}

string query_autoload()
{
        return query("name");
}

void autoload()
{
}

