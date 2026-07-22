// huyao.c

#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
	set_name(HIY"天蚕宝衣"NOR,({"tiancan baoyi","baoyi","cloth"}));
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","件");
		set("long","一件黑黝黝的背心，很有弹性。\n");
		set("value",500000);
		set("material","armor");
		set("armor_prop/armor",10);
		set("oldsix/max_damage",10);
		set("oldsix/protect",100);
		set("oldsix/by",1);
		set("zhengzhao",4);
		set("no_sell",1);
	}
	setup();
}

mapping armor_action(object me,object target,int damage)
{
	string msg="";
	mapping foo=([]);
	this_object()->set("oldsix/damage",0);
		msg+=HIW"天蚕宝衣突然反弹，将$N的攻击卸去了大半！\n"NOR;
		damage/=2;
		if(damage<=0)	damage=0;
	foo["msg"]=msg;
	foo["damage"]=damage;
	return foo;
}
int move(mixed dest)
{
        if(! userp(dest))       return ::move(dest);
        if( ::move(dest)==0)    return 0;
	message("channel:rumor",YEL"【谣言】"+ "某人：天蚕宝衣被"+
        dest->query("name")+"抢到手了！\n"NOR,users());
        return 1;
}
