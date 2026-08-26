/*
 * transient.c - reaction object, resulting from the mixing of two
 *     substances.
 *
 * The following pseudo-objects may be used in progress strings:
 *    #obj# - replaced by the filename of this object (virtual objects
 *            don't seem to handle file_name correctly)
 *    #env# - replaced by the filename of the environment
 *    #env2# - replaced by the filename of the environment of the environment
 *    #result# - replaced by the filename of the result object
 */

// This use to be /obj/cont_medium, but /obj/food has more features
inherit "/obj/food";

#include <move_failures.h>

// Default amount per unit weight (for setting weight of non-continuous
// items)
#define AMT_PER_WGT 200

// progress_msg is an array of data structures of the form:
//   ({({ msg_1, ({function_str1a, function_str1b, ...})}),
//     ({ msg_2, ({function_str2a, function_str2b, ...})}),
//     ...
//   })
// At interval n, msg_n is printed out and function_strnx is called, after
// having the substitutions above performed and being passed through
// process_string.  This should give plenty of functionality (if not, I
// can always add more :).

mixed *progress_msg = ({});
int duration, interval, counter, hp_base;
float result_amt;
string result, result_alias;
string final = "boom";
int in_progress;

void set_progress_msg(mixed *msg) { progress_msg = msg; }
void set_final(string s) { final = s; }
void set_result(string s) { result = s; }
void set_result_alias(string s) { result_alias = s; }
void set_result_amt(float amt) { result_amt = amt; }

void set_duration(int time) {
    // NOTE that this must be called after the progress_msg has been set
    duration = time;
    if (sizeof(progress_msg)) {
        interval = duration / sizeof(progress_msg);
    } else {
        interval = duration;
    }
}

void add_progress_msg(mixed *msg) {
    progress_msg += ({msg});
    set_duration(duration); // calculate new interval
}

// Note: hp_base is hps of damage done per unit.  If it's being carried
// by a living thing, it does full damage.  Otherwise, it does 1/5 damage
// to everyone in the room (sort of an arbitrary decision, but I'm trying
// to keep the number of parameters down).

void set_hp_base(int hp) { hp_base = hp; }

void start_reaction() {
    /*
     * NOTE: this is the function that sets off the call_outs.  Call it
     * after everything else has been set up.
     */
    if (sizeof(progress_msg) > 1) {
        call_out("progress", interval);
    } else {
        call_out(final, interval);
    }
    in_progress = 1;
}

void stop_reaction() {
    if (counter < sizeof(progress_msg)-1) {
        remove_call_out("progress");
    } else {
        remove_call_out(final);
    }
    in_progress = 0;
}

void restart_reaction() {
    if (counter < sizeof(progress_msg)-1) {
        call_out("progress", interval);
    } else {
        call_out(final, interval);
    }
    in_progress = 1;
}

void progress() {
    object env, env2;
    string msg, fcn;
    int i;

    env = environment(this_object());
    env2 = environment(env);
    if (progress_msg[counter][0]) {
        msg = replace(progress_msg[counter][0],
                      ({"#env#", file_name(env),
                        "#env2#", env2?file_name(env2):0,
                        "#obj#", file_name(this_object()),
                        "#result#", ""}));
        msg = process_string(msg);
        tell_room(env2, msg);
    }
    if (progress_msg[counter][1]) {
        for (i = 0; i < sizeof(progress_msg[counter][1]); i++) {
            fcn = replace(progress_msg[counter][1][i],
                  ({"#env#", file_name(env),
                    "#env2#", env2?file_name(env2):0,
                    "#obj#", file_name(this_object()),
                    "#result#", ""}));
            process_string("@@"+fcn+"@@");
        }
    }
    counter++;
    if (counter < sizeof(progress_msg)-1) {
        call_out("progress", interval);
    } else {
        call_out(final, interval);
    }
}

