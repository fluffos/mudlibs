inherit NPC;

string ask_test();

void create()
{
    set_name("小千", ({"qian"}));
    set("long", "小千可是无敌的哦！不要妄想对小千下手。\n");
    set("gender", "女性");
    set("age",25);
    set("combat_exp", 1);
    set("max_qi", 1000000000);
    set("qi", 100000000);
    set("max_jing", 1000000000);
    set("jing", 1000000000);
    
    set("inquiry", ([
            " 【消除标记】" : (: ask_test :),
        ]));
    
    setup();
}

string ask_test()
{
	__DIR__"fb_main"->main(this_player());
	return "完成测试\n";
}
/*
void init()
{
	command("say 哈哈哈哈哈哈哈哈哈哈哈哈好 \n");
}*/