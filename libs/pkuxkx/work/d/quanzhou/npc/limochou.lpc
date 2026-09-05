// Jay 3/21/96
// modified by iszt@pkuxkx, 2007-01-24

#include <ansi.h>

inherit NPC;

int do_look(string);
int ask_me();
int ask();
void heal();
void do_chat();
int auto_perform();
string *rnd_cmd = ({"killall","slap4","blush","slap","heng1","cold","starefy","consider"});

void create()
{
	set_name("李莫愁", ({ "li mochou", "li", "mochou" }));
	set("long", "她生得极为美貌，但冰冷的目光让人不寒而栗。\n");
	set("nickname", HIR"赤练"HIW"仙子"NOR);
	set("gender", "女性");
	set("rank_info/respect", "道姑");
	set("age", 27);
	set("per", 28);
	set("attitude","heroism");
	set("str", 30);
	set("dex", 35);
	set("con", 17);
	set("int", 25);
	set("shen_type", -1);
	set("count",3);

	set_skill("cuff", 80);
	set_skill("meinu-quan",80);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("throwing", 100);
	set_skill("xianyun",100);
	set_skill("whip",100);
	set_skill("changhen-bian",100);
	set_skill("yunu-xinfa",100);
    set_skill("sanwu-shou",100);
    set_skill("chilian-shenzhang",100);
    set_skill("hand",100);
    set_skill("strike",100);
	set("book_count",1);
	map_skill("force", "yunu-xinfa");
	map_skill("whip","changhen-bian");
	map_skill("dodge","xianyun");
	map_skill("parry","changhen-bian");
	map_skill("cuff","meinu-quan");
    map_skill("hand","sanwu-shou");
    map_skill("strike","chilian-shenzhang");
	prepare_skill("hand","sanwu-shou");
    prepare_skill("strike","chilian-shenzhang");
	set("jiali",50);

	set("combat_exp", 150000);
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);

	set("inquiry", ([
		"name" : "站远点！",
		"here" : "我不是本地人，不知道。",
		"情" : "你如何能理解其中相思之苦、惆怅之意？",
		"陆展元" : "你问那个薄情的小畜生做什么？",
		"何沅君" : (: ask_me :),
                "鞭法秘笈" : (: ask :), 
                "鞭法秘籍" : (: ask :), 
		"小龙女" : "那是我的师妹。你问她想干什么？",
		"林朝英" : "那是我的师祖，不该你问的你别问，小心我宰了你。",
        "五毒神掌" : "这是我的独门绝技，如果你能把我遗失在江湖的《赤炼神掌补遗》找回来，我可以考虑教你。",
		]) );

	setup();
	set("chat_chance", 1);
	set("chat_msg", ({
		"李莫愁纵声而歌，音调凄婉，歌道：「问世间，情是何物，直教生死相许？」\n",
		"李莫愁歌道：「天南地北双飞客，老翅几回寒暑？」\n",
		"李莫愁唱道：「欢乐趣，离别苦，就中更有痴儿女。」\n",
		"李莫愁唱道：「君应有语，渺万里层云，千山暮雪，只影向谁去？」\n",
		"李莫愁词意悲切，声调更是哀怨，唱道：「横汾路，寂寞当年箫鼓。荒烟依旧平楚。」\n",
		"李莫愁歌道：「招魂些何嗟及，山鬼自啼风雨。」\n",
		"李莫愁唱道：「天也妒，未信兴，莺儿燕子俱黄土。」\n",
		"李莫愁唱道：「千秋万古，为留待骚人，狂歌痛饮，来访雁丘处。」\n",
		(: do_chat :),
	}) );
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :)
	}));
	carry_object("/d/quanzhou/obj/fuchen")->wield();
	carry_object("/d/wudang/obj/greenrobe")->wear();
	carry_object("/d/quanzhou/obj/bp_zhen");
	carry_object("/d/quanzhou/obj/jieyao");
}

void init()
{
	::init();
	add_action("do_look","look");
	add_action("do_look","hug");
	add_action("do_look","mo");
	add_action("do_look","18mo");
	add_action("do_look","kiss");
}

