// /clone/board/comm_b.c
inherit BULLETIN_BOARD;
void create()
{
        set_name("玩家交流留言板", ({ "board", "nitan board", }) );
        set("location", "/d/city/chatroom");
        set("board_id", "comm_b");
        set("no_get",1);
        set("long", "这是一块供玩家交流心得的留言板。\n");
        setup();
        set("unit","块");
        set("capacity", 218);
        replace_program(BULLETIN_BOARD);
}

