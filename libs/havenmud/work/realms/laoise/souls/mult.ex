
#include <lib.h>
inherit LIB_SOUL;

static void create() {
        ::create();
        SetVerb("zaxan");
        SetRules("", "LIV");
        SetMessageVerbs( ([ "" : ({ "smell" }), "LIV" : ({ "think", "smell" }) ]) );
        SetMessages( ([
          ""        : "$agent_name $agent_verb funny.",
          "LIV"     : "$agent_name $agent_verb $target_name $target_verb funny.",
          ]) );
}
