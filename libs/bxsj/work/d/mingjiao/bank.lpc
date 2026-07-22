// Room: bank.c
// Looklove y2k/4/09
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIR"勒马斋"NOR);
        set("long", @LONG
绿洲边上的一家钱庄，室内收拾的很干净，仿佛都能感觉到外面绿洲新鲜
的气息，钱庄的主人似乎来自中原，很有品位的将这里的每个角落都布置的井
井有条。附近的人们都到这里来找他兑换钱庄通行全国的银票。有的还喜欢停
下来，和老板聊聊天。
LONG
        );

        set("exits", ([
                "east" : __DIR__"shejing",
        ]));

        set("objects", ([
                __DIR__"npc/banker" : 1,
          
        ]));
 
        setup();
}

