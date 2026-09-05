// bankhuoji  钱庄伙计
// Modified by iszt@pkuxkx, 2007-03-26, inherited BANKER

#include <ansi.h>

inherit NPC;
inherit BANKER;

void create()
{
        set_name("钱庄伙计", ({ "huo ji", "keeper" }));
        set("str", 20);
        set("gender", "男性");
        set("age", 25);
        set("long", "他是个勤劳的伙计，肚子里也有些墨水。\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");

        set("shen_type",1);set("score",200);setup();
}

void init()
{
	npc::init();
	banker::init();
}