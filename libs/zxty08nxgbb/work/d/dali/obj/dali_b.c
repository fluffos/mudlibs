// /clone/board/baituo_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"雕龙石柱"NOR, ({ "board" }) );
        set("location", "/u/hades/d/dali/guangchang");
        set("board_id", "dali_b");
        set("long", @LONG
这是一条数丈高的石柱。数条浮雕巨盘旋闹柱，龙首
低颔，汩汩清水从龙嘴中涌出，远远望去宏伟壮观。
LONG
        );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}

