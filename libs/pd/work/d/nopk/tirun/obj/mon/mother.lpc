#include <std.h>
#include <tirun.h>

inherit MONSTER;

void check_quest(string *what);

void create() {
    ::create();
   set_name("frantic mother");
   set("id",  ({ "mother", "frantic mother", "monster" }) );
   set("short", "A frantic mother");
   set("aggressive", 0);
   set_level(12);
   set("long", "This mother is frantic about her poor son, who is badly injured.");
   set_alignment(1000);
   set("race", "human");
   set_body_type("human");
   set_gender("female");
   set_emotes(2,({ "%^RESET%^%^CYAN%^The frantic mother exclams:%^RESET%^ Oh my son!  Will you please help me??" }),0);
}
void catch_tell(string str) {
    object ob;
    string a, b;

    if(this_player() == (ob = this_object())) return;
    if((sscanf(str, "%squest%s", a, b) == 2) || (sscanf(str, "%shelp%s", a, b) == 2)) {
        this_object()->force_me("say You want to help???  Please tell the hospital!");
        this_object()->force_me("say Tell them that the Hosseldorf family needs help.");
        this_object()->force_me("say They'll know where to find us.  Please hurry!");
        return;
    }
}
