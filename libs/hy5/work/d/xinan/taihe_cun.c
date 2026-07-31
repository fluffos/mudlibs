#include <room.h>
inherit ROOM;


void create()
{
    set("short", "太和村");
    set("long", @LONG
太和村是南诏国建都的故址。大唐年间，南诏统一滇贵高原，偏安一隅长达
二百年。后来段氏建立大理王国，立都于点苍山下的大理城，这里的城池便渐渐
荒废了。现在只有一个中等规模的村寨，几十幢竹屋散落在芭蕉树间。路边草丛
里有一块丈余高的碑(tie zhu)，通体黝黑，似乎是铁铸成。
    北面是洱海。
LONG
    );
    set("exits", ([
        "southwest"     : __DIR__"bazi1",
        "north"         : __DIR__"erhai",
        "east"          : __DIR__"chayuan",
    ]));
    set("item_desc", ([
        "tie zhu":  @LONG
这是一块丈余高的铸铁碑，是南诏国王阁罗凤于天宝十年所立，碑上刻着：
        朕家世世臣奉大唐，常存交好之意，不料反遭奸臣诬告，
    祸至交兵，朕不得已而转附于吐蕃。然此自非吾原意也。他
    日若得容许复归于唐，当指此碑与来使观之。
        ......
下面还有许多字。
LONG
    ]));
    set("outdoors","xinan");
    set("objects",([
        __DIR__"npc/cunmin" : 1,
        __DIR__"npc/popi"   : 1,
    ]) );
    setup();
}
