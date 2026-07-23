// jiuyang-zhenjing.c
// Modified by jpei
#include <ansi.h>
inherit ITEM;
mapping *skills = ({
	(["name": "lieyan-dao", "max": 400]),
	(["name": "liehuo-jian", "max": 400]),
	});
void create()
{
	set_name(HIR"九阳真经"NOR, ({"jiuyang zhenjing", "jiuyang", "zhenjing", "book"}));
	set_weight(600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一套四本薄薄的经书。你可以用dujing jiuyang zhenjing来读它。
书后还有一本附本，上面记载着一种刀法（lieyan-dao)，和一种剑法(liehuo-jian)你可以通过翻阅fanyue来看看。\n");
		set("value", 800000);
		set("material", "paper");
		set("no_drop", "这么珍贵的武林秘籍，你可不能随意丢弃！\n");
		set("no_get", "这样东西是那人的宝贝，连睡觉都要当枕头垫，你无法拿取！\n");
                set("treasure", 1);
	}
}

void init()
{
	add_action("do_yandu",({"fanyue"}));
        add_action("do_du", "dujing");
        add_action("do_du", "studyjing");
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int jylevel, neili_lost;

        if (!id(arg)) return 0;

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

        if (!me->query_skill("literate", 1)) {
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }
        
        if (me->query("jing") < 60) {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }
	if (me->query_skill("force",1) < 20) {
		write("你的内功基础没有打好，不能修练九阳神功。\n");
		return 1;
	}
	if (me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("guiyuan-tunafa",1) )
	return notify_fail("你不先散了别派内功，怎能学九阳神功？！\n");


        jylevel = me->query_skill("jiuyang-shengong", 1);
	if (jylevel < 30)
		neili_lost = jylevel / 2;
	else if (jylevel < 70)
		neili_lost = jylevel * 2 / 3;
	else if (jylevel < 120)
		neili_lost = jylevel * 3 / 4;
	else
		neili_lost = jylevel;
	if (jylevel >= (me->query_skill("force", 1) + 30)) {
		write("由于你的内功的火侯不够，不能再获得更高一层的提高。\n");
		return 1;
	}
	if (jylevel / 5 >= me->query_int()) {
		write("由于你的悟性不够，无法进一步研习高一层的九阳神功。\n");
		return 1;
	}
	if (me->query("neili") < neili_lost) {
		write("你内力不够，无法钻研这么高深的武功。\n");
                return 1;
        }
        if (me->query("combat_exp") < jylevel * jylevel * jylevel / 10) {
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        }
	if (jylevel >= 200) {
                write("你已经无法再从经书上领悟到什么，要有更高的修为必须自已练了。\n");
                return 1;
        }
	if (jylevel >= 120 && me->query("neili") < me->query("max_neili") + jylevel) {
                write("这最后一册书上的内容过于深奥，光靠研读而不身体力行是无法再获得进步的。\n");
                return 1;
        }
        me->receive_damage("jing", 50);
        me->add("neili", -neili_lost);
	if (!jylevel) {
		write("你翻开第一册经书，发现上面尽是弯弯曲曲的梵文，但每一行之间却以蝇头小楷写满了中国文字。\n");
		write("你定一定神，从头细看，发现文中所记似是关于练功运气的诀窍。\n");
	        write("你开始研读第一册，上面讲述的是九阳功入门基础。\n");
	}
	if (jylevel >= 120)
	        write("你按照书中所讲打坐一阵，再对照着研读《九阳真经》最后一册，这才有点心得。\n");
	else
	        write("你研读《九阳真经》，颇有心得。\n");
	me->improve_skill("jiuyang-shengong", me->query_skill("literate", 1) / 3 + 1);
	if (!random(5)) message("vision", me->name() + "拿着一本经书正在钻研。\n", environment(me), ({me}));
	if (me->query_skill("jiuyang-shengong", 1) > jylevel) {
		if (jylevel == 29) {
		        write("你读完了第一册，觉得这册上所讲的入门基础很是易学。\n");
		        write("你开始研读第二册，上面讲述的是练气法门。\n");
		}
		else if (jylevel == 69) {
		        write("你读完了第二册，虽然这册上所讲的练气法门有些难度，但是并没有太深奥的地方。\n");
		        write("你开始研读第三册，上面讲述的是运气诀要。\n");
		}
		else if (jylevel == 119) {
		        write("你读完了第三册，这册上所讲的运气诀要颇为艰深，你费了好大的劲才完全理解了。\n");
		        write("你开始研读第四册，上面讲述的已经是十分艰深的内功精要，读起来相当困难。\n");
		}
		else if (jylevel == 199) {
		        write("你终于读完了第四册，揭过最后一页之后，心中又是欢喜，又微微感到怅惘。\n");
		        write("屈指算来，数年的光阴匆匆而过，至今方始功行圆满。\n");
if (!me->query("jiuyangok/con"))
{
			me->add("con", 1);
me->set("jiuyangok/con",1);
}
		}
	}
	return 1;
}
int query_autoload()
{
       return 1;
}
int do_yandu(string arg)
{
	int cost, my_skill, max_level, i, flag = 0;
	string book, skill;
	object me = this_player();
	object where = environment(me);

	if (!arg)
		return notify_fail("你要读什么？\n");
	if (sscanf(arg, "%s %s", book, skill) != 2)
		return notify_fail("指令格式：yandu <书名> <技能>\n");
	if (book != "jiuyang")
		return notify_fail("你要读什么书，这是九阳真经(jiuyang)啊\n");
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
		return notify_fail("也许是缺乏实战经验，你对书上面所说的东西总是无法领会。\n");
	else
		write("你研读着有关" + to_chinese(skill) + "的技巧，似乎有些心得。\n");
	me->improve_skill(skill, ((int)me->query_skill("literate", 1) / 5 + 1));
	me->receive_damage("jing", cost);
	me->add("potential", - random(2));
	return 1;
}
