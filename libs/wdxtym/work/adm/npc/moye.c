// moye.c  莫邪
// Written by Doing Lu  1998/11/2

inherit NPC;
inherit F_NOCLONE;

#include <ansi.h>

int	ask_me();
int	no_money();

#define ITEM_TYPE       0
#define ITEM_STYPE      1
#define ITEM_UNIT       2
#define ITEM_WEIGHT     3
#define ITEM_POINT      4
#define ITEM_PROP       5

static mapping item_type = ([
//      类型	道具类别  继承文件  单位  分量 点数 特殊变量
	"针"   : ({ "weapon", "pin",    "根", 10, 100, 0, }),
	"刀"   : ({ "weapon", "blade",  "把", 150, 100, 0, }),
	"剑"   : ({ "weapon", "sword",  "柄", 150, 100, 0, }),
	"棍"   : ({ "weapon", "club",   "根", 150, 100, 0, }),
	"杖"   : ({ "weapon", "staff",  "根", 150, 100, 0, }),
	"锤"   : ({ "weapon", "hammer", "把", 350, 100, 0, }),
	"斧"   : ({ "weapon", "axe",    "把", 220, 100, 0, }),
	"暗器"   : ({ "weapon", "throwing",    "柄", 220, 100, 0, }),
	"鞭"   : ({ "weapon", "whip",   "根", 150, 100, 0, }),
	
	"短兵" : ({ "weapon", "dagger", "支", 30,  100, 0, }),
	"护甲" : ({ "armor",  "armor",  "张", 150, 80,
		     ([ "armor_prop" : ([ "parry"   : "apply_armor() / 15 + 1",
					  "armor"   : "apply_armor()",
				       ]),
		      ]) }),
	"战衣" : ({ "armor",  "cloth",  "件", 200, 100, 0, }),
	"磨" : ({ "item",  "item",  "个", 200, 100, 0, }),
	"靴子" : ({ "armor",  "boots",  "双", 60,  40,
		     ([ "armor_prop" : ([ "dodge"   : "apply_armor() / 10 + 1",
					  "armor"   : "apply_armor()",
				       ]),
		      ]) }),
	"头盔" : ({ "armor",  "head",   "顶", 75,  50,  0, }),
	"裤子" : ({ "armor",  "pants",  "条", 100,  50,  0, }),
	"腰带" : ({ "armor",  "waist",  "条", 80,  40,  0, }),
	"护腕" : ({ "armor",  "wrists", "对", 50,  25,
		     ([ "armor_prop" : ([ "sword"   : "apply_armor() / 6 + 1",
					  "staff"   : "apply_armor() / 6 + 1",
					  "blade"   : "apply_armor() / 6 + 1",
					  "club"    : "apply_armor() / 6 + 1",
					  "hammer"  : "apply_armor() / 6 + 1",
					  "whip"    : "apply_armor() / 6 + 1",
					  "dagger"  : "apply_armor() / 6 + 1",
					  "stick"   : "apply_armor() / 6 + 1",
					  "unarmed" : "apply_armor() / 6 + 1",
					  "claw"    : "apply_armor() / 6 + 1",
					  "cuff"    : "apply_armor() / 6 + 1",
					  "hand"    : "apply_armor() / 6 + 1",
					  "strike"  : "apply_armor() / 6 + 1",
					  "finger"  : "apply_armor() / 6 + 1",
					  "parry"   : "apply_armor() / 6 + 1",
					  "whip"    : "apply_armor() / 6 + 1",
					  "armor"   : "apply_armor()",
				       ]),
		      ]) }),
	"箫"   : ({ "weapon", "xsword", "支", 30,  100, 0, }),
	"铁掌" : ({ "armor",  "hands",  "双", 45,  100,
		    ([ "armor_prop" : ([ "hand"   : "10",
					 "strike" : "10",
					 "unarmed_damage" : "apply_damage()",
					 "armor"  : "10",
				       ]),
		     ]) }),
	"指套" : ({ "armor",  "hands",  "套", 35,  100,
		    ([ "armor_prop" : ([ "claw"   : "10",
					 "finger" : "10",
					 "unarmed_damage" : "apply_damage()",
					 "armor"  : "10",
				       ]),
		     ]) }),
]);

