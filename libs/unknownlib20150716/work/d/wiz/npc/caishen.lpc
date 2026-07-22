// caishen.c, weiqi...97/12/21.
//财神爷赵公明, this guy is used to steal money from players.
//a player is allowed to carry 200-2000 gold depending on his/her dao-xing.
inherit NPC;
void steal_money();
void check_one(object user);

object *player;
int i=0;

void create()
{
set_name("赵公明", ({ "zhao gongming", "zhao", "caishenye", "caishen" }) );
set("long", "财神爷赵公明，天下人无不想见的大名人。\n");
set("title", "财神爷");
set("attitude", "friendly");
set("class", "xian");
set("age", 41);
set("max_gin", 200);
set("max_kee", 500);
set("max_sen", 300);
set("max_force", 300);
    
set("str", 30);
set("per", 10+random(15));

set("combat_exp", 100000);
set_skill("parry", 50);
set_skill("dodge", 40);
set_skill("unarmed", 50);
set_skill("changquan", 50);
map_skill("unarmed", "changquan");

setup();

carry_object("/d/obj/cloth/xianpao")->wear();
}
