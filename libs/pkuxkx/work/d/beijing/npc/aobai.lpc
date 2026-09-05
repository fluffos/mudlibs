#include "/d/beijing/autok.h"
inherit NPC;
string ask_strategy();
void create()
{
 	set_name("鳌拜", ({
 		"ao bai",
 		"ao",
 		"bai",
 	}));
 	set("long",
 		"他就是满洲第一勇士，身穿一袭金边锦缎。他身材魁梧，\n"
 		"相貌狰狞，太阳穴高高鼓起，似乎身怀绝世武功。\n"
 	);

 	set("nickname", "满洲第一勇士");
 	set("title", "朝廷顾命大臣");
 	set("gender", "男性");
 	set("attitude", "heroism");

 	set("age", 50);
 	set("shen_type", -1);
 	set("str", 25);
 	set("int", 25);
 	set("con", 25);
 	set("dex", 25);
 	set("max_qi", 1500);
 	set("max_jing", 1500);
 	set("neili", 1500);
 	set("max_neili", 1500);
 	set("jiali", 150);
 	set("combat_exp", 1000000);

 	set_skill("force", 180);
 	set_skill("hunyuan-yiqi", 180);
 	set_skill("dodge", 180);
 	set_skill("shaolin-shenfa", 180);
 	set_skill("hand", 180);
 	set_skill("parry", 180);
 	set_skill("unarmed", 180);
 	set_skill("iron-cloth", 180);
 	set_skill("literate", 100);
 	set_skill("fengyun-shou", 180);

 	map_skill("force", "hunyuan-yiqi");
 	map_skill("dodge", "shaolin-shenfa");
 	map_skill("hand", "fengyun-shou");
 	map_skill("parry", "fengyun-shou");

 	prepare_skill("hand", "fengyun-shou");
    	set("book_count", 1);
    	set("inquiry", ([
	"为官之道" : "小皇帝的江山迟早是我的，哈哈哈哈！！",
	//"兵法战策" : (: ask_strategy :),
    	]));
     	//create_family("朝廷", 2, "官员");
         set("chat_chance_combat", 10);
         set("chat_msg_combat", ({
                 " 鳌拜怒道：你敢不让我睡觉，老子宰了你 ！\n",
                 (: command("say 老子宰了你这" + RANK_D->query_rude(this_player())+"!\n") :),
 		(: command("pain") :),
                       }) );
         set("no_get",1);
         setup();
//         carry_object(__DIR__"obj/anmenkey")->wield();
         carry_object(__DIR__"obj/jinduan")->wear();
         carry_object(__DIR__"obj/yaodai")->wear();
         carry_object(__DIR__"obj/yaoshi");
         add_money("gold", 2);
 }

void init()
{
	object ob;
	ob = this_player();
	auto_kill(ob);
        if(userp(ob) && ob->query("class") != "officer")
        {
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, ob);
	}
}
void die()
{
	object obj,me,cor;
	me = this_object();
	if( objectp(obj = me->get_damage_origin_object()) && ((obj->query_temp("tiandihui/kill_ao"))))
	{
		 obj->set_temp("tiandihui/killer",1);
	}
	if(obj) obj->set_temp("luding/ao", 1);
    	::die();

	return;
}
/*string ask_strategy()
{
        object ob;
        if (this_player()->query("class") != "officer")
                return RANK_D->query_respect(this_player()) + 
                "与朝廷素无来往，不知此话从何谈起？";
         if (this_player()->query_skill("strategy", 1) >= 140)
                return "我已经没什么好教你的了。";
        if (query("book_count") < 1)
                return "老子行军打仗百战百胜，不过我的兵书已经被人拿走了。";

        if (this_player()->query("pin") > 5)
                return "你官阶尚低，升迁以后再来问我吧。";
        ob = new(__DIR__"obj/book_weiliao");
        ob->move(this_player());
        add("book_count", -1);
        return "好吧，这本「尉缭子」你拿回去好好钻研。";

}
*/