void create()
{
	set_name("莫邪", ({ "mo ye", "moye", "mo" }));
	set("long", "她长得清美秀丽，一副不食人间烟火的模样。她就是铸剑大师干将的妻子。\n" );

	set("nickname", HIY "剑仙" NOR);
	set("gender", "女性");
	set("attitude", "friendly");

	set("age", 1525);
	set("shen_type", 0);
	
	set("str", 1000);			// 保证不会因为负荷过大而接受不了东西
       set("icon","05005");
	set("inquiry", ([
		
		"打造" : (: ask_me :),
		"钱不够":(: no_money :),
	
		"退货" : "那你就把东西给干将，他来做主。",
		"原料" : "炼制道具可不能没有原料啊，要想炼制好武器就得有"
			 "玄铁石一类的东西。\n	  要想炼制好防具就"
			 "得有天蚕丝那些东西。这些原料很难找，可遇不可求啊！\n",
		"价格" : "你把原料给我看看(show)，我就能估摸出一个价钱。",
	]));

	setup();

	set("startroom", "/d/item/xiaowu");
	check_clone();
	if (! this_object()) return;

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object me;

	// 清除询问标志
	if (! objectp(me = this_player()) || ! interactive(me))
		return;

	add_action("do_show", "show");
	add_action("do_answer", "answer");
	if (me->query_temp("item/status") == "item_gived")
	{
		remove_call_out("greeting2");
		call_out("greeting2", 1, me);
	} else
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}

void greeting(object me)
{
	if (objectp(me) && environment(me) == environment())
	{
		message_vision("$N笑着对$n说：你好，你是想打造道具"
			       "吗？\n", this_object(), me);
	}
}

void greeting2(object me)
{
	if (objectp(me) && environment(me) == environment())
	{
		message_vision("$N对$n说：交钱就可以打造了哦。\n",
			       this_object(), me);
	}
}

int do_show(string arg)
{
	object	me;
	object	ob;
	string	msg;
	string  mat;
	int	power_point;
	int	value;
	int	n;

	me = this_player();
	if (! arg)
		return notify_fail("你想干什么，是要跳个舞么？\n");

	mat = arg;
	power_point = 0;

	if (! objectp(ob = present(mat, me)))
		return notify_fail("算了吧，你身上没有 " + mat + " 这种东西。\n");

	if (! ob->query("material_attrib"))
	{
		message_vision("$N一愣，对$n说道：这种东西也能用来炼"
			       "制，我没听说过。\n", this_object(), me);
	}

	power_point = ob->query("power_point");
	if (! power_point)
	{
		message_vision("$N仔细的看了看$n拿出的原料，叹道："
			       "这样原料看来已经是锻造不了了。\n",
			       this_object(), me);
		return 1;
	}
	value = power_point * 2 + 10;
	msg = sprintf("$N仔细看了看$n拿出的原料，说道：这种原料打造道具，只需要%s两黄金，怎么样，我们价格很合理吧？\n" +
                      "要是没问题，请给我原料并付钱。\n" +
                      "我顺便提醒你一句：在打造过程中，你若要帮忙提高装备品质，你的当前内力和最大内力不能低于200点。\n", chinese_number(value));
	message_vision(msg, this_object(), me);

	return 1;
}

// 发出提示信息
int ask_me()
{
	message_vision("$N对$n说道：" 
		"你是要打造自己的道具吗？\n"
		"我们这里可以为你打造各种武器包括刀、剑、锤、鞭、杖和护甲，都是第一流的。\n"
		"你先把原料给我看看，我先估算一下价钱。如果你满意咱们就一手交钱，一手交货！\n", this_object(), this_player());
	return 1;
}

