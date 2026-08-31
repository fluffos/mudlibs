#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("dragon");
    set_short("%^RESET%^%^BOLD%^an old healer dragon%^RESET%^");
    set_long("%^BOLD%^This white dragon is quite old and wise looking.  He seems to be upset, mumbling about an egg.");
    set_id(({"dragon", "healer dragon"}));
    set_level(300);
    set_race("dragon");
    set_body_type("dragon");
    set_gender("male");

}

void catch_tell(string str) {
string a, b;
    if(!str) return;
    str=lower_case(strip_colours(str));
    if(sscanf(str, "%s says: %s", a, b)!=2) return;
    if(sscanf(b, "%segg%s", a, str)==2) {
      force_me("say There is a dragon egg that is poisoned, or so I hear.  I bet some dragon healing salve would fix it up straight away.");
      return;
    }
    if(sscanf(b, "%ssalve%s", a, str)==2) {
      force_me("say Dragon healing salve is great.  You just mix together a jalisk flower, welterwort, crying damsel, white dittany, and bitterblossom.  You need to know how to %^BOLD%^combine %^RESET%^it though.");
      return;
    }
    if(sscanf(b, "%scombine%s", a, str)==2) {
      force_me("say If you <combine jalisk flower, welterwort, crying damsel, white dittany, and bitterblossom into dragon healing salve> you should be able to apply it to the egg and all will be good.");
      return;
    }
}

