#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void init()
{
        if(!wizardp(this_player()))
        set("no_get","嘿嘿，巫师的东西，有门吗?\n");
        add_action("do_aim","aim");
        add_action("do_shoot","shoot");
        add_action("do_shootall","shootall");
	add_action("do_stop","stopshoot");
}

void create()
{
        set_name(HIY"AK47自动步枪"NOR, ({ "ak47", "qiang", "gun" ,"ak"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("bullet", 100);
                set("value", 50000);
                set("material", "steel");
                set("rigidity", 100000);
                set("long", "这是一把俄罗斯生产的AK47自动步枪，里面满装着一百发黄金子弹。\n");
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

        obj->die();

        return 1;
}
int do_shootall()
{
        object me, obj;
        string arg;
        object *ob;
         int i;

        me = this_player();
        ob = all_inventory(environment(me));
        message_vision(HIG "$N一个闪身，凌空而起，跃上一棵大树隐蔽起来。\n" NOR, me, obj);
        call_out("do_check",1,environment(me));
        return 1;
}
int do_check(object here)
{
	object *ob;
	int i,shown;
	object me;
string *msg = ({
	HIM"剑气穿过，$N呆了一呆，身上忽然射出几道血剑。$N大叫一声，扑倒在地。\n"NOR,
	HIC"一道青光闪过，$N已经被拦腰割成了两段！\n"NOR,
	HIR"剑气从$N当胸穿过，$N惨叫一声，仰面倒地，再也不动了。\n"NOR,
	HIB"$N从未见过如此神奇的剑术，不禁万念俱灰，转身挥刀自宫...不，是自杀了。\n"NOR,
	HIG"$N看到眼前血腥的屠杀场面，哼也没哼，软倒在地，活活吓死了。\n"NOR,
});
	
        me = this_player();
        ob = all_inventory(here);
        shown = 0;
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if(ob[i]->query("id") == "guo jing" ) continue;
                if(ob[i]->query("id") == "hao mao" ) continue;
                if(ob[i]->query("dart_id")) continue;
                if(userp(ob[i])) continue;
                if (!shown)
                	message_vision(HIM"只听冰冰一声轻笑，手中宝剑绽出几道霞光，转眼化为无敌剑气，直向敌人飞去！\n"NOR,ob[i]);
       		shown = 1;
       		message_vision(msg[random(sizeof(msg))], ob[i]);
        	ob[i]->die();
               }
         call_out("do_check",1,here);
	return 1;
}

int do_stop()
{
	
	while (remove_call_out("do_check") != -1)
	{
		tell_object(this_player(),"你停止了埋伏。\n");
	}
	return 1;
}