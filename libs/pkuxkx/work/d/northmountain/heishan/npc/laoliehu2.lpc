#include <ansi.h>
inherit NPC;
string ask_num(string name,string file);
void create()
{

    set_name("李老五", ({"li laowu", "laowu","li"}));
	set("title","老猎户");
    set("gender", "男性");
    set("age", 55);
    set("long", "他是一名老猎户，早年和张老七闹过别扭。\n");
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",10000);

   	set("inquiry", ([
	"野熊" : (: ask_num,"野熊","bear" :),
	"鹿" : (: ask_num,"鹿","deer" :),
    	]));
    setup();
    carry_object(__DIR__"obj/cloth1")->wear();
}
string ask_num(string name,string file)
{
	object *npc=children(__DIR__+file);
	npc=filter(npc,(: environment:));
	npc=filter(npc,(: environment($1)->query_location()==$2:),"/d/northmountain/heishan/");
	if (sizeof(npc)<1) return "我已经很久没有看见"+name+"了。\n";
	else return "我这段时间在山里见过"+chinese_number(sizeof(npc))+"只"+name+"。\n";
}
