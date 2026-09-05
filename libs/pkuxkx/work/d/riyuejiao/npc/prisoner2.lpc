#include <ansi.h>

inherit NPC;
varargs void wield_weapon(string weapon);

void create()
{
	string name,*tmp,*pinying;
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("gender", "男性" );
	set("age", 22+random(10));
    set("title",HIC+"狱中豪杰"+NOR);
	set("long", "这是一名不知道何派的弟子，被关在神教监狱很久了。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	set("random_npc",1);
    set("food",500);
    set("water",500);
	set("chat_chance", 25);
	set("uni_target", 1);
    set("cantleave",1);
	setup();
    carry_object("/clone/cloth/cloth")->wear();
}




