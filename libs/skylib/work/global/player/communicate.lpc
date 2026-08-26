
/**
 * The communication handling code for the player object.  Controls all
 * the basic channels and basic communication stuff.
 * @author Pinkfish
 */
#include <drinks.h>
#include <library.h>
#include <player.h>
#include <language.h>

nosave int real_max_sp;

int sp, max_sp;
nosave object converse_ob;
nosave string my_file_name;
string *languages, cur_lang;

string drunk_speech(string str);
string expand_nickname(string str);
private int converse(string);
private int do_write(string);
private int do_repeat(string);

void communicate_commands() {
  add_command("converse", "", (: converse(0) :));
  add_command("converse", "<string'person'>", (: converse($4[0]) :));
  add_command("frimble", "<string>", (: do_write($4[0]) :));
  add_command("repeat", "<string'command'>", (: do_repeat($4[0]) :));
} /* communicate_commands() */

int query_real_max_sp() {
   if(!real_max_sp)   
     real_max_sp =  50 + (TO->query_level() * 2);

   return real_max_sp;
} /* query_real_max_sp() */

int query_max_sp() { return max_sp; }

int adjust_max_sp( int number ) {
   max_sp += number;
   if ( max_sp < 0 )
      max_sp = 0;

   number = query_real_max_sp();
   
   if ( max_sp > number )
      max_sp = number;
   return max_sp;
} /* adjust_max_sp() */

int set_max_sp( int number ) { return adjust_max_sp( number - max_sp ); }

int query_sp() { return sp; }

int adjust_sp( int number ) {
   if ( sp + number < 0 )
      return -1;

   if ( number < 0 )
     adjust_max_sp( 1 );
   sp += number;
   if ( sp > max_sp )
     sp = max_sp;
   return sp;
} /* adjust_sp() */

int set_sp( int number ) {
   return adjust_sp( number - sp );
} /* set_sp() */

void comm_event( mixed thing, string type, string start, string rest,
      string lang ) {
   if ( !objectp( thing ) && !pointerp( thing ) ) {
      return;
   }
   event( thing, type, start, rest, lang );
   // Trickle the event down to our inventory too..
   // But not to us...
   call_other(all_inventory(), "event_" + type, this_object(),
              start, rest, lang);
} /* comm_event() */

void do_whisper(object ob, string event_type, string start, string type,
                   string words, object *others, string lang, object me) {
   event(ob, event_type, start, type, words, others, lang, me);
} /* do_whisper() */

private int do_write(string arg) {
  if (!arg || arg == "") {
    notify_fail("Syntax: "+query_verb()+" <string>\n");
    return 0;
  }
  write(sprintf("$I$0=%s\n", arg));
  this_player()->adjust_time_left(-DEFAULT_TIME);
  return 1;
} /* do_write() */

private int converse(string str) {
  if (!LANGUAGE_HAND->query_language_spoken(cur_lang)) {
    notify_fail(capitalize(cur_lang)+" is not a spoken language.\n");
    return 0;
  }
  if (str) {
    if (!LANGUAGE_HAND->query_language_distance(cur_lang)) {
      notify_fail(capitalize(cur_lang)+" is not able to spoken at a "+
                  "distance.\n");
      return 0;
    }
    str = lower_case(str);
    str = (string)this_object()->expand_nickname(str);
    converse_ob = find_player(str);
    if (!converse_ob)
      converse_ob = find_living(str);
    if (!converse_ob) {
      notify_fail("Syntax: converse [player]\n");
      return 0;
    }
    if (converse_ob == this_object()) {
      notify_fail("You have a nice conversation with yourself. Gee, what fun.\n");
      return 0;
    }
  }
  write("Give '**' to stop.\n");
  write("] ");
  input_to("do_converse");
  return 1;
} /* converse() */

