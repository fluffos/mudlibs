// gate 刀府大门

#include <ansi.h>

inherit ROOM;

void init();

void create() {
    set("short", "刀府大门");
    set("long",
@TEXT  这里是一座朱门白墙的大庄院。庄院大门上所悬匾额写着“刀府”二字，书
法银钩铁画，颇具英气。然而抬眼望去，整座庄院均被一片茂密的竹林所包围。
除大门口外几许空地，只余一条青石小道通往庄外，却又显得幽静非常。
TEXT);

    set("outdoors", "daofu");

    set("exits", ([
        "enter" : __DIR__"qianyuan",
    ]));

    setup();
}
