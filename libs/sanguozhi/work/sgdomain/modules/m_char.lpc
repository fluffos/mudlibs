// m_char.c by fire on June 25 1998
// this file will be inherited by all
// the famous npc and players
// they are all called char
// some are copies from m_actions.c
////////////////////////////////////////////////////////////
#include <mudlib.h>
#include <daemons.h>
#include <commands.h>
inherit "/sgdomain/modules/m_charanswer";
void add_hook(string, function);
private function        my_hook;
private string * response_queue = ({});
object query_body() {
    return this_object();
}
object query_shell_ob() {
    return this_object();
}
//:FUNCTION do_game_commanda
//Emulates handling of emotes and player commands for NPCs that inherit this
//module.  E.g. do_game_command("wield sword").  do_game_command("smile hap*").
 nosave protected void do_game_commanda(string str) 
{
    object save_tu;
    mixed * winner;
    string verb, argument;
    save_tu = this_user();
    // set_this_player(this_object()); // set_this_player() unavailable in this driver build (no NO_ADD_ACTION) -- no-op'd, this_player() is whatever it naturally is here
    verb = str;
    sscanf(verb, "%s %s", verb, argument);
    
  
    winner = CMD_D->find_cmd_in_path(verb, ({ CMD_DIR_PLAYER "/" }));
    if (arrayp(winner)) {
        winner[0]->call_main("","","","","","",argument);
    }
    else if (environment()) {
        mixed result = parse_sentence(str);
        if (stringp(result))
            write(result);
    }
    // set_this_player(save_tu); // set_this_player() unavailable in this driver build (no NO_ADD_ACTION) -- no-op'd, this_player() is whatever it naturally is here
}
private void do_respond() {
    mixed cmd = response_queue[0];
//	tell_user("fire",sprintf("%O %O\n",
//		response_queue,cmd));    
    if (stringp(cmd))
        do_game_commanda(cmd);
    else
        evaluate(cmd);
    response_queue = response_queue[1..];
	if(sizeof(response_queue)>0) do_respond();
}
//:FUNCTION respond
//me BEFORE the message gets to you.
void respond(string str) {
    response_queue += ({ str });
    call_out( (: do_respond :), random(3));
    if (!my_hook) {
        my_hook = (: remove_call_out :);
        add_hook("remove", my_hook);
    }
}
void responda(string str)
{

    response_queue += ({ str });
    do_respond();
}
int is_char()
{
        return 1;
}



void move_char()
{
	string p_id,f_name;
	object env;
	env=environment(this_object());
	if(!objectp(env)) return;
	p_id=this_object()->query_primary_id();
	f_name=file_name(env);
	CHAR_D->set_char(p_id,"room",f_name);
}
void move_setup()
{
   add_hook("move",(: move_char :));
}
