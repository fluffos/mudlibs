// Taohua Newbie job Zine

#include <ansi.h>

int generate()
{
    object flower;
    int i;
    tell_room(this_object(),"一阵风刮过，鲜花落了遍地。\n");
    
    for (i=0;i<4+random(7);i++)
    {
        flower=new(__DIR__"obj/flower");
        flower->move(this_object());
    }
	remove_call_out("generate");
    call_out("generate",1440);
    return 1;
}

void init()
{
    add_action("do_caiji","caiji");
}

int do_caiji(string arg)
{
    object me=this_player();
    object ping;
    int i;
    object *all;
    if (me->query("family/family_name")!="桃花岛")
    {
        tell_object(me,"你跑到别人门派来干嘛？\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!me->query("thnewbiejob/jiuhua/start"))
    {
        tell_object(me,"未得庄主许可，任何人不得擅自采集花露。\n");
        return 1;
    }
    if (!present("ci ping",me))
    {
        tell_object(me,"你要用什么来盛放花露？\n");
        return 1;
    }
    ping=present("ci ping",me);
    if (!ping->query("is_ciping"))
    {
        tell_object(me,"你要用什么来盛放花露？\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"采集的方法是caiji <花名>\n");
        return 1;
    }
    if (arg!="mei gui"&&arg!="bai he"&&arg!="yujin xiang"&&arg!="huohe hua"&&arg!="jian lan"&&arg!="mantian xing"&&arg!="xiangri kui"&&arg!="lan hua"&&arg!="mati lian"&&arg!="xunyi cao")
    {
        tell_object(me,"你要采集什么花的花露？\n");
        return 1;
    }
    all=all_inventory(this_object());
    for (i=0;i<sizeof(all);i++)
    {
        if (arg==all[i]->query("id"))
        {
            message_vision("$N采集了一滴花露。\n",me);
            if(NATURE_D->outdoor_room_event() == "event_morning")
            {
                if (arg==me->query("thnewbiejob/jiuhua/p1")&&!me->query("thnewbiejob/jiuhua/p1get"))
                {
                    me->set("thnewbiejob/jiuhua/p1get",1);
                }
                else if (arg==me->query("thnewbiejob/jiuhua/p2")&&!me->query("thnewbiejob/jiuhua/p2get"))
                {
                    me->set("thnewbiejob/jiuhua/p2get",1);
                }
                else
                {
                    tell_object(me,"你忘记了陆乘风告诉你需要采集的花露，只好倒掉重来。\n");
                    me->set("thnewbiejob/jiuhua/p1get",0);
                    me->set("thnewbiejob/jiuhua/p2get",0);
                }
            }
            else
            {
                tell_object(me,"因为并不是清晨的花露，无法入药，你只好倒掉重来。\n");
                me->set("thnewbiejob/jiuhua/p1get",0);
                me->set("thnewbiejob/jiuhua/p2get",0);
            }

        }
        else
        {
            tell_object(me,"地上并没有这种鲜花。\n");
        }
        return 1;
    }
    
}