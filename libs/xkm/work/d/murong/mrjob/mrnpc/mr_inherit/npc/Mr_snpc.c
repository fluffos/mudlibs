/************************
File:   Mr_snpc.c
Create: Play 征召专用
Time:   4/25/2002
************************/
inherit NPC;

void create()
{
        seteuid(getuid());
	set_name("征召隐士",({ "zhengzhao yinshi", "yinshi" }) );
        set("gender", "男性" );
        set("age", 50);
        set("long", "一位隐士，过着与世无争的悠闲生活。\n");
        set("per", 28);
        set("str", 34);
        set("dex", 25);
        set("con", 26);
        set("int", 25);
        set("chat_chance", 10+random(10));
	set("chat_msg", ({
                "","",
		(: random_move :),
	}) );
        set("attitude", "friendly");

        setup();
        carry_object("/clone/armor/cloth")->wear();
}

void init()
{
	::init();
        add_action("do_killing", "kill");
        remove_call_out("del_ob");
	call_out("del_ob",300,this_object());
}
int do_killing(string arg)
{
	object *inv,victim;
	int i;
        if ( !arg || arg == "")	return 0;
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
          {
        	if(victim == this_object())
          	{
          		command("say "+this_player()->name()+"君子动口不动手喔！");
          		return 1;
          	}
          }
        return 0;               
}
int del_ob(object ob)
{
	object me;
	me=ob->query("Mr_canvass");
        remove_call_out("del_ob");
	if(!me)  destruct(ob);
	if(environment(me)!=environment(ob))
        set("chat_chance", 10+random(10));
        if(me->query_temp("Mrjob_time")<time())
        destruct(ob);
        else
        call_out("del_ob",30,ob);
	return 1;
}