// longnv.c 小龙女

// 1998.9 by Lgg

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_job();
string ask_yunv();
string ask_me();
string ask_shoutao();
string ask_suo();
string ask_zhen();
int ask_fail();
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
        set("str", 60);
        set("int", 67);
        set("con", 66);
        set("dex", 68);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "sword.hebi yang" :),
            		(: command("perform sword.hebi yang") :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "小龙女幽幽地道：“不知过儿现在在哪里？可有看到我刺在玉蜂翅上的字？”\n",
                "小龙女喃喃道：“玉女剑与全真剑合壁，是可天下无敌。可是...哪里去找这一个人呢？”\n",
                "小龙女深深地叹了口气，转过头去。\n",
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),
        }));

        set("qi", 16500);
        set("max_qi", 16500);
        set("jing", 16600);
        set("max_jing", 16600);
        set("neili", 34000);
        set("max_neili", 34000);
        set("jiali", 200);

        set("combat_exp", 6000000);
        set("score", 0);

        set_skill("force", 250);
        set_skill("throwing", 300);
        set_skill("whip", 260);
        set_skill("yinsuo-jinling", 320);
        set_skill("yangyanshu", 380);
        set_skill("yunv-xinfa", 310);    //玉女心法
        set_skill("sword", 150);
        set_skill("yunv-jian", 320);     //玉女剑
        set_skill("quanzhen-jian",130);  //全真剑
        set_skill("dodge", 260);
        set_skill("yunv-shenfa", 320);   //玉女身法
        set_skill("parry", 150);
        set_skill("hubo", 120);          //双手互搏
        set_skill("unarmed",150);
        set_skill("meinv-quan", 320);    //美女拳法
        set_skill("literate",120);
        set_skill("qufeng",250);         //驱蜂之术
        set_skill("wuzhan-mei",250);
        set_skill("strike",200);
        set_skill("tianluo-diwang",320);         //驱蜂之术

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
                        "job" : (: ask_job :),
                        "任务" : (: ask_job :),
                        "失败" : (: ask_fail :),
                        "fail" : (: ask_fail :),
	"金铃索":(: ask_suo :),
	"金丝手套":(: ask_shoutao :),
	"玉蜂针":(: ask_zhen :),
        ]) );

        set("env/wimpy", 40);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
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

void init()
{
        ::init();
	add_action("do_killing", "kill");
	add_action("do_killing", "touxi");
	add_action("do_killing", "hit");
	add_action("do_killing", "ansuan");
	add_action("do_killing", "qiangjian");
}

int do_killing(string arg)
{

	object player, victim, weapon;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "杨过")
		{
		message_vision("$N微微一笑道：过儿，我来助你! \n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		victim->kill_ob(player);
		return 1;
		}
	}
	return 0;
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
string ask_job()
{
        object ob,feng;
object killer;
int k;
        mapping fam;

        string what;
        string *wanted;

        ob = this_player();


        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "古墓派")
                return RANK_D->query_respect(this_player()) +
                "与本派毫无瓜葛，不用为我做事啊？";

        if (ob->query("combat_exp")< 5000)
            {
                      message_vision("$N对着$n摇了摇头说：你目前的本事不够，捉玉峰会受伤的。\n", this_object(), ob);
                return ("你先去学武功吧！");
            }

        if ((int)ob->query_condition("menpai_busy"))
            {
                      message_vision("$N对着$n摇了摇头说：你不是刚刚放弃不想做了吗?\n", this_object(), ob);
                return ("如果你有别的事，我也没有办法啊！");
            }

if (ob->query("combat_exp") >1000000)
{
        if ( ob->query_temp("gumukill") )
        {
                command("say 我不是告诉你林中有黑衣女子吗？");
                return ("去查一查她在干什么吧！");
        }
}
        if ( ob->query_temp("gmjob") )
        {
                command("say 我不是才叫你去做玉蜂浆的吗？");
                return ("如果你有别的事，我也没有办法啊！");
        }

        ob->set_temp("gmjob",1);
feng=new(__DIR__"jobyufeng",1);
feng->move("/d/gumu/shulin"+(random(9)+1));
        message_vision(HIW"小龙女对$N说：小树林中我养了一些采蜜玉蜂。\n"NOR, ob);
        message_vision(HIW"小龙女淡淡一笑对$N说：你去古墓前面的小树林捉点蜜蜂回来！\n"NOR, ob);
//if (1)
if (random(30)==1)
{
ob->set_temp("gumukill",1);
        message_vision(HIR"听说小树林中有不明身份的黑衣女子！你可要小心一点。\n"NOR, ob);
killer=new(__DIR__"killer",1);
if ((int)ob->query_skill("force",1) > 10)
{
k=(int)ob->query_skill("force",1);
}
else k=10;
        killer->move("/d/gumu/shulin"+(random(9)+1));
        killer->set("combat_exp",ob->query("combat_exp"));
        killer->set("qi", ob->query("max_qi"));
        killer->set("eff_qi", ob->query("max_qi"));
        killer->set("max_qi", ob->query("max_qi"));
        killer->set("jing", ob->query("max_jing"));
        killer->set("eff_jing", ob->query("max_jing"));
        killer->set("max_jing", ob->query("max_jing"));
        killer->set("neili", ob->query("max_neili"));
        killer->set("max_neili", ob->query("max_neili"));
killer->set_skill("strike", k*4/5);
killer->set_skill("whip", k*4/5);
        killer->set_skill("xue-dao", k*4/5);
        killer->set_skill("unarmed",k*4/5);
        killer->set_skill("xianglong-zhang",k*4/5);
        killer->set_skill("dodge", k*4/5);
        killer->set_skill("blade", k*4/5);
        killer->set_skill("parry", k*4/5);
        killer->set_skill("dashou-yin", k*4/5);
        killer->set_skill("shenkong-xing", k*4/5);
        killer->set_skill("longxiang", k*4/5);
        killer->set_skill("huntian-qigong", k*4/5);
killer->set_skill("chilian-shenzhang", k*4/5);
killer->set_skill("jueqing-bian", k*4/5);
killer->set_name(HIB "黑衣女子" NOR, ({ ob->query("id")+"-heiyi nvzi"}));
ob->set_temp("gumukill",1);
}
        return (HIW"然后去做点玉蜂浆，供大家吃吧！\n"NOR);
}
int ask_fail()
{
        object me = this_player();
if (me->query("jing") < 50)
            	{
            		command("say 你的精神太差了，等一会再来!.\n");
            		return 1;
            	}
if (me->query("qi") < 50)
            	{
            		command("say 你的精神太差了，等一会再来!.\n");
            		return 1;
            	}

        if (me->query_temp("gmjob") == 1) {
                command("sigh");
                command("say 你实在不想去的话，我只好找别人帮忙了");
me->delete_temp("gumukill");
me->delete_temp("gmjob");
me->add("jing",-me->query("max_jing")/20);
me->add("eff_jing",-me->query("max_jing")/20);
me->add("qi",-me->query("max_qi")/20);
me->add("eff_qi",-me->query("max_qi")/20);
                me->apply_condition("menpai_busy", 5 +
                        (int)me->query_condition("menpai_busy"));
//                me->apply_condition("menpai_busy",2+random(4));
                return 1;
                }
}

