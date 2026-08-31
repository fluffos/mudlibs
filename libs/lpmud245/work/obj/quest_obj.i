# 1 "obj/quest_obj.c" 





string hint_string, name;

set_hint(h) {
    hint_string = h;
}

set_name(n) {
    name = n;
}

id(str) { return str == name || str == "quest"; }

short() {
    return name;
}

long() {
    write("This is the quest '" + name + "':\n");
    write(hint_string);
}

hint() { return hint_string; }
