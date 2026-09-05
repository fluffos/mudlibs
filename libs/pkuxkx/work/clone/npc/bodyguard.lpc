//玩家召唤保镖 zine 2014/8/13

#include <ansi.h>
#include "/clone/npc/bodyguard_config.h"
inherit FAMILY_NPC;
int ask_me();
int ask_topic(string);
void create()
{
	int gender=random(2);
	int type=random(2)+1;
	string cloth;
	string name,*tmp,*pinying;
	set("gender", gender?"女性":"男性");
	name=gender?NAME_D->create_female_name():NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("nickname",NAME_D->create_nick());
	set("type",type);
	if (type==1) set("title",HBRED+BLK+"影子杀手"+NOR);
	else set("title",YEL+"傀儡人"+NOR);
	set("age", 25);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 1000000);
	set("shen_type", 1);
    set("attitude", "friendly");
	set("max_jingli",1000);
	set("jingli",1000);
	set("neili",1000);
	set("max_neili",1000);
	set("max_qi",2000);
	set("qi",2000);
	set("max_jing",1500);
	set("jing",1500);
	set("jiali",50);
    set("no_get", 1);
	set("VIP_BODYGUARD",1);
	set_skill("literate",250);
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set("no_ask",1);
	set("CustomizedAskMode","闲聊");
	set("NoBusyAsking",1);
	set("inquiry", ([
                "闲聊" : (: ask_me :),
                "籍贯" : (: ask_topic,"籍贯" :),
                "绰号" : (: ask_topic,"绰号" :),
				"年龄" : (: ask_topic,"年龄" :),
				"师承" : (: ask_topic,"师承" :),
				"喜好" : (: ask_topic,"喜好" :),
				]));
	setup();
	cloth="/clone/cloth/";
	cloth+=gender?"female":"male";
	cloth+=(1+random(8))+"-cloth";
	carry_object(cloth)->wear();
}
void init()
{
	add_action("do_dismiss","dismiss");
}

void initialize_guard()
{
	BG_INIT->initialize_guard(this_object());
}
void restore_guard(object me)
{
	BG_SAVE->restore_guard(me,this_object());
}
void save_guard(object me)
{
	BG_SAVE->save_guard(me,this_object());
}
int accept_object(object me,object ob)
{
	BG_OBJECT->accept(me,ob,this_object());
	return 1;
}
int ask_topic(string topic)
{
	BG_HIRE->ask_topic(topic,this_player(),this_object());
	return 1;
}
int do_dismiss()
{
	BG_HIRE->do_dismiss(this_player(),this_object());
	return 1;
}
int ask_me()
{
	BG_HIRE->ask_me(this_player(),this_object());
	return 1;
}