// parrot.c 鹦鹉
// Lklv modify 2001.10.18

#include <ansi.h>

inherit NPC;

string ask_name();
string ask_caishen();
string ask_password();
string ask_greatwall();

//string keep_msg = 0;
object follow_ob = 0;
int password_try = 0;

void create()
{
	set_name("鹦鹉", ({ "ying wu", "parrot", "yingwu" }) );
	set("race", "野兽");
	set("gender", "雄性" );
	set("age", 2);
	set("long", "一只会说话的小绿鹦鹉。\n");
	set("attitude", "peaceful");

	set("limbs", ({ "头部", "身体", "翅膀", "尾部" }) );
	set("verbs", ({ "claw", "poke" }) );

	set("str", 15);
	set("dex", 30);
	set("con", 15);
	set("int", 20);

	set("combat_exp", 800);

	set_skill("dodge", 500);

	set_temp("apply/attack", 6);
	set_temp("apply/defense", 6);
	set_temp("apply/dexerity", 100);
	set_temp("apply/armor", 3);

	set("inquiry", ([
		"name": (: ask_name :),
		"rumors": "听说日本人也在寻找瑞士银行那个帐户的密码。",
		"here": "我又不是人，怎么知道？！",
		"寒雨": "说起来也是他创造了我，不过这家伙是个造ｑｕｅｓｔ狂。",
		"jpei": "说起来也是他创造了我，不过这家伙是个造ｑｕｅｓｔ狂。",
		"暗号" : "这都不知道？去看《富贵兵团》！",
		"帐户" : "先对上暗号再告你密码！",
		"财神" : (: ask_caishen :),
		"万里长城万里长": (: ask_greatwall :),
		"密码": (: ask_password :),
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command, "!!!" :),
	}));
	set("chat_chance", 3);
	set("chat_msg", ({
		(: command, "chicken" :),
	}));

	set("race", "飞禽");
	set("can_speak", 1);
	setup();
}

void init()
{
	object ob = this_player();

	::init();
	add_action("do_let", "let");
	if ((!follow_ob || !objectp(follow_ob) || !random(10)) && userp(ob)&&!wizardp(ob)) {
		command("follow " + ob->query("id"));
		follow_ob = ob;
	}
	if (objectp(follow_ob) && !present(follow_ob, environment(this_object())))
		call_out("continue_follow", 1, follow_ob);
}

int continue_follow(object ob)
{
	if (objectp(ob) && !present(ob, environment(this_object()))) {
		say("鹦鹉忽然振翅飞走了。\n");
		move(environment(ob));
		message_vision("鹦鹉飞了过来，停在$N的肩膀上。\n", ob);
	}
}

int do_let(string arg)
{
	object ob = this_player();
	string myid, todie;

	if (!arg || sscanf(arg, "%s %s", myid, todie) < 2)
		return notify_fail("你想做什么？\n");
	if (!id(myid)) return notify_fail("你想谁做什么？\n");
	if (todie != "to die" && todie != "去死" && todie != "die")
		return notify_fail("你想让鹦鹉做什么？\n");
	if (ob != follow_ob) return notify_fail("鹦鹉才不理你呢！\n");
	message_vision("$N对着鹦鹉喝道：“你去死吧！”\n", ob);
	command("inn " + ob->query("id"));
	command("deadlove parrot");
	die();
	return 1;
}

void relay_say(object ob, string msg)
{

	if (!msg) return;
	say(CYN + "鹦鹉重复道：「" + msg + "」\n" + NOR);
}

