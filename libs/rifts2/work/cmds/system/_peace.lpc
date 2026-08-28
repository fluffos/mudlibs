// For use by any q to stop combat.

int cmd_peace() {
    object *inv, tp;
    int i;
    tp = this_player();

    write("You bring peace to the area.\n");
    say(tp->query_cap_name()+" raises "+tp->query_possessive()+" hands to the sky and brings peace to the area.\n", tp);
    inv = all_inventory(environment(tp));
    for(i=0; i<sizeof(inv); i++) {
        if(!living(inv[i])) continue;
        inv[i]->cease_all_attacks();
    }
    return 1;
}

int help(){
write(@TEXT
Syntax: <peace>

This command stops all attacks in the room.

See also: dest.
TEXT
);
}
