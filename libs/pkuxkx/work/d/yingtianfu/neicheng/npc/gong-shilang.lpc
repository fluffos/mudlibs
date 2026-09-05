//工部侍郎

#include <ansi.h>
inherit NPC;
#include "gongbu_shilang.h"

void create()
{
    set_name("工部左侍郎", ({"gongbu shilang", "shilang"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 40);
    set("long", "他就是当今朝廷的工部左侍郎。\n");
    set("attitude","heroism");
    set("generation",0);
    set("mingpin",3);
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    
	set("inquiry", ([
	
     "治理长江": (: ask_cj :),
     "虞衡司事务": (: ask_yh :),
     "营缮司事务": (: ask_ys :),
	]));

    setup();
    setup_player_name();
}
