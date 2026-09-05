#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( HIY"东厂关防印"NOR, ({ "guanfang yin", "yin"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是东厂的关防印，可以凭此印自由进出东厂。\n你仔细一看，印上写着“钦差总督东厂官校办事太监关防”几个大字！\n");
                set("value", 100);
                set("dongchang", 1);
                set("no_drop",1);
                set("no_put", 1);
                set("no_get", 1);
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
        tell_object(environment(), HIY"一个小太监急急忙忙地跑来，对你说道：“奉海公公之命特来收回关防印！”\n"NOR);
        tell_object(environment(), HIY"你小心翼翼地将关防印交给了小太监！小太监接过印头也不回的走了。\n"NOR);
        destruct(this_object());
}
