/*                                logger

   The loggerdaemon to have control over the logger-server. Read news
   aso. use with 'daemon add /bin/logger'

   by Walchy @ Tubmud

   version : 2.08

         start : 19-Apr-1998
   last update : 20-May-1998
*/

#include <logger.h>
#include <kernel.h>
#include <libs.h>
#include <server.h>
#include <message.h>
#include <prop/player.h>

inherit ACCESS;
inherit "basic/daemon";
inherit "basic/create";
inherit "basic/tools/time";

private mapping   commands;          // Hold the commandlist
private mapping   topics;            // Other topics on the daemon

/********************************************************************/
/*                          Internal Functions                      */
/********************************************************************/

// Makes the command_mapping with functions and Helptext.
/* Commands to add
  add_command("do_add", "log add");           // Ready
  add_command("do_list", "log list");         // Ready
  add_command("do_read", "log read");         // Ready
  add_command("do_news", "log news");         // Ready
  add_command("do_reset", "log reset");       // Ready
  add_command("do_remove", "log remove");     // Ready
  add_command("do_help", "log help");         // Under construction
  add_command("do_toggle", "log toggle");     // Ready
  add_command("do_set", "log set");           // Ready
  add_command("do_switch", "log switch");     // Ready
  add_command("do_status", "log status");     // Ready
*/

