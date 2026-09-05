#include <ansi.h>

inherit F_MASTER;
inherit NPC;

#include "/d/beijing/beijing_defs.h"
#include "/d/beijing/job_info.h"
#include "/d/beijing/autok.h"
#include "autocheck.h"
#include <title.h>

string ask_qishang();
string ask_yin();

void create()
{
        set_name("海大富", ({"hai dafu", "hai gonggong", "hai", "gonggong"}));
        set("title", "东厂五品官员 " + HIW"尚膳监首领太监"NOR);
        set("long",
                "这是一个面色蜡黄的老太监，弓腰曲背，不住咳嗽，看他有气无力的样子，似是身患重病。\n"
        );

        set("gender", "无性");
        set("rank_info/respect", "公公");

        set("attitude", "heroism");
        set("class", "eunuch");
				set("no_get", 1);
				
        set("age", 60);
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("kar", 200);

        set("apply/attack",  30);
        set("apply/defense", 30);

				set("pin", 5);
				set("yin_count", 5);
				
				set("max_qi", 2800);
				set("eff_qi", 2800);
				set("qi", 2800);

				set("max_jing", 1800);
				set("eff_jing", 1800);
				set("jing", 1800);

				set("jingli", 3600);
				set("max_jingli", 3600);

				set("neili", 5600);
				set("max_neili", 5600);

				set("jiali", 150);

				set("combat_exp", 5000000);
	
				set_skill("force", 250);
				set_skill("dodge", 220);
				set_skill("cuff", 220);
				set_skill("strike",220);
//				set_skill("hand",180);
				set_skill("parry", 220);
				set_skill("blade",220);
				set_skill("sword",220);
//				set_skill("claw",180);
        set_skill("throwing", 240);
        
        set_skill("qishang-quan", 60);
				set_skill("kongdong-xinfa", 250);
				set_skill("luofeng-liushi", 220);
				set_skill("shizi-zhan", 220);
        set_skill("fengyun-jian", 250);
        set_skill("kongling-jian", 250);
        set_skill("wulong-quan", 220);

        map_skill("dodge", "luofeng-liushi");
        map_skill("parry", "fengyun-jian");
        map_skill("force", "kongdong-xinfa");
				map_skill("sword", "kongling-jian");
				map_skill("strike", "shizi-zhan");
				map_skill("cuff", "wulong-quan");
	
				prepare_skill("strike", "shizi-zhan");
				prepare_skill("cuff", "wulong-quan");
	
        
        set("chat_chance", 15);
        set("chat_msg", ({
//                (:  :)
				"海公公叹道：“七伤拳”乃我派武功绝学，可惜我只学到些皮毛。唉～\n",
        }) );

        set("inquiry",([
									"关防印": (: ask_yin :),
									"七伤拳": (: ask_qishang :),
        ]));
        
				create_family("东厂", 2, "官员");
				
				setup();
				
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/beijing/dongchang/obj/guanfu")->wear();//太监官服
}

void init()
{
	object ob;

	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);

	add_action("do_join", "join");
	
	ob = this_player();
	do_check(ob, this_object());
	
	if( interactive(ob) && !is_fighting())
		call_out("greeting", 1, ob);
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	auto_kill(ob);
}

string ask_qishang()
{
	return "明教金毛狮王谢逊夺得《七伤拳谱》古抄本，竟练成神功，不知道他现在身在何处。\n";
}

string ask_yin()
{
	object ob;
	if (this_player()->query("class") != "eunuch")
		return RANK_D->query_respect(this_player()) +
		"与东厂素无来往，不知此话从何谈起？";
		
	if (query("yin_count") < 1)
	{		
		if(!random(10)) 
			set("yin_count", 5);
		this_player()->start_busy(1);
		return "你来晚了，关防印已经被人拿走了。";
	}
	
	if (objectp(present("guanfang yin", this_player())))
		return "你已经有关防印了，怎么还要?";
		
	add("yin_count", -1);
	ob = new("/d/beijing/dongchang/obj/guanfangyin");
	ob->move(this_player());
	this_player()->start_busy(1);
	return "关防印是东厂的信物，你暂时拿去用吧，我会派人收回的。";
}

void attempt_apprentice(object ob)
{
	if (ob->query("class") != "eunuch")
	{
		ob->set_temp("chaoting/dc", 1);
		command("say " + RANK_D->query_respect(ob) + "是否有意加入东厂呢？(join)");
		return;
	}	

	command("say 好吧，那我就收下你了。");
	command("recruit " + ob->query("id"));
	return;
}

