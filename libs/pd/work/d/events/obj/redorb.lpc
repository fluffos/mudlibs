//  Whit

#include <std.h>

inherit OBJECT;

string COLOR, *all;

string query_color_orb() { return COLOR; }

void get_orb_color() {
    string f, co;

    f = file_name(this_object());
    sscanf(f, "/d/events/obj/%sorb", co);
    COLOR = co;
}

void create() {
    get_orb_color();
    ::create();
    all = ({"red","green","blue","yellow"});
    set_name(COLOR+" orb");
    set_short("a "+COLOR+" orb");
    set_long("The orb is a bright "+COLOR+" color.  There are "
      "scratch marks on it resembling 3 stones.");
    set_id( ({"orb",COLOR+" orb"}) );
    call_out("check_status", 4);
}

int check_status() {
    int i, tmp;
    object *tmp2;

    i = sizeof(all);
    tmp2=({});
    tmp=0;
    if(COLOR != "red") return 0;
    if(!environment(this_object())) {
	call_out("check_status", 30);
	return 1;
    }
    while(i--) if(present(all[i]+" orb", environment(this_object()))) {
	    tmp2 += ({ present(all[i]+" orb", environment(this_object())) });
	    tmp++;
	}
    if(environment(this_object())->is_player()) tmp=0;
    if(!environment(this_object())->is_event_area()) tmp=0;
    if(tmp>=4) {
	tmp2 -= ({ this_object() });
	i = sizeof(tmp2);
	while(i--) tmp2[i]->remove();
	new("/d/events/obj/gateway")->move(environment(this_object()));
	write("The 4 orbs sink into the ground.  A low rumble is heard and a "
	  "gateway grows up from the ground.", environment(this_object()));
	this_object()->remove();
	return 1;
    }
    write(""+tmp);
    if(environment(this_object()))
	message("info", "The "+COLOR+" orb twinkles slightly.",
	  environment(this_object()));
    call_out("check_status", 20);
}



