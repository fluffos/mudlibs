#include <magic.h>

string query_action_name() { return "Scribe"; }

int main(string arg) {
   string spell, paper;
   object ob;

/*
   // temporary ban on scrolls
   msg("~CBRTSorry, but scrolls are currently disabled while magical objects "+
       "receive something of a major makeover.~CDEF");
   return 1;
*/

   if ( !arg || sscanf(arg,"%s onto %s",spell,paper) != 2 ) {
      notify_fail("Usage: scribe <spell> onto <paper>\n");
      return 0;
   }
   if ( !member(this_player()->query_known_spells(), spell) ) {
      notify_fail("You don't know that spell in order to scribe it.\n");
      return 0;
   }
   ob = single_present(paper, this_player(), (:$1->query_location("front")==""||$1->query_num_pages()>1:) );
   if (!ob) {
      if (ob = single_present(paper, environment(this_player())) )
         notify_fail("You must be holding "+ob->query_specific()+" in order to scribe onto it.\n");
      else
         notify_fail("Can't find any such blank sheet of paper '"+paper+"' to scribe onto.\n");
      return 0;
   }

   if (ob->query_location("front") != "" && !ob->query_num_pages()) {
      notify_fail("You must have a blank sheet of paper in order to scribe a spell.\n");
      return 0;
   }

   if( ob->query_num_pages() && ob->query_spell() ) {
      notify_fail("That book isn't open to an empty page.\n");
      return 0;
   }

   spell = MAGIC_DAEMON->query_spell(spell);
   if (this_player()->query_mana() < spell->query_cost() * 2) {
      notify_fail("You don't have enough mana to scribe this spell.\n");
      return 0;
   }

   this_player()->push_action( ({
                                 1000,
                                 this_object(),
                                 ob,	// paper to scribe onto
                                 ST_STANDING,
                                 spell
                               }) );

   return 1;
}

void on_action(object paper, mixed spell) {
   if (environment(paper) != this_player()) {
      msg("You must be holding the paper to scribe onto it!");
      return;
   }
   if (this_player()->query_mana() < spell->query_cost() * 2) {
      msg("You don't have enough mana to scribe this spell.");
      return;
   }
   AUDIO_DAEMON->sfx_room( environment(this_player()), "write.wav" );
   // since we have variable requirements, set don't add...
   this_player()->add_readiness(-1000);
   MAGIC_DAEMON->draw_mana(this_player(), spell->query_type(), spell->query_cost() * 2);
   this_player()->msg_local("~CACT~Name ~verbscribe a spell "+(paper->query_num_pages()?"onto page "+paper->query_current_page()+" of":"onto")+" ~targ.~CDEF");
   this_player()->practice_spell(spell->query_name(),1.5);
   this_player()->practice_skill_conditional( "magic.technique.scribing", spell->query_level() * 25 + 20, max(spell->query_cost() / 5, 1) );
   this_player()->practice_skill_conditional( "magic.item.scroll", spell->query_level() * 20 + 10, min(spell->query_cost() / 10, 2) );
   if( !paper->query_num_pages() ) {
     paper->remove();
     if (paper)
     	destruct(paper);
     paper = clone_object("/magic/obj/scroll");
   }
   paper->set_spell(spell->query_name());
   paper->set_author(this_player());
}
