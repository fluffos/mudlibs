// Room: /d/emei/lingyunti.c 峨嵋派 凌云梯

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "凌云梯" NOR);
	set("long", @LONG
这是凌云梯，最早是一位叫阿婆多的外国和尚在此缚木架石，以渡行人，
又叫「胡僧梯」。路边有梅子坡，可见满坡青梅如豆，于疏枝密叶中逗引行人，
甚有「望梅止渴」之功用。此梯北通洗象池，南至雷洞坪。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([
		"northdown" : __DIR__"xixiangchi",
		"southup" : __DIR__"leidongping",
	]));

	set("valid_startroom",1);

	setup();

}
int valid_leave(object me, string dir)
{
 if (dir == "southup" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge",(int)me->query("dex")/5);
      me->receive_damage("jingli",  (int)me->query("dex"));
      return 1; }     return ::valid_leave(me, dir);

} 