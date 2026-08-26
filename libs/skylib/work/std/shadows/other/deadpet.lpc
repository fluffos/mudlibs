/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: deadpet.c,v 1.1 1998/01/06 04:42:56 ceres Exp $
 * $Log: deadpet.c,v $
 * Revision 1.1  1998/01/06 04:42:56  ceres
 * Initial revision
 * 
*/
inherit "/std/effect_shadow";

#define EFFECT "/std/effects/other/deadpet"
#define BP tell_object( find_player("gerbil"), "BP.\n");

mixed *info = ({ });
int add = 0;

void update_args() {
call_out("add_effect", 1, EFFECT, ({0, 0, 0}) );
}

void set_add() {
  add = 1;
}

mixed query_info() { return info;}

void remember_pet(mixed *arg) {
if(!sizeof(info) && add) {info = arg();}
    info = info + ({ ({arg[0], arg[1], arg[2], 1}) }) ;
update_args();
}


mapping q_d() {
    mapping ret = ([]);
mixed *value;
if(!sizeof(info)) {info = arg();}
    foreach(value in info) {
        if(value[3] == 1) {
            if(undefinedp(ret[value[2]]) ) {
                ret[value[2]] = ({ value });
            } else {
                ret[value[2]] += ({ value });
            }
        }
    }
update_args();
    return ret;
}

int num_dead_pets() {
    int a;
    a = sizeof(info);
    while(a--) {
        if(info[a][3]) {return 1;}
    }
    return 0;
}


void remove_pet(string str) {
    int a;
    for(a=0;a<sizeof(info);a++) {
        if(lower_case(info[a][2]) == str) {
            if(info[a][3]) {
                info[a][3] = 0;
if(!(num_dead_pets())) {
                    this_object()->delete_effect(this_object()->effects_matching("priest.dead.pet")[0]);
                }
update_args();
                return;
            }
        }
    }
}


mixed *really_remove_pet() {
   mixed *args;
if(!sizeof(info)) {info = arg();}
    args = info[0];
    info = info[1..];
update_args();
    return args;
}

void remove_specific_pet(string name, int order) {
    int a;
    for(a=0;a<sizeof(info);a++) {
        if(info[a][3]) {
            if(lower_case(info[a][2]) == name) {
                if(!(--order)) {
                    info[a][3] = 0;
update_args();
                    if(!this_object()->num_dead_pets()) {
                        this_object()->delete_effect(this_object()->effects_matching("priest.dead.pet")[0]);
                        return;
                    }
                }
            }
        }
    }
}



void init_static_arg(mapping map, object own) {
  info = map[info];
}


