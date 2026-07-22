// kuzhi.c 枯枝
#include <weapon.h>
inherit SWORD;
int do_snap(string arg);
void create()
{
    set_name("枯枝", ({ "ku zhi","zhi" }) );
    set_weight(350);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一根干枯的树枝，看来可以折(snap)成数段。\n");
        set("unit", "根");
        set("value", 10);
        set("flag",2);
        set("wield_msg", "$N抓起一根$n，握在手中当武器。\n");
    }
    init_sword(1,2);
    setup();
}
void init()
{
    add_action("do_snap","snap");
}
int do_snap(string arg)
{
     object kuzhi;
     if( !arg || !id(arg) )
         return notify_fail("你想折什么？\n");
     if (query("name")=="断掉的枯枝") return 0;
        set_name("断掉的枯枝", ({ "duan zhi","zhi" }) );
        set("long", "一根断掉的枯枝。\n");
        set("value", 0);
     if (environment()){
        if (environment()==this_player())
                message_vision("$N用手把枯枝折成两段。\n", this_player());
        else
                message_vision("$N一脚把枯枝踩成两段。\n", this_player());
        kuzhi=new(__FILE__);
        kuzhi->do_snap("zhi");
        kuzhi->move(environment(this_object()));
    }
    return 1;
}