private void
make_commands() {
  commands = ([
    "add": "do_add"; "log add [option] <arguments>"; "\
                                +---------+\n\
                                | log add |\n\
                                +---------+\n\n\
Syntax       : log add [option] <arguments>\n\n\
Description  : With the option -readindex you add a directory to your list\n\
               of logdirs you want to read.\n\
               With option -index you add a new logdirectory to the\n\
               loggingservice. Arguments are :\n\
               <name>    - An unique name for your logdirectory.\n\
               <path>    - The complete path of the directory with endig /.\n\
               <maxlog>  - Maximal number of entries of the .log-file.\n\
               <maxold>  - Maximal number of entries of the .old-file.\n\
               <swapout> - Number of entries which are swapped out gets the\n\
                           .log-file too long.\n\
               <priv>    - Give a privilege to the index. Means that the\n\
                           object which call the log-function has to own\n\
                           the given privilege. If no privilege is given\n\
                           it is set to 0. --> If you don't know what this\n\
                           means read manual for security. <--\n\n\
Examples     : log add -readindex /players/walchy/seita/log/\n\
               log add -index Walchy /players/walchy/log/ 100 100 30\n\
               log add -index Walchy /players/walchy/log/ 10 10 10 walchy:\n",
    "list": "do_list"; "log list [options]"; "\
                               +----------+\n\
                               | log list |\n\
                               +----------+\n\n\
Syntax       : log list [options]\n\n\
Description  : If you give no options you'll get a list of all your\n\
               selected readindices. News e = new entries in this index\n\
               since your last reset and news a = autonews on.\n\
               As option you can give -current for a list of logfiles\n\
               in the current index or -readindex <name> for a list of\n\
               logfiles in the given readindex.\n\n\
Examples     : log list\n\
               log list -current\n\
               log list -readindex Walchy\n",
    "help": "do_help"; "log help <command or topic>"; "\
                               +----------+\n\
                               | log help |\n\
                               +----------+\n\n\
Syntax       : log help <command or topic>\n\n\
Description  : Shows the help-page of the given command or all possible\n\
               commands. Note that only the command itself is given, not\n\
               the identifer 'log'.\n\n\
Examples     : log help add\n\
               log help toggle\n",
    "news": "do_news"; "log news [-all]"; "\
                               +----------+\n\
                               | log news |\n\
                               +----------+\n\n\
Syntax       : log news [-all]\n\n\
Description  : Shows all logfiles in the current index.\n\
               If you use the option -all every logfile with new entries\n\
               from all added indexes is shown.\n\n\
Examples     : log news\n\
               log news -all\n",
    "set": "do_set"; "log set <option> [<option>]"; "\
                                +---------+\n\
                                | log set |\n\
                                +---------+\n\n\
Syntax       : log set <option> [<option>] ...\n\n\
Description  : You can change the number of entries or the privilege\n\
               of a file or a whole index. With the option -index or\n\
               or -logfile you give what will be changed. -entries and\n\
               three int for the entries per logfile and -privilege with\n\
               a privilege for changing the privilege. You can combine\n\
               the options. (First int is entries in *.log, second entries\n\
               in *.old and the third for number of entries to swapout.)\n\n\
Examples     : log set -index Walchy -privilege walchy:\n\
               log set -logfile explore -entries 100 200 40\n\
               log set -index Seita -privilege seita: -entries 80 150 20\n",
    "switch": "do_switch"; "log switch <index>"; "\
                              +------------+\n\
                              | log switch |\n\
                              +------------+\n\n\
Syntax       : log switch <index>\n\n\
Description  : Switches to the given index. Many functions are only working\n\
               in the current index, eg 'log read' or 'log remove' -logfile.\n\
\n\
Examples     : log switch Walchy\n\n\
See also     : log read, log remove, log toggle\n",
    "status" : "do_status"; "log status [options]"; "\
                              +------------+\n\
                              | log status |\n\
                              +------------+\n\n\
Syntax       : log status [options]\n\n\
Description  : Shows datas about the reader (-main), indexes (-index) or\n\
               logfiles (-logfile). You can combine all flags and add\n\
               more then one name after a flag. So you can look for\n\
               the status of more logfiles in one index.\n\n\
Examples     : log status -main\n\
               log status -index Walchy -logfile test explore\n",
    "toggle": "do_toggle"; "log toggle [options]"; "\
                              +------------+\n\
                              | log toggle |\n\
                              +------------+\n\n\
Syntax       : log toggle [options]\n\n\
Description  : Toggles [options]\n\
               which     Flags      Description\n\
               -------------------------------------------------------------\n\
               -index    -autonews  Toggles the autonews of the whole\n\
                                    directory on or off.\n\
                         -newlogs   Toggles the adding of new logs for the\n\
                                    whole directory on or off. (Only with\n\
                                    access to this directory)\n\
               -logfile  -newlogs   Toggles the adding of a single logfile\n\
                                    on or off. (Only with access) The\n\
                                    logfile is searched in the current\n\
                                    index.\n\
                         -autonews  Toggles the autonews of the given files\n\
                                    on or off. If you set a spezific logfile\n\
                                    for the autonews, you'll only receive news\n\
                                    from this logfiles.\n\
               -main     -header    Toggles the header in the logreading on\n\
                                    or off.\n\
                         -lognews   Toggles the newlogs on or off. Lognews\n\
                                    means that you got a list off all new\n\
                                    logfiles after your login.\n\
               You can combine the flags.\n\n\
Exapmles     : log toggle -main -header\n\
               log toggle -logfile explore -newlogs\n\
               log toggle -index Seita -autonews\n\
               log toggle -logfile explore killer found update -autonews\n\
               log toggle -main -header -lognews\n",
    "read": "do_read"; "log read [options] <logfile>"; "\
                               +----------+\n\
                               | log read |\n\
                               +----------+\n\n\
Syntax       : log read [options] <logfile>\n\n\
Description  : Shows the entries of the given logfile. If no option is\n\
               added all entries since the last timereset are shown.\n\
               -old : With this option also the entries in the *.old\n\
                      file are shown.\n\
               -all : Every entry in the given logfile is shown.\n\
               -object : After this option you have to give a objectname.\n\
                         Like the name of the player or object which\n\
                         causes a logentry.\n\
               -showold : This is a very special option. It works only\n\
                          when the *.old-file isn't stored in the logger\n\
                          dataformat. (Lines 0) You can't combine this\n\
                          option with others.\n\
               You can combine all options expect -showold. The logfile\n\
               is searched in the current index.\n\n\
Examples     : log read killer\n\
               log read -all -object Walchy killer\n",
    "remove": "do_remove"; "log remove [options] <arguments>"; "\
                              +------------+\n\
                              | log remove |\n\
                              +------------+\n\n\
Syntax       : log remove [options] <arguments>\n\n\
Description  : Removes a readindex or a complete index if you\n\
               have access to it. Options are -readindex for an index in the\n\
               reader, -index for a complete index or -logfile for a single\n\
               file. You can also remove only and *.old file with the option\n\
               -oldfile.\n\
               As argument the name of the logdir, index or filename is\n\
               given. Normally when a index is removed only the file\n\
               loglist.o is removed, expect you give the option -all,\n\
               then all files (*.log, *.old and *.o) in this directory\n\
               are removed.\n\n\
Examples     : log remove -readindex Walchy\n\
               log remove -index Seita -all\n\
               log remove -logfile test\n\
               log remove -oldfile test\n",
    "reset": "do_reset"; "log reset <arguments>"; "\
                               +-----------+\n\
                               | log reset |\n\
                               +-----------+\n\n\
Syntax       : log reset <argument>\n\n\
Description  : Sets the checktime of a specific index or all indices to now.\n\
               Give the name of an index as argument or the option '-all'.\n\
               -all means that in all indices the last read date is set to \n\
               now. -here means that the current index is set to now.\n\n\
Examples     : log reset -readindex Walchy\n\
               log reset -all\n\
               log reset -here\n" ]);
  topics = ([ "general": "general";
                         ("General Information about the Logger Daemon\n"
                          "\n"
                          "The daemon is used to create new indices (see"
                          " also 'man logger' for information about the"
                          " log server) and to gain information about the"
                          " log entries in the various logfiles. To ease"
                          " handling all the different logfiles, for each"
                          " user a current index is stored. You can set"
                          " this current index with the command 'log"
                          " switch'.\n"),
              "news-system": "news-system";
                             ("The News-System of the Logger Daemon\n"
                              "\n"
                              "The daemon provides the broadcasting of"
                              " news about logging events. This means"
                              " that you can tell the daemon to notify"
                              " you each time a new entry is logged into"
                              " a specific logfile or to any logfile of"
                              " a specific index.\n"
                              "Use the commands 'log toggle' to tell the"
                              " daemon to notify you of different"
                              " occasions or to stop notifying you.\n") ]);
}

