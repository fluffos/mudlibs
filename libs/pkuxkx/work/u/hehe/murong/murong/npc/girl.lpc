//girl.c
//by hehe
//2003.3.21
#include <ansi.h>
inherit NPC;
int ask_me();

void create()
{
	set_name("绿衣女郎", ({ "girl" }));
    set("gender", "女性");
    set("age", 18);

    set("long", "一个天生丽质的女郎，正在唱着听不懂得歌谣。\n");
    set("attitude", "friendly");
    set("combat_exp", 1000);
    set("shen_type", 1);
    set_skill("unarmed", 20);
    set_skill("dodge", 20);
    set_skill("parry", 20);
	set_temp("apply/attack", 10);
    set_temp("apply/defense", 10);
    set("inquiry", ([
		"姑苏慕容" : "我们姑苏慕容名扬天下，天下人人尽知！",
		"参合庄" : "参合庄的名字，外边人勿会晓得，这位从啥地方听来?",
        "拜庄" : (: ask_me :),
    ]) );

    setup();

}

int ask_me()
{
	command("say 想必你是少庄主的客人吧，请上船吧。\n");
	this_player()->set_temp("marks/拜",1);

	return 1;
}