int no_money()
{
	object me;
	object ob;

	me = this_player();
	if (me->query_temp("item/status") == "item_gived")
	{
		message_vision("$N打量了一下$n道：没钱那就下次吧！\n",
			       this_object(), me);
		if (objectp(ob = query_temp("item/accept")))
		{
			message_vision("$N把" + ob->name() + "交还给$n。\n", this_object(), me);
			if (! ob->move(me))
				ob->move(environment());
		}
		delete_temp("item");
		me->delete_temp("item");
		return 1;
	}

	message_vision("$N眼睛一瞪，对$n说道：没钱？你没钱关我啥事，"
		       "我又不是财神爷。\n", this_object(), me);
	return 1;
}

// 接受定金
int accept_object(object me, object ob)
{
	string status,str;
	int    i,val;

	status = query_temp("item/status");
	if (status == "look_working")
	{
		message_vision("$N紧张的对$n说：别吵，干将正在干活呢。\n",
			       this_object(), me);
		return 0;
	}

	if (status == "waiting")
	{
		if (query_temp("item/player_id") == me->query("id"))
		{
			command("say 你好好和干将谈，少打岔！");
			return 0;
		}

		message_vision("$N对$n说：别吵，干将正在和顾客谈话呢。\n",
			       this_object(), me);
		return 0;
	}

	if (status == "accept")
	{
		if (query_temp("item/player_id") != me->query("id"))
		{
			command("say 我正在和别的客人商量呢，你先别添乱！");
			return 0;
		}

		if (! ob->query("money_id"))
		{
			command("say 你还是快点交钱吧，要是没钱就明说！");
			return 0;
		}
	}

	if (ob->query("material_attrib") &&
	    ob->query("power_point"))
	{
		// 计算价值
		val = ob->query("power_point") * 2 + 10;
		message_vision("$N对$n说道：很好，用这块原料打造道具需要" +
			       chinese_number(val) + "两黄金，交钱吧。\n",
			       this_object(), me);
		val *= 10000;
		if (wizardp(me))
		{
			message_vision("$N仔细看了看$n，笑着说道：原"
				       "来是巫师，那么你随便给点好了。\n",
				       this_object(), me);
			val = 1;
		}
		ob->set("item/value", val);
		me->set_temp("item/status", "item_gived");
		me->set_temp("item/value", val);
		set_temp("item/status", "accept");
		set_temp("item/player_id", me->query("id"));
		set_temp("item/accept", ob);

		// 如果过一段时间没有交款，还道具粗坯
		remove_call_out("time_out");
		call_out("time_out", 30, me, ob);
		return 1;
	}

	if (ob->query("money_id"))
	{
		object origin;
		mixed p;
		string *types;

		if (me->query_temp("item/status") == "answer_type")
		{
			message_vision("$N摇摇头，对$n说：快说你要做什么东西！\n",
				       this_object(), me);
			return 0;
		}

		if (me->query_temp("item/status") != "item_gived")
		{
			message_vision("$N把$n递过去的" + ob->name() +
				       "推了回来，道：无功不受禄！\n",
				       this_object(), me);
			return 0;
		}

		if (ob->value() < me->query_temp("item/value"))
		{
 			message_vision("$N对$n说：对不起，本店开张一"
				       "千多年来，还没有打过折扣。\n",
				       this_object(), me);
			return 0;
		}

		origin = query_temp("item/accept");
		if ((p = origin->query("can_make")) == "all")
		{
			types = keys(item_type);
		} else
		if (arrayp(p))
			types = p;
		else
		if (stringp(p))
			types = ({ p });

		p = origin->query("not_make");
		if (arrayp(p))
			types -= p;
		else
		if (stringp(p))
			types -= ({ p });

		set_temp("item/types", types);
		set_temp("item/money", ob);
		ob->move(this_object());

		str = ZJOBLONG"莫邪对你说：好，这就给你炼！你打算打造什么东西，请告诉我类型：\n"ZJOBACTS2+ZJMENUF(4,4,9,30);
		for(i=0;i<sizeof(types);i++)
		{
			str += types[i]+":answer "+types[i]+ZJSEP;
		}
		write(str+"\n");

		me->set_temp("item/status", "answer_type");
		return -1;
	}

	message_vision("莫邪眼睛一瞪，对$N说道：你给我这些东西干什么？我不要！\n", me);
	return 0;
}

