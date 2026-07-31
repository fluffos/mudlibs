//dangpu.c
//hydra 980501

inherit ROOM;

void create()
{
        set("short","杨记当铺");
        set("long", @LONG
门口一面大旗，在风中飘扬，上面一个大大的“杨”字。门口正上方的一块
匾上写着四个烫金大字--“杨记当铺”。由于当铺建在高昌最繁华的西街上，这
里的商人们有时候急着回家，就把东西都卖到这里，所以这里的生意非常兴隆。
店主人是个维吾尔人，很精明地在这里开了一家当铺，兼做钱庄生意。
LONG
        );
        set("exits", ([ 
                "north"         :       __DIR__ "xijie2",
                ])
        );
//      replace_program(ROOM);
        setup();
}

