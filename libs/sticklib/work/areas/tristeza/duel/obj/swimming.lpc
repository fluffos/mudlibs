/* Changes short when swimming */

object target;

void
do_shadow(object ob) {
    target=ob;
    shadow(ob);
}

string
short() {
    return (target->query_name()+" is swimming here");
}


void
move_player(mixed arg, mixed arg2) {
    string msg;

    msg = (string) target -> query_move_msg("mout");
    target -> set_move_msg("mout", "swims");
    target->move_player(arg, arg2);
    target -> set_move_msg("mout", msg);
    if(environment(target)->query_water()) return;

    destruct(this_object());
}

status
query_swimming() {return 1;}
