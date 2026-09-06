#include <object.h>
#include <magic.h>
#include <item.h>
#include <condition.h>
#include <saveload.h>
#include <literacy.h>

string spell;
string author;
string label;
int level;	// skill points borrowed from author

string query_distant() {
  if (label)
    return ::query_distant() + " {" + label + "}";
  return ::query_distant();
}

string query_plural() {
  if (label)
    return ::query_plural() + " {" + label + "}";
  return ::query_plural();
}

string * query_alt_plural() {
  if (label)
    return ::query_alt_plural() + ({ label+" scrolls" });
  return ::query_alt_plural();
}

int on_label(string str) {
  if (label) {
    msg("The scroll is already labeled '"+label+"'!");
    return 0;
  }
  label = str;
  set_alt_name( ({ "magical scroll", label+" scroll" }) );
  return 1;
}

void create() {
  ::create();
  set_distant("a magical scroll");
  set_specific("the scroll");
  set_plural("scrolls");
  set_alt_plural( ({"scrolls", "magical scrolls"}) );
  set_name("scroll");
  set_alt_name( ({"magical scroll"}) );
  set_look("This is a magical scroll. Read it to determine what spell "+
           "it contains. Recite it to actually cast the spell.");
  set_gettable(1);
  set_droppable(1);
  set_bulk(1);
  set_weight(25);
  set_value(250);
  set_max_condition(1);
  set_condition(1);
  set_dest_on_break(1);
}

int on_break() {
  object room = environment(this_object());
  if (room->query_is_living())
     room = environment(room);
  set_actor(this_object());
  msg_room(room,"~CWRN~Name ~verbburst into flames and ~verbis gone!~CDEF");
  return 1;
}

string query_spell() { return spell; }
// can only set valid spells ;)
void set_spell(string str) {
  if (MAGIC_DAEMON->query_spell(str))
    spell = str;
  else
    debug("attempt to set invalid spell '"+str+"' on scroll.");
}

string query_author() { return author; }
// author must know the spell ;)
void set_author(object who) {
  if (!who) {
    debug("attempt to set null author on scroll.");
    return;
  }
  if (!who->query_is_living()) {
    debug("attempt to set non-living author '"+who+"' on scroll.");
    return;
  }
  if (!member(who->query_known_spells(),spell)) {
    debug("attempt to set stupid author '"+who+"' on scroll.");
    return;
  }
  author = who->query_name();
  level = who->query_skill("magic.technique.scribing") + who->query_skill("magic.item.scroll") / 2;
  move_object(this_object(),who);
}

int query_level() { return level; }

// returns a description of the power level of this scroll
string level_desc() {
  if (level < 10)
    return "pitiful";
  if (level < 25)
    return "very low";
  if (level < 50)
    return "mediocre";
  if (level < 75)
    return "high";
  if (level < 100)
    return "very high";
  if (level < 150)
    return "incredible";
  return "insane";
}

// called whenever this scroll is read
int on_read() {
   string buf;
   // eventually probably should make this use kn.arcana and/or arcane language
   int check = this_player()->skill_check("magic.item.scroll", 25, 50, 75);
   buf = "The scroll is covered in mystic runes.";
   if (label)
      buf += "\nIt is labelled '"+label+"'.";
   if ( check >= 1 ) {
      buf += "\nIt appears to be a '"+spell+"' spell.";
      if ( check >= 3 )
         buf += "\nThe scroll contains a "+level_desc()+" amount of power.";
      else
         buf += "\nYou are unable to determine the scroll's power level.";
      if ( check >= 2 )
         buf += "\nThe scroll is signed by "+capitalize(author)+".";
      else
         buf += "\nYou are unable to decipher the signature.";
   } else
      buf += "\nYou are unable to decipher any of the arcane writing.";
   msg(buf+"\n");
   return 1;
}

// called when the scroll is actually recited
void on_recite(mapping param) {
  object ob;
  if (!param["caster"]->query_is_living()) {
    debug("attempt by non-living object to recite scroll");
    return;
  }
  ob = MAGIC_DAEMON->query_spell(param["spell"]);
  ob->on_cast(param);

  param["caster"]->practice_skill_conditonal("magic.item.scroll",level,1);

  if (param["caster"]->skill_check("magic.item.scroll",max(level + 50, level * 2))) {
    msg("~CBRTYou focus your will and prevent the scroll from burning up!~CDEF");
  } else {
    set_actor(param["caster"]);
    param["caster"]->msg_local("~CWRN~Npos scroll is enveloped in a burst of flame and is gone.~CDEF");
    destruct(this_object());
  }
}
