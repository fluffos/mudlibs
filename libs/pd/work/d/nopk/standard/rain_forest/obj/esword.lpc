#include <std.h>
inherit WEAPON;

create() {
   ::create();
   set_name("sword");
   set_short("Excist's sword");
   set_id(({"sword"}));
   set_long("This sword was used by Excist when he was in the prime "
            "of his life. It still is very nice and could easily kill");
   set_wc(6);
   set_weight(18);
   set_type("blade");
   set_curr_value("gold", 120);
}
/* void weapon_hit() {
   object ob;
   if (this_player()->query_skill("blade") < 30) return;
   if (random(1) > random(1)) return;
   ob = this_player()->query_current_attacker();
   if (!ob) return;
   write("You slash your opponent with tremendous power");
   tell_room(environment(this_player()),
 ""+this_player()->query_cap_name()+
    " slashes "+this_player()->query_title_gender()+" opponent with "
     "tremendous power!", ({ ob, this_player() }));
   tell_object(ob,
""+this_player()->query_cap_name()+" slashes
 you powerfully "
     "with "+this_player()->query_title_gender()+"'s sword!");
   ob->damage(this_player()->query_skill("blade") + random(70));
}

int query_auto_load() { if (this_player()->query_skill("blade") >=
20) return
1; }


int weapon_hit(object ob) {
    int x, y;

    if((string)ob->query("race") != "god") return 1;
    y = random(10);
    x = (int)this_player()->query_alignment();
    if(x> 0) x = (x/100);
    else x = 0;
    y += x;
    write("you just hit him(test)");
    say(this_player()->query_cap_name()+" testing \n",
this_player());
    return y;
}


*/
