int main(string str) {
   object obj;
   string tmp;

   if( !str ) {
      msg("You must tell me what you want to junk.");
      return 1;
   }

   obj = single_present(str, this_player());
   if( !obj ) {
      msg("You don't have any `"+str+"' to junk.");
      return 1;
   }
   set_target(obj);
   if (obj->query_is_living()) {
      msg("~CWRNHow the heck did you pick up one of those?! No, You can't throw ~prot away!~CDEF");
      return 1;
   }
   if (obj->query_kept()) {
      msg("~CWRNYou don't actually want to junk that.~CDEF");
      return 1;
   }
   if (obj->query_is_money()) {
      msg("~CWRNUm...you're crazy.~CDEF");
      return 1;
   }
   this_player()->msg_local("~CACT~Name ~verbjunk ~targ.~CDEF");
   destruct(obj);
// These rewards are EXTREMELY exploitable.
// Ask me if you don't get it. -- Acius
// gp:  Probably from picking up a pile of stuff and junking them one
// at a time en masse for healing spam

//   if (this_player()->query_hp() < this_player()->query_max_hp()) {
//     tmp = "hp"; this_player()->add_hp(1);
//   } else if (this_player()->query_mana() < this_player()->query_max_mana()) {
//     tmp = "mana"; this_player()->add_mana(1);
//   } else if (this_player()->query_endurance() < this_player()->query_max_endurance()) {
//    tmp = "endurance"; this_player()->add_endurance(1);
//   } else {
   msg("Thanks for being a good citizen and helping keep Walraven clean.");
   this_player()->add_lawful_alignment( 1 );
//     return 1;
//   }
//   msg("You have received one "+tmp+" for your trouble.\nThanks for helping keep Walraven clean.");
   return 1;
}
