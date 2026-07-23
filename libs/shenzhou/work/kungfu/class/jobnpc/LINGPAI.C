//Code by Scatter
//Lingpai
//V 1.0
#include <ansi.h>

inherit ITEM;

void init()
{
    set("no_get", "算了吧，破铜烂铁也要捡？\n");
    set("no_drop", "你舍得丢吗？\n");
    add_action("do_search", "search");
}

void create()
{
    set_name("巡补令牌", ({"lingpai"}));
    set_weight(600);
    if (clonep())
        set_default_object(__FILE__);
    else{
        set("unit", "只");
        set("long", "这是一个巡补令牌, 可以让你先斩后奏. 用来寻找非法行为(search here)\n");
        set("value", 0);
        set("material", "bamboo");
    }
    setup();
}

int do_search()
{
    object me=this_player();
    object ob;

    int intrnum;
    int rnum;
    int myexp;
    
    if (this_player()->is_busy())
    {
       tell_room(environment(me),"你还在忙呀！\n");
       return 1;
    }
    else
    {

    myexp = me->query("exp", 1);
    intrnum = random(100);

    if(intrnum < 20)
    {
               switch (random(8))

    {

    case 0:
        tell_room(environment(me),"有一个土匪正在欺负一只狗！\n");
        break;
    case 1:
        tell_room(environment(me),"有一个土匪正在欺负小孩！\n");
        break;
    case 2:
        tell_room(environment(me),"有一个土匪正在虐待妇女！\n");
        break;
    case 3:
        tell_room(environment(me),"有一个土匪正在殴打壮士！\n");
        break;
    case 4:
        tell_room(environment(me),"有一个土匪正在辱骂爱国英雄！\n");
        break;
    case 5:
        tell_room(environment(me),"有一个土匪正在收保护费！\n");
        break;
    case 6:
        tell_room(environment(me),"有一个土匪正在进行偷窃行为！\n");
        break;
    case 7:
        tell_room(environment(me),"有一个土匪正在人群中偷东西！\n");
        break;
    default:
        tell_room(environment(me),"有一群土匪正在打架！\n");
        break;
    }
     ob=new("/kungfu/class/jobnpc/tufei.c");
     ob->move(environment(this_player()));
     this_player()->start_busy(2+random(2));
     ob->set("combat_exp", this_player()->query("combat_exp")/4*3);
     ob->reincarnate();
    return 1;
    }


    else
    {
    tell_room(environment(me),"这里看起来很安定！\n");
    this_player()->start_busy(2+random(2));
    return 1;
    }
    return 1;
    }
    return 1;
}
