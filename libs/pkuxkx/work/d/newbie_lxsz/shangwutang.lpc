// D:\xkx\d\liuxiu-shanzhuang\shangwutang.c尚武堂
// labaz  2012/10/23
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"
#define DIE_NOTIFY_NO_CONTINUE 486

void create()
{
    set("short", "尚武堂");
    set("long", 
"你走进了一间开阔的武堂。纵横开阔几十丈，仿佛进入了一个开阔
的广场。武馆内的兵器架"+YEL"(shelf)"NOR+"上的武器应有尽有，木人几十具成矩形排
开，梅花桩、八卦阵也有数处。几名劲装的武师在里面或练习、或印证功夫，
呵呵有声。“尚武堂”三个遒劲的大字悬于高粱。这里明显比一般的武馆都
要宏大，更有气势。

                   "+HIC"※==※==※==※==※
                   ※  尚  武  堂  ※ 
                   ※==※==※==※==※"NOR+"

"
);

    set("indoors","liuxiu-shanzhuang");

    set("item_desc", ([
        "shelf":HIY"兵器架里有几把很独特的长剑，因为太过锋利，\n所以只有等你武功达到一定程度时也许才有机会得到一把。\n"NOR,
        ]));

    set("exits", ([
        "north" : __DIR__"cangshuge",
        "south" : __DIR__"zhengting",
        ])
     );

	set("objects", ([
		__DIR__"npc/wushi" : 1,
	]));
	
	// set("no_get",1);
	set("no_put",1);
    setup();
}

void init()
{
	object ob,who;
	ob=this_object();
	who=this_player();
	
	if (1==who->query_temp("newbie/fight"))
	{
		set_nextquest(who,"尚武堂找武师比武，fight wushi","这场比试消耗了你不少的体力，回厢房去休息(sleep)一下吧。", 20, 100);
	}
	add_action("show_quest","quest");
	this_player()->listen_to_die(this_object());
}


int die_notify(object victim)
{
    object killer;
    if(!objectp(victim) || !userp(victim)) return 0;
    if(environment(victim) == this_object() && userp(victim))
    {
        if(victim->query("qi") < 1) victim->set("qi",1);
		if(victim->query("eff_qi") < 1) victim->set("eff_qi",1);
    }
    return DIE_NOTIFY_NO_CONTINUE;
}


int valid_leave(object who,string dir)
{
	object ob,*inv;
    int i;
    
	if (who->is_fighting()) return notify_fail("你正在战斗中，没分出胜负前不能离开这个房间。\n");
	
	if (1==check_questindex(who,"找武师拜师学艺，bai wushi") && 1==who->query_temp("newbie/needmoney"))
	{
		set_nextquest(who,"找武师拜师学艺，bai wushi","帮武师去铁匠铺买一把钢剑，去酒铺买一壶烧刀子酒，回来交给武师", 20, 100);
		ob=new("/clone/money/silver");
		ob->set_amount(6);
		tell_object(who,GRN"武师挠了挠头，道，先别走，还没给你钱。咳，给你六两白银去置办吧。\n"NOR);
		ob->move(who);
		tell_object(who,GRN"武师给你了六两白银。\n\n"NOR);
		who->set_temp("newbie/needmoney",0);
		return notify_fail("你停下了脚步。\n");
	}
    
    if ("north"==dir && 1!=check_questindex(who,"去藏书阁读江湖掌故"))
    {
        return notify_fail("藏书阁重地，未经庄主许可不得擅入！\n");
    }
    
    if ("north"==dir)
    {
        inv = all_inventory(who);
        for(i=0; i<sizeof(inv); i++) 
        {
            if (userp(inv[i])) return notify_fail("藏书阁重地，未经庄主许可不得带人擅入！\n");
        }
    }
	who->remove_listen_to_die(this_object()); 
	return ::valid_leave(who,dir);
}