void boom() {
    object env, env2, cont, new_env;
    object *victims, *contents;
    object result_ob;
    int hp, i, amt, tmp;
    string msg, fcn;
    
    // Assume substance is in a container
    env = environment(this_object());
    env2 = environment(env);
    amt = query_amount();
    if (living(env)) {
        // Held by a living
        hp = hp_base*amt;
        env->adjust_hp(-hp);
    } else if (living(env2)) {
        // In a container held by a living
        hp = (hp_base*amt)/2;
        env2->adjust_hp(-hp);
    } else if (env->query_co_ord()) {
        // Sitting in a room
        hp = (hp_base*amt)/2;
        victims = all_inventory(env);
        for (i = 0; i < sizeof(victims); i++) {
            if (living(victims[i])) {
                victims[i]->adjust_hp(-hp);
            }
        }
    } else if (env2->query_co_ord()) {
        // Sitting in a container in a room
        hp = (hp_base*amt)/5;
        victims = all_inventory(env2);
        for (i = 0; i < sizeof(victims); i++) {
            if (living(victims[i])) {
                victims[i]->adjust_hp(-hp);
            }
        }
    }
    if (result) {
        result_ob = clone_object(result);
        if (result_alias) {
            // result_alias should be 0 if this isn't a cont_medium
            result_ob->set_medium_alias(result_alias);
        }
        if (function_exists("set_amount", result_ob)) {
            result_ob->set_amount(to_int(result_amt*query_amount()));
        } else if (result_amt > 0.0) {
            result_ob->set_weight(to_int(result_amt*query_amount()/AMT_PER_WGT));
        }
    }
    if (sizeof(progress_msg)) {
        if (progress_msg[counter][0]) {
            msg = replace(progress_msg[counter][0],
                          ({"#env#", file_name(env),
                            "#env2#", env2?file_name(env2):0,
                            "#obj#", file_name(this_object()),
                            "#result#", result_ob?file_name(result_ob):0}));
            msg = process_string(msg);
            tell_room(env2, msg);
        }
        if (progress_msg[counter][1]) {
            for (i = 0; i < sizeof(progress_msg[counter][1]); i++) {
                fcn = replace(progress_msg[counter][1][i],
                              ({"#env#", file_name(env),
                                "#env2#", env2?file_name(env2):0,
                                "#obj#", file_name(this_object()),
                                "#result#", ""}));
                process_string("@@"+fcn+"@@");
            }
        }
    }
    move("/room/void");
    // Destroy container (unless living or a room) and move contents
    // up.
    contents = all_inventory(env);
    if (result_ob) contents += ({result_ob});
    for (i = 0; i < sizeof(contents); i++) {
        if (contents[i]->query_continuous()) {
            contents[i]->dest_me();
            continue;
        }
        new_env = env2;
        while (new_env && ((tmp=contents[i]->move(new_env)) != MOVE_OK)) {
            new_env = environment(new_env);
        }
        if (!new_env) contents[i]->dest_me();
    }
    if (!living(env) && !function_exists("query_co_ord", env)) {
        env->dest_me();
    }
    call_out("dest_me", 0);
}

object morph() {
    // Returns the object created...
    object env, env2, result_ob, new_env, *contents;
    string msg, fcn;
    int i, mv_stat;

