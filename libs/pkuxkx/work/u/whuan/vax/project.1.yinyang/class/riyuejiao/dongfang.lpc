// dongfang.c 东方不败
//by bing
inherit NPC;
inherit F_MASTER;
#include "riyuenpc2.h"
#include <ansi.h>
int greet(object);
void heal();
void yoar();
void consider();
int ask_baodian();
int ask_ling();
int ask_xinfa();

void create()
{
          set_name( "东方不败", ({ "dongfang bubai", "dongfang","bubai" }));
        set("title",MAG "日月神教" NOR + HIG "教主" NOR);
        set("long","他身穿粉红衣衫，左手拿着一个绣花绷架，右手持着一枚绣花针，
正在刺绣。脸上甚是光滑，没有一根胡须，还施了脂粉。
他乃是号称武功天下第一的日月神教教主－－" + HIR "东方不败" + NOR "！。\n");
        set("gender", "无性");
	set("nickname", HIR "武功天下第一" NOR);
        set("age", 45);
        set("attitude","heroism");
        set("shen_type", -1);
	set("shen",-300000);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 2500);
        set("max_jing", 2500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 300);
        set("combat_exp", 15000000);
	set("score",5000);
	set("book_count",1);
	set("xinfa_count",1);
         set("chat_chance", 10);
        set("chat_msg", ({
                (: heal :),
		"东方不败叹了口气，自言自语道：「莲弟在忙什么呀？怎么还不来看我？是不是把我忘了？」\n",
		"东方不败说道：「我初当教主，那可意气风发了，说什么文成武德，中兴圣教，当真是不要脸的胡吹法螺。」\n",
		"东方不败说道：「自从我修习‘葵花宝典’，才慢慢悟到了人生妙谛。其后勤修内功，数年之后，终于明白了天人化生、万物滋长的要道。」\n",
		"东方不败阴笑数声，说道：「任我行那小子，自诩才智武功超群绝伦，还不是让我压在西湖底下不得翻身？」\n",
                (: yoar :),
        }));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
        }) );
        set("inquiry", ([
            "东方不败" : "我就是东方不败，你找我有什么事呀？",
            "东方教主" : "我就是东方不败，你找我有什么事呀？",
	    "任我行" : "那是我教前教主，被我囚在西湖底下的梅庄地牢里面，你要是不听话，哼哼，也是这个下场！",
	    "任盈盈" : "她是任我行的女儿，一般不住在黑木崖上。?,
	    "圣药" : "那是我对有功之人的赏赐，吃了以后对我更加忠心。在风雷堂童堂主处领取。",
	    "三尸脑神丹" : "那是我对有功之人的赏赐，吃了以后对我更加忠心。在风雷堂童堂主处领取。",
	    "葵花宝典" : (: ask_baodian :),
	    "黑木令" : (: ask_ling :),
	    "心法" : (: ask_xinfa :),
       ]) );

        set_skill("force", 500);
        set_skill("kuihua-shengong", 450);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("riyue-dao", 450);
      	set_skill("riyue-shengong",400);
        set_skill("kaishan-zhang", 450);
        set_skill("strike", 450);
        set_skill("ryingzhua-gong", 450);
        set_skill("claw", 480);
	set_skill("sword",500);
	set_skill("riyue-jian",450);
	set_skill("blade",450);
        set_skill("feitian-shenfa", 450);
        set_skill("literate",280);
	set_skill("pixie-jian",490);
        map_skill("force", "kuihua-shengong");
        map_skill("parry", "riyue-jian");
        map_skill("dodge", "pixie-jian");
        map_skill("sword","pixie-jian");
        map_skill("claw", "ryingzhua-gong");
        map_skill("strike", "kaishan-zhang");
	prepare_skill("claw", "ryingzhua-gong");
	prepare_skill("strike", "kaishan-zhang");
	create_family("日月神教", 19, "弟子");
        setup();
	carry_object("/d/city/obj/flower_shoe")->wear();
        carry_object("/d/city/obj/pink_cloth")->wear();
        carry_object("/d/city/obj/goldring")->wear();
        carry_object("/d/city/obj/necklace")->wear();
	carry_object("/d/quanzhou/obj/xiuhua");
	carry_object("/d/riyuejiao/obj/xiuhuajia")->carry();
       }
