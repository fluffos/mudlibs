//jinling  yamen.c
inherit ROOM;

void create()
{
        set("short", "衙门");
        set("long", @LONG
这里是金陵城的知府衙门。朱红的大门上钉着碗口大的铜钉，闪闪发光，
气派非凡。在门口立有两坐石狮，张牙舞爪，你不禁感到一阵心悸，还是赶
紧离开吧。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "east" : __DIR__"beijie1",

]));

        set("no_clean_up", 0);

set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}
