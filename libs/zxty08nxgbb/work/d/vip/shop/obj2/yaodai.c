#include <armor.h>
#include <ansi.h>
#include <mudlib.h>
inherit SURCOAT;
 
void owner_is_killed() { destruct(this_object()); }
void create()
{
         set_name(HIC"黄金腰带"NOR, ({ "huangjin yaodai", "yaodai" }));

        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "条");
                set("long", "这是一件黄金腰带，用以保护腹部。增加防御力500,下线不掉{kaiguang yaodai}!\n");
              set("tianya_money",2);
		set("no_put",1);
              set("no_sell",1);
              set("ty_gift", 1);
              set("no_get", 1);
            set("no_vipcun",1);

              set("no_give", 1);
              set("no_drop",1);                 set("armor_prop/dodge", -3);
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
        if (me->query("vipshop/yaodai")>1)
                return notify_fail("这件装备你开光过了！\n");

                tell_object(me, HIG "恭喜你！你为你的装备开光好了，现在除了死亡，你的装备下线将不掉落。\n");
                me->set("vipshop/yaodai", 2);

        return 1;
}
