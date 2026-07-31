// Room: murenxiang.c 木人巷
#include <ansi.h>
inherit ROOM;

int do_quit();
int do_save();
void muren_attack(object me);

void create()
{
        set("short", "木人巷");
        set("long", @LONG
这里是少林寺的木人巷，出家的小弟子第一次下山都必须通过十八木人的考验。
这里只有向前的路，并无回头的路了。
LONG);
        set("exits", ([ 
                "north" : __FILE__,
        ]) );
        set("no_sleep_room", 1);
        set("no_get_from", 1); 
        set("no_fight", 1); 
        setup();
}

void init()
{
        object me = this_player();
        if (userp(me)) {
                         if (interactive(me) && me->query("muren_winner")){
                 message_vision(HIR "一大群僧兵一涌而上，乱棒齐下，将$N打得昏死过去......\n" NOR, me);
                 me->unconcious();
                 me->set("eff_qi", 1);
                 me->set("qi", 1);
                 me->apply_condition("bonze_jali", 120);
                 me->move("/d/shaolin/jianyu");
                  }
                set("busy", 1);
                add_action("do_save", "save");
                add_action("do_quit", "quit");
                me->add_temp("murenxiang", 1);
                muren_attack(me);
        }
}

void muren_attack(object me)
{
        remove_call_out("muren_attack");
        if (me && present(me, this_object())) {
                call_out("muren_attack", 3, me);
                new(__DIR__"npc/muren_fighter" + me->query_temp("murenxiang"))->move(this_object());
        }
        else 
                delete("busy");
}

int do_save()
{
        write("这里不准存盘！\n");
        return 1;
}

int do_quit()
{
        write("这里不准退出！\n");
        return 1;
}

int valid_leave(object me, string dir)
{

        if (dir == "north" && me->query_temp("murenxiang") >= 9) {
                me->delete_temp("murenxiang");
                me->delete_temp("ask_muren");
                me->move(__DIR__"shijie1");
                me->add("combat_exp", 5000);
                me->set("muren_winner", 1);
                me->delete_temp("ask_muren");
                return notify_fail("历尽千辛万苦，你终于闯过了木人巷！经过此次闯阵，你觉得武功大进！\n");
        }
          
        return ::valid_leave(me, dir);
}
 
