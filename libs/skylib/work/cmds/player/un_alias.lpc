inherit COMMAND_BASE;

/**
 * This method allows a single alias to be removed.
 * Only doable by self or a lord
 * @param str the name of the alias to remove
 * @return 1 on success, 0 on failure
 */
varargs int unalias(string str, object who ) {
    if (!who) who = this_player();
   if (!who->is_alias(str)) {
      add_failed_mess("The alias '" + str + 
                      "' does not exist, cannot unalias.\n");
      return 0;
   }
   if (who->remove_player_alias(str)) {
      write("Successfully unaliased '" + str + "'.\n");
      return 1;
   } else {
      add_failed_mess("Unable to unalias '" + str + "'.\n");
      return 0;
   }
} /* unalias() */

mixed *query_patterns() {
   return ({
      "<word'alias'>", (: unalias($4[0]) :),
         });
} /* query_patterns() */
