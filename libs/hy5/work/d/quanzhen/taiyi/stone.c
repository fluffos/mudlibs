//Cracked by Roath
// stone.c
// Jay 7/4/96

#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

string* names = ({
	"鹅卵石","石块","大石头",
});

string* longs = ({
	"这是一块不太大的鹅卵石。\n",
	"这是一块有着棱角的石块。\n",
	"这是一块沉甸甸的大石头。\n",
});

void create()
{
    int i = random(sizeof(longs));

    set_name(names[i], ({"shikuai", "shi", "stone"}));
    set_weight(i*500 + 300); 
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("long", longs[i]);
	set("unit","块");
	set("wield_msg","$N搬起一块石头准备战斗。\n");
	set("material", "stone");
    }
    init_hammer(i+1);
    setup();
}
