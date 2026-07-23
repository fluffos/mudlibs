inherit ITEM;
#include "/inherit/item/embed.h"
void create()
{
        set_name(HIW "冰魄银针" NOR, ({ "bingpo yinzhen", "zhen", "needle", "yinzhen" }));
        //bingbo->bingpo 注音问题 caiji@SJ 
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("damage", 3);
                set("poison", "bing_poison");
                set("embed", 1);
                set("unit", "枚");
                set("throw_msg", HIW"$N袖袍一挥，一枚冰魄银针自袖底飞出直向$n急射而去！\n"NOR);
                set("long", "一枚纯银的细针，针身镂刻花纹，打造得极是精致。\n");
                set("unique", 20);
                set("value", 20000);
        }
        setup();
}


