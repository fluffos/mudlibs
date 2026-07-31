// longnv.c 小龙女

// 1998.9 by Lgg

#include <ansi.h>

inherit NPC;

string ask_yunv();
string ask_me();
string ask_shoutao();
string ask_suo();
string ask_zhen();

void create()
{
        set_name("小龙女", ({"long nv", "long"}));
        set("gender", "女性");
        set("age", 18);
        set("long",
                "披著一袭轻纱般的白衣，犹似身在烟中雾里，除了一头黑发之外，全身雪白，，\n"+
                "面容秀美绝俗，只是肌肤间少了一层血色.她一生爱穿白衣，当真如风拂玉树，\n"+
                "雪裹琼苞，兼之生性清冷，实当得起“冷浸溶溶月”的形容。\n");
        set("attitude", "friendly");

        set("per", 30);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "小龙女幽幽地道：“不知过儿现在在哪里？可有看到我刺在玉蜂翅上的字？”\n", 
                "小龙女喃喃道：“玉女剑与全真剑合壁，是可天下无敌。可是...哪里去找这一个人呢？”\n",
                "小龙女深深地叹了口气，转过头去。\n",
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),
        }));

        set("qi", 6500);
        set("max_qi", 6500);
        set("jing", 6600);
        set("max_jing", 6600);
        set("neili", 14000);
        set("max_neili", 24000);
        set("jiali", 200);

        set("combat_exp", 2000000);
        set("score", 0);

        set_skill("force", 150);
        set_skill("throwing", 300);
        set_skill("whip", 260);
        set_skill("yinsuo-jinling", 260);
        set_skill("yangyanshu", 300);
        set_skill("yunv-xinfa", 250);    //玉女心法
        set_skill("sword", 150);
        set_skill("yunv-jian", 250);     //玉女剑
        set_skill("quanzhen-jian",130);  //全真剑
        set_skill("dodge", 160);
        set_skill("yunv-shenfa", 260);   //玉女身法
        set_skill("parry", 150);
        set_skill("hubo", 120);          //双手互搏
        set_skill("unarmed",150);
        set_skill("meinv-quan", 260);    //美女拳法
        set_skill("literate",120);
        set_skill("qufeng",250);         //驱蜂之术
        set_skill("wuzhan-mei",150);
        set_skill("strike",200);
        set_skill("tianluo-diwang",300);         //驱蜂之术

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");

        create_family("古墓派", 3, "弟子");


        set("book_count", 1);
        set("count",3);
        set("yfzhen",3);

        set("inquiry", ([
                "过儿" : (: ask_me :),
                "杨过" :  "你知道我过儿的下落？\n",
                "玉女剑法" : "玉女剑法和全真剑法合壁，天下无敌！\n",
                "古墓派" : "我的林祖师爷爷本来和重阳先师是一对璧人，可是...\n",
                "玉女心经" : (: ask_yunv :),
	"金铃索":(: ask_suo :),
	"金丝手套":(: ask_shoutao :),
	"玉蜂针":(: ask_zhen :),
        ]) );

        set("env/wimpy", 40);
        setup();

        carry_object(__DIR__"obj/shunvjian")->wield();
        carry_object(__DIR__"obj/baipao")->wear();
	carry_object("/d/gumu/obj/jinling-suo");
	carry_object("/d/gumu/obj/jinsi-shoutao");
	carry_object("/d/gumu/obj/si_cloth");

}

void attempt_apprentice(object ob)
{
	if(ob->query("per") < 20)
	{
        	command("say 尊容实在不敢恭维，恐怕学不了玉女心法。\n");
	}
	else
	{
	        command("say 好吧，我就收下你这个徒弟了。\n");
        	command("recruit " + ob->query("id"));
	}
}

string ask_yunv()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "古墓派")
                return RANK_D->query_respect(this_player()) +
                "与本派毫无瓜葛，何以问起本派的心经？";
        if (query("book_count") < 1)
                return "你来晚了，本派的玉女心经已经被人取走了。";
        add("book_count", -1);
        ob = new("/clone/book/yunvjing1");
        ob->move(this_player());
        return "好吧，这本「玉女心经」你拿回去好好研读。";
}


