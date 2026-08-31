
inherit WEAPON;

#define MY_MSG		({"%^BOLD%^RED%^Soulburner tells you: %^RESET%^Let darkness embrace you.",\})

#define YOUR_MSG	({"%^BOLD%^BLACK%^"+env->query_cap_name()+" is momentarily enveloped in dark flowing flames.",\})


int weapon_hit();
create() {::create();;set_id(({"axe", "axe of omah", "soulburner", "battleaxe"}));;set_short("%^BOLD%^GREEN%^A%^RESET%^GREEN%^xe of %^BOLD%^O%^RESET%^GREEN%^mah%^RESET%^");;set_name("soulburner");;set_long("The Axe of Omah, or soulburner as it is sometimes called, is a short handled battleaxe measuring less than half a meter in length.  The blade is simple in design, with little curve and a shape similar to that of a hatchet.  The chrome metal is extremely reflective and has a soft green glow while the handle is wrapped in heavy black leather and hilted with a small human skull.");;set_weight(10);;set_value(300);;set_wc(8);;set_ac(0);;set_type("axe");;set_hands(1);;set_wield("%^BOLD%^GREEN%^HAUNTING%^RESET%^GREEN%^ visions of the Mjharr'a dead fill your mind.");;set_hit((:this_object(),"weapon_hit":));}


void init() {
init();
set_heart_beat(5);

}
void heart_beat() {
int x;
object env;
if(env=environment())
if(living(env)) {
message("info", "%^BOLD%^RED%^Soulburner tells you:%^RESET%^ Let darkness embraces you...", env);
message("info", "%^BOLD%^BLACK%^"+env->query_cap_name()+" is momentarily enveloped by dark flowing flames.", environment(env),env); 
this_player()->add_hp(this_player()->query_level());
this_player()->add_sp(this_player()->query_level());
this_player()->add_mp(this_player()->query_level());
}
}

int weapon_hit()
{
int result;
object atk;
if(random(175) > 155) {write("The figurines upon the staff writhe in agony!\nAfter a flash of blue;light, you feel more revitalized!");;say("The figurines upon "+(string)this_player()->query_cap_name()+"'s staff;writhe in agony!\nAfter a flash of blue light,;"+this_player()->query_cap_name()+" looks revitalized. ");;result=(this_player()->query_skill("magic;attack")/4+(random(this_player()->query_stats("intelligence"))));;this_player()->add_mp(result);;return result;}
}
int query_auto_load() {if(this_player()->query_class() != "fighter") return 0;;if(this_player()->query_level() < 30) return 0;;return 1; }
