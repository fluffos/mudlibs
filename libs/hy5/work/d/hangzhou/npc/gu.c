//Cracked by Kafei
// /d/hangzhou/npc/gu.c
// by aln  2 / 98

inherit NPC;
string ask_jiannan();
string ask_degree();

#include <ansi.h>

string ask_book();

void create()
{
        set_name("顾炎武", ({ "gu yanwu" , "gu" }));
        set("gender", "男性");
        set("age", 55);
        set("long", 
"他又高又瘦，面目黝黑。\n"
"他字亭林，江苏昆山人士。\n");
        set("shen_type", 1);
        set("combat_exp", 2000);
        set_temp("no_kill",1);
        set("str", 20);
        set("int", 30);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 500);
        set("max_jing", 500);

        set("score", 10000);

        set_skill("dodge", 30);
        set_skill("sword", 30);
	set_skill("literate", 300);
        set("inquiry", ([
		"画" : "这是二瞻先生的丹青。",
		"二瞻" : "他乃是当今一位大画家。",
		"查士标" : "二瞻先生有位本家伊璜先生牵连在这场‘明史’大案中。",
		"伊璜" : "查伊璜, 也就是查继佐, 因大力将军所助, 免罪不究。", 
		"大力" : "大力将军乃广东提督吴六奇将军。",
		"大力将军" : "大力将军乃广东提督吴六奇将军。",
		"吴六奇" : "吴六奇将军身在曹营心在汉, 实际上是天地会洪顺堂香主。",
		"天地会" : "天地会是台湾国姓爷延平郡王郑成功手下谋主陈永华所创。",
		"陈永华" : "陈先生暗中联络老兄弟，胸口所刺八字便是会里的口号。",
		"陈近南" : "就是天地会总舵主陈永华，江湖人言道：‘平生不识陈近南，便称英雄也枉然’。",
		"口号" : "天父地母，反清复明。",
		"反清复明" : "你也要学一学当年岳武穆尽忠报国, 刺字以决你心? ",
		"岳武穆" : "岳武穆名飞字鹏举，乃抗金的名将，一生用兵如神。据说他死后留下了一部武穆遗书，其中记载着他一生戎马生涯的兵法要诀。",
		"武穆遗书" : "这部遗书最早收藏在皇宫之中，后听说铁掌帮帮主上官剑南率帮中高手，将此书偷走，不知是真是假。",
		"上官剑南" : (: ask_jiannan :),
		"学位" : (:ask_degree:),
         	"科举" : (:ask_degree:),
                 "《明书辑略》" : (: ask_book :),
                 "明书辑略" : (: ask_book :),
                 "修撰" : (: ask_book :),
                 "book" : (: ask_book :),
        ]));

	set("chat_chance", 3);
	set("chat_msg", ({
		"顾炎武高声呤道：清风虽细难吹我，明月何尝不照人？ 真是绝唱！ \n",
		"顾炎武道：如此江山，沦于夷狄。我辈忍气吞声。偷生其间，实令人悲愤填膺。\n",
		"顾炎武道：终有一日驱除胡虏，还我大汉河山，比之徒抒悲愤，更加令人气壮。\n",
		"顾炎武道：当今之世，便真有桃源乐土，咱们也不能独善其身，去躲了起来。\n",
        }) );
        setup();

        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_yes","yes");
	add_action("do_no","no");
	::init();
}

