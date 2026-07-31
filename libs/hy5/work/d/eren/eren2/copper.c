#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", YEL"铜屋"NOR);
        set("long", @LONG
各式各样的兵器，还有各式各样的暗器。金铁之气，砭骨生寒，森森
的寒光，将四壁都照成了铁青色。枪，最长的长达丈八，最短的才不过叁
尺，剑，最大的宛如木桨，最小的竟宛如筷子。长枪短剑，整齐地排列着，
它们虽然没有生命，却又似蕴含着杀机，令人胆寒的杀机！
    普天之下，所有的凶杀之器，只怕尽都在这屋里。
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                        ]));
        set("objects", ([
                __DIR__"npc/maskman_c" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}     
