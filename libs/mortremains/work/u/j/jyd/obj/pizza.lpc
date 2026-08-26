
string short(){
    return "A pavement pizza";
}
void init() {
    add_action("retch", "retch");
    add_action("eat", "eat");
}

string id(string str){
    return (str == "pavement pizza" || str == "puke" || str == "pizza");
}

int long(){
    write("\nA steamy, squishy, smelly pavement pizza. There are diced");
    write(" carrots and tomato skins floating around in it. Unfortunately");
    write(" it smells so bad that it makes you feel sick\n\n");
    say("\n"+this_player()->query_name()+" pokes around in the pavement pizza"+
       "\n", this_player());
    call_out("feel_ill",8);
    return 1;
}
int feel_ill() {
    write("\nYou don't feel so well, your stomach is churning Horribly!!\n");
    say("\n"+this_player()->query_name()+" bends over in agony."+
       "\n", this_player());
    call_out("feel_terrible",8);
    return 1;
}
int feel_terrible() {
    write("\nYou feel really unwell!! You're starting to go green!!\n");
    say("\n"+this_player()->query_name()+" takes on a greenish"+
       " tinge.\n", this_player());
    call_out("retch",8);
    return 1;
}
int retch() {
    write("\nYou double over and the world seems to pour out of your throat.");
    write(" You haven't had a technicolour yawn like this since you last had");
    write(" fourteen pints of bloody mary followed by a vindaloo and an");
    write(" extra hot, underdone doner kebab\n\n");
    say("\n"+this_player()->query_name()+" Doubles over and pukes up the last"+
       " four meals.\n", this_player());
    if(!present("pizza",environment(this_player()))) {
      move_object(clone_object("u/j/jyd/obj/pizza"),environment(this_player()));
      return 1;
    }
    return 1;
}
int eat(str) {
  if(!id(str)){ return 1;}
    write("\nYou don't feel so well. In fact, your health has been affected.");
    write(" Eating the pizza was not such a good idea!!\n");
    say("\n"+this_player()->query_name()+" has just eaten a pile of puke!!!"+
       "\n", this_player());
    call_out("feel_terrible",8);
    return 1;
}
int get() {
    write("\nYou just manage to scoop up the more congealed lumps of pizza.\n");
    say(this_player()->query_name()+" Scoops up the more congealed lumps"+
    " of a Pavement Pizza.\n", this_player());
    return 1;
}
