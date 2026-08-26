
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "Herself");
    set("short" , "a chick trying on jeans");
    set("long", "a girl who was trying to squeeze into a \n"+
      "pair of jeans two sizes too small, before \n"+
      "you so rudely interupted her. \n");
    set("id" , ({ "chick" , "girl" , "jeans chick" }) );
    set("smell" , "She smells like new clothes. \n");
    set_size(6);
    set_name ("startled chick") ;
    set ("gender", "female") ;
    set("race", "human");
    set_align("le");
    enable_commands() ;
    set_living_name("startled chick");
    set("agressive" , 1);
    set("wealth" , 250);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("chat_chance", 10);
    set("chat_output", ({
      "The girl struggles to pull her jeans on. \n",
      "Chick says: I know i wear this size! \n",
    }) );
    set("att_chat_output", ({
      "Girl says: You are so rude!\n",
      "Girl says: Get outta here!\n",
    }) );
    set("damage" , ({2,5}) );
    set("weapon_name", "bag of diet pills");
    set ("CLASS", "warrior");
    set_verbs( ({ "swing at" , "shove" , "pound" }) );
    set_level(7);
}

void init(){
    ::init();
    command("What the hell are you doing in here? \n");
    if(userp(TP))
	command("kill "+TP->query("name"));
}