int do_answer(string arg)
{
	object money;
	object ob;
	object me;
	object ganjiang;

	me = this_player();
	if (me->query_temp("item/status") != "answer_type")
		return 0;

	if (! arg)
		return notify_fail("你要回答什么？\n");

	message_vision("$n对$N道：就打造" + arg + "吧！\n",
		       this_object(), me);

	if (member_array(arg, query_temp("item/types")) == -1 ||
	    undefinedp(item_type[arg]))
	{
		message_vision("$N“啊秋”一下打了个喷嚏，一脸无辜的看着$n。\n",this_object(), me);
		return 1;
	}

	// 如果干将不在
	if (! objectp(ganjiang = present("gan jiang",environment(this_object()))))
	{
		message_vision("$N看了看四周，不禁一呆，说道：干将呢"
			       "？他不在，没办法做了...你改天再来吧。\n",
			       this_object());
		if (ob = query_temp("item/accept"))
		{
			message_vision("$N把" + ob->name() + "交还给$n。\n",
				       this_object(), me);
			if (! ob->move(me))
				ob->move(environment());
		}
		delete_temp("item");
		me->delete_temp("item");
		return 0;
	}

	if (objectp(money = query_temp("item/money")))
		destruct(money);
	delete_temp("item/money");
	set_temp("item/status", "look_working");
	me->set_temp("item/status", "waiting");
	ob = query_temp("item/accept");
	ob->set("item/ctype", arg);
	ob->set("item/type", item_type[arg][ITEM_TYPE]);
	ob->set("item/stype", item_type[arg][ITEM_STYPE]);
	ob->set("item/unit", item_type[arg][ITEM_UNIT]);
	ob->set("item/point", ob->query("power_point") * item_type[arg][ITEM_POINT] / 100);
	ob->set("item/owner", me);
	ob->set("item/owner_id", me->query("id"));
	ob->set("item/owner_name", me->name(1));
	ob->set("item/wscale", item_type[arg][ITEM_WEIGHT]);
	ob->set("item/prop", item_type[arg][ITEM_PROP]);
	message_vision("$N把" + ob->name() + "交给了$n。\n",
		       this_object(), ganjiang);
	if (! ob->move(ganjiang))
		error("Can move the object to ganjiang.");
	remove_call_out("time_out");
	ganjiang->accept_object(this_object(), ob);
	return 1;
}

void time_out(object me, object ob)
{
	object money;
	int at_present;

	money = query_temp("item/money");

	if (! objectp(me))
		me = find_player(query_temp("item/player_id"));

	if (! objectp(me) || environment(me) != environment())
	{
		command("say 奇怪，刚才那位客人呢？怎么这就走了？\n");
		at_present = 0;
	} else
	{
		command("say 你慢慢犹豫吧，我可不能跟你耗着！想好再来吧！");
		at_present = 1;
	}

	delete_temp("item");
	if (objectp(me))
		me->delete_temp("item");

	if (money)
	{
		if (at_present)
			command("give " + money->query("id") +
				" to " + me->query("id"));

		if (environment(money) == this_object())
			command("drop " + money->query("id"));
	}

	if (ob)
	{
		if (at_present)
			command("give " + ob->query("id") +
				" to " + me->query("id"));

		if (environment(ob) == this_object())
			command("drop " + ob->query("id"));
	}
}
