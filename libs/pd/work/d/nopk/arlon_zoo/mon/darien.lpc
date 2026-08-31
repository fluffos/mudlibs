#include <std.h>
inherit MONSTER;

void confirm_key(string *given);

void create() {
    ::create();
   set_name("Darien");
   set_id( ({ "darien", "man", "zookeeper" }) );
   set_short("Darien, the zookeeper");
   set("aggressive", 0);
   set_level(16);
   set_long("Darien is an older man, rugged features showing years of worldly experience abroad.  Adventuring days behind him now, he has started this petting zoo as a way to stay active in the community.\n");
   set_body_type("human");
   set_alignment(0);
   set("race", "human");
   set_emotes(2,({ "Darien smiles happily.", "Darien welcomes you to his petting zoo." }),0);
   set_gender("male");
}

void init() {
    ::init();
    add_action("pet_monster","pet");
}

void catch_tell(string str) {
    object ob;
    string a, b;

    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%s gives you %s", a, b) == 2) {
        call_out("confirm_key", 2, ({ lower_case(a), lower_case(b) }) );
    }
}

int pet_monster(string petted){
    
    string monster_action = "I know this is a petting zoo, but isn't petting me a bit much?";

    string no_monster = "Pet what?\n";
    string wrong_monster = "Pet who?\n";
    string petted_monster, petted_number;

    if(petted==0) return notify_fail(no_monster);

    sscanf(petted, "%s %s", petted_monster, petted_number);
    if(petted_monster == 0){petted_monster=petted;}

    if(!present(lower_case(petted))) return notify_fail(wrong_monster);

    if(member_array(petted_monster,this_object()->query_id()) == -1)
        return notify_fail(wrong_monster);

        this_object()->force_me("say "+monster_action);
    return 1;
}

void confirm_key( string *given ) {
    object tp, ob;
    string who, that;

    string say1 = "What's this?  This looks like my zoo keys!";
    string say2 = "Where did you find them?  An imp northeast of";
    string say3 = "here you say?  I was wondering what happened to";
    string say4 = "these.  I do thank you though, without these I ";
    string say5 = "wouldn't be able to retrieve the donations of ";
    string say6 = "the day.   Let me get you a little something";
    string say7 = "for your trouble and to say thank you.";
    string quest_action1 = "Darien takes the %^BOLD%^silver%^RESET%^ key, ";
    string quest_action2 = "unlocks the donation box, and withdraws some gold.";

    string not_a_key = "What is this for?";
    string wrong_key = "What is this for?";

    who = given[0];
    that = given[1];

    tp = present(who, environment(this_object()));
    ob = present("key");
    if(!tp) return;
    if(!ob) {
        this_object()->force_me("say "+not_a_key);
        return;
    }
    if(!ob->id("petting_zoo_deed_key")) {
        this_object()->force_me("say "+wrong_key);
        return;
    }
    this_object()->force_me("say "+say1);
    this_object()->force_me("say "+say2);
    this_object()->force_me("say "+say3);
    this_object()->force_me("say "+say4);
    this_object()->force_me("say "+say5);
    this_object()->force_me("say "+say6);
    this_object()->force_me("say "+say7);
    tell_room(environment(this_object()),quest_action1+quest_action2,this_object());

    ob->remove();
    ob = new("/std/obj/coins");
    ob->set_money("gold", 500);
    ob->move(this_object());

    this_object()->force_me("give 500 gold coin to "+tp->query_name());

    if(!tp->set_mini_quest("zoo keys", 100, "You found the zoo keeper's lost keys.\n"))
        tp->add_exp(500+random(200));

    return;
}
