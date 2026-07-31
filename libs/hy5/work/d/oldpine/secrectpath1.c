 // Room: /d/oldpine/secrectpath1.c
inherit ROOM; 
void create()
{
        set("short", "秘密通道");
        set("long", @LONG
你现在正站在一个岩石通道之中，从南边隐隐传来哗哗的水声，岩
壁上生著厚厚的青苔，一股恶臭从北边传来，像是什麽野兽，也许你该
回头出去了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"passage",
]));
        set("no_clean_up", 0); 
        set("coor/x",540);
        set("coor/y",2380);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}     
