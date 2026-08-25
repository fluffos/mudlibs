//    /adm/SimulEfun/magic_class.c
//    From the Nightmare Mudlib
//    Returns true if this_player() is a magic class
//    by Kalinash@Nightmare on May 20, 1994.

#define MAGIC_CLASSES ({"mage", "kataan", "cleric", "monk"})

int magic_class(object who) {
    string Class;

    Class = who->query_class();
    if(member_array(Class, MAGIC_CLASSES) == -1)
        return 0;
    return 1;
}
