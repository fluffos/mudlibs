#include "std.h";
int injections, price;

id(str) { return str == "bag"; }

reset(arg) {
	if (!arg) injections = 10;
	price = injections * 200;
}

long() {
   write("This is a bag of blood donated by some creature of unknown\n"+
         "origin. It might be good to 'inject' it though.\n");
}

short() {
   return "A bag of blood";
}

query_value()
{
    return price;
}

init() {
   add_action("do_inject", "inject");
}

do_inject(arg) {
object tp;
tp = this_player();
if(!tp->drink_alcohol(14)){
	return 1;
}else{
   if(arg == "blood" || arg == "") {
injections=injections - 1;
this_player()->heal_self(40);
write("You wince as you slide the thick needle in a swollen vein. There\n"+
      "is enough blood for "+injections+" left in the bag.\n");
say(capitalize(tp->query_name()) + " grits their teeth as the needle slides into a vein.\n");
if(injections == 0){
	destruct(this_object());
write("The blood bag is empty and disappears.\n");
		}
return 1;
		}
	}
}

get() {
    return 1;
}
query_save_flag(){return 1;}

query_weight() {
    return 2;
}
