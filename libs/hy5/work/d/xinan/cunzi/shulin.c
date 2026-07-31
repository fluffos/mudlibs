//Writen by lnwm
//shulin.c

inherit ROOM;

void create()
{
    set("short", "小树林");
    set("long", @LONG
村子的尽头是一个小树林，树林十分茂密，你瞪大了眼睛向里看去似
乎没有道路。树林的后面就是苍翠挺拔的青城山东坡。你的身后就是这一
带山区常见的小村落。
LONG
        );
    set("outdoors","lnwm");
    set("exits", ([
        "south"     :       __DIR__ "lroad5",
    ]));
    
    setup();
    replace_program(ROOM);
}


