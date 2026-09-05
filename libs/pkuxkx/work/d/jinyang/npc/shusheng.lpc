// 书生
// created by Zine 5 Sep 2010

inherit NPC;


int ask_knowledge();
void create()
{
	set_name("书生", ({ "shu sheng","shusheng","sheng"}) );
	set("title", "酸气纵横八千里");
	set("gender", "男性" );
	set("long", "这是一个穿着一件月白长衫的书生，似乎很有学问。\n");
	set("str", 40);
	set("int", 40);
	set("dex", 40);
	set("kar", 40);       
	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 200);
	set("max_jing", 200);
	set("eff_jingli", 200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("shen_type", 100);
    set("combat_exp", 1000000);
    set_skill("force", 200);
	set_skill("cuff", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set("age", 15+random(15));
       	set("inquiry", ([
        	"学问" : (: ask_knowledge :),
         	"知识" : (: ask_knowledge :),
         	

	]));
	set("chat_chance", 10);
	set("chat_msg", ({
		"书生嘟囔说道: 进京赶考，我呸，我的学问全村第一了，还考什么考？\n",
		(: random_move :)
	}) );
	setup();
	carry_object("/d/jinyang/obj/heibuxie")->wear();
    carry_object("/d/jinyang/obj/ybcloth")->wear();
}

void init()
{
	object ob;
	::init();
	if( (ob = this_player()) ) 
		{
			remove_call_out("talk");
			call_out("talk", 1, ob);
		}
}

void talk(object ob)
{
	if( !ob || environment(ob) != environment()) 
		return;
		switch( random(5) ) 
			{
				case 0:
					command("say 学而时习之，不亦悦乎？");
                    command("say 有朋自远方来，不亦乐乎？");
					break;
				case 1:
                    command("say 其为人也孝悌而好犯上者，鲜矣。");
                    command("say 不好犯上而好作乱者，未之有也。");
					break;
				case 2:
					command("say 吾日三省乎吾身。为人谋而不忠乎？");
                    command("say 与朋友交而不信乎？传不习乎？");
					break;
				case 3:
                    command("say 君子不重则不威，学则不固。");
                    command("say 主忠信，无友不如己者，过则勿惮改。");
					break;
				case 4:
                    command("say 为政以德，譬如北辰，居其所，而众星共之。");
                    command("say 由，诲汝知之乎！知之为知之，不知为不知，是知也。");
                    break;
			}
}

int ask_knowledge()
{
	object ob=this_player();
	command("nomatch" +this_object()->query("id"));
	command("say 我可以很诚实的告诉你，我们晋阳城里，月色学问第一，我第二。");
	command("say 相信你也很同意我的观点吧？");
	command("sure " + ob->query("id"));
	return 1;
}

#include "die.h"