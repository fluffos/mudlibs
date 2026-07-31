// rong.c 黄蓉
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_chicken();
int ask_zhou();
int ask_husband();
void create()
{
    set_name("黄蓉", ({"huang rong", "huang", "rong"}));
    set("title", "桃花岛主独生爱女");
    set("gender", "女性");
    set("age", 18);
        set("long", 
                "她方当韶龄，不过十五六岁年纪，肌肤胜雪，娇美无比，容色绝丽，不可逼视。\n"
                "她长发披肩，全身白衣，头发上束了一条金带，灿然生光。一身装束犹如仙女一般。\n");
        set("gender", "女性");
        set("rank_info/rude", "小妖女");

    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 28);
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 8800);
    set("eff_qi", 8800);
    set("max_qi", 8800);
    set("jing", 8000);
    set("eff_jing", 4800);
    set("max_jing", 4000);
    set("neili", 8000);
    set("max_neili", 8000);
    set("jiali", 20);
	
    set("combat_exp", 1800000);
    set("score", 0);
	
    set_skill("force", 160);
    set_skill("bibo-shengong", 280);
    set_skill("unarmed", 180);
    set_skill("xuanfeng-leg", 280);      // 旋风扫叶腿
    set_skill("strike", 180);            // 基本掌法
    set_skill("luoying-zhang", 280);
    set_skill("dodge", 150);
    set_skill("anying-fuxiang", 270);
    set_skill("parry", 185);
    set_skill("literate",150);           // 读书识字
    set_skill("sword", 180);
    set_skill("luoying-shenjian",280);
	
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("strike" , "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "strike.pikong" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
        }));
	
    create_family("桃花岛", 2, "弟子");

	set("inquiry", ([
                "name" : "在下黄蓉，是桃花岛主的女儿。",
                "rumors" : "我爹爹在这里布了一个八卦阵，必须精通八卦的卦象才能通过。",
                "郭靖" : "靖哥哥虽然有点傻乎乎的，对我却是真心的。",
                "黄蓉" : "你找我有什么事吗？",
                "黄药师" : "我爹爹聪明绝顶，文才武学，书画琴棋，算数韬略，医卜星相，奇门五行，无一不精。",
                "爹爹" : "我爹爹聪明绝顶，文才武学，书画琴棋，算数韬略，医卜星相，奇门五行，无一不精。",
                "东邪" : "我爹爹聪明绝顶，文才武学，书画琴棋，算数韬略，医卜星相，奇门五行，无一不精。",
                "周伯通" : "是那个被关在山洞里的怪人吗？有一次我穿过八卦阵去玩，和他聊了半天呢。",
                "八卦阵" : "是爹爹按八卦的卦象排的，不同的方向表示爻的变化与否，每三爻为一卦，八卦按顺序都走对就过阵了。",
                "爻" : "这也不知道？我没法帮你了。",
                "丈夫" : (: ask_husband :),
                "夫君" : (: ask_husband :),
		"黄药师" : "爹爹呀, 不在厅里麽? ",
		"郭靖"   : "怎么? 你有我靖哥哥的消息吗? ",
		"洪七公" : "师父他老人家就喜欢吃叫化鸡! ",
		"叫化鸡" : (: ask_chicken :),
	      	"周伯通": (: ask_zhou :),
	]) );

    setup();
    carry_object(__DIR__"obj/ruanwei")->wear();
    carry_object(__DIR__"obj/shudai")->wear();

}

init()
{
	object ob;
	mapping myfam;
        
	::init();
	add_action("do_kiss", "kiss");
	if (interactive(ob = this_player()) && !is_fighting()) {
		myfam = (mapping)ob->query("family");
		if ((!myfam || myfam["family_name"] != "桃花岛") &&
			(!wizardp(ob)))
		{
			remove_call_out("saying");
			call_out("saying",2,ob);
		}
	}
}
int ask_husband()
{
        object nvxu, user;
        object ob = this_player();
        string id;
        int user_load = 0;

        if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
                nvxu = load_object("/clone/npc/huang-son-in-law");
        id = nvxu->query("winner");
        if (id == ob->query("id")) {
                if (nvxu->query("death_count") < ob->query("death_count"))
                        say("黄蓉低下头，弄着衣角，什么话也不说。");
                else
                        message_vision(CYN"黄蓉含情脉脉地看着$N，眼光娇羞无限。\n"NOR, ob);
        }
        else {
/*                if (!(user = find_player(id))) {
                        user = new(USER_OB, id);
                        if (!user->restore()) {
                                say("黄蓉低下头，弄着衣角，什么话也不说。");
                                destruct(user);
                                return 1;
                       }
                        user_load = 1;
                }*/
                if (nvxu->query("death_count") < user->query("death_count"))
                        say("黄蓉低下头，弄着衣角，什么话也不说。");
                else
                        command("say 我的丈夫就是" + nvxu->query("name") + "！");
                if (user_load) destruct(user);
        }
        return 1;
}
int do_kiss ( string arg )
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="rong" )
     return 0;
   
   if ( (string) ob -> query ("gender") == "男性" )
      command ("say 救命啊！救命啊！"+ ob->query("name") + "要非礼我！\n") ;
   else
      message_vision("\n黄蓉对$N笑道：“好姐姐不要这样，我怕痒！”\n", ob);
   return 1 ;
}

void saying(object ob)
{
    if (!ob || environment(ob) != environment())
        return;
    if ((string)ob->query("gender") == "男性")
        message_vision("\n黄蓉面现惊奇之色，打量了$N一眼，说到：“你是什么人，"
        "竟敢乱闯我的闺房？\n再不滚出去，看我怎么整你！”\n", ob);
    else
        message_vision("\n黄蓉看了看$N，说到：“好久没生人来过了，"
        "不知这位姐姐可有我靖哥哥的消息？\n", ob);
}

void attempt_apprentice(object ob)
{
   if ((int)ob->query_temp("marks/蓉儿")==1)
   {
      say( "黄蓉一脸笑意：“多谢你带来靖哥哥的口信!”\n");
      say( "黄蓉轻轻一笑：我不收徒的..可也不能让你白来，这软猥甲就送给你吧．\n");
      new("/kungfu/class/taohua/obj/ruanwei")->move(ob);
      tell_object(ob,"黄蓉从身上脱下一件软猥甲递给你。\n");
      ob->set_temp("marks/蓉儿",2);
   }
   else
    command("say 我年纪这么小就收徒弟，岂不让人笑掉大牙！");
}

string ask_chicken()
{
	if (this_player()->query_temp("marks/鸡", 1))
		return "你这个人怎么这么烦？老说车轱辘话！\n";
	else
	{
		say("蓉儿神往地说：叫化鸡可是杭州著名特产，我爹当年费了好大的劲才搞到了制作\n"
			"它的秘方。你问它来干什么？\n");
		this_player()->set_temp("marks/鸡", 1);
		return "你可以出去了。\n";
	}
}

int ask_zhou()
{
	object me = this_player();
	if (me->query_temp("jiuyin/huang")) {
		command("say 他好像是被爹爹关在岛上，不知道为什么。");
		command("say 我天天都给他送饭，不过今天爹爹要我好好练些奇门算数。");
		command("angry");
		command("say 这样吧，你帮我送去可好？");
		if (!present("fan he", me)) {
			new(__DIR__"obj/fanhe")->move(this_object());
			command("give fan he to " + me->query("id"));
		}
		me->delete_temp("jiuyin/huang");
		return 1;
	}
	return 0;
}
