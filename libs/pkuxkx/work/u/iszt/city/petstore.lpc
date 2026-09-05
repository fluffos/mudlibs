// Room: /city/petstore.c
// by pretty

inherit ROOM;

void create()
{
        set("short", "宠物店");
        set("long", @LONG
    这是一家宠物店，空气中混杂着几种莫名其妙的味道，想必是从老板身后
的好多笼子里散发出来的。老板不是本地人，谁也不知道他从哪里来。他每月出去
采购一次小动物，如果你喜欢小动物的话，到这里来准没错。墙上挂着一个宠物价
格表(sign)，也许你该看看。
LONG);
        set("item_desc", ([
                "sign" : @TEXT
本店提供各种小动物供你选择，现在的种类有猪、狗、猫、鼠、鹰，现定统
一价格为 100 两黄金，如果你真的喜欢的话，可以自己订(ding)一个。
命令格式 例如 ding pig $RED$ 飞天猪 arthur 
TEXT
        ]));

        set("objects", ([
                "/clone/npc/seller" : 1,
        ]));

        set("exits", ([
                "north" : __DIR__"dongdajie3",
        ]));

        setup();
        replace_program(ROOM);
}