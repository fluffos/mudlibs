inherit NPC;
#define FARM "/d/bangpai/farm/farm"

string ask_kaitong();
string ask_kuojian();
string ask_buy_animal();

void create()
{
    set_name("老农", ({"lao nong"}));
    set("long", "老农。\n");
    
    set("combat_exp", 100000);
    set("gender", "男性");
    
    set("inquiry", ([
        "开通" : (: ask_kaitong :),
        "扩建" : (: ask_kuojian :),
        "购买动物" : (: ask_buy_animal :),
    ]));
    
    setup();
}

void init()
{
    add_action("do_kaitong", "kaitong");
    add_action("do_kuojian", "kuojian");
    add_action("do_buy_animal", "buy_animal");
}

string ask_kaitong()
{
    this_player()->force_me("kaitong");
    
    return "";
}

int do_kaitong(string arg)
{
    object who = this_player();
    
    FARM->kaitong(who, arg);
    
    return 1;
}

string ask_kuojian()
{
    this_player()->force_me("kuojian");
    
    return "";
}

int do_kuojian(string arg)
{
    object who = this_player();
    
    FARM->kuojian(who, arg);
    
    return 1;
}

string ask_buy_animal()
{
    this_player()->force_me("buy_animal");
    
    return "";
}

int do_buy_animal(string arg)
{
    object who = this_player();
    
    FARM->buy_animal(who, arg);
    
    return 1;
}