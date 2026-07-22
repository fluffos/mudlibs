// xtong3.c 小童

inherit NPC;
#include <ansi.h>
void greeting(object);
void init();
void create()
{
        set_name("小童", ({ "xiao tong","xiao","tong" }) );
        set("gender", "男性" );
        set("age", 13);
        set("long", "这是一个清秀的小童，身着一身青衣，一付可爱的样子。\n");
        set("shen_type", 1);
        set("combat_exp", 50000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("attitude", "friendly");

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("silver",random(50));
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

string *foods=({
        FOOD_D("rice"),
        FOOD_D("miantang"),
        FOOD_D("qingcai")
});

void greeting(object ob)
{  
	object food;
	mapping fam;

	fam = ob->query("family");
        if( !ob || environment(ob) != environment() ) return;
        if( fam && fam["family_name"] == "明教"){
             say(CYN"小童笑吟吟地说道：这位" + RANK_D->query_respect(ob)
             + "您饿了吧，请用餐。\n"NOR);
             food = new(foods[random(sizeof(foods))]);
             food->set("value",0);
             food->move(ob);
        }
        else 
          say(CYN"小童眨眨眼睛，笑吟吟地说道：这位" + RANK_D->query_respect(ob)
             + "，欢迎来蝴蝶谷做客，但不要偷吃哟！\n"NOR);
        return;
}
