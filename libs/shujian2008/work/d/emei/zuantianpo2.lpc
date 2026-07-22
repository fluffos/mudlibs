// Room: /d/emei/zuantianpo2.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIY "钻天坡" NOR);
        set("long", @LONG
莲花石与洗象池之间，道路陡绝，石栈若齿，直上蓝天，石蹬达一千三百
多级，是在陡峭山壁上开凿出来的坡道。人行其上，前后顶踵相接，一如登天。
这段路叫「鹁鸽钻天」，这段陡坡也因此而叫「钻天坡」。这里西上坡顶便到
洗象池，东下可达莲花石。
LONG
        );
        set("outdoors", "峨眉山");
        set("exits", ([ 
          	"eastdown" : __DIR__"zuantianpo",
          	"westup" : __DIR__"xixiangchi",
	]));
	
	set("lingwu", ([
		"skill" : "dodge",
		"low_limit" : 100,
		"up_limit" : 200,
		"lw_msg": CYN"$N发现这里上接洗象池，下望莲花石，坡陡路险，最能考验一个武人的轻功。\n"+
			  "于是心里默想着$s步法，开始领悟$b方面的武学问题。\n"NOR,
	]));
        set("no_clean_up", 0);

        setup();
}
int valid_leave(object me, string dir)
{
 	if (dir == "westup" && (int)me->query_skill("dodge", 1) < 101 ) {
      		me->improve_skill("dodge",(int)me->query("dex"));
      		me->receive_damage("jingli",  (int)me->query("dex"));
      		return 1; 
      	}     
      	return ::valid_leave(me, dir);
} 
