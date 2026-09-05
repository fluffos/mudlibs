// chen.c
// Jay 5/7/96

inherit NPC;
inherit F_DEALER;
#include <ansi.h>
int keepmoving();
void create()
{
        string name,*tmp,*pinying;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title", color[random(sizeof(color))]+"小贩"+NOR);
        set("shen_type", 1);

        set("str", 20);
        set("gender", "男性");
        set("age", random(20)+25);
        set("long",
                "他是一个小贩，一直在建康府的广场卖些吃的。\n");
        set("combat_exp", 8000);
        set("attitude", "friendly");
        
        set("sinan","yes");
        set("vendor_goods", ({
                "/d/city/npc/obj/peanut",
                "/d/city/npc/obj/jiudai",
                
                    }));

        set("random_npc",1);
        setup();
		carry_object("/clone/cloth/cloth")->wear();
        call_out("keepmoving",1);
}

int keepmoving()
{
    this_object()->random_move();
    call_out("keepmoving",15);
    return 1;
}

void init()
{
	add_action("do_list","list");
	add_action("do_buy","buy");
}