void relay_emote(object me, string arg)
{
	switch (arg) {
		case "die":
		case "idle":
		case "sure":
		case "lazy":
		case "xbc97":
		case "smell":
		case "bored":
		case "escape":
		case "chicken":
		case "laughproud":
		case "nonsense":
			command(arg);
			break;
		case "waggle":
		case "willbe":
		case "pain":
		case "push":
		case "puke":
		case "poke":
		case "stare":
		case "admit":
		case "rascal":
		case "story":
		case "crazy":
		case "thank":
		case "name1":
		case "disapp":
		case "disapp1":
		case "accuse":
		case "homework":
		case "papaya":
		case "benger":
		case "sue":
		case "regard":
		case "courage":
		case "meeting":
		case "pat":
		case "pig":
		case "piggy":
		case "flower":
		case "joke":
		case "sigh":
		case "poor":
		case "ugly":
		case "rabbit":
		case "pretty":
		case "knife1":
		case "grpfight":
		case "points":
		case "congra":
		case "sing3":
		case "lover":
		case "nocry":
		case "flatter":
		case "rabbit2":
		case "goodkid":
		case "fire":
		case "boat":
			command(arg + " parrot");
			break;
		case "interest":
			command("liar");
			break;
		case "slow":
			command("lover");
			break;
		case "shout":
			command("peace");
			break;
		case "bug":
		case "cook":
			command("taste");
			break;
		case "hero":
		case "hehe":
			command("fear");
			break;
		case "cold":
		case "sing2":
		case "magic":
		case "taste":
			command("escape");
			break;
		case "inn":
		case "sorry":
		case "careful":
			command("sneer");
			break;
		case "kick":
		case "slap":
		case "trip":
			command("pain");
			break;
		case "fire1":
		case "swear":
			command("shake");
			break;
		case ":)":
		case "haha":
		case "xixi":
		case "laugh":
		case "hehehe":
		case "giggle":
			command("nosmile");
			break;
		case "claw":
			command("cry");
			break;
		case "!!!":
		case "gun":
		case "club":
		case "hug":
		case "drug":
		case "doubt":
		case "makeup":
			command("corpse parrot");
			break;
		case "shameless":
			command("hate parrot");
			break;
		case "admire":
			command("humble parrot");
			break;
		case "joythank":
			command("thank parrot");
			break;
		case "rhero":
			command("shout parrot");
			break;
		case "poem":
			command("raise parrot");
			break;
		case "slogan":
			command("slogan2 parrot");
			break;
		case "angry":
			command("stare parrot");
			break;
		case "happy":
			command("rich parrot");
			break;
		case "dare":
			command("points parrot");
			break;
		case "lick":
			command("smell parrot");
			break;
		case ":(":
		case "cry":
			command("nocry " + me->query("id"));
			break;
		case "xigua":
			command("xigua2 " + me->query("id"));
			break;
		case "nod":
			command("shake " + me->query("id"));
			break;
		case "shake":
			command("nod " + me->query("id"));
			break;
		case "blush":
			command("lover " + me->query("id"));
			break;
		case "monk":
			command("buddhi " + me->query("id"));
			break;
		case "hungry":
			command("rich " + me->query("id"));
			break;
		case "slapsb":
			command("inn " + me->query("id"));
			break;
		case "wait":
			command("nomatch " + me->query("id"));
			break;
		case "lean":
			command("hug " + me->query("id"));
			break;
		case "god":
			command("comfort " + me->query("id"));
			break;
		case "faint":
			command("nofear " + me->query("id"));
			break;
		case "wanfu":
			command("bow " + me->query("id"));
			break;
		case "innocent":
			command("goodman " + me->query("id"));
			break;
		case "yawn":
			command("zzz " + me->query("id"));
			break;
		case "visit":
			command("welcome " + me->query("id"));
			break;
		case "welcome":
			command("visit " + me->query("id"));
			break;
		case "brag":
			command("gun " + me->query("id"));
			break;
		case "dunno":
			command("disapp " + me->query("id"));
			break;
		case "hmm":
			command("? " + me->query("id"));
			break;
		case "poem3":
			command("willbe " + me->query("id"));
			break;
		case "zzz":
			command("shutup " + me->query("id"));
			break;
		case "nomatch":
			command("mother " + me->query("id"));
			break;
		case "nofear":
			command("chicken " + me->query("id"));
			break;
		case "meet":
		case "smell1":
			command("seduce " + me->query("id"));
			break;
		case "rose":
		case "kiss1":
			command("kiss " + me->query("id"));
			break;
		case "rich":
		case "protect":
			command("joythank " + me->query("id"));
			break;
		case "hammer":
		case "killair":
			command("peace " + me->query("id"));
			break;
		case "uncle":
		case "anniversary":
			command("sure " + me->query("id"));
			break;
		case "cut":
		case "corpse":
		case "soup":
		case "smash":
		case "slash":
		case "knife":
			command("peace1 " + me->query("id"));
			break;
		case "thumb":
		case "mother":
		case "praise":
		case "goodman":
		case "applaud":
		case "handsome":
			command("noshame " + me->query("id"));
			break;
		case "bf":
		case "gf":
		case "chitchat":
			command("nonsense " + me->query("id"));
			break;
		case "wave":
		case "bye":
		case "byebye":
		case "goodbye":
			command("slow " + me->query("id"));
			break;
		case "rob":
		case "fat":
		case "dumb":
		case "uncle":
		case "u&me5":
		case "congra1":
		case "marriage":
			command("faint " + me->query("id"));
			break;
		case "love":
		case "lovelook":
		case "loveshoe":
		case "deadlove":
		case "ghostlove":
		case "joycup":
		case "touch1":
		case "wink":
		case "u&me2":
		case "xigua2":
		case "sex":
		case "seduce":
		case "doufu":
		case "oath":
		case "flirt":
			command("puke " + me->query("id"));
			break;
		case "nosmile":
		case "brother":
		case "massage":
			command("goodkid " + me->query("id"));
			break;
		case "ysis":
		case "sister":
		case "aunt":
		case "18mo":
		case "beauty1":
		case "shajiabang1":
			command("uncle " + me->query("id"));
			break;
		case "bite":
		case "grin":
		case "hate":
		case "consider":
			command("fear " + me->query("id"));
			break;
		case "flush":
		case "u&me1":
		case "kill1":
		case "callname":
			command("shout " + me->query("id"));
			break;
		case "agree":
		case "u&me":
		case "raise":
			command("u&me5 " + me->query("id"));
			break;
		default:
			command(arg + " " + me->query("id"));
			break;
	}
}

