//Cracked by Roath
// xiaotong.c 小童
// Long, 6/13/97
#include <ansi.h>
inherit NPC;
void greeting(object);
void create()
{
	set_name("小僮", ({ "xiao tong", "tong"}));
	set("long", "他是个年龄不大的小男孩，但已很健壮了。\n");
	set("gender", "男性");
	set("age", 14);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("race", "人类");	
	set("max_qi", 150);
	set("eff_qi", 150);
	set("qi", 150);
	set("max_jing", 150);
	set("eff_jing", 150);
	set("jing", 150);
	set("max_neili", 150);
	set("eff_neili", 150);
	set("neili", 150);
	set("max_jingli", 150);
	set("eff_jingli", 150);
	set("jingli", 150);
	set("combat_exp", 1000);
	set("score", 1000);

	set_skill("force", 5);
	set_skill("dodge", 5);
	set_skill("parry", 5);
	set_skill("cuff", 5);
	set_skill("sword", 5);
	
	setup();
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

void greeting(object me)
{	command("bow " + me->query("id"));
	command("say 你如果要些吃的或喝的只要叫我一声"+HBRED+HIW"(serve)"NOR+"。");
	command("say 
         人的精神和气血是很重要的，只要你注意补充食物和
    饮水，就能够自动补充精气。 尤其是在大沙漠等地方更需
    要喝足够的水才行。
    用("+HBRED+HIW"eat"NOR+")来吃东西，用("+HBRED+HIW"drink"NOR +")来喝， 有很多可以装水的
    容器，喝光了可以再装，如扬州，从城中心，往南走两步，
    再往西，就能装水("+HBRED+HIW"fill 容器"NOR +")");
}

