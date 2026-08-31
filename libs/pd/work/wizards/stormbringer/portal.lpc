#include <std.h>
inherit OBJECT;
void create()
{
 ::create();
 set_name("portal");
 set_short("a glowing portal");
 set_id( ({ "portal" }) );
 set_long("A portal leading to hall destinations. To use the portal, <portal list> or <portal to [hall name]>.");
 set_prevent_get("The portal is not real!");
}
 
void init() {
 ::init();
   add_action("portal_to", "portal");
}
int portal_to(string str) {
    string dest, list;
 
    if (!str)
       return 0;
    if(sscanf(str, "to %*s"))
        sscanf(str, "to %s", str);
    if(str == "list") {
        list = "%^RESET%^%^BOLD%^  portal to\n%^RESET%^%^CYAN%^=+=+=+=+=+=+=+=+=+=+=+%^RESET%^\n";
        list += "  clergy\n";
          list += "  cleric\n";
          list += "  druid\n";
          list += "  kataan\n";
          list += "  monk\n";
        list += "  fighter\n";
          list += "  antipaladin\n";
          list += "  berserker\n";
          list += "  paladin\n";
          list += "  ranger\n";
          list += "  warrior\n";
        list += "  mage\n";
          list += "  necromancer\n";
          list += "  pyromancer\n";
          list += "  sorceror\n";
          list += "  wizard\n";
          list += "  rogue\n";
          list += "  assassin\n";
          list += "  scout\n";
        list += "  thief\n";
          list += "  thug\n";
        list += "  wanderer\n";
          list += "  bard\n";
          list += "  gypsy\n";
          list += "  jester\n";
          list += "  swashbuckler\n";
          list += "  archangel\n";
          list += "  demon\n";
       list += "  dragon\n";
        list += "  warwick\n";
        write(list);
        return 1;
    }
    switch(str) {
        case "clergy": dest = "/d/nopk/tirun/clergy_hall"; break;
        case "cleric": dest = "/d/nopk/tirun/clergy/cleric/cleric_hall"; break;
        case "druid": dest = "/d/nopk/tirun/clergy/druid/druid_hall"; break;
        case "kataan": dest = "/d/nopk/tirun/clergy/kataan/kataan_hall"; break;
        case "monk": dest = "/d/nopk/tirun/clergy/monk/monk_hall"; break;
        case "fighter": dest = "/d/nopk/tirun/fighter_hall"; break;
        case "antipaladin": dest = "/d/nopk/tirun/fighter/antipaladin/antipaladin_hall"; break;
        case "berserker": dest = "/d/nopk/tirun/fighter/berserker/berserker_hall"; break;
        case "paladin": dest = "/d/nopk/tirun/fighter/paladin/paladin_hall"; break;
        case "ranger": dest = "/d/nopk/tirun/fighter/ranger/ranger_hall"; break;
        case "warrior": dest = "/d/nopk/tirun/fighter/warrior/warrior_hall"; break;
        case "mage": dest = "/d/nopk/tirun/mage_hall"; break;
        case "necromancer": dest = "/d/nopk/tirun/mage/necromancer/necromancer_hall"; break;
        case "pyromancer": dest = "/d/nopk/tirun/mage/pyromancer/pyromancer_hall"; break;
        case "sorceror": dest = "/d/nopk/tirun/mage/sorceror/sorceror_hall"; break;
        case "wizard": dest = "/d/nopk/tirun/mage/wizard/wizard_hall"; break;
        case "rogue": dest = "/d/nopk/tirun/rogue_hall"; break;
        case "assassin": dest = "/d/nopk/tirun/rogue/assassin/assassin_hall"; break;
        case "scout": dest = "/d/nopk/tirun/rogue/scout/scout_hall"; break;
        case "thief": dest = "/d/nopk/tirun/rogue/thief/thief_hall"; break;
        case "thug": dest = "/d/nopk/tirun/rogue/thug/thug_hall"; break;
        case "wanderer": dest = "/d/nopk/tirun/wanderer_hall"; break;
        case "bard": dest = "/d/nopk/tirun/wand/bard/bard_hall"; break;
        case "gypsy": dest = "/d/nopk/tirun/wand/gypsy/gypsy_hall"; break;
        case "jester": dest = "/d/nopk/tirun/wand/jester/jester_hall"; break;
        case "swashbuckler": dest = "/d/nopk/tirun/wand/swashbuckler/swashbuckler_hall"; break;
        case "archangel": dest = "/wizards/inferno/angel/main"; break;
        case "demon": dest = "/d/freepk/merkkerri/demonquest/dquest115"; break;
        case "dragon": dest = "/d/nopk/tirun/dragon_hall"; break;
        case "warwick": dest = "/d/nopk/tirun/portal_room"; break;
    }
    if(dest) {
        write("You leap into the the portal!");
        say(this_player()->query_cap_name()+" leaps into the portal!");
        this_player()->move_player(dest, "into the portal");
        say(this_player()->query_cap_name()+" enters.");
    }
    return 1;
}
