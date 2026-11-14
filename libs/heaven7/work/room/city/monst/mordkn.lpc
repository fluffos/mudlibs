#include <mudlib.h>
inherit MONSTER;

void make_items();
void reset(status arg) {
  ::reset(arg);
  if(arg) make_items();

  else {
    set_name("mordenkainen");
    set_alias("archmage");
    set_al(30);
    set_short("Archmage Mordenkainen");
    set_long(
     "A great and powerful mage, Mordenkainen spends much time \n"+
     "pondering over new bits of magical research, or keeping  \n"+
     "his mind on the matters of the Council of High Magic,    \n"+
     "which he is the current leader.\n");
    set_gender(1);
    set_race("human");
    add_class("mage");
    add_class("cleric");
    load_spells(30,({ 
     "heal", "cure light wounds", "cure serious wounds", "poison",
     "lightning bolt", "chain lightning", "bbb", 
     "fire ball", "fire shield", "chill touch", "death spell",
     "disintegrate", "ice storm", "comet", "meteor swarm",
     "energy drain", "burning hands", "curse", "bless",
     "mks", "monster summon 1", "monster summon 2", "monster summon 3",
    }));
    add_spell_immunity("lightning");
    add_spell_immunity("cold");
    set_level(35);
    set_hp(3000);
    set_magic_resist(55);
    load_chat(5, ({ "Mordenkainen asks: What are you doing here?\n", 
     "Mordenkainen says: Leave me be.\n",
     "Mordenkainen ponders the complexities of a magical formula.\n",
     "Mordenkainen asks: Why do you bother me?\n",
     "Mordenkainen says: Leave me to my thoughts.\n",
     "Mordenkainen frowns.\n",
     "Mordenkainen thinks carefully.\n",
    }));
    load_a_chat(5, ({ "Mordenkainen exclaims: You will surely die!\n",
     "Mordenkainen exclaims: Leave now, and I will spare you!\n",
     "Mordenkainen says: I have warned you.\n",
     "Mordenkainen says: You will never beat my magical powers.\n",
     "Mordenkainen says: My magic is more powerful than you.\n",
    }));
    make_items();
  }
}

void make_items() {
  if(!present("robes")) {
    move_object(clone_object("room/city/obj/grobe"),this_object());
    command("wear robes", this_object());
  }
  set_ac(30);
  set_wc(30);
}