int do_join()
{
	object player = this_player();
	int time;
	string name;
	name = player->query("name");

	if (!player->query_temp("chaoting/dc")) return 0;
	if (this_object()->is_fighting()) return notify_fail("海公公正在战斗中，无暇他顾。\n");
	if (player->is_fighting()) return notify_fail("你正在战斗中，无暇他顾。\n");
		
	if (player->query("class") == "officer")
		{
			message_vision("$N对$n说道：“难道大人您对加入东厂也有兴趣吗？”\n", this_object(), player);
			return 1;
		}

	if (player->query("class") == "eunuch")
		{
			message_vision("$N对$n说道：" + RANK_D->query_respect(player)  + "当对东厂尽忠竭力，他日必定前途无量！\n", this_object(), player);
			return 1;
		}
		
	if (player->query("gender") == "男性")
		{
			message_vision("$N对$n说道：" + RANK_D->query_respect(player) + "尚未净身，恐怕不适合入宫做事。\n", this_object(), player);
			return 1;
		}	

	if (player->query("gender") == "女性")
		{
			message_vision("$N对$n说道：" + "我虽已废，但一样可以给你这个小美人带来快乐，要不要试试？\n", this_object(), player);
			return 1;
		}	
		
	player->delete_temp("chaoting/dc");
	
	if(mapp(player->query("family")))
	{
		message_vision("$N决定背叛师门，加入东厂！！\n", player);
		player->set("rank_info/respect", "公公");
		player->set("rank_info/rude", "阉贼");		
		player->delete("family");
		player->set("family", ([
			"family_name"    : "东厂",
			"enter_time"     : time(),
			]));

		if ( player->query("combat_exp") >= 1000 ) player->add("betrayer", 1);
	}
	else
	{
		message_vision("$N决定加入东厂！！\n", player);
		player->set("family", ([
			"family_name"    : "东厂",
			"enter_time"     : time(),
			]));
	}
		time = player->query("mud_age");
		player->set("dongchang/salary", time);
		player->set("score", 0);
		player->set("class", "eunuch");

		player->set("title",YEL"东厂九品官员"NOR);
//title系统记录玩家title by seagate@pkuxkx
	  player->set_title(TITLE_RANK, YEL"东厂九品官员"NOR);
		player->set("name","小"+name[0..0]+"子");

		player->set("pin", 9);
		message_vision("$N拍着$n的肩膀说道：恭喜你成为东厂一员。\n", this_object(), player);
		player->save();
		return 1;
}

int recruit_apprentice(object ob)
{
	int pin;
	string *rank_name, title, name;
	string *all_color = ({HIR,HIB,HIG,HIY,HIC,HIW,HIM,GRN,YEL});

	if( ::recruit_apprentice(ob) )
	pin = ob->query("pin");
	name = ob->query("name");
	if(pin <= 6) ob->set("name", name[1..1] + "公公");
	
	switch (pin)
	{
	case 9:
	rank_name = ({"直殿监典簿", "都知监长随"});
	title = rank_name[random(sizeof(rank_name))];
	break;

	case 8:
	rank_name = ({ HIW"尚膳监奉御"NOR, HIW"尚衣监监丞"NOR});
	title = rank_name[random(sizeof(rank_name))];
	break;

	case 7:
	rank_name = ({ CYN"尚宝监少监"NOR, CYN"印绶监少监"NOR});
	title = rank_name[random(sizeof(rank_name))];
	break;

	case 6:
	rank_name = ({ HIC"内官监管事太监"NOR, HIC"司设监管事太监"NOR,});
	title = rank_name[random(sizeof(rank_name))];
	break;

	case 5:
	title = BLU"神宫监管事太监"NOR;
	break;

	case 4:
	title = HIB"御用监理刑百户";
	break;

	case 3:
	title = HIM"御马监掌刑千户"NOR;
	break;

	case 2:
	title = MAG"东厂掌印太监"NOR;
	break;

	case 1:
	title = HIY"司礼监掌印太监";
	break;
	}
	title = all_color[pin - 1] + "东厂" + chinese_number(pin) + "品官员 "NOR + title;
	ob->set("title", title);
	//title系统记录玩家title by seagate@pkuxkx
	ob->set_title(TITLE_RANK, title);
	return 1;
	
}