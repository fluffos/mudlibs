#pragma strong_types

#include <money.h>
#include <grammar.h>
#include <prop/player.h>
#include <sequence.h>
#include <regexps.h>
#include <message.h>   // Chameloid, 28-Apr-96
#include <gender.h>    // Chameloid, 28-Apr-96
#include <wizlevels.h> // Chameloid, 28-Aug-96
#include <kernel.h>    // Chameloid, 28-Aug-96
#include <libs.h>      // Chameloid, 28-Aug-96
#include <closures.h>  // Chameloid, 3-Sep-96
#include <who.h>       // Chameloid, 3-Sep-96
#include <names.h>     // Chameloid, 3-Jan-97
#include <server.h>    // Coogan, 19-Apr-99
#include <published/peerage.h>  // Coogan, 30-Sep-99
#include <termcol.h>   // Coogan, 01-Mar-00, 25-Nov-2003
#include <encoding.h>  // Alfe, 2004-May-21

inherit "basic/coloured_string";  // Alfe, 16-Feb-01

string repeat_string(string rep,int n) {
  string *out;
  out = allocate(n);
  while (--n >= 0)
    out[n] = rep;
  return implode(out,"");
}

private varargs mixed generate_who_line(object o, status wiz, int width,
        status verbose, string* groups, mapping important, status short) {
  // made varargs, added short for short-who queries, Coogan, 07-Feb-02
  string *seniors,*elders,*arches,*gods,name,class;
  mixed tmp,h;
  status cloaked;
  status group_given;  // Coogan, 30-Sep-99
  string* g;
  int strlen_difference;  // difference between verbatim strlen and coloured.

  group_given = !!groups;

  // embedded each call of filterable functions to the player object to
  // be displayed into a with_player() with this_object() as this_player()
  // if none is set to avoid strange output,
  // Chameloid, 30-Jan-96

  if (!with_player(this_player() || this_object(),
                   #'call_other, ({ o,"short" })))
    tmp = (wiz? "["+o->query_vis_name()+"]" : 0);
  else
    tmp = capitalize_coloured(with_player(this_player() || this_object(),
                                          (#'describe),
                                          ({ o,ARTICLE_A,DESCRIBE_FULL })));
  h = with_player(this_player() || this_object(),
                  (#'call_other),({ o,"query_name" }));
  cloaked = (h != o->call_with_limited_filters(#'call_other,0,-1,
                                               o,"query_name"));
  if (!tmp || !wiz && group_given && cloaked)
    return 0;
  name = o->query_real_name();
  seniors = important["seniors"] || ({}); // Surak, 2-Jan-00
  elders = important["elders"] || ({});
  arches = important["arches"] || ({});
  gods = important["gods"] || ({});
  if (!wiz && cloaked)
    class = "??";
  else if (is_wizard(o))
    if (member(gods, name) >= 0)
      class = "GD";
    else if (member(arches, name) >= 0)
      class = "AR";
    else if (member(elders, name) >= 0)
      class = "EL";
    else if (member(seniors, name) >= 0)  // Surak, 2-Jan-00
      class = "SE";
    else
      class = "WZ";
  else
    class = sprintf("%:2'0'i",o->query_level());

#ifdef PEERAGE
  g = PEERAGE_CLAN_NAMES + ({ "clans" });
  if (sizeof((PEERAGE_CLAN_NAMES + ({ "clans" })) &
             (m_indices(groups || ([ ]))))) {
    int rank;
    rank = PEERAGE_RANK(name);
    class = capitalize_coloured(PEERAGE_CLAN(name)[0..0]);
    if (rank)
      class = class + rank;
    else
      class = " " + class;
  }
#endif

  if (short) {  // Coogan, 07-Feb-02
    if (o->query_away() && h[0..6] == "absent ")
      h = h[7..];  // cut "absent "
    if (cloaked) {
      h = capitalize(describe(h, ARTICLE_A));
    }
    return sprintf("%'.'-11.11s [%:2s]", h, class);
  }

  strlen_difference = strlen(tmp) - strlen_visible(tmp);
  if (verbose) {
    tmp = subcoloured_string(tmp, 0, width-16-1);  // Coogan, 11-Jan-02
    return sprintf("   | %:*'_'s %:4s |",
                   16 - width - strlen_difference,
                   tmp + " ",
                   "[" + class + "]");
  } else {
    tmp = subcoloured_string(tmp, 0, width-11-1);  // Coogan, 11-Jan-02
    return sprintf("   | %:*s |",
                   11 - width - strlen_difference,
                   tmp);
  }
}

varargs string who_string(string mode, mapping parsed, mapping groups,
                          mixed intermud, string area) {
  // made intermud 'mixed', Coogan, 07-Feb-02
  // added arg 'area', Coogan, 06-Jan-2003, for MoMu
  int i,j,width;
  string one, *im_options;
  status wiz,all;
  mixed *u;  // changed to mixed *, Coogan, 18-Oct-00
  mixed h;
  int short, alpha, vert;  // Coogan, 07-Feb-02
  int k, l;

  if (!parsed) {
    u = users();
    all = 1;
  } else {
    u = filter(m_indices(mkmapping(m_values(parsed))),#'objectp);
    if (groups && this_player() && member(u, this_player()) < 0 &&
        (widthof(groups) == 0 ||  // widthof(), Coogan, 20-Jan-2004
         member(flatten_array(m_values(groups)),
                this_player()->query_real_name()) >= 0))
      u += ({ this_player() });
    u = filter(u, #'interactive);
  }

  alpha = 1;  // Coogan, 08-Feb-02
  vert  = 1;

  if (intermud) {  // Coogan, 07-Feb-02, for different intermud requests
    short = (sizeof(u) > 20);
    if (stringp(intermud)) {
      im_options = explode(intermud, " ") - ({ "" });
      foreach (one : im_options) {
        switch (one) {
          case "alpha" : alpha = 1; break;
          case "short" : short = 1; break;
          case "long"  : short = 0; break;
          case "vert"  : vert  = 1; break;
          case "horiz" : vert  = 0; break;
          case "level" : alpha = 0; break;
        }
      }
    }
  }

  if (groups && member(groups,"all")) {
    groups = 0;
    all = 1;
  }

  wiz = is_wizard(this_player());
  if (!mode)
    mode = (this_player() && !this_player()->query_property(P_VERBOSE_WHO)?
            WHO_MODE_BRIEF : WHO_MODE_VERBOSE);
  switch (mode) {
  case WHO_MODE_BRIEF: // fall through
  case WHO_MODE_SHORT: // fall through
  case WHO_MODE_VERBOSE:
    if (this_player())
      width = this_player()->query_property(P_DISPLAY_WIDTH) || 79;
    else
      width = 79;
    if (mode == WHO_MODE_SHORT) {  // Coogan, 08-Feb-02
      short = 1;
      if (width < 78)
        return "Display list must be 78 at least to view the short-who mode.\n";
    }
    if (intermud && alpha == 0)  // Coogan, 07-Feb-02
      u = sort_objects(u, "query_level", #'>);
    else
      u = sort_objects(u, "query_name", #'>);
    h = map_indices(mkmapping(u), #'generate_who_line, wiz, width,
                    mode==WHO_MODE_VERBOSE, groups,
                    map_indices(mkmapping(({ "seniors", "elders", "arches",
                                             "gods" })),
                                "query_mailing_list","room/mailing_lists"),
                    short);
    u = filter(u,lambda(({ 'x }),({ CL_INDEX,h,'x })));
    h = map(u,lambda(({ 'x }),({ CL_INDEX,h,'x })));
    if (short) {  // Coogan, 07-Feb-02
      if (vert) {
#if 0
        h = ({ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" });
        h = h[0..9];
#endif
#if 1  /* strange code to make out of
          ,---------.
          | a c e   |
          | b d     |
          `---------'
          this list:
          ,---------.
          | a c d e |
          | b       |
          `---------'
          do we really want this?  maybe this would be better:
          ,---------.
          | a b c d |
          | e       |
          `---------'
          or this:      or this:   
          ,---------.   ,---------.
          |  a c e  |   | a  c  e |
          |  b d    |   | b  d    |
          `---------'   `---------'
          the current code also makes out of this:
          ,---------.
          | a d g j |
          | b e h   |
          | c f i   |
          `---------'
          this:
          ,---------.
          | a d g i |
          | b e h j |
          | c f     |
          `---------'
          Alfe 2006-Jul-14
        */
        if ((k = sizeof(h) % 4)) {
          // we have to add something, otherwise the output might be only
          // three columns wide.
          k = 4 - k;                    // amount of missing items
          l = (sizeof(h) + k) / 4;      // amount of lines
#if 0
          debug("coogan", ({ k, l }));
#endif
          if (k == 3) {  // insert an empty element at the bottom of 2nd column
            h[(l*2-1)..(l*2-2)] = ({ "" });
            k = 2;
          }
          if (k == 2) {  // insert an empty element at the bottom of 3rd column
            h[(l*3-1)..(l*3-2)] = ({ "" });
            k = 1;
          }
        }
#endif
#if 1
        h = explode(sprintf("%#-68.4s", implode(h, "\n")), "\n");
#else
        h = explode(sprintf("%#-68s", implode(h, "\n")), "\n");
#endif
        for (j=sizeof(h); j-->0; )
          h[j] = sprintf("   | %-67.67s %s|",
                         h[j], repeat_string(" ", width-78));
      } else {  // sorting horizontal
        while (sizeof(h) < 8)
          h += ({ "" });
        if ((i = sizeof(h) % 4))
          i -= 4;
          while (i) {
            h += ({ "" });
            i++;
          }
        for (j = 0; ;) {
          if (sizeof(h) >= j+4) {
            h[j..j+3] = ({ sprintf("   | %-16s %-16s %-16s %-16s %s|",
                                   h[j], h[j+1], h[j+2], h[j+3],
                                   repeat_string(" ", width-78)) });
            j++;
          } else
            break;
        }
      }
    }
    if (intermud)
      one = "1"; 
    else
      one = "one";
    h[0..-1] = ({ sprintf(" %'_'*s",width-7,""),
                  sprintf("/%*s/ \\",width-9,""),
                  sprintf("%|:*s|   |",width-9,
                          message2string(({"There ",M_VERB,"are",u," ",
                                           (groups?
                                            (!sizeof(u)?
                                             "nobody":
                                             describe(one + " person",0,0,
                                                      sizeof(u))):
                                            (!sizeof(u)?
                                             (!parsed?
                                              "nobody":
                                              "no such person"):
                                             describe((all?
                                                       one+" person":
                                                       one+" such person"),
                                                      0,0,sizeof(u))))})+
                                         (groups?({" of the given ",
                                                   M_DESCRIBE_GROUP,"group",
                                                   sizeof(groups)}):({}))+
                                         ({ (" on " +
                                             (area || capitalize(DOMAIN)) +
                                             (intermud?" ("+HOME_HOST_FULL+" "+
                                              query_mud_port()+")":"")+".") }),
                                         // Chameloid, 3-Jan-97
                                         this_object())),
                  sprintf("\\%'_'*s\\_/|",width-9,""),
                  sprintf("   |%*s|",width-9,"") });
    h[<0..<1] = ({ sprintf("    \\%'_'*s\\_/",width-9,"") });
    h[<4][<0..<1] = "__";
    h[<3][<0..<1] = "/ \\";
    h[<2][<0..<1] = "   |";
    if (intermud)  // Coogan, 16-Feb-01
      return terminal_colour(implode(h,"\n")+"\n",
                             LIB_CNTL_SEQUENCES->get_plain_mapping());
    return implode(h,"\n")+"\n";
  case WHO_MODE_EXTRA_BRIEF:
    if (!wiz)
      u = filter_objects(u,"short");
    for (i=sizeof(u); i--; )
      if (u[i]->query_name() != 
          u[i]->call_with_limited_filters(#'call_other,0,-1,
                                          u[i],"query_name"))  // cloaked?
        if (wiz)
          u[i] = ((u[i]->short()? u[i]->query_name()+" " : "")+"["+
                  u[i]->query_vis_name()+"]");
        else
          u[i] = u[i]->query_name();
      else
        u[i] = u[i]->query_name();                                 
    u = sort_array(map(u,#'capitalize_coloured),#'>);
    return break_string(make_list(u,"")+".\n");
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

varargs status who(status no_more,string mode) {
  mixed h;
  if (no_more || !this_player())
    message(who_string(mode));
  else
    this_player()->tell_more(who_string(mode));
  return 1;
}

status help(string topic) {
  if (topic == "wizard" && this_player()->query_level() >= WL_APPRENTICE) {
    cat("/doc/wiz_help");
    return 1;
  }
  if (topic) {
    /* added to prevent errors at help requests with SPACE 
       -- Ardanna 04-Jun-1992*/
    if (sizeof(explode(topic," ")) > 1) {
      notify_fail("No such help file.\n");
      return 0;
    }
    /* modified to check for illegal help paths -- Demos 21-Oct-1991 */
    if ((sizeof(explode(topic,"/")) > 1) ||
        file_size("/doc/helpdir/"+topic) <= 0) {
      notify_fail("No such help file.\n");
      return 0;
    }
    this_player()->view_text(read_file("/doc/helpdir/"+topic),"help "+topic);
    this_player()->start_view();
    return 1;
  }
  this_player()->view_text(read_file("/doc/help"),"help");
  this_player()->start_view();
  // replaced the old cat("/doc/help"),  Alfe 96-Feb-10
  return 1;
}

int do_action(string action,mapping args)
{
  mixed h,t,c;
  string output,s,s2, s3, *skills,*cointypes;
  int i,*coinamount,num,exp;
  object ob, ob2, *ol1, *ol2;

  switch (action) {
  case "toggle":  // Alfe 96-Jan-30
#if 1  // Alfe 2004-Sep-10
    h = ({
      "'look' ("      + (this_player()->query_property(P_COMBINED)?
                         "combined" : "long")+")",
      "'map' ("       + (this_player()->query_property(P_LITTLEMAP)?
                         "on" : "off")+")",
      "'echo' ("      + (this_player()->query_property(P_ECHO)?
                         "on" : "off")+")",
      "'more' ("      + (this_player()->query_property(P_NO_MORE)?
                         "disabled" : "enabled")+")",
      "'output' ("    + (this_player()->query_output()?
                         "on" : "off")+")",
      "'history' ("   + (this_player()->query_input_history()?
                         "on" : "off")+")",
      "'monitor' ("   + (this_player()->query_property(P_MONITOR)?
                         "on" : "off")+")",
      "'inventory' (" + (this_player()->query_property(P_ADD_INVENTORY)?
                         "on" : "off")+")",
      "'who' ("       + (this_player()->query_property(P_VERBOSE_WHO)?
                         "on" : "off")+")",
      "'refuse' ("    + (this_player()->query_property(P_AUTO_REFUSE)?
                         "on" : "off")+")",
      "'beep' ("      + (this_player()->query_property(P_DONT_BEEP)?
                         "no" : "yes")+ ")",
      "'fails' ("     + (this_player()->query_property(P_ALL_FAIL_MESSAGES)?
                         "all" : "one")+ ")",
      // P_HIDE_AUTOLOADS by Coogan, 29-Apr-99
      "'autoloads' (" + (this_player()->query_property(P_HIDE_AUTOLOADS)?
                         "hidden" : "visible") + ")",
      "'brief' ("     + (this_player()->query_brief()?
                         "on" : "off") + ")",
      "'resize' ("    + ((i=this_player()->query_property(P_RESIZE_WINDOW))<0?
                         (i==-1? "off" : "on, silently") :
                         (i== 1? "on, verbose" : "notice")) + ")",
      "'encoding' ("  + ENCODING_DESCS[this_player()->query_encoding()] + ")",
      "'inputencoding' (" + (ENCODING_DESCS[this_player()->
                                            query_encoding(1)] + ")"),
    });
    notify_fail("You may toggle " + make_list(h, 0, " or ") + ".\n");
#else
    notify_fail("You may toggle 'look' ("+
                (this_player()->query_property(P_COMBINED)?
                 "combined" : "long")+"), 'map' ("+
                (this_player()->query_property(P_LITTLEMAP)?
                 "on" : "off")+"), 'echo' ("+
                (this_player()->query_property(P_ECHO)?
                 "on" : "off")+"), 'more' ("+
                (this_player()->query_property(P_NO_MORE)?
                 "disabled" : "enabled")+"), 'output' ("+
                (this_player()->query_output()?
                 "on" : "off")+"), 'history' ("+
                (this_player()->query_input_history()?
                 "on" : "off")+"), 'monitor' ("+
                (this_player()->query_property(P_MONITOR)?
                 "on" : "off")+"), 'inventory' ("+
                (this_player()->query_property(P_ADD_INVENTORY)?
                 "on" : "off")+"), 'who' ("+
                (this_player()->query_property(P_VERBOSE_WHO)?
                 "on" : "off")+"), 'refuse' ("+
                (this_player()->query_property(P_AUTO_REFUSE)?
                 "on" : "off")+"), 'beep' ("+
                (this_player()->query_property(P_DONT_BEEP)?
                 "no" : "yes")+ "), 'fails' ("+
                (this_player()->query_property(P_ALL_FAIL_MESSAGES)?
                 "all" : "one")+ "), 'autoloads' (" +
                // P_HIDE_AUTOLOADS by Coogan, 29-Apr-99
                (this_player()->query_property(P_HIDE_AUTOLOADS) ?
                 "hidden" : "visible") + "), 'brief' (" + //Coogan,01-Dec-00
                (this_player()->query_brief() ?
                 "on" : "off") + "), 'resize' (" +  // Coogan, 24-Oct-2002
                ((i=this_player()->query_property(P_RESIZE_WINDOW)) < 0
                 ? (i==-1 ? "off" : "on, silently")
                 : (i==1  ? "on, verbose" : "notice")) +
                "), 'encoding' (" +
                ENCODING_DESCS[this_player()->query_encoding()] +
                "), or 'inputencoding' (" +
                ENCODING_DESCS[this_player()->query_encoding(1)] +
                ").\n");
#endif
    return 0;
  case "toggle_fails":  // Alfe 98-Mar-18
    if (this_player()->query_property(P_ALL_FAIL_MESSAGES)) {
      this_player()->remove_property(P_ALL_FAIL_MESSAGES);
      message("You will now receive just the most important fail message.\n");
    }
    else {
      this_player()->set_property(P_ALL_FAIL_MESSAGES);
      message("You will now receive all fail messages.\n");
    }
    return 1;
  case "toggle_history":
    i = this_player()->query_input_history();
    this_player()->set_input_history(!i);
    message("You "+(i? "dis" : "en")+"able your personal input history.\n");
    return 1;
    // Ugh Apr-24-1995
  case "toggle_output":
    this_player()->toggle_output();
    message("Output from other objects while editing turned "+
            (this_player()->query_output() ? "ON" : "OFF")+".\n");
    return 1;
  case "toggle_more":
    if (this_player()->query_property(P_NO_MORE)) {
      this_player()->remove_property(P_NO_MORE);
      message("More turned ON.\n");
    }
    else {
      this_player()->set_property(P_NO_MORE);
      message("More turned OFF.\n");
      this_player()->flush_more();  // Alfe 95-Jun-20
    }
    return 1;
  case "toggle_monitor":   // Carador, Aug-96
    if (this_player()->query_property(P_MONITOR)) {
      this_player()->remove_property(P_MONITOR);
      message("Monitoring of hit and spell points turned OFF.\n");
    }
    else {
      this_player()->set_property(P_MONITOR);
      message("Monitoring of hit and spell points turned ON.\n");
    }
    return 1;
  case "toggle_who": // Chameloid, 28-Aug-96
    if (this_player()->query_property(P_VERBOSE_WHO)) {
      this_player()->remove_property(P_VERBOSE_WHO);
      message("Verbose who turned OFF.\n");
    }
    else {
      this_player()->set_property(P_VERBOSE_WHO);
      message("Verbose who turned ON.\n");
    }
    return 1;
  case "toggle_brief":  // Coogan, 01-Dec-00, moved from obj/player to here
    if (this_player()->toggle_brief())
      message("Brief mode.\n");
    else
      message("Verbose mode.\n");
    return 1;
  case "toggle_resize":  // Coogan, 24-Oct-2002
    i = this_player()->query_property(P_RESIZE_WINDOW);
    i++;
    if (i == 2)
      i = -2;
    switch (i) {
    case -1:
      message("Resizing the window will not take any effects on your "
              "display size adjustments.\n");
      break;
    case 1:
      message("Resizing the window will now take effect on your "
              "display size adjustments (verbose output at each resize).\n");
      break;
    case -2:
      message("Resizing the window will now take effect on your "
              "display size adjustments (no output about it).\n");
      break;
    default:
      message("You'll get only informed about window resizes, and this will "
              "have no effects on your display size adjustments.\n");
      break;
    }
    if (i)
      this_player()->set_property(P_RESIZE_WINDOW, i);
    else
      this_player()->remove_property(P_RESIZE_WINDOW);
    return 1;
  case "toggle_encoding":  // Alfe 2004-May-21
    {
      int encoding;
      encoding = ((this_player()->query_encoding() + 1) %
                  sizeof(ENCODING_DESCS));
      this_player()->set_encoding(encoding);
      this_player()->set_encoding(encoding, 1);
      message("Your encoding is set to '" + ENCODING_DESCS[encoding] +
              "' now.\n");
      this_player()->tell_unmodified("Umlauts in latin1: \xe4 \xf6 \xfc \xdf"
                                     " \xc4 \xd6 \xdc\n"
                                     "Umlauts in utf8:   \xc3\xa4 \xc3\xb6"
                                     " \xc3\xbc \xc3\x9f \xc3\x84 \xc3\x96"
                                     " \xc3\x9c\n");
      return 1;
    }
  case "toggle_inputencoding":  // Alfe 2004-May-21
    {
      int encoding;
      encoding = ((this_player()->query_encoding(1) + 1) %
                  sizeof(ENCODING_DESCS));
      this_player()->set_encoding(encoding, 1);
      message("Your inputencoding is set to '" + ENCODING_DESCS[encoding] +
              "' now.\n");
      return 1;
    }
  case "who": // Chameloid, 3-Sep-96
    this_player()->tell_more(who_string(args[WHO_MODE_PARSER_CLASS],
                                        args[G_AMBIG_LIVINGS],
                                        args[G_AMBIG_LIVINGS,1]));
    return 1;
  case "score":
    // moved it from obj/player to here, Carador, Aug-96
    if (this_player()->query_ghost()) {
      // no notify_fail here, because we really do something! we tell
      // the player that he is a ghost.  Alfe 96-Oct-10
      message("You are in an immaterial state with no scores.\n");
      return 1;
    }
    
    output = "You are " + describe(this_player(), ARTICLE_NONE, DESCRIBE_FULL) +
            " (level "+this_player()->query_level()+")\n";
    // Carador, 2-Dec-97
    // This prints something like:
    // You have 231 level points (quests: 173, explore: 56, combat: 2).
    output += this_player()->query_achievements_score();
    // Coogan, 04-Feb-02, show the level raise message
    if (LIB_ADVANCE->compute_level(this_player())>this_player()->query_level())
#if TUBMUD
      output += "You can raise your level at the Rocky Mouth.\n";
#else
      output += "You can raise your level.\n";
#endif
    output += "You have "+this_player()->query_exp()+ " experience points.\n";
    output += "You are carrying " + 
              LIB_MONEY->describe_money(this_player()->query_coins()) + ".\n";
    output += this_player()->query_hp() + " hit points(" + 
              this_player()->query_max_hp() + "), " + 
              this_player()->query_sp() + " spell points(" + 
              this_player()->query_max_sp() + ").\n";
    output +=   "Str: " + this_player()->query_str() + 
              "  Dex: " + this_player()->query_dex() + 
              "  Int: " + this_player()->query_int() +
              "  Con: " + this_player()->query_con() + "\n";
    // Coogan, 04-Feb-02: added the next part
    if (!is_wizard(this_player()) &&
        (i = LIB_ADVANCE->query_statsum(this_player())) <
          LIB_ADVANCE->query_max_statsum(this_player()) &&
        LIB_ADVANCE->query_cost_for_one_stat(i+1) < this_player()->query_exp())
      output += "You can increase your stats.\n";
    if (ob = this_player()->query_hunter())
      output += "You are hunted by " + describe(ob) + ".\n";
    t = ({ });
#if 0  // Coogan, 01-Apr-2003
    if (this_player()->query_intoxication() > 0)
      t += ({ "intoxicated" });
    if (this_player()->query_stuffed() > 0)
      t += ({ "satiated" });
    if (this_player()->query_soaked() > 0)
      t += ({ "not thirsty" });
#else
    output += "Carry utilisation: ";
    if (this_player()->query_carry() > this_player()->query_max_carry())
      output += TERMCOL_DESC_BOLD_RED;
    output += LIB_STRINGS->to_percent_line(this_player()->query_carry(),
                                           this_player()->query_max_carry(),
                                           10) + TERMCOL_DESC_NORMAL;
    if (this_player()->query_level() >= 45)
      output += "  (" + this_player()->query_carry() + " of max " +
                        this_player()->query_max_carry() + ")";
    output += "\nSatiation of " + this_player()->saturation_string() + "\n";
    if (this_player()->query_stuffed() <= -1000)
      t += ({ "hungry" });
    if (this_player()->query_soaked() <= -1000)
      t += ({ "thirsty" });
#endif
    if (sizeof(t))
      output += "You are " + make_list(t) + ".\n";
    message(output);
    this_player()->show_wimpy();
    message("Age: " + this_player()->show_age() + ".\n");
#if __TLS__  // Coogan, 15-Oct-2005
    if ((i = query_mud_port(-1)) > 1 &&
        query_mud_port(this_player()) == query_mud_port(i-1)) {
      // give a message if the player connection uses the TLS port
      message(this_player()->query_tls_score_string());
    }
#endif
    return 1;
  case "xyzzy":
    LIB_CHANNELS->channel_shout_message("general",({ M_CAPITALIZE,
                                                     M_PL_THE,M_PL_VERB,"try",
                                                     " the command 'xyzzy'." }),
                                        ({ "Gamedriver" }));
    message("Fine, but sorry, nothing happens.\n");
    return 1;
  case "email":
    if (args[G_TEXT]) {
      this_player()->set_mailaddr(args[G_TEXT]);
      write("Changed your email address as wished.\n");
    }
    else
      message("Your current email address is: "+
              this_player()->query_mailaddr() + "\n");
    return 1;
  case "town":
    if (args[G_TEXT]) {
      if (strlen(args[G_TEXT]) > 17)  // Coogan, 26-Nov-01
        return message("The town name is too long!\n"), 1; 
      this_player()->set_called_from_town(args[G_TEXT]);
      write("Changed your real world town as wished.\n");
    }
    else
      message("Your current real world town is: "+
              LIB_INTERNET->player2town(this_player()) + "\n");
    return 1;
  case "capitalize":
    if (args[G_TEXT])
      if (!this_player()->set_vis_name(args[G_TEXT])) {
        notify_fail("You misspelled your name, used more than three"
                    " capitals, didn't use a capital after a dash (-),"
                    " didn't use a capital as initial, made your name"
                    " use more than eleven characters, used a character"
                    " different from a letter, a tick (') and a dash,"
                    " used a tick or a dash as first or last character"
                    " or used more than one tick or dash.\n");
        return 0;
      }
      else 
        message("Your capitalization is now set to \"" + args[G_TEXT] +
                "\".\n");
    else
      message("Your capitalization currently is \"" +
              this_player()->query_vis_name() + "\".\n");
    return 1;
  case "bug":
  case "typo":
  case "idea":
  case "praise":
    if (ob = args[G_INDIRECT])
      s = args[G_INDIRECT,1];
    else
      ob = environment(this_player());
    if (action == "praise")   // split praises from bug/typo, Coogan, 26-Sep-01
      s3 = ".praise";
    else
      s3 = ".rep";
    if ((c = creator(ob)))
      t = "/log/" + c + s3;   // removed lower_case, Carador, 28-Nov-96.
    else                      // added this branch, Coogan, 08-May-01
      t = "/log/corelib" + s3;
    if ((s2 = args[G_TEXT])) {
      s2 = (ctime(time())+ " " + 
            this_player()->query_vis_name() + 
            ": " + capitalize(action) + " in " +
            (load_name(object_name(ob)) == load_name(ob)
             ?  object_name(ob) : load_name(ob)) +
            " (cloned by " +
            to_string(ob->query_cloned() || ob->query_cloner() ||
                      ob->cloned_by()) + ")" +
            " (" + s + "):\n" + s2 + "\n");
      if (t) // Ugh Oct-16-1996
        write_file(t, s2);
      // Ugh Oct-16-1996
      if (c && (c = castle_file(c)) && find_object(c))
        catch(c->notify_player_report(ob,action,s2));
      switch (action) {
      case "typo":
        log_file("TYPO", s2);
        break;
      case "bug":
        log_file("BUG", s2);
        break;
      case "idea":
        log_file("IDEA", s2);
        break;
      case "praise": 
        log_file("PRAISE", s2);
      }
      message("Thanks for your help.\n");
    }
    else {
      message("Please give a more elaborate description of your "+action+"! " 
              "(End with '**', abort with '~q')\n]");
      ob2 = clone_object("bin/sub/bug_logger");
      ob2->initialize(action, ob, t, s);
    }
    return 1;
  case "help":
    return help(args[G_TEXT]);
  case "webster":
    if (h = find_player("webster"))
      tell_object(h,this_player()->query_vis_name()+" tells you: "+
                  args[G_TEXT]+"\n");
    else
      write("Sorry, Webster isn't working.\n");
    return 1;
  case "do_command":
    {
    string *commands, str;
    if (!(str = args[G_TEXT])) {
      if (this_player()->fetch_then_command()) {
        message("Done.\n");
        return 1;
      }
      return 0;
    }
    commands = 
      regexplode(str, "([^;\"]*\"[^\"]*\")*[^;]*|[^;]*") - ({ "", ";" });
    if (sizeof(commands) > 1)
      this_player()->add_then_command(implode(commands[1..],";"));
    if (sizeof(commands) > 0)
      return command(commands[0],this_player());
    }
    break;
  case "toggle_verbose_do":
    if (this_player()->query_property(P_VERBOSE_SEQUENCE)) {
      message("Displaying do-commands now turned off.\n");
      this_player()->remove_property(P_VERBOSE_SEQUENCE);
    }
    else {
      message("Displaying do-commands now turned on.\n");
      this_player()->set_property(P_VERBOSE_SEQUENCE);
    }
    return 1;
  case "display":
    if (!member(args,G_WORD))  // no arguments given
      message("display height = "+
              this_player()->query_property(P_DISPLAY_HEIGHT)+
              ", display width = "+
              this_player()->query_property(P_DISPLAY_WIDTH)+"\n");
    else {  // at least one argument is given
      if (!IS_REGEXP(args[G_WORD],REGEXP_INT))  // first arg is no proper int
        message("First argument is no number, ignored.\n");
      else {
        h = to_int(args[G_WORD]);
        if (h < 1)
          return notify_fail("Display heights below 1 are discouraged.\n"), 0;
        if (h > 200)
          return notify_fail("The height should not be greater than 200.\n"),0;
        this_player()->set_property(P_DISPLAY_HEIGHT,h);
        message("Display height set to "+h+".\n");
      }
      if (member(args,G_TEXT))  // a second argument is given
        if (!IS_REGEXP(args[G_TEXT],REGEXP_INT))  // second argument is no int
          message("Second argument is no number, ignored.\n");
        else {
          h = to_int(args[G_TEXT]);
          if (h < 10 || h > 500)
            return notify_fail("Display widths below 10 or greater than 500"
                               " are not supported.\n"), 0;
          this_player()->set_property(P_DISPLAY_WIDTH,h);
          message("Display width set to "+h+".\n");
        }
    }
    return 1;

  case "party_create":
    if (SE_PARTY->query_is_party_member()) {
      ob = SE_PARTY->query_party_leader();
      return
        notify_fail(({({ M_WRITE, "You can't create a new party now, because "
                         "you are still a member of ", M_S, M_OBJECT, ob,
                         " party!" })})), 0;
    }
    if (!SE_PARTY->create_party()) 
      return notify_fail("Somehow, the party could not be created.\n"), 0;
    message("Party created.\n");
    return 1;

  case "party_add":
    if (!SE_PARTY->query_is_party_member())
      return notify_fail("You are not a member of a party!\n"), 0;
    if (!SE_PARTY->query_is_party_leader(this_player()))
      return notify_fail("You are not the leader of the party!\n"), 0;
    // next two checks added, Coogan, 21-Apr-99
    if (SE_PARTY->query_is_party_member(args[G_ANY_LIVING])) {
      notify_fail(({({ M_WRITE, M_THE, args[G_ANY_LIVING], M_VERB, "are",
                       args[G_ANY_LIVING], " already member of a party!" })}));
      return 0;
    }
    if (!present(args[G_ANY_LIVING], environment(this_player()))) {
      notify_fail(({({ M_WRITE, M_THE, args[G_ANY_LIVING], M_VERB, "are",
                       args[G_ANY_LIVING], " not present!" })}));
      return 0;
    }
    if (!interactive(args[G_ANY_LIVING]))
      return
        notify_fail(({({ M_WRITE, M_THE, args[G_ANY_LIVING], M_VERB, "are",
                         args[G_ANY_LIVING], " not a player!" })})), 0;
    ol1 = SE_PARTY->query_party_members(this_player());
    h   = map(ol1, lambda(({ 'x }),
                          ({ #'call_other, 'x, "query_vis_name" })));
    if (SE_PARTY->add_to_party(args[G_ANY_LIVING])) {
      ob = SE_PARTY->query_party_leader();
      message(({
        ({ M_TARGETS, ol1, M_THE, args[G_ANY_LIVING], " joined the party!" }),
        ({ M_RAW, M_TARGETS, args[G_ANY_LIVING],
           "You joined the party of ", ob->query_vis_name(), "!\nThe other ",
           ((sizeof(h) > 1) ? "members are " : "member is "),
           describe_list(h), "." }),
        }));
      return 1;
    }
    notify_fail(({({ M_WRITE, "Due to an error ", M_THE, args[G_ANY_LIVING],
                     " could not added to the party!" })}));
    return 0;

  case "party_leave":
  case "party_remove":
    if (!SE_PARTY->query_is_party_member())
      return notify_fail("You are not a member of a party!\n"), 0;
    if (action == "party_remove" &&
        !SE_PARTY->query_is_party_leader(this_player()))
      return notify_fail("You are not the leader of the party!\n"), 0;
    ob2 = args[G_ANY_LIVING] || this_player();
    ol1 = SE_PARTY->query_party_members(SE_PARTY->query_party_leader(ob2));
    ob = SE_PARTY->leave_party(ob2);
    if (action == "party_leave" ||
        ob2 == this_player())
      message(({({ M_TARGETS, ol1, M_THE, ob2, " left the party." }),
                ({ M_WRITE, "Ok." })}));
    else
      message(({({ M_TARGETS, ol1, M_THE, this_player(), " removed ",
                   M_THE, M_OBJECT, args[G_ANY_LIVING], " from the party." }),
                ({ M_WRITE, "Ok." })}));
    if (ob) {
      send_message(({ M_TARGETS, ol1 - ({ ob2 }), M_THE, ob, M_VERB, "are", ob,
                      " the new party leader!" }));
    }
    return 1;

  case "party_ch_leader":
    if (!SE_PARTY->query_is_party_member())
      return notify_fail("You are not a member of a party!\n"), 0;
    if (!SE_PARTY->query_is_party_leader(this_player()))
      return notify_fail("You are not the leader of the party!\n"), 0;
    if (SE_PARTY->query_is_party_leader(args[G_ANY_LIVING]))
      return notify_fail("But you are already the party leader!\n"), 0;
    ol1 = SE_PARTY->
            query_party_members(SE_PARTY->query_party_leader(this_player()));
    if (member(ol1, args[G_ANY_LIVING]) == -1)
      return notify_fail(({({ M_WRITE, M_THE, args[G_ANY_LIVING], M_VERB,
                              "are", args[G_ANY_LIVING],
                              " not a member of the party!" })})), 0;
    if (h = SE_PARTY->change_party_leader_to(args[G_ANY_LIVING]))
      send_message(({ M_TARGETS, ol1, M_THE, args[G_ANY_LIVING], M_VERB, "are",
                      args[G_ANY_LIVING], " now the new party leader!" }));
    else
      notify_fail(({({ M_WRITE, "Somehow it was impossible to make ", M_THE,
                       args[G_ANY_LIVING], " to the new party leader!" })}));
    return h;

  case "party_score":
    if (!SE_PARTY->query_is_party_member())
      return notify_fail("You are not a member of a party!\n"), 0;
    ob = SE_PARTY->query_party_leader(this_player());
    ol1 = SE_PARTY->query_party_members(ob);
    output = "\nName            Level    hp/ max    sp/ max\n"
             "===========================================\n";
    for (i = 0; i < sizeof(ol1); i++) {
      output += sprintf("%-13s %7d  %4d/%4d  %4d/%4d\n",
                        ol1[i]->query_vis_name(), ol1[i]->query_level(),
                        ol1[i]->query_hp(), ol1[i]->query_max_hp(),
                        ol1[i]->query_sp(), ol1[i]->query_max_sp());
    }
    output += "\nParty leader: " + ob->query_vis_name() + "\n";
    message(output + "\n");
    return 1;

  case "party_info":
    if (!sizeof(t = SE_PARTY->query_parties())) {
      message("At the moment, there are no parties.\n");
      return 1;
    }
    ol1 = m_indices(t);
    output = "";
    for (i = 0; i < sizeof(ol1); i++) {
      output += "Party of " + ol1[i]->query_vis_name() + ":\n";
      output += "Members: " +
                make_list(map_objects(SE_PARTY->query_party_members(ol1[i]),
                                      "query_vis_name")) + ".\n\n";
    }
    message(output);
    return 1;

  case "references":
    h = this_player()->get_referenced();
    if (!sizeof(h))
      return message("You have no references set.\n"), 1;
    message("Your references are as follows:\n");
    foreach (object referenced, string *references : h)
      write(break_string(sprintf("  %' .'-29s : %s\n",
                                 message2string(({ M_THE, referenced })),
                                 make_list(references)),
                         0, 34, -1));
    return 1;

  case "remove_reference":
    if (!(h=this_player()->query_referenced(args[G_WORD])))
      return message("Nothing referenced by " + args[G_WORD] +
                     ", no reference removed.\n"), 1;
    this_player()->remove_reference(args[G_WORD]);
    send_message(({ M_WRITE, "Ok, you now don't refer to ",
                    M_SUBJECT, this_player(), M_OBJECT, M_THE, h,
                    " as " + args[G_WORD] + " anymore." }));
    return 1;

  case "reference":
    if (sizeof(h=this_player()->query_references(args[G_OBJECT]))
#if __START_TIME__ == "_S_T_20020425000717"
        && pointerp(h)  // old version might return mapping; don't warn then.
#endif
        )
      send_message(({ M_WRITE, "WARNING: You already refer to ", M_SUBJECT,
                      this_player(), M_OBJECT, M_THE, args[G_OBJECT],
                      " as " + make_list(h) +
                      ".  The new reference will be added." }));
    if (h=this_player()->query_referenced(args[G_WORD]))
      send_message(({ M_WRITE, "WARNING: You already refer to ",
                      M_SUBJECT, this_player(), M_OBJECT, M_THE, h,
                      " as " + args[G_WORD] +
                      ".  This reference is now overwritten." }));
    this_player()->add_reference(args[G_WORD], args[G_OBJECT]);
    send_message(({ M_WRITE, "Ok, you now refer to ", M_SUBJECT, this_player(),
                    M_OBJECT, M_THE, args[G_OBJECT],
                    " as " + args[G_WORD] + "." }));
    return 1;
  }
  return 0;  // Coogan, 26-Mar-2011
}

