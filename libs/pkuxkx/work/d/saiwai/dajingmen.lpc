//大境门 /d/jinyang/dajingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "大境门");
        set("long", 
"这里位于高耸入云的东、西太平山间，据长城之要隘，扼边关之锁钥，形式\n险要，为历代兵家必争之地。它一夫当关，万夫莫开，以雄伟、险峻闻名于世。\n城墙上贴着告示(gaoshi)。山边长着些合欢(hehuan)。\n"

        );
        set("item_desc", ([
		"hehuan" : "合欢可以入药，你可以摘(zhai)下来。\n", 
	    ])); 
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
                //"west" : __DIR__"eastavenue1",
                "north" : __DIR__"guandaon1",
                //"southwest" : __DIR__"citywall2",
                "south" : __DIR__"northstreet",
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "saiwai");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n宣大总督谕\n";
}

void init()
{
	object me=this_player();
	add_action("do_zhai","zhai");
    add_action("do_southeast","southeast");
    add_action("do_southeast","东南");
	if (!me->query_temp("shediaoquest/zjk/intro")&&(me->query("shediaoquest/zjk")==1||me->query("shediaoquest/zjk")==2))
	{
		tell_object(me,HIW+"张家口是南北通道，塞外皮毛集散之地，人口稠密，市肆繁盛。\n"+NOR);
		tell_object(me,BLINK+RED+"你此刻才觉得腹中饥饿，快找一家酒家吧。\n"+NOR);
		me->set_temp("shediaoquest/zjk/intro",1);
	}
	return;
}

int do_southeast()
{
    object me=this_player();
    object ob=this_object();
    object nextdoor=load_object("/d/jueqinggu/xiaolu");
    tell_room(nextdoor,me->query("name")+"不知从何处爬了出来。\n");
    me->move(nextdoor);
    tell_object(me,"你攀上岩石，迅速往绝情谷方向移动。\n");
    tell_room(ob,me->query("name")+"攀上两旁的岩石，身影迅速消失在你的视野里。\n");
    return 1;
}
int do_zhai()
{
    object me=this_player();
    object gc;
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("合欢"))
    {
        return notify_fail("合欢已经被摘完了。\n");
    }
    me->set_temp("合欢",1);
    gc=new("/d/taishan/obj/hehuan");
    gc->move(me);
    message_vision("$N摘下了一片合欢。\n",me);
    return 1;
}

int valid_leave(object me,string dir)
{
    if (dir=="north")
    {
		if (load_object("/d/menggu/xiboliya"))
		load_object("/d/menggu/xiboliya")->init_robbers();
		if (!userp(me))
        return notify_fail("\n");
    }
    return ::valid_leave(me,dir);
}