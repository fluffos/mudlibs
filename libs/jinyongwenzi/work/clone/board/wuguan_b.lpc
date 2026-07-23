// /clone/board/wiz_b.c

inherit BULLETIN_BOARD;

void create()
{
      set_name("武馆花名册", ({ "board" }) );
      set("location", "/d/wuguan/dayuan");
      set("board_id", "wuguan_b");
      set("long", "这是一个襄阳武馆内供人们留言用的花名册。\n" );
	setup();
	set("capacity", 60);
}
int do_post(string arg)
{
       object me;
       me = this_player();
       if (me->query("combat_exp",1) < 200)
               return notify_fail("你现在的江湖阅历不够在这里留言。\n");

       return ::do_post(arg);
}
