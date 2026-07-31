// /u/beyond/mr/yanziwu.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",WHT"燕子坞"NOR);
         set ("long",@long
燕子坞是幕容氏世居之地, 幕容氏乃夕日大燕国的后裔, 后来日见式微, 
但其弟子却一心一意想光复大燕。其武功见长于以彼之道, 还施彼身, 端的
十分厉害。
long);
         set("exits",([
"north" : __DIR__"midaocao",
"south" : __DIR__"xiaojing1-2",
"west" : __DIR__"houyuan1",
             "east" : __DIR__"wuchang",
]));
set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
set("objects",([
	"quest/menpaijob/mr/murong-fu" :1,
	"/d/biwu/champion_mr":1,
	"/d/mr/npc/puren":2,
	"/d/mr/npc/binu":2,
	"/quest/menpai/mr/shi":1,
]));
"/clone/board/murong_b.c"->foo();
         setup();
         replace_program(ROOM);
}