string ask_jiannan()
{
	object me = this_object();
	object ob = this_player();
        
	if (present("zitie", ob)) return "顾炎武道：我不是已经告诉你了么，怎么还问？\n";
        command("say 这位上官帮主乃是一位侠义之士，铁掌帮自他接任后，力加整顿，多行侠
义之事，不过数年声势大振，在江湖上侵寻已可以与北方的丐帮分庭抗礼了。只是后来忽
然消声匿迹，不知所踪了。看来想找到武穆遗书，必先找到上官帮主才行！\n");
        command("look " + ob->query("id"));
        command("say 看来" + RANK_D->query_respect(ob) + "也是我辈中人，老朽这里有一幅字帖送给你，希望你
能不忘驱除胡虏，还我河山的志向！");
	new("/d/tiezhang/obj/zitie")->move(ob);
        message_vision("$N交给$n一幅字帖。\n", me, ob);
        return "";
}

int is_apprentice_of() 
{
	return 1;
}

int recognize_apprentice(object ob)
{
	int money = 50, level = ob->query_skill("literate", 1);

	if (level > ob->query("int")*10){
		message_vision(CYN"\n$N对着$n端详了一番道：“你因先天所制，已无法再进修更高深的学问了。”\n"NOR, this_object(), ob);
                message_vision(CYN"$N又点了点头：“"+ask_degree()+"”\n\n"NOR, this_object());
		return 0;
	}
	
	if (level > 29) money = 100;
	if (level > 59) money = 500;
	if (level > 89) money = 1000;
	if (level > 119) money = 2500;

	ob->delete_temp("mark/literate");
	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2: write("你现在的学费是每次" + MONEY_D->money_str(money) + "，请备好零钱。\n");
			return 1;
	}
        ob->set_temp("mark/literate", 1);
        return 1;
}

void kill_ob()
{
	if(!is_killing(this_player()->query("id")))
        	command("chat* !!!");
        this_player()->start_busy(2);
        ::kill_ob(this_player());
}


int accept_object(object who, object ob)
{
	object me = this_object();

        
        if (!who || environment(who) != environment()) return 0;
        if (!objectp(ob) ) return 0;
        if (!present(ob, who)) return notify_fail("你没有这件东西。");

        if (userp(ob)){
		command("fear "+(string)who->query("id"));
		command("say 你这粗人，怎么做出这等事来？");
		return 0;
	}

        if (ob->query("id") == "tu juan") {
		command("ah " + who->query("id"));
		command("say 真是想不到啊！竟然能见到" + ob->query("name") + "真迹！\n");
		message_vision("$N拿起$n仔细地欣赏着。\n", me, ob);
		who->set_temp("gu_gold", 100);
		remove_call_out("destroying");
		call_out("destroying", 1, ob);            
		remove_call_out("ask");
		call_out("ask", 4, me, ob, who);
		return 1;
	}
        else if (ob->query("id") == "xiang shi") {
		command("ah");
		command("say 东汉画像石！你是从哪里搞到的？\n");
		message_vision("$N拿起$n仔细地欣赏着。\n", me, ob);
		who->set_temp("gu_gold", 50);
		remove_call_out("ask");
		call_out("ask", 4, me, ob, who);
		return 1;
	}
        else if (ob->query("id") == "kuaixueshiqing tie") {
		command("fly");
		command("say 快雪时晴帖！王羲之的真迹！！\n");
		message_vision("$N拿起$n仔细地欣赏着。\n", me, ob);
		who->set_temp("gu_gold", 250);
		remove_call_out("ask");
		call_out("ask", 2, me, ob, who);
		return 1;
	}
        else if (ob->id("xi shan xing lv tu")) {
		command("jump " + who->query("id"));
		command("say 范宽的溪山行旅图！我找它好久了！！\n");
		message_vision("$N拿起$n仔细地欣赏着。\n", me, ob);
		message_vision("$N把玩了半天，叹道：可惜可惜，这是无价之宝，老夫已经买不起了。\n", me);
	}
        else if (ob->id("ou xie pu")) {
		command("nod " + who->query("id"));
		command("say 老夫也略通棋理，看来这是一张很高深的棋谱，你可以去找识货的人。\n");
	}
        else if (ob->id("guang ling san")) {
		command("nod " + who->query("id"));
		command("say 老夫也略通音律，不过这本琴谱高深莫测，你还是去找识货的人吧。\n");
	}
        return 0;
}

void ask(object ob, object obj, object me)
{
	if(!me || environment(me) != environment()){
		command("say 咦，人呢？");
if (obj)
		destruct(obj);
		return;
	}
	command("hmm "+me->query("id"));
	message_vision(HIY"$N说道：在下极其喜爱这" + "东西" + HIY"，不知这位" + RANK_D->query_respect(me) + "能(yes)不能(no)忍痛割爱呢？\n"NOR, ob, me);
	me->set_temp("gu_answer", 1);
if (obj)
	destruct(obj);       
}

int do_yes()
{
	object me = this_player();

	if (!me->query_temp("gu_answer")) return 0;
	message_vision(CYN"$N连忙对$n一鞠躬，答道：先生竟然喜爱，那就当晚辈送给先生的礼物吧。\n"NOR,me, this_object());
	me->set_temp("gu_yes", 1);
	me->delete_temp("gu_answer");	
	remove_call_out("answer");
	call_out("answer", 3, me);
	return 1;
}

int do_no()
{
	object me = this_player();

	if (!me->query_temp("gu_answer")) return 0;
	message_vision(CYN"$N面有难色：这个…这个…\n"NOR, me);
	me->delete_temp("gu_answer");
	remove_call_out("answer");
	call_out("answer", 4, me);
	return 1;
}

int answer(object me)
{
	int amount;
	object n_money, ob = this_object();

	if (!me->query_temp("gu_yes")) {
		command("pat "+me->query("id"));
		command("say 哈哈，我知你也舍不得。这样吧，就当是我求你，我再给双倍价钱。");
		message_vision("说着$N不由$n分说，塞给$n几锭黄金，就拿进内屋里去了。\n", ob, me);
		n_money = new("/clone/money/gold");
		n_money->move(me);
		amount = me->query_temp("gu_gold"); 
		n_money->set_amount(amount);
		me->delete_temp("gu_gold");
	}
	else {
		command("haha");
		command("say 好，那我就多谢你了！");
		me->delete_temp("gu_yes", 1);	
		me->delete_temp("gu_gold");
		return 1;
	}
}

void die()
{
	object killer;
	
	if(objectp(killer = query_temp("last_damage_from")) ){
                killer->add("shen", -5000);      
	        killer->apply_condition("killer", killer->query_condition("killer")+100);
	        command("chat "+killer->name()+"奸诈险恶，竟然背叛我朝，投靠清廷...");
	        }
	::die();
}	
	 
	
string ask_degree()
{
     	object me = this_player();

     	string title,newtitle;
     	int level;

        level = me->query_skill("literate",1);
        if (!level || level < 1 )
                newtitle = "文盲";
        else if (level < 10)
                newtitle = "学童";
        else if (level < 20)
                newtitle = "童生";
        else if (level < 30)
                newtitle = "书生";
        else if (level < 40)
                newtitle = "秀才";
        else if (level < 50)
                newtitle = "举人";
        else if (level < 60)
                newtitle = "解元";
        else if (level < 70)
                newtitle = "贡士";
        else if (level < 80)
                newtitle = "会元";
        else if (level < 100)
                newtitle = "进士";
        else if (level < 120)
                newtitle = "庶吉士";
        else if (level < 130)
                newtitle = "传胪";
        else if (level < 140)
                newtitle = "探花";
        else if (level < 150)
                newtitle = "榜眼";
        else if (level < 160)
                newtitle = "状元";
        else if (level < 170)
                newtitle = "翰林";
        else if (level < 180)
                newtitle = "学士";
        else if (level < 200)
                newtitle = "内阁大学士";
        else if (level < 230)
                newtitle = "内阁首辅";
        else if (level < 250)
                newtitle = "文坛领袖";
        else if (level < 270)
                newtitle = "文学大宗师";
        else newtitle = "圣人";
        
        title =  newtitle + " " + me->query("name") + 
                "(" + capitalize(me->query("id")) + ")";
        me->set_temp("apply/short", ({title}));

        return "凭阁下的学识，依老夫看，你可以做一名"+newtitle+"。";
}


string ask_book()
{
        object ob;

        if( !(ob = present("mingshi", this_player())) )
                return "没有原稿，我怎么修撰？";

        if( ob->query("checked") )
                return "我已经修撰过此书了。";

        ob->set("checked", 1);
        message_vision("顾炎武将书阅后修改了几处谬误，同时也给$N讲解了一下。\n", this_player());
        if( (int)this_player()->query_skill("literate", 1) < 60 )
                this_player()->improve_skill("literate", 
                          10 * this_player()->query("int"));

        return "修撰明史乃是一件美事，老夫已尽力而为了。";
}

