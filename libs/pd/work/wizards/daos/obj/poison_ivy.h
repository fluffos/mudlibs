object ob;
int i;

void infect(object ob) {
    ob = this_player();
    i = random(20);

    if (i == 20) {
	message("info", "You are very itchy.", ob);
	message("info", this_player()->query_cap_name()+" is very itchy.", environment(ob), ({ob}) );
    }
}
string extra_look() {
    string *limbs;
    limbs = this_player()->query_limbs();
    return "You have a horrible rash on " + limbs[random(sizeof(limbs))] + ".";
}

void init() {
    if (!random(20)) infect(ob);
}
