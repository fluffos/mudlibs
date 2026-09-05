//太医院判

#include <ansi.h>
inherit NPC;
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"


int ask_b1();
int ask_b2();
int ask_b3();
int ask_b4();
int ask_b5();
int ask_b6();
int ask_b7();
int ask_b8();
int ask_b9();
int ask_b10();

void create()
{
    set_name("太医院判", ({"taiyi yuanpan", "yuanpan"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的太医院判。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    
	set("inquiry", ([
	
     "鸡血藤": (: ask_b1 :),
     "薄荷": (: ask_b2 :),
     "鱼腥草": (: ask_b3 :),
     "常山": (: ask_b4 :),
     "当归": (: ask_b5 :),
     "丁香": (: ask_b6 :),
     "茯苓": (: ask_b7 :),
     "覆盆子": (: ask_b8 :),
     "合欢": (: ask_b9 :),
     "荆芥": (: ask_b10 :),
	]));

    setup();
   
}

int ask_b10()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"太医院判忙着整理药材，没空理你。\n");
        return 1;
    }
    else
    {
        command("say 荆芥本是常用药，但近年战火纷飞，居然只有在北疆小镇才能买到。");
        return 1;
    }
}

int ask_b9()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"太医院判忙着整理药材，没空理你。\n");
        return 1;
    }
    else
    {
        command("say 合欢长在张家口通往塞外的路上。");
        return 1;
    }
}

int ask_b8()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"太医院判忙着整理药材，没空理你。\n");
        return 1;
    }
    else
    {
        command("say 覆盆子极难找到，据说只有关外长白山才有。");
        return 1;
    }
}

int ask_b7()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"太医院判忙着整理药材，没空理你。\n");
        return 1;
    }
    else
    {
        command("say 按我的记忆，茯苓生长在昆明，江州附近马尾松下。");
        return 1;
    }
}

int ask_b6()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"太医院判忙着整理药材，没空理你。\n");
        return 1;
    }
    else
    {
        command("say 按我的记忆，丁香在苏州，镇江的园子一般都可以找到。");
        return 1;
    }
}

int ask_b5()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"太医院判忙着整理药材，没空理你。\n");
        return 1;
    }
    else
    {
        command("say 当归在苏州，扬州，晋阳的药铺一般都可以买到。");
        return 1;
    }
}

int ask_b4()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"太医院判忙着整理药材，没空理你。\n");
        return 1;
    }
    else
    {
        command("say 常山一般长在福建、四川一带的山间坡旁。");
        return 1;
    }
}

int ask_b1()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"太医院判忙着整理药材，没空理你。\n");
        return 1;
    }
    else
    {
        command("say 鸡血藤一般长在云南、四川一带的山间坡旁。");
        return 1;
    }
}

int ask_b2()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"太医院判忙着整理药材，没空理你。\n");
        return 1;
    }
    else
    {
        command("say 薄荷在很多地方都能找到，一般有山的地方就有薄荷。");
        return 1;
    }
}

int ask_b3()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"太医院判忙着整理药材，没空理你。\n");
        return 1;
    }
    else
    {
        command("say 鱼腥草生长在江南，有水的地方一般能找到。");
        return 1;
    }
}