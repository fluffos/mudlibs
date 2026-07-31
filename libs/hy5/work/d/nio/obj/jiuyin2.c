// jiuyin2.c 九阴真经下卷

inherit ITEM;

int do_study(string arg);

void create()
{
	set_name("九阴真经下卷", ({ "jiuyin xiajuan", "jiuyin", "xiajuan", "renpi"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "这是一张人皮，上面刺着武学秘籍《九阴真经》的下卷，记述的都只是实战中的招式法门，却并无心法和口诀。第一页上写着：天之道，损有余而补不足，是故虚胜实，不足胜有余。相传是宋徽宗年间一位叫黄裳的所作。\n");
		set("value", 40000);
		set("material", "leather");
		set("no_drop", "这么珍贵的武林秘籍，你可不能随意丢弃！\n");
		set("no_get", "这样东西是那人的宝贝，连睡觉都要当枕头垫，你无法拿取！\n");
	}
}

void init()
{
	add_action("do_study", "du");
	add_action("do_study", "study");
}

int do_study(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int i, level, *levels = ({0,0,0,0}), *can = ({0,0,0,0}); 
	int cost, neili_lost, neili_adjust;

	if (!(arg=="jiuyin xiajuan" || arg == "jiuyin" || arg == "xiajuan" || arg == "renpi"))
		return 0;

	if (where->query("pigging")){
		write("你还是专心拱猪吧！\n");
		return 1;
        }
	if (me->is_busy()) {
		write("你现在正忙着呢。\n");
		return 1;
	}

	if( me->is_fighting() ) {
		write("你无法在战斗中专心下来研读新知！\n");
		return 1;
	}

/*        if(!arg || !objectp(ob = present(arg, me)) ){
                write("你要读什么？\n");
                return 1;
        }
*/
	if (!id(arg)) {	
		write("你要读什么？\n");
		return 1;
	}
	if( !me->query_skill("literate", 1) ){
		write("你是个文盲，先学点文化(literate)吧。\n");
		return 1;
	}

	cost = 30 + 30 * (25 - me->query("int"))/20;
	if (cost < 10) cost = 10; // minimum cost

	if (arg == "jiuyin" && present("jiuyin shangjuan", me)) {
		if (!random(5)) message("vision", me->name() + "专心致志地拿着一本经书与一张人皮对照研究着。\n", environment(me), me);
		if( (int)me->query("jing") < cost * 5 ) {
			write("你现在过于疲倦，无法专心下来研读新知。\n");
			return 1;
		}

		neili_adjust = 0;
		levels[ 0 ] = me->query_skill("force", 1);
		levels[ 1 ] = me->query_skill("dodge", 1);
		levels[ 2 ] = me->query_skill("parry", 1);
		levels[ 3 ] = me->query_skill("sword", 1);
		for (i = 0; i < 4; i++)
		{
			if (levels[i] > 80) neili_lost = 15;
			else if (levels[i] > 60) neili_lost = 10;
			else neili_lost = 5;

			if ((int)me->query("neili") + neili_adjust >= neili_lost) {
				neili_adjust -= neili_lost;
				can[i] = 1;
			}
			if (can[i] > 0 && (int)me->query("combat_exp") < (int)levels[i]*levels[i]*levels[i]/10) {
				neili_adjust += neili_lost;
				can[i] = -1;
			}
			if (can[i] > 0 && levels[i] > 99) {
				neili_adjust += neili_lost;
				can[i] = -2;
			}
		}
		if (can[0] <= 0 && can[1] <= 0 && can[2] <= 0 && can[3] <= 0) {
			if (can[0] == -2 && can[1] == -2 && can[2] == -2 && can[3] == -2) {
				write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
				return 1;
			}
			else {
				write("你的内力以及实战经验不够，无法钻研这么高深的武功。\n");
				return 1;
			}
		}

		me->add("neili", neili_adjust);
		write("你研读《九阴真经》，于武学的认识更深了一层。\n");
		if (can[0]) {
			me->receive_damage("jing", cost + 5);
			if(!levels[0]) me->set_skill("force", 0);
			me->improve_skill("force", (int)me->query_skill("literate", 1)/4+1);
		}
		if (can[1]) {
			me->receive_damage("jing", cost + 3);
			if(!levels[1]) me->set_skill("dodge", 0);
			me->improve_skill("dodge", (int)me->query_skill("literate", 1)/5+1);
		}
		if (can[2]) {
			me->receive_damage("jing", cost);
			if(!levels[2]) me->set_skill("parry", 0);
			me->improve_skill("parry", (int)me->query_skill("literate", 1)/5+1);
		}
		if (can[3]) {
			me->receive_damage("jing", cost + 2);
			if(!levels[3]) me->set_skill("sword", 0);
			me->improve_skill("sword", (int)me->query_skill("literate", 1)/5+1);
		}
        }
	else {
		if (!random(5)) message("vision", me->name() + "专心致志地研究一张人皮。\n", environment(me), me);
		if( (int)me->query("jing") < cost ) {
			write("你现在过于疲倦，无法专心下来研读新知。\n");
			return 1;
		}

		level = me->query_skill("taoism", 1);
		if (level > 80) neili_lost = 15;
		else if (level > 60) neili_lost = 10;
		else neili_lost = 5;

		if ((int)me->query("neili") < neili_lost) {
			write("你内力不够，无法钻研这么高深的道学。\n");
			return 1;
		}

		if (level > 99) {
			write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
			return 1;
		}

		me->receive_damage("jing", cost);
		me->add("neili", -neili_lost);
		if(!level) me->set_skill("taoism", 0);
		write("你研读《九阴真经》下卷，领悟了一些道学知识。\n");
		me->improve_skill("taoism", (int)me->query_skill("literate", 1)/4+1);
	}
	return 1;
}
