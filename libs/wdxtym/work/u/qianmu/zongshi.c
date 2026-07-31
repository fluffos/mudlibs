inherit NPC;

string ask_yeqiuquan();

void create()
{
    set_name("野球拳宗师", ({"zong shi"}));
    set("long", "一个身穿粗布衣的大汉。\n");
    
    set("combat_exp", 100000);
    set("gender", "男性");
    set("age", 35);
    set("inquiry", ([
        "野球拳" : (: ask_yeqiuquan :),
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
    
    tell_object(who, "你试图挑战野球拳宗师\n只见野球拳宗师缓缓向你击出一拳，竟让你感觉无处闪躲。\n");
    tell_object(who, "拳头停在你面前，额头留下冷汗……\n");
    return 1;
}

string ask_yeqiuquan()
{
    object who = this_player();
    
    if (who->query_skill("yeqiu-quan", 1))
        return "你已习得野球拳，不用再这里请教了。";
    else
    {
        who->set_skill("yeqiu-quan", 3);
        return "我传授你野球拳，此拳法精妙无比，还望你好好领悟。";
    }
}