//create by guoth

#include <ansi.h>

inherit ITEM;

void create()
{
   set_name( HIW "轩辕古墓隔世石碑" NOR , ({ "geshi bei","bei" }) );
   set_weight(200000);
   set("long", @LONG
            入古墓者 男子需胆大心细 女子要绝待风华
        无福之人 难以学的好武功 无貌之人 难以学得好法术
               入我古墓需得忍得寂寞，奋发图强，
               有朝一日让我古墓大展神威于三界之中
LONG);
       if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
                set("material", "stone");
                set("value", 200);
                set("no_get", 1);
                set("amount",30);
        }
 
            setup();
}


