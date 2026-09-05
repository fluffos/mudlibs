 // /clone/board/center_b.c

#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
set_name(YEL "侠客行" NOR + CYN "江湖风云录" NOR, ({"board"}) );
set("location","/d/luoyang/wangxinglou1");
set("loc2","/u/jason/workroom");
   set("board_id","ct_b");
set("long", HIW"行走江湖，靠的是朋友. 此留言板愿能提供最新的信息。\n巫师友情提醒：行走江湖请时刻输入"+HIR"news"+HIW"命令察看最新消息！\n"NOR);

        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}

