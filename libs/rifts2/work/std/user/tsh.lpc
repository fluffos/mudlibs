//      /std/user/tsh.c
//      from the Nightmare Mudlib
//      tsh- the TMI-shell or Tru-shel
//      created by Truilkan@TMI 920205
//      bug in $h & $H options fixed by Pallando@Nightmare 930709

#include <adt_defs.h>
#include <commands.h>
#include <tsh.h>

#define DEFAULT_PROMPT "> "
#define MAX_HIST_SIZE  50
#define MIN_HIST_SIZE  20
#define MAX_PUSHD_SIZE 50
//below was private inherit... boggle?
inherit CSTACK_ADT;       /* for pushd and popd */ 
inherit "/std/user/history";
// private inherit CSTACK_ADT;       /* for pushd and popd */

private nosave string tsh_prompt;
private nosave int cur, hist_size, pushd_size, custom_prompt;

string do_nicks(string arg);
string do_alias(string arg);
string handle_history(string arg);
int tsh(string file);

int do_new() {
    string d1;

	tsh_prompt = (string)this_object()->getenv("prompt");
	tsh_prompt = !tsh_prompt ? DEFAULT_PROMPT : tsh_prompt + " ";
	custom_prompt = (tsh_prompt != DEFAULT_PROMPT);

	d1 = (string)this_object()->getenv("pushd");
	pushd_size = 0;
	if (d1)
		sscanf(d1,"%d",pushd_size);
	if (pushd_size > MAX_PUSHD_SIZE)
		pushd_size = MAX_PUSHD_SIZE;

	d1 = (string)this_object()->getenv("history");
	hist_size = 0;
	if (d1)
		sscanf(d1,"%d",hist_size);
	if (hist_size > MAX_HIST_SIZE)
		hist_size = MAX_HIST_SIZE;
    if (!hist_size)
       hist_size = MIN_HIST_SIZE;
	return 1;
}

int pushd(string arg) {
    string path;

    path = (string)this_object()->get_path();
    if((int)CD->cmd_cd(arg) && cstack::enqueue(path) == -1) {
        cstack::dequeue();
        cstack::enqueue(path);
    }
    return 1;
}

int popd() {
    mixed dir;

    dir = cstack::pop();
    if((int)dir == -1) write("Directory stack is empty.\n");
    else CD->cmd_cd((string)dir);
    return 1;
}

void initialize() {
    string rcfile;

    do_new();
    if(pushd_size) cstack::alloc(pushd_size);
    if(hist_size) history::alloc(hist_size);
    rcfile = user_path((string)this_player()->query_name()) + ".login";
    if(file_size(rcfile) > -1) this_player()->tsh(rcfile);
}

string write_prompt()
{
    string path, prompt, tmp;

    if( custom_prompt )
    {
        prompt = tsh_prompt;
        path = (string)this_player()->get_path();
        tmp = user_path((string)this_player()->query_name());
        tmp = tmp[0 .. strlen(tmp)-2];
        if(sscanf(path, "/wizards/%s", tmp) == 1)
	    path = "~" + tmp;
        prompt = replace_string( prompt, "$D", path );
        prompt = replace_string( prompt, "$h",
            "" + (int)this_player()-> query_hp() );
        prompt = replace_string( prompt, "$H",
            "" + (int)this_player()-> query_max_hp() );
        prompt = replace_string( prompt, "\\n", "\n" );
        prompt = replace_string( prompt, "$N", lower_case(mud_name()) );
        prompt = replace_string( prompt, "$C", ""+query_cmd_num() );
        prompt += " ";
    } else {
        prompt = DEFAULT_PROMPT;
    }
    message("prompt", prompt, this_object());
    return prompt;
}

nomask string process_input(string arg) {
    if(arg && arg != "") {
      arg = handle_history(arg);
      arg = do_nicks(arg);
      if(objectp(this_object()->query("mirror action")) ||
        pointerp(this_object()->query("mirror action")))
        catch(call_other(this_object()->query("mirror action"), "force_me", do_alias(arg)));
      return do_alias(arg);
    }
    return arg;
}

int tsh(string file) {
   string contents, *lines;
   int j, len, finished;

   if (geteuid(previous_object()) != geteuid()) return 0;
   if (!file) {
      notify_fail("usage: tsh filename\n");
      return 0;
   }
   contents = read_file(resolv_path((string)this_object()->get_path(),file));
   if (!contents) {
      notify_fail("tsh: couldn't read " + file + "\n");
      return 0;
   }
   lines = explode(contents,"\n");
   len = sizeof(lines);
   finished = 0;
   for (j = 0; j < len && !finished; j++) {
    if(!command(lines[j])) {
         write(file + ": terminated abnormally on line #" + (j+1) + "\n");
         write("while doing: " + lines[j] + "\n");
         finished = 1;
      }
   }
   return 1;
}
