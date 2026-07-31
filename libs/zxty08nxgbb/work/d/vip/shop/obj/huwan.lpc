// huwan.c 护腕
#include <ansi.h>
#include <armor.h>
#include <mudlib.h>
inherit WRISTS;
void create()
{
        set_name(HIR"真龙护腕"NOR, ({ "wrists", "huwan" }));

        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", "这是一双增加防御力200的真龙护腕,下线不掉。\n");
              set("tianya_money",2);
		set("no_put",1);
              set("no_sell",1);
              set("ty_gift", 1);
              set("no_get", 1);
              set("no_give", 1);
              set("no_drop",1); 
            set("no_vipcun",1);

                set("armor_prop/armor", 200);
                set("material", "cloth");
        }
        setup();
}
void init()
{
        add_action("do_kai", "kaiguang");
}

int do_kai(string arg)
{
        object me;

        if (! id(arg))
                return notify_fail("你要开光什么？\n");

        me = this_player();
         
        if (!me->query("vip"))
                return notify_fail("你不是VIP！\n");
        if (me->query("vipshop/huwan")>1)
                return notify_fail("这件装备你开光过了！\n");

                tell_object(me, HIG "恭喜你！你为你的装备开光好了，现在除了死亡，你的装备下线将不掉落。\n");
                me->set("vipshop/huwan", 2);

        return 1;
}
