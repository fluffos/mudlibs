// guard.c

#include <ansi.h>

inherit NPC;
int do_catch(object ob);

void create()
{
	set_name("带刀警察",({"xunbu"}));

	set("nickname","治安警备");
	set("title","京都");
	set("gender", "男性" );
	set("age",25);
	set("long",
	"日本政府的带刀警卫队。你最好还是不要招惹他。\n"
	);
	set("pursuer",1);
	set("attitude", "heroism");
	setup();
        carry_object(__DIR__"obj/wushidao")->wield();
}

