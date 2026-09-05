#include <ansi.h>
#include <title.h>
inherit NPC;
string ask_leadership();
string ask_strategy();
string ask_jiajiang();
void create()
{
	set_name(HIY"康熙"NOR, ({
		"kang xi",
		"emperor",
	}));
	set("title", "大清皇帝");
	set("long",
		"他就是当今皇上。他年龄不大，眉清目秀，神情轩昂，有一股凛然之威。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");
	set("no_get", 1);

	set("age", 16);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 20 + random(10));
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 10000);
	set("score", 100);
    	set("book_count", 1);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("cuff", 50);
	set_skill("claw",50);
	set_skill("strike",50);
	set_skill("unarmed",50);
	set_skill("parry", 50);
	set_skill("blade",50);
	set_skill("sword",50);
	set_skill("staff",50);

    //	create_family("朝廷", 1, "皇帝");

    	set("inquiry", ([
  	"name" : "寡人就是大清天子。",
	/*"为官之道" : (: ask_leadership :),
	"兵法战策" : (: ask_strategy :),*/
	//"晋升" : "这个你到兵部去问明珠尚书吧。",
	//"promotion" : "这个你到兵部去问明珠尚书吧。",
	//"升官" : "这个你到兵部去问明珠尚书吧。",
	"here" : "这里就是皇宫。",
    //"嘉奖" : (: ask_jiajiang :),
    //"jiajiang" : (: ask_jiajiang :),
    	]));
	setup();

      carry_object(__DIR__"obj/longpao")->wear();
//	carry_object("/d/city/obj/gangdao")->wield();
}

