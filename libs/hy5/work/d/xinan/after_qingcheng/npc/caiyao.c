//Writen by lnwm
//caoyao.c

inherit NPC;

void create()
{
	set_name("采药人", ({ "caiyao ren","ren" }) );
    set("gender", "男性" );
    set("age", 40);
    set("long",
"一位身背竹篓的深山菜药人。\n"
	    );
    set("combat_exp", 5000);

	set("chat_chance", 1);
    setup();
}




