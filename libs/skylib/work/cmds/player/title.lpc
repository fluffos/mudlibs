/*  -*- LPC -*-  */
inherit COMMAND_BASE;

mixed cmd_list() {
    if (this_player()->query_player_title()) {
        write("Your player title is currently set to: " +
          this_player()->query_player_title() + ".\n");
    } else {
        write("Your player title is currently not set.\n");
    }

    write("You can set your player title to one of " +
      query_multiple_short(map(this_player()->query_all_player_titles(),
          (: capitalize($1) :))) +
      ".\n");
    return 1;
} /* cmd_list() */

int cmd_set(string title) {
    string* bits;
    string womble;

    title = lower_case(title);
    bits = explode(title, " ");
        if (sizeof(bits) > 1) {
            add_failed_mess("You cannot use a title with more than 1 bit.\n");
            return 0;
        }

    if (strlen(title) > 20) {
        add_failed_mess("Your title is too long.\n");
    }

    foreach (womble in bits) {
        if( !creatorp(TP) )
            if (member_array(womble,
                this_player()->query_all_player_titles()) == -1) {
                add_failed_mess("The title '" + womble + "' is not valid.\n");
                return 0;
            }
    }

    if (this_player()->query_player_title() &&
      lower_case(this_player()->query_player_title()) == title) {
        add_failed_mess("You already have your player title set to '" + title +
          "'.\n");
        return 0;
    }

    this_player()->set_player_title(title);
    add_succeeded_mess("$N set$s $p player title to " + capitalize(title) + 
      ".\n");
    return 1;
} /* cmd() */

int cmd_reset() {
    if (!this_player()->query_player_title()) {
        add_failed_mess("Your player title is already unset.\n");
        return 0;
    }
    this_player()->set_player_title(0);
    add_succeeded_mess("$N reset$s $p player title.\n");
    return 1;
} /* cmd_reset() */

mixed *query_patterns() {
    return ({ "", (: cmd_list :),
      "<string'title'>", (: cmd_set($4[0]) :),
      "none", (: cmd_reset() :) });
} /* query_patterns() */
