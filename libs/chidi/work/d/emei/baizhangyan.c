// Room: /d/emei/shanmen.c 峨嵋派 山门
// create by host dec,12

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "百丈岩");
    set("long", @LONG
你现在正走一条用坚实石板铺成的宽大石阶，两边建有石栏，凭栏观赏，
遥遥可望见峨嵋绝顶。循石阶而上，在石阶旁一块巨大的岩石矗立在那里，
在岩石上银钩铁划的上书“峨嵋重地，不得妄入”。
LONG
    );

    set("exits", ([
        "northdown":__DIR__"shijie3",
        "southup": __DIR__"jinding",
    ]));

    set("outdoors", "emei");
    set("objects",([
          CLASS_D("emei") + "/jingfeng" : 1,
    ]));
    setup();
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");

    if ((!myfam || myfam["family_name"] != "峨嵋派") && dir == "southup") {
        if(objectp(present("jing feng", environment(me))))
            return notify_fail("静风双手合十，闪身拦住你说道：这里是峨嵋派重地，施主还是请回吧。\n");
    }

    return ::valid_leave(me, dir);
}
