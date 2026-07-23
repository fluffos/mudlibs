//xiuxishi.c 休息室
#define __BWDH__ "/cmds/leitai/bwdh/"

#include <ansi.h>
#include <room.h>

inherit ROOM;
#include "pro.h"

void create()
{
        set("short",HIR"休息室"NOR);
        set("long", @LONG
这是试剑山庄的休息室，平日这里一片呼喝之声，最重修习基本，庄主对
弟子管教极为严格，也正因为如此，门下弟子武功大都不弱，而且品行端正，
武林之中莫不敬仰，此时休息室上却空无一人，想必有大事发生。在一角有一
个牌子(sign)。
LONG
        );
        
        set("no_fight",1);
        set("item_desc",([
        	"sign" : @LONG
        	在本休息室，你可以干以下几件事情：
        	
        	一，取装备(na xxxx)，具体请look jia。
        	二，和另一组玩家对话(cy xxxx)。
        	
        	如果您已经准备就绪，请输入(ok)，以便开始比赛。\n",
LONG
        ]));
        set("objects", ([ /* sizeof() == 1 */
        	__DIR__"obj/jia" : 1,
        ]));
        setup();
}

void init()
{
	add_action("do_ok",({"done","ok"}));
	add_action("do_chuanyin",({"chuanyin","cy"}));
}
