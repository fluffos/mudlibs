inherit ROOM;
#include <ansi.h>

void create ()
{
    set ("short", "濯凤池");
  set ("long", @LONG
池面不过丈许方圆，以石为底，小巧玲珑，终年热气蒸腾,乃是灵鹫宫天
然之宝，灵鹫宫底姑娘们，常年累月就在这里洗澡(wash)^_^
LONG);

  set("exits", ([ /* sizeof() == 1 */
 "north" : __DIR__"xiuxishi",
]));

  setup();
}

void init()
{
  add_action("do_wash", "wash");
}
int do_wash()
{
int time=2+random(3);
object me;
  me=this_player();
if (me->query("gender")!="女性") 
return notify_fail(HIR"男的也想在这里洗？没有搞错吧？\n"NOR);
if( me->is_busy() )
return notify_fail(HIY"你正在洗着那!Dear MM\n"NOR);
 me->start_busy(time);
call_out("over",time,me);
return notify_fail(HIY"你轻轻的解下衣服，然后.......\n"NOR);
}
void over(object me)
{
me=this_player();
//   me->set("name",HIC"树大根深"NOR);
write (HIY"你洗完之后,浑身舒畅!精神倍增!\n"NOR);
//.............满血，满气??
}
