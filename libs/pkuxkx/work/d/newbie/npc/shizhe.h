//shizhe.h 新手学堂教学使者
//by zoom
//2004.4.3

#include <ansi.h>
inherit NPC;

string* guider_id = ({"mudadm","hongdou","xigua"});
string* guider_name = ({"管理","红豆","西瓜"});

int ask_help();
void greeting(object);
void create()
{
        int n=random(sizeof(guider_name));
        set_name(guider_name[n], ({ guider_id[n] }));
	set("long", "他是北大侠客行历任管理员之一，现在已经另某高就。\n");
	set("title","[教学使]");
	set("gender", "男性");
	set("age", 24);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("int", 30);
	set("con", 30);
	set("dex", 20);
	set("race", "人类");	
	set("max_qi", 800);
	set("eff_qi", 800);
	set("qi", 800);
	set("max_jing", 800);
	set("eff_jing", 800);
	set("jing", 800);
	set("max_neili", 800);
	set("eff_neili", 800);
	set("neili", 800);
	set("max_jingli", 800);
	set("eff_jingli", 800);
	set("jingli", 800);
	set("combat_exp", 10000);
	set("score", 1000);
        set("inquiry", ([
	        "here"   :  "这里是新手学堂，是指导新手熟悉环境和有关指令的地方。\n",
	        "help"   :  (: ask_help :),
        ]));
	setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

int ask_help()
{
	call_out("greeting", 1, this_player());
	return 1;
}


void unconcious()
{
        die();
}

void die()
{
        this_object()->set("eff_qi",this_object()->query("max_qi"));
        this_object()->set("qi",this_object()->query("max_qi"));
        this_object()->set("eff_jing",this_object()->query("max_jing"));
        this_object()->set("jing",this_object()->query("max_jing"));
        return;
}
