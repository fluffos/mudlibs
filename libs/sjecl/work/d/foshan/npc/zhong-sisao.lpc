// zhong.c 钟四嫂 

#include <ansi.h>

inherit NPC;

int ask_me();

void create()
{
	set_name("钟四嫂", ({ "zhong sisao","zhong","sisao" }));
	set("long",
		"她头发散乱，脸上、衣上、手上全是鲜血，手中抓着一柄菜刀，哭一
阵，笑一阵，指手划脚，原来是个疯子。\n");
	set("gender", "女性");
	set("age", 35);

	set("str", 20);
        set("int", 15);
        set("con", 20);
        set("dex", 15);

	set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);

        set("jingli",100);
        set("max_jingli",100);
        set("jiali", 1);   
	set("combat_exp", 2000);

        set("inquiry", ([
		"钟小三"   : (: ask_me :),
                "凤天南": "老天爷生眼睛呀，我那小三子可没偷人家的鹅吃啊！\n",
]) );


	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	this_player()->set_temp("marks/feng",1);
	write("钟四嫂突然大声哭喊起来，目光呆滞，显然无法回答你的问题。\n");
	return 1;
}