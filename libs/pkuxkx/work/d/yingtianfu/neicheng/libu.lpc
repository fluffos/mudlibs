//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"吏部衙门"NOR);
        set("long", 
"这里吏部衙门的大门。\n"

        );
        set("exits", ([
                
              
                
                
                "west" : __DIR__"changanjie1",
                "enter" : __DIR__"li_garden",
                
                
                
        ]));
        set("valid_startroom", 1);
        set("objects", ([
		__DIR__"npc/bing4" : 2,
	    ]));
        setup();
   
}

void init()
{
    add_action("do_daying","daying");
}

int do_daying()
{
    object me=this_player();
    object officer;
    if (!me->query_temp("mingtasks/libu/introducer"))
    {
        return 0;
    }
    officer=find_player(me->query_temp("mingtasks/libu/introducer"));
    if (!officer||!living(officer)||base_name(environment(officer))!=base_name(environment(me)))
    {
        tell_object(me,"你的引荐人不在场，还是等等吧。\n");
        return 1;
    }
    me->delete_temp("mingtasks");
    me->add("zhusantimes",1+random(2));
    officer->set_temp("mingtasks/libu/task1finish",2);
    MONEY_D->pay_player(me,100000);
    message_vision("$N静静对答吏部官员的问话，$n听得暗暗点头。\n",me,officer);
    message_vision("良久，吏部官员道：现在史督师在扬州急需人才，$N似乎很对他的胃口，我已为你在他军中记下一功。\n",me);
    message_vision("朝廷不能薄待贤士，特赠你黄金十两。\n",me);
    return 1;
}

int valid_leave(object me,string dir)
{
    if (!userp(me)&&dir=="west"&&!me->query("mingpin"))
    {
        return notify_fail("\n");
    }
    if (dir=="enter"&&!me->query("mingpin")&&!me->query("ming/tj/pin")&&!present("entry permit",me)&&!me->query("mingjiaonewbiejob/daming")&&!me->query_temp("mingtasks/libu/theone"))
    {
        return notify_fail(this_object()->query("short")+"闲杂人等，不得入内。\n");
    }
        
    return ::valid_leave(me,dir);
}
