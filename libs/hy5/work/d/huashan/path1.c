// path1.c

inherit ROOM;

void create()
{
        set("short", "华山脚下");
        set("long", @LONG
西岳华山，巍然耸立于陕西省华阴县城南。它北瞰黄河，南连秦岭，
五座山峰高低错落，各据一方，其间又有一段若断若续的山岭相连，疏密
有度，神韵天成，远远望去，状若巨朵青莲，外围诸峰如莲瓣，中间三峰
似莲蕊，因此山便因'花'得名，取名华山。又因其西临少华山，故华山又
称太华。它素有「奇峰天下第一山」之称，西面是小村。北是玉泉院。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
            "west" : "/d/village/eexit",
            "north" : __DIR__"yuquan",
            "southeast" : __DIR__"shaluo",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
