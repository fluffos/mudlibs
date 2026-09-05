//Zine 给盗宝人增加点麻烦

inherit ROOM;
#include <ansi.h>
int name();
string *shorts=({"荒地","山坡","溪间","草丛","树林","小道","废宅","破庙"});
string *colors=({HIR,RED,HIW,WHT,HIC,CYN,HIY,YEL,HIB,BLU,HIG,GRN,HIM,MAG,HBMAG,HBBLU,HBRED,HBRED,HBYEL,HBWHT,HBCYN});
int selfcheck();
void create()
{
	set("short", "荒地");
	set("long", "这里是一处荒地，人迹罕至，也不知道你怎么会来到这里的。\n");
    set("outdoors", "changbai");
    set("dbr_stage",1);
    set("no_task",1);
    set("real_dark",1);
    set("least_msg",1);
    set("no_reset",1);
    set("no_clean_up", 1);
    set("exits/out",__DIR__"dbr_stage2");
    setup();
    name();
    call_out("selfcheck",1);
}

int selfcheck()
{
    int i;
    object vic,rm;
    object * all=all_inventory(this_object());
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("id")=="corpse"&&all[i]->query("victim_id"))
        {
            vic=find_player(all[i]->query("victim_id"));
            if (vic && userp(vic)&&vic->query_temp("yidao/luanru_pre_loc"))
            {
                rm=load_object(vic->query_temp("yidao/luanru_pre_loc"));
                if (rm)
                {
                    all[i]->move(rm);
                    tell_room(rm,"一具尸体被一辆路过的马车丢了出来！\n");
                }
            }
        }
        if (!all[i]->is_character())
        {
            destruct(all[i]);
        }
    }
    call_out("selfcheck",120);
    return 1;
}

void init()
{
    add_action("do_look","look");
}

int do_look(string arg)
{
    object me=this_player();
    if (arg=="out")
    {
        write(WHT"那边灰蒙蒙的，什么也看不清！\n"NOR);
        return 1;
    }
    return 0;
}

int name()
{
    int number=random(sizeof(shorts));
	set("short", colors[random(sizeof(colors))]+shorts[number]+NOR);
	set("long", "这里是一处"+shorts[number]+"，人迹罕至，也不知道你怎么会来到这里的。\n");
    delete("realmap");
    return 1;
}

int valid_leave(object me,string dir)
{
    object where,killer;
    if (me->query_temp("yidao/target_ob"))
    {
        killer=me->query_temp("yidao/target_ob");
    }
    if (dir=="out")
    {
        if (!userp(me)||me->query("hyd/step"))
        {
            return notify_fail("\n");
        }
        else if (killer&&present(killer,this_object())&&!me->query_temp("hyd_want_exit_without_finish"))
        {
            me->set_temp("hyd_want_exit_without_finish",1);
            return notify_fail("你要杀的盗宝人"+killer->query("name")+"还在这里呢，你确定要离开，请再次输入out。\n");
        }
        else if (!me->query_temp("hyd_exits_out"))
        {
            while (!objectp(where) || 
                   !where->isroom()||
                   MAP_D->place_belong(where)=="不明区域"||
                   MAP_D->place_belong(where)=="未知区域"||
                   base_name(where) == "/adm/daemons/taskd")
            {where=MAP_D->random_place();}
            me->move(where);
            me->delete_temp("hyd_want_exit_without_finish");
            return notify_fail("你似乎被困住了，关键时刻，巫师出手相助，你被带到了一处所在。\n");
        }
        else
        {
            where=load_object(me->query_temp("hyd_exits_out"));
            if (where)
            {
                me->delete_temp("hyd_exits_out");
                me->move(where);
            }
            me->delete_temp("hyd_want_exit_without_finish");
            return notify_fail("你发现了一条出路，毫不迟疑的走了出去。\n");
        }
    }
    return ::valid_leave(me,dir);
}