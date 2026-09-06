/* A quicktyper
**
** This is just an interface to the lib/qtyper. It should
** be sufficient, though :-)
**
**   13-Aug-92 [m] First experiments
**   15-Aug-92 [m] More development.
**   31-Aug-92 [m] Adapted for new property system
**   05-Oct-92 [m] Nicened the help.
**   20-Feb-93 [m] Made it non-droppable.
**   08-May-96 [s] Small features for output
**
** [m] Mateese, Biontic Magics & Darkness
** [s] Sique
*/

#include <properties.h>
#include <secure/wizlevels.h>

#include "/obj/lib/stddefs.h"
#include <string.h>

#include "/obj/lib/qtyper.h"
inherit "/obj/lib/qtyper";
inherit "/std/thing";

/*-------------------------------------------------------------------------
** Initialization, Description
*/

void create() {
  qtyper::create();
  thing::create();

  AddId("qtyper");
  AddId("quicktyper");
  SetLong ("\
This is a quicktyper, easing your typing.\n\
Give 'help quicktyper' for information.\n"
          );
  SetProp (P_NODROP, "You can't drop your quicktyper.\n");
  SetProp (P_NOGIVE, "You can't give your quicktyper away.\n");
}

varargs string QueryShort() {
  object owner;
  if ((owner = _get_owner()) || (owner = lastowner))
    return capitalize(geteuid(owner))+"'s quicktyper";
  return "A quicktyper";
}

/*-------------------------------------------------------------------------
** Add our own commands
*/

varargs void AddActions () {
  add_action("Help", "help");
  qtyper::AddActions();  /* Allow non-parse-commands as well */
}

void init() {
  object o;
  if (present("xtool")) {
    say("qtyper met xtool - selfdestruct\n");
    remove();
    if (this_object()) destruct(this_object());
  }
  if ((o = present("qtyper")) != this_object() && o) {
    say("qtyper met qtyper - destructing it\n");
    o->remove();
    if (o) destruct(o);
  }
  thing::init();
  qtyper::init();  /* This does all! */
}

/*-------------------------------------------------------------------------
** Print some help.
*/

