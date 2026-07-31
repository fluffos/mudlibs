
#include <ansi.h>
inherit NPC;
string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈","柳","风","刘","林", }); 
string *name_words = ({ "一","二","三","四","五","六","七","八","九","十", });
string *color_title = ({"[天杀门]杀手","[地煞门]杀手",});

void create()
{
 string name,weapon;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
       set_name(name, ({ "killer", "shashou", "sha shou" }));
       set("gender", "男性");
       set("title", color_title[random(sizeof(color_title))]);
       set("long", "这人身穿黑色紧装，面上蒙着一块黑布，只露出一双眼睛，精光四射。\n");
       set("age", random(20)+25);      
	set("str", 20+random(5));
       set("int",20+random(5));  
       set("con",20+random(5));     
       set("dex",20+random(5));
        set("vendetta/authority",1);
        set("per", 1);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 1);
	set("bellicosity", 10000);
        set("chat_chance", 99);
        set("chat_msg", ({
		(: command, "get all from corpse" :),
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "杀手喝道：今天老子又要神书又要命！！\n",
                "杀手笑道：快把神书交出来！让你死的痛快一点!\n",
        }) );

        set_skill("unarmed", 20+random(200));
        set_skill("sword", 20+random(200));
        set_skill("parry", 20+random(200));
        set_skill("dodge", 20+random(200));
        set_skill("move", 20+random(200));

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 20);
        set_temp("apply/damage", 20+random(80));
        set_temp("apply/move", 20);

        setup();

       carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}
int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		 name() + "说道：今天收获不小，休息去了。\n\n",environment(),
		this_object() );
       	destruct(this_object());
}


