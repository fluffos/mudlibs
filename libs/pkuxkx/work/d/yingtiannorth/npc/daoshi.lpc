// By Zine
               
#include <ansi.h> 
inherit NPC; 
int ask_quest();
int ask_bonus();

void create()
{
	set_name("老道士", ({ "lao daoshi","daoshi"}));
        
	set("long",
	"他是这里的观主，执掌灵英观几十年了，也和清凉山的老和尚吵了几十年了。\n"
         );
	set("title",HIW"大贤大德"NOR);
	set("gender", "男性");
	
	set("age", 73);
	set("attitude", "peaceful");
	set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
	set("max_qi", 1000);
        set("qi", 1000);
        set("neili", 900);
	set("max_neili", 900);
	set("jiali", 50);
	set("combat_exp", 650000+random(100000000));
	
    set("inquiry", ([
			"老和尚" : (: ask_quest :),
            "清凉寺" : (: ask_quest :),
            "bonus" : (: ask_bonus :),
            "远道而来" : (: ask_bonus :),
       	]) );    
        setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();
	

}



int ask_quest()
{
    object ob=this_object();
    object me=this_player();
    command("say 清凉山老和尚道貌岸然，看到漂亮小姑娘都会两眼放光。\n");
    if (me->query("gender")=="女性" && me->query("per")>35)
    {
        me->set_temp("beauty",1);
    }
    return 1;
}


int ask_bonus()
{
    object ob=this_object();
    object me=this_player();
    if (me->query("jiangnanquest/finish2"))
    {
        command("say 干嘛？还上瘾了？\n");
        return 1;
    }
    if (!me->query("jiangnanquest/step8"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step7"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step6"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step5"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step4"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step3"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step2"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }
    if (!me->query("jiangnanquest/step1"))
    {
        command("say 江南很大，你还需要去历练一些。\n");
		return 1;
    }

    else
    {
        me->delete("honorbonus/titlegiven");
        me->set("jiangnanquest/finish2",1);
        command("say 远道而来建康府你也不容易，我没啥好做的只有请洛阳的老友点石成金帮你擦亮招牌。\n");
		return 1;
    }
}