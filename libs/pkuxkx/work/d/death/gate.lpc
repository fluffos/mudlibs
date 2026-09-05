// gate.c
// Modified by iszt@pkuxkx, 2007-05-21

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "鬼门关" NOR);
	set("long", 
		"这里就是著名的阴间入口「鬼门关」，在你面前矗立著一座高大的\n"
		"黑色城楼，许多亡魂正哭哭啼啼地列队前进，因为一进鬼门关就无法再\n"
		"回阳间了。抬头仰望，你竟然仿佛看到片片祥云，听到阵阵仙乐。\n");
	set("exits", ([
		"north" : "/d/death/gateway",
		//"up": "/d/heaven/nantianmen" //这是一个几乎什么都没有的房间，神话也不符合侠客行的基本设定，还可以用来钻复活漏洞，取消了。 zine@pkuxkx 2014/7/31
	]) );
	set("objects", ([
		__DIR__"npc/wgargoyle":1
	]) );
	set("no_fight", 1);
	set("no_perform", 1);
	set("no_exert", 1);
	set("abs_no_die",1);
	setup();
}

void init()
{
	object user = this_player(), obj;
    string id;

        if (!wizardp(this_player()))
	add_action("do_none", "");

	call_out("tooold", 1, user);

    //消灭一切npc
    if(user->is_character() && !userp(user) && !user->query("is_ghost"))
    {
        destruct(user);
    }

    if ( userp(user) )
    {
        obj = this_object();
        id = user->query("id");
        if (time()-obj->query_temp("record/"+id+"/time")>7200)
        {
            obj->set_temp("record/"+id+"/times", 1);
        }
        else
        {
            if (obj->query_temp("record/"+id+"/times") < 50) obj->add_temp("record/"+id+"/times", 1);
        }
        obj->set_temp("record/"+id+"/time", time());
    }
}

int do_none(string arg)
{
	string verb = query_verb();

        if(verb != "chat" &&verb != "chat*" && verb != "tell" && verb != "look" && verb != "go")
	{
		write("做鬼就老老实实呆着吧。\n");
		return 1;
	}
	return 0;
}

void tooold(object user)
{
	if(!user)
		return;
	if(user->query("max_qi") < 0 || user->query("max_jing") < 0)
	{
		user->set("tooold", 1);
		user->move("/d/city/mingren");
		user->set("startroom", "/d/city/mingren");
		user->set("max_qi", 10);
		user->set("eff_qi", 10);
		user->set("qi", 10);
		user->set("max_jing", 10);
		user->set("eff_jing", 10);
		user->set("jing", 10);
//		user->revive();
	}
}
