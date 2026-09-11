// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
inherit LIVING;
inherit M_ACTIONS;
string *emotes, *adverbs;
string find_target() {
    string u_id;
    object *who = users(); // & all_inventory(environment());
    if (!sizeof(who)) 
        return this_object()->query_id()[0];
    u_id=who[random(sizeof(who))]->query_userid();
    if(!find_body(u_id))
        return this_object()->query_id()[0];
    return u_id;
}
void do_my_thing() {
    string which = emotes[random(sizeof(emotes))];
    string *rules = keys(SOUL_D->query_emote(which));
    string rule = rules[random(sizeof(rules))];
    object *who = users();
    string comm, token;
    
    if (!environment()) return;
    comm = which;
    foreach (token in explode(rule, " ")) {
        comm += " ";
        switch (token) {
        case "OBJ":
        case "LIV":
            comm += find_target();
            break;
        default:
            comm += token;
        }
    }
    call_out( (: do_my_thing :), 60);
    do_game_command(comm);
}
void setup() {
    set_name("Barney","巴雷");
    set_gender(1);
    set_proper_name("小恐龙巴雷");
    set_in_room_desc("小恐龙巴雷(barney)");
    set_long("他就是人见人爱的紫色小恐龙。");
    emotes = SOUL_D->list_emotes();
    adverbs = SOUL_D->get_adverbs();
    call_out( (: do_my_thing :), 5);
}
     
