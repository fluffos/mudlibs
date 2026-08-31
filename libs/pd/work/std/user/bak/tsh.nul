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

inherit CSTACK_ADT;       /* for pushd and popd */
#include <strings.h>
private static string tsh_prompt;
private static int cur, hist_size, pushd_size, custom_prompt, on_prompt;

string do_nicknames(string arg);
string do_alias(string arg);
string handle_history(string arg);
int tsh(string file);
int query_prompt() { return on_prompt; }
void set_prompt(int x) { on_prompt = x; }
int do_new() {
    string d1, d2;

        tsh_prompt = (string)this_object()->getenv("prompt");
        tsh_prompt = !tsh_prompt ? DEFAULT_PROMPT : tsh_prompt + "";
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
// this
int pushd(string arg) {
    string path;

    path = (string)this_object()->get_path();
    if((int)CD->cmd_cd(arg) && cstack::enqueue_cstack(path) == -1) {
        cstack::dequeue();
        cstack::enqueue_cstack(path);
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
// here
    if(pushd_size) cstack::alloc_cstack(pushd_size);
    if(hist_size) history::alloc_history(hist_size); 
// there
    cstack::alloc_cstack(MAX_PUSHD_SIZE);
    history::alloc_history(MAX_HIST_SIZE);
    rcfile = user_path((string)this_player()->query_name()) + ".login";
    if(file_size(rcfile) > -1) this_object()->tsh(rcfile);
}
// this
string write_prompt()
{
    string path, prompt, tmp;
    int maxhp, maxsp, maxmp, hp, sp, mp;
     tsh_prompt = (string)this_object()->getenv("prompt");
     tsh_prompt = !tsh_prompt ? DEFAULT_PROMPT : tsh_prompt + " ";
     custom_prompt = (tsh_prompt != DEFAULT_PROMPT);

    if( custom_prompt )
    {
        prompt = tsh_prompt;
        maxhp = this_player()-> query_max_hp();
        maxsp = this_player()-> query_max_sp();
        maxmp = this_player()-> query_max_mp();
        hp    = this_player()-> query_hp();
        sp    = this_player()-> query_sp();
        mp    = this_player()-> query_mp();
        if((int)this_player()-> query_max_hp()/((int)this_player()->query_hp() ? (int)this_player()->query_hp() : 1) > 9)
            prompt = replace_string( prompt, "$h",
                "%^RED%^" + (int)this_player()-> query_hp() );
        else
            prompt = replace_string( prompt, "$h",
                "" + (int)this_player()-> query_hp() );
        prompt = replace_string( prompt, "$H",
            "" + (int)this_player()-> query_max_hp() );

        prompt = replace_string ( prompt, "$s",
            "" + (int)this_player()-> query_sp() );
        prompt  = replace_string ( prompt, "$S",
            "" + (int)this_player()-> query_max_sp() );
        prompt = replace_string ( prompt, "$m",
            "" + (int)this_player()-> query_mp() );
        prompt = replace_string ( prompt, "$M",
            "" + (int)this_player()-> query_max_mp() );
        prompt = replace_string ( prompt, "$b",
            "" + (int)this_player()-> query_bp() );
        prompt = replace_string ( prompt, "$B",
            "" + (int)this_player()-> query_max_bp() );

        prompt = replace_string( prompt, "\\n", "\n" );
        prompt = replace_string( prompt, "$N", lower_case(mud_name()) );
        prompt = replace_string( prompt, "$C", ""+query_cmd_num() );
        prompt += " ";

    } else {
        prompt = DEFAULT_PROMPT;
    }
    message("prompt", prompt, this_object());
    on_prompt = 1;    
    return prompt;
}

nomask string process_input(string arg) {
//    arg = trim_spaces(arg);
    on_prompt = 0;
    if(arg && arg != "" && arg[0]!=' ') return 
        do_alias( do_nicknames( handle_history( arg ) ) );
    else return arg;
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
