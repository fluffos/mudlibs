
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a siren");
    set("prevent_summon" , 1);
    set ("long", @EndText
A beautiful half woman, half bird. Her beauty seems
to draw you to her.
EndText
    );
    set("id" , ({"siren"}) );
    set("attrib1" , "enchanting");
    set("stat/constitution", 12);
    set_size(5);
    set("wealth" , 2100);
    set_name("siren");
    set("gender" , "female");
    set("race" , "half human-half bird");
    set("damage" , ({3,9}) );
    set("damage_type" ,"force");
    set("weapon_name" , "song");
    set_verbs( ({"hypnotize" , "enchant" , "draw"}) );
    set("stat" , ([
      "strength" : 8,
      "intelligence" : 18,
      "charisma" : 24,
      "dexterity" : 14,
      "wisdom" : 18,
      "constitution" : 16
    ]) );
    set("max_sp", 400);
    set("spell_points" , 400);
    set("special" , 5);
    set("mage_spells" , ({"glitter" , "lightning" , "chill" , "blind"}) );
    set("chat_chance" , 6);
    set ("chat_output", ({
      "The siren enchants you with her beautiful song. \n",
    }) );
    set ("att_chat_output", ({
    }) );
    set_skill("Unarmed" , 2, "strength");
    set_level(26);
    arm("/d/class/wizard/general/obj/book");
    wear("?","?");
}
void init () {
    ::init();
    command("cast glitter");
}
int special_attack() {
    object ob;
    int sv;

    string target;
    if (random(3)) return 0;
    if(query("cast_delay") || query("spell_points")<80)return 0;
    switch(random(3)){
    case 0 : command("cast chill");break;
    case 1 : command("cast lightning");break;
    case 2 : command("cast blind");break;
    }
    return 0;
}
/*
int hit_func(object ob, int damage) {
    if(!random(25)) {
	tell_object(ob, "The siren sings the most beautiful song you've "+
	  "ever heard. Your head spins from the unearthly "+
	  "notes. \n");
	ob->block_attack(random(2)+1);
	ob->receive_damage((random(5)+5), "suffocation");
    }
}
*/
