//      /bin/system/_clone.c

//      from the Nightmare Mudlib

//      clones objects into the game

//      created by Sulam 911219

//      largely rewritten for Nightmare by Descartes of Borg 930809



#include <std.h>



inherit DAEMON;



int cmd_clone(string str) {

    object ob;

    mixed res;

    string message;



    if(member_group(geteuid(previous_object()), "ambassador")) return 0;

    if(!str) {

        notify_fail("Clone what file?\n");

        return 0;

    }

    this_player()->set("error report", 0);

    seteuid(getuid(previous_object()));

    if(res = catch(ob = new(str = resolv_path((string)this_player()->get_path(),

      str))))

        write(str+": "+res);

    if(!ob) {

      if(this_player()->query("error report")) {

        printf("Runtime errors occurred in the execution.\n"

          "Would you like to view the error report (y/n)? ");

        input_to((: call_other, "/cmds/system/handler", "handle_error" :), 0, this_player(),

          (string)this_player()->query("error report"));

      }

      return 1;

    }

    if(ob->move(this_player()) || !ob->get())

      ob->move(environment(this_player()));

    if(stringp(ob->query_short()))

    message = replace_string((string)this_player()->query_mclone(),"$O",

	(string)ob->query_short());

    else message = "";

    write(file_name(ob)+": cloned.");

    say(message,this_player());

    if(this_player()->query("error report")) {

      printf("Runtime errors occurred in the execution.\n"

        "Would you like to view the error report (y/n)? ");

      input_to((: call_other, "/cmds/system/handler", "handle_error" :), 0, this_player(),

        (string)this_player()->query("error report"));

    }

    return 1;

}



void help() {

   message("help", "Syntax: <clone [filename]>\n\nClones an object into your"

           " inventory if it is an object which can be gotten, otherwise it "

           "moves it into your environment.", this_player());

}

