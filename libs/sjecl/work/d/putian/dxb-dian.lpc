// Room: /d/putian/dxb-dian.c
// Lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"大雄宝殿"NOR);
        set("long", @LONG
这里是大雄宝殿。正中间供奉着如来三宝的金身塑像，左右各是文殊、普
贤诸位菩萨。大殿四周的墙壁上画有许多佛经典故的壁画，构图宏伟，色彩绚
丽。殿中一年四季香火不断，一群僧人正自焚香诵经。
LONG
        );

        set("exits", ([
                "northdown" : __DIR__"guangchang",
                "southdown" : __DIR__"qiandian",
        ]));
        set("objects",([
                __DIR__"npc/shami" : 2,
                CLASS_D("putian") + "/da-ku": 1,
        ]));
        setup();
}
