// m_meetplace.c 
// this is the container will guest meet greeter
// by fire on March, 02 2000 inspired by suicide's meet hook
#include <hooks.h>
void add_hook(string tag, function hook);
void remove_hook(string tag, function hook);
private array greeters=({});
private int can_have_meet=0;
void obj_arrive(object o) {
	if(o->is_greeter()) {
		greeters -=({o});
		greeters +=({o});
	}
	if(o->is_guest()) {
		if(sizeof(greeters)) {
			foreach(object gobj in greeters) {
				if(!objectp(gobj)) {
					greeters-=({gobj});
					continue;
				}
				if(o==gobj) continue;
				gobj->do_greet(o);
			}
		}
	}
}
void obj_leave(object o) {
	greeters-=({o});
	if(o->is_guest()) {
		if(sizeof(greeters)) {
			foreach(object gobj in greeters) {
				if(!objectp(gobj)) {
					greeters-=({gobj});
					continue;
				}
				if(o==gobj) continue;
				gobj->do_send(o);
			}
		}
	}
}

void init_greetplace() {
	object *obs;
	obs=all_inventory(this_object());
	greeters=({});
	if(!sizeof(obs)) return;
	foreach(object o in obs) {
		if(o->is_greeter())
			greeters+=({o});

	}
	return;
}
mixed get_greeters() {
	return greeters;
}
int set_can_meet(int v) {
	if(v) {
		if(can_have_meet)
			return -1;
		else {
		   init_greetplace();
		   add_hook("object_arrived",(:obj_arrive:));
		   add_hook("object_left",(:obj_leave:));
		   can_have_meet=1;
		   return 1;
		}
	}
	if(!can_have_meet) return -2;
	can_have_meet=0;
	greeters=({});
	remove_hook("object_arrived",(:obj_arrive:));
	remove_hook("object_left",(:obj_leave:));
}
int is_meet_place() {
	return 1;
}
int can_meet() {
	return can_have_meet;
}
