/*
兵器强化系统，思路来自于塞班年代的手机网游，代码本身简单，需要一定的逻辑性。
*/

#include <ansi.h>
inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

//int query_autoload() { return 1; }
void create()
{
        set_name(HIM "混沌石" NOR, ({ "hundun shi", "fqhs" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "天外混沌石可以将自造防具装备进行等阶升级，当然需要你的装备有了一定的强度才可以使用它。\n" NOR);
                set("unit", "颗");
                set("base_unit", "颗");
                set("no_sell", 1);
                set("no_give", 1);
                set("no_drop", 1);
                set("no_get", 1);
                set("base_weight", 1);
                set("zb",1);             
                set("yuanbao",100);               
            set("base_value",500000);
        }
        setup();
}

void init()
{
        add_action("do_integrate", "fstrengthen");
}

int do_integrate(string arg)
{
        object me;
        object ob;
        string ownerid,namejia;
        int cgl,cgll;

        if (! arg)
                return notify_fail("你要往什么道具上使用混沌石？\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)) &&
            ! objectp(ob = present(arg, environment(me))))
                return notify_fail("你身上和附近没有这样道具啊。\n");
if (ob->is_weapon() || ob->is_unarmed_weapon())
                return notify_fail("你只能在防具上使用混沌石。\n");
        ownerid = ob->item_owner();
//jiapoint = ob->query("point")/10;
cgl = ob->apply_armor()/10;//随着防御有效值的提高，强化的难度也提高
tell_object(me, "你把" + name() + "盖在" + ob->name() + "上，然后口中念念有词，\n"
                        "只见混沌石融入了" + ob->name() + "体内！\n");
if (ob->query("itemlevel")>=20)
{
tell_object(me, HIC "你发现混沌石已经无法融入" + ob->name() +" 又缓缓的退了出来。\n" NOR);
return 1;
}
if (random(cgl)==0||me->query("sitemlevel")>=cgl)//这个是什么意思呢？意思就是有保底，避免过多强化失败
{
        ob->add("itemlevel", 1);
        ob->save();
        ob->set("armor_prop/armor",ob->apply_armor());//读取
        me->delete("sitemlevel");
        if (ob->query("itemlevel")==20)
                message("channel:chat",HBRED"系统通告"HIR"："+me->query("name")+"成功把"+ob->name()+"强化到了满级，一把神级装备出世了.\n"NOR,users());                
        tell_object(me, HIC "强化成功！你感受到" + ob->name() + HIC"变的更稳重而神秘了，目前等阶：+"+ob->query("itemlevel")+"。\n" NOR);
    
        }
        else
        {
        me->add("sitemlevel",1);
        tell_object(me, HIC "强化失败！你的" + ob->name() + HIC"啥变化都没有！\n" NOR);           
        }
add_amount(-1);
      
        return 1;
}