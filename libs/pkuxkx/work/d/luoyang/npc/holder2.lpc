// holder
// created by Zine 30 Sep 2010

inherit NPC;
#include <ansi.h>
#include <random_name.h>

void create()
{
	set_name(get_rndname(), ({get_rndid(), }));
    set("title", HIW"财不露白"NOR);
	set("gender", "男性" );
	set("long", "一个贼眉鼠眼的家伙。\n");
	set("str", 20);
	set("int", 20);
	set("dex", 20);
	set("kar", 20);       
	set("qi", 100);
	set("max_qi", 100);
	set("jing", 100);
	set("max_jing", 100);
	set("eff_jingli", 10);
	set("neili", 10);
	set("max_neili", 10);
	set("jiali", 200);
	set("shen_type", 1);
    set("random_npc",1);
	set("combat_exp", 10000);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/sword/qingfeng")->wield();
	call_out("dest",300);
    call_out("keepmoving",1);
}

int keepmoving()
{
    if (!environment())
	{
		return 1;
	}
    this_object()->random_move();
	remove_call_out("keepmoving");
    call_out("keepmoving",15);
    return 1;
}

int dest()
{
	tell_room(environment(),this_object()->query("name")+"一闪身就不见了。\n");
	destruct(this_object());
	return 1;
}

