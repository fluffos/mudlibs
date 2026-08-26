/*
 * second_sight.c - substance to allow "scrying" in the vessel which
 *     holds it.
 */

#define SCRY_SHADOW "/std/shadows/magic/second_sight"

inherit "/obj/reagents/transient";

object player, shad;

void add_picture_command() {
    player = this_player();
    player->add_command("picture", this_object(),
                          "<string> in <indirect:object:me-here>");
}

void scare_player(object env) {
  write("You see " + env->the_short() + " point " +
        env->query_possessive() + " finger " +
        "at you, and you manage to duck just as a lightning " +
        "bolt shoots towards your head.\n");
  if (environment(this_player())) {
    tell_room(environment(this_player()),
              this_player()->the_short() + " ducks just " +
              "as a bolt of lightning whizzes over " +
              this_player()->query_possessive() +
              " head.\n",
              ({ this_player() }));
    this_object()->move("/room/rubbish");
  }
}

int do_picture(object *indirs, string *indir_match, string dir_match,
               mixed *args, string pattern) {
    object *target, env;
    string str;

    //printf("Args: %O\nIndirs: %O\n", args, indirs);
    if (environment(this_object()) != indirs[0]) {
        this_player()->add_failed_mess(this_object(),
            "Nothing seems to happen.\n", indirs);
        return 0;
    }
    // Now the fun stuff - trying to figure out what they want to look at.
    // Don't let players use file names
    if (objectp(find_object(args[0])) && !creatorp(TP)) {
        this_player()->add_failed_mess(this_object(),
            "Don't get cute.\n", indirs);
        return 0;
    }
    target = "/global/player/wiz_present"->wiz_present(args[0], this_player());
    if (sizeof(target) > 0) {
        // Don't scry creators or their possessions
        if (!creatorp(TP)) {
            env = target[0];
            while (objectp(env)) {
                if (creatorp(env)) {
                    scare_player(env);
                    return 1;
                }
                env = environment(env);
            }
        }
    } else {
        target = ({ 0 });
        // Some special cases
        if (sscanf(args[0], "%s's room", str)
            || sscanf(args[0], "%s's location", str)
            || sscanf(args[0], "room of %s", str)
            || sscanf(args[0], "location of %s", str)) {
            target[0] = find_living(str);
            if (objectp(target[0])) {
                if (!creatorp(TP)
                    && creatorp(target[0])) {
                    scare_player(target[0]);
                    return 1;
                }
                target[0] = environment(target[0]);
            }
        }
    }
    if (!sizeof(target) || !objectp(target[0])) {
        this_player()->add_failed_mess(this_object(),
            "Can't find \"" + args[0] + "\".\n", indirs);
        return 0;
    }
    // Can't scry anything in a /w directory.
    if (!creatorp(TP)
        && (explode(file_name(target[0]), "/")[0] == "w")) {
        write("You hear thunder rumbling in the distance.  The gods "
              "must be getting angry.\n");
        return 1;
    }
    if (environment(this_object()) && environment(environment(this_object())))
        tell_room(environment(environment(this_object())),
                  "Shadowy shapes begin to form in " +
                  indirs[0]->the_short() + ".\n");
    if (!objectp(shad)) {
        shad = clone_object(SCRY_SHADOW);
        shad->shadow_viewer(indirs[0], target[0], 0);
        //printf("Creating shadow\n");
    } else {
        shad->change_view(target[0]);
        //printf("Changing view\n");
    }
    return 1;
}

void dest_me() {
    if (objectp(player))
      player->remove_object2(this_object(), 1);
    if (objectp(shad))
      shad->dest_shadow(shad);
    ::dest_me();
}