void do_chat()
{
	object *ob, *player;
	object me = this_object();

	if(base_name(environment(me)) == "/d/quanzhou/nanhu")
		return;
	if(!random(5))
		CHANNEL_D->do_channel(this_object(), "bd", "奇怪，我这是在哪里呢？");
	ob = all_inventory( environment( me ));
	for(int i=0; i<sizeof(ob); i++)
	{
		if( living(ob[i]) && !random(5))
		{
			if(userp(ob[i]) && random(3))
			{
			if(random(2))
			CHANNEL_D->do_channel(this_object(), "bd", rnd_cmd[random(sizeof(rnd_cmd))]+" "+ob[i]->query("id"), 1);
			if(random(2))
			CHANNEL_D->do_channel(this_object(), "bd", "快说，是不是你这个"+RANK_D->query_rude(ob[i])+"把我弄到这里来的？");
			return;
			}
	
			if(ob[i]->query("gender")=="男性" && random(5))
			{
			if(random(2))
			CHANNEL_D->do_channel(this_object(), "bd", rnd_cmd[random(sizeof(rnd_cmd))]+" "+ob[i]->query("id"), 1);
			if(random(2))
			CHANNEL_D->do_channel(this_object(), "bd", "怎么我会跟"+ob[i]->name()+"这个臭男人在一起的？");
			return;
			}
		}
	}
	return;
}

int ask_me()
{
	object me;
	me = this_player();
	message("vision",
		HIY "李莫愁冷笑一声：「我这就送你去见她。」\n"
		"李莫愁决心杀死" + me->name() +"！\n"
		NOR, environment(), this_object() );
	kill_ob(this_player());
	return 1;
}
int ask()
{
	object me;

	me = this_player();
	message("vision",
		HIY "李莫愁冷笑一声：「哼，想抢我秘笈，我这就送你地狱。」\n"
		"李莫愁决心杀死" + me->name() +"！\n"
		NOR, environment(), this_object() );
	if (query("book_count")==1)
	carry_object("/d/gumu/obj/book3");
	set("book_count",0);
	kill_ob(this_player());
	return 1;
}

int do_look(string target)
{
	object me;

	me = this_player();
	if (target=="li" || target=="li mochou" || target=="mochou" ) 
	if ((string)me->query("gender") != "女性"&& (int)me->query("age")>14 && (int)me->query("combat_exp")>100000 && living(this_object())) {
		message("vision",
			HIY "李莫愁大怒，喝道：我最恨你们这些薄情的臭男人！去死吧！\n"
			"李莫愁决心杀死" + me->name() +"！\n"
			NOR, environment(), this_object() );
		kill_ob(this_player());
	}
}	   

void heal()											 
{													   
	object ob=this_player();						

	if (ob->query("eff_qi") < ob->query("max_qi"))  
	{											   
		command("exert heal");				  
		command("enforce 50");				 
		return;								 
	}											   

	if (ob->query("qi") < ob->query("eff_qi"))	  
	{											   
		command("exert recover");			   
		return;								 
	}											   

	if (ob->query("jing") < ob->query("eff_jing"))  
	{
		command("exert regenerate");			
		return;
	}	

}

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object ob = new("/d/quanzhou/obj/bp_zhen");

	if ( !objectp(target) ) return 0;
	if( me->is_busy() ) return 0;

	if (me->query("count") != 0 && !me->is_busy() && random(3) == 1) 
	{
	message_vision(HIW"$N袖袍一挥，一枚冰魄银针自袖底急射而出！\n"NOR,me);
	me->add("count",-1);
	if(random(me->query_skill("throwing",1)) > random(target->query_skill("dodge",1)))
	{
		message_vision( HIC "结果$N一不留神被银针刺中。\n" NOR, target);
		tell_object(target, RED"你突然感到一阵头晕，原来针上有毒！\n"NOR);
		F_POISON->poison_attack(me,target,"bing_poison",50 + target->query_condition("bing_poison"));
		target->receive_damage("qi",100,me);
		target->receive_wound("qi",random(80)+20,me);
		ob->move(target);
	}
	else
	{
		message_vision( HIC "\n可是$N看到了暗器，一闪身躲开了。\n" NOR, target);
		ob->move(environment(target));
	}
	}
	return 1;
}

int dest(object lizi)
{
	if(lizi)
	destruct(lizi);
	return 1;
}

int accept_object(object me, object lizi)
{
    
	if( lizi->query("id") != "chilian buyi")
	return notify_fail("李莫愁道：这是何物？\n");
    if (!lizi->query("chilian_buyi"))
    return notify_fail("李莫愁道：你想作死啊？\n");
    if (lizi->query("owner")!=me->query("id"))
    return notify_fail("李莫愁道：你从哪里偷来的？\n");
    if (me->query("赤炼五毒"))
    return notify_fail("李莫愁道：哼！显摆！\n");
    else
		{
			command("say 不错，这就是我遗落的《赤炼神掌补遗》，好吧，作为答谢，我把五毒神掌的运功诀窍传授于你。");
            message_vision("李莫愁对$N讲解五毒神掌的运功诀窍。\n",me);
			me->set("赤炼五毒",1);
			call_out("dest",1,lizi);
		}
	return 1;
}