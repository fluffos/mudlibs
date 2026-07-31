// xuantian.c 【玄天宝鉴】

#include <ansi.h>
#include <weapon.h>

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name(HIR"【玄天宝鉴】"NOR, ({"xuantian baojian","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
	set("long","一本表装得很精美的书，里面没有一个文字，画满了卦像。\n");
        set("material", "paper");
        set("value", 100);   
	set("no_sell",1);
        }
}

