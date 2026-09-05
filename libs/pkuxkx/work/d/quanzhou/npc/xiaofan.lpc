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
                "他是一个小贩，一直在武夷山一带兜售什么玩意。\n");
        set("combat_exp", 8000);
        set("attitude", "friendly");
        set("inquiry", ([
                
                "here" : "泉州是个港口，会行船的人很多。\n",
                "司南" : "这可是个好东西，过老林全靠它了。\n",
        ]));
        set("sinan","yes");
        set("vendor_goods", ({
                "/d/xiangyang/npc/obj/sinan",
                
                    }));

        setup();
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

void init()
{
        object ob;
        
        
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
                say(this_object()->query("name")+"笑眯眯地说道：客官，要不要来看看？\n");
                break;
        case 1 :
                say(this_object()->query("name")+"说道：客官，今天天气真不错，适合过老林啊。\n");
                break;
        }
}
