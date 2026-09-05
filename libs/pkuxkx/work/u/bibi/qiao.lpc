//樵
//by bing
#include <ansi.h>


inherit NPC;

int ask_fish();
int ask_goldfish();


void create()
{
        set_name("樵隐", ({ "qiaoyin" }));
        set("long", "这人左手提着一捆松柴，右手握着一柄斧头，容色豪壮，神态虎虎，举手迈足似是大将军有八面威风。\n");
        set("gender", "男性");
        set("rank_info/respect", "大叔");
        set("age", 46);
        set("attitude","heroism");
        set("str", 20);
        set("dex", 35);
        set("con", 20);
        set("int", 30);
        set("shen_type", 5000);

        set_skill("finger", 100);
	set_skill("yiyangzhi",100);
        set_skill("force", 100);
        set_skill("dodge", 100);
	set_skill("parry",100);
	set_skill("xiantian-gong",80);
        map_skill("force", "xiantian-gong");
	map_skill("parry","yiyangzhi");
	map_skill("finger","yiyangzhi");
        set("jiali",50);

        set("combat_exp", 150000);

        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        setup();
        carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("seeing");
                call_out("seeing", 1, ob);
        }

}
void seeing(object ob)
{
	if (ob->query_temp("marks/樵1")==1) 
	{
		return;
	}

	tell_room(environment(ob),"只听那樵夫唱到：\n"
		"峰峦如聚，波涛如怒，山河表里潼关路。望西都，意踯躅。\n"
		"伤心秦汉经行处，宫阙万间都做了土。兴，百姓苦！亡，百姓苦！\n");


	if ((ob->query_skill("literate",1))<60)
	{
        tell_room(environment(ob),"可是你一点也不明白他词里的意思。\n");
		return;
	}
      tell_room(environment(ob),"你不禁喝了声彩：好曲儿！\n");
       tell_room(environment(ob),"那樵夫转过身来，把斧头往腰间一插，问到：好？好在哪里？\n");
       tell_room(environment(ob),"你微微一笑，低头唱到：\n");
      tell_room(environment(ob),"青山相待，白云相爱。梦不到紫罗袍共黄金带。一茅斋，野花开，管甚么兴废谁成败？\n");
      tell_room(environment(ob),"陋巷单瓢亦乐哉。贫，气不改！达，志不改！\n");
      tell_room(environment(ob),"那樵夫听得心中大悦，也不多问，向山边一指，道：上去罢！\n");
	ob->set_temp("marks/樵1",1);
	return; 
	
}
		



