#include <ansi.h>
inherit ROOM;


void create()
{
        set("short", HIG"泪人儿的工作室"NOR);
        set("long", @LONG
一间非常宽敞明亮的房子,东西不多,十分整洁.原木花纹的电脑桌上摆着
一台电脑(dian nao)，旁边放着CD架.微腥的海风轻拂着淡绿的窗纱轻轻
飘动(window),窗前小几上的鲜花也随之起舞.

LONG
        );

        set("exits", ([
              
                "out"  : "/d/wizard/guest_room"
        ]));

     
       set("item_desc",([
                    "dian nao" : "这是tear的专用电脑，一般人不能用的！\n",
                    "windown" : "这是一善窗子，你可以通过窗子看到外面的景物！\n",
                    ]));

        setup();
}          

