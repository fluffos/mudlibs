void start_shadow(){
    call_out("init_c",5);
    return;
}
void init_c() {
    object new_shadow;
    shadow(find_player("cattt"),1);
}
string query_short(){
    string *titles;
    titles=({"Cattt meows at you.",
      this_player()->query("cap_name")+" is Cattt's love slave.",
this_player()->query("short")+"!!",
"Cattt is prejudice against all "+this_player()->query("race")+"s.",
      ""
    });
    return(titles[random(sizeof(titles)-1)]);
}

mixed query_auto_load() {
    return 1;
}
