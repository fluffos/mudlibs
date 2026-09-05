// booksell

inherit NPC;
inherit F_DEALER;
#include <localtime.h>
void create()
{
	set_name("贩书郎", ({ "fanshu lang","lang", "seller"}) );
	set("gender", "男性" );
	set("age", 20+random(10));
	set("long",
		"这位伙计板着张脸，仿佛谁欠他钱一样。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "大弟弟");
	set("vendor_goods", ({
		"/d/yingtianfu/neicheng/obj/history-1",
        "/d/yingtianfu/neicheng/obj/history-2",
        "/d/yingtianfu/neicheng/obj/history-3",
        "/d/yingtianfu/neicheng/obj/history-4",
        "/d/yingtianfu/neicheng/obj/history-17",
        "/d/yingtianfu/neicheng/obj/history-19",
        "/d/yingtianfu/neicheng/obj/history-20",
	}));
	setup();
    call_out("gettime",1);
}

void init()
{	
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int gettime()
{
    mixed* timeinfos;
    int hour;
    timeinfos = localtime(time());
    hour = timeinfos[LT_HOUR];
    if (hour==4)
    {
        set("vendor_goods", ({
		"/d/yingtianfu/neicheng/obj/history-1",
        "/d/yingtianfu/neicheng/obj/history-5",
        "/d/yingtianfu/neicheng/obj/history-13",
        "/d/yingtianfu/neicheng/obj/history-4",
        "/d/yingtianfu/neicheng/obj/history-16",
        "/d/yingtianfu/neicheng/obj/history-18",
        "/d/yingtianfu/neicheng/obj/history-20",
	}));
    }
    if (hour==8)
    {
        set("vendor_goods", ({
		"/d/yingtianfu/neicheng/obj/history-6",
        "/d/yingtianfu/neicheng/obj/history-7",
        "/d/yingtianfu/neicheng/obj/history-8",
        "/d/yingtianfu/neicheng/obj/history-4",
        "/d/yingtianfu/neicheng/obj/history-21",
        "/d/yingtianfu/neicheng/obj/history-22",
        "/d/yingtianfu/neicheng/obj/history-20",
	}));
    }
    if (hour==12)
    {
        set("vendor_goods", ({
		"/d/yingtianfu/neicheng/obj/history-1",
        "/d/yingtianfu/neicheng/obj/history-5",
        "/d/yingtianfu/neicheng/obj/history-13",
        "/d/yingtianfu/neicheng/obj/history-4",
        "/d/yingtianfu/neicheng/obj/history-16",
        "/d/yingtianfu/neicheng/obj/history-18",
        "/d/yingtianfu/neicheng/obj/history-20",
	}));
    }
    if (hour==16)
    {
        set("vendor_goods", ({
		"/d/yingtianfu/neicheng/obj/history-14",
        "/d/yingtianfu/neicheng/obj/history-15",
        "/d/yingtianfu/neicheng/obj/history-13",
        "/d/yingtianfu/neicheng/obj/history-12",
        "/d/yingtianfu/neicheng/obj/history-8",
        "/d/yingtianfu/neicheng/obj/history-9",
        "/d/yingtianfu/neicheng/obj/history-10",
	}));
    }
    if (hour==20)
    {
        set("vendor_goods", ({
		"/d/yingtianfu/neicheng/obj/history-5",
        "/d/yingtianfu/neicheng/obj/history-9",
        "/d/yingtianfu/neicheng/obj/history-10",
        "/d/yingtianfu/neicheng/obj/history-12",
        "/d/yingtianfu/neicheng/obj/history-13",
        "/d/yingtianfu/neicheng/obj/history-9",
        "/d/yingtianfu/neicheng/obj/history-19",
	}));
    }
    if (hour==0)
    {
        set("vendor_goods", ({
		"/d/yingtianfu/neicheng/obj/history-2",
        "/d/yingtianfu/neicheng/obj/history-3",
        "/d/yingtianfu/neicheng/obj/history-16",
        "/d/yingtianfu/neicheng/obj/history-17",
        "/d/yingtianfu/neicheng/obj/history-11",
        "/d/yingtianfu/neicheng/obj/history-9",
        "/d/yingtianfu/neicheng/obj/history-13",
	}));
    }
    remove_call_out("gettime");
    call_out("gettime",600);
    return 1;
}