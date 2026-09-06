#include <npc.h>
#include <macros.h>

void
create_monster(){
    set_name("perfectly miniaturized dark elf");
    set_id( ({"elf", "drow", "miniaturized dark elf"}) );
    set_long("A miniaturized dark elf. It's growth must have been \
stunted due to the weak light here. It seems to be hungry. Maybe you \
should feed it.");
    set_level(2);
    set_money(30);
    set_wc(9);
    set_ac(3);
    set_race("dark elf");
    load_chat(5, ({
	"Elf asks: Can I help, you look a little lost?",
	"Elf squints and rubs his eyes.",
	"Elf says: Excuse me. Could you tell me the way to Doomdark's \
Zoo for Novices?",
      }));
}

void
give_object_by(object given_by, object item) {
    if(intp(item) || !item->is_food()) {
	given_by->tell_me("Miniaturized dark elf says: This isn't food! \
Give me food!");
	ENV->tell_here(sprintf("Miniaturized dark elf says something to %s",
	    given_by->query_name()), given_by);
	if(!intp(item))
	    call_out("drop_it", 2, item);
	return;
    }

    ENV->tell_here(sprintf("Dark elf eats %s.",
	lower_case(item->query_short()) ));
    destruct(item);
    call_out("grow_a_bit", 2);
}

void
grow_a_bit() {
    ENV->tell_here("Miniaturized dark elf seems to grow a bit.");
    if(!random(3) && level<10) level += 1;
}

void
drop_it(object item) {
    if(!item->drop() && item) {
	ENV->tell_here(sprintf("Miniaturized dark elf drops %s.",
	    lower_case(item->query_short()) ));
	move_object(item, ENV);
	ENV->extra_move_object(item, ENV);
    }
}
