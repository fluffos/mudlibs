#include "/obj/clean.c"
/*
 * This file defines a general purpose armor. See below for configuration
 * functions: set_xx.
 */

/*
 * If you are going to copy this file, in the purpose of changing
 * it a little to your own need, beware:
 *
 * First try one of the following:
 *
 * 1. Do clone_object(), and then configure it. This object is specially
 *    prepared for configuration.
 *
 * 2. If you still is not pleased with that, create a new empty
 *    object, and make an inheritance of this objet on the first line.
 *    This will automatically copy all variables and functions from the
 *    original object. Then, add the functions you want to change. The
 *    original function can still be accessed with '::' prepended on the name.
 *
 * The maintainer of this LPmud might become sad with you if you fail
 * to do any of the above. Ask other wizards if you are doubtful.
 *
 * The reason of this, is that the above saves a lot of memory.
 */

string name, alias, short_desc, long_desc;
int value, weight;
string type;
int size, save_flag, worn, ac;
object worn_by;
object next;
string info;
int set_ac_flag;

reset(arg)
{
    if(arg)
	return;
    type = "armor";
}

/* Calls a wizard defined function */
call_armor_special(owner) {
  int bonus;

  bonus=call_other(this_object(),"do_special",owner);
  if(next)
    bonus+=next->call_armor_special(owner);
  return bonus;
}

link(ob)
{
    next = ob;
}

remove_link(str)
{
    object ob;

    if (str == name) {
	ob = next;
	next = 0;
	return ob;
    }
    if (next)
	next = call_other(next, "remove_link", str);
    return this_object();
}

init() {
    add_action("wear"); add_verb("wear");
    add_action("remove"); add_verb("remove");
/*
    add_action("take_off"); add_verb("unwear");
*/
    add_action("remove"); add_verb("unwear");
}

rec_short()
{
    if(next)
	return name + ", " + call_other(next, "rec_short");
    return name;
}

short() {
  string tmp_short;
    if (!short_desc)
	return 0;
     tmp_short = short_desc;
       if(this_player()->is_player() && size) {
         if(size == 1) tmp_short = tmp_short + " (XS)";
         if(size == 2) tmp_short = tmp_short + " (S)";
         if(size == 3) tmp_short = tmp_short + " (M)";
         if(size == 4) tmp_short = tmp_short + " (L)";
         if(size > 4) tmp_short = tmp_short + " (XL)";
              }
  if (call_other(this_player(), "query_level", 0) > 30)
   {
       tmp_short = tmp_short + "  < ac " + ac + ", " +type +" >";
     }
     if (worn)
      return tmp_short + " (worn)";
      return tmp_short;
}

long(str) {
string tmp_long;
tmp_long="";
       if(this_player()->is_player() && size) {
         if(size == 1) tmp_long = tmp_long + " [XS]";
         if(size == 2) tmp_long = tmp_long + " [S]";
         if(size == 3) tmp_long = tmp_long + " [M]";
         if(size == 4) tmp_long = tmp_long + " [L]";
         if(size > 4) tmp_long = tmp_long + " [XL]";
              }
    write(long_desc);
    if(size) write("Size: "+tmp_long+"\n");
}

id(str)
{
    return str == name || str == alias || str == type;
}

test_type(str)
{
    if(str == type)
	return this_object();
    if(next)
	return call_other(next, "test_type", str);
    return 0;
}

tot_ac()
{
    if(next)
	return ac + call_other(next, "tot_ac");
    return ac;
}

query_type() { return type; }

query_value() { return value; }

query_worn() { return worn; }

query_name() { return name; }

armor_class() { return ac; }

wear(str)
{
    object ob;
    object guild, invob;  /* For paladin additions */
    int tmp;

    if (!id(str))
	return 0;
    if (environment() != this_player()) {
	write("You must get it first!\n");
	return 1;
    }
    if(present("notarmor",this_player())) {
       write("For some reason you are unable to wear armor.\n");
       return 1;
    }
    if (worn) {
	write("You already wear it!\n");
	return 1;
    }
    if(size) {
      tmp=find_size(this_player());
      if(tmp > size) {
        write("You find that it is too small for you.\n");
        return 1;
       }
      if(tmp < size - 1) {
        write("It is far to big for you, it simply falls off.\n");
        return 1;
      }
      if(tmp < size) write("It's a little big but you can wear it.\n");
      }
    next = 0;
/* BEGIN PALADIN ADDITION */
/* If the paladin has an off-wielded weapon they cannot wear shields! */
   invob = first_inventory(this_player());
   while(invob) {
     guild = invob->query_offwielded();
     if(guild && type == "shield") {
       write("You have an offwielded weapon!\n");
       return 1;
     }
     invob = next_inventory(invob);
   }
/* END PALADIN ADDITION */
    ob = call_other(this_player(), "wear", this_object());
    if(!ob) {
	worn_by = this_player();
	worn = 1;
	return 1;
    }
    write("You already have an armor of class " + type + ".\n");
write("Worn armor " + call_other(ob,"short") + ".\n");
    return 1;
}

