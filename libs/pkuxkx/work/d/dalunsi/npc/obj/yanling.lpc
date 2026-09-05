#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIW"雁翎"NOR, ({ "yan ling", "ling" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根长长的大雁翎毛，看花纹似乎在中原不太多见，所以比较珍贵\n");
                set("value", 10000);
                set("material", "head");
                set("wear_msg", HIY "$N高高兴兴的把$n"+HIY"别在了头上。\n" NOR);
                set("remove_msg", HIY "$N把$n从头上摘了下来。\n" NOR);
                set("armor_prop/armor", 1);                                
        }
        setup();
}

