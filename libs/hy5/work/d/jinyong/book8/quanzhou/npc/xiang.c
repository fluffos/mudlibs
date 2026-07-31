// xiang.c
#include <ansi.h>
inherit NPC;
int ask_kill();
int ask_me();

void create()
{
	set_name("向问天", ({ "xiang wentian", "xiang"}));
	set("nickname", HIR "天王老子" NOR );
	set("gender", "男性");
	set("title", "日月神教光明右使");
	set("long", "他就是日月神教的光明右使。为人极为豪爽。\n");
	set("age", 45);
	set("shen_type", -1);
	
	set("str", 21);
	set("per", 28);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
	set("chat_chance", 1);
	set("inquiry", ([
		"杨莲亭"     : "这种人，该杀！\n",
		"东方不败"   : "篡位叛徒，我非杀了他不可！\n",
		"杀东方不败" : (: ask_kill() :),
		"任我行"     : (: ask_me() :),
	]));
	set("qi", 14000);
	set("max_qi", 14000);
	set("jing", 21000);
	set("max_jing", 21000);
	set("neili", 23500);
	set("max_neili", 23500);
	set("jiali", 350);
	
	set("combat_exp", 6500000);
	set("score", 0);
	
	set_skill("force", 310);
	set_skill("hunyuan-yiqi", 310);
	set_skill("dodge", 110);
	set_skill("shaolin-shenfa", 310);
	set_skill("finger", 310);
	set_skill("strike", 310);
	set_skill("hand", 310);
	set_skill("claw", 310);
	set_skill("parry", 310);
	set_skill("nianhua-zhi", 310);
	set_skill("sanhua-zhang", 310);
	set_skill("fengyun-shou", 310);
	set_skill("longzhua-gong", 310);
	set_skill("buddhism", 110);
	set_skill("literate", 110);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 500);
	set_temp("apply/damage", 200);
	set_temp("apply/attack", 200);
	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
	create_family("日月神教", 2, "光明右使");
	
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

int ask_kill()
{
	object ob,me = this_player();
	
	command("tell "+this_player()->query("id")+" 你要去杀东方不败？\n");
	message_vision(HIC "向问天对$N点了点头说：我助你一臂之力。\n" NOR,this_player());
	ob=new("/d/heimuya/npc/obj/card4");
	ob->move(me);
	tell_object(me,"向问天从怀里摸出一块令牌塞到你的手上。\n");
	return 1;
}

int ask_me()
{
	int i;
	object ob = this_object();
	object me = this_player();

  	if(((int)me->query("jinyong/book8")>=6))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),me);
		return 1;	
	}
	if(objectp(present("dizi", environment(me))))
	{
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(me) +"还是先打发了这群走狗吧！\n",this_object(),me);
		return 1;
	}	
	
	if((int)me->query("jinyong/book8")==5) {
		message_vision(HIC "$N对$n说：教主被困，已历十年。\n" NOR,ob,me);
		message_vision(HIC "现今我查出教主被困在梅庄，正打算去搭救。\n" NOR,ob,me);
		i = random(1600);
		me->set("jinyong/book8",6);
		me->add("combat_exp",i+18000);
		me->add("potential",i*14);
		me->add("mpgx",10);
		me->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (me,"你赢得了"+chinese_number(i+18000)+"点经验"+
		           chinese_number(i*14)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		me->save();
	call_out("leavet",1);
		return 1;
	}
	message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(me) +"，我们还是一起品品茶，聊聊人生吧！\n",this_object(),me);
	return 1;
}

void leavet()
{
        object ob = this_object();
 message_vision("$N飞身向外离去！\n" NOR,this_object());
        destruct(this_object());
}
