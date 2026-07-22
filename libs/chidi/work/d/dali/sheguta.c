 // Room: /d/dali/npc/mazumiao.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月21日，北京时间：17时46分28秒。

inherit ROOM;

void create()
{
        set("short", "蛇骨塔");
        set("long", @LONG
蛇骨塔位于大理城内，建在点苍山斜阳峰东坡。相传洱海有妖蛇
名“薄劫”，其尾塞海口，洪水泛滥，有勇士段赤城只身入洱海与妖
蛇同归于尽。后人建塔以震水势，用蛇骨灰塔，水势自息。
    这是一座密椽式方形砖塔。
LONG
        );
    set("no_fight", "1");
    set("no_steal", "1");
    set("no_sleep_room", "1");
        set("valid_startroom","1");
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xbdajie2",
]));

        set("objects", ([ /* sizeof() == 2 */
        __DIR__"npc/youke" : 2,
]));

        setup();
}
void init()
{
    if (!wizardp(this_user()))
    add_action("discmds",({"duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender"}));
}
int discmds()
{
    tell_object(this_player(),"大胆！神圣之地岂容你胡来？！\n");
    return 1;
}
