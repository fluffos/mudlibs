// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

private nosave object victim;

int start_shadowing(object ob) {
    if (!shadow(ob)) return 0;
    victim = ob;
    return 1;
}

int stop_shadowing() {
    if (!remove_shadow(this_object())) return 0;
    victim = 0;
}

string * query_shadows() {
    string * shadows;
    if (!victim) return ({});
    if (!(shadows = victim->query_shadows())) shadows = ({});
    return shadows + ({ file_name(this_object()) });
}
