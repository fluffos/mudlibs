#include <ansi.h>
inherit ROOM;

void create()
{
     set("short", GRN"树林"NOR);
     set("long", @LONG
这里大树参天，地上铺满枯干的树叶，树枝间藤条网布，令你举步
维艰。几道阳光从树枝缝里射进来，照在你的脸上。
LONG);
        set("no_sleep_room", 1);
        set("objects", ([
        	CLASS_D("baituo") + "/ouyangfeng" : 1,
        ])); 
        set("exits", ([
         	"out" : __DIR__"shulin2",
        ]));         
        setup();
}        

void init()
{
	if(this_player() && userp(this_player()) )
	{
	write("\n你急步抢进大树林，阳光下只见一美貌少女与一个身材魁梧的人盘\n"
	"旋来去，斗得正急。那男人武功高强，在他掌力笼罩之下，少女虽然身\n"
	"法轻盈，也只是勉力支撑而已。\n\n"NOR); 
        message_vision(HIY"\n$N急忙窜出，已纵到二人中间，当即伸双手十指往左右轻轻一拂，把他们远远分开。\n"NOR, this_player());
        write(HIY"那少女呆了一呆，接着转身奔出树林几个起落就不见了。\n"NOR);            
        }
}

int valid_leave(object me, string dir)
{
        if (objectp(present("ouyang feng", environment(me))) && dir == "out")
                return notify_fail("欧阳锋走过来对你摇摇头，示意你先不要走。\n");
        return ::valid_leave(me, dir);
}