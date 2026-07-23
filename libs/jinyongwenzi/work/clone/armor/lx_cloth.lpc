// 十三龙象袈裟
// by emnil	2/15/2k

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

string setcolor();

void create()
{
	set_name(HIW"十三龙象袈裟"NOR, ({ "shisan longxiang" ,"longxiang jiasha", "jiasha", "shisan jiasha" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("text" , "这是一件喇嘛穿的袈裟，上面绣着些梵文，看似普通但却是大轮寺开寺始祖终身所穿的袈裟。\n"
				+"可能是因为它长时间被龙象内力笼罩，所以也似乎有了储存内力的功效。你可以试试注入内力(longxiang)。\n"NOR);
		set("long",HIW+query("text") );

		set("material", "silk");
		set("unit", "件");
		set("unique", 1);
		set("value", 10000000);
		set("treasure", 1);
		set("wear_msg", HIW"只见$N"HIW"双手一抖，便把一件隐隐透着紫色光彩的袈裟穿在了身上。\n" NOR);
		set("armor_prop/armor", 80);

		set("owner","no owner");
		set("neili",0);
        }
        setup();
}

void init()
{
	add_action("do_longxiang","longxiang");
}

int do_longxiang(string arg)
{
	int cost;
	object me = this_player();

	if( query("neili") >= 13990 )
		return notify_fail("袈裟中已经充满了内力，你再也无法注入了！\n");

	if( me->query_skill("force") < 160 )
		return notify_fail("你的内功等级不够，无法注入内力！\n");

	if( me->query_skill("longxiang-boruo",1)>100 && me->query_skill_mapped("force")=="longxiang-boruo" )
		cost = 1000;
	else
		cost = 1200;

	if( cost > me->query("neili") )
		return notify_fail("你的内力不足，无法注入足够的内力！\n");

	if( query("owner")!=me->query("id") && query("owner")!="no owner" ) {
		set("neili" , query("neili")/2);
		message_vision(MAG"$N"MAG"发现你的内力与袈裟中原有的内力相冲突，虽然最终还是注入了你的内力，但已经损失了不少。\n",me);
	}
	set("owner" , me->query("id"));

	add("neili" ,  1000);
	if (query("neili") > 13990) set("neili" , 13990);
	me->add("neili" , -cost);

	if( cost<=1000 )
		message_vision(MAG"$N"MAG"脸上泛起一层隐隐的紫气，双手虚按十三龙象袈裟，把龙象内力注入袈裟之中。\n"NOR,me);
	else
		message_vision(HIC"$N"HIC"潜运内功，努力把内力注入十三龙象袈裟，最后虽然成功但因为不是龙象内力而多花了点力气。\n"NOR,me);
	
	setcolor();

	return 1;
}

mixed ob_hit(object target, object me, int damage)
{
	int times , qi , cost , charge = 16;
	string color;
	
	if(query("neili")<= 0 || damage<250)
		return 0;

	if(query("owner") == me->query("id"))
		times = 10;
	else 
		times = 15;

	cost = (damage / 2)*charge/10*times/10;
	qi = damage/2;
	if( cost > query("neili") ) {
		qi = qi * query("neili") / cost ;
		cost = query("neili");
	}		
	add("neili" , -cost);

	if(wizardp(me) && me->query("env/test")) 
		tell_object(me,sprintf("qi:%d , neili:%d   ",qi,cost));

	color = setcolor();	
	if( times<=10 )
		message_vision(query("name")+color+"突然发出耀眼的光芒，抵挡了$N"+color+"的部分攻势！\n"NOR,target);
	else
		message_vision(query("name")+color+"突然发出耀眼的光芒，抵挡了$N"+color+
					"的部分攻势！但因为内功冲突而浪费了不少储存的真气。\n"NOR,target);

	return -qi;
}

string setcolor()
{
	int lvl;
	string color , s;

	if ( query("neili") != 0 )
		lvl = query("neili") / 1000;
	else
		lvl = 0;
	switch (lvl)  {
		case  0:
		case  1:
		case  2: color = HIW;break;
		case  3:
		case  4: color = HIC;break;
		case  5:
		case  6: color = CYN;break;
		case  7:
		case  8: color = HIB;break;
		case  9:
		case 10: color = BLU;break;
		case 11:
		case 12: color = HIM;break;
		case 13: color = MAG;break;
		default: color = HIW;
	}
	set("name" , color+"十三龙象袈裟"NOR );
	
	if( lvl > 0 )
		s = color+"袈裟之上已经注有"+CHINESE_D->chinese_number(lvl)+"道内力！\n"NOR;
	else
		s = "";
	set("long" , color+query("text")+s);

	return color;
}