get() { return 1; }

drop(silently) {
    if (worn) {
        call_other(worn_by, "stop_wearing", name);
	worn = 0;
	worn_by = 0;
	if (!silently)
	    tell_object(environment(this_object()),"You drop your worn armor.\n");
    }
    return 0;
}

remove(str) {
    if (!id(str))
	return 0;
    if (!worn) {
	return 0;
    }
    call_other(worn_by, "stop_wearing",name);
    worn_by = 0;
    worn = 0;
    return 1;
}

query_weight() { return weight; }

set_id(n) { name = n; }
set_name(n) { name = n; }
set_short(s) { short_desc = s; long_desc = s + ".\n"; }
set_value(v) { value = v; }
set_weight(w) { weight = w; }
set_ac(a) { ac = a; 
      set_ac_flag = 7; }
set_alias(a) { alias = a; }
set_long(l) { long_desc = l; }
set_type(t) {
   if (ac > 0 || !set_ac_flag) {
    if (t !="armor" && t !="helmet" && t != "boots" && t != "ring" && t !="amulet" && t != "shield" && t != "misc") 
    destruct (this_object());
     }
 type = t;
}
set_arm_light(l) { set_light(l); }
set_info(i) {
    info = i;
}

query_info() {
    return info;
}
take_off() {
   worn_by = this_player();
   worn_by = 0;
   worn = 0;
    return 1;
 }
save_thing(str){
     save_object(str);
     return 1;
  }
restore_thing(str){
      restore_object(str);
      return 1;
   }
set_save_flag(arg) {
save_flag = 1;
if(arg > 0) save_flag = arg;
 }
set_size(arg) {
    size = arg;
   }
query_size() { return size; }
find_size(plob) {
   int hf,pr,hi,we,sizew,sizeh,sizea;
   string ge;
   hf=plob->query_phys_at(1);
   hi=plob->query_phys_at(2);
   we=plob->query_phys_at(3);
   ge=plob->query_gender();
   pr=plob->query_pregnancy();
   if(ge == "male" || ge == "creature") {
     if(hf == 7) sizeh = 5;
     if(!sizeh && hf == 6 && hi > 6) sizeh = 5;
     if(!sizeh && hf == 6 && hi < 7) sizeh = 4;
     if(!sizeh && hf == 5 && hi > 6) sizeh = 3;
     if(!sizeh && hf == 5 && hi > 0) sizeh = 2;
     if(!sizeh) sizeh = 1;

     if(we > 250) sizew = 5;
     if(!sizew && we > 190) sizew = 4;
     if(!sizew && we > 150) sizew = 3;
     if(!sizew && we > 110) sizew = 2;
     if(!sizew) sizew = 1;
   }
   if(ge == "female") {
     if(hf > 6) sizeh = 5;
     if(!sizeh && hf == 5 && hi > 9) sizeh = 4;
     if(!sizeh && hf == 5 && hi > 2) sizeh = 3;
     if(!sizeh && hf == 5 && hi < 3) sizeh = 2;
     if(!sizeh) sizeh = 1;

     if(we > 220) sizew = 5;
     if(!sizew && we > 160) sizew = 4;
     if(!sizew && we > 130) sizew = 3;
     if(!sizew && we > 100) sizew = 2;
     if(!sizew) sizew = 1;
  }
   if(pr) {
    if(pr > 3000) sizew +=1;
    if(pr > 8100) sizew +=1;
    if(pr > 13000) sizew +=1;
   }
    sizea = (sizeh + sizew)/2;
/*
    write(sizeh+"-"+sizew+"-"+sizea+"-"+ge+"-"+hf+"-"+hi+"-"+we+"\n");
*/
    return sizea;
}
query_save_flag() {
    if(ac >1) {
      if(type=="boots" || type=="ring" || type=="amulet" || type=="misc" )
      return 1;
    }
    if(ac > 4) return 1;
return save_flag;
}
