// girl.c 赌场服务员

inherit NPC;
void func1();
void func2();
string* testfunc;

void create()
{
          set_name("彩票小姐", ({ "girl" }) );
         set("gender", "女性" );
        set("age", 19);
        set("long",
                 "她打扮得花枝招展，不时向你抛个媚眼，试图吸引你多买点彩票，
你不禁意欲将计就计了......\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        setup();
        set("chat_chance", 3); 
        set("chat_msg", ({
"小姐说道：「来吧！买点彩票！支持mud福利事业！」\n",
"小姐作神秘状说道：「昨天刚刚有个人中了头奖呢！」\n",
        }));
}

void test()
{       
	int i;
	testfunc = ({"func1","func2"});
	i = random(sizeof(testfunc));
	call_out(testfunc[i],1);
	testfunc -= ({testfunc[i]});
	call_out(testfunc[0],1);
}

void func1()
{
	command("say func1");
	return;
}
void func2()
{
	command("say func2");
	return;
}

