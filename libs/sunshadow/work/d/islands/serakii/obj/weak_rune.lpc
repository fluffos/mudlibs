//weak rune

#include <std.h>

inherit OBJECT;

int blah;
string weakness_type;

void create(){
	::create();
    set_name("weak rune");
    set_id("weak_rune");	
    set_short("");
    set_long("");
    set_weight(0);
    set_property("no animate",1);
    set_heart_beat(1);	
	blah = 0;
    set_property("inanimate bonus", 1);

}

void  set_weakness(string str){
    weakness_type = str;
    set_item_bonus("attack bonus", 5);
	
	switch(weakness_type){
		
		case "fire":
            set_item_bonus("fire resistance", -20);
		break;
		case "cold":
            set_item_bonus("cold resistance", -20);
		break;
		case "electricity":
            set_item_bonus("electricity resistance", -20);
		break;
		case "acid":
            set_item_bonus("acid resistance", -20);
		break;

    return;
}

}


void init(){
	::init();

	add_action("my_give","give");
	add_action("my_give","offer");
    if(!userp(ETO)) TO->remove();
}

int expire(){
   object room, player;
   
    player = environment(this_object());    
    room = environment(this_object());
	tell_object(player,"%^C056%^You feel weakness leave you...%^CRST%^\n");
	TO->remove();
	return 1;
}

void hurt(object tp){
   object room, player;
   
   player = environment(this_object());    
   room = environment(this_object());	
	
	
	if(!objectp(tp)){
		remove();
		return;
	}
if(tp->query_ghost()){
    remove();
      return;
  }
	tell_object(player,"%^C056%^You feel weakness rush through you...%^CRST%^\n");
	call_out("hurt",20,tp);
	if(blah >4 && !interactive(tp)){
    expire();
	}
	blah++;
}

int my_give(string str){
	if(id(str)) return 1;
	}