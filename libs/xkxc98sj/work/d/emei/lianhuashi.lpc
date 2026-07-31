// Room: /d/emei/lianhuashi.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "莲花石" NOR);
	set("long", @LONG
这是莲花石。此处岩石纹理纵横，形似莲花，颜如芙蓉，仿佛萼瓣层叠，
细蕊欲绽。上有一庵，叫「莲花社」。由此往西上直达洗象池，东下左通华严
顶，右通九老洞。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([ 
	  "eastdown" : __DIR__"huayanding",
	  "westup" : __DIR__"zuantianpo",
	  "southeast" : __DIR__"jiulaodong",
]));
        set("objects",([
		CLASS_D("emei") + "/zhao-lingzhu" : 1,
		CLASS_D("emei") + "/su-mengqing" : 1,
          ]));
	setup();
}
int valid_leave(object me, string dir)
{
 if (dir == "westup" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge",(int)me->query("dex"));
      me->receive_damage("jingli",  (int)me->query("dex"));
      return 1; }     return ::valid_leave(me, dir);

} 
