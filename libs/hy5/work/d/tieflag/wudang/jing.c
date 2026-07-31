#include <ansi.h>
inherit ROOM; 
void create()
{
    set("short", "水井中");
    set("long", @LONG
在水井中睁眼四望，四周井壁滑不留手。你心里后悔不及，不知
如何才能出去。井中灰朦朦的，象是什么都没有。如果四周搜索一下，
也许有所发见。
LONG
        );
    set("item_desc", ([
        "wall": "滑不留手的井壁。你可以试着爬(climb)上去。\n",
        "井壁": "滑不留手的井壁。你可以试着爬(climb)上去。\n",
        ]) );
    set("coor/x",150);
    set("coor/y",-130);
    set("coor/z",-40);
    setup();
} 
void init()
{
    add_action("do_climb", "climb");
    add_action("do_search", "search");
    call_out("airing", 5, this_player());
} 
int do_search(string arg)
{
    object ob;
    
    ob = this_player();
    if( ob->is_busy() )
        return notify_fail("你的动作还没有完成，不能移动。\n");
    message_vision("$N仔细的查看四周的井壁，搜遍了各个角落。\n", ob);
    ob->start_busy(2);
    call_out("search_obj", 4, ob);
    return 1;
} 
int search_obj(object me)
{
    int kar;
    int exp;
    object sword, box ;
    
    if(!(this_object()->query("marks/没了")))
    {
        kar = (int)me->query("kar");
        exp = (int)me->query("combat_exp");
        if( kar > 40 ) kar = 40;
        if( (random(40 - kar) < 5) && exp >= 2000000 && me->query_skill("dodge",1)>=100)
        {
            this_object()->set("marks/没了", 1);
            message_vision(HIY "$N找到了一个长方铁盒，放进了怀里。\n"NOR, me);
            me->set_temp("marks/七星剑", 1);
            me->command("remove all");
            seteuid(geteuid(me));
            sword = new(__DIR__"obj/msword2");
            box = new(__DIR__"obj/box");
            sword->set_temp("marks/owner", me);
            sword->set_temp("marks/owner_name",me->query("id"));
            sword->move(box);
            box->move(me);
            if(!me->query("m_success/七星剑"))
            {
                me->set("m_success/七星剑",1);
                me->add("score",150);
                me->add("combat_exp",15000);
                me->add("potential",1900);
                tell_object(me,"好样的，你得到150点评价，1900点潜能，15000点经验！\n");
                tell_object(me,"不过，还是快离开这里吧。\n");
            }
        }
        else message_vision("$N什么都没找到。\n", me);
    }
    else message_vision("$N什么都没找到。\n", me);
    return 1;
} 
int airing(object ob)
{
    int i, htime, ntime;
    
    if( environment(ob) == this_object())
    {
        htime = (int)ob->query("str") + (int)ob->query("kar");
        if(!(ntime = (int)ob->query_temp("marks/井时")))  ntime = 5;
        else ntime = ntime + 5;
        ob->set_temp("marks/井时", ntime);
        if( ntime > htime ) {
            ob->die();
            ob->set_temp("marks/井时", 0);
        }
        else if( ntime > (htime - 15) )
            message_vision(HIR "$N已经憋得成半昏迷状态，再不出赶快出井，就会憋死在这儿。\n"NOR, ob);
        else if( ntime > (htime - 30) )
            message_vision(HIR "$N已经憋得面红耳赤，半分钟之内再不出井，恐怕会憋死在这儿。\n"NOR, ob);
        else 
            message_vision(HIW "$N觉得胸口越来越闷，大概在井里已呆不了很久。\n"NOR, ob);
        
        call_out("airing",5, ob);
    }
    return 1;
} 
int do_climb(string arg)
{
    object obj, me;
    int kar;
    
    if(!arg || arg=="") return notify_fail("你要往哪里爬？\n");
    me = this_player();
    if( arg == "wall" || arg == "井壁" || arg == "up")
    {
        if( me->is_busy() )
            return notify_fail("你的动作还没有完成，不能移动。\n");
        message_vision("$N使出吃奶的力量，顺着井壁向上爬去。\n", me);
        me->start_busy(1);
        call_out("climb_wall", 2, me);
        return 1;
    }
    return notify_fail("你不可以爬"+arg+"！\n");
}        
int climb_wall(object me)
{
    int kar;
    if (me->is_ghost()) return 0;
    kar = (int)me->query("kar");
    if( kar > 60 ) kar = 60;
    if( random(60 - kar) < 15 )
    {
        me->set_temp("marks/井时", 0);
        me->move(__DIR__"wudang3.c");
        message_vision("$N从水中湿淋淋的爬了出来。\n", me);
    }
    else message_vision("$N手上一个没抓稳，又掉了下来。\n", me);
    return 1;
}  
void reset()
{
    ::reset();
    delete("marks/没了");
}     
