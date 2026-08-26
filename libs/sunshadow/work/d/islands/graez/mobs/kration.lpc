#include <std.h>
#include <daemons.h>
#include "../graez.h"
inherit NPC;

int currentlist;

void create(){
   ::create();
   set_name("kration");
   set_id(({"kration","Kration","crafter","centaur crafter"}));
   set_short("Kration of the northern Steppes");
   set_long("\n");
   set_gender("male");
   set_alignment(4);
   set_race("centaur");
   set_class("fighter");
   set_hd(30,1);
   set_max_hp(300);
   set_hp(300);
   set("aggressive",0);
   currentlist = random(30)/10;
   command("speech speak in a gruff tenor");
   command("speak wizish");
}

void init() {
    ::init();
    add_action("my_listy","list");
    if(avatarp(TP) && TP->query_invis()) return 1;
    if(TP->query_invis()) return 1;
    if((int)TP->query_size() == 1 && TP->query_highest_level() > 20) {
      force_me("emote pulls set of greaves from one of the many piles.");
      force_me("say These humans know their armor, but they dont get us.");
      force_me("emote looks at the piles.");
      force_me("say nothing for those of us with four legs.");
      force_me("emote throws the pair of greaves back on the pile.");
      force_me("say I have supplies though.");
      force_me("say If you want to see the %^YELLOW%^list%^RESET%^ of what I want to trade.");
      force_me("emote produces a crumpled piece of paper from his cloak.");
    }
}

int my_listy(string str) {
    if(TP->query_invis() && !avatarp(TP)) {
      tell_object(TP,"Omthgar doesn't seem to notice you.");
      return 1;
    }

    if((int)TP->query_highest_level() < 21 && !avatarp(TP)) {
      force_me("emoteat "+TP->query_name()+" considers $N for a bit, but shakes "
"his head.");
      force_me("say You're not ready for this... Come back later.");
      force_me("emote turns away from you.");
      return 1;
    }
    force_me("emoteat "+TP->query_name()+" looks up from and offers "
"the page for $N to look over.");
    tell_object(TP,"\n%^RESET%^%^ORANGE%^On the paper is a list scrawled in "
"messy handwriting:%^RESET%^");
    switch(currentlist) {
      case 0:
      tell_object(TP,"%^YELLOW%^Robe of the Dragon, four times enchanted.  "
"%^WHITE%^Rumored to be obtained from the island of Tonerra.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Boots of Speed, five times enchanted.  "
"%^WHITE%^Rumored to be kept within the Demongate Tower.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Leather headpieces of various kinds, four "
"times enchanted.  %^WHITE%^Said to be often used by the beings of Argentrock "
"island.%^RESET%^\n");
      break;
      case 1:
      tell_object(TP,"%^YELLOW%^Chainmail of the Azure Seas, five times "
"enchanted.  %^WHITE%^Said to be found somewhere upon the island of "
"Attaya.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Pants of the Dervish, five times enchanted.  "
"%^WHITE%^Rumored to be obtained within the Crystalline Tower upon "
"Attaya.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Crown of the Shadow Dancer, twice "
"enchanted.  %^WHITE%^Last known to have been interred in the burial tombs "
"beneath Lothwaite.%^RESET%^\n");
      break;
      case 2:
      tell_object(TP,"%^YELLOW%^Shimmering Cape, five times enchanted.  "
"%^WHITE%^Reported as able to be obtained from within the Crystalline Tower "
"upon Attaya.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Mithril Mesh Gauntlets, five times enchanted"
".  %^WHITE%^Also believed to be found upon Attaya island.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Robes of Sunlight or Moonlight, thrice "
"enchanted.  %^WHITE%^Rumored to have last been obtained upon the island "
"of Ovadexel.%^RESET%^");
      tell_object(TP,"%^YELLOW%^Robes of Starlight or Nightmares, thrice "
"enchanted.  %^WHITE%^Also rumored to have last been obtained upon the island "
"of Ovadexel.%^RESET%^\n");
      break;
    }
    force_me("say If there's anything on there you can retrieve I can reward "+
	"you with something from my supply.");
    return 1;
}

