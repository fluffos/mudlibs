// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("Íõ·½Æ½", ({ "wang fangping", "wang", "fangping" }));

set("long","Íõ·½Æ½±¾ÊÇÉ½ÖĞµÀÊ¿£¬ºóÔÚ·á¶¼É½Í¬Òõ³¤ÉúÍ¬ĞŞÁ¶³ÉÏÉ£¬Óù·â(¡¸¹íÍõ¡¹¡£\n");
        set("attitude", "peaceful");
	set("per", 30);
	set("str", 25);
	set("int", 25);
        set("age", 30);
	set("title", "ÂÖ»ØË¾Ö÷");
	set("nickname", "¹íÍõ");
        set("combat_exp", 850000);
  set("daoxing", 600000);

        set("max_gin", 1400);
        set("max_kee", 1400);
        set("max_sen", 1400);
	set("class", "youling");
	set("force", 2500);
	set("max_force", 1500);
	set("force_factor", 100);
	set("max_mana", 1500);
	set("mana", 2500);
	set("mana_factor", 100);




        set("nkgain", 400);

	set_temp("apply/dodge", 50);
	set_temp("apply/armor", 50);


create_family("ÑÖÂŞµØ¸®", 2, "ÄãºÃ");

        setup();
	carry_object("/d/obj/weapon/stick/wuchangbang")->wield();
	carry_object("/d/obj/cloth/taijicloth")->wear();
}


void attempt_apprentice()
{
	object me;
	me = this_player();
        command("grin");

        command("say ºÜºÃ£¬" + RANK_D->query_respect(me) +
"¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓĞ³É¡£\n");
       command("recruit " + me->query("id") );
	me->set("class", "youling");
        return;
}
/*
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
		ob->set("title", "µØ¸®ÕĞ»êË¾Òõ±ø");
}

*/
ÿ
