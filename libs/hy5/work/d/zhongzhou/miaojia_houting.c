#include <ansi.h> 

inherit ROOM;

void create()
{
	set("short", "苗家后厅");
	set("long", @LONG
这里是苗家的后厅，厅内非常的宽敞明亮。正中摆放着张
八仙桌，四周墙壁上挂着一些字画。只见一个脸色透黄，神情
严肃的瘦高个子正座中堂，正是「金面佛」苗人凤。
LONG);
	set("exits", ([
  		"west"  : __DIR__"miaojia_zoulang1",
  		"north" : __DIR__"miaojia_zoulang2",
  		"south" : __DIR__"miaojia_shufang",
	]));
        set("objects", ([
                CLASS_D("miao") + "/miao" : 1,
                "/quest/menpai/newmp/shi7" : 1,
                "/kungfu/class/hu/tian" : 1,
                "/d/biwu/champion_hj" : 1,
"/d/zhongzhou/npc/dizi" : 4,

        ]));
set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("coor/x", -180);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        "/clone/board/miao_b"->foo();
}

int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me = this_player();

        if (dir == "north" || dir == "south")
        {
                if ((string)me->query("family/family_name") != "关外胡家"
                & objectp(present("miao renfeng", environment(me))))
                        return notify_fail(CYN "苗人凤眉头微微一皱，喝道：阁下未"
                                           "免太过放肆，是瞧不起苗某人吗？\n" NOR);
        }
        return ::valid_leave(me, dir);
}
