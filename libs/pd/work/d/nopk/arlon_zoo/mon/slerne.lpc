#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void confirm_key(string *given);
void create() {
    ::create();
    set_name("Slerne");
    set_id( ({ "slerne", "blue", "dragon" }) );
    set_short("Slerne, the baby %^BOLD%^%^BLUE%^blue %^RED%^dragon%^RESET%^");
    set("aggressive", 0);
    set_level(15);
    set_long("This rather large baby %^BOLD%^%^BLUE%^blue%^RESET%^ dragon "+
      "looks like he is enjoying himself."+
      "  He is prancing around like a cat, "+
      "rubbing up against the visitors, "+
      "and even occasionally licking them playfully on the face!\n");
    set_body_type("dragon");
    set_alignment(0);
    set("race", "blue dragon");
    set_emotes(10,({ "Slerne likes to be petted!", "Slerne rubs up against you.  Is that purring?" }),0);
    set_gender("male");
}
void init() {
    ::init();
    add_action("pet_monster","pet");
    add_action("scratch_slerne","scratch");
    add_action("ride_slerne","ride");
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

    string monster_action = "Ahhh! thank you!  Could you scratch under my chin too?\n";

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

int scratch_slerne(string str){
    string say1 = "say Ahhhh, good! good!  Thank you very much!  Perhaps you can help me?";
    string say2 = "say I was playing with my friend Darien's keys this morning.  They are";
    string say3 = "say so pretty, all %^YELLOW%^gold%^RESET%^ and %^BOLD%^silver%^RESET%^ and such."+
    "  If i can't find them, and";
    string say4 = "say give them back, he may not let me continue to stay here and i do so ";
    string say5 = "say love the petting and scratching.  I know i just had them a moment";
    string say6 = "say ago, and in this house too.";

    if (str == "slerne" || str == "blue" || str == "dragon"){
	write("Scratch where?\n");
    }
    if (str == "chin"){
	this_object()->force_me("say Ahhh, that feels good!  And behind the ears?");
	return 1;
    }
    if (str == "ear" || str == "ears"){
	this_object()->force_me(say1);
	this_object()->force_me(say2);
	this_object()->force_me(say3);
	this_object()->force_me(say4);
	this_object()->force_me(say5);
	this_object()->force_me(say6);
	return 1;
    }
    write("Scratch what?\n");
    return 1;
}
void confirm_key( string *given ) {
    object tp, ob;
    string who, that;

    string say1 = "You found the keys!  Thank you so very much.";
    string say2 = "Could you do me one more favor and give them ";
    string say3 = "to Darien for me?  I think he's a little upset";
    string say4 = "with me at the moment and I know he'd be a lot";
    string say5 = "more greatful to you than he would be with me.";

    string not_a_key = "I don't know what this is for, but thank you.";
    string wrong_key = "No, no, this is not the right key.";

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
	this_object()->force_me("give key to "+tp->query_name());
	return;
    }
    this_object()->force_me("say "+say1);
    this_object()->force_me("say "+say2);
    this_object()->force_me("say "+say3);
    this_object()->force_me("say "+say4);
    this_object()->force_me("say "+say5);

    this_object()->force_me("give key to "+tp->query_name());
    return;
}
int ride_slerne(string ridden){
    string monster_action = "Slerne is too young to be ridden!\n";

    string no_monster = "Ride what?\n";
    string wrong_object = "Ride what?\n";
    string ridden_object, ridden_number;

    if(ridden==0) return notify_fail(no_monster);

    sscanf(ridden, "%s %s", ridden_object, ridden_number);
    if(ridden_object == 0){ridden_object=ridden;}

    if(ridden_object != "slerne" && ridden_object != "dragon" && ridden_object != "blue")
	return notify_fail(wrong_object);

    tell_room(environment(this_object()),monster_action,this_object());
    return 1;
}
