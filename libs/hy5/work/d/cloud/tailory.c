
// tailory.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2000,3880,0}));
	set("short", "天凤布庄");
	set("long",
"你现在正站在天凤布庄里，这里因为制作的衣服天下无双而被称 第一布庄 这里人来人往，\n"
"生意十分兴隆。靠近门口的墙壁上挂着(sign)。\n"
);
        set("exits", ([
                "north"          : __DIR__"nwroad2" ]) );

        set("objects", ([
                __DIR__"npc/tailor" : 1,
 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：定制衣服。\n须先申请彩凤卡(apply card).\n";
}