/*void init()
{
    add_action("do_yes","yes");
    add_action("do_no","no");
}

int do_no()
{
    object me=this_player();
    if (!me->query_temp("chaoting/jiajiang"))
    {
        return 0;
    }
    if (me->query("chaoting/jiajianged"))
    {
        return 0;
    }
    else
    {
        command("disapp");
        command("say 人各有志，既然你不愿随国姓，我也不再勉强。王爵也不收回了。");
        me->set("chaoting/jiajianged",1);
        command("say 立下此等功绩，大清也绝不会亏待与你。");
        me->add("combat_exp",100000);
        tell_object(me,"你被大清奖励了十万点实战经验。\n");
        return 1;
    }
}

int do_yes()
{
    object me=this_player();
    string *givenname1 =
	 ({ "骊", "倩", "筱", "嘉","敏","琳","雯","琴","艳","璐","颖","凡","薇","静","玲","恬","萍"});
    string *givenname2 =
	 ({ "跃", "江", "波", "宇","加","韬","煜","庆","超","鹏","雷","律","宁","康","晨","飞","苒"});
    string *flagname=({"正黄","镶黄","正白","镶白","正红","镶红","正蓝","镶蓝"});
    string *flagcolor=({"Y1","Y2","W1","W2","R1","R2","B1","B2"});
    string name, new_name,color;
    int n;
    if (!me->query_temp("chaoting/jiajiang"))
    {
        return 0;
    }
    if (me->query("chaoting/jiajianged"))
    {
        return 0;
    }
    else
    {
        me->delete_temp("chaoting/jiajiang");
        me->set("chaoting/jiajianged",1);
        me->set("chaoting/stayforever",1);
        n=random(sizeof(flagname));
        me->set("chaoting/flagcolor",flagcolor[n]);
        name = me->query("name");
		color=COLOR_D->get_color(name);
		name=COLOR_D->uncolor(name);
        if (me->query("gender")=="男性")
        {
            new_name ="爱新觉罗."+name[0..0]+givenname2[random(sizeof(givenname2))];
        }
        else
        {
            new_name ="爱新觉罗."+name[0..0]+givenname1[random(sizeof(givenname1))];
        }
		new_name = color+new_name+NOR;
        command("smile");
        me->set("chaoting/old_name",name);
        me->set("name", new_name);
        me->set_face( FACE_FACT, me->query("name") );
        CHANNEL_D->do_channel(this_object(), "jh", me->query("chaoting/old_name")+"忠心耿耿，为本朝立下汗马功劳，特赐名"+me->query("name")+",领"+flagname[n]+"旗，钦此。");
        me->add("combat_exp",200000);
        tell_object(me,"你被大清奖励了二十万点实战经验。\n");
        return 1;
    }
}

string ask_jiajiang()
{
    object ob=this_object();
    object me=this_player();
    if (me->query("class") != "officer")
                return RANK_D->query_respect(this_player()) +
                "与朝廷素无来往，不知此话从何谈起？";
    if (!me->query("chaoting/wang")&&!me->query("chaoting/jiawang"))
                return "你寸功未立，来这里讨打吗？";
    if (me->query("chaoting/jiajianged"))
                return "你不是已经获封过铁帽子王，还来作甚？";
    if (me->query("mingpin"))
                return "明朝人居然做到我大清官场的顶峰？";
    else
    {
        message_vision("$N沉吟道：按祖制，异姓不得封王，非有莫大功绩不得获爵。\n",ob);
        message_vision("$N道：你为本朝立下绝世功绩，自然也不会亏待与你，摄政王已封了你爵位。\n",ob);
        message_vision("$N道：这样吧，既不违背祖制，也不让有功之臣寒心，我赐你国姓，你可愿否(yes OR no)？\n",ob);
        me->set_temp("chaoting/jiajiang",1);
        return "赐姓之后，你只能永世效忠我朝，不得再有贰心！\n";
    }
}
string ask_leadership()
{
        object ob;
        if (this_player()->query("class") != "officer")
                return RANK_D->query_respect(this_player()) +
                "与朝廷素无来往，不知此话从何谈起？";
        if (this_player()->query("pin") > 3)
                return "你官品太低，还看不了「资治通鉴」。";
        if (query("book_count") < 1)
                return "为官之道需要研究古人著作，不过「资治通鉴」已经被人拿走了。";

        add("book_count", -1);
        ob = new(__DIR__"obj/book_tongjian");
        ob->move(this_player());
        return "为官之道需要研究古人著作，这本「资治通鉴」你拿回去好好钻研。";
}

string ask_strategy()
{
        object ob;
        if (this_player()->query("class") != "officer")
                return RANK_D->query_respect(this_player()) +
                "与朝廷素无来往，不知此话从何谈起？";
        return "行军打仗要钻研古代兵书，" + RANK_D->query_respect(this_player()) + "可以去问问多隆多总管。";


}*/
/*int accept_object(object me, object ob)
{
        int gem;
        int *gem_level;
        object gem_ob;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, me) ) return 0;

	if (me->query("class") != "officer")
	{
		tell_object(me, "你无缘无故给我这个干什么啊？\n");
		return 0;
	}

	if (me->query("pin") > 2)
	{
		tell_object(me, "你官阶太低，还没必要作这个任务。\n");
		return 0;
	}

	if ( (string)ob->query("name") == YEL"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
	{
		if (!me->query_temp("jing/p1"))
		me->set_temp("jing/p1", 1);
		else
		{
			tell_object(me, "这本经书你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == HIY"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
	{
		if (!me->query_temp("jing/p2"))
		me->set_temp("jing/p2", 1);
		else
		{
			tell_object(me, "这本经书你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == BLU"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
	{
		if (!me->query_temp("jing/p3"))
		me->set_temp("jing/p3", 1);
		else
		{
			tell_object(me, "这本经书你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == HIB"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
	{
		if (!me->query_temp("jing/p4"))
		me->set_temp("jing/p4", 1);
		else
		{
			tell_object(me, "这本经书你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == RED"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
	{
		if (!me->query_temp("jing/p5"))
		me->set_temp("jing/p5", 1);
		else
		{
			tell_object(me, "这本经书你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == HIR"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
	{
		if (!me->query_temp("jing/p6"))
		me->set_temp("jing/p6", 1);
		else
		{
			tell_object(me, "这本经书你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == WHT"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
	{
		if (!me->query_temp("jing/p7"))
		me->set_temp("jing/p7", 1);
		else
		{
			tell_object(me, "这本经书你已经给过我了啊？\n");
			return 0;
		}
	}
	if ( (string)ob->query("name") == HIW"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
	{
		if (!me->query_temp("jing/p8"))
		me->set_temp("jing/p8", 1);
		else
		{
			tell_object(me, "这本经书你已经给过我了啊？\n");
			return 0;
		}
	}
	call_out("destroy", 1, ob);
	if (	   me->query_temp("jing/p1")
		&& me->query_temp("jing/p2")
		&& me->query_temp("jing/p3")
		&& me->query_temp("jing/p4")
		&& me->query_temp("jing/p5")
		&& me->query_temp("jing/p6")
		&& me->query_temp("jing/p7")
		&& me->query_temp("jing/p8") )
	{
		me->delete_temp("jing");
		message_vision("$N大喜道：“干得好！”。\n", this_object());
		if (me->query("score") < 1500)
		{
			me->add("score", 10);
			tell_object(me, "你对朝廷的贡献度增加了。\n");
		}
		me->add("chaoting/jing", 1);
                if (me->query("chaoting/jing") > 1)
		{
	                tell_object(me, "康熙对你说到：“爱卿功勋卓著，寡人就给你一点奖励吧。”\n");
			gem = me->query("chaoting/jing") / 5 + 2;
			if(gem > 4) gem = 4;
			gem_level = ({7500 + (gem - 2) * 1000, 7500 + (gem - 2) * 1000});
			gem_ob = GEMDROP_D->gem_drop(gem_level);
			if(gem_ob->move(me))
			message_vision(HIR"康熙敕给$N一颗" + gem_ob->name() + HIR"。\n "NOR, me);
		}
		me->add("combat_exp", 10000);
		tell_object(me, "你的经验增加了。\n");
	}
	else
		tell_object(me, RANK_D->query_respect(me) + "快把剩下的经书找齐给我吧。\n");

        return 1;
}
void destroy(object ob)
{
	destruct(ob);
}*/
void die()
{
	object obj,me;
	me = this_object();
	if( objectp(obj = me->get_damage_origin_object()) )
	{
		 obj->apply_condition("bjkiller", 500 + obj->query_condition("bjkiller"));
	}
    	::die();

	return;
}
