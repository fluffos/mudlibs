	/* Bat of Correction */

inherit "obj/weapon";

reset(arg)  {
    ::reset();
    if(arg) return;

set_name("bat");
set_alias("slugger");
set_short("Wren's Bat of Corrections");
set_long("A massive bat to correct the wayward players.  \n");

set_type("bat");   /*sword,knife,club,axe,bow,polearm */
set_class(22);
set_weight(1);
set_value(100);
set_hit_func(this_object());

}

weapon_hit(attacker) {
int W;
W = random(13);
if(W>9)  {
    say(" SPLAT. \n");
    write(" You FLATTEN THEM. \n");
    return 100;
          }
return;
}
