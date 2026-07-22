inherit BULLETIN_BOARD;

void create()
{
       set_name("江湖新闻版",({ "newsboard" }) );
       set("location", "/d/wizard/wizard_room"); 
       set("board_id", "yxwdnews_b");   
        set("long","意虽高处,身却不就。感慨万分,情又何奈?\n" );
        setup();
        set("capacity", 3000);
        replace_program(BULLETIN_BOARD);
}

