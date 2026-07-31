// kuihua.c 葵花宝典
// Jay 4/5/96

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}

void create()
{
        set_name("葵花宝典", ({ "kuihua baodian", "baodian", "book"}));
        set_weight(600);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这就是武林第一秘籍《葵花宝典》，相传是一位宫中太监所作。\n");
                set("value", 1);
                set("material", "paper");
                set("no_sell", 1);
        }
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int plvl; 
	int neili_lost;

	if (! arg || !id(arg))
		return 0;

        if (where->query("pigging"))
	{
                write("你还是专心拱猪吧！\n");
                return 1;
        }

        if (me->is_busy())
	{
                write("你现在正忙着呢。\n");
                return 1;
        }

        if (me->is_fighting())
	{
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
        }

	if (where->query("no_fight"))
	{
		write("你无法在这里静下心来研读宝典。\n");
		return 1;
	}

        if ((string)me->query("gender") == "女性")
	{
                write("自古没有听说女人可以读《葵花宝典》的。\n");
                return 1;
        }

        if ((string)me->query("gender") == "男性")
	{
               write("《葵花宝典》的第一页写着：欲练神功，必先自宫。\n");
               return 1;
        }

        if (! me->query_skill("literate", 1))
	{
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

	if (me->query_skill("pixie-jian", 1) >= 180)
	{
		write("这本书你已经研究得差不多了，没什么好读的了。\n");
		return 1;
	}

        switch(random(3))
	{
        case 0:
        	message("vision", me->name() + "偷偷摸摸翻出一本书在读。\n", environment(me), me);
              	break;
        case 1:
        	message("vision", me->name() + "边读书边骚首弄姿，好象在模仿女人。\n", environment(me), me);
                break;
        case 2:
        	message("vision", me->name() + "边读书边把腰身扭来扭去。\n", environment(me), me);
              	break;
        }
        if ((int)me->query("jing") < 30)
	{
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }

	plvl = me->query_skill("pixie-jian", 1);
        if (plvl > 150) neili_lost = 50; else
        if (plvl > 120) neili_lost = 25; else
        if (plvl > 100) neili_lost = 15; else
	if (plvl > 60)  neili_lost = 10;
	            else neili_lost = 5;

        if ((int)me->query("neili") < neili_lost)
	{
		write("你内力不够，无法钻研这么高深的武功。\n");
                return 1;
        }

        if (! me->can_improve_skill("pixie-jian", 1))
	{
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        }

        if (plvl > 199)
	{
                write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
                return 1;
        }

        me->receive_damage("jing", random(15) + 15);
	me->add("neili", -neili_lost);
	me->improve_skill("pixie-jian", random((int) me->query_skill("literate", 1) / 3) + plvl / 5 + 1);
        write("你研读《葵花宝典》，颇有心得。\n");
	me->stary_busy(random(3));
        return 1;
}

