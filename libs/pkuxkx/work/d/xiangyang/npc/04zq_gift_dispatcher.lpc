// 04zq_gift_dispatcher.c  by Yom 2004-9-27 23:26
//modify by Vast 2004-09-29
//QC by Pal 2004-09-30
inherit NPC;
//inherit F_DEALER;

#include <ansi.h>
string ask();
int do_answer(string);

void create()
{
    set_name("神仙侍从", ({ "shenxian shicong", "shicong" }));
    set("title",GRN "仙境" NOR + YEL "使者" NOR);
    set("long","他一身灵透之气，看样子就很像个仙家的人了。\n");
    set("gender", "男性");
    set("age", 17);
    set("attitude","heroism");
    set("shen_type", 0);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);
    set("max_qi", 800);
    set("max_jing", 600);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 50);
    set("combat_exp", 50000);
	set("score",1000);
    set("chat_chance", 10);

    set("chat_msg", ({
	"神仙侍从谦恭地说道：「又是佳节到！祝大家都开开心心快快乐乐......」\n",
	"神仙侍从微笑着说：「仙人们派我来给大家发礼物，我混个脸熟先，大家以后可得罩我啊！」\n",
    "神仙侍从响亮地说：「大家快来领礼物啊，福气运气都来啦，来看看会得到个什么礼物呢？」\n",
    "神仙侍从满脸笑容：「嗯，这个，这个，过节挺好的嘛」\n",
    "神仙侍从说：「各位mm好，mm优先领礼物！」\n",
    }));

    set("inquiry", ([
        "中秋" : "佳节到，恭喜大家团圆开心",
    	"神仙" : "你也想成仙人么？看他们飞来飞去很自在吧",
    	"yom"  : "那个家伙啊，嗯，这个，我们聊点别的吧",
        "仙境使者" : "就是我啦，我是奉命来给大家送礼物的",
    	"礼物" : (: ask :),
    	"gift" : (: ask :),
   ]) );

    set_skill("force", 150);
    set_skill("dodge", 150);
    set_skill("parry", 150);
    set_skill("strike", 150);
    set_skill("literate",100);
    setup();

    carry_object("/d/riyuejiao/obj/zipao")->wear();
	carry_object("/d/riyuejiao/obj/yaodai")->wear();
}
void init()
{
	object ob;
	mapping fam;
	add_action("do_answer","answer");
        ::init();
	ob = this_player();
	if (interactive(ob) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


int des(object ob)
{
 destruct(ob);
return 1;
}

void attempt_apprentice(object ob)
{
	   command("say 我还正在修炼，不能收徒，你去找仙人们吧!\n");
	   command("pat "+ob->query("id"));
	   command("smile "+ob->query("id"));
	   command("addoil "+ob->query("id"));

	   return;

}

int do_answer(string arg)
{
	object ob = this_player();
	command("say 你在说什么啊~\n");
	command("look "+ob->query("id"));
	return 1;
}

string ask()
{
	object me,gift;
	int giftgot;

	me = this_player();
	giftgot = (int)me->query("gift/zq_gift");
                if ( (int)me->query("mud_age" ) < 86400 )
                        return ("你还未成年，过两年再享受吧!\n");

	if ( giftgot == 0 )
	{
		if( (string)me->query("gender") == "女性" )
		{
			command("smile "+ me->query("id"));
			command("rose "+ me->query("id"));
			command("say mm好啊，你想得到什么礼物呢？我帮你搬回去吧，不用客气的!\n");
		}
		else
		{
			command("smile "+ me->query("id"));
			command("bow "+ me->query("id"));
			command("say 您想得到什么礼物？尽说不妨～\n");
		}

		me->set("gift/zq_gift",1);
		gift = new("/clone/gift/04zq_gift");
		gift->move(me);
		return RANK_D->query_respect(me) +
                "，恭喜啦，这是属于你的礼物，快打开看看吧!\n";
	}
	else
	{
		switch( giftgot )
		{
			case 1:
			{
				me->add("gift/zq_gift",1);
				command("sorry "+ me->query("id"));
				return "抱歉，你的礼物已经领过了，别着急，等等下次发礼物吧\n";
				break;
			}
			case 2:
			{
				me->add("gift/zq_gift",1);
				command("point "+ me->query("id"));
				return "嗯，哦，你，你，你！\n";
				break;
			}
			case 3:
			{
				me->add("gift/zq_gift",1);
				command("shake "+ me->query("id"));
				return "我不认识你啊，你老缠着我干嘛\n";
				break;
			}
			default:
			{
				//me->set("zq_gift",1);
				command("lookin "+ me->query("id"));
				return "!!!\n";
				break;
			}
		}
	}

}
