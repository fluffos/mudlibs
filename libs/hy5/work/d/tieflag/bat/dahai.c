#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "大海");
        set("long",@LONG
你正处在茫茫大海之中。你极目远望，只见海天一线，周围连个黑点都没有。
耳边只有海浪（wave）的拍打声。
LONG
        );
        set("coor/x",3000);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
void init()
{
        add_action("do_look","look");
}
int do_look(string arg)
{
 object me,room;
 if(!arg || arg != "wave") return 0;
 me = this_player();
 if(!random(10)) {
  tell_object(me, BLU "突然间，你的船触礁了！一个大浪打来，你被抛入空中．．．\n"NOR);
  room = load_object(__DIR__"anbian");
  me->move(room); 
  return 1;
 } else {
 tell_object(me, BLU "海浪就象是一头头恶狼，唑咬着你的船！\n"NOR);
 return 1;
 }
}       
