// shufang 书房
#include <ansi.h>

inherit ROOM;

void init();

void create() {
    set("short", "书房");
    set("long",
"这里是一间书房，除了书桌(desk)书架外，并没有太多装饰。唯有窗旁挂着\n" +
"一幅立轴，上面写着：“" + HIY "谁人多事种芭蕉，早也萧萧，晚也萧萧。" NOR + "”若是透窗看\n" +
"去，可见屋外正是种着几株芭蕉树。此间主人或许有些心事？\n");

    set("item_desc", ([
        "desk" : "笔砚等物之外，书桌上还放着一个青铜香炉(xianglu)，颇有古意。\n",
    ]));

    set("exits", ([
        "west" : __DIR__"woshi",
    ]));

    setup();
}
