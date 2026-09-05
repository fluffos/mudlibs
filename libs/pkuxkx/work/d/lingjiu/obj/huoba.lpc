//huoba.c   火把，用来在黑暗的地方照明
inherit ITEM;
int do_dian(string);
void create()
{
     set_name("火把", ({ "huoba" }));
     set_weight(1000);
     set("long", "这是一支用于照明的火把，到了黑暗的地方可以用火折点燃(dian)它。\n");
          set("unit", "支");
          set("value", 200);
}

 void init()
{
	add_action("do_dian","dian");
}

int do_dian(string arg)
{
        object ob = this_object();
        object me=this_player();
        if( !arg || arg!="huoba" ) return notify_fail("你要点燃什么？\n");
        if( arg=="huoba" ) {
             if (!present("fire", me))  {write("你没有带着火折,怎么点燃火把？");return 0;}
             write("你擦著火折，点燃了火把。\n");
             me->set_temp("use_fire", 1);
	    new(__DIR__"huoba2")->move(me);
		destruct(ob);
             return 1;
       }
}