void do_converse(string str) {
  if(str == "**") {
    write("Ok.\n");
    return;
  }
  if(str)
    if (!converse_ob)
      "/cmds/living/sa_y"->cmd( str );
    else
      if ( function_exists( "trap_tell", environment() ) )
        environment()->trap_tell( str, converse_ob, 1 );
      else
        "/cmds/living/t_ell"->cmd( str, converse_ob, 1 );
  write("] ");
  input_to("do_converse");
} /* do_converse() */

void add_language(string lang) {
  int lvl;
  string skill;

  if (!LANGUAGE_HAND->test_language(lang))
    return ;
  /*
   * Change this to add in skill levels in the appropriate skills.
   * Mostly so existing code will continue to work.
   *
   *if (member_array(lang, languages) != -1)
   *  return ;
   *languages += ({ lang });
   */
  if (LANGUAGE_HAND->query_language_spoken(lang)) {
    skill = LANGUAGE_HAND->query_language_spoken_skill(lang);
    lvl = this_object()->query_skill(skill);
    this_object()->add_skill_level(skill, 100 - lvl);
  }
  if (LANGUAGE_HAND->query_language_written(lang) ||
      LANGUAGE_HAND->query_language_magic(lang)) {
    skill = LANGUAGE_HAND->query_language_written_skill(lang);
    lvl = this_object()->query_skill(skill);
    this_object()->add_skill_level(skill, 100 - lvl);
  }
} /* add_language() */

/* THis function is obsolete...  But....
 * Used to help with the update.
 */
void remove_language(string lang) {
  int i;

  if ((i = member_array(lang, languages)) == -1)
    return ;
  languages = delete(languages, i, 1);
/*
  if (lang == cur_lang) {
    if (!sizeof(languages))
      cur_lang = "grunt";
    else
      cur_lang = languages[0];
    tell_object(this_object(), "You just forgot the language you were "+
                "speaking.  You are now speaking "+cur_lang+".\n");
  }
 */
} /* remove_language() */

int set_language(string str) {
  if (this_object()->query_womens_day())
    return str == "wommon";
  if (!LANGUAGE_HAND->test_language(str))
    return 0;
/*
  if(member_array(str, languages+({ "grunt" })) == -1)
    return 0;
 */
  cur_lang = str;
  return 1;
} /* set_language() */

string query_current_language() { return cur_lang; }
 
string *query_languages() {
  /*
   * This is an old function....  It will not be used in future, the
   * information it returns is incorrect.
   */
  return copy( languages );
} /* query_languages() */

int query_language(string str) {
  if (member_array(str, languages) == -1)
    return 0;
  return 1;
} /* query_language() */


private int do_repeat(string str) {
  if (!str) {
    notify_fail("Syntax: repeat <cmd>\n");
    return 0;
  }
  input_to("do_wombat_repeat", 0, str);
  write("Enter the commands you wish to pass to "+str+".  '**' on a line "+
        "by itself to exit.\n");
  write("] ");
  return 1;
} /* do_repeat() */

protected int do_wombat_repeat(string str, string com) {
  if (str == "**") {
    return 0;
  }
  write("Doing '"+com+" "+str+"\n");
  command(com+" "+str+"\n");
  write("] ");
  input_to("do_wombat_repeat", 0, com);
  return 0;
} /* do_wombat_repeat() */

/**
 * This method returns the people in the array who this player is currently
 * ignoring.
 * @param people the people to check to see if they are being ignored
 * @return the people who are being ignored from the array
 * @see query_ignored_by()
 */
object *query_ignoring(object *people)  {
   string *ignore;
   object *fail = ({ });

   ignore = this_object()->query_property( "ignoring" );
   if ( ignore )  {
      fail = filter_array( people,
                (: member_array( $1->query_name(), $(ignore) ) > -1 :) );
   }
   return fail;
} /* query_ignoring() */

/**
 * This method returns the people in the array who are ignoring this
 * player.
 * @param people the people to check to see for ignoring
 * @return the array of people that are ignoring this player
 * @see query_ignoring()
 */
object *query_ignored_by(object *people) {
   return filter(people, (: sizeof($1->query_ignoring( ({ this_player() }) )) :));
} /* query_ignored_by() */
