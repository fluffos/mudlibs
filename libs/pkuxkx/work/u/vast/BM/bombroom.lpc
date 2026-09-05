inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "Vast的炸弹人游戏");
	set("long", @LONG本房间为炸弹人游戏的测试房间入口，游戏规则如下：
	
	1. give arbiter 10 gold，然后ask arbiter about 玩游戏，即可参与报名；
	2. 报名后ask arbiter about 玩游戏, 可以看已经报名的玩家;
	3. 报名人数满4个后，自动开始游戏；
	4. 每行动一步可以看到当前幸存的玩家数量及地图
	   （高亮绿色为玩家当前所在房间，红色为有炸弹的房间）
	5. 用setbomb命令放置炸弹，炸弹10秒后爆炸；
	6. 已经放置炸弹的房间无法进入；
	7. 每走一步会有短暂的busy；
	8. 炸弹爆炸会引起隔壁房间的连锁反应；
	9. 最后的幸存者即为胜利者；
	10. 胜利者 ask arbiter about 奖励，得到奖励。
 
	祝大家玩得开心！有bug和建议请到论坛报告！
					Vast
					2009.02
	
LONG);

	set("no_fight", 1);
	
	set("exits", ([
	"west": "/d/wizard/biwuchang",
		 ])
		 );
  set("objects",([
    __DIR__"arbiter" : 1,
        ]));
  set("room_location", "/d/city/");
	
	setup();
}

void init()
{
        add_action("do_none", "perform");
        add_action("do_none", "yun");
        add_action("do_none", "study");
        add_action("do_none", "du");
        add_action("do_none", "lian");
        add_action("do_none", "practice");
        add_action("do_none", "dazuo");
        add_action("do_none", "exercise");
        add_action("do_none", "tuna");
        add_action("do_none", "respirate");
        add_action("do_none", "read");
        add_action("do_none", "dz");
        add_action("do_none", "hitall");
        add_action("do_none", "killall");
        add_action("do_none", "kill");
        add_action("do_none", "exert");
        add_action("do_none", "attack");
        add_action("do_none", "qiecuo");
        add_action("do_none", "xiulian");
}

int do_none()
{
		write("什么？\n");
    return 1;
}