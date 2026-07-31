
// tearoom.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
        
	set("coor",({2050,3950,0}));
	set("short", "香茗坊");
        set("long",
"你来到绮云镇西边的一家茶坊里,它的历史已不下百年,绮云镇本就是以盛产茶叶而闻名于世\n"
",因此茶楼的生意出奇的好。高高悬起的金匾(sign)让你的有一种眩晕的感觉,幸好阵阵茶香\n"
"使你清醒了许多。站在门口,你可以看到北首有一扇不太起眼的木雕门(door)。东侧的楼梯\n"
"通往楼上的雅座,不时能听到上面传来丝竹之声和阵阵笑声...\n"
);

        set("item_desc", ([
                "sign": (: look_sign :),
                "door": (: look_door, "north" :),
        ]) );

        set("exits", ([
                "south"          : __DIR__"nwroad3",
                "west"           : __DIR__"nwroad1",
                "north"          : __DIR__"tea_corridor",
                "up"             : __DIR__"tearoom2" ]) );

        set("objects", ([
                __DIR__"npc/tea_waiter" : 1,

 ]) );


       set("valid_startroom", 1);

        setup();

}

string look_sign()
{
        return "匾上写着: 香茗坊 ， 旁边一排小字: 御赐亲笔。 \n";
}


