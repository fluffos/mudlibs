// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"倚天剑"NOR,({ "yitian jian","jian"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long",        HIW"这是一把通体狭长的剑，份量颇重，剑鞘上刻着“倚天一出，谁与争锋”。\n"NOR);
		set("value",1000000);
		set("material", "steel");
		set("oldsix/qjdy",1);
		set("zhengzhao",1);
	}
	init_sword(25);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", HIW"只听“铮”的一声，一道耀眼的银光闪过，$N的手中多了把倚天剑。\n"NOR);
        set("unwield_msg", HIW"银光咋敛,$N手中的倚天剑已经收入腰间的剑鞘内。\n"NOR);

// The setup() is required.

	setup();
}

mixed weapon_action(object me,object victim)
{
	object ob,target_weapon;
	string msg;
	target_weapon=victim->query_temp("weapon");
	if(! target_weapon)	return 0;
	if( target_weapon->query("oldsix/qjdy"))	{
		msg=HIW"“铛”的一声，"+this_object()->query("name")+HIW"与"+
		target_weapon->query("name")+HIW"相交，冒出点点火星！\n"NOR;
		return msg;
	}
	msg=HIW"只见白光一闪，"+victim->query("name")+HIW"手中的"+target_weapon->query("name")+HIW"被"+this_object()->query("name")+HIW"削为两段！\n"NOR;
			ob=target_weapon;
			ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "断掉的" + ob->query("name"));
			ob->set("value",0);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
			return msg;

}
int move(mixed dest)
{
        if(! userp(dest))       return ::move(dest);
        if( ::move(dest)==0)    return 0;
	message("channel:rumor",YEL"【谣言】"+ "某人：倚天剑被"+
        dest->query("name")+"抢到手了！\n"NOR,users());
        return 1;
}
