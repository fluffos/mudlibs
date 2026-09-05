// taohuadao/qingxiaoting 清啸亭

inherit ROOM;

void create()
{
    set("short", "清啸亭");
    set("long", @LONG
这是一个凉亭。四周桃花芬芳，实乃幽闲清雅之地。不远处有一个小木屋(house)，显得非常的别致。
LONG
    );
    set("item_desc",([
                "house" : "小木屋朝南有一扇门(door)，可以走进去(enter)看看。\n",
                ]));

    set("exits", ([ /* sizeof() == 1 */
                "westup" : __DIR__"liangwangfeng",
                ]));
    set("outdoors","taohuadao");
    setup();
}
void init()
{
    add_action("do_enter","enter");
}
int do_enter(string arg)
{
    object me = this_player();
    if(!arg || arg =="")
        return 0;
    if (arg =="door")
    {
        if ((me->query_temp("marks/蓉") && me->query_temp("marks/蓉1"))||me->query_temp("marks/洪七公"))
        {
            message_vision("$N走进了小木屋。\n",me);
            me->move(__DIR__"woodhouse");
            message_vision("$N从屋外走了进来。\n",me);
            me->set_temp("marks/蓉",0);
            me->set_temp("marks/蓉1",0);
            return 1;
        }
        else
        {
            write("你觉得贸然进去有些不妥，还是先问问傻姑和程英再说吧。\n");
        }
    }
    return 1;
}