void init()
{
	object ob;
	mapping fam;
	add_action("do_flatter","say");
        ::init();
	ob = this_player();
	if (interactive(ob) && !is_fighting()) {
		remove_call_out("greet");
		call_out("greet", 1, ob);
	}
        if ( ((int)ob->query("score") < 500 || (int)ob->query("shen") >-1000 )
		&& ((fam = ob->query("family")) && fam["master_id"] == "dongfang bubai"))
        {
                command("say 你不去杀那些所谓的正教大侠,反而多次残害同道中人，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
        }

}

int greet(object ob)
{
	tell_object(ob,"东方不败朝你嫣然一笑，说道:「是莲弟让你来的吧？」\n");
	if (ob->query("gender") == "男性")
	{
		command("say 臭男人有什么好？莲弟怎么会让这个人来见我呢？");
	}
	if (ob->query("gender") == "女性")
	{
		command("say " + ob->query("name") + "，我可真羡慕你，一个人生而为女子，已比臭男子幸运百倍。");
		command("say 我若得能和你易地而处，别说是日月神教的教主，就算是皇帝老子，我也不做。");
	}
	return 1;
}

int do_flatter(string arg)
{
        if(this_player()->query_temp("riyue/flatter") )
                return 0;
        if( !arg ) return notify_fail("你说我什么？\n");
        message_vision("$N大声说道：" + arg + "\n", this_player());
        if( strsrch(arg, "圣教主文成武德，仁义英明，中兴圣教，泽被苍生。") >=0)
	{
                command("smile");
                command("say 嗯。\n");
		this_player()->set_temp("riyue/flatter",1);
        }
        return 1;
}

void attempt_apprentice(object ob)
{
	if ( ((int)ob->query("riyue_drug") != 0) && (ob->query("family/family_name") != "日月神教" ))
	{
	   command("say 大胆叛逆，竟敢反出神教，我今天就为教除逆！\n");
	   command("kill "+ob->query("id"));
	   return;
	}
/*
if((int)ob->query("betrayer"))
        {
                command("say "+RANK_D->query_respect(ob)+"你多次判师，背信弃义。我怎会收你。\n");
                return;
        }
*/

	if (ob->query("family/family_name") != "日月神教")
	{
	   command("say 我们日月神教拜师要从堂主拜起，" + RANK_D->query_respect(ob) + "先去拜堂主吧！\n");
	   return;
	}
	
	if ((int)ob->query("family/generation") == 22)
	{
	   command("say 你现在还没资格拜我为师，你应该拜的是我教长老。\n");
	   return;
	}

	if ((string)ob->query("family/master_id") == "ren woxing")
	{
	   command("say 任我行的徒弟？怎么跑到我这儿来了？");
	   command("say 想给你师傅报仇？好啊，受死吧！");
	   command("kill " + ob->query("id"));
	   return;
	}

	if (ob->query("riyue_drug") == 0)
	{
	   command("say " + RANK_D->query_respect(ob) + "吃了我教的圣药了吗？\n");
	   return;
	}
	
	if (ob->query("riyue_drug") == 999)
	{
	   command("say " + RANK_D->query_respect(ob) + "还没吃今年的圣药，我不能收你。\n");
	}

	if ((int)ob->query("score") < 1500)
	{
	   command("say " + RANK_D->query_respect(ob) + "对本教的贡献还不够，我不能收你。\n");
	   return;
	}

	if ((int)ob->query_skill("flatter",1) < 100)
	{
	   command("say " + RANK_D->query_respect(ob) + "还没学会应该怎么跟我说话，还是先回去好好学习一下吧！\n");
	   return;
	}

	if ((int)ob->query_skill("riyue-shengong",1) < 60)
	{
	   command("say " + RANK_D->query_respect(ob) + "的日月神功好象还没学好，再回去好好学学吧！\n");
	   return;
	}
	
	if ((int)ob->query("shen") > -10000)
	{
	   command("say 我最痛恨那些所谓正教中的伪君子，" + RANK_D->query_respect(ob) + "若是能杀他几个，我一定收你。\n");
	   return;
	}

	if (!ob->query_temp("riyue/flatter"))
	{
	   command("say 你说我怎么样啊？\n");
	   return;
	}

        command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！");
        command("recruit "+ob->query("id"));
	command("chat 哼哼！我也收了徒弟了，你们正教大侠们给我小心一点！");
	return;
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
	if((string)ob->query("gender")=="女性")
		{ ob->set("title",MAG "日月神教" NOR + HIR +"神女" NOR); }
	else	{ ob->set("title",MAG "日月神教" NOR + HIG +"长老" NOR); }


}

int accept_object(object me,object ob)
{
	object book;
	if ((string)ob->query("id") == "shou ji")
	if (me->query_temp("riyue/killer") == 1)
		{
        		message_vision("东方不败盯着任我行的首级看了许久，抬起头来，大笑三声。\n", me);
			message_vision("东方不败对$N说到：「你为本教诛除叛逆，立了大功，这本《葵花宝典》你拿回去好好钻研钻研，算是我对你的奖赏吧！」\n",me);
			book = new("/d/riyuejiao/obj/kuihua");
			book->move(me);
			set("book_count",0);
			if((string)me->query("gender")=="女性")
				{ me->set("title",MAG "日月神教" NOR + HIR "圣姑" NOR); 
				  message_vision("东方不败对$N说到：「从今以后，你就是本教的圣姑了！」\n",me);}
			else	{ me->set("title",MAG "日月神教" NOR + HIG "总管" NOR); 
				  message_vision("东方不败对$N说到：「从今以后，你就是本教的总管了！」\n",me);}
          	    	remove_call_out("destroying");
			call_out("destroying", 1, me, ob);
			return 1;
		}
	else	
		{	message_vision("东方不败脸色一沉，对$N说到：「谁让你去杀他的？看在你一片忠心的份上，罢啦！不追究你的刑事责任了！」\n",me);
			command("hehe");
          	    	remove_call_out("destroying");
			call_out("destroying", 1, me, ob);
			return 1;
		}	
	return 0;

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

int ask_xinfa()
{
	object me = this_player();
	object book;

	if (!query("xinfa_count"))
	{
		command("say 我的内功心法已经给人了，你来晚了。");
		return 1;
	}

	if (((string)me->query("title") == MAG "日月神教" NOR + HIR "圣姑" NOR )
		|| ((string) me->query("title") == MAG "日月神教" NOR + HIG "总管" NOR ))
		if (me->query("betrayer")<1)
		{
			command("look " + me->query("id"));
			command("sigh");
			command("say 现在象你这样根红苗壮的弟子已经很少啦！");
			command("say 这是我研习葵花宝典的一些体会，你拿回去好好看看吧！");
			book = new("/d/riyuejiao/obj/xinfa");
			book->move(me);
			message_vision("东方不败给了$N一篇内功心法。\n",me);
			set("xinfa_count",0);
			return 1;
		}
	command("say 我的内功心法不能随便给人。");
	return 1;
}


int ask_baodian()
{
	object me;
	object book;
	me = this_player();

	if (!query("book_count"))
	{
		command("say 你来晚了，我的《葵花宝典》已经给人了。");
		return 1;
	}

	if (((string)me->query("title") == MAG "日月神教" NOR + HIR "圣姑" NOR )
		|| ((string) me->query("title") == MAG "日月神教" NOR + HIG "总管" NOR ))
	{
		command("say 这本《葵花宝典》你拿回去好好钻研钻研。");
		book = new("/d/riyuejiao/obj/kuihua");
		book->move(me);
		set("book_count",0);
		return 1;
	}
	
	if ((string)me->query("family/master_id") != "dongfang bubai")
	{
		command("l " + me->query("id"));
		command("say 那是我教历代教主相传之武功宝典，你没有资格拿到。");
		return 1;
	}
	
	tell_object(me,"东方不败低头想了一想，说到：「你去给我杀了任我行这个老贼，把他的脑袋拿给我，我就传你葵花宝典。」\n");
	me->set_temp("riyue/杀任",1);
	return 1;
}

int ask_ling()
{
	object me,ling;
	me = this_player();

	if (me->query_temp("riyue/杀任") != 1)
	{
		command("l " + me->query("id"));
		tell_object(me,"东方不败眼里露出怀疑的神色：「那是我教教主的信物，你问它干什么？」\n");
		return 1;
	}
	
	ling = new("/d/riyuejiao/obj/heimuling");
	tell_object(me,"东方不败给你一块黑色的令牌。\n");
	command("say 你拿着这块黑木令给梅庄的人看，他们就不敢拦你了。\n");
	ling->move(me);
	return 1;
}

void yoar()
{
	if (!this_object()->query("shout"))
	{
		message( "channel:" + "chat",
			HIR "东方不败" NOR + HIC "说道：日出" + HIR "东方" + HIC "，唯我" + HIR "不败" + HIC "！\n" NOR, users() );
	}
	this_object()->set("shout",1);
	return ;
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(2) )
        {
            case 0:
            command("wield zhen");
            command("perform sword.cixue " + target->query("id"));
            command("unwield zhen");
             break;
            case 1:
            command("wield zhen");
            command("perform sword.cimu " +target->query("id"));
            command("unwield zhen");
             break;
             }
}
