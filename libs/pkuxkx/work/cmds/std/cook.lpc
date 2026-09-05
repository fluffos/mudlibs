// profession职业系统 by Vast@pkuxkx 2009-06
// cook.c 烹饪

#include <ansi.h>

int main(object me, string arg)
{
	mapping profs, stuff;
	string file, *mat;
	object env, food, *all_mat;
	int sk, i, j, k, n, *num, time;
	
	if(!arg) return notify_fail("你要做什么菜？\n");
	if(!me->query_skill("cooking", 1))
		return notify_fail("你尚未学会烹饪之术。\n");
	if(!mapp(profs = me->query_profs()) || undefinedp(profs["cooking"]))
		return notify_fail("你什么东西都不会做！\n");
	if(member_array(arg, profs["cooking"]) == -1)
		return notify_fail("你并不会做" + to_chinese(arg) + "。\n");
	if(me->is_busy() || me->is_fighting() || me->query_temp("pending/cooking"))
		return notify_fail("你正忙着呢,哪有时间做菜啊？\n");
	
	env = environment(me);
	
	if(!env->query("kitchen") && !objectp(present("camp fire", env)))
		return notify_fail("你必须在厨房里或者篝火旁才能做菜。\n");
	
	file = PROFESSION_D("cooking/" + arg);
	sk = me->query_skill("cooking", 1);
	
	if(sk < file->query_min_level())
		return notify_fail("你厨艺不精，还没法做这道菜。\n");
	
	stuff = file->query_stuff();
	mat = keys(stuff);
	num = values(stuff);	

	for(i = 0; i < sizeof(stuff); i++)
	{
		for(j = 0; j < num[i]; j++)
		{
			if(objectp(present(mat[i]->query("id") + " " + (string)( j + 1), me)))
				k++;
		}
		
		if(k < num[i])
			return notify_fail("你带的" + mat[i]->query("name") + "不够，还没法做这道菜。\n");

		k = 0;
		n += num[i];
	}
	
//	all_mat = allocate(n);

	for(i = 0; i < sizeof(stuff); i++)
	{
		for(j = 0; j < num[i]; j++)
		{
			if(objectp(food = present(mat[i]->query("id")  + " " + (string)( j + 1), me)))
//				all_mat[n - 1] = food;
//				n--;
				destruct(food);
		}
	}

	time = file->query_time();
	
	me->set_temp("cooking/food", arg);
	me->set_temp("pending/cooking", 1);
	me->set_temp("cooking_cost", time);
	
	tell_object(me, "你将" + to_chinese(arg) + "的原料一股脑放在了一起。\n");
	message_vision("$N撸起袖子，准备做菜！\n", me);

	me->start_busy("cooking", "halt_cooking");	
	return 1;
}

int cooking()
{
	object me = this_player();
	string food_name = me->query_temp("cooking/food");
	int cost = me->query_temp("cooking_cost");
	int i, j, sk, min, max;
	string file = PROFESSION_D("cooking/" + food_name);
	mapping product;
	object food;
	string *des;
	
	if(!arrayp(des = file->query_des()))
		des = ({"$N开始做菜，蒸、炒、煎、炸，极尽所能！", });
	if(random(2) == 0)
		message_vision(des[random(sizeof(des))] + "\n", me);
	
	if(cost < 1)
		{
			product = file->query_product();
			for(i = 0; i < sizeof(product); i++)
			{
				for(j = 0; j < values(product)[i]; j++)
				{
					food = new(keys(product)[j]);
					food->move(me);
					tell_object(me, "你擦了擦头上的汗水，终于做出了一" + food->query("unit") + food->query("name") + "！\n");
				}
			}
			sk = me->query_skill("cooking", 1);
			min = file->query_min_level();
			max = file->query_max_level();
			
			if(sk < me->query("level") * 5)
				{
    			if ((sk - min) < (max - min)/2)
    				me->improve_skill("cooking", file->query_bonus());
    			else if (((sk - min) < (max - min)*3/4) && random(2) == 1)
    				me->improve_skill("cooking", file->query_bonus());
    			else if ((sk <= max) && random(3) == 1)
    				me->improve_skill("cooking", file->query_bonus());
			}
					
			me->set_temp("pending/cooking", 0);
			return 0;
		}
	me->add_temp("cooking_cost", -1);
	return 1;
}

int halt_cooking()
{
	object me = this_player();
	tell_object(me, HIG"你停止做菜，又浪费了一大堆珍贵的食材。\n"NOR);
	me->set_temp("pending/cooking", 0);
	me->set_temp("cooking_cost", 0);
	return 1;	
}

int help(object me)
{
	write(@HELP
指令格式 : cook [食物英文名称]

北大侠客行的职业技能之一，在厨房或者有篝火的地方，
可以使用此命令烹饪食物。当然必须先学会要烹饪的菜
谱，并且身上带着足够的原材料。
此动作可以用halt命令终止。

相关命令: professions(prof), survey, 
HELP
	);
	return 1;
}
