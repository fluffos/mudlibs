
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("prevent_summon" , 1);
    set("author" , "herself");
    set("short" , "Serena the mermaid");

    set ("long", @EndText
The mermaid was made of stone, but she
has come to life. Her long brown hair
curls down over her shoulders. The blue
cut glass on her tail has turned into
shimmering blue scales. She looks a little
bit sad. 
EndText
    );   // EndText should be on a line all by itself, with NO SPACES
    set("id" , ({"serena" , "Serena" , "mermaid" }) );
    set("attrib1" , "sad");
    set_size(5);
    set_name("Serena");
    set("gender" , "female");
    set("race" , "mermaid");
    set("stat" , ([
      "strength" : 8,
      "intelligence" : 21,
      "charisma" : 19
    ]) );
    set("damage", ({8,16}) );
    set("weapon_name" , "tail");
    set("damage_type", "bludgeoning");
    set_verbs( ({"hit" , "slap" , "smack at" , "whip"}) );
    set("max_sp", 350);
    set("spell_points" , 350);
    set("special" , 5);
    set("mage_spells" , ({"coldcone" , "images" , "fireball" , "wilting"}) );
    set("natt" , 1);
    set("chat_chance", 10);
    set("chat_output", ({
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
      "Mermaid says [to you]: What did i do to deserve this? \n",
      "Mermaid emits a horrible high-pitched squeal. \n",
    }) );
    set("stat/strength", 16);
    set("wealth" , 1320);
    set_skill("Unarmed", 2, "strength");
    set_level(22);
    arm("/d/class/wizard/general/obj/book") ;
    wear("?", "?");
}

void die() {
    say(wrap(
	"The life source drains from the mermaid's body... She lets out \n"+
	"one last horrible scream... then flops on the ground, dead.\n"));
    ::die() ;
    return 1;
}
void init (){
    ::init();
    command("cast images");
}

int special_attack() {
    object ob;
    int sv;

    string target;

    if (random(3)) return 0;
    if (query("cast_delay") || query("spell_points")<80 ) return 0;

    switch (random(3)){
    case 0 : command("cast coldcone");break;
    case 1 : command("cast fireball");break;
    case 2 : command("cast wilting");break;
    }
    return 0;
}
/* End of File */