string ask_me()
{
        object ob;

        if(query("count") < 1)
                return "你知道过儿的下落？";

        add("count", -1);
        ob=new(__DIR__"obj/junzijian");
        ob->move(this_player());
        return "这柄君子剑送给你做个信物，见到过儿的时候请交给他。";
}

int recognize_apprentice(object ob)
{
        mapping myfam;
        if (!ob->query("family"))
        return 0;
        myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "古墓派") return 1 ;
        if ((int)ob->query_temp("tmark/龙") == 1 )
        message_vision("小龙女叹了口气，看看$N，说道：咱们的缘分已经尽了,\n"
                          "我也没什么东西可教你的了。\n", ob);
        if (!(int)ob->query_temp("tmark/龙"))
                return 0;
        ob->add_temp("tmark/龙", -1);
        return 1;
}

int accept_object(object who, object ob)
{

        if ( (string) ob->query("id") =="yufeng" ) {
                remove_call_out("destroying");
                call_out("destroying", 1, this_object(), ob);
                if (!(int)who->query_temp("tmark/龙")) who->set_temp("tmark/龙",0);
                message_vision("小龙女捧着玉蜂，幽幽地叹了口气，说道：\n"
                               "难得你还有心找到了我的玉蜂送回来，你可\n"
                               "以从我这里学点功夫。\n", who);
                who->add_temp("tmark/龙", 80);
                //ob->die();
                return 1;
        }
        return 0;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}


string ask_suo()
{
	object me=this_player();
	object obn;
	mapping myfam;
if(!me->query("family"))
		return "你是谁啊?我不认识你啊！\n";

	if (query("count") < 1)
		return "你来晚了，金铃索已经给人取走了。\n";

	if(me->query_temp("金铃索",1))
		return "不是给过你了吗？\n";
		
	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "古墓派")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")==!"taoist")
            	{
            		obn=new("/d/gumu/obj/jinling-suo");
            		obn->move(me);
            		add("count", -1);
            		me->set_temp("金铃索",1);
            		return "这条金铃索我送给你把。";
            	}
            	else
            	{
            		command("say 你是我师姐的弟子，我干嘛要给你？.\n");
            		return 0;
            	}
        }
        else
        {
        	return 0;
        }
}	
string ask_shoutao()
{
	object me=this_player();
	object obn;
	mapping myfam;
	if (query("count") < 1)
		return "你来晚了，金丝手套已经给人取走了。\n";

	if(me->query_temp("金丝手套",1))
		return "不是给过你了吗？\n";

if(!me->query("family"))
		return "你是谁啊?我不认识你啊！\n";
		
	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "古墓派")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")==!"taoist")
            	{
            		obn=new("/d/gumu/obj/jinsi-shoutao");
            		obn->move(me);
            		add("count", -1);
            		me->set_temp("金丝手套",1);
            		return "这双金丝手套就送给你吧。\n";
            	}
            	else
            	{
            		command("say 你是我师姐的弟子，我干嘛要给你？.\n");
            		return 0;
            	}
        }
        else
        {
        	return 0;
        }
}	
string ask_zhen()
{
	object me=this_player();
	object obn;
	mapping myfam;
	if (query("yfzhen") < 1)
		return "我这里已经没有玉蜂针了。\n";
if(!me->query("family"))
		return "你是谁啊?我不认识你啊！\n";

	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "古墓派")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")==!"taoist")
            	{
            		obn=new("/d/gumu/obj/yfzhen");
            		obn->move(me);
            		add("yfzhen", -1);
            		return "这些玉蜂针就送给你吧。\n";
            	}
            	else
            	{
            		command("say 你是我师姐的弟子，我干嘛要给你？.\n");
            		return 0;
            	}
        }
        else
        {
        	return 0;
        }
}	