int Help (string str) {
  int iswiz;

  if (!ForMe()) {
    notify_fail ("Maybe you should take it first?\n");
    return FALSE;
  }
  iswiz = PL && IS_IMMORTAL(PL);
  if(str && id(str))
    write ("\
This is your private quicktyper. It will help you to type commands by\n\
 setting aliases for them and it also remembers all the things you typed\n\
 in a history.\n\
Additional help is available for the topics 'alias', 'history',\n\
 'multiple'"+(iswiz?", 'script'":"")+" and 'qmode'.\n\
The quicktyper defines the commands 'alias', 'unalias', 'history', 'do',\n"
+(iswiz?" 'sh', 'for'":"")+" and 'qmode'.\n\
 Every command prints a short description when given as '<cmd> ?',\n\
 e.g. 'alias ?'.\n"
+(iswiz ? "The quicktyper also id's as 'qtyper'.\n":"")
          );
  else if (str == "alias")
    write("\
Alias commands:\n\
   'alias'                  to receive the list of all current aliases\n\
                            and commands\n\
   'alias ?'                displays a short help\n\
   'alias <name>'           to see the command behind an alias\n\
   'alias <name> <command>' to tell your little demon to remember an alias\n\
   'unalias <name>'         to forget an alias\n\n\
   <command> can be a normal command but can also contain '"+carg
                                                             +"<num>' where\n\
   each '"+carg
           +"<num>' stands for an optional argument behind the alias when\n\
   executed. Examples:\n\n\
   'alias lb look at board'\n\
   When typing 'lb', 'look at board' will be executed instead of of 'lb'\n\n\
   'alias gc get "+carg+"1 from corpse'.\n\
   When typing 'gc coins' the word 'coins' will be substituted with the\n\
   '"+carg
     +"1'. If you type 'gc coins 3' the second argument behind 'gc' will be\n\
   placed at the end of the command. 'get coins from corpse 3' will be\n\
   executed.\n\n\
   'test say "+carg+"3 "+carg+"2 "+carg+"1'\n\
   Play around with this one to learn how the argument subtitution works.\n"
         );
  else if (str == "multiple")
    write ("\
Multiple command execution:\n\
   'do ?'                                         displays a short help\n\
   'do [<num>#]<command>[;[<num>#]<command>] ...' for multiple execution\n\
                                                  of commands\n\n\
   Example: 'do 5#w;3#n;smile;2#s;look'\n\
            This will execute 5 times 'w', 3 times 'n', 'smile', ...\n"
+(iswiz ?
 "\n   'for ?'                        displays a short help\n\
   'for <filepattern> <command>'\n\
      Execute <command> for all matching files. The <command> string can\n\
      contain replacment marks where the filename shall be inserted:\n\
       - '"+carg+carg+"' : the full file name\n\
       - '"+carg+"e' : the extension of the file name\n\
       - '"+carg+"f' : the file name without extension and directory name\n\
       - '"+carg+"h' : the full directory name of the file\n\
       - '"+carg+"r' : the full file name without file extension\n\
       - '"+carg+"t' : the file name without the directory name\n\
\n   Examples:\n\
     for ~/room/*.c goto "+carg+"r\n\
\n       Lets you visit quickly all your rooms.\n\
\n     for ~/obj/* mv "+carg+""+carg+" "+carg+"h/oldobj/"+carg+"f."+carg
                        +"e.old\n\
\n       Move all files from your 'obj' dir into the 'obj/oldobj' dir\n\
        and change the extensions to '<extension>.old'.\n"
:"")
          );
  else if(iswiz && str == "script")
    write (
 "Script command execution:\n\
  'sh ?'           displays a short help\n\
  'sh <filename>'  Read in the file and execute each line of it \n\
                   as it would be typed on the keyboard\n"
          );
  else if (str == "history")
    write (
"History commands:\n\
   'history'       to see the list of all the commands you have typed\n\
   '"+histrep
     +"'            to execute your latest command again\n\
   '"+crepl+"<old>"+crepl
          +"<new>   to redo the last command with all <old> strings\n\
                   replaced by <new>\n\
   '"+chist
    +"<num>'        to execute the command of the history with \n\
                   the number <num>\n\
   '"+chist
    +"<string>'     to execute the latest command which starts with <string>\n"
          );
  else if (str == "qmode" && !iswiz)
    write (
 "Changing the operation mode of the quicktyper:\n\
  'qmode'                 displays the current mode.\n\
  'qmode ?'               displays a short help.\n\
  'qmode echo on'         every cmd done by the quicktyper will be echoed.\n\
  'qmode echo off'        switches off echoing.\n\
  'qmode maxhist  <nr>'   sets the history size to <nr> lines.\n\
  'qmode chars    <str>'  the magic chars for history, arguments and\n\
                          replacement are set in this order from the three\n\
                          characters of <str>.\n"
          );
  else if (str == "qmode" && iswiz)
    write ("\
Changing the operation mode of the quicktyper:\n\
  'qmode'             displays the current mode.\n\
  'qmode ?'           displays a short help.\n\
  'qmode <option>...' sets one or more options of the quicktyper.\n\
with <option> ==\n\
  'active  on | off'  (de)activates the alias und history functions.\n\
  'heart   on | off'  (de)activate the quicktypers heartbeat.\n\
  'first   on | off'  (de)activates reestablishing of the quicktyper's\n\
                       pole position on every init() and every heart_beat.\n\
  'echo    on | off'  (de)activates echoing of executed commands.\n\
  'noforce on | off'  (de)activates the force protection.\n\
  'maxhist  <nr>'     sets the history size to <nr> lines.\n\
  'maxrecur <nr>'     the substitution of aliases recurses max <nr> times.\n\
  'chars    <str>'    the magic chars for history, arguments and\n\
                       replacement are set in this order from the three\n\
                       characters of <str>.\n"
          );
  else return FALSE;

  return TRUE;
}

/*************************************************************************/
