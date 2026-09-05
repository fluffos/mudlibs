// 伙计 zine oct 16 2010

inherit NPC;

int ask_ding();
void create()
{
        set_name("伙计", ({ "huoji"}));
        set("gender", "男性");
        set("age", random(10) + 20);
        set("long", "他是一个小伙计，眼睛中透着精明。\n");
        set("combat_exp", 1000);
        set("shen_type", 1);
        set("attitude", "peaceful");
		set("uni_target",1);
        set("qi", 1000); 
		set("max_qi", 1000); 
        set("neili", 800); 
        set("max_neili", 800);
        set("jiali", 10);
		set("inquiry", ([
            "泥人" : (: ask_ding :),
            "定制" : (: ask_ding :),
			"ding" : (: ask_ding :),
            
       	]) );

        setup();
}



void unconcious()
{
        die();
}

void die()
{
        message_vision("小伙计摇了摇头，似乎很不理解你想干嘛。\n",environment(this_object()));
        this_object()->fullme();
        return;
}

int ask_ding()
{
	object me=this_player();
	object ob=this_object();
	if (me->query_temp("figureding"))
    {
        tell_object(me,"伙计道：你不是已经问过我了，去定制就是了。\n");
        return 1;
    }
    else
    {
        tell_object(me,"伙计道：本店专门捏制泥人，你如果需要可以去定制(ding)一个。\n");
        tell_object(me,"本店只收取成本价八金。\n");
        me->set_temp("figureding",1);
        return 1;
    }
}

