// SEEKER!
// a dungeonware.net hack by Stormy
#include <daemons.h>
inherit DAEMON;
int abil();
#define tp this_player()
string *charging;
void create(){
    ::create();
    charging = ({});
}
int cmd_charge(string str){
    object ob, p;
    int i;
    p=this_player();
    if (this_player()->query_class()!="fighter"){
	write("What?\n");
	return 1;
    }
    if (!abil()) {
	notify_fail("What?");
	return 0;
    }
    if (!str || str==""){
	write("Charge what?");
	return 1;
    }
    if (this_player()->query_race()!="centaur" && this_player()->query_race()!="weimic" &&
      !this_player()->query_riding()){
	write("You are not in a position to charge.");
	return 1;
    }
    if(this_player()->query_current_attacker()) {
	write("You are already in combat with something else!\n");
	return 1;
    }
    ob = present(str, environment(this_player()));
    if (!ob){
	write("You dont see that anywhere in sight.");
	return 1;
    }
    if (member_array(ob, this_player()->query_hunted()) != -1)
	return notify_fail("You are already in combat with that.\n");
    if(ob == this_player()) {
	write("I think you need to see a doctor?");
	return 1;
    }
    if(ob == this_player()->query_riding()) {
	write("You planning on getting off your mount and charging it on foot?");
	return 1;
    }
    if(this_player()->query_sp() < 100) {
	write("You are too tired to charge.\n");
	return 1;
    }  
    if (this_player()->query_ghost()){
	write("You are not in a position to charge.");
	return 1;
    }
    if(ob->query_ghost()) {
	write("Charge a ghost? I think not.");
	return 1;
    }
    if(!living(ob)){
	write("You cannot charge that.");
	return 1;
    }
    if (this_player()->query_disable())
	return notify_fail("You are busy.\n");
    if (environment(ob)->query_property("no attack")){
	write("You cannot charge in such a peaceful place.");
	return 1;
    }
    i = sizeof(charging);
    while (i--){
	if (charging[i]==this_player()->query_name()){
	    write("You are already charging something.");
	    return 1;
	}
    }
    if (!charging) charging = ({ this_player()->query_name() });
    else
	charging += ({ this_player()->query_name() }); 
    write("You charge toward "+capitalize(ob->query_name())+".");
    message("charge", this_player()->query_cap_name()+" charges toward "+ capitalize(ob->query_name())+".", environment(this_player()),  ({ ob, this_player() }));
    message("charge", this_player()->query_cap_name()+" charges toward you.", ob);
    this_player()->set_disable();
    if (this_player()->query_mounted() && this_player()->query_mounted()->query_class()=="fighter")
	this_player()->query_mounted()->set_disable();
    if(this_player()->query_race() != "centaur"){
	call_out("charge_hit", 3, ob);
	call_out("disabler", 1, tp);
    }else
	call_out("charge_hit", 2, ob);
    return 1;
}
void disabler(object p) {
    p->set_disable();
}
void do_charge_message(float perc, string name, string limb, object ob){
    string a,b;
    if (perc < 0.1){
	a = "%^GREEN%^scraped%^RESET%^";
	b = "%^GREEN%^barely%^RESET%^";
    }
    else
    if (perc >= 0.6){
	a = "%^BOLD%^%^RED%^destroyed%^RESET%^";
	b = "%^BOLD%^%^RED%^utterly%^RESET%^";
    }
    else
    if (perc >= 0.5){
	a = "%^WHITE%^%^BOLD%^destroyed%^RESET%^";
	b = "%^WHITE%^%^BOLD%^terribly%^RESET%^";
    }
    else
    if (perc >= 0.3){
	a = "%^ORANGE%^%^BOLD%^mutilated%^RESET%^";
	b= "%^ORANGE%^%^BOLD%^horribly%^RESET%^";
    }
    else
    if (perc >= 0.2){
	a = "%^ORANGE%^sliced%^RESET%^";
	b = "%^ORANGE%^badly%^RESET%^";
    }
    else
    if (perc >= 0.1){
	a = "%^GREEN%^%^BOLD%^knicked%^RESET%^";
	b = "%^GREEN%^%^BOLD%^barely%^RESET%^";
    }
    write("Your charge "+a+" "+name+" "+b+" in the "+limb+".");
    message("info",  
      this_player()->query_cap_name()+"s charge "+a+" "+name+" "+b+" in the "+limb, 
      environment(this_player()), ({ this_player(), ob }) );
    message("info",
      this_player()->query_cap_name()+"s charge "+a+" You "+b+" in the "+limb, ob );
}
int charge_hit(object ob){
    int a, dam, b, cha;
    float c;
    string target_thing;
    int wc, i, tmp;
    object *weap, moun;
    charging -= ({ this_player()->query_name() });
    if (!ob) return 1;
    if (environment(this_player())!=environment(ob)){
	write("Your opponent is out of range.");
	return 1;
    }
    if (environment(ob)->query_property("no attack"))
	return 1;
    weap = (object *)this_player()->query_wielded();
    for(i=0, tmp = sizeof(weap); i<tmp; i++) {
	if((string)weap[i]->query_type() != "blade" &&
	  (string)weap[i]->query_type() != "axe" &&
	  (string)weap[i]->query_type() != "knife") continue;
	if (wc < weap[i]->query_wc()) wc = weap[i]->query_wc();
    }
    if (!wc){
	write("You trot around your opponent.");
	this_player()->add_sp(-(random(50)+50));
	return 1;
    }
    if (this_player()->query_race()=="centaur"|| this_player()->query_race()=="weimic")
	cha = this_player()->query_skill("charging");
    else cha = (this_player()->query_skill("riding")*10)/15;
    a = ( (this_player()->query_stats("dexterity")*5+this_player()->query_stats("strength")*5) -
      (ob->query_stats("dexterity")*3/2 + ob->query_stats("intelligence")) +
      (cha*4) - (ob->query_skill("defense")*3/2)-(random(ob->query_level()/5)) 
      + (random(this_player()->query_level()/4)) 
    );

    dam = (cha*5) + (this_player()->query_stats("strength")*3 +
      this_player()->query_stats("dexterity")*4) -
    (ob->query_stats("strength")*3/2) -
    (ob->query_skill("defense")*2/3 + ob->query_stats("dexterity")*2/3)+
    wc*28/2;
    moun = this_player()->query_mounted();
    if (this_player()->query_mounted() && this_player()->query_mounted()->query_class()=="fighter"){
	weap = (object *)this_player()->query_wielded();
	for(i=0, tmp = sizeof(weap); i<tmp; i++) {
	    if((string)weap[i]->query_type() != "blade" &&
	      (string)weap[i]->query_type() != "axe" &&
	      (string)weap[i]->query_type() != "knife") continue;
	    if (wc < weap[i]->query_wc()) wc = weap[i]->query_wc();
	}
	if (wc) {
	    dam += moun->query_stats("strength")*2+
	    moun->query_stats("dexterity")*3-
	    ob->query_stats("dexetrity") -
	    ob->query_skill("defense")/2 + ob->query_stats("dexterity")/2+
	    moun->query_skill("riding")*2;
	}
    }
    if (a < -random(250) && !ob->query_paralyzed() && !present("pillow", ob)){
	write("You miss your charge.");
	say( this_player()->query_cap_name()+" misses his charge.");
	this_player()->add_sp(-(random(75)+50));
	if(this_player()->query_mounted())
	    this_player()->query_mounted()->add_sp(-(random(75)+50));
	if(!this_player()->kill_ob(ob, 0)) return 1;
	return 1;
    }
    target_thing = (string)ob->return_target_limb();
    a = ob->query_hp();
    b = ob->query_hp() -dam;
    c = b - a;
    if(a != 0)
	c = c / a;
    if (c < 0) c = -c;
    if (this_player()->query_mounted())  
	if (this_player()->query_mounted()->query_class()=="fighter"){
	    if(!this_player()->query_mounted()->kill_ob(ob)) {
		write(ob->query_cap_name()+" can't be attacked by you yet.");
		return 1;
	    }
	    write("With the aid of "+this_player()->query_mounted()->query_cap_name()+", your charge hits with more force.");
	    message("info", this_player()->query_cap_name()+"'s charge hits with more force due to the aid of "+this_player()->query_mounted()->query_cap_name()+".", this_player(), environment(this_player()));
	    dam *=10/9;
	    this_player()->query_mounted()->add_sp(-dam/8);
	}
    if(!this_player()->kill_ob(ob)) {
	write(ob->query_cap_name()+" can't be attacked by you yet.");
	return 1;
    }
    do_charge_message(c, capitalize(ob->query_name()), target_thing, ob);
    ob->do_damage(target_thing, dam*3/4);
    ob->check_on_limb(target_thing);
    this_player()->add_sp(-dam/6);
    return 1;
}
void help(){
    write("Syntax: charge <living>\n"
      "This is an ability a centaur/satyr or any fighter riding "
      "a horse can do. You charge at your enemy with your weapon, "
      "and do massive damage if you hit. This you can only do if "
      "your not in combat.");
}
int abil() {
    object tpp;
    tpp = this_player();
    if (!tpp) return 0;
    if (tpp->query_class() != "fighter") return 0;
    if (tpp->query_race() == "raknid") return 0;
    if (tpp->query_level() < 10) return 0;
    return 1;
}
