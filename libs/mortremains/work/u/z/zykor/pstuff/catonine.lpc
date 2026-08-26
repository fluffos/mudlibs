// cat_o_nine_tails.c
// Jakal@Shadows (Zykor)
// unique

#include <mudlib.h>
inherit WEAPON ;

void create() {
set ("author", "Zykor");
set("damage", ({ 12,18 }) );
set_weapon_type("whip");
set ("id", ({ "cat o nine tails", "cat o nine", "cat" }) ) ;
set ("short", "a cat-o-nine-tails") ;
set ("long", "This flail has nine long strands of black leather, each with sharp barbs in"+
" them. Strange how each one the nine pieces of leather seem almost alive.\n") ;
set_verbs( ({ "smack", "whack", "pound" }) ) ;
	set_verbs2( ({ "smacks", "whacks", "pounds" }));
	set("second", 0) ;
	set("nosecond", 0) ;
  set ("hit_func", "hit_function");
}

void hit_function() {
int chance, i;
string hisname;
object him;


him = this_player()->query_current_attacker();
if(!present(him,environment(this_player()))) return 1;
hisname = capitalize(him->query("name"));


chance = random(50);
switch(chance){

case 0..1 : {
	return 1;
	break;
}

case 2..9 : {

for(i = 0;i < chance;i++){
	write("One of the tails of the cat-o-nine comes alive and thrashes "+
		hisname + " wickedly!\n");
	say("One of the tails of the cat-o-nine comes alive and thrashes "+
		hisname + " wickedly!\n");
	him->receive_damage(random(4)+4);
}
if(chance == 9){
	write("The barrage leaves " + hisname + " stunned momentarily.\n");
	say("The barrage leaves " + hisname + " stunned momentarily.\n");
	him->block_attack(4) ;
}
	return 1;
	break;
}
case 10..49 : {
	return 1;
	break;
}
}

}
