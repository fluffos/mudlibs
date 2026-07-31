// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIC"屠龙刀"NOR,({"tulong dao","dao"}));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
               set("long", HIC"三百年来,号称武林第一利器,有道是:
武林至尊,宝刀屠龙.号令天下,莫敢不从.倚天不出,谁与争锋.
故老相传,刀中藏有一个秘密.\n"NOR);
		set("value", 1000000);
		set("material", "steel");
		set("oldsix/qjdy",1);
		set("zhengzhao",1);
	}
	init_blade(25);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", HIC"伴着一声大喝，$N从背后鲨鱼皮套中抽出一把屠龙刀。顿时$N气势徒增。\n 刀把上铭刻的两条龙在青色的氤氲之气中更显威猛。\n"NOR);
       set("unwield_msg", HIC"$N将手中的屠龙刀插入背后的鲨鱼皮套,神色为之一松。\n"NOR);

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
	if(! userp(dest))	return ::move(dest);
	if( ::move(dest)==0)	return 0;
	message("channel:rumor",YEL"【谣言】"+ "某人：屠龙刀被"+
	dest->query("name")+"抢到手了！\n"NOR,users());
	return 1;
}
