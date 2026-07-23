// 比武擂台
// by snowman@SJ

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "风云门");
        set("long", "这里是"+MUD_NAME+"里的比武擂台，这里据说曾经有很多对武林人士在这里比试
武艺。擂台下面的人声鼎沸，擂台之上有一面大兵器架，想在这里比武的人
可以从兵器架上拿取需要的武器和护具。在擂台的中央放着一块大牌子(paizi)
，在擂台的一角放着一块巫师须知(sign)。\n");
        set("no_death", 1);
        set("no_get_from", 1); 
        set("no_sleep_room", 1);
        set("dest_room", "/d/wizard/lt1");
        set("objects", ([    
             __DIR__"npc_leitai" : 1,
        ]));
        set("item_desc", ([             
        	"sign" : "\n比武之人必须由仙人以上的巫师用( login )的办法放进入擂台，或是程序
自动送入。在双方都准备好( ok )了以后开始比武，或由巫师下比武命令( biwu )。
巫师可以让玩家退出( tui )擂台，及开放擂台信息( xinxi )。\n\n",       
             "paizi" : "\n比武之人可以从物品架上拿取物品，准备好了后请打 OK 。
如果要放弃比赛，请打 LEAVE 。\n\n",
        ]));
        setup(); 

}
#include "leitai.h";
