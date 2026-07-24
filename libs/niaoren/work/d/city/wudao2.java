// Room: /city/wudao2.c
// Date: Feb 27.1998 by Java
#include <ansi.h>;
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "四海擂");
	set("long", @LONG
這里是四海擂台，玩家可在此依次向本門擂主挑戰，爭奪 "本門第一" 的
稱號。台上告示(gaoshi)分明，各位大俠還是要讀一下，以免巫師誤會。本擂
客串古龍大俠主持擂務，對于這個酒歌放縱于天外的前輩，大家對他一貫是信
賴有加的。
LONG );
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east" : __DIR__"wudao",
	]));
        set("objects", ([
                __DIR__"npc/gulong" : 1,
        ]));
	set("no_clean_up", 0);
	setup();
}
string look_gaoshi()
{
	return 
"
1. 本擂台點到為止，只分勝敗，不決生死。
2. 本擂台由當值巫師安排各門派順次比武。原則上在線人數多的門派優先。
3. 在比武中，如果發生非比武門派弟子攪亂擂台，巫師有權以任何必要形式維
   護正常比武順利進行。
4. 大俠們也應度德量力，因實力過分懸殊去鬼門關旅游將沒有路費。
5. 允許\使用現行所有武功\，允許\perform，powerup，enforce，poison 等。
6. 允許\使用除金絲甲，軟猥甲，真絲寶甲外的所有防具。
7. 不允許\使用攻擊力超過50的兵器如敖拜匕首，倚天劍，伏魔刀等，但自鑄兵
   器不在此限。
8. 違反6.7 條，經核實后除立即取消稱號外，追加重罰。
9. 每個門派得出前兩名獲得者獎品可向天神選取。

                                    四海擂台  敬啟\n";
}
void init()
{
	add_action("do_quit","quit");
	add_action("do_quit","exit");
	add_action("do_quit","practice");
	add_action("do_quit","lian");
	add_action("do_quit","study");
	add_action("do_quit","du");
}

int do_quit(string arg)
{
        write(this_player()->query("name")+"，專心看比武吧！\n");
	return 1;
}
int valid_leave(object me, string dir)
{
	object obj;
	if (objectp(obj = present("gu long", environment(me))))
		if (obj->query("candidate")->query("id") == me->query("id"))
		return notify_fail("古龍攔住你說：你是候選人，豈有逃席之理。\n");

        return ::valid_leave(me, dir);
}
