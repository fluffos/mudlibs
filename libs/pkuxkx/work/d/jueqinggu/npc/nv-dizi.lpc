
#include <ansi.h>
inherit NPC;


void create()
{
    string name,*tmp,*pinying;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("title",HIG+"绝情谷 "+color1+"女弟子"+NOR);
	set("shen_type", 1);

	set("str", 30);
	set("gender", "女性");
	set("age", 20+random(10));
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("random_npc",1);
	setup();
    carry_object(__DIR__"obj/cloth-2")->wear();

}

void init()
{
    int i;
    object *all=all_inventory(environment(this_object()));
    for (i=0;i<sizeof(all) ;i++ )
    {
        if (userp(all[i])&&random(3))
        {
            command("sleep");
        }
    }
}