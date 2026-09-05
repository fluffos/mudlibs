// Room: /u/cuer/emei/fhuang.c

#include <ansi.h>

inherit ROOM;

int do_tui(string);
void init();

void create()
{
	set("short", "凤凰台");
	set("long", @LONG
这里就是凤凰台了，这里的树木高大茂密，来往的人
很稀少，没有了嘈杂的人声，显得很幽静。一群白猿在大
树之间往来攀援，却有一头白猿站在一块大石头旁爪耳挠
鳃，悲鸣不已。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"bgsgate",
           ]));
	set("objects",([
             __DIR__"npc/baiyuan" : 1,
              ]));  

	setup();
}

void init()
{
  add_action("do_tui","tui");
}                             

int do_tui( string arg )
{ 
  object me = this_player();
  object ob; 
  if( !arg || (arg != "stone" && arg != "shitou") )
    return notify_fail("你要推什么？\n");
  if(!(me->query_temp("tui")) || me->query_temp("tui") == 0)
    return notify_fail("哪有你要推的东西啊？\n");
  if( me->query("max_neili") < 400 )
    return notify_fail("你推了半天，但石块一动不动。\n"); 
  me->delete_temp("tui");
  say(GRN"石块轰隆隆的滚到一边，露出一个洞穴。\n从洞里跳出一头白猿，和你旁边的白猿一起呼啸着上树了。\n");
  say("$n由于好奇就钻了进去。\n"NOR,me);
  ob = present("baiyuan", environment(me) );
  destruct(ob);
  me->move(__DIR__"cave");
  return 1; 
}
