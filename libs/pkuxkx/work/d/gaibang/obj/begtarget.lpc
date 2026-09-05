//Zine

inherit NPC;
#include <ansi.h>

void create()
{
        string name,*tmp,*pinying;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title", color[random(sizeof(color))]+"行善积德"+NOR);
        set("shen_type", 1);

        set("str", 20);
        set("gender", "男性");
        set("age", random(20)+45);
        set("long",
                "他是一个远近闻名的大善人。\n");
        set("combat_exp", 8000);
        set("attitude", "friendly");

        setup();
        
}


