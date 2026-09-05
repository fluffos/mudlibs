// Modified By  : iszt, 2006-08-16
// moved call_out("dest") to init(), added the prompt in dest()

//add by advent
//取走时有颜色提示
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( HIY"皇宫通行令"NOR, ({ "hgtongxing ling", "ling"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是大内签发的皇宫通行令，可以凭此令自由进出紫禁城。\n");
                set("value", 100);
                set("zijin", 1);
                set("no_drop",1);
                set("no_put", 1);
                set("no_store", 1);
                set("no_sell", 1);
                set("no_pawn", 1);
                set("no_give_user", 1);
        }
        setup();
}

void init()
{
        call_out("dest", 600);
}

void dest()
{
        tell_object(environment(), HIR"你的皇宫通行令失效了！\n"NOR);
        destruct(this_object());
}