int return_home(object home)
{
	// At home already?
	if (!environment() || environment()==home)
		return 1;

	// Able to leave?
	if (!living(this_object()) || is_fighting()) return 0;

	if (!follow_ob || !objectp(follow_ob)) {
		message("vision", this_object()->name() + "急急忙忙地飞走了。\n",
			environment(), this_object());
		if (move(home)) {
			message("vision", this_object()->name() + "急急忙忙地飞了过来。\n",
				environment(), this_object());
			return 1;
		}
		return 0;
	}
	return 1;
}

string ask_name()
{
	if (this_player()->query_temp("parrot"))
		return "我就是财神。";
	else
		return "你没搞错吧？鹦鹉也有名字吗？";
}

string ask_password()
{
	if (this_player()->query_temp("parrot"))
		return "密码虽然长，但是很好记：43420 024 420 念八遍。";
	else {
		if (password_try < 16012345) password_try += random(10) + 1;
		return "什么密码？master的登录密码吗？我试了" + chinese_number(password_try) + "次了，还没试出来....";
	}
}

string ask_caishen()
{
	if (this_player()->query_temp("parrot"))
		return "财神就是我。";
	else
		return "想发财想疯了？！";
}

string ask_greatwall()
{
	this_player()->set_temp("parrot", 1);
	return "齐心合力建家乡。";
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N正想对鹦鹉下毒手，忽然被人踢了个跟头，一个动物保护主义者喝道：“请爱护小动物！”\n", ob);
}

int accept_fight(object ob)
{
	message_vision("鹦鹉对着$N大叫：“" + RANK_D->query_rude(ob) + "，有本事杀我呀！”\n", ob);
	return 0;
}
