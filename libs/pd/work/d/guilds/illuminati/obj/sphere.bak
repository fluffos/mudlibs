#include <std.h>
#include <locations.h>
inherit OBJECT;

string envname, envlong, envpath;
int ok;

void create() {
   ::create();
     set_id(({"sphere", "glass", "glass sphere"}));
     set_name("glass sphere");
     set_long("A perfect sphere of glass. The inside is flawless and so clear as to be almost invisible.");
     set_short("%^BOLD%^WHITE%^a G%^RESET%^l%^BOLD%^a%^RESET%^s%^BOLD%^s %^RESET%^s%^BOLD%^p%^RESET%^h%^BOLD%^e%^RESET%^r%^BOLD%^e%^RESET%^");
     set_weight(1);
     set_curr_value("gold", 500);
     set_property("magic item", ({"mark", "smash"}) );
}

void init() {
   ::init();
     if(ok)
       add_action("breakin", "smash");
     else
       add_action("markin", "mark");
}

int markin(string str) {
    object tp, env;
    tp = this_player();
    if(tp->query_guild() != "illuminati")
      return 0;
    if(environment(this_object()) != tp)
      return notify_fail("You have to get the sphere first.\n");
    if(!str || str == "")
      return notify_fail("You must give a name for the location.\n");
    if(sscanf(str,"%*s %*s") == 2)
       return notify_fail("Use only one word to mark the sphere.\n");

    env = environment(tp);

    if(env->query_property("no teleport"))
      return notify_fail("You concentrate, but the sphere cannot focus.\n");

    envname = str;
    envlong = env->query_long();

    add_action("breakin", "smash");
    remove_action("markin", "mark");

    message("info", "\n%^BOLD%^WHITE%^You focus on the sphere and it slowly fills with a light mist.%^RESET%^\n", tp, );

    set_short("%^BOLD%^WHITE%^a G%^RESET%^l%^BOLD%^a%^RESET%^s%^BOLD%^s %^RESET%^s%^BOLD%^p%^RESET%^h%^BOLD%^e%^RESET%^r%^BOLD%^e ("+envname+")%^RESET%^");
    set_long("A perfect sphere of glass. The inside is filled with a white mist, it slowly coalesces into an image:\n\n"+envlong+"\n");
    set_id(({"sphere", "glass", "glass sphere", envname}));
    envpath = base_name(env);
    ok = 1;
    return 1;
}

int breakin(string str) {
    object tp, env;
    tp = this_player();
    if(tp->query_guild() != "illuminati")
      return 0;
    if(environment(this_object()) != tp)
      return notify_fail("You have to get the sphere first.\n");
    if(present(str, tp) != this_object())
      return notify_fail("Smash what?");
    if(environment(tp)->query_property("no teleport") || tp->query_arena())
      return notify_fail("You cannot use the sphere in this place.\n");
    if(tp->query_current_attacker())
      return notify_fail("You are too busy fighting!");
    env = load_object(envpath);
    message("info", "%^BOLD%^WHITE%^You heft the sphere above your head, then smash it on the ground.%^RESET%^", tp, );
    message("info", "%^BOLD%^WHITE%^"+tp->query_cap_name()+" holds a glass sphere over his head, then abruptly smashes it on the ground.%^RESET%^", environment(tp), tp);
    message("info", "%^BOLD%^WHITE%^A white mist begins to form.%^RESET%^", env, );
    remove_action("breakin", "smash");
    this_object()->move(TEMP_LOC);
    call_out("goingalready", 6, tp);
    return 1;
}

int goingalready(object tp) {
    object env;
    env = load_object(envpath);
    message("info", "\n%^BOLD%^WHITE%^A white mist engulfs you!%^RESET%^\n", tp);
    message("info", "%^BOLD%^WHITE%^A white mist engulfs "+tp->query_cap_name()+"!%^RESET%^", environment(tp), tp);
    tp->move_player(env);
    message("info", "%^BOLD%^WHITE%^The mist subsides.%^RESET%^", env, );
    this_object()->remove();
    return 1;
}

mixed *query_auto_load() {
    if (this_player()->query_level() >= 20 && this_player()->query_guild() == "illuminati")
      return ({"/d/guilds/illuminati/new/sphere.c", ({envname, envlong, envpath, ok}) });
    else
      return 0;
}

void init_arg(mixed *stuff) {
    envname = stuff[0];
    envlong = stuff[1];
    envpath = stuff[2];
    ok = stuff[3];
    if(ok) {
      set_short("Glass sphere ("+envname+")");
      set_long("A perfect sphere of glass. The inside is filled with a white mist, it slowly coalesces into an image:\n\n"+envlong+"\n");
      set_id(({"sphere", "glass", "glass sphere", envname}));
    }
}

int is_sphere() {
    return 1;
}

mixed *query_props() {
      mixed *vars;
      vars = ({envname, envlong, envpath, ok });
      return vars;
}
