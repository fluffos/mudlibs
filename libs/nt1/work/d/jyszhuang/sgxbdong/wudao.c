#include <ansi.h>;
inherit ROOM;
string look_gaoshi();
string look_shibi();
void create()
{
        set("short", HIW"绝顶上"NOR);
        set("long", @LONG
这里已就是华山之巅了，朝山脚下望去，山坡上阵阵松涛哗哗作响，
另人豪情大增，北面有一面石壁(bi)，光秃秃地分外显眼，再往下就是
华山绝顶的擂台，来参加比武的武林人物，早已在此搭起了一溜溜的凉
棚，棚中桌椅杯盆俱全，看来比武大会快开始了。
LONG );

        set("outdoors", "city");
        set("item_desc", ([
                "bi" : (: look_shibi :),   
        ]));

        set("objects", ([
        ])); 
        set("exits", ([
           "down"  : "/d/huashan/houzhiwangyu",
        ]));
        set("no_fly",1);
        set("no_clean_up", 0);
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_beg", "1");
        setup();
}

void init()
{
        add_action("do_quit","quit");
        add_action("do_quit","exit");
        add_action("do_break", "break");
        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
        add_action("do_quit","exert");
        add_action("do_quit","songxin");
        add_action("do_quit","yun");
        add_action("do_quit","learn");
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna");
        add_action("do_quit","perform");
        add_action("do_quit","persuade");
        add_action("do_quit","quanjia");
        add_action("do_quit","practice");
        add_action("do_quit","lian");
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_qu
it","jiao");
}

int do_quit(string arg)
{
        write(this_player()->query("name")+"，折腾个啥劲儿呀，专心看比武吧！\n");
        return 1;
}
string look_shibi()
{
       return
HIW"\n你仔细的查看了石墙壁一会儿，发现这里的石墙壁似乎有空洞的回音，\n"
+"你不禁想用掌力试着震震(break)看。\n"NOR;
}

int do_break(string arg)
{
        object me=this_player();

        if (query("exits/enter"))
        return notify_fail("墙上的石壁已经打开了。\n");

        if (!arg || (arg != "bi" && arg != "shi bi"))
        return notify_fail("你要用掌力震开什么？\n");

        if(me->query("neili")<me->query("max_neili")
           || me->query("neili")<2000)
        return notify_fail("你现在内力不够充盈，无法震开石壁！\n");
        message_vision(HIY"$N双掌运足功力，大喝一声，猛的朝石壁击去！\n"NOR,me);
        if(!me->query("zhuanshi/jineng"))
        message_vision(
        HIW"只听轰的一声闷响，只惊得山谷隆隆，鸟鹊乱飞！\n"NOR,me);
        else
        {
        message_vision(
        HIW"只听喀的一声巨响，石壁缓缓地打开了，露出一个洞穴！\n"NOR,me);
        set("exits/enter", __DIR__"dongkou.c");
        call_out("hole_close",5);
        }
        me->start_busy(5);
        me->set("neili",0);
        return 1;
}

int hole_close()
{
        message_vision(
        HIW"只听石壁隆隆巨响，洞穴又缓缓合闭了！\n"NOR,this_object());
        delete("exits/enter");
        return 1;
}

