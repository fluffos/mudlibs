//Writen by lnwm
//caopeng.c

inherit ROOM;

void create()
{
    set("short", "小草棚");
    set("long", @LONG
路边临时搭建的小草棚，因为山里常常多雨，所以村民们就搭了这个
小棚子。到了雨天，村民就聚在这里一边欣赏雨幕中的青城山，一边大拜
龙门阵。有几个孩子在这里玩耍，一个杂货贩在这里歇脚。
LONG
    );
    set("exits", ([
        "west"      :    __DIR__ "lroad4",
        ]));
    set("objects", ([           
         __DIR__ "npc/xiaofan" : 1,
    ]) );
    set("outdoors","lnwm");
    setup();
}


