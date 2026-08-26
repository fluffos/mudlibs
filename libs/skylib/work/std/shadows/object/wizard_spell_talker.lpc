/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: wizard_spell_talker.c,v 1.1 2000/06/08 01:48:53 pinkfish Exp $
 * $Log: wizard_spell_talker.c,v $
 * Revision 1.1  2000/06/08 01:48:53  pinkfish
 * Initial revision
 *
 * Revision 1.1  1998/01/06 04:40:23  ceres
 * Initial revision
 * 
*/
inherit "/std/effect_shadow";

int query_collection_channel_number() { return coll_num; }
 
void set_collection_num(int num) { coll_num = num; }
 
void handle_collection_message(object orig, int coll_mess, string mess) {
  if (interactive(environment(player))) {
    tell_object(environment(player),
    sprintf("%s (%s) fluff's: %-=*s\n", player->short(), orig->one_short(),
                (int)environment(player)->query_cols()-7-strlen((string)player->sh
ort()), mess));
  }
} /* handle_collection_message() */
 
string long(string str, int dark) {
  return player->long(str, dark)+
         "\nIt glows a slight red colour, maybe you can 'fluff' things "+
         "into it?\n";
} /* long() */
 
void init() {
  player->init();
  this_player()->add_command("fluff", player, "'into' %D 'message' %s");
} /* init() */
 
int command_control(string verb, object *in_dir, string id_arg, 
                    string ii_arg, string *args, string pattern) {
  if (verb != "fluff") {
    return (int)player->command_control(verb, in_dir, id_arg, ii_arg, args, 
                                       pattern);
  }
  COLLECTION_CONT->send_message(this_player(), coll_num, args[1]);
  this_player()->add_succeeded_mess(player, "$N fluff's into $D.\n", ({ }));
  return 1;
} /* command_control() */
