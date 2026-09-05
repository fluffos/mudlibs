#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void init()
{
//                set("long", "这是一把俄罗斯生产的AK47自动步枪，里面满装着"+this_object()->query("bullet")+"发黄金子弹。\n");
                set("long", "这是一把俄罗斯生产的AK47自动步枪，里面满装着"+this_object()->query("bullet")+"发黄金子弹。\n");
        add_action("do_aim","aim");
        add_action("do_shoot","shoot");
        add_action("do_shootall","shootall");
}

void create()
{
        set_name(HIY"AK47自动步枪"NOR, ({ "ak47", "qiang", "gun" ,"ak"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("bullet", random(100));
                set("no_sell",1);
                set("no_store",1);
                set("no_pawn",1);
                set("value", 50000);
                set("material", "steel");
                set("rigidity", 100000);
//                set("long", "这是一把俄罗斯生产的AK47自动步枪，里面满装着"+this_object()->query("bullet")+"发黄金子弹。\n");
                set("wield_msg", "$N把肩上的$n里握在手中。\n");
                set("unequip_msg", "$N将手中的$n挂回肩上。\n");
        }
        init_sword(100);
        setup();
}

int do_aim(string arg)
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
        
        if(wizardp(obj))
                return notify_fail("你活得不耐烦了，敢打天神？！\n");

        if(obj == me)
                return notify_fail("用 suicide 指令会比较快:P。\n");
        
        message_vision(HIY "\n$N举起金手枪，远远地瞄准$n，接着「克」地一声，把子弹压上了膛。\n\n" NOR, me, obj);
        this_object()->set_temp("target", arg);
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

        message_vision(HIR "\n$N对准$n扣动了扳机！！！\n只听「乒」地一声巨响，$n惨叫一声，缓缓地仆倒在血泊里！\n\n" NOR,
                        me, obj);

        obj->delete_temp("last_damage_from");
        obj->die();
        this_object()->add("bullet",-1);
        this_object()->set("value",0);
        return 1;
}
int do_shootall()
{
        object me, obj;
        string arg;
        object *ob;
         int i;
        if( this_object()->query("bullet") <=0)
                return notify_fail("金子弹已经打光了。\n");

        me = this_player();
        ob = all_inventory(environment(me));
        message_vision(HIR "\n$N正如土匪一样冲进屋子里面来，\n不管三七二十一，没有瞄准就胡乱的开枪！！\n只听「乒」「乒」连续几声的枪响，\n\n" NOR, me, obj);
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if(ob[i]->query("id") == "guo jing" ) continue;
                if(ob[i]->query("id") == "zhu") continue;
                if(ob[i]->query("dart_id")) continue;
                if(userp(ob[i])) continue;
       message_vision(HIR"只听$N惨叫一声，缓缓地仆倒在血泊里！\n" NOR, ob[i]);
        ob[i]->delete_temp("last_damage_from");
        ob[i]->die();
        this_object()->add("bullet",-1);
               }
        this_object()->add("bullet",-1);
        this_object()->set("value",0);
        return 1;
}

