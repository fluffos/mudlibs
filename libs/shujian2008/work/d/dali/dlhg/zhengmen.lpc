// Room: /dlhg/zhengmen.c

inherit ROOM;
#include <wanted.h>
#include <ansi.h>
#include <room.h>

string look_gaoshi();

void create()
{
        set("short", "皇宫正门");
        set("long", "这便是大理皇宫正门。巍峨雄伟的城墙上，「"HIY"圣慈宫"NOR"」三个大字十分显眼，
气势辉煌。夕阳照在琉璃瓦上，金碧辉煌，令人目为之眩。一张镶着金边的告
示(gaoshi)贴在墙上，许多侍卫立在两旁。路旁还立了一座牌坊(paifang)。\n");

        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
                "paifang":HIC"\n\t\t※  ※ 圣   道   广   慈 ※  ※\n\n"NOR, 
        ]));

        set("exits", ([
                "north" : __DIR__"zoulang1",
                "south" : "/d/dali/qsjie2",
        ]));
        set("objects", ([
                __DIR__"npc/shiwei" : 4,

        ]));
        set("outdoors", "大理");
        set("coor/x",-310);
  set("coor/y",-440);
   set("coor/z",-20);
   setup();
}

string look_gaoshi()
{
        return HIY"
\t\t※※※※※※※※※※※※※※※※※
\t\t※※※                      ※※※
\t\t※※※  "HIR"皇宫重地  闲人莫入"HIY"  ※※※
\t\t※※※                      ※※※
\t\t※※※※※※※※※※※※※※※※※\n"NOR;
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && is_wanted(me))
		return 0;
	if (dir=="north" && objectp(present("huanggong shiwei", this_object()))) {
		if (me->query("qinwang"))
			message_vision(HIY"侍卫恭恭敬敬地对$N说道：“原来是"
				+(string)me->query("qinwang")+"，请进，请进。”\n"NOR, me
			);
		else if (me->query_skill("qiantian-yiyang")&&!me->query("tls"))
			message_vision(HIY"侍卫恭恭敬敬地对$N说道：“原来是镇南王府的人，请进，请进。”\n"NOR, me); 
		
		else if (me->query_temp("huanggong") )
			message_vision(HIY"侍卫恭恭敬敬地对$N说道：“原来是镇南王府的人，请进，请进。”\n"NOR, me); 
		
		else {
			if (me->query("gender") == "女性")
				return notify_fail("侍卫上前挡住你，朗声说道：皇宫重地，岂容寻常烟花女子自由出入。\n");
			if (me->query("gender") == "无性") 
				return notify_fail(
					"侍卫上前挡住你，朗声说道：这里是大理的皇宫，不是京城的紫禁城，公公请回吧。\n"
				);
			if (me->query("gender") == "男性") 
				return notify_fail("侍卫伸手拦住你朗声说道：皇宫重地，岂容寻常乡村野夫自由出入。\n");
		}
	}      
	return ::valid_leave(me, dir);
}
