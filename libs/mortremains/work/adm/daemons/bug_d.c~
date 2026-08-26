// Bug/typo/idea tracking system
// Based, in part, on the interface idea at Tsunami.
// Used in conjunction with the "bug", "idea", "typo", and "bugs" commands
// Deathknight -- May 13, 1996


#include <mudlib.h>

inherit DAEMON ;

/* These are only used once, so we #define them */
#define RESTORE_BTI  "/data/bugs"
#define BTI_DATA_FILE  "data/bugs"

/*
 * Structure for this mapping:
 *   int number : ({ int type, string location_filename,
 *                   string assigned_to, mixed * comment_array })
 *
 * Where type is:  1-bug, 2-typo, 3-idea
 *
 * Where comment_array is:
 *   ({ string name, int date, string comment, ... })
 *
 * (bti stands for Bugs/Typos/Ideas)
 */
mapping bti;
int next_number;


void create() {
    ::create() ;
    next_number = 1;
    bti = ([]);
    restore_object (RESTORE_BTI);
}

void save_me () {
    save_object (BTI_DATA_FILE);
}

int add_new (string comment) {
    int bti_type;
    object env, tp;
    string env_str;

    tp = this_player();
    if (!tp || !interactive (tp))  return 0;
    env = environment (tp);
    if (!env)  env_str = "(Nowhere)";
    else env_str = file_name (env);
    if (query_verb() == "bug")  bti_type = 1;
    else if (query_verb() == "typo")  bti_type = 2;
    else if (query_verb() == "idea")  bti_type = 3;
    else return 0;
    if (bti[next_number]) {
        write ("Internal bug daemon error!\n");
        return 0;
    }

    bti[next_number++] = ({ bti_type, env_str, 0,
      ({ tp->query("name"), time(), comment }) });
    save_me();
    return next_number-1;
}


string bug_type (int type) {
    switch (type) {
      case 1:  return "bug";
      case 2:  return "typo";
      case 3:  return "idea";
      default:  return "internal error!";
    }
}


void list_bug (int bug_num) {
    mixed *bug, *comments;
    int x;

    bug = bti[bug_num];
    if (!bug) {
        if (bug_num >= next_number)
            write ("That number has not yet been reached.\n");
        else write ("That bug has already been concluded.\n");
        return;
    }
    
    comments = bug[3];
    printf ("Number:  %d\n"
            "Date:        %s\n"
            "Type:        %s\n"
            "Location:    %s\n"
            "Originator:  %s\n"
            "Assigned to: %s\n"
      "------------------------------------------------------------",
      bug_num, ctime (comments[1]), bug_type (bug[0]), bug[1],
      comments[0][0], (bug[2] ? bug[2]:"(unassigned)") );
    
    for (x=0; x<sizeof (comments); x+=3) {
        printf ("%s: %s  %s\n", ctime (comments[x+1]),
          comments[x], comments[x+2]);
    }
}


int add_comment (int bug_num, string comment) {
    object tp;

    tp = this_player();
    if (!tp || !interactive (tp))  return 0;
    if (!bti[bug_num]) {
        write ("Invalid bug number.\n");
        return 0;
    }

    bti[bug_num][3] += ({ tp->query("name"), time(), comment });
    save_me();
    return bug_num;
}


int assign_bug (int bug_num, string name) {
    object tp;

    tp = this_player();
    if (!tp || (!adminp (tp) && name != 0))  return 0;
    if (!bti[bug_num]) {
        write ("Invalid bug number.\n");
        return 0;
    }
    if (!name && bti[bug_num][2] != tp->query("name") && !adminp (tp)) {
        write ("You can only resolve your own bugs.\n");
        return 0;
    }
/* Should we check if name's a valid user? */
    
    bti[bug_num][2] = name;
    bti[bug_num][3] += ({ tp->query("name"), time(),
      (name ? "assigned to "+name:"resolved") });
    save_me();
    return bug_num;
}


