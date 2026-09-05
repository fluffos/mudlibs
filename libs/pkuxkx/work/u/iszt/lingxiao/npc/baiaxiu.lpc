// baiaxiu.c
// Created by iszt@pkuxkx, 2007-02-23

#include "setdizi.h"

int do_qiangjian(string arg);
int get_favor(object me);
void set_favor(object me, int favor);
void add_favor(object me, int favor);
void relay_emote(object me, string verb);

void create()
{
	setcreate(-2);
	set_name("白阿绣", ({ "bai axiu", "bai", "axiu", "xiu" }) );
	set("gender", "女性" );
	set("age", 14);
	set("long", "她是白万剑的独生女，颇有些娇羞忸怩，一张瓜子脸，清丽文秀，\n"
	"白玉般的脸颊说不出的娇美动人。\n");
	set("per", 28);

	set("rank_info/respect", "姑娘");
	set("rank_info/rude", "小贱人");
	add("inquiry", ([
		"name" : "我叫阿绣，我爹爹姓白，我自然也姓白啦。\n",
		"rumors" : "一次爷爷醉后对我说起，窗外的绝壁中似乎有什么秘密，和爷爷的内功有关。\n",
		"here" : "这里是我的房间，你进来做什么？\n",
	]) );
	setfamily(6);

	setup();
	setequip();
}

void init()
{
	add_action("do_qiangjian", "qiangjian");
}

int do_qiangjian(string arg)
{
	object me = this_player();
	message_vision("$N强奸了阿绣。\n", me);
	return 1;
}

int get_favor(object me)
{
	return query("favor/" + me->query("id"));
}

void set_favor(object me, int favor)
{
	set("favor/" + me->query("id"), favor);
	return;
}

void add_favor(object me, int favor)
{
	add("favor/" + me->query("id"), favor);
	return;
}

