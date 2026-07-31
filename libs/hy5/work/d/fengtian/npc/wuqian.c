// wuqian.c

inherit NPC;

string ask_me(object who);

void create()
{
        set_name("吴谦", ({ "wu qian"}) );
        set("title", "老猎户");
        set("gender", "男性" );
        set("age", 59);

        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

	set("inquiry",([
	"刘浪" : (: ask_me :),
]));

        set("long","这是一位满脸沧桑的老者。\n");

        set("combat_exp", 100);
        set("attitude", "friendly");

        set("max_atman", 500);
        set("atman", 500);
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 20);
        set("max_mana", 500);
        set("mana", 500);

        setup();
        
        carry_object("/clone/misc/cloth")->wear();
}

string ask_me(object who)
{
	if(who->query("gender") != "女性"
	|| !who->query_temp("feiyu_upgrade_quest/ask_my"))
                return 0;

	who->set_temp("feiyu_upgrade_quest/ask_liehu",1);

	call_out("leave",5);

	return "那都是很早以前的事情了，其实我只是碰巧经过躲在边上
          看到了当时的情况。当时那个姓刘的带着几个大汉匆匆忙
          忙的向关内走，方员外可能是受人之托要截住这帮人，双
          方打了起来，结果方员外受了伤，让这伙人跑了。那件事
          以后没过多久方员外家听说是被这伙人报复，给放火烧掉
          了。。。想当年提起盛京府的方华林，又有钱又会武功，
          也是方圆几百里响当当的人物，真可惜呀。。。你去原来
          方家附近打听打听吧，也许能有二十年前那件事的线索。";
}

private void leave()
{
	if(environment())
		message_vision("$N匆匆忙忙的走了。\n",this_object());
	destruct(this_object());
}
