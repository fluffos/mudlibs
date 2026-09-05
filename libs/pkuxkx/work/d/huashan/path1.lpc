// path1.c

#include <ansi.h>

inherit ROOM;

string shi_bei();

void create()
{
        set("short", "华山脚下");
        set("long", 
"这里是华山脚下，南面就是素有「奇峰天下第一山」的西岳华山，华
山由于远望宛如一朵白莲花，因而得名（古时，「华」与「花」通）。西
面有个小村庄，北边有几间房屋。路边有块" + RED "石碑(shibei)。"NOR +"\n"
        );
        set("exits", ([ /* sizeof() == 3 */
                "west" : "/d/village/eexit",
                "north" : __DIR__"yuquan",
                "southeast" : __DIR__"shaluo",
				"northeast" : __DIR__"machehang",
        ]));

        set("item_desc", ([
                "shibei" : (: shi_bei :),
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );
        set("room","room18");
        setup();
}
 
string shi_bei()
{
        return YEL "        西\n\n        岳\n\n        华\n\n        山\n" NOR;
}