    env = environment(this_object());
    env2 = environment(env);
    // Need to move out of the container to make room
    move("/room/void");
    if (stringp(result)) {
        result_ob = clone_object(result);
        if (stringp(result_alias)) {
            // result_alias should be 0 if this isn't a cont_medium
            result_ob->set_medium_alias(result_alias);
            result_ob->set_amount(to_int(result_amt*query_amount()));
        } else if (result_amt > 0.0) {
            result_ob->set_weight(to_int(result_amt*query_amount()/AMT_PER_WGT));
        }
        mv_stat = result_ob->move(env);
        if (mv_stat) {
            //write("Uh oh, move error: " + mv_stat + "\n");
            // Destroy container (unless living or a room) and contents.
            contents = all_inventory(env);
            for (i = 0; i < sizeof(contents); i++) {
                contents[i]->dest_me();
            }
            if (!living(env) && !function_exists("query_co_ord", env)) {
                tell_room(env2, "The " + env->short(0) +
                          " explodes, splattering the contents all over.\n");
                env->dest_me();
            }
            result_ob->dest_me();
            result_ob = 0;
        }
    }
    if (sizeof(progress_msg)) {
        if (progress_msg[counter][0]) {
            msg = replace(progress_msg[counter][0],
                          ({"#env#", env?file_name(env):0,
                            "#env2#", env2?file_name(env2):0,
                            "#obj#", file_name(this_object()),
                            "#result#", result_ob?file_name(result_ob):0}));
            msg = process_string(msg);
            tell_room(env2, msg);
        }
        if (progress_msg[counter][1]) {
            for (i = 0; i < sizeof(progress_msg[counter][1]); i++) {
                fcn = replace(progress_msg[counter][1][i],
                          ({"#env#", env?file_name(env):0,
                            "#env2#", env2?file_name(env2):0,
                            "#obj#", file_name(this_object()),
                            "#result#", result_ob?file_name(result_ob):0}));
                process_string("@@"+fcn+"@@");
            }
        }
    }
    call_out("dest_me", 0);
    return result_ob;
}
    
string query_pounds() { return "about " + ::query_weight()/9; }

void query_progress_msg() {
    int i, j;
    
    write("({\n");
    for (i = 0; i < sizeof(progress_msg); i++) {
        write(progress_msg[i][0] + " ({\n");
        if (!progress_msg[i][0]) {
            write("0})\n");
        } else {
            for (j = 0; j < sizeof(progress_msg[i][1]); j++) {
                write(progress_msg[i][1][j] + "\n");
            }
            write("})\n");
        }
    }
}

mixed stats() {
  return ::stats() + ({
      ({ "duration", duration }),
      ({ "interval", interval }),
      ({ "counter", counter }),
      ({ "hp base", hp_base }),
      ({ "result amt", result_amt }),
      ({ "result", result }),
      ({ "result alias", result_alias }),
      ({ "final", final }),
      ({ "in progress", in_progress }),
  });
} /* stats() */

mapping query_dynamic_auto_load() {
    return ([
             "::": ::query_dynamic_auto_load(),
             "progress_msg" : progress_msg,
             "duration" : duration,
             "interval" : interval,
             "counter" : counter,
             "hp_base" : hp_base,
             "result_amt" : result_amt,
             "result" : result,
             "result_alias" : result_alias,
             "final" : final,
             "in_progress" : in_progress,
           ]);
} /* query_dynamic_auto_load() */

void init_dynamic_arg(mapping args) {
    if (args["::"])
      ::init_dynamic_arg(args["::"]);
    if (!undefinedp(args["progress_msg"]))
      progress_msg = args["progress_msg"];
    if (!undefinedp(args["duration"]))
      duration = args["duration"];
    if (!undefinedp(args["interval"]))
      interval = args["interval"];
    if (!undefinedp(args["counter"]))
      counter = args["counter"];
    if (!undefinedp(args["hp_base"]))
      hp_base = args["hp_base"];
    if (!undefinedp(args["result_amt"]))
      result_amt = args["result_amt"];
    if (!undefinedp(args["result"]))
      result = args["result"];
    if (!undefinedp(args["result_alias"]))
      result_alias = args["result_alias"];
    if (!undefinedp(args["final"]))
      final = args["final"];
    if (!undefinedp(args["in_progress"])) {
        in_progress = args["in_progress"];
        if (in_progress)
          restart_reaction();
    }
} /* init_dynamic_arg() */

mapping int_query_static_auto_load() {
   return ([
      "::": ::int_query_static_auto_load(),
   ]);
} /* int_query_static_auto_load() */

mapping query_static_auto_load() {
   if ( file_name( this_object() )[ 0 .. 22 ] == "/obj/reagents/transient" )
      return int_query_static_auto_load();
   return 0;
} /* query_static_auto_load() */

void init_static_arg( mapping map ) {
   if ( map[ "::" ] )
      ::init_static_arg( map[ "::" ] );
} /* init_static_arg() */