void receive_given_item(object obj){
    string basename, *ids;
    if(!objectp(obj)) return;
    ids = obj->query_id();


    if((int)TP->query_highest_level() < 21 && !avatarp(TP)) {
      force_me("emoteat "+TP->query_name()+" considers $N for a bit, but shakes "
"his head.");
      force_me("say You're not ready for what I have, and I dont know "+
	  "how you got what you have, so go away till you're really ready.");
      force_me("emote puts the item back down on the table.");
      force_me("drop "+ids[0]);
      return 1;
    }
    basename = base_name(obj);
    force_me("emote inspects the garment with a crystal lense.");
    switch(currentlist) {
      case 0:
        if(basename == "/d/islands/tonerra/obj/mrobe") {
          if((int)obj->query_property("enchantment") != 4) {
            force_me("say The enchantments are wrong, I cant use this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Yes! This is perfect. There's an officer here who needs it.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJ"smallshirt")->move(TO);
          force_me("drop shirt");
          force_me("say Thank you. I hope you can use what I give you");
          return 1;
        }
        if(basename == "/d/dagger/marsh/tower/obj/speedboots") {
          if((int)obj->query_property("enchantment") != 5) {
            force_me("say The enchantments are wrong, I cant use this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Yes! This is perfect. There's an officer here who needs it.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJ"smallboots")->move(TO);
          force_me("drop boots");
          force_me("say Thank you. I hope you can use what I give you");
          return 1;
        }
        if(basename == "/d/common/obj/rand/rand_leath_head") {
          if((int)obj->query_property("enchantment") != 4) {
            force_me("say The enchantments are wrong, I cant use this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Yes! This is perfect. There's an officer here who needs it.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJ"smallhat")->move(TO);
          force_me("drop fedora");
          force_me("say Thank you. I hope you can use what I give you");
          return 1;
        }
        force_me("say I'm not looking for this today.  Read my "
"%^YELLOW%^>list<%^RESET%^ to know what I am looking for.");
        force_me("emote puts it back down on the table.");
        force_me("drop "+ids[0]);
        return 1;
      break;

      case 1:
        if(basename == "/d/attaya/obj/azure") {
          if((int)obj->query_property("enchantment") != 5) {
            force_me("say The enchantments are wrong, I cant use this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Yes! This is perfect. There's an officer here who needs it.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJ"smallchain")->move(TO);
          force_me("drop chain");
          force_me("say Thank you. I hope you can use what I give you");
          return 1;
        }
        if(basename == "/d/attaya/obj/shorts") {
          if((int)obj->query_property("enchantment") != 5) {
            force_me("say The enchantments are wrong, I cant use this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Yes! This is perfect. There's an officer here who needs it.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJ"smallpants")->move(TO);
          force_me("drop pants");
          force_me("say Thank you. I hope you can use what I give you");
          return 1;
        }
        if(basename == "/d/barriermnts/lothwaite/obj/shadow_circlet") {
          if((int)obj->query_property("enchantment") != 2) {
            force_me("say The enchantments are wrong, I cant use this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Yes! This is perfect. There's an officer here who needs it.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJ"smallberet")->move(TO);
          force_me("drop beret");
          force_me("say Thank you. I hope you can use what I give you");
          return 1;
        }
        force_me("say I'm not looking for this today.  Read my "
"%^YELLOW%^>list<%^RESET%^ to know what I am looking for.");
        force_me("emote puts it back down on the table.");
        force_me("drop "+ids[0]);
        return 1;
      break;

      case 2:
        if(basename == "/d/attaya/obj/shimmeringcape") {
          if((int)obj->query_property("enchantment") != 5) {
            force_me("say The enchantments are wrong, I cant use this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Yes! This is perfect. There's an officer here who needs it.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJ"smallcloak")->move(TO);
          force_me("drop pendant");
          force_me("say Thank you. I hope you can use what I give you");
          return 1;
        }
        if(basename == "/d/attaya/obj/bish_gauntlets") {
          if((int)obj->query_property("enchantment") != 5) {
            force_me("say The enchantments are wrong, I cant use this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Yes! This is perfect. There's an officer here who needs it.");;
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          obj->remove();
          new(OBJ"smallgauntlets")->move(TO);
          force_me("drop gauntlets");
          force_me("say Thank you. I hope you can use what I give you");
          return 1;
        }
        if(basename == "/d/islands/dreams/obj/moonlight_robe" || basename == "/d/islands/dreams/obj/sunlight_robe") {
          if((int)obj->query_property("enchantment") != 3) {
            force_me("say The enchantments are wrong, I cant use this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Yes! This is perfect. There's an officer here who needs it.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          new(OBJ"smallmrobe")->move(TO);
          force_me("drop robe");
          force_me("say Thank you. I hope you can use what I give you");
          return 1;
        }
        if(basename == "/d/islands/dreams/obj/starrobe" || basename == "/d/islands/dreams/obj/nightmare_robe") {
          if((int)obj->query_property("enchantment") != 3) {
            force_me("say The enchantments are wrong, I cant use this.");
            force_me("emote puts it back down on the table.");
            force_me("drop "+ids[0]);
            return 1;
          }
          force_me("say Yes! This is perfect. There's an officer here who needs it.");
          force_me("emoteat "+TP->query_name()+" stashes it away, and pulls out "
"another garment which he puts on the table before $N.");
          new(OBJ"smallmrobe2")->move(TO);
          force_me("drop robe");
          force_me("say Thank you. I hope you can use what I give you");
          return 1;
        }
        force_me("say I'm not looking for this today.  Read my "
"%^YELLOW%^>list<%^RESET%^ to know what I am looking for.");
        force_me("emote puts it back down on the table.");
        force_me("drop "+ids[0]);
        return 1;
      break;
    }
    force_me("say I'm not looking for this today.  Read my "
"%^YELLOW%^>list<%^RESET%^ to know what I am looking for.");
    force_me("emote puts it back down on the table.");
    force_me("drop "+ids[0]);
    return 1;
}
