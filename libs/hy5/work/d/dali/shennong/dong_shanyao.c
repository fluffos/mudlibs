// 东山腰 /d/menpai/shennong/dong_shanyao.c

inherit ROOM;



void create()
{   
    set("short",    "东山腰");
    set("long", @LONG
转过山坳，只见一大堆乱石之中团团坐着二十余人。人丛中一个瘦小的老者
坐在一块高岩之上，高出旁人，颌下一把山羊胡子，神态甚是倨傲。乱石之后有
大股大股的青烟冒出，带来一阵阵让人很不舒服的气味。
LONG
    );
    set("exits",    ([
        "south"     :   __DIR__"dong_shanao",
        "northeast" :   __DIR__"luanshi_hou",
    ]) );
    set("objects",  ([
        __DIR__"npc/sikong_xuan"    :   1,
        __DIR__"npc/gao_laozhe"     :   1,
        __DIR__"npc/bangzhong"      :   2,
    ]) );
    set("outdoors", "wuliang");
    setup();
}