// Returns a string containing anz chars c

private string
make_char(int anz, string c) {
  return sprintf("%'" + c + "'*s",anz,"");
}

// Get screenwidth of player

private int
get_width() {
  return this_player() -> query_property(P_DISPLAY_WIDTH);
}

// Returns a string for formatted output of the mapping lines.
// The mapping lines are returned from SE_LOGGER -> read_log()

string
make_output(mapping lines) {
  int      i;
  string   out;

  if (sizeof(lines[LR_TEXT])) {
    out = "";
    for(i = 0; i < sizeof(lines[LR_LTIME]); i++) {
      out += (nice_date(lines[LR_LTIME][i], 3)+" "+
              sprintf("%-13s%3s ",
                      LIB_STRINGS->cut_string_nicely(lines[LR_OBJNAME][i],12),
                      lines[LR_OBJLEVEL][i])+
              break_string(lines[LR_TEXT][i],0,32,1)+"\n");
    }
  } else {
    out = "No matching entries found.\n";
  }
  return out;
}

// Checks for options in the string args.
// All word after a -word are stored under the mapping key "-word"
// If there a word before a -word appears it is stored with the
// key "unknown".

private mapping
check_args(string args) {
  string   *word, oneword;
  mixed    *one;
  mapping   back;
  int       i, e;

  back = ([ "unknown": ({}) ]);
  word = explode(args||"", " ");
  for( i = 0; i < sizeof(word); i++) {
    if (word[i][0..0] == "-") {
      oneword = word[i];
      if (!member(back, word[i])) {
        back += ([ word[i]: ({}) ]);
        one = ({});
      } else {
        one = back[word[i]];
      }
      e = i;
      while (1 == 1) {
        e ++;
        if (e >= sizeof(word)) {
          i = sizeof(word);
          break;
        }
        if (word[e][0..0] == "-") {
          i = e-1;
          break;
        } else {
          one += ({ word[e] });
          continue;
        }
      }
      back[oneword] = one;
    } else {
      back["unknown"] += ({ word[i] });
    }
  }
  return back;
}

// Functions to store data in the user who uses the daemon.

private mapping
get_data() {  // this_player() --> query_owner(), Coogan, 24-Jun-1998
  return (query_owner()->query_extern_data("logger", "data") ||
          m_allocate(0,3));
}

private void
set_data(mapping d) {
  this_player()->set_extern_data("logger", "data", d);
}

private string
get_current_index() {
  return this_player()->query_extern_data("logger", "current_index") || "";
}

private void
set_current_index(string i) {
  this_player()->set_extern_data("logger", "current_index",i);
}

private status
query_flag(mixed flag) {
  mixed   h;

  h = this_player()->query_extern_data("logger", "flags");
  return mappingp(h) && member(h,flag);
}

private void
set_flag(mixed flag) {
  mixed   h;

  h = this_player()->query_extern_data("logger", "flags") || ([]);
  h += ([ flag ]);
  this_player()->set_extern_data("logger", "flags", h);
}

private void
remove_flag(mixed flag) {
  mixed   h;

  h = this_player()->query_extern_data("logger", "flags") || ([]);
  h -= ([ flag ]);
  this_player()->set_extern_data("logger", "flags", h);
}

private void
check_news(string iname) {
  int       i;
  mixed     indices;
  mapping   data;

  data = get_data();

  if (!iname) {
    indices = m_indices(data);

    for( i = 0; i < sizeof(indices); i++) {
      if (data[indices[i], 1] > 0) {
        SE_LOGGER->add_notify(this_object(), indices[i]);
      } else {
        SE_LOGGER->remove_notify(this_object(), indices[i]);
      }
    }
  } else {
    if (data[iname, 1] > 0) {
      SE_LOGGER->add_notify(this_object(), iname);
    } else {
      SE_LOGGER->remove_notify(this_object(), iname);
    }
  }
}

void
receive_news(mapping news) {
  mapping   data;

  data = get_data();

  if (!member(data, news[L_INDEX])) { return; }

  if (data[news[L_INDEX], 1] > 0) {
    if (data[news[L_INDEX], 1] == 2 &&
        member(data[news[L_INDEX], 2], news[L_FILE]) == -1) {
      return;
    }
    tell_object(query_owner(),
                "\n--- NEWS from '"+news[L_INDEX]+"' file : "+
                news[L_FILE]+" --- "+
                nice_date(news[L_LTIME], 1)+" --- "+
                news[L_OBJNAME]+" ("+news[L_OBJLEVEL]+") ---\n"+
                news[L_TEXT]+"\n");
  }
}

