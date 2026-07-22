// zhong3.c 钟小二 

#include <ansi.h>

inherit NPC;

string ask_me();

void create()
{
	set_name("钟小二", ({ "zhong xiaoer","zhong", "xiaoer" }));
	set("long",
		"他赤着双足，衣裤已被恶狗的爪牙撕得稀烂，身后一路滴着鲜血。\n");
	set("gender", "男性");
	set("age", 13);
	set("attitude", "friendly");

	set("str", 15);
        set("int", 15);
        set("con", 25);
        set("dex", 20);

	set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);

        set("jingli",100);
        set("max_jingli",100);
        set("jiali", 1);   
	set("combat_exp", 500);

	set("inquiry", ([
		"钟小三"   : (: ask_me :),
	]) );
	set("shen_type", 0);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

string ask_me()
{
	if( (random(10) < 5) || is_fighting() )
		return "我…不知道。\n";
	else 
	{
		if( this_player()->query_temp("marks/feng"))
		{
			this_player()->delete_temp("marks/feng");
			this_player()->set_temp("marks/zhong",1);
			return "哥哥死的好冤枉呀!";	
		}	
	else return "妈妈不让我乱说话。";
	}
}
