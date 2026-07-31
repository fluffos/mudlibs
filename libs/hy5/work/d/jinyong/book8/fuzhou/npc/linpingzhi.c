#include <ansi.h>
inherit NPC;
int ask_me();

void create()
{
        set_name("林平之", ({ "lin pingzhi", "lin", "pingzhi" }));
        set("gender", "男性");
        set("age", 18);
        set("title", "福威镖局少镖头");
        set("long", "他就是「福威镖局」的少镖头－－林平之。\n");
        set("combat_exp", 300000);
        set("shen_type", 1);
        set("qi", 5000);
        set("max_qi", 5000);
        set("max_neili", 5000);
        set("neili", 5000);
        set("jiali", 10);
        set_skill("force", 150);
        set("per",25);
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set("inquiry", ([
                "福威镖局" : (: ask_me :),
        ]) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 200);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	object fang = present("fang renzhi",where);
	if(fang)
	{
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"还是先打发了面前这位吧！\n",this_object(),who);
		return 1;
	}
	  	if(((int)who->query("jinyong/book8")>=2))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),who);
		return 1;	
	}
	command("bow " + who->query("id"));
	message_vision("$N对$n说道： 小子一时冲动，打抱不平，杀了青城派掌门余沧海的儿子。\n",this_object(),who);
	message_vision("青城派派好手前来寻仇，福威镖局全家几乎鸡犬不留。\n",this_object());
	message_vision("我父亲为保住林家血脉，连夜送我出城，如今我只有拜师学艺，学好武功。\n",this_object());
	message_vision("林平之只要活着一天，誓报此仇！\n",this_object());
	
	i = random(800);
	who->set("jinyong/book8",2);
	who->add("combat_exp",i+6880);
	who->add("potential",i*8);
	who->add("mpgx",10);
	who->add("expmax",2);
	//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
	tell_object (who,"你赢得了"+chinese_number(i+6880)+"点经验"+
	           chinese_number(i*8)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
	call_out("leavet",1);
	return 1;
}
void leavet()
{
        object ob = this_object();
 message_vision("$N飞身向外离去！\n" NOR,this_object());
        destruct(this_object());
}