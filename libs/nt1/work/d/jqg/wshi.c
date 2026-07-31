// wshi.c By River 98/08/29
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          set("short",HIC"卧室"NOR);
          set("long", @LONG
举步入内，一瞥眼间，只见屋中陈设简陋，但洁净异常，堂上只一桌一几，
此外便无别物，桌几放置竟与古墓石室中的桌椅一模一样。只是古墓中用具大
都石制，此处的却由粗木搭成。但见室右有榻。
LONG        );

          set("exits", ([
               "south" : __DIR__"zhongtang",
          ]));         
          set("sleep_room", 1);
          set("no_fight", 1);
          
          setup();
}
