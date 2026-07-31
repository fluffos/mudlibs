
// Room: /d/snow/tao.c

inherit ROOM;

void create()
{
        set("short", "茅山道观");
        set("long",
"这是一间阴森的道观，在你面前的神桌上供奉著三清的塑像,一位貌似仙人的道士正在练功\n"
"。门是朝北开的。\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"eroad3",
]));

        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}
