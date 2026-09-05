// waiter.c

inherit NPC;
#include <ansi.h>;

int ask_jiu();
void create()
{
        set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("inquiry", ([
                "玄冰碧火酒" : "前几天倒是有这么一回事，后来就不知道了。\n",
        ]));
        set("shen_type",1);set("score",200);setup();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if( !this_object()->visible(ob)) return;
/*
        if (!ob->query_temp("welcome100") || ob->query("mud_age")<1000)
        {
                ob->set_temp("welcome100","1");
tell_object(ob,"店小二笑咪咪地说道：这位"+RANK_D->query_respect(ob)+"，欢迎来到"HIR"北大侠客行。"NOR"

    如果你有什么不明白的，可以问老玩家。缺钱花，也可以请老玩家
帮你暂渡难关。大侠们都会乐于助人的。当然你也可以用"RED"help"NOR"来获得我
们给您的帮助。
    你在help中能看到很多帮助项目。
    这里的故事和情节，谜语的基本依据是金庸的十五本小说。如果你
对故事不太记得了或想了解多些可以用"RED"help intro"NOR"这个帮助项。如果你
从没玩过 MUD游戏，那就先看看"RED"help newbie"NOR"来新手上路吧。"RED"help cmds"NOR"
是这里所有玩家都能用的命令。想认识一下这里的地图就"RED"help maps"NOR"，里
面有很多项目的，你可以选择地图项目"RED"help pkuxkx.map"NOR"看到整个游戏的
地图。而"RED"help yangzhou.map "NOR"就是扬州城的地图。如果你还没有拜师，可
以打"RED"help menpai"NOR"，选择一个你喜欢的门派，然后用你身上的新手精灵"RED"travel\n"NOR
"到那个门派拜师学艺。吃喝的问题可以到中央广场（从这里w,s）上面的赏月台，
sit chair,knock table,drink wan,eat shangyueshipin。都是免费的。至于升
级方式的说明可以看help tasks，选择合适你的途径，当然也可以通过战斗方式
升级。然后当然最重要的是向老玩家请教，这就一定要会使用"RED"chat"NOR"
这个命令啦。这里的帮助文件也因为我们的工作而更新，多多留意哦。叛师在
这里会吃亏的，没想好拜哪个门派就先看help。扬州的中央广场是信息中心，
常去看看那里的公告，最新的消息一定最早出现在那里。另外，"HIG
"bbs.pku.edu.cn"NOR"的mud版以及"HIG"web.pkuxkx.net"NOR"的论坛也是这里
的基地，特别是北大未名BBS Mud版的精华区里，有不少有用的文章可以参考。
在主页上还有"HIR"常用路径以及集成了常用路径的zmud"NOR"可供下载。有了
这些常用路径，从中央广场去少林时只要打shaolin，回来只要打shaolinb，
去北京只要打beijing，从北京回中央广场打beijingb即可。是不是很方便呢？
赶快去下载吧，它会给你提供很多便利的！

    如果您对这个游戏的设计和管理有什么建议或意见请"RED"到中央广场或
者巫师会客室留言"NOR"，我们一定会认真考虑的。\n\n");
        }
*/
        switch( random(2) ) {
                case 0:
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}

int accept_object(object who, object ob)
{

        if (ob->query("money_id") && ob->value() >= 200)
        {
                tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");

                who->set_temp("rent_paid",1);

                return 1;
        }

        return 0;
}

int ask_jiu() //iszt@pkuxkx, 2006-10-01
{
        object me = this_player();
        object ob = new("/clone/gift/giftjiu");
        object where = TASK_D->random_place();
        string area = TASK_D->place_belong(where);
        object* inv = all_inventory(where);

        if(me->query("marks/ask2006guoqing"))
                return notify_fail("小二说道：你不是问过了么？还问？烦不烦啊？");
        if(me->query("combat_exp") < 100000)
                return notify_fail("小二说道：就你这点经验，还想喝这个，别把小命丢了！");

        me->set("marks/ask2006guoqing", 1);

        me = this_player();
        ob = new("/clone/gift/giftjiu");
        where = TASK_D->random_place();
        area = TASK_D->place_belong(where);
        inv = all_inventory(where);

        message_vision("$N走近$n，问道：客官有什么吩咐？\n", this_object(), me);
        tell_object(me, HIG"店小二趁人不注意，悄悄告诉你：听说玄冰碧火酒在"+area+where->query("short")+HIG"出现，不知是真是假。\n"NOR);

        ob->move(where);
        if(sizeof(inv) > 0)
                if (!ob->move(inv[random(sizeof(inv))]))
                        ob->move(where);
        return 1;
}
