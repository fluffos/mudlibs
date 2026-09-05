// 谷底
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>
#include "/d/xingxiu/flower.h"
string * animal=({__DIR__"npc/lingyang",__DIR__"npc/maoniu",__DIR__"npc/rabbit",__DIR__"npc/squirrel",__DIR__"npc/deer"});
string look_valley();
void create()
{
	set("short", HIM"谷底"NOR);
	set("long", @LONG
这里是星宿后山的谷底，繁花似锦，几只小动物悠闲地踱着步子。山明水秀，
你不禁有放声长啸(shout)的冲动。一条小溪(valley)流向山谷深处。
LONG
	);
	set("exits", ([ 
		"out" : __DIR__"gu2",
        "east" : __DIR__"shanlin3",
     
        
		
    ]));
    set("couldfish",1);
	set("objects", ([animal[random(sizeof(animal))] : 1,
    flower:2 ,
    ]));
    set("item_desc", ([ 
        "valley" : (:look_valley:),  
    ])); 
    set("resource/water", 1);
    set("no_reset",1);
    set("no_clean_up", 1);
    set("outdoors", "xingxiuhai");
	setup();
    call_out("echo",300);
    call_out("mes",1);
	::create();
}

string look_valley()
{
    object me=this_player();
    object ob;
    string msg;
    if (me->is_busy()||me->is_fighting())
    {
        msg="你正忙着呢。\n";
        return msg;
    }
    if (!me->query_temp("xx_valley_quest_entry_time"))
    {
        msg="你看来看去，并不能发现这条小溪，有任何异常之处。\n";
        return msg;
    }
    if (time()-(int)me->query_temp("xx_valley_quest_entry_time")>15)
    {
        msg="你看来看去，并不能发现这条小溪，有任何异常之处。\n";
        return msg;
    }
    else
    {
        if (ob=load_object(__DIR__"gu4"))
        {
            tell_room(this_object(),me->name()+"顺着溪流，向上游走去，越走越远了。\n");
            me->delete_temp("xx_valley_quest_entry_time");
            tell_room(ob,me->name()+"从小溪下游走了过来。\n");
            me->move(ob);
            msg="\n";
            return msg;
        }
        else
        {
            msg="程序出错，请联系Zine解决。\n";
            return msg;
        }
    }
}

int mes()
{
    object ob;
    ob=new(__DIR__"npc/mes1");
    ob->move(this_object());
    ob=new(__DIR__"npc/mes2");
    ob->move(this_object());
    return 1;
}

int echo()
{
    string ec,*echos=({});
    object ob=this_object();
    object *pl=all_inventory(ob);
    int i;
    if (ob->query("word1"))
    {
        echos+=({ob->query("word1")});
    }
    if (ob->query("word2"))
    {
        echos+=({ob->query("word2")});
    }
    if (ob->query("word3"))
    {
        echos+=({ob->query("word3")});
    }
    if (ob->query("word4"))
    {
        echos+=({ob->query("word4")});
    }
    if (ob->query("word5"))
    {
        echos+=({ob->query("word5")});
    }
    if (sizeof(echos)<=0)
    {
        echos+=({"啊啊啊～～啊啊～～\n"});
    }
    ec=echos[random(sizeof(echos))];
    tell_room(ob,HIG+"空谷中传来了一些奇怪的声响：\n"+ec+NOR);
    for (i=0;i<sizeof(pl);i++)
    {
        if (userp(pl[i])&&(!present("xiang",pl[i])||(present("xiang",pl[i])&&present("xiang",pl[i])->query("is_xiang"))))
        {
            tell_object(pl[i],"你不禁觉得有些蹊跷，此地一览无余，方圆几里之内全无人迹，这道回声来得太特别了。\n");
            tell_object(pl[i],"也许蹊跷之处，就在这条小溪。\n");
            pl[i]->set_temp("xx_valley_quest_entry_time",time());
        }
    }
    remove_call_out("echo");
    call_out("echo",300+random(600));
    return 1;
}

int record(string arg)
{
    object ob=this_object();
    if (!ob->query("word1"))
    {
        ob->set("word1",arg+"\n");
    }
    else if (!ob->query("word2"))
    {
        ob->set("word2",arg+"\n");
    }
    else if (!ob->query("word3"))
    {
        ob->set("word3",arg+"\n");
    }
    else if (!ob->query("word4"))
    {
        ob->set("word4",arg+"\n");
    }
    else if (!ob->query("word5"))
    {
        ob->set("word5",arg+"\n");
    }
    else
    {
        ob->set("word1",arg+"\n");
    }
    return 1;
}

int gene()
{
    object obs,*ob=all_inventory(this_object());
    int i;
    if (sizeof(ob)>5||time()-(int)this_object()->query("gene_time")<10)
    {
        return 1;
    }
    else
    {
        obs=new(flower);
        obs->move(this_object());
        obs=new(flower);
        obs->move(this_object());
        obs=new(animal[random(sizeof(animal))]);
        obs->move(this_object());
        this_object()->set("gene_time",time());
        return 1;
    }
}

void init()
{
    add_action("do_shout","shout");
    add_action("do_drink", "drink");
    gene();
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        if(arg)
                return 0;
        current_water = me->query("water");
        max_water = (int)me->max_water_capacity();
        if (current_water<max_water) {
                me->add("water", 250);
                message("vision", me->name()+"趴在小溪边，一通牛饮。\n",
                        environment(me), ({me}) );
                write("你趴在小溪边，咕噜咕噜喝起水来了。\n");
        }
        else write("你已经不渴了，还是别喝了。\n");

        return 1;
}

int do_shout(string arg)
{
    object me=this_player();
    if (!arg||!stringp(arg))
    {
        return 0;
    }
    record(arg);
    message_vision(HIC+"$N猛吸一口气，用丹田之气迸发出一声怒吼："+arg+"\n"+NOR,me);
    return 1;
}

int valid_leave(object me,string dir)
{  
    int i;
    object *all=deep_inventory(me);
	if (dir=="out") 
    {
        if (me->query("combat_exp")<100000&&me->query("family/family_name")=="星宿派")
        {
            return notify_fail("你这么菜就准备去闯荡江湖了？\n");
        }
        for (i=0;i<sizeof(all);i++)
        {
            if (userp(all[i])&&all[i]->query("family/family_name")=="星宿派"&&all[i]->query("combat_exp")<100000)
            {
                return notify_fail("把星宿年轻弟子背出去？亏你想的出来！\n");
            }
        }
        me->remove_listen_to_die(this_object());
		me->delete_temp("revive_room");
		return ::valid_leave(me, dir);
    }
    if (!userp(me)&&(dir=="out"||dir=="east"))
    {
        return notify_fail("\n");
    }
	return ::valid_leave(me, dir);
}
