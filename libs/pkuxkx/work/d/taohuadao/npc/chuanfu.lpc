#include <ansi.h>
// d/taohuadao/npc/chuanfu.c
// By llx 26/10/97
inherit NPC;
int ask_dao();
int ask_chuan();
void init();
void delete_served();
void create()
{
	set_name("船夫", ({"chuan fu","fu"}) );
       	set("gender", "男性" );
        set("age", 40);
	set("long",
	  "他是一位四十多岁的船夫，常年从事于人客及货物运送。\n"
	  "但是他很少到远海的一个小岛去，听说那里有一个杀人魔鬼。\n");
	set("attitude", "peaceful");
    set("shen_type", 0);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 200);
        set("max_jing", 150);
        set("neili", 200);
        set("max_neili", 200);
		set("combat_exp", 3000);
        set("score", 1000);
        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 25);
        set_skill("parry", 20);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 10);
        set("inquiry",([
	"桃花岛" : (: ask_dao :),
	"渡船" : ( : ask_chuan :),
	]));
        set("shen_type",1);set("score",200);setup();
        
		carry_object("/d/city/obj/cloth")->wear();
}
int ask_dao()
{
	say("你说桃花岛呀，那里可有一个杀人魔鬼。\n");
	this_player()->set_temp("marks/岛",1);
	return 1;
}

int ask_chuan()
{
	if((int)this_player()->query_temp("marks/岛"))
	{
	say("你要真想过海，我就送你一程吧。\n");
	this_player()->set_temp("marks/船",1);
	this_player()->set_temp("marks/岛",0);
	return 1;
	}
	else
	{
	say("你没事过海干什么？\n");
	return 1;
	}
}

