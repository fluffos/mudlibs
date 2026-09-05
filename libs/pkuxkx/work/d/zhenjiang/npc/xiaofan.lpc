//Zine

inherit NPC;
inherit F_DEALER;
#include <ansi.h>

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
        set("random_npc",1);
        set("str", 20);
        set("gender", "男性");
        set("age", random(20)+25);
        set("long",
                "他是一个小贩，一直在梦溪园兜售什么文房四宝。\n");
        set("combat_exp", 8000);
        set("attitude", "friendly");
        set("inquiry", ([
                
                "here" : "镇江四通八达，北面过江就是扬州，西面通往建康府，东面通向苏州。\n",
                
        ]));
        set("sinan","yes");
        set("vendor_goods", ({
                "/d/zhenjiang/npc/obj/zhi",
                "/d/zhenjiang/npc/obj/bi",
                "/d/zhenjiang/npc/obj/mo",
                "/d/zhenjiang/npc/obj/yan",
                "/d/xingxiu/npc/obj/case",
                "/clone/obj/gemlocker",
                    }));

        setup();
        
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
                say(this_object()->query("name")+"说道：客官，新到的笔墨纸砚啊。\n");
                break;
        }
}
