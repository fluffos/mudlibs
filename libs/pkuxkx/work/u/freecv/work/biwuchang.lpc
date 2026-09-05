// biwuchang.cg.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"比武场"NOR );
        set("long", HIY@LONG
    说英雄谁是英雄。这里是扬州城里唯一的比武场，四周旗杆林立
到处都是观战的人群，不时发出一阵阵喝彩声。比武台中央站着江湖
上黑白两道皆敬畏的老侠“铁手丹心”。
LONG NOR
        );
        set("exits", ([ /* sizeof() == 1 */
             "west" : "/u/freecv/wizard_room_freecv",
//          "down" : __DIR__"shangyuetai",
//          "up" : __DIR__"restroom",
        ]));
        set("objects",([
                  "/d/city/npc/tieshou" : 1,
                 CLASS_D("btshan/ouyangfeng") : 1,
                 CLASS_D("lingjiu/tonglao") : 1,
                 CLASS_D("gaibang/hong") : 1,
                 CLASS_D("huashan/feng") : 1,
                 CLASS_D("mingjiao/zhang") : 1,
                 CLASS_D("quanzhen/wang") : 1,
                 CLASS_D("riyuejiao/dongfang") : 1,
                 CLASS_D("shaolin/damo") : 1,
                 "/d/dali/npc/duanyu" : 1,
                 CLASS_D("wudang/zhang") : 1,
                 CLASS_D("gumu/yang") : 1,
                 CLASS_D("gumu/longer") : 1,
                 CLASS_D("taohua/huang") : 1,
                 CLASS_D("xingxiu/li") : 1,
                   "/d/pker/npc/chu" : 1,
                "/d/emei/houshan/npc/miejue" : 1,
                   CLASS_D("murong/murongbo") : 1,
                   CLASS_D("tiandihui/chen") : 1,
        ]));
       set("no_die", 1);
        set("no_clean_up", 0);
        set("outdoors", "xx" );
        setup();
	call_other("/clone/board/fight_b", "???");
}

// changed by akuma 
// 防止有人利用比武来练功
// hehe

void init()
{
//        object me=this_player();
	add_action("do_none",({"lian","study","xue","learn","dazuo","tuna","exercise","apprentice","du","research","practice",}));
	add_action("do_quit",({"quit","suicide"}));
/*	me->set_temp("biwu/combat_exp",me->query("combat_exp"));
	me->set_temp("biwu/learned_points",me->query("learned_points"));
	me->set_temp("biwu/potential",me->query("potential"));
	me->set_temp("biwu/qi",me->query("qi"));
	me->set_temp("biwu/eff_qi",me->query("eff_qi"));
	me->set_temp("biwu/max_qi",me->query("max_qi"));
	me->set_temp("biwu/jing",me->query("jing"));
	me->set_temp("biwu/eff_jing",me->query("eff_jing"));
	me->set_temp("biwu/max_jing",me->query("max_jing"));
	me->set_temp("biwu/neili",me->query("neili"));
	me->set_temp("biwu/max_neili",me->query("max_neili"));
	me->set_temp("biwu/jingli",me->query("jingli"));
	me->set_temp("biwu/max_jingli",me->query("max_jingli"));
*/
	// ok
}

int do_none()
{
	write("对不起，比武场中请不要练功。\n");
	return 1;
}
int do_quit()
{
          this_player()->move("/adm/room/quitroom");
        return 1;
}

int valid_leave(object me,string dir)
{
if(me->query("age")<18&&dir=="up")
{
 return notify_fail("小毛孩不能到这种地方去！\n");
}
/*	me->set("learned_points",me->query_temp("biwu/learned_points"));
	me->set("combat_exp",me->query_temp("biwu/combat_exp"));
	me->set("potential",me->query_temp("biwu/potential"));
	me->set("qi",me->query_temp("biwu/qi"));
	me->set("eff_qi",me->query_temp("biwu/eff_qi"));
	me->set("max_qi",me->query_temp("biwu/max_qi"));
	me->set("jing",me->query_temp("biwu/jing"));
	me->set("eff_jing",me->query_temp("biwu/eff_jing"));
	me->set("max_jing",me->query_temp("biwu/max_jing"));
	me->set("neili",me->query_temp("biwu/neili"));
	me->set("max_neili",me->query_temp("biwu/max_neili"));
	me->set("jingli",me->query_temp("biwu/jingli"));
	me->set("max_jingli",me->query_temp("biwu/max_jingli"));
	me->delete_temp("biwu");
*/
	return ::valid_leave(me,dir);
}
