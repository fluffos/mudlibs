// yingying.c 任盈盈
//by bing

inherit NPC;
#include <ansi.h>
void heal();
void suck();
string ask_ling();
string ask_yao();
string ask_qu();

void create()
{
        set_name("任盈盈", ({ "ren yingying", "ren", "yingying" }));
        set("title",MAG "日月神教" NOR + HIR +"圣姑" NOR);
        set("long","她一头乌黑的长发，大大的眼睛，睫毛甚长，肌肤白得便如透明一般，
隐隐透出来一层晕红，容貌秀丽绝伦。\n");
        set("gender", "女性");
        set("age", 16);
	set("per",50);
        set("attitude","peaceful");
        set("shen_type", -1);
	set("shen",-5000);
        set("str", 20);
        set("int", 30);
        set("con", 30);
        set("dex", 25);
	set("drug_count",random(5));
        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 50);
        set("combat_exp", 300000);
	set("score",1000);
	set("letter_account",1);
        set("chat_chance", 30);
        set("chat_msg", ({
		"任盈盈幽幽地说道：「冲哥自从回了华山一直也没有音信，是不是忘了我啊？」\n",
                (: heal :),
		"任盈盈叹了口气：「哪怕有他一封信也好啊......」\n",
		"任盈盈皱了皱眉：「我听不惯黑木崖上那些肉麻的话，就躲到这里来了。」\n",
		"任盈盈说道：「那些三山五岳的洞主、岛主若是惹怒了教主，得不到解药，就会来向我求情。」\n",
		"任盈盈说道：「我家的阿花只吃牛肉，不知道冲哥什么时候才能来喂？」
任盈盈不由得笑了起来。\n",
        }));
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
		(: suck :),
		(: suck :),
		(: perform_action, "sword.xuanmu" :),
        }) );
        set("inquiry", ([
            "东方不败" : "几年前我爹爹失踪后他继任了教主的位置，小时候他常带我上山摘果子。现在我也好几年没见他了。",
            "东方教主" : "几年前我爹爹失踪后他继任了教主的位置，小时候他常带我上山摘果子。现在我也好几年没见他了。",
	    "任我行" : "那是我爹爹，几年以前失踪了，你能帮我找他么？",
	    "令狐冲" : (: ask_ling :),
	    "圣药" : "那是我教教主对有功之人的赏赐，吃了以后对教主更加忠心。在风雷堂童堂主处领取。",
	    "三尸脑神丹" : "那是我教教主对有功之人的赏赐，吃了以后对教主更加忠心。在风雷堂童堂主处领取。",
	    "解药" : (: ask_yao :),
            "笑傲江湖":"找不到冲哥，谈什么笑傲江湖？",
	    "曲洋" : (: ask_qu :),
	    "曲长老" : (: ask_qu :),
       ]) );

        set_skill("force", 100);
        set_skill("xixing-dafa", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
	set_skill("sword",100);
	set_skill("riyue-jian",100);
        set_skill("feitian-shenfa", 200);
        set_skill("literate",150);
        map_skill("force", "xixing-dafa");
        map_skill("parry", "riyue-jian");
        map_skill("dodge", "feitian-shenfa");
        map_skill("sword","riyue-jian");
	prepare_wskill("sword","riyue-jian");
	create_family("日月神教", 20, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
	carry_object(__DIR__"obj/duanjian")->wield();
       }
void init()
{
	object ob;
        ::init();
	ob = this_player();
	if (interactive(ob) && !is_fighting()) {
		remove_call_out("greet");
		call_out("greet", 1, ob);
	}
	add_action("do_move", "move");
}

void attempt_apprentice(object ob)
{
	command("say 你别开玩笑啦，小女子怎么能作你师傅？");
}

int accept_object(object me,object ob)
{
	object obj,chong;
	if ((string)ob->query("id") == "xiao ao jiang hu")
	if (me->query_temp("riyue/ask_qu") == 1)
		{
        		message_vision("任盈盈喜出望外，接过曲谱看了看，说道「真是曲长老的手迹！」\n", me);
			message_vision("任盈盈对$N感激地一笑。\n",me);
                        if (random(10) < 3)
			{
				obj = new(__DIR__"obj/glsan");
				obj->move(me);
				message_vision("任盈盈说道：" + RANK_D->query_respect(me) + "一路劳苦，小女子感激不尽。这本《广陵散》是小女子于朋友那里所得，乃是当世之珍，权表谢意了。\n",me);
				message_vision("任盈盈给$N一本《广陵散》\n",me);
				if (objectp(chong = present("linghu chong", environment(me))))
				{
					message_vision("令狐冲说道：「盈盈，我们结婚吧！」\n",me);
					message_vision("任盈盈含羞点了点头。\n",me);
					command("say 嗯。");
					message_vision("令狐冲大笑着拉着任盈盈的手向红娘庄方向走了过去。\n",me);
                                         this_object()->move("/d/marry/hong-damen");
                                         chong->move("/d/marry/hong-damen");
					message_vision("令狐冲和任盈盈携手走了过来。\n",chong);
					message_vision(MAG "令狐冲对著任盈盈说道：在下令狐冲，愿意和姑娘结为夫妇\n" NOR,chong);
					CHANNEL_D->do_channel(this_object(), "jh", "令狐冲跪下身来, 捧起任盈盈的手, 轻轻地吻了一下, 然后抬起头对妹妹深情的说道:\"盈盈嫁给我吧! 我会爱你到永远永远! \"", -1);
					CHANNEL_D->do_channel(this_object(), "jh", "任盈盈的脸都红了。", -1);
					CHANNEL_D->do_channel(this_object(), "jh", "任盈盈点了点头。", -1);
					message_vision(MAG "任盈盈对著令狐冲说道：小女子任盈盈，愿意和壮士结为夫妇\n" NOR,chong);
					message_vision(MAG "恭喜 任盈盈 和 令狐冲 ，一对璧人喜结良缘。\n" NOR,chong);
					CHANNEL_D->do_channel(this_object(), "jh", "媒婆(Mei_po)：令狐冲 和 任盈盈 现在开始是夫妇啦!", -1);
					CHANNEL_D->do_channel(this_object(), "jh", "任盈盈伸手过去，扣住令狐冲的手腕，叹道：“想不到我任盈盈，竟也终身和一支大马猴锁在一起，再也不分开了。”说着嫣然一笑，娇柔无限。", -1);
					CHANNEL_D->do_channel(this_object(), "jh", "令狐冲「哈哈」地开怀大笑。", -1);
					message_vision("令狐冲兴高采烈地携娇妻离开了红娘庄。\n",chong);
					destruct(chong);
					call_out("destroying",0,me,this_object());
					return 1;
				}
			}
                        else if (random(2))
                         {
                                obj = new("/d/reborn/jinyong/obj/xajh");
                                obj->move(me);
                                message_vision("任盈盈说道：多谢这位" + RANK_D->query_respect(me) + "。这本《笑傲江湖》就送给你作个纪念吧！\n",me);
                         }
			else 
			{
				obj = new(__DIR__"obj/yanyu");
				obj->move(me);
				message_vision("任盈盈说道：多谢这位" + RANK_D->query_respect(me) + "。这具燕语古琴就送给你作个纪念吧！\n",me);
			}
			me->delete_temp("riyue/ask_qu");
		   	remove_call_out("destroying");
			call_out("destroying", 1, me, ob);
                 call_out("destroying",1,me,this_object());
			return 1;
		}
	return 0;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

void greet(object me)
{
	if (me->query_temp("riyue/leading") && (present("linghu chong", environment(me))))
	{
		message_vision("任盈盈望着令狐冲甜甜地一笑，眼中却流下泪来：冲哥，真的是你吗？我不是在做梦吧？\n",me);
		message_vision("任盈盈一下子投入了令狐冲的怀抱。\n",me);
		command("say 冲哥，我们终于又在一起了。");
		command("say 当年曲长老和衡山派的刘师伯就没咱们这么幸运。");
		command("sigh");
		this_object()->delete("chat_chance");
		me->delete_temp("riyue/leading");
	}
	
	return;
}

string ask_yao()
{
	object me,drug;
	int age;
	mapping fam;
	me = this_player();

	if (me->query_temp("riyue/kill_ahua"))
	{
		command("heng");
		return "你杀了我的阿花，我不理你了。\n";
	}

        if (!(fam = me->query("family")) || fam["family_name"] != "日月神教" )
                return RANK_D->query_respect(me) +
                "与本教素无来往，不知此话从何谈起？\n";
	age = (int)me->query("age");
	if ((me->query("riyue_drug") == 999) || ( me->query("riyue_drug") < age))
	{
		if ( query("drug_count") == 1)
			{
				drug = new("/d/riyuejiao/obj/naoshendan");
				drug->move(me);
				set("drug_count",0);
				return "这是解药，速速服下吧！以后千万小心一点啊！\n";
			}
			else {  return "对不起，今天的圣药已经给别人了，你过会儿再来吧！\n";   }
	}
	else  { return RANK_D->query_respect(me) + "药性又没发作，要什么解药？\n"; }
}


string ask_qu()
{
	object me = this_player();

	if (me->query_temp("riyue/lead_ok"))
	{
		me->set_temp("riyue/ask_qu",1);
		return "怎么？你也知道曲长老的事吗？\n";
	}
	return "这事你不知道就不要乱打听了。\n";
}

string ask_ling()
{
	object me,letter;
	me = this_player();
	
	if (me->query_temp("riyue/kill_ahua"))
	{
		command("heng");
		return "你杀了我的阿花，让冲哥来喂什么？\n";
	}

	if (me->query_temp("riyue/get_letter"))
	{
		return "我不是已经给你信了吗？你送到了吗？\n";
	}
	
	if (!this_object()->query("letter_account"))
	{
		return "我已经让人送信给冲哥，让他赶快回来。\n";
	}

	command("say 冲哥说他很快就会从华山回来，可是到现在也没回来。");
	command("sigh");
	command("say 他是不是又让那个小师妹给迷住了呀？");
	command("cry " + me->query("id"));
	command("say 我这里有一封信，你帮我交给他好吗？");
	message_vision("任盈盈交给$N一封信。\n",me);
	letter = new(__DIR__"obj/xin");
	letter->move(me);
	command("say 记住，一定要亲手交给他啊！");
	command("blush");
	this_object()->set("letter_account",0);
	me->set_temp("riyue/get_letter",1);
	return "多谢你啦！\n";
}

void suck()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        command("exert neilisuck " + target->query("id"));

}

void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 50");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}