void relay_emote(object me, string verb)
{
	object ob = this_object();
	int favor = get_favor(me);
	string id = me->query("id");
	object* inv;
	string respect = RANK_D->query_respect(me);

	//determine whether verb is the same as the last one
	if(verb == me->query_temp("lingxiao/last_verb_to_axiu"))
	{
		if(favor < 4)
			message_vision(CYN"$n奇怪的看着$N，不知道想说些什么。\n"NOR, me, ob);
		else if(favor < 10)
			message_vision(CYN"$n奇道：「你这一遍一遍的不烦么？」\n"NOR, me, ob);
		else if(favor > 40)
			message_vision(CYN"$n看着$N，一脸幸福。\n"NOR, me, ob);
		return;
	}
	me->set_temp("lingxiao/last_verb_to_axiu", verb);

	//make the emote list shorter, e.g. zt == zt1 == zt2 == zt3......
	verb = replace_string(verb, "1", "");
	verb = replace_string(verb, "2", "");
	verb = replace_string(verb, "3", "");
	verb = replace_string(verb, "4", "");
	verb = replace_string(verb, "5", "");
	verb = replace_string(verb, "6", "");
	verb = replace_string(verb, "7", "");
	verb = replace_string(verb, "8", "");
	verb = replace_string(verb, "9", "");
	verb = replace_string(verb, "0", "");
	verb = replace_string(verb, "x", "");
	verb = replace_string(verb, "fy", "");

	//make responses according to verb
	switch(verb)
	{
	case "hi":
		if(favor < 2)
		{
			message_vision(CYN"$n微微一笑，向着$N盈盈道了个万福。\n"NOR, me, ob);
			add_favor(me, 1);
		}
		else if(favor < 10)
		{
			message_vision(CYN"$n嗔道：「你不停的问我好，是不是有什么企图？」\n"NOR, me, ob);
			add_favor(me, -1);
		}
		else
			message_vision(CYN"$n嗔道：「怎地你对我还是如此生分？」\n"NOR, me, ob);
		break;
	case "mm":
	case "pat":
		if(favor < 10)
		{
			message_vision(CYN"$n满面通红，躲了开去。\n"NOR, me, ob);
			add_favor(me, -1);
		}
		else if(favor < 18)
			message_vision(CYN"$n略带害羞的低下头。\n"NOR, me, ob);
		else
		{
			message_vision(CYN"$n微微一笑，略带害羞的低下头。\n"NOR, me, ob);
			add_favor(me, 1);
		}
		break;
	case "kill":
	case "killair":
		if(favor < 10)
		{
			command("fear");
			message_vision(CYN"$n满面惊恐的看着$N，惊叫道：「不要！不要！」\n"NOR, me, ob);
			add_favor(me, -2);
		}
		else
		{
			command("fever " + id);
			add_favor(me, -1);
		}
		break;
	case "protect":
		if(favor < 4)
		{
			message_vision(CYN"$n嫣然一笑，对$N道：「不敢劳烦这位"+respect+"。」\n"NOR, me, ob);
		}
		else if(favor < 10)
		{
			message_vision(CYN"$n笑道：「你当我是寻常弱女子，还需要保护么？」\n"NOR, me, ob);
			add_favor(me, -1);
		}
		else
		{
			command("foll " + id);
			add_favor(me, 1);
		}
		break;
	case "kiss":
	case "mo":
	case "hug":
		if(favor < 8)
		{
			message_vision(CYN"$n柳眉倒竖，怒道：「无耻好色之徒，竟敢如此轻薄于我！」\n"NOR, me, ob);
			ob->kill_ob(me);
			add_favor(me, -10);
		}
		else if(favor < 14)
		{
			command("blush " + id);
			message_vision(CYN"$n\n"NOR, me, ob);
		}
		else
		{
			if(random(2))
				command("kiss " + id);
			command("lean " + id);
			add_favor(me, 1);
		}
		break;
	case "mapi":
	case "flatter":
	case "praise":
	case "beauty":
	case "zeze":
		if(favor < 4)
		{
			message_vision(CYN"$n皱了皱眉，不过毕竟有人赞她，显然也不如何生气。\n"NOR, me, ob);
		}
		else if(favor < 12)
			message_vision(CYN"$n笑笑，不置可否。\n"NOR, me, ob);
		else
		{
			message_vision(CYN"$n被$N新鲜的情话逗的花枝乱颤，显是芳心暗喜。\n"NOR, me, ob);
			add_favor(me, 1);
		}
		break;
	case "slap":
	case "kick":
	case "callname":
	case "cuo":
	case "hate":
	case "cook":
	case "cut":
	case "corpse":
	case "die":
	case "brag":
	case "t":
		if(favor < 10 && random(2))
		{
			message_vision(CYN"$n呜呜的哭了起来：「你欺负我！我告诉爷爷去。」\n"NOR, me, ob);
			add_favor(me, -2);
		}
		else if(favor < 10)
		{
			message_vision(CYN"但见$n眼睛红了一圈，不发一言，提了长剑向$N冲来！\n"NOR, me, ob);
			ob->kill_ob(me);
			add_favor(me, -3);
		}
		else if(favor < 18)
		{
			command("boring " + id);
			add_favor(me, -1);
		}
		else
		{
			command("why " + id);
			add_favor(me, -1);
		}
		break;
	case "fight":
		if(favor < 15)
			message_vision(CYN"$n抱拳道：「"+respect+"武功惊人，小女子极是拜服，还是不用比了。」\n"NOR, me, ob);
		else
			message_vision(CYN"$n微微笑道：「你我之间还比划什么？」\n"NOR, me, ob);
		break;
	case "nocloth":
	  	inv = filter_array(all_inventory(ob),(:$1->query("equipped")=="worn":));
		inv -= ({0});
		if(favor < 20)
		{
			message_vision(CYN"$n大惊，忙低头检查自己身上的衣衫，"NOR, me, ob);
			if(sizeof(inv))
			{
				message_vision(CYN"却发现丝毫没有凌乱的痕迹。\n"NOR, me, ob);
				command("faint " + id);
				add_favor(me, -2);
			}
			else
			{
				message_vision(CYN"脸「唰」的红了起来。\n"NOR, me, ob);
				command("wuwu");
				message_vision(CYN"$n带着泪痕怒叱道：「淫贼，你毁我清白，我跟你拼了！」\n"NOR, me, ob);
				ob->kill_ob(me);
				add_favor(me, -12);
			}
		}
		else
			message_vision(CYN"$n娇笑道：「讨厌！都是你干的啦！」\n"NOR, me, ob);
		break;
	case "pai":
		if(favor < 14)
			command("0");
		else
		{
			message_vision(CYN"$n泪眼盈盈：「你真的不要我了么？」\n"NOR, me, ob);
			add_favor(me, random(2));
		}
		break;
	case "lie":
	case "liar":
	case "norumor":
	case "rumor":
	case "zaoyao":
	case "selang":
	case "rascal":
		if(random(2))
			command("inn " + id);
		else
			command("done");
		add_favor(me, random(3)-1);
		break;
	case "tigermount":
		message_vision(CYN"$n皱皱眉，看来把这满口不明不白的$N当成怪物了。\n"NOR, me, ob);
		add_favor(me, -1);
		break;
	case "sword":
	case "zt":
	case "zhutou":
	case "pig":
	case "wenmang":
		if(favor < 9)
			command("disagree " + id);
		else if(favor < 14)
		{
			command("zt3 " + id);
			message_vision(CYN"$n指着$N笑道：「好新鲜的猪头！」\n"NOR, me, ob);
			add_favor(me, random(2));
		}
		else
		{
			message_vision(CYN"$n笑着追$N，粉拳不停的捶在$N的背上。\n"NOR, me, ob);
			add_favor(me, 1);
		}
		break;
	case "yi":
		if(favor < 5)
			command("what " + id);
		else if(favor < 12)
		{
			command("missu " + id);
			add_favor(me, 1);
		}
		else
		{
			command("patfy " + id);
			message_vision(CYN"$n显然是把$N当自己的外甥了。\n"NOR, me, ob);
		}
		break;
	case "over":
	case "nomatch":
	case "weak":
	case "shuang":
		command("notell ");
		break;
	case "shake":
		command("say 你吃了什么药了，怎么只会摇头么？");
	case "ah":
	case "0":
		if(favor < 12)
		{
			command("la " + id);
			add_favor(me, random(3)-1);
		}
		else
		{
			message_vision(CYN"$n假装生气的了撅嘴，「噗哧」一声笑了出来。\n"NOR, me, ob);
			add_favor(me, random(2));
		}
		break;
	case "fadai":
	case "idle":
		if(favor < 16)
			command("boring " + id);
		add_favor(me, random(3)-1);
		break;
	case "rpwt":
	case "badrp":
	case "sigh":
		if(favor < 6)
		{
			message_vision(CYN"$n淡然一笑，摇了摇头。\n"NOR, me, ob);
			add_favor(me, -1);
		}
		else if(favor < 22)
		{
			command("notell");
			message_vision(CYN"$n淡然一笑，摇了摇头。\n"NOR, me, ob);
			add_favor(me, random(3)-1);
		}
		else
		{
			command("qifu " + id);
			command("xixi");
			add_favor(me, 1);
		}
		break;
	case "bye":
	case "goodbye":
	case "byebye":
		if(favor < 5)
			command("wave" + id);
		else if(favor < 14)
		{
			command("slow " + id);
			add_favor(me, 1);
		}
		else
		{
			command("lonely");
			add_favor(me, -1);
		}
		break;
	case "ks":
	case "pei":
	case "chan":
		if(favor < 12)
		{
			message_vision(CYN"总算$n修养还好，只是感到厌烦的转过身去，不再理$N。\n"NOR, me, ob);
			add_favor(me, -1);
		}
		else
			command("taoyan");
		break;
	case "yao":
	case "beg":
		if(favor < 6)
			command("nobeg " + id);
		else if(favor < 20)
		{
			command("nobeg");
			add_favor(me, random(3)-1);
		}
		else if(favor < 22)
			command("west1");
		else
		{
			command("lean " + id);
			add_favor(me, 2);
		}
	case "laugh":
	case "smile":
	case "ii":
	case "haha":
	case "hoho":
	case "he":
		if(favor < 4)
		{
			command("xixi");
			add_favor(me, random(2));
		}
		else if(favor < 12)
		{
			if(random(2)) command("xixi");
			if(random(2)) command("child");
			message_vision("阿绣显得很高兴，", me, ob);
			add_favor(me, random(4)-1);
		}
		else
		{
			command("he");
			add_favor(me, random(2));
		}
		break;
	case "heihei":
	case "grin":
	case "demon":
	case "hehe":
		command("fear");
		add_favor(me, -1);
		break;
	case "love":
	case "rrose":
	case "yrose":
		if(favor < 12)
		{
			message_vision(CYN"$n看到$N火辣辣的表白，害羞的转过身去。\n"NOR, me, ob);
			add_favor(me, random(3)-1);
		}
		else
		{
			command("wa " + id);
			command("blush");
			add_favor(me, random(2));
		}
		break;
	case "dao":
	case "fly":
	case "faint":
		message_vision(CYN"$n连忙好心好意的上前把$N扶了起来。\n"NOR, me, ob);
		add_favor(me, random(3)-1);
	case "cry":
	case "wuwu":
		command("nocry " + id);
		break;
	case "nocry":
		command("nocry");
		if(favor > 12)
			add_favor(me, random(4)-1);
		break;
		break;
	case "why":
		if(favor < 5)
		{
			message_vision(CYN"$n尖叫道：「松手！你这个流氓！」\n"NOR, me, ob);
			add_favor(me, -1);
		}
		else
			command("dunno1 " + id);
		break;
	default:
		if(random(2))
			message_vision(CYN"$n摇摇头，一脸茫然的看着$N。\n"NOR, me, ob);
		else
			message_vision(CYN"$n睁大眼睛望着$N，不知道$N想干什么。\n"NOR, me, ob);
	}
	if(favor < 2)
		write("看来她对你没什么感觉。\n");
	else if(favor < 6)
		write("看来她已经对你相当熟识了。\n");
	else if(favor < 10)
		write("看来她对你有些好感。\n");
	else if(favor < 14)
		write("看来她心中已经快接受你了。\n");
	else if(favor < 18)
		write("看来她心中对你没什么防备了。\n");
	else if(favor < 22)
		write("看来她心中已经几乎完全接受你了。\n");
	else
		write("看来她心中已经完全接受你了。\n");
}