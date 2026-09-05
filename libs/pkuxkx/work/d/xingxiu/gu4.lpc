// 谷底
// edit: by zine Oct 19 2010

inherit "/d/xingxiu/xxconfig";
#include <ansi.h>
#include "/d/xingxiu/flower.h"
//#include "/d/menggu/entry_migong.h"
string * animal=({__DIR__"npc/lingyang",__DIR__"npc/maoniu",__DIR__"npc/rabbit",__DIR__"npc/squirrel",__DIR__"npc/deer"});
string look_valley();
string look_incense();
void create()
{

	set("short", HIM"谷底深处"NOR);
	set("long", @LONG
这里是谷底的深处，繁花似锦，几只小动物悠闲地踱着步子。只见一条小溪
(valley)流出山谷。地上遗有几支未燃尽的香(incense) 。这里还有一间草庐，
不知是何人修建。
LONG
	);
    set("exits", ([
             "northup" : __DIR__"waterfall",
             "enter" : __DIR__"caolu",
             "east" : __DIR__"shanlin6",
			 //"westdown" : "/d/lingzhou/zhaling3",
        ]));
	set("resource/water", 1);
    set("couldfish",1);
    set("outdoors", "xingxiuhai");
	set("objects", ([animal[random(sizeof(animal))] : 1,
    flower:2 ,
    ]));
    set("item_desc", ([ 
        "valley" : (:look_valley:),
        "incense" : (:look_incense:),
    ]));
	/*set("entry_direction","westdown");
	set("migong","/d/lingzhou/zhaling");
	set("migong_posi","east");
	set("look_refuse_msg","扎陵湖升腾起一片雾气，你什么也看不清。\n");
	set("enter_refuse_msg","扎陵湖升腾起一片雾气，你什么也看不清，稍等再进吧。\n");*/
    setup();
	::create();
}

string look_incense()
{
    object me=this_player();
    string msg;
    if (me->query("family/family_name")=="星宿派")
    {
        msg="这节断香似乎对于炼毒有很大助益，你拿(get)回去问问我踏月色而来吧。\n";
    }
    else
    {
        msg="不明白的东西最好别碰。\n";
    }
    return msg;
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
    else if (ob=load_object(__DIR__"gu3"))
        {
            tell_room(this_object(),me->name()+"顺着溪流，向下游走去，越走越远了。\n");
            me->delete_temp("xx_valley_quest_entry_time");
            tell_room(ob,me->name()+"从小溪上游走了过来。\n");
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


void init()
{
    add_action("do_get","get");
    add_action("do_drink", "drink");
}

int do_get(string arg)
{
    object ob,me=this_player();
    if (!arg||(arg!="incense"&&arg!="香"&&arg!="xiang"))
    {
        return 0;
    }
    if (me->query_temp("xx_valley_quest_pick_incense"))
    {
        tell_object(me,"你不是刚刚取过香吗？留点给你的师兄弟吧。\n");
        return 1;
    }
    ob=new(__DIR__"obj/incense");
    ob->move(me);
    me->set_temp("xx_valley_quest_pick_incense",1);
    message_vision(HIC+"$N从地上的几支香中取了一支收好。\n"+NOR,me);
    return 1;
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