// Returns a string containing the complete list of all selected
// indices of this_player()

private string
make_indices_list() {
  int       i, cdat, rdat;
  string    outdesc;
  mapping   data;
  mixed     indices;

  data = get_data();
  indices = m_indices(data);

  outdesc = "\
                                                             news\n\
Nr : Index             last change        last reset         ea\n\
--------------------------------------------------------------------------\n";      
// : Walchy            27.03.98 13:30:40  26.03.98 12:17:16  **

  if (sizeof(indices)) {
    for (i = 0; i < sizeof(indices); i++) {
      outdesc+=sprintf("%-3s", to_string(i))+": ";
      outdesc+=sprintf("%-17s", indices[i])+" ";
      cdat = SE_LOGGER->last_index_change(indices[i]);
      rdat = data[indices[i], 0];
      outdesc+=sprintf("%-18s", nice_date(cdat,0))+" ";
      outdesc+=sprintf("%-18s", nice_date(rdat,0))+" ";
      if (rdat <= cdat) {
        outdesc += "*";
      } else {
        outdesc += "-";
      }
      switch (data[indices[i], 1]) {
        case 0 : 
          outdesc += "-";
          break;
        case 1 :
          outdesc += "*";
          break;
        case 2 : 
          outdesc += "+";
          break;
      }
      outdesc += "\n";
    }
    if (get_current_index() != "") {
      outdesc += "\nThe current index is "+get_current_index()+".\n";
    } else {
      outdesc += "\nYou are'nt switched to an index now.\n";
    }
  } else {
    outdesc = "Currently there are no readindices.\n";
  }
  return outdesc;
}

// Returns a string containing all logfiles in the index iname.
// checkdata is for newscheck and header if a header is added.

private string
make_logfile_list(string iname, int checkdate, status header) {
  string   *logfiles, outdesc;
  int       i, cdat, *lines;
  mapping   data;

  data = get_data();
  logfiles = SE_LOGGER -> query_index_logfiles(iname);
  if (sizeof(logfiles)) {
    logfiles = sort_array(logfiles, #'>);
    if (header) {
      outdesc = "\
                                                      lines     news\n\
Nr : Logfile                   last change           log  old    ea\n\
--------------------------------------------------------------------\n";
// : explore                   17.04.1998 12:30:34  1234  873*   **
    } else {
      outdesc = "";
    }
    for (i = 0; i < sizeof(logfiles); i++) {
      cdat = SE_LOGGER->query_logfile_lastchange(iname, logfiles[i]);
      lines = SE_LOGGER->query_logfile_lines(iname, logfiles[i]);
      outdesc+=sprintf("%-3s", to_string(i))+": ";
      outdesc+=sprintf("%-25s", logfiles[i])+" ";
      outdesc+=sprintf("%-20s", nice_date(cdat,0))+" ";
      outdesc+=sprintf("%4d", lines[0])+" ";
      outdesc+=sprintf("%4d", lines[1]);
      if (lines[3] == 0) {
        outdesc += "*";
      } else {
        outdesc += " ";
      }
      outdesc += "   ";
      if (cdat >= checkdate) {
        outdesc += "*";
      } else {
        outdesc += "-";
      }
      if (member(data[iname, 2], logfiles[i]) != -1) {
        outdesc += "*";
      } else {
        outdesc += "-";
      }
      outdesc += "\n";
    }
  } else {
    outdesc = "This index is unknown or empty.\n";
  }
  return outdesc;
}

// Returns a string containing all logfiles with new entries in all
// selected indices.

private string
make_news_list() {
  string    outdesc, *logfiles, *newsfiles;
  mapping   data;
  mixed    *indices;
  int       i, lf;

  data = get_data();
  indices = m_indices(data);
  outdesc = "";

  for (i = 0; i < sizeof(indices); i++) {
    logfiles = sort_array(SE_LOGGER -> query_index_logfiles(indices[i]), #'>);
    newsfiles = ({});
    for (lf = 0; lf < sizeof(logfiles); lf++) {
      if (SE_LOGGER -> query_logfile_lastchange(indices[i], logfiles[lf]) >=
          data[indices[i], 0]) {
        newsfiles += ({ logfiles[lf] });
      }
    }
    if (sizeof(newsfiles)) {
      outdesc += "\n--- News in index "+indices[i]+" (Last reset : "+
                 nice_date(data[indices[i], 0],0)+") : ---\n"+
                 make_list(newsfiles)+".\n";
    }
  }
  return outdesc;
}

/********************************************************************/
/*                           Command Functions                      */
/********************************************************************/

status
do_help(string comm) {
  int     i;
  mixed   coms;

  if (member(commands, comm)) {
    this_player()->view_text(break_string(commands[comm, 2]),
                             "Logger help : "+comm+".");
    this_player()->start_view();
    return 1;
  }
  if (member(topics, comm)) {
    this_player()->view_text(break_string(topics[comm, 1]),
                             "Topic : "+comm+".");
    this_player()->start_view();
    return 1;
  }
  coms = sort_array(m_indices(commands),#'>);
  message(" Commands of the logdaemon : \n\n");
  for (i = 0; i < sizeof(coms); i++) {
    message(commands[coms[i], 1]+"\n");
  }
  coms = m_indices(topics);
  if (sizeof(coms)) {
    message("\n Other topics : \n\n");
    for (i = 0; i < sizeof(coms); i++) {
      message(topics[coms[i], 0]+"\n");
    }
  }
  return 1;
}

status
do_add(string s) {
  int       i;
  mixed     h, priv, error, indices;
  string   *does_not_exist;
  mapping   args, data;

  args = check_args(s);

  if (args["-readindex"]) {  // does it exist?
    // add a new index to ones which are of interest for us
    data = get_data();
    h = args["-readindex"];
    does_not_exist = ({});
    for (i=sizeof(h); i-->0; ) {
      data[h[i], 0] = time();
      data[h[i], 1] = 0;    // initialized as: no news
      data[h[i], 2] = ({}); // Empty for file-autonews. 
      if (!SE_LOGGER->index_exists(h[i]))
        does_not_exist += ({ h[i] });
    }
    send_message(({ "Added new ",M_DESCRIBE_GROUP,"index",h,
                    ": " + make_list(h,"(none)") }));
    if (sizeof(does_not_exist))
      send_message(({ "WARNING: ",M_NONE,does_not_exist,
                      M_VERB,"do",does_not_exist,
                      " not exist (yet)!" }));
    set_data(data);
    return 1;
  }
  if (h=args["-index"]) {
    if (sizeof(h) < 5) {
      message("Not enough parameters to ladd -index. lhelp ladd for more "+
              "information.\n");
      return 1;
    }
    if (sizeof(h) == 6) {
      priv = h[5];
    } else {
      priv = 0;
    }
    if (error=catch(SE_LOGGER->add_index(h[1], h[0],
                                         to_int(h[2]),
                                         to_int(h[3]),
                                         to_int(h[4]), priv))) {
      if (!pointerp(error)) {
        return 0;
#if 0
        raise_error(error);
#endif
      }
      switch (error[0]) {
      case L_B_ALREADY_IN_USE:
        tell_object(this_player(), "The logname '"+h[0]+
                    "' is already in use "+"by "+error[1]+".\n");
        return 1;
      case L_B_NO_SUCH_PATH:
        tell_object(this_player(), "The path '"+h[1]+"' doesn't exists.\n");
        return 1;
      case L_B_NO_WRITE_PERMISSIONS:
        tell_object(this_player(), "You have no write permission to '"+h[1]+
                    "'.\n");
        return 1;
      case L_B_DIRECTORY_NOT_FREE:
        tell_object(this_player(), "This path is already used by "+error[1]+
                    " with the name '"+error[2]+".\n");
        return 1;
      }
    }
    // we also add it to the interesting indices for this user...
    do_add("-readindex "+h[0]);
    return 1;
  }
  return do_help("add");
}

void check_log_dir() {}

int
do_switch(string args) {
  mapping data;
  data = get_data();
  if (!args || !strlen(args)) {
    return do_help("switch");
  }
  if (!member(data,args)) {
    message(args+" isn't in the list.\n");
    return 1;
  }
  if (SE_LOGGER->index_exists(args)) {
    set_current_index(args);
    check_log_dir();
    message("Switched to index "+args+".\n");
  } else {
    message("WARNING: Index not found.\n");
  }
  return 1;
}

int
do_status(string arg) {
  mapping   args;
  string    out;
  int       i;

  if (!arg || !strlen(arg)) {
    return do_help("status");
  }
  args = check_args(arg);
  out = "";

  if (member(args, "-main")) {
    out += "\n--- Main Status : ----------\n"+
           "Header     : ";
    if (query_flag(L_NO_HEADER)) {
      out += "off";
    } else {
      out += "on";
    }
    out += "\nLogin news : ";
    if (query_flag(L_LOGONNEWS)) {
      out += "on";
    } else {
      out += "off";
    }
    out += "\n# of index : "+to_string(sizeof(m_indices(get_data())))+".\n";
  }
  if (member(args, "-index")) {
    if (sizeof(args["-index"]) > 0) {
      for (i = 0; i < sizeof(args["-index"]); i++) {
        out += "\n--- Indexstatus '"+args["-index"][i]+"' : ----------\n";
        out += SE_LOGGER -> info_index(args["-index"][i], 0);
      }
    }
  }
  if (member(args, "-logfile")) {
    if (sizeof(args["-logfile"]) > 0) {
      for (i = 0; i < sizeof(args["-logfile"]); i++) {
        out += "\n--- Logfilestatus '"+args["-logfile"][i]+"' : ----------\n";
        out += SE_LOGGER -> info_index(get_current_index(),
                                       args["-logfile"][i]);
      }
    }
  }
  if (strlen(out) > 0) {
    this_player() -> view_text(out+"\n", "Loggerstatus.");
    this_player() -> start_view();
  }
  return 1;
}

int
do_toggle(string arg) {
  int       logdir, logname, i;
  string    out, *on ,*off;
  mapping   args, data;

  if (!arg || !strlen(arg)) {
    return do_help("toggle");
  }

  args = check_args(arg);
  data = get_data();

  if (member(args, "-main")) {
    if (member(args, "-header")) {
      if (query_flag(L_NO_HEADER)) {
        remove_flag(L_NO_HEADER);
        message("Set readheader on.\n");
      } else {
        set_flag(L_NO_HEADER);
        message("Set readheader off.\n");
      }
    }
    if (member(args, "-lognews")) {
      if (query_flag(L_LOGONNEWS)) {
        remove_flag(L_LOGONNEWS);
        message("Set log-on-news off.\n");
      } else {
        set_flag(L_LOGONNEWS);
        message("Set log-on-news on.\n");
      }
    }
    return 1;
  }

  if (member(args, "-index")) {
    if (member(data, args["-index"][0])) {
      if (member(args, "-autonews")) {
        if (data[args["-index"][0], 1]) {
          data[args["-index"][0], 1] = 0;
          message("Autonews of "+args["-index"][0]+" off.\n");
        } else {
          data[args["-index"][0], 1] = 1;
          message("Autonews of "+args["-index"][0]+" on.\n");
        }
        data[args["-index"][0], 2] = ({});
        set_data(data);
        check_news(args["-index"][0]);
      }
      if (member(args, "-newlogs")) {
        switch (SE_LOGGER -> toggle_new_logs(args["-index"][0], 0)) {
          case -2 : message("No access to this dirctory.\n");
          case  1 : message("Directory toggled.\n");
        }
        out = "--- New Indexdata '"+args["-index"][0]+"' : ---\n";
        out += SE_LOGGER -> info_index(args["-index"][0], 0);
        this_player() -> view_text(out+"\n", "Loggerstatus.");
        this_player() -> start_view();
      }
      return 1;
    }
  }

  if (member(args, "-logfile")) {
    if (SE_LOGGER->logfile_exists(get_current_index(),
                                  args["-logfile"][0])) {
      if (member(args, "-autonews")) {
        on = ({});
        off = ({});
        for (i = 0; i < sizeof(args["-logfile"]); i++) {
          if (member(data[get_current_index(), 2],
                     args["-logfile"][i]) == -1) {
            data[get_current_index(), 2] += ({ args["-logfile"][i] });
            on += ({ args["-logfile"][i] });
            data[get_current_index(), 1] = 2;
          } else {
            data[get_current_index(), 2] -= ({ args["-logfile"][i] });
            off += ({ args["-logfile"][i] });
            if (sizeof(data[get_current_index(), 2]) < 1) {
              data[get_current_index(), 1] = 0;
            }
          }
        }
        if (sizeof(on)) {
          message("Logfiles on : "+make_list(on)+".\n");
        }
        if (sizeof(off)) {
          message("Logfiles off : "+make_list(off)+".\n");
        }
        check_news(get_current_index());
        set_data(data);
        return 1;
      }
      if (member(args, "-newlogs")) {
        switch (SE_LOGGER->toggle_new_logs(get_current_index(),
                                           args["-logfile"][0])) {
          case -2 : message("No access to this dirctory.\n");
          case  1 : message("Directory toggled.\n");
        }
        out = "--- New Logfiledata '"+args["-logfile"][0]+"' : ---\n";
        out += SE_LOGGER -> info_index(get_current_index(),
                                       args["-logfile"][0], 0);
        this_player() -> view_text(out+"\n", "Loggerstatus.");
        this_player() -> start_view();
      }
      return 1;
    }
  }
  message("The first argument is not 'main' nor an index nor a "
          "single logfile in the current index.\n");
  return 1;
}

int
do_news(string arg) {
  mapping   args, data;

  args = check_args(arg);
  data = get_data();

  check_news(0);

  if (member(args, "-all")) {
    this_player()->view_text(make_news_list(), "News list");
    this_player()->start_view();
    return 1;
  }
  this_player()->view_text(make_logfile_list(get_current_index(),
                                             data[get_current_index(), 0], 1),
                           "Logfile list : "+get_current_index());
  this_player()->start_view();
  return 1;  
}

int
do_list(string arg) {
  mapping   args, data;
  status    found;
  string    out, text;

  args = check_args(arg);
  data = get_data();
  found = 0;

  check_news(0);

  if (member(args, "-current")) {
    if (get_current_index() == "") {
      message("There is no current index.\n");
      return 1;
    }
    found = 1;
    out = make_logfile_list(get_current_index(),
                            data[get_current_index(), 0], 1);
    text = "Logfile list : "+get_current_index();
  }
  if (member(args, "-readindex")) {
    if (!member(data, args["-readindex"][0])) {
      message("There is no readindex called "+args["-readindex"][0]+".\n");
      return 1;
    } else {
      found = 1;
      out = make_logfile_list(args["-readindex"][0],
                              data[args["-readindex"][0], 0], 1);
      text = "Logfile list : "+args["-readindex"][0];
    }
  }

  if (!found) {
    out = make_indices_list();
    text = "Indices list";
  }
  this_player()->view_text(out, text);
  this_player()->start_view();
  return 1;
}

int
do_remove(string arg) {
  mapping   args, data;
  mixed     indices;
  string   *word, sname;
  int       name, back;

  args = check_args(arg);
  data = get_data();
  indices = m_indices(data);

  if(member(args, "-readindex")) {
    sname = args["-readindex"][0];
    if (!member(data, sname)) {
      message("The readindex "+sname+" is unknown.\n");
      return 1;
    }
    if (sname == get_current_index()) {
      set_current_index("");
    }
    data -= ([ sname ]);
    set_data(data);
    check_news(sname);
    message("The readindex "+sname+" is removed.\n");
    return 1;    
  }
  if (member(args, "-index")) {
    if (member(args, "-all")) {
      back = SE_LOGGER -> remove_index(args["-index"][0], 1);
    } else {
      back = SE_LOGGER -> remove_index(args["-index"][0], 0);
    }
    switch(back) {
      case -1 :
        message("Unknown index : "+args["-index"][0]+".\n");
        break;
      case -2 :
        message("No privilege to "+args["-index"][0]+".\n");
        break;
      case 1 :
        message("Index "+args["-index"][0]+" successfully removed.\n");
        do_remove("-readindex "+args["-index"][0]);
        break;
    }
    return 1;
  }
  if (member(args, "-logfile") ||
      member(args, "-oldfile")) {
    if (member(args, "-logfile")) {
      sname = args["-logfile"][0];
      back = SE_LOGGER -> remove_log_file(get_current_index(),
                                          args["-logfile"][0], 0);
    } else {
      sname = args["-oldfile"][0];
      back = SE_LOGGER -> remove_log_file(get_current_index(),
                                          args["-oldfile"][0], 1);
    }
    switch (back) {
      case 0 :
        message("Unknown index : "+get_current_index()+".\n");
        break;
      case -1 :
        message("Unknown logfile : "+sname+".\n");
        break;
      case -2 :
        message("No access to index "+get_current_index()+".\n");
        break;
      case 1 :
        message("Logfile "+sname+" removed.\n");
        break;
    }
    return 1;
  }
  return do_help("remove");
}

int
do_reset(string arg) {
  int       i;
  mapping   args, data;
  mixed     indices;

  if (!arg || !strlen(arg)) {
    return do_help("reset");
  }

  args = check_args(arg);
  data = get_data();
  indices = m_indices(data);

  if (member(args, "-all")) {
    for (i = 0; i < sizeof(indices); i++) {
      data[indices[i], 0] = time();
    }
    message("All readindices last checktime is set to now.\n");
    set_data(data);
    return 1;    
  }
  if (member(args, "-here")) {
    data[get_current_index(), 0] = time();
    message("Readindex "+get_current_index()+" set to now.\n");
    set_data(data);
    return 1;
  }
  if (member(args, "-readindex")) {
    for (i = 0; i < sizeof(args["-readindex"]); i++) {
      data[args["-readindex"][i], 0] = time();
    }
    send_message( ({ M_DESCRIBE_GROUP, "index", args["-readindex"],
                     ": " + make_list(args["-readindex"] ,"(none)"), " ",
                     M_DESCRIBE_GROUP, "are", args["-readindex"],
                     " set to now." }) );
    // ^^ To do !!!!
    set_data(data);
    return 1;
  }
  return 0;
}

int
do_set(string arg) {
  mapping   args;
  int       i;
  string    out;

  if (!arg || !strlen(arg)) {
    return do_help("set");
  }

  args = check_args(arg);

  if (member(args, "-privilege")) {
    if (sizeof(args["-privilege"]) > 0) {
      if (args["-privilege"][0] == "0") { args["-privilege"][0] = 0; }
      if (args["-privilege"][0] == "1") { args["-privilege"][0] = 1; }
    } else {
      args["-privilege"][0] = 0;
    }
  }
  if (member(args, "-entries")) {
    if (sizeof(args["-entries"]) != 3) {
      message("Invalid number of arguments to -entries.\n");
      return 1;
    }
    for (i = 0; i < 3; i++) {
      args["-entries"][i] = to_int(args["-entries"][i]);
    }
  }

  if(member(args, "-index")) {
    if (member(args, "-privilege")) {
      SE_LOGGER -> set_new_privilege(args["-index"][0], 0,
                                     args["-privilege"][0]);
    }
    if (member(args, "-entries")) {
      SE_LOGGER -> set_new_entrynr(args["-index"][0], 0,
                                   args["-entries"]);
    }
    out = "--- New Indexdata '"+args["-index"][0]+"' : ---\n";
    out += SE_LOGGER -> info_index(args["-index"][0], 0);
    this_player() -> view_text(out+"\n", "Loggerstatus.");
    this_player() -> start_view();
    return 1;
  }
  if(member(args, "-logfile")) {
    if (member(args, "-privilege")) {
      SE_LOGGER -> set_new_privilege(get_current_index(),
                                     args["-logfile"][0],
                                     args["-privilege"][0]);
    }
    if (member(args, "-entries")) {
      SE_LOGGER -> set_new_entrynr(get_current_index(),
                                   args["-logfile"][0],
                                   args["-entries"]);
    }
    out = "--- New Logfiledata '"+args["-logfile"][0]+"' : ---\n";
    out += SE_LOGGER -> info_index(get_current_index(),
                                   args["-logfile"][0]);
    this_player() -> view_text(out+"\n", "Loggerstatus.");
    this_player() -> start_view();
    return 1;
  }
  return 1;
}

int
do_read(string arg) {
  string  *args, *check;
  string   lname, pname;
  string   compout;
  mixed   *flags;
  mixed    lines;
  int      i, stime, old;

  if (!arg || !strlen(arg)) {
    do_news(0);
    return 1;
  }

  old = 0;
  stime = 0;
  flags = ({});
  args = explode(arg, " ");

  if (member(args, "-showold") != -1) {
    // -showold was given, just give out the unlimited oldfiles
    // UNFINISHED: BUG WILL BE RAISED
    lname = args[1];
    if (!SE_LOGGER->logfile_exists(get_current_index(),lname)) {
      message("There is no log called '"+lname+"'.\n");
      return 1;
    }
    if (!SE_LOGGER->oldfile_is_unlimited(get_current_index(),lname)) {
      message("The *.old-file is stored as normal logdata. Use the option "
              "-old to include it to the output.\n");
      return 1;
    }
    old = 1;
  } else {  // no -showold was given, give out normal logfiles
    for(i = 0; i < sizeof(args); i++) {
      check = explode(args[i], "");
      if (check[0] == "-") {
        if (args[i] == "-all") {
          flags += ({ L_SHOWALL });
          continue;
        }
        if (args[i] == "-object" || args[i] == "-obj") {
          flags += ({ L_OBJECT, args[i+1] });
          i++;
          continue;
        }
        if (args[i] == "-old") {
          flags += ({ L_SHOWOLD });
          continue;
        }
      } else {  // didn't start with -
        lname = args[i];
        break;
      }
    }
  }
  if (SE_LOGGER->logfile_exists(get_current_index(),lname)) {
                                                        // does this log exist?
    compout = "";
    if (!old) {  // not the unlimited oldfiles?
      stime = get_data()[get_current_index(),0];
      lines = SE_LOGGER->read_log(lname,get_current_index(),stime,flags);
    }
    if (!query_flag(L_NO_HEADER)) {
      if (!old) {
        compout += "Date     ";
      } else {
        compout += " Date     ";
      }
      compout += ("Time  Player        Lv Text\n"+
                  make_char(get_width(), "-")+"\n");
    }
    if (!old) {  // not the unlimited logfiles?
      compout += make_output(lines);
    } else {  // yes, the unlimited logfiles
      compout += SE_LOGGER->load_unlimited_log(get_current_index(),lname);
    }
    this_player()->view_text(compout,
                             "Log : "+get_current_index()+", "+lname);
    this_player()->start_view();
  } else {
    message("Unknown logfile : "+lname+".\n");
  }
  return 1;
}

status
log_command(string s, string verb) {
  string   *word;
  string    args;

  if (!s)
    return do_help(""), 1;

  word = explode(s, " ");
  args = implode(word[1..], " ");

  if (member(commands, word[0])) {
//    notify_fail("Internal error.\n");
    return call_other(this_object(), commands[word[0], 0], args);
  }
  notify_fail("Unknown command.\n");
  return 0;
}

/********************************************************************/
/*                            Init Functions                        */
/********************************************************************/

void
notify_login(string name) {
  object   pl;

  if ( !(pl = find_player(name)) ||
       !is_wizard(pl) ||
       !query_flag(L_LOGONNEWS) ||
       pl != query_owner()) { return; }
  with_player(pl, #'do_news, ({ "-all" }));
}

void
notify_depetrify(string s) {
  notify_login(s);
}

void create() {
  make_commands();
  add_command("log_command", "log");
  set_auto_clone();

#if 0  // check for news only after all creation is completed.
       // Alfe 1998-Jun-24
  if (clonep(this_object())) {
    check_news(0);
    SE_USERS->add_notify();
  }
#endif

  set_privilege(1);

  create::create();
}

#if 1  // Alfe 1998-Jun-24
void set_player(string name) {
  // not inherited:  daemon::set_player(name);
  if (clonep(this_object())) {
    check_news(0);
    SE_USERS->add_notify();
  }
}
#endif
