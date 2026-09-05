//clone/npc/badguy.c
// By Zine
#include <ansi.h>
inherit NPC;
void player_name(object user)
{
	string *names=({"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen"}),post_name="娘",pronoun="她";
	int i=random(13);
	if (user->query("gender")=="男性") 
	{
		post_name="郎";
		pronoun="他";
	}
	set_name(COLOR_D->uncolor(user->query("name"))[0..1]+chinese_number(i+1)+post_name,({user->query("id")+" "+names[i],"punk"}));
	set("gender",user->query("gender"));
	set("per",user->query("per"));
	if (!user->query("family"))
	set("long",pronoun+"是一个横行乡里的恶霸，听说和江湖上一个叫"+user->query("name")+"的人颇有瓜葛。\n");
	else
	{
		set("long",pronoun+"是一个横行乡里的恶霸，是武林中"+user->query("family/family_name")+"小有名气高手"+user->query("name")+"的亲戚。\n");
		set("family",user->query("family/family_name"));
	}
}

void create()
{
	set_name("匿名",({"anonymous"}));
	set("gender", "男性");
	set("title",HIM"乡间一霸"NOR);
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
	set("max_qi", 2000);
	set("qi", 2000);
	set("neili", 2900);
	set("max_neili", 2900);
	set("jiali", 50);
	set("combat_exp", 500000);
	set_skill("force", 60);
	set_skill("strike", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("literate", 100);
        set_skill("taiyi-shengong",60);
        set_skill("taiyi-zhang",60);
        set_skill("taiyi-jian",60);
        set_skill("taiyi-you",60);
        map_skill("force", "taiyi-shengong");
        map_skill("strike", "taiyi-zhang");
        map_skill("sword", "taiyi-jian");
        map_skill("dodge", "taiyi-you");
        map_skill("parry", "taiyi-jian");
        prepare_skill("strike", "taiyi-zhang");
	set("random_npc",1);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	object me=this_player();
	if (me==query("relative")&&!query("greeted"))
	{
		command("say "+me->query("name")+"哥哥，你怎么来啦，今天一定要跟着你混了？");
		command("buguai "+me->query("id"));
		command("follow "+me->query("id"));
		set("greeted",1);
	}
}
void die()
{
	object ob=this_object(),me=ob->query("relative");
	int mag=random(40)+40;
	if(!objectp(get_damage_origin_object()) || get_damage_origin_object() != me)
	{
		::die();
		return;
	}
	if (me->query_temp("relationship/daily_task")==ob)
	{
		message_vision(HIW"$N"+HIW+"对着$n"+HIW+"冷冷地道：“你我虽是亲戚，但杀你确是基于公义。下次投胎，好好做人。”\n"+NOR,me,ob);
		me->delete_temp("relationship/daily_task");
		if (!me->query_temp("relationship/daily_bless"))
		{
			me->set_temp("relationship/daily_bless",1);
			me->add_temp("apply/magic", mag);
			tell_object(me,"为民除害之后，你增加了"+chinese_number(mag)+"点掉宝率。\n");
		}
	}
	::die();
}
