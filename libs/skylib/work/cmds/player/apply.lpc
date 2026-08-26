/* Applications Room for Suvangi
 * By Quango 950808
 *
 * Cleaned up a bunch.
 * Sibbis 960622
 */
// Made into the Nameless Sorrows application command.. Donky 30/07/96
// Used on Riftwar Shaydz

#define BOARD_NAME "applications"

inherit COMMAND_BASE;

void continue_loop(int step);
void abort_app();
void end_app();

nosave mapping questions;
nosave string *qkeys;

void create() {
    ::create();
    questions = ([
      "A_rlname"     : "What is your real name?",
      "B_rlage"      : "What is your age?",
      "C_rlloc"      : "Where do you live?",
      "D_rlschool"   : "Do you attend a school or university?  "
                       "If so, which one?  What is your major there?",
      "E_rlwork"     : "Do you work?  If so, what do you do?",
      "F_rlhobby"    : "What are your hobbies and interests?",
      "G_rlunix"     : "How much experience do you have with basic Un*x "
                       "commands (like ls, cd, rm, etc.)?",
      "H_mudlong"    : "How long have you been mudding?",
      "I_mudwhere"   : "Where have you mudded?  Under what names?",
      "J_mudbanned"  : "Have you ever been banned from a mud?  If so, why?",
      "K_coded"      : "If you have coded on a MUD in the past, where did "
                       "you code?",
      "L_coding"     : "Do your currently code on a MUD?  If so, where?",
      "M_knowloser"  : "Do you already know anyone who codes here, who could "
                       "recommend you?  If so, who?",
      "N_whyus"      : "Why would you like to code here?",
      "O_playlength" : "How long have you played here?",
      "P_timeavail"  : "How much time (hours/week) could you devote to "
                       "coding on "+mud_name()+"?",
      "Q_whatarea"   : "Which areas of the mud would you be interested in "
                       "working on?",
      "R_misc"       : "Do you have anything else you'd like to tell us?\n"
                       "Also, please leave an email address where we can "
                       "reach you.  The answer to your application will be "
                       "sent to your mudmail though."
      ]);

    qkeys = asort(keys(questions));

} /* create() */

/** @ignore yes */
int cmd( string str ) {
    int i;
    object user = TP;

    /* In case the person quit while doing the application */
    i = user->query_property("apply step");

    while( i > -1 ) {
        user->remove_property("app part " + i );
        i--;
    }

    user->remove_property("apply step");

    write("Application for a creator position on "+mud_name()+".\n\n"
        "Please note that a blank entry will abort your application.\n\n");

    write("There is no need for you to enter every piece of information "
        "that exists about you at the first prompt.  Please answer all "
        "the questions given, and you will get an opportunity at the end "
        "to let us know anything else about you that seems relevant.\n\n");
    write("NOTE:- Some people have reported problems filling out this "
        "application.\n"
        "If for some reason it doesn't complete (it asks you at the end to "
        "type yes), you might be better off using the web application on our "
        "website (help website).\n");

    /*** Loop to the first question ***/
    continue_loop(0);
    return 1;

} /* cmd() */

/** @ignore yes */
void lame_line_editor( string last, string stuff, int first_go_around ) {
    if( first_go_around ) {
        write("When you are done with this question, type '**', '.', or "
            "enter a blank line.\n");
        write("] ");
        input_to("lame_line_editor", "", 0 );
        return;
    } else if( !last || last == "" || last == "." || last == "**") {
        TO->next_step(stuff);
        return;
    }

    stuff += last+" ";
    write("] ");
    input_to("lame_line_editor", stuff, 0 );

} /* lame_line_editor() */

/** @ignore yes */
void next_step( string previous_input ) {
    int step;

    if( !previous_input || previous_input == "" ) {
        abort_app();
        return;
    }

    step = TP->query_property("apply step");
    TP->add_property("app part "+step, previous_input );
    step++;

    if( step >= sizeof(qkeys) ) {
        end_app();
        return;
    }

    continue_loop(step);

} /* next_step() */

/** @ignore yes */
void continue_loop( int step ) {
    string q_str;

    write("\n");
    q_str = "Question #"+(step+1)+": ";
    printf("%s%-=*s\n", q_str, TP->query_cols()-strlen(q_str),
        questions[qkeys[step]] );
    TP->add_property("apply step", step );
    TO->lame_line_editor("", "", 1 );

} /* continue_loop() */

/** @ignore yes */
void abort_app() {
    write("Are you sure you want to ABORT the application? ");
    input_to("confirm_abort", "", 0 );
} /* abort_app() */

/** @ignore yes */
void confirm_abort( string confirm ) {
    int i, step;

    if( lower_case( confirm[0..0] ) != "y" ) {
        step = TP->query_property("apply step");
        continue_loop(step);
        return ;
    }

    i = TP->query_property("apply step");
    while( i > -1 ) {
        TP->remove_property("app part " + i );
        i--;
    }

    TP->remove_property("apply step");
    TP->save_me();

    write("Application aborted.\n");
    return;

} /* confirm_abort() */

/** @ignore yes */
void end_app() {
    string message;
    int i;

    TP->remove_property("apply step");

    message = "";

    for( i = 0; i < sizeof(qkeys); i++ ) {
        message += sprintf("---> %-=*s\n\n", 70, questions[qkeys[i]] );
        message += sprintf("     %-=*s\n\n", 70,
            TP->query_property("app part " + i ) );
        TP->remove_property("app part " + i );
    }

    TP->save_me();
    TP->set_finish_func("end_app_2", TO );
    TP->add_property("app message", message );
    TP->more_string("Your application:\n\n" + message, "Apply");

} /* end_app() */

/** @ignore yes */
void end_app_2() {
    string message;

    message = TP->query_property("app message");
    TP->remove_property("app message");

    write("Are you sure you want to send the application? ");
    input_to("confirm_apply", 0, message );

} /* end_app_2() */

/** @ignore yes */
void confirm_apply( string str, string message ) {
    str = lower_case(str)[0..0];

    if( str != "y" && str != "n" ) {
        write("Are you sure you want to send the application (Yes or No)? ");
        input_to("confirm_apply", 0, message );
        return;
    }

    if( str == "n" ) {
        write("Application aborted.\n");
        return;
    }

    BOARD_H->add_message( BOARD_NAME, TP->query_name(),
        "Application by "+TP->query_cap_name(), message );

    write("Thank you for your application.  You should hear back "
        "from us within 2-4 days.\n");
    return;

} /* confirm_apply() */

/** @ignore yes */
mixed query_patterns() { return ({ "", (: cmd :) }); }
