// hai.c 海公公
// Jay 4/6/96
//Redesign for Dongchang by Vast on 3/27/2009

#include <ansi.h>
#include <title.h>
inherit NPC;

string ask_for_zigong();
string ask_for_dongchang();
string ask_yin();

void create()
{
		string *pfm = ({"sword.pokong", "sword.biri"});
		int i = random(2);
	
        set_name("海公公", ({"hai gonggong", "hai", "gonggong"}));
        set("title", "东厂千户");
        set("long",
                "他是东厂大太监海大富，乔装改扮成商人模样出京寻欢作乐，长得既像老头又像老太太。\n"
        );

        set("gender", "无性");
        set("rank_info/respect", "公公");

        //set("attitude", "heroism");       picewolf修改，主要是为了新人不被截镖
		set("attitude", "peaceful");

        set("class", "eunuch");

        set("inquiry",([
                "自宫"  : (: ask_for_zigong :),
//                "东厂"  : (: ask_for_dongchang :),
//                "关防印": (: ask_yin :),
        ]));

        set("age", 60);
//        set("shen_type", -1);
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
                (: random_move :)
        }) );
        
     		set("chat_chance_combat", 100);
     		set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: perform_action, pfm[i] :),
                            }) );        

				create_family("东厂", 2, "官员");



setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}

void init()
{
        add_action("do_decide", "decide");
        add_action("do_join", "join");
}

string ask_for_zigong()
{
        object me;

        me = this_player();
        
        if(me->query("class") == "officer")
        	return "你乃朝廷官员，我怎敢造次......";

        if( (string)me->query("gender")=="无性" )
                return "你我同是阉人，何必开如此无聊的玩笑？";

        if( (string)me->query("gender") == "女性" )
                return "我虽已废，但一样可以给你这个小美人带来快乐，要不要试试？";

        if(me->query("shen") > 0)
        	return "你乃正人君子，何苦做这等营生。";
        	
       me->set_temp("pending/zigong", 1);
        return "自宫？这位公子相貌堂堂，何必... 我真希望能有你的那个。自宫之后，不可后悔，你若决心已定(decide)，告诉我。";
}

string ask_for_dongchang()
{
	object me = this_object();
	object player = this_player();

	mapping fam;
	int leave_age;

	if (player->query("class") == "officer")
		return "难道大人您对加入东厂也有兴趣吗？";

	if (player->query("class") == "eunuch")
		return RANK_D->query_respect(player)  + "当对东厂尽忠竭力，他日必定前途无量！";
		
	if (player->query("gender") == "男性")
	return RANK_D->query_respect(player) + "尚未净身，恐怕不适合入宫做事。";

	if (player->query("gender") == "女性")
	return "我虽已废，但一样可以给你这个小美人带来快乐，要不要试试？";

        if(player->query("shen") > 0)
        	return "你行事不够心狠手辣，东厂可不是你能进的。";
        			
	player->set_temp("chaoting/dc", 1);
			return "一般人可不敢惹咱东厂，你若加入东厂，将来定会飞黄腾达，没准还是圣上身边的红人呢。怎么样？决定加入吗？(join)";
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

int do_decide()
{
        if( !this_player()->query_temp("pending/zigong") )
                return 0;

        message_vision(
                "$N一咬牙，褪下中衣。（女玩家闭眼！）\n\n"
                "$n伸出长剑插到$N两腿之间，飞速一剜，……\n\n"
                "$N顿时惨叫一声昏了过去……\n\n",
                this_player(), this_object() );
        CHANNEL_D->do_channel(this_object(), "jh", "嗨……");
        command("hehe");
        this_player()->delete_temp("pending/zigong");
        this_player()->set("gender","无性");
//        this_player()->set("class", "eunach");//此处注释，避免bug
        this_player()->set("combat_exp",this_player()->query("combat_exp")+1000);
        //待增加内容： 自宫 -1 str, -1 con, +2 dex, +2 容貌 -1000 shen
        //是否需要将几项基本参数最小值固定设置为10的判断去掉？
        
        this_player()->unconcious();
        return 1;
}

int do_join()
{
	object player = this_player();
	int time;
	string name;
	name = player->query("name");
	if (!player->query_temp("chaoting/dc")) return 0;
		
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
		player->set("dongchang/oldname", name);
		player->set("name","小"+name[0..0]+"子");

		player->set("pin", 9);
		message_vision("$N拍着$n的肩膀说道：恭喜你成为东厂一员。\n", this_object(), player);
		player->save();
		return 1;
}

void attempt_apprentice(object ob)
{
	object yin, hai, place;
	
	if (ob->query("class") != "eunuch")
	{
		command("say " + RANK_D->query_respect(ob) + "是否有意加入东厂呢？");
		return;
	}		
		
	if(ob->query("family/master_id") == "hai dafu")
		{
			command("say " + "出门在外不方便以师徒相称，要学功夫还是回宫中再说吧！");
			return;
		}
	if(ob->query_temp("bai_hai") < 3)
		{
			command("yii " + ob->query("id"));
			command("say " + RANK_D->query_respect(this_object()) + "可是丝毫不会武功啊！");
		}
	else
		{
			ob->delete_temp("bai_hai");
			command("say " + "你既然非要学我的功夫，那就到紫禁城中东厂尚膳监找我吧！");
			tell_object(ob, "海公公给了你一颗东厂关防印。\n");
			command("say " + "印先借你用用，过段时间我会收回的。");
			tell_object(ob, "海公公急急忙忙地离开了。\n");
			yin = new("/d/beijing/dongchang/obj/guanfangyin");
			yin->move(ob);
			if(!objectp(place = find_object("/d/beijing/dongchang/shangshanjian")) )
				place = load_object("/d/beijing/dongchang/shangshanjian");
			if(!objectp(hai = present("hai dafu", place)) )
				{
				 	hai = new("/d/beijing/dongchang/npc/haidafu");
					hai->move(place);
				}
			destruct(this_object());
			return;
		}
		ob->add_temp("bai_hai", 1);
		return;
}
