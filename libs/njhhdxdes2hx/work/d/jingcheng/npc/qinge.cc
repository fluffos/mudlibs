// qinge.c
//by dwolf

#include <ansi.h>
inherit NPC;

string tell_story();
string ask_me();
string *make_msg = ({  
    HIW"\停了片刻，秦歌说道，“罢了，我就给你说了吧。”\n\n"NOR,    
    HIG"这是我一生中最伤心的事，我闷了十几年，今日要一吐为快。\n\n"NOR,
    HIG"这得从柳玉儿的母亲说起：昔日天下第一美人，是柳嫣然，也就是玉儿她妈。\n\n"NOR,
    HIG"当年我和嫣然一见钟情，共结连理，不久有了玉儿，我们本来非常幸福，但有 \n\n"NOR,
    HIG"一天突然祸从天降。那年玉儿才三岁，我应宰相刘罗锅邀请，去训练禁军，没  \n\n"NOR,
    HIG"想到虎丘五虎趁此机会，抢走她们母子，这帮混蛋想侮辱我妻，但嫣然誓死不  \n\n"NOR,
    HIG"从，横刀自尽。那帮家伙失望之余，竟然把我三岁的玉儿卖了。当我得到消息  \n\n"NOR,
    HIG"后，星夜赶奔虎丘，手刃五贼，但嫣然已去，玉儿无踪，我－－－－唉------- \n\n"NOR,
    HIG"说到这儿，这位传奇人物已禁不住流下泪来。\n\n"NOR
});

void create()
{
	set_name(YEL"秦歌"NOR, ({ "qin ge", "qin" }));
	set("gender", "男性");
	set("title", RED"多情刀客"NOR);
	set("age", 40);
	set("long",
        	MAG"他中等年纪，看上去很成熟，给人饱经沧桑的样子。他愁眉紧锁，看上去
满怀心事。\n"NOR);

	set("attitude", "peaceful");

	set("str", 40);
	set("int", 40);

	set("combat_exp", 2000000);

	set("inquiry", ([
		"家信" 	: (: ask_me :),
		"柳玉儿"  : (: tell_story :),
	]) );  
	set("count", 1);
	
	set("chat_chance", 10);
	set("chat_msg", ({
		HIM"秦歌吟道：“前不见古人，后不见来者，知我者谓我心忧，不知我者谓我何愁。” \n"NOR,
		HIM"秦歌叹道：“江湖风云出我辈，一入江湖岁月摧。”\n"NOR,
	}) );
	
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 20);

	set_skill("dodge", 200);
	set_skill("blade", 200);
	set_skill("parry", 200);
	set_skill("force", 200);
	set_skill("unarmed", 100);
		
	setup();

	carry_object("/d/jingcheng/npc/obj/dblade.c")->wield();
	carry_object("/d/jingcheng/npc/obj/cloth")->wear(); 
}      

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (query("count") < 1)
		return RED"抱歉，你来晚了，已经有人帮我传信了。"NOR;

/*	ob = new("/d/jingcheng/npc/obj/yupei.c");     */
	ob = new(__DIR__"obj/letter.c");
	ob->move(this_player());

	add("count", -1);

	message_vision(YEL"\n秦歌叹了一口气，点点头，从胸前取出一封家信交给$N。\n\n"NOR, this_player());

	return YEL"你既然知道在我的事，也是有缘，这封信就给你了。如果你见到\n"
		"玉儿，就告诉她，我一直在找她。让她拿着信后到小秦淮酒家找我。"NOR;
}


string tell_story()
{
	object who;
    who=this_player();
	call_out( "make_stage", 2, who, 0 );
	return CYN"秦歌盯着你看，似乎要看穿你。“你怎么问这个问题呢？”\n"NOR;
}

void make_stage(object who,int stage)
{
	tell_object(who,make_msg[stage]);
	if (++stage < sizeof(make_msg) ) {
		call_out( "make_stage", 2, who, stage);
		return;
	}
	return;
}
         
		
