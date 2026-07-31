//xiangfang2.c 卧室

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIM"睡房"NOR);
        set("long", @LONG
蝴蝶粉贝双灯，静静地燃着，沁着淡淡一片粉红光色，宽敞的睡房，布置
得可真雅致，尤其是临窗处的一溜菊花盆景，衬着轻轻挽起，薄如蝉翼的纱幔，
整个卧室呈现出一派高洁清雅。。
LONG
        );        	

        set("exits", ([
               "west" : __DIR__"xiangfang1",               
        ]));      
	set("no_fight",1);
        set("objects", ([
        ]));

        setup();
}
