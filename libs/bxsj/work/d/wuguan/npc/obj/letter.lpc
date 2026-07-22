// letter
#include <ansi.h>

inherit ITEM;

void init();

void create()
{
        set_name(HIW"付韩兄书"NOR,({"xin", "shu xin", "letter" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一封蜡漆封口的信笺，是襄阳武馆馆主让你转交给一位老友的。
上书
                 「字付"+HIR"韩兄"+NOR"，弟"+HIC"震山"+NOR"再拜」
\n你看着信封上熟悉的行书，不由得回忆起在当年在武馆中的生涯。\n\n");
                set("unit", "封");
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("value", 0);                
         }
}
int query_autoload()
{
	return 1;
}
