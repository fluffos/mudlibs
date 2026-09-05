//生日礼物
inherit ITEM;

#include <localtime.h>
#include <ansi.h>

string* resultstr = ({"膂力","悟性","根骨","身法","容貌","福缘","灵性"});
void create()
{
        set_name(HIW"生日蛋糕"NOR,({"dan gao","cake"}));
        set("long","这是一个生日蛋糕。上面用巧克力写着:生日快乐！\n红红的樱桃点缀在白白的奶油上，让你很有想要吃一口的欲望。\n"
        );
        set("value",1);
        set_weight(10);
        set("no_store",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_steal",1);        
		set("unit","个");
        setup();
}

void init()
{
	if(environment(this_object())==this_player())
        add_action("do_eat","eat");
    set("long",sprintf(query("long"),this_player()->name()));
}

int do_eat(string arg)
{
    object me=this_player();
    object ob=this_object();
 
    int result = -1;

    mixed date_local, year;
    int time;
    time=time();
    date_local=localtime(time);
    year=date_local[LT_YEAR];
    
    if(ob->query_temp("tt_forward/to") != this_player()->query("id"))
    {
        write("真不害臊，这是给你的蛋糕么？\n");
        return 1;
    }
    if(!me->is_realuser() && !wizardp(me))
    {
        write("只有实名制玩家才能享用生日蛋糕！\n");
        return 1;
    }    
        if(me->query("birthdaycake/last_eat") == year)
    {
        write("你今年的生日蛋糕已经吃过了！\n");
        return 1;
    }    
    if(random(30) == 0)
    {
        //加主属性
        switch(random(4))
        {
            case 0://臂力
            write("你吃下一口蛋糕，感到全身都充满了力量！\n");
            me->add("str",1);
            result = 0;
            break;
            case 1://悟性
            write("你吃下一口蛋糕，感到自己对世界的领悟又深刻了一层！\n");
            me->add("kar",1);
            result = 1;
            break;        
            case 2://根骨
            write("你吃下一口蛋糕，只觉得四肢百骸都被洗礼过一样。\n");
            me->add("con",1);
            result = 2;
            break;       
            case 3://身法
            write("你吃下一口蛋糕，感觉身手敏捷了许多。\n");
            me->add("dex",1);
            result = 3;
            break;       
        }
        
    }
    else
    {
        switch(random(3))
        {
            case 0://容貌
            write("你吃下一口蛋糕，感觉到自己又变漂亮了一些！\n");
            me->add("per",1);
            result = 4;
            break;
            case 1://福缘
            write("你吃下一口蛋糕，心里美滋滋的，今年一定好运不断！\n");
            me->add("kar",1);
            result = 5;
            break;        
            case 2://灵性
            write("你吃下一口蛋糕，只觉得心中一片空明，脑瓜子似乎也变得更加灵活了。\n");
            me->add("spi",1);
            result = 6;
            break;                               
        }
    }
    
    shout("祝"+sprintf( BOLD "%s" NOR "%-s", RANK_D->query_rank(me), me->short(1) )+"生日快乐！\n");
    shout("         [5;1;33m﹒﹒﹒﹒﹒[0;37m[m
          [35m▎▎▎▎▎[m
[35m       [33m▅▅▅▅▅▅▅[m
[33m  [5m﹒  [0;1;33m▆▆▆▆▆▆▆▆  [5m﹒[m
[5;1;33m  [0;1;35m┃[33m▆▆▆▆▆▆▆▆▆▆[35m┃[m
[1;35m  [33m▆▆ [32mHappy Birthday [33m▆▆[m
[1;33m  ████████████[m
");
    shout(HIW""+me->name()+"吃下生日蛋糕，获得"+resultstr[result]+"奖励一点！\n"NOR);
    if(me->query("combat_exp") <= 5000000)
    {
        me->add("combat_exp",10000+random(20000));
        me->add("potential",10000+random(20000));
        me->add("balance",1000000+random(2000000));
        write(HIY"北侠巫师组恭贺您生日快乐。祝您福如东海，寿比南山，美貌常驻，笑口常开。\n您的经验，潜能，存款增加了！\n"NOR);
    }
    me->set("birthdaycake/last_eat",year);
    log_file("user/birthday",sprintf("%s于%s吃下生日蛋糕，获得%s奖励1点。\n",
	me->query("id"),ctime(time()),resultstr[result]));
    destruct(this_object());
    return 1;
}
