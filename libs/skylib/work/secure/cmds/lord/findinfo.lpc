
#define NO_ENV(x)  sizeof( filter( x, (: clonep($1) && !ENV($1) && !query_shadowing($1) :) ) )

inherit COMMAND_BASE;

int cmd() {
    int l;
    object *rooms, *items, *doors, *chatters, *livings, *objects,
    *containers, *weapons, *clothing, *armours, *money, *handlers, *cmds;

    objects = objects();

    rooms = filter( objects, (: $1->query_is_room() :) );
    objects -= rooms;
    l += sizeof(rooms);

    items = filter( objects, (: base_name($1) == "/std/room/basic/item" :) );
    objects -= items;
    l += sizeof(items);

    doors = filter( objects, (: base_name($1) == "/std/room/basic/door" :) );
    objects -= doors;
    l += sizeof(doors);

    chatters = filter( objects, (: base_name($1) == "/std/room/basic/chatter" :) );
    objects -= chatters;
    l += sizeof(chatters);

    containers = filter( objects, (: base_name($1) == "/std/container" :) );
    objects -= containers;
    l += sizeof(containers);

    weapons = filter( objects, (: $1->query_weapon() :) );
    objects -= weapons;
    l += sizeof(weapons);

    reset_eval_cost();

    clothing = filter( objects, (: $1->query_clothing() :) );
    objects -= clothing;
    l += sizeof(clothing);

    armours = filter( objects, (: $1->query_armour() :) );
    objects -= armours;
    l += sizeof(armours);

    money = filter( objects, (: base_name($1) == "/obj/money" :) );
    objects -= money;
    l += sizeof(money);

    handlers = filter( objects, (: base_name($1)[0..9] == "/handlers/" ||
               base_name($1)[0..16] == "/secure/handlers/" :) );
    objects -= handlers;
    l += sizeof(handlers);

    cmds = filter( objects, (: base_name($1)[0..5] == $2 ||
                               base_name($1)[0..12] == $3 :),
                               "/cmds/", "/secure/cmds/" );
    objects -= cmds;
    l += sizeof(cmds);

    objects = filter( objects, (: base_name($1) == "/std/object" :) );
    l += sizeof(objects);

    livings = livings();
    l += sizeof(livings);

    tell_object( TP, sprintf(
        "Types of various objects:    Num (no env)\n\n"
        "rooms:                      %4d\n"
        "/std/room/basic/item:       %4d\n"
        "/std/room/basic/door:       %4d\n"
        "/std/room/basic/chatter:    %4d\n"
        "/std/object:                %4d (%d)\n"
        "/std/container:             %4d (%d)\n"
        "/obj/weapon:                %4d (%d)\n"
        "/obj/clothing:              %4d (%d)\n"
        "/obj/armour:                %4d (%d)\n"
        "/obj/money:                 %4d (%d)\n"
        "livings:                    %4d (%d)\n"
        "heart beats:                %4d\n"
        "handlers:                   %4d\n"
        "commands:                   %4d\n---\n"
        "Used by these objects:      %4d\n"
        "Total objects loaded:       %4d\n",
        sizeof(rooms), sizeof(items), sizeof(doors),
        sizeof(chatters), sizeof(objects), NO_ENV( objects ),
        sizeof(containers), NO_ENV( containers ),
        sizeof(weapons), NO_ENV( weapons ),
        sizeof(clothing), NO_ENV( clothing ),
        sizeof(armours), NO_ENV( armours ),
        sizeof(money), NO_ENV( money ), sizeof(livings),
        NO_ENV( livings ), sizeof( heart_beats() ),
        sizeof(handlers), sizeof(cmds), l, sizeof(objects()) ) );

    return 1;

} /* cmd() */
