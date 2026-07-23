#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(HIC"新修本草"NOR, ({ "xinxiu bencao", "medicine book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("treasure",1);
                set("unique", 1);
                set("long", "这是一本由唐代苏敬等编辑完成的医学药典，由唐朝廷向全国颁行流通
使用，为中国医学史上第一部国家药典，它又被称为《唐本草》。\n");
                 set("value", 45000);
                set("material", "paper");
                set("exp_required", 200000);
                 set("jing_cost", 75);
                set("difficulty", 32);
                set("min_skill", 120);
                set("max_skill", 141);
        }
}
#include "m-book.h";
                
