// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "椎捣狱");
        set("long", @LONG
迎面就是几个巨人，手持大椎，几个巨大的类似捣药碗似的东西里面
似乎有惨叫之声传来，定睛细看，原来是囚犯被放进去，由巨人捣为
肉泥，看了这许多惨状，你镇定了许多。“善恶到头终须报”，早知
今日，何必当初啊。定了定神，你毅然地走向车崩狱。
LONG
        );
        set("exits", ([
		"up" : __DIR__"moai",
		"down" : __DIR__"chebeng",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-180);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
