// ÌúÑªÃËÁôÑÔ°å
inherit BULLETIN_BOARD;
void create()
{
        set_name("ÌúÑªÃËÁôÑÔ°å", ({ "board" }) );
        set("location", "/d/txm/guangchang");
        set("board_id", "txmboard");
        set("no_get",1);
        set("long", "ÕâÊÇÌúÑªÃË°ïÖÚµÄÁôÑÔ±¡¡£\n" );
        setup();
        set("unit","¿é");
        set("capacity", 230);
        replace_program(BULLETIN_BOARD);
}

