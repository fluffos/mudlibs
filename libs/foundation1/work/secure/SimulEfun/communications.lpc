
varargs void say(mixed str, object ob) {
    if(!environment(this_player())) return;
    message("say", str+"", environment(this_player()),
      (objectp(ob) ? ({ this_player(), ob }) : ({ this_player() })));
}

void tell_object(object ob, mixed str) { message("tell", str+"", ob); }

varargs void tell_room(object ob, mixed str, mixed exclude) {
    if(!ob) return;
    message("environment", (str ? str+"" : ""), ob,
      (exclude ? (pointerp(exclude) ? exclude : ({exclude})) : ({})));
}

varargs void shout(mixed str, mixed exclude) {
    if(objectp(exclude)) exclude = ({ exclude });
    else if(!pointerp(exclude)) exclude = ({});
    if(this_player()) exclude += ({ this_player() });
    message("shout", str+"", users(), exclude);
}

