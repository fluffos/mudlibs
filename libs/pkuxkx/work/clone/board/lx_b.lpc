 // /clone/board/center_b.c

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
set_name(YEL "凌霄城" NOR + CYN "留言板" NOR, ({"board"}) );
set("location","/d/lingxiao/dating");
   set("board_id","lx_b");
set("long", HIW"凌霄城的留言板，雪山弟子可以在此发表看法。\n"NOR);

        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}
