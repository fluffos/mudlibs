// shishi.c
#include <ansi.h>

inherit ROOM;

mapping *skills = ({
	(["name": "dafumo-quan", "max": 200]),
	(["name": "jiuyin-zhengong", "max": 100]),
	(["name": "jiuyin-shenfa", "max": 150]),
	});

void create()
{
        set("short", "石室");
        set("long", @LONG
室中也无特异之处，你抬头仰望，但见室顶密密麻麻的写满了字迹符号，
你看了一会，但觉奥妙难解。室顶西南角绘著一幅图，似与武功无关，凝神细
看，倒像是幅地图。
LONG
        );

        set("exits", ([
                "up" : __DIR__"shiguan",
        ]));

	set("item_desc", ([
		"图" : "你凝望著那幅图，心中不由大喜，原来那绘的正是出墓的秘道。\n",
		"室顶" : "你看着室顶，满满的都是密密麻麻的小字。\n",
	]) );

        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_look",  ({ "kan", "look" }));
	add_action("do_yandu",({"yandu"}));
}

int do_look (string arg)
{
	object me = this_player();
	
	if (me->query_temp("jiuyin/gumu") < 3)
		return 0;
	if( !arg || arg!="zi")
		return notify_fail("你想看什么？\n");
	if (!me->query("jiuyin/gumu") && me->query("jiuyin/gumu-failed") > 2)
		return notify_fail("你已经看过很多次，再看也没什么心得了！\n");
	message_vision(HIY"$N望著那些小字，似乎都是一些武功要诀。\n", me);
	if (me->query("jiuyin/gumu")) {
		message_vision("$N陡然一瞥间，看到几个小字“九阴真经内功要诀”，你兴奋极了。\n", me);
		message_vision("$N研究了一下，发现应该能研读(yandu)些"HIB"大伏魔拳法"HIY"(dafumo-quan)、\n", me);
		message_vision(HIB"九阴真功"HIY"(jiuyin-zhengong)以及"HIB"九阴身法"HIY"(jiuyin-shenfa)的皮毛。\n"NOR, me);
		return 1;
	}
	if (me->query("kar") > 40 && random(20) == 0) {
		message_vision("$N陡然一瞥间，看到几个小字“九阴真经内功要诀”，你兴奋极了。\n", me);
		message_vision("$N研究了一下，发现应该能研读(yandu)些"HIB"大伏魔拳法"HIY"(dafumo-quan)、\n", me);
		message_vision(HIB"九阴真功"HIY"(jiuyin-zhengong)以及"HIB"九阴身法"HIY"(jiuyin-shenfa)的皮毛。\n"NOR, me);
		me->delete("jiuyin/gumu-failed");
		me->set("jiuyin/gumu", 1);
		message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"在古墓石室中发现了九阴真经内功要诀啦。\n"NOR, users());
		return 1;
	} else {
		message_vision("不过上面写的艰深难懂，$N看了一会就放弃了。\n"NOR, me);
		me->add("jiuyin/gumu-failed", 1);
		return 1;
	}
}

int do_yandu(string arg)
{
	int cost, my_skill, max_level, i, flag = 0;
	string book, skill;
	object me = this_player();
	object where = environment(me);

	if (!me->query("jiuyin/gumu"))
		return 0;
	if (!arg)
		return notify_fail("你要读什么？\n");
	if (sscanf(arg, "%s %s", book, skill) != 2)
		return notify_fail("指令格式：yandu <书名> <技能>\n");
        if((int)me->query("learned_points") < 200 ) 
		return notify_fail("你的潜能太少了。\n");
	if (book != "yaojue")
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
	if( (int)me->query("potential") < 1 )
		return notify_fail("你的潜能已经用完了，再怎么读也没用。\n");
	if( (int)me->query("combat_exp") < 1000000 )
		return notify_fail("你的实战经验不足，再怎么读也没用。\n");
	if( me->query("int") < 25 || me->query_int() < 50 )
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
