inherit ROOM;
void create()
{
        set("short", "雪峰脚下");
        set("long", @LONG
这里是襄阳城西的荒野,再往西看,是一坐高耸如云的山峰,看不到顶,更找不到上去的路.
只看到半山腰上雾气蒙蒙,分不清那是云哪是雾.两只巨大的白雕在云端盘旋.
LONG
        );
                set("exits", ([
                "east" : "/d/xiangyang/westr4",
                "west"  : "/d/migong/migong1/entry",
                "up"   : __DIR__"xuefeng1",

            ]));

        setup();
}

  int valid_leave(object me, string dir)
{

        if (dir == "up")
        {

                 if(!me->query_temp("上峰"))

                {
                  return notify_fail("你抬头向上一望,我的妈呀,这么高怎么爬呀?该找个本地人问问.");
                }

//if (me->query_skill("xianglong-zhang", 1) >=135)
                 if(me->query_skill("dodge", 1) <80)

                {
                  return notify_fail("你笨手笨脚地抓住岩石的缝隙往上爬,刚爬两不,脚下一个不稳,掉了下来,摔了一个屁股墩.");
                }

        }
        return ::valid_leave(me, dir);
}
