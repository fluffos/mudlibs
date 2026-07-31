#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void init()
{
       add_action("do_miao","miao");
       add_action("do_pen","pen");
}

void create()
{
        set_name(HIC"防狼喷雾"NOR, ({ "pen wu", "pen","wu", "penwu" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("bullet", 1000);
                set("value", 50000);
                set("material", "steel");
                set("long", "西门无剑公司出厂的最新最有效的防狼喷雾(女性专用)。\n");
                set("wield_msg", "$N从小手提包里拿出一小瓶子防狼喷雾。\n");
                set("unwield_msg", "$N将手里的防狼喷雾放回手提包里。\n");
        }
        setup();
}

int do_miao(string arg)
{
        object me, obj;
        
        me = this_player();

        if( !arg )
                return notify_fail("你想喷哪头野狼？\n");

        if( this_object()->query("bullet") <=0)
                return notify_fail("防狼喷雾已经用光了。\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是狼。\n");

        if(obj == me)
                return notify_fail("用 suicide 指令会比较快:P。\n");

     message_vision(HIM "\n$N从小提包里掏出一小瓶子"HIY"【"HIG"西门灭狼牌"HIY"】"HIM"防狼喷雾，对准了蠢蠢欲动的"HIC"$n"HIM"。\n\n" NOR, 
                        me, obj);

        this_object()->set_temp("target", arg);

        return 1;
}

int do_pen()
{
        object me, obj;
        string arg;

        me = this_player();

        if( !(arg = this_object()->query_temp("target")) ) 
                return notify_fail("你还没有瞄准你的喷的狼！\n");

        if( !objectp(obj = present(arg, environment(me)) ))
                return notify_fail("你要喷的狼早溜了。\n");

        message_vision(HIR "\n$N对着接近自己的"HIB"野狼$n"HIR"喷射了防狼喷雾...\n
"HIY"$n"HIG"捂着"HIR"红肿的眼睛"HIG"滚在地上，一边流鼻涕一边乱"HIC"哭"HIG"乱"HIC"叫"HIG"。\n\n" NOR,
                        me, obj);

        this_object()->add("bullet", -1);
      obj->set_temp("pker_time",1);
      return 1;
}

