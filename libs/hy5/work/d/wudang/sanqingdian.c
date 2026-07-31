// sanqingdian.c 三清殿
// by Xiang
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "三清殿");
        set("long", @LONG
这里是凌霄宫的三清殿，是武当派会客的地点。供着元始天尊、太上道
君和天上老君的神像，香案上香烟缭绕。靠墙放着几张太师椅，地上放着几
个蒲团。东西两侧是走廊，北边是练武的广场，南边是后院。
LONG );
        set("valid_startroom", 1);
        set("exits", ([
                "north" : __DIR__"guangchang",
                "south" : __DIR__"houyuan",
                "east"  : __DIR__"donglang1",
                "west"  : __DIR__"xilang",
        ]));
        set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("objects", ([
                CLASS_D("wudang") + "/guxu" : 1,
                CLASS_D("wudang") + "/song" : 1,
                "/d/biwu/champion_wd" :1,
    "quest/menpai/wudang/shi" : 1,                      
        ]));
//        set("no_clean_up", 0);
        setup();
        "/clone/board/wudang_b"->foo();
}

void init()
{
        object me;
        mapping skill_status;
        string *sname;
        int i, level;
        float exper;

        me = this_player();

        exper = to_float(me->query("combat_exp"));

        if ( !(skill_status = me->query_skills()) ) return;
        sname  = keys(skill_status);

        for(i=0; i<sizeof(skill_status); i++)
        {
                level = skill_status[sname[i]];
                if( pow(to_float(level), 3.0) / 10.0 > exper
                && exper > 100.0
                && sname[i] != "buddhism"
                && sname[i] != "literate"
                && sname[i] != "taoism" )
                {
                        level = ceil( pow( exper*10.0, 0.333333) );
                        me->set_skill(sname[i], level);
                }
        }
        add_action("do_turn", "turn");
}
int do_turn(string arg){
        object me, guard, nroom;    
        me = this_player();
        if(!arg || (arg != "handle" && arg != "把手")) {
                tell_object(me,"你要转什么？\n");
                return 1;
        }
        message_vision(HIY "$N在椅子上按了一下，脚下忽然裂开了一个大洞，\n$N大叫了一声，掉了下去。\n"NOR, this_player());
        nroom = find_object("/d/ghost/dijiao");
        if(!objectp(nroom)) nroom=load_object("/d/ghost/dijiao");
   me->move(nroom);
        message_vision(HIY "\n$N走进了神龛后的后门。\n"NOR, me);
        return 1;
}  
