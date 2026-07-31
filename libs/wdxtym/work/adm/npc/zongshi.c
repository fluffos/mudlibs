inherit NPC;

string ask_xiaoaoquan();

void create()
{
    set_name("扬州城主", ({"zong shi"}));
    set("long", "一个身材高大，帅气无比。貌似潘安。微微一笑，迷倒万千少女。的大帅比。\n");
    
    set("combat_exp", 10000000);
    set("gender", "男性");
    set("age", 35);
    set("inquiry", ([
        "新手技能" : (: ask_xiaoaoquan :),
        ]));
    
    setup();
}

void init()
{
    add_action("disable", ({"kill", "hit", "fuhuo", "touxi", "fight", "ansuan", "steal"}));
}

int disable(string arg)
{
    object who = this_player();
    
    if (arg != "zong shi")
        return 0;
    
    tell_object(who, "你试图挑战扬州城主\n只见缓缓向你击出一拳，竟让你感觉无处闪躲。\n");
    tell_object(who, "拳头停在你面前，额头留下冷汗……\n");
    return 1;
}

string ask_xiaoaoquan()
{
    object who = this_player();
    
    if (who->query_skill("spells", 1))
        return "你已习得新手技能，不用再这里请教了。";
    else
    {
        who->set_skill("xiaoao-quan", 600);
		who->set_skill("youzhi-jian", 600);
		who->set_skill("spells", 600);
        return "我传授你新手技能，此法精妙无比，还望你好好领悟。";
    }
}