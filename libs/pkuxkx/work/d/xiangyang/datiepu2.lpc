#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",RED"打铁铺(售盔甲)"NOR);
        set("long",
  HIC"这是一家打铁铺,屋子中心摆着一个火炉,一个中年铁匠
在满头大汗地打铁.这位张铁匠是远近闻名的好把式,他的手艺
是祖传的,以打盔甲护具见长.\n"NOR
        );
        set("exits", ([
                "south" : __DIR__"xywest1",
        ]));
      set("objects", ([
                __DIR__"npc/zhang": 1,
        ]));
        setup();
        replace_program(ROOM);
}
