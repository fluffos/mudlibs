// cave3.c 隧洞
inherit ROOM;
#include <room.h>
void create()
{
          set("short","隧洞");
          set("long",@LONG
你爬行了一阵，隧洞渐宽，已可直立行走，行了良久，始终不到尽头，地
下却越来越平。突然猛听得左首传来一阵大笑之声，这几下明明是笑声，听来
却竟与号哭一般，语调异常的凄凉悲切。
LONG
);

          set("exits",([
             "west": __DIR__"shiyao",
          ]));
           
          setup();
          replace_program(ROOM);
}
