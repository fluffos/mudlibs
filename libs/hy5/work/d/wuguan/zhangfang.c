#include <room.h>

inherit ROOM;

void create()
{
        set("short", "帐房");
        set("long", @LONG
这里是武馆内的一个帐房，室内一个帐房先生在这里认真地做着帐。
几名新弟子正围着帐房先生，看来是想把积攒下来的钱物存在这里。墙
上挂有一个牌子(paizi)。
LONG);
        set("exits", ([
                "north" : __DIR__"shilu-1",
        ]));
        set("objects", ([
                __DIR__"npc/fan" : 1,
        ]) );
        set("item_desc", ([ 
            "paizi" : "牌子上写道：
武馆帐房。
        存钱(cun)，
        取钱(qu)，
        查帐(check)，
        兑换(duihuan)。
        \n"
        ]));    
        setup();
        replace_program(ROOM);
}


