#pragma save_binary
#include <ansi.h>
#include <weapon.h>

inherit M_WEAPON;


int duanlian(string weapon_id);

void create()
{
	
    set_name( COR "订作的" NOR, ({ "order" }) );
	set("unit", "把");
	set("no_drop",1);
    set("no_get",1);
	set("make_time","zgtl_tanbin");
    set("origin","原料");
	set("timestamp","STAMP");
	set("maker","smith");
    set("owner","fengyun");
    set("level",1);
    set_desc();
	set("rigidity",500);
	set("wield_msg", "$N从怀中摸出一把$n握在手中。\n");
    set("unwield_msg", "$N将手中的$n藏入怀中。\n");
	
	init_dagger(this_object()->query("level")*10);
	setup();
}
void init()
{
        add_action("do_duanlian","duanlian");
}

int do_duanlian(string weapon_id)
{
	object me,weapon;
	int w_level;

	weapon=this_object();
	if (weapon->query("id")!=weapon_id)
		return 0;
	me=this_player();

	w_level=weapon->query("level");
	if (weapon->query("owner")!=me->query("id"))
		return notify_fail("你费了半天劲，可就是不能找到诀窍来提升这件武器！\n");
	if( !weapon )
		return notify_fail("你要锻炼什么?\n");

	if( (int)me->query("eff_force") < 10*w_level+1000 )
		return notify_fail("你的内力不够，无法锻炼匕首！\n");
	
	if( (int)me->query("kee") < 150 )
		return notify_fail("你的气不够，无法锻炼匕首！\n");
	
	if( (int)me->query("gin") < 30 )
		return notify_fail("你的精不够，无法锻炼匕首！\n");
	
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的神不够，无法锻炼匕首！\n");

	if( me->query("eff_kee")*100/me->query("max_kee") < w_level*25)
		return notify_fail("你现在的体力太弱，无法锻炼匕首！\n");

	if( me->query("eff_gin")*100/me->query("max_gin") < w_level*25 )
		return notify_fail("你现在的精力无法集中，不能锻炼匕首！\n");

	if( me->query("eff_sen")*100/me->query("max_sen") < w_level*25 )
		return notify_fail("你现在的神气不足，不能锻炼匕首！\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 125*w_level )
		return notify_fail("你的潜能不够，无法锻炼匕首！\n");
	
	if( ((int)me->query("combat_exp") < 125*w_level)||((int)me->query("business_exp") < 125*w_level) )
		return notify_fail("你的经验不够，无法锻炼匕首！\n");

	message_vision(HIR "$N手指匕脊，一股内力丝丝的传了进去。\n" NOR, me);

	me->add("max_force",-10*w_level);
	me->add("eff_force",-10*w_level);
	me->add("kee",-150);
	me->add("eff_kee",1-w_level*20*me->query("max_kee")/125);
	me->add("gin",-30);
	me->add("eff_gin",1-w_level*20*me->query("max_gin")/125);
	me->add("sen",-30);
	me->add("eff_sen",1-w_level*20*me->query("max_sen")/125);
	
	me->add("learned_points", 125*w_level);
	me->add("combat_exp", -125*w_level);
	me->add("business_exp", -125*w_level);


	message_vision(HIY "匕身忽的一亮，一道金光隐入$N的匕首体，不见了！\n" NOR,me);
	message_vision(HIG "$N的匕首的等级提高了！\n" NOR, me);
	if(weapon->query("equipped") ) 
		weapon->unequip();
	weapon->add("level",1);
	weapon->set_desc();
	weapon->init_dagger(weapon->query("level")*10);
	weapon->save();
	weapon->restore();
	return 1;
}
void owner_is_killed()
{
        write(HIY"只见一声清脆的响声，"+query("name")+HIY"落在地上，断成数截。\n"NOR);
        destruct(this_object());
}
