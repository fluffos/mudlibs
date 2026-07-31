 //TIE@FY3
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight();  
void create()
{
    set_name("李玉函", ({ "master li", "master","li" }) );
    set("gender", "男性" );
    set("nickname", HIG"拥翠山庄少主"NOR);
    set("age", 25);
    set("int", 30);
    set("per", 30);
    set("cor", 50);
    set("reward_npc", 1);
    set("difficulty", 30);
    set("ill_boss",5);
    set("apprentice_available", 50);
    create_family("黄山派", 3, "掌门");
    set("rank_nogen",1);
    set("ranks",({"弟子","小侠","少侠","大侠","奇侠","长老","元老","副掌门"}));
    
    set("long",
        "李玉函乃天下第一剑客李观鱼之子，出身拥翠山庄，因少年有为而被任为黄山派掌门\n"
        );
     set("pubmaster",1);
    set("force_factor", 120);
    set("max_neili", 2000);
    set("neili", 2000);
    set("resistance/sen",80); 
    set("combat_exp", 6000000);
    set("score", 90000);
            set("max_neili", 95000);
        set("neili", 95000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
  
        set("combat_exp", 59999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("yunwu-strike", 500);
	set_skill("qiusheng-blade", 530);
	set_skill("xianjing", 550);
	set_skill("liuquan-steps", 500);

	map_skill("unarmed", "yunwu-strike");
        map_skill("blade", "qiusheng-blade");
        map_skill("force", "xianjing");
        map_skill("dodge", "liuquan-steps");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.liushuichanchan" :),
                (: perform_action, "unarmed.miwu" :),
                (: perform_action, "blade.jingsheng" :),
        }) );  
            

    
    setup();
    //carry_object(__DIR__"obj/cq");
    carry_object(__DIR__"obj/greencloth")->wear();
    carry_object(__DIR__"obj/yuhuan")->wield();
    if (!random(6000000)) carry_object(__DIR__"obj/cq2");
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 2);
}

int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "huangshan");
    add("apprentice_availavble", -1);
} 
int accept_fight(object me)
{
        return 0;
} 
void init()
{
        add_action("do_get","get");
} 
int do_get(string arg)
{
    string what,where;
    object the_wall;
    if(!arg) return 0;
    if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
    the_wall = present(where,environment(this_object())) ;
    if (the_wall)
    if(the_wall->query("name") == "西墙")       
    {
        message_vision("$N对$n大吼一声：大胆！竟敢打先父遗物的主意！\n",
                       this_object(),this_player());
        this_object()->kill_ob(this_player());
        this_player()->start_busy(2);
        return 1;
    }
    return 0;
}  
smart_fight()
{
        int i,j,count;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (who->query("qi")<6000) {
                count=0;
                for (j=0;j<sizeof(enemy);j++) {
                        if (enemy[j]->is_zombie()) count++;
                }
                if (count>=3)
                        command("perform zombie-wp1");
        }
        if (!random(3)&& who->query("qi")>8000) who->perform_action("blade.jingsheng");
        return;
}  
int accept_object(object who, object ob)
{
		int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( ob->query("money_id") )
{
	if(who->query_skill("unarmed",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("unarmed",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("unarmed",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 100;
		}
	}
	who->add_temp("learn_timeb",i);
command("say 既然你诚心想学我的武功，我就成全成全你吧。");
	return 1;
}	
	
        if(!who->query("marks/黄山送信") || who->query("class")!="legend") return 0; 
        if( ob->query("name")!="铁雪信笺" ) return 0;
                message_vision(CYN"$N微微笑道：多日不见，你师傅还好么？\n"NOR,this_object());
                message_vision(CYN"$N说:一路上辛苦了，在寒舍歇息几天吧，我新招个徒弟，有空你们可以切磋一下。\n"NOR,this_object());
                tell_object(who,HIW"你心中暗喜：好机会！可以乘机学几手了！！\n"NOR);
                who->set("marks/黄山学艺",1);
                who->delete("marks/黄山送信",1);
        return 1;
} 


int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}