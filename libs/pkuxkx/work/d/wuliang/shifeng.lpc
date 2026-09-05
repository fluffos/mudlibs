// by paladin

inherit ROOM;

void create()
{
set("short","洞中小道");
        set("long", @LONG
一条石级斜向上, 通向一个仅可容身的洞穴, 隐隐听到轰隆轰隆的水声. 
LONG
        );
set("outdoors", "dali");
       set("no_sleep_room",1);

        set("exits", ([
"north" : __DIR__"shishi",
"out" : __DIR__"jiangpan",
        ]));

// set("objects",([
//      __DIR__"npc/qingshe" : random(2),
//      __DIR__"npc/jinshe" : random(2),
//     ]));

        setup();
        replace_program(ROOM);
}
