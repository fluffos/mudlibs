// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("°×ÎŞ³£", ({ "bai wuchang","wuchang", "gargoyle" }));
        set("long","Ò»¸ö°×ÒÂ°×¾»ÃæÆ¤µÄÊ¹Õß£¬ËÀ°×µÄÁ³ÉÏ¿´²»³öÈÎºÎÏ²Å­°§ÀÖ¡£\n");
        set("attitude", "peaceful");
	set("per", 10);
	set("str", 25);
	set("int", 25);
        set("age", 30);
	set("title", "ÕĞ»êË¾Ö÷");
        set("combat_exp", 120000);
  set("daoxing", 200000);

        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);
	set("class", "youling");
	set("force", 1500);
	set("max_force", 800);
	set("force_factor", 50);
	set("max_mana", 600);
	set("mana", 1000);
	set("mana_factor", 40);

create_family("ÑÖÂŞµØ¸®", 3, "ÄãºÃ");

        setup();
	carry_object("/d/obj/cloth/bai")->wear();
}


void attempt_apprentice()
{
	object me;
	me = this_player();
        command("grin");

        command("say ºÜºÃ£¬" + RANK_D->query_respect(me) +
"¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓĞ³É¡£\n");
       command("recruit " + me->query("id") );
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
//		ob->set("title", "µØ¸®ÕĞ»êË¾Òõ±ø");
}

ÿ
