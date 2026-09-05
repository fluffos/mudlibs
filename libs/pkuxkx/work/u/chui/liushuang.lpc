// 浓硫酸
// BY KEINXIN @sj2 2003.4

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG"浓硫酸"NOR, ({"nong liusuan", "liusuan", "suan"}));
	set_weight(10);
    set("value", 100000);
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("value", 100000);
		set("long", "这是一个精致的磁瓶，瓶身上标着"+HIG"浓硫酸"NOR+"两个字，是
由炼丹人从胆矾中提炼出的。腐蚀性极强。		
使用方法"HIY" po 某人 "NOR"\n");
		set("unit", "瓶");
	}
}
  void init()
{
  add_action("do_po","po");
}
int do_po(object target)
{
	
        target = present(target,environment(this_player()));
        if (!target
        ||  environment(target)!=environment(this_player()))
                return notify_fail("你要泼谁？\n");    

        if (target == this_player()) return notify_fail("有创意！\n");
        
        if (target->query_per()< 6) return notify_fail(""+target->query("name")+"都成这样了，还用得着泼？\n");

        message_vision(HIC"$N偷偷取出"HIG"浓硫酸"HIC"，悄悄接近$n，乘$n不注意，冷不防将"HIG"浓硫酸"HIC"泼向$n ! "NOR"\n", this_player(),target);
	
	if (random(target->query("combat_exp"))>this_player()->query("combat_exp")/2){
	
        message_vision(RED"$n出于本能，抬手一击，结果整瓶"HIG"浓硫酸"RED"全部向$N脸上飞去！\n$N痛苦得在地上打滚，脸上嗞嗞的冒着白烟和水泡 ！ "NOR"\n", this_player(),target);
        this_player()->add_temp("apply/per",-5);
        this_player()->add("per",-1);
	this_player()->start_busy(10);
	destruct(this_object());
	return 1;
	}
        message_vision(RED"$n躲闪不及，结果整瓶"HIG"浓硫酸"RED"全部泼在$n脸上！\n$n痛苦得在地上打滚，脸上嗞嗞的冒着白烟和水泡 ！ "NOR"\n", this_player(),target);
        target->add_temp("apply/per",-5);
        target->add("per",-1);
	target->start_busy(10);
	destruct(this_object());
	return 1;
}
