#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

mapping *skills = ({
	(["name": "jiuyin-zhengong", "max": 2000]),
	(["name": "daode-jing", "max": 500]),
	(["name": "jiuyin-shenzhua", "max": 500]),
	(["name": "jiuyin-shenzhang", "max": 500]),
	(["name": "jiuyin-shenfa", "max": 500]),
	(["name": "dafumo-quan", "max": 500]),
	(["name": "xuanyin-jian", "max": 500]),
	(["name": "yinlong-bian", "max": 500]),
	});

void create()
{
	string desc = "";
	int i;

        set_name(HIB"「九阴真经」"NOR, ({ "jiuyin zhenjing", "zhenjing" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
		for (i=0; i<sizeof(skills); i++)
			desc += sprintf("\t%s (%s)\n", to_chinese(skills[i]["name"]), skills[i]["name"]);
                set("long",HIC"这是一本武林中人梦寐以求的武学秘籍，上面写着：「九阴真经」。你可以研读以下的技能：\n\n"HIW+desc+"\n"NOR);
                set("treasure", 1);
                set("value", 0);
                set("material", "skin");
                set("no_drop", 1);
                set("no_put", 1);
                set("no_give", 1);
                set("no_get", 1);
                set("no_steal", 1);
        }
}

void init()
{
	add_action("do_yandu",({"yandu"}));
}

int do_yandu(string arg)
{
	int cost, my_skill, max_level, i, flag = 0;
	string book, skill;
	object me = this_player();
	object where = environment(me);

	if (!me->query("jiuyin/full"))
		return 0;
	if (!arg)
		return notify_fail("你要读什么？\n");
	if (sscanf(arg, "%s %s", book, skill) != 2)
		return notify_fail("指令格式：yandu <书名> <技能>\n");
	if (book != "zhenjing")
		return 0;
	for (i=0; i<sizeof(skills); i++)
		if (skill == skills[i]["name"]) {
			max_level = skills[i]["max"];
			flag = 1;
			break;
		}
	if (!flag)
		return notify_fail("你无法从" + this_object()->name() + "中学到这个技能。\n");
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");
	if (where->query("sleep_room"))
		return notify_fail("卧室不能读书，会影响别人休息。\n");
	if( me->is_fighting() )
		return notify_fail("你无法在战斗中专心下来研读新知！\n");
	if( !me->query_skill("literate", 1) )
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
	if (!random(5))
		message("vision", me->name() + "正专心地研读" + this_object()->name() + "。\n", environment(me), me);
	if((int)me->query("potential") - (int)me->query("learned_points") < 200 ) 
         return notify_fail("你的潜能太少了!\n");	

	if( (int)me->query("learned_points") < 1 )
		return notify_fail("你的潜能已经用完了，再怎么读也没用。\n");

	if( (int)me->query("potential") < 1 )
		return notify_fail("你的潜能已经用完了，再怎么读也没用。\n");
	if( (int)me->query("combat_exp") < 1000000 )
		return notify_fail("你的实战经验不足，再怎么读也没用。\n");
	if( me->query("int") < 30 || me->query_int() < 60 )
		return notify_fail("以你目前的领悟能力，还没有办法学这个技能。\n");
	notify_fail("依你目前的能力，没有办法学习这种技能。\n");
	if( !SKILL_D(skill)->valid_learn(me) )
		return 0;
	cost = 40 * (1 + (50 - (int)me->query("int")) / 20);
	if (cost < 10) cost = 10; // minimum cost
	if((int)me->query("jing") < cost) {
                me->start_busy(1);
	        return notify_fail("你的精不够用了。\n");
	}
	my_skill = me->query_skill(skill, 1);
	if (my_skill > max_level)
		return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
	if (my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp"))
		return notify_fail("也许是缺乏实战经验，你对帛卷上面所说的东西总是无法领会。\n");
	else
		write("你研读着有关" + to_chinese(skill) + "的技巧，似乎有些心得。\n");
	me->improve_skill(skill, ((int)me->query_skill("literate", 1) / 5 + 1));
	me->receive_damage("jing", cost);
	me->add("potential", - random(2));
	return 1;
}

int query_autoload() { return 1; }
