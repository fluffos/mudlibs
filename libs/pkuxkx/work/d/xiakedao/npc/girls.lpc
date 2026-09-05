
#include <ansi.h>

inherit NPC;
void create()
{
	int i,amun;
	string *name= ({"兰花", "竹叶", "小菊", "玫瑰", "杜鹃"});
	set_name( name[random(5)] , ({ "pretty girl", "girl" }) );
	set("long", "这是一位侠客岛的小丫头\n");
	set("attitude", "friendly");
	set("max_qi", 500);
	set("max_jing", 500);
	set("age", 18);
        set("gender", "女性" );
        set("chat_chance", 1);
        set("chat_msg", ({
                "小丫头窃窃道：听说要静侯三个时辰．．．．才肯．\n",
        }) );

	set("str", 35);
	set("con", 30);
	set("dex", 25);

	set("combat_exp", 200000);
	set_skill("throwing",100+random(100));
	set_skill("dodge", 100+random(50));
	set_skill("force", 100+random(50));
	set_skill("parry", 100+random(50));
	set_skill("unarmed", 100+random(50));
	set("shen_type",1);set("score",200);setup();
	carry_object(__DIR__"obj/bluecloth")->wear();
        carry_object(__DIR__"obj/anqi")->wield();
}
