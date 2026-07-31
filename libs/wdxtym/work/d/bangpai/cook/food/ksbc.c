#include "food.h"

mapping food_info = ([
	"name" : "开水白菜",
	"id" : "ksbc",
	"need" : (["baicai" : 5,]),
	"time" : 300,
	"unit" : "盘",
	]);

void create()
{
	create_food(food_info);
}

int add_buff(object who)
{
	who->set_temp("eat_food", 1);
	who->add_temp("apply/damage", 50);
	who->add_temp("apply/unarmed_damage", 50);
	who->add_temp("apply/attack", 50);
	tell_object(who, "你吃下了开水白菜，获得50攻击加成。\n");
	return 1;
}

void remove_buff(object who)
{
	who->delete_temp("eat_food");
	who->add_temp("apply/damage", -50);
	who->add_temp("apply/unarmed_damage", -50);
	who->add_temp("apply/attack", -50);
	tell_object(who, "你吃下食物所加的buff消失了。\n");
}