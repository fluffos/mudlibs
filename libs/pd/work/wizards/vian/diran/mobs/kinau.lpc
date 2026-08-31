#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("kinau");
    set_short("%^RESET%^%^BOLD%^Kinau, the High Priest of Diran%^RESET%^");
    set_long("Kinau is an old yet sturdy dwarf.  He seems to be worried about a stolen <ruby>.  Maybe you should ask him about it?");
    set_id(({"kinau", "high priest"}));
    set_level(100);
    set_race("dwarf");
    set_body_type("dwarf");
    set_gender("male");
    set_emotes(10, ({
      "Kinau frantically circles the tall circular stone.",
      "Kinau paces back and forth.",
      "%^CYAN%^Kinau mumbles to himself: %^RESET%^Why, why, WHY?",
"%^CYAN%^Kinau looks up and says wisely: %^RESET%^As a tale, so is life; not how long it is, but how good it is, is what matters.",
      "Kinau throws his hands up to the heavens in complete despair.",
    }), 0);
 
}

void catch_tell(string str) {
string a, b;
    if(!str) return;
    str=lower_case(strip_colours(str));
    if(sscanf(str, "%s says: %s", a, b)!=2) return;
    if(sscanf(b, "%sruby%s", a, str)==2) {
      force_me("say A Duergar has stolen the holy ruby which keeps peace in our village.  I have heard rumor that he is hidden in a secret <shack> in the Tundra.");
      return;
    }
    if(sscanf(b, "%sshack%s", a, str)==2) {
      force_me("say The shack is hidden away in the tundra, I believe it may be hard to find.  Please find and kill this Duergar, and bring my ruby <back>.");
      return;
    }
    if(sscanf(b, "%skey%s", a, str)==2) {
      force_me("emote checks his pockets.");
      force_me("say Oh my god! I have lost the keys again???");
      return;
    }
    if(sscanf(b, "%squest%s", a, str)==2) {
      force_me("say We need HELP!  A Duergar has stolen the holy ruby which keeps peace in our village.");
      force_me("cry");
      return;
    }
        if(sscanf(b, "%sback%s", a, str)==2) {
      force_me("say When you make your way to me with the ruby, you will be able to <insert> it into the circular stone holder here with me in the church.");
      return;
    }
    if(sscanf(b, "%shi%s", a, str)==2) {
      force_me("emote smacks you.");
      force_me("say THE RUBY HAS BEEN STOLEN! TELL ME WHAT YOU KNOW!!!!");
      return;
    }

}
