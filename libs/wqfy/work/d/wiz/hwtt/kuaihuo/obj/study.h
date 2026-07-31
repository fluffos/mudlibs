// study.c

#include <skill.h>

int do_learn(string arg)
{
	object me;
	object ob;
	mapping skill;
	string	book,liter;
	int cost, sena;
	int amount=0;
	int my_skill;
	me = this_player();
	if( me->is_fighting() )
		return notify_fail("你无法在战斗中专心下来领悟！\n");
       if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能领悟。\n");

       if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
                return notify_fail("指令格式：lingwu <物品> <神数量>\n");

	if(!objectp(ob = present(book, me)) )
	if(!objectp(ob = present(book, environment(me))))
		return notify_fail("你要领悟什麽？\n");

	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("你无法从这样东西领悟到任何东西。\n");
// added by tie
	if(stringp(skill["literate"])) liter = skill["literate"];
	else liter = "literate";
	if( !me->query_skill(liter, 1) )
		return notify_fail("你看不懂耶．．，先学学"+to_chinese(liter)+"吧。\n");

	message("vision", me->name() + "正试着领悟" + ob->name()
		+ "。\n", environment(me), me);
	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

	cost = skill["sen_cost"] + skill["sen_cost"] 
		* (skill["difficulty"] - (int)me->query_int())/20;
	cost = cost /2;
        if(cost < 1) cost = 1;
	if( cost > sena)
	return notify_fail("以你目前的能力，你至少要花"+chinese_number(cost)+"点神\n");
	if( (int)me->query("sen") <= sena) {
		write("你现在过於疲倦，无法专心下来领悟。\n");
		return 1;
	}

	if( me->query_skill(skill["name"], 1) > skill["max_skill"] ) {
		write("你领悟了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
		return 1;
	}
        my_skill = (int) me->query_skill_eff_lvl(skill["name"]);
             
	me->receive_damage("sen", sena);

	if( !me->query_skill(skill["name"], 1) )
		me->set_skill(skill["name"], 0);
	amount = (me->query_skill(skill["name"], 1) - 75) * SKILL_D(skill["name"])->black_white_ness()/100;
        if(amount < -25 && me->query_skill(skill["name"], 1) < 75) amount = -25;
	amount +=(int)me->query_skill(liter, 1)/5+1;
	if( amount < 1) amount = 1;
	amount = amount*sena/cost;
	me->improve_skill(skill["name"], amount);
	write("你领悟有关" + to_chinese(skill["name"]) + "的技巧，似乎有点收获。\n");
	return 1;
}


