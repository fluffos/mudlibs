#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void init()
{
        add_action("do_miao","miao");
        add_action("do_wakeup","xin");
        add_action("do_shoot","shoot");
}

void create()
{
        set_name(HIY BLK"AK47"NOR, ({ "AK 47", "ak","47", "gun" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("bullet", 1000);
                set("value", 50000);
                set("material", "steel");
                set("long", "重火力机关枪！！！\n");
                set("wield_msg", "$N提起一柄"HIY BLK"AK47"NOR"「喀嚓」一声把子弹上了膛。\n");
                set("unwield_msg", "$N将手里的"HIY BLK"AK47"NOR"收了起来。\n");
        }
        init_blade(100);
        setup();
}

int do_miao(string arg)
{
        object me, obj;
        
        me = this_player();

        if( !arg )
                return notify_fail("你想杀谁？\n");

        if( this_object()->query("bullet") <=0)
                return notify_fail("金子弹已经打光了。\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if(obj == me)
                return notify_fail("用 suicide 指令会比较快:P。\n");

        message_vision(HIY "\n$N举起"BLK"AK47"HIY"，远远地瞄准$n，接着「克」地一声，把子弹压上了膛。\n\n" NOR, 
                        me, obj);

        this_object()->set_temp("target", arg);

        return 1;
}

int do_wakeup (string str)
{
        object who;

        if (!str) return notify_fail ("[MYST]: wakeup error, wakeup <someone>\n");

        if (!(who = present(lower_case(str), environment(this_player()))) )
                return notify_fail ("[MYST]: wakeup error, 没有" + str + "\n"); 
        who->remove_call_out("revive");
        who->revive();
        who->reincarnate();
        return 1;
}

int do_shoot()
{
        object me, obj;
        string arg;

        me = this_player();

        if( !(arg = this_object()->query_temp("target")) ) 
                return notify_fail("你还没有瞄准你的射击目标！\n");

        if( !objectp(obj = present(arg, environment(me)) ))
                return notify_fail("你要射击的对象已经离开了。\n");

        message_vision(HIR "\n$N对准$n扣动了扳机！！！\n只听「达达达」地一阵巨响，$n惨叫一声，缓缓地仆倒在血泊里！\n\n" NOR,
                        me, obj);

        this_object()->add("bullet", -1);
        obj->unconcious();

        return 1;
}


