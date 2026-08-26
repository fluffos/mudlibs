// Chernobog (5/3/22)
// Potion Case

#include <std.h>
#include <move.h>
inherit BAG;

void create(){
    ::create();
    set_name("potion case");
    set_id(({ "case", "potion case" }));
    set_short("folded leather case");
    set_long("Leather inserts divide the container into multiple compartments, allowing one to organize and protect the vials inside. It folds up with a simple metal clasp to keep it secured.");
    set_max_internal_encumbrance(30);
    set_weight(4);
    set_value(500);
    set_property("repairtype", ({ "leatherwork" }));
    set_open_long(""+this_object()->query_long()+"\n%^RESET%^%^CRST%^%^C101%^The leather case is currently open.%^CRST%^\n");
    set_closed_long(""+this_object()->query_long()+"\n%^RESET%^%^CRST%^%^C101%^The leather case is currently closed.%^CRST%^\n");
    set_possible_to_close(1);
}

int item_allowed(object item){
    if(item->is_potion()) return 1;
    tell_object(this_player(), "\nIt seems only brewed potions and elixirs will work with this case.");
    return 0;
}

