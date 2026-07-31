// Room: /d/4world/huofang.c
inherit ROOM;

void create ()
{
  set ("short", "仓库");
  set ("long", @LONG

这里不知是那家商号的仓库，周围密密麻麻堆放着些箱子。仓库中
做工的人很多，大多是光着脚的青年汉子。一趟又一趟的搬运着货
物。墙上贴着张大报，大意是缺人手，要请人来工作(work)。
LONG);
  set("objects", ([ /* sizeof() == 1 */
]));

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"west1",
]));

  setup();
}
void init()
{
        add_action("do_work", "work");
}

// 严格限制奖励
// 严格限制速度
// mudring.
int do_work(string arg)
{
        object ob;
        object me;

        me = this_player();

        if (me->is_busy()) {
                return notify_fail("旁边的壮汉赶紧把你扶起来：先歇一会儿。\n");
        }

        tell_object(me,"你从车上卸下一袋袋的大米，又垒在墙边，累的腰酸腿疼！\n");
        me->add("qi",-20);
        me->add("jing",-20);
        ob = new("/obj/money/silver");
        ob->move(me);
        tell_object(me,"旁边过来个工头笑眯眯地对你说：辛苦啦，这是你的工钱。\n");
        me->start_busy(6);
        return 1;
}
