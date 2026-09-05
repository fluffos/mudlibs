// Room: /d/emei/shifang.c 峨嵋派 石坊

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石坊");
set("outdoors","emei");
        set("long",
"这座石坊据传是上古留传下来的，石坊上横书"GRN"“震旦第一”"NOR"四\n"
"个字，字虽不大，却很有气势，使人不由为之一凛，此处山势虽\n"
"陡，却使人意兴盎然，再往上走就是玉女池了。\n"
        );

        set("exits", ([
		"northup" : __DIR__"yunvchi",
		"southdown" : __DIR__"jietuo",
               ]));

        setup();
        replace_program(ROOM);
}
