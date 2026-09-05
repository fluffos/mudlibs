// xiaotou.c
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
void consider();
void create()
{
        seteuid(getuid());
        set_name("小偷", ({ "xiao tou","xiao","tou"}) );
	set("title",MAG"神偷"NOR);
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个街头小偷。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("con", 25);
        set("int", 20);
        set("dex", 20);
        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 100);
        set("max_neili", 100);
        set("jiali", 10);
        set("shen_type", 0);
        set("thief", 1);
        set("combat_exp",2300);
        set_skill("force", 30);
    	set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("stealing", 100);
        set_skill("unarmed", 30);
	set("chat_chance_combat",20);
	set("chat_chance",3);
        set("shen_type",-1);
set("score",200);
setup();
	set("chat_msg",({(:random_move:)}));
        add_money("silver", 10);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("stealing");
                call_out("stealing", 1, ob);
        }
}
void stealing(object ob)
{
        if( !ob || environment(ob) != environment()
                || (int)ob->query_skill("taoism", 1) > 30
                || ob->query_int() > 30
          ) return;
        switch( random(3) ) {
                case 0:
                       command("steal coin from " + ob->query("id"));
                       break;
                case 1:
                       command("steal silver from " + ob->query("id"));
                       break;
                case 2:
                       command("steal gold from " + ob->query("id"));
                       break;
              
              }
}

