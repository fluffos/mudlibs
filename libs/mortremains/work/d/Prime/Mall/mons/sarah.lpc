
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "sarah");
    set("long" , "Sarah is one of those sweet, innocent \n"+
      "looking women. She has curly blonde hair, shoulder length. \n"+
      "If you look closely, you might notice that\n"+
      "one of her eyes is half brown and half blue.\n"+
      "She looks at you politely, and smiles\n");
    set("id" , ({ "sarah" , "sara" , "shopkeeper" , "keeper" }) );
    set("smell" , "She smells like freshly cut flowers. \n");
    set_size(5);
    set_name ("sarah");
    set ("gender", "female") ;
    set("race", "human");
    set_align("le");
    enable_commands() ;
    set("wealth" , 250);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("chat_chance", 10);
    set("chat_output", ({
      "Sarah looks at you sweetly. \n",
      "Sarah says: How can i help you today? \n",
    }) );
    set("att_chat_output", ({
      "Sarah cries out: I'm sorry, I only wanted to help you!\n",
      "Sarah says: Is this the way you treat all salespeople? \n",
    }) );
    set("damage" , ({5,10}) );
    set("weapon_name" , "hands");
    set_verbs( ({"hit at" , "swing at" , "slap at" }) );
    set_level(23);
}

