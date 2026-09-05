/*
 * global/commands/colour - written by Coogan, 26-Feb-00
 *
 */

#pragma strong_types

#include <termcol.h>    // Coogan, 25-Nov-2003
#include <grammar.h>
#include <message.h>
#include <closures.h>
#include <prop/player.h>
#include <bits.h>       // Coogan, 19-Feb-2001
#include <files.h>      // Coogan, 16-Oct-2001
#include <kernel.h>     // Coogan, 16-Oct-2001

#define BG_COLOUR       "<bg_colour>"
#define G_WRONG_COLOUR  "<g_wrong_colour>"  // Coogan, 22-Sep-2001

inherit ACCESS;          // Coogan, 16-Oct-2001
inherit "basic/name";    // Coogan, 16-Oct-2001
inherit "basic/create";

private nosave mapping colours;


varargs status test_colour_valid(string colour, status background) {
  string result, model;

  model = this_player()->query_property(P_TERMCOL_MODEL);
  if (!model)
    return notify_fail("As for you the colour usage is switched off, "
                       "you can't adjust colours now!\n"), 0;
  result = TERMCOL_MODELS[model][DESC2TERMCOL[colour]];
  if (!result) {
    notify_fail("For your colour set, there are only the colours " +
                make_list(sort_array(map(m_values(MODEL2TERMCOL[model]),
                                         lambda(({ 'x }),
                                                ({ CL_L_INDEX,
                                                       TERMCOL2DESC, 'x }))),
                                     #'>)) +
                " valid.\n");
    return 0;
  }
  return 1;
}

status do_action(string verb, mapping args) {
  string token, ttoken, token_fg, token_bg, *ind, model, *adjustable, setting;
  string key, living;
  mixed m, *msg, m1, m2;
  mapping spec_col;
  int state, i, is_channel;

  state   = this_player()->query_property(P_TERMCOL_STATUS);
  model   = this_player()->query_property(P_TERMCOL_MODEL);
  setting = this_player()->query_property(P_TERMCOL_SETTING);

  if (args && args[G_WORDS])  // Coogan, 03-Sep-01
    args[G_WORDS] = lower_case(args[G_WORDS]);

  if (args && args[G_WORD])  // Coogan, 16-Oct-01
    args[G_WORD] = lower_case(args[G_WORD]);

  adjustable = m_values(TERMCOL_SERVICES) +
               m_values(TERMCOL_DESCRIPTIONS) +
               m_values(TERMCOL_TECHNICAL);  // Coogan, 27-Aug-2003

  // added "args[G_WORDS] &&", Coogan, 05-May-00
  if (args && args[G_WORDS] &&
      member(adjustable, args[G_WORDS]) == -1)
    return notify_fail("It's only possible to adjust the colours for " +
                       make_list(sort_array(adjustable, #'>)) + ".\n"), 0;

  if (args && args[G_WORD]) {  // Coogan, 16-Oct-01
    if (args[G_WORDS] &&
        member(m_values(TERMCOL_SERVICES), args[G_WORDS]) == -1)
      return  // should be message(), otherwise the n_f() from above will be
              // given with the next parsed rule. Coogan.
        message("It's only possible to adjust such special colours for " +
                make_list(sort_array(m_values(TERMCOL_SERVICES),#'>))+".\n"),
                1;
    if (unguarded(1, #'file_size, "/save/players/"+args[G_WORD][1..-1])
           == FSIZE_NOFILE) {
      if (!find_living(args[G_WORD]))
        message("Warning: No living of the name " + args[G_WORD] + " found!\n"
                "Hope you know what you're doing.\n");
    }
  }

  m1 = unmkmapping(TERMCOL_SERVICES + TERMCOL_DESCRIPTIONS + TERMCOL_TECHNICAL);
  if (args && member(args, G_WORDS)) {
    key = m1[0][member(m1[1], args[G_WORDS])];
    if (member(args, G_WORD)) {
      if (strstr(args[G_WORDS], "channel") > -1) {
        is_channel = 1;
        key += ":" + args[G_WORD];
      } else
        key += ":" + to_real_name(args[G_WORD]);
    }
  }

  switch (verb) {
  case "set_bg_colour":
    if (member(args, G_WRONG_COLOUR)) 
      args[BG_COLOUR] = args[G_WRONG_COLOUR];  // will fail!
    if (!test_colour_valid(args[BG_COLOUR]))
      return 0;
    if (DESC2TERMCOL[args[BG_COLOUR]] == TERMCOL_NORMAL)
      this_player()->set_bg_colour(setting, key, 0);
    else
      this_player()->set_bg_colour(setting, key,
                                   DESC2TERMCOL[args[BG_COLOUR]]);
    message("Background colour for " + args[G_WORDS] +
            (member(args, G_WORD)
             ? (is_channel ? args[G_WORD]
                           : " from " + to_vis_name(args[G_WORD]))
             : "") +
            " changed to " + (args[BG_COLOUR] || "default") + ".\n");
    break;

  case "set_fg_colour":
    if (member(args, G_WRONG_COLOUR))
      args[G_COLOUR] = args[G_WRONG_COLOUR];  // will fail!
    if (!test_colour_valid(args[G_COLOUR]))
      return 0;
    if (DESC2TERMCOL[args[G_COLOUR]] == TERMCOL_NORMAL)
      this_player()->set_fg_colour(setting, key, 0);
    else  
      this_player()->set_fg_colour(setting, key,
                                   DESC2TERMCOL[args[G_COLOUR]]);
    message("Foreground colour for " + args[G_WORDS] +
            (member(args, G_WORD)
             ? (is_channel ? args[G_WORD]
                           : " from " + to_vis_name(args[G_WORD]))
             : "") +
            " changed to " + (args[G_COLOUR] || "default") + ".\n");
    break;

  case "reset_colours":
    this_player()->set_colour_defaults();
    message("Colours reset to the defaults.\n");
    return 1;
  case "reset_one_colour":
    this_player()->set_colour_defaults(setting, key);
    message("Colours for " + args[G_WORDS] +
            (member(args, G_WORD)
             ? (is_channel ? args[G_WORD]
                           : " from " + to_vis_name(args[G_WORD]))
             : "") +
            " reset to the defaults.\n");
    return 1;
  case "status":
    if (!model) {
      message("As you don't use a colour model, you don't see any "
              "colours at all.\n");
      return 1;
    }
    message("You're using colour model " + model + " with the " + setting +
            " setting.\n\n");
    if (TEST_BIT(state, TERMCOL_BIT_SERVICE)) {
      ind = sort_array(m_indices(TERMCOL_SERVICES), #'>);
      m = ({({ M_WRITE, "Your personal colour adjustments for services:" }),
            ({ M_WRITE, "Service           Foreground        Background" })});
      foreach (token : ind) {
        if ((ttoken = TERMCOL2DESC[this_player()->
                                     query_fg_colour(setting, token)]))
          token_fg = ttoken;
        else
          token_fg = "(default)";
        if ((ttoken = TERMCOL2DESC[this_player()->
                                     query_bg_colour(setting, token)]))
          token_bg = ttoken;
        else
          token_bg = "(default background)";
        ttoken = TERMCOL_SERVICES[token];
        m += ({({ M_WRITE,
                  sprintf("%-18s", ttoken),
                  M_CNTL_SEQ, token,
                  sprintf("%-18s", lower_case(token_fg)),
                  M_CNTL_SEQ, TERMCOL_NORMAL,
                  sprintf("%-21s", lower_case(token_bg)),
                  M_CNTL_SEQ, TERMCOL_NORMAL,
             })});
      }
      message(m);
      message("\n");

      m2 = this_player()->query_colours()[setting];
      m2 = filter(m2, (: (strstr($1, ":") > -1) :));
      if (sizeof(m2)) {
        m2 = unmkmapping(m2);
        ind = sort_array(m2[0], #'>);
        m = ({({ M_WRITE, "Your special colour adjustments for services:" }),
              ({ M_WRITE,
                 "Service        with/from    Foreground    Background" })});
        foreach (token : ind) {
          living = token[(i = strstr(token, ":"))+1 ..];
          if (strstr(token, "CHANNEL") == -1)  // Coogan, 21-Oct-01
            living = to_vis_name(token[i+1 ..]);
          if ((ttoken = TERMCOL2DESC[this_player()->
                                       query_fg_colour(setting, token)]))
            token_fg = ttoken;
          else
            token_fg = "(default)";
          if ((ttoken = TERMCOL2DESC[this_player()->
                                       query_bg_colour(setting, token)]))
            token_bg = ttoken;
          else
            token_bg = "(default background)";
          ttoken = TERMCOL_SERVICES[token[0..i-1]];
          m += ({({ M_WRITE,
                    sprintf("%-15s", ttoken),
                    sprintf("%-13s", living),
                    M_CNTL_SEQ, token,
                    sprintf("%-14s", lower_case(token_fg)),
                    M_CNTL_SEQ, TERMCOL_NORMAL,
                    sprintf("%-21s", lower_case(token_bg)),
                    M_CNTL_SEQ, TERMCOL_NORMAL,
               })});
        }
        message(m);
        message("\n");
      }
    }

    if (TEST_BIT(state, TERMCOL_BIT_DESCRIPTION)) {  // Coogan, 01-Sep-01
      ind = sort_array(m_indices(TERMCOL_DESCRIPTIONS), #'>);
      m = ({({ M_WRITE,
               "Your personal colour adjustments for descriptions:" }),
            ({ M_WRITE, "Description       Foreground        Background" })});
      foreach ( token : ind ) {
        if ((ttoken = TERMCOL2DESC[this_player()->
                                      query_fg_colour(setting, token)]))
          token_fg = ttoken;
        else
          token_fg = "(default)";
        if ((ttoken = TERMCOL2DESC[this_player()->
                                      query_bg_colour(setting, token)]))
          token_bg = ttoken;
        else
          token_bg = "(default background)";
        ttoken = TERMCOL_DESCRIPTIONS[token];
        m += ({({ M_WRITE,
                  sprintf("%-18s", ttoken),
                  M_CNTL_SEQ, token,
                  TERMCOL_DESCRIPTIONS2DESC_DESCRIPTIONS[token],
                  sprintf("%-18s", lower_case(token_fg)),
                  M_CNTL_SEQ, TERMCOL_NORMAL, TERMCOL_DESC_NORMAL,
                  sprintf("%-21s", lower_case(token_bg)),
                  M_CNTL_SEQ, TERMCOL_NORMAL, TERMCOL_DESC_NORMAL,
             })});
      }
      message(m);
      message("\n");
    }

    if (TEST_BIT(state, TERMCOL_BIT_TECHNICAL)) {  // Coogan, 27-Aug-2003
      ind = sort_array(m_indices(TERMCOL_TECHNICAL), #'>);
      m = ({({ M_WRITE,
               "Your personal colour adjustments for technical writings:" }),
            ({ M_WRITE, "Topic             Foreground        Background" })});
      foreach ( token : ind ) {
        if ((ttoken = TERMCOL2DESC[this_player()->
                                      query_fg_colour(setting, token)]))
          token_fg = ttoken;
        else
          token_fg = "(default)";
        if ((ttoken = TERMCOL2DESC[this_player()->
                                      query_bg_colour(setting, token)]))
          token_bg = ttoken;
        else
          token_bg = "(default background)";
        ttoken = TERMCOL_TECHNICAL[token];
        m += ({({ M_WRITE,
                  sprintf("%-18s", ttoken),
                  M_CNTL_SEQ, token,
                  TERMCOL_TECHNICAL2TECH_DESCRIPTIONS[token],
                  sprintf("%-18s", lower_case(token_fg)),
                  M_CNTL_SEQ, TERMCOL_NORMAL, TERMCOL_TECH_NORMAL,
                  sprintf("%-21s", lower_case(token_bg)),
                  M_CNTL_SEQ, TERMCOL_NORMAL, TERMCOL_TECH_NORMAL,
             })});
      }
      message(m);
      message("\n");
    }

    message("You toggled using colours for 'services' (" +
            (TEST_BIT(state, TERMCOL_BIT_SERVICE) ? "on" : "off") +
            "), 'descriptions' (" +
            (TEST_BIT(state, TERMCOL_BIT_DESCRIPTION) ? "on" : "off") +
            ") and 'technical' (" +
            (TEST_BIT(state, TERMCOL_BIT_TECHNICAL) ? "on" : "off") + ").\n");
    return 1;

  case "colour_setting":
    if (args[G_WORD] && member(TERMCOL_DEFAULT_SETTINGS, args[G_WORD]) == -1)
      return
        notify_fail("You can switch between the colour settings " +
                    make_list(sort_array(TERMCOL_DEFAULT_SETTINGS, #'>)) +
                    ".\n"), 0;
    if (!args[G_WORD]) {
      message("You're using the colour setting " + setting + " right now.\n"
              "You can switch between the colour settings " +
              make_list(sort_array(TERMCOL_DEFAULT_SETTINGS, #'>)) + ".\n");
      return 1;
    }
    this_player()->set_property(P_TERMCOL_SETTING, args[G_WORD]);
    this_player()->compute_terminal_colour_mapping();
    message("Colour setting changed to " + args[G_WORD] + ".\n");
    return 1;

  case "colour_model":
    if (args[G_WORD] &&
        (args[G_WORD] != "off" && !member(TERMCOL_MODELS, args[G_WORD])))
      return notify_fail("You can switch between the colour models " +
                         make_list(sort_array(m_indices(TERMCOL_MODELS), #'>))+
                         " or switch it off.\n"), 0;
    if (!args[G_WORD]) {
      if (model)
        message("You're using the colour model " + model + " right now.\n");
      else
        message("Currently you've switched off all colour usage.\n");
      if (sizeof(TERMCOL_MODELS) > 2)
        message("You can switch between the colour models " +
                make_list(sort_array(m_indices(TERMCOL_MODELS), #'>)) +
                " or switch it off.\n");
      else
        message("You can use the colour model " + m_indices(TERMCOL_MODELS)[0]+
                " or switch it off.\n");   
      return 1;
    }
    if (args[G_WORD] == "off") {
      this_player()->remove_property(P_TERMCOL_MODEL);
      this_player()->compute_terminal_colour_mapping();
      message("General usage of colours is switched off.\n");
      return 1;
    }
    this_player()->set_property(P_TERMCOL_MODEL, args[G_WORD]);
    this_player()->compute_terminal_colour_mapping();
    message("Colour model changed to " + args[G_WORD] + ".\n");
    return 1;

  case "colour_toggle":  // Coogan, 19-Feb-01
    if (!args[G_WORD]) {
      message("You can toggle 'services', 'descriptions' "
              "and 'technical'. Currently you've these adjustments:\n"
              "'services' (" +
              (TEST_BIT(state, TERMCOL_BIT_SERVICE) ? "on" : "off") +
              "), 'descriptions' (" +
              (TEST_BIT(state, TERMCOL_BIT_DESCRIPTION) ? "on" : "off") +
              ") and 'technical' (" +
              (TEST_BIT(state, TERMCOL_BIT_TECHNICAL) ? "on" : "off") +").\n");
      return 1;
    }
    if (member(({ "services", "descriptions", "technical" }),
               args[G_WORD]) == -1)
      return notify_fail("You can only toggle \"services\", \"descriptions\""
                         " and \"technical\".\n"), 0;
    return do_action("toggle_"+args[G_WORD], 0);

  case "toggle_services":
    TOGGLE_BIT(state, TERMCOL_BIT_SERVICE);
    if (state)
      this_player()->set_property(P_TERMCOL_STATUS, state);
    else
      this_player()->remove_property(P_TERMCOL_STATUS, state);
    this_player()->compute_terminal_colour_mapping();
    if (TEST_BIT(state, TERMCOL_BIT_SERVICE))
      message("Colours for services are now used.\n");
    else
      message("Colours for services are now switched off.\n");
    return 1;

  case "toggle_descriptions":
    TOGGLE_BIT(state, TERMCOL_BIT_DESCRIPTION);
    if (state)
      this_player()->set_property(P_TERMCOL_STATUS, state);
    else
      this_player()->remove_property(P_TERMCOL_STATUS, state);
    this_player()->compute_terminal_colour_mapping();
    if (TEST_BIT(state, TERMCOL_BIT_DESCRIPTION)) 
      message("Colours for descriptions are now used.\n");
    else
      message("Colours for descriptions are now switched off.\n");
    return 1;

  case "toggle_technical":
    TOGGLE_BIT(state, TERMCOL_BIT_TECHNICAL);
    if (state)
      this_player()->set_property(P_TERMCOL_STATUS, state);
    else
      this_player()->remove_property(P_TERMCOL_STATUS, state);
    this_player()->compute_terminal_colour_mapping();
    if (TEST_BIT(state, TERMCOL_BIT_TECHNICAL)) 
      message("Colours for technical things are now used.\n");
    else
      message("Colours for technical things are now switched off.\n");
    return 1;

  default:
    return 0;
  }

  // Coogan, 13-Sep-01, rewrote the next lines
  if (member(m_values(TERMCOL_SERVICES), args[G_WORDS]) > -1) {
    m = unmkmapping(TERMCOL_SERVICES);
    if (key)
      msg = ({ M_CNTL_SEQ, key });
    else
      msg = ({ M_CNTL_SEQ, m[0][member(m[1], args[G_WORDS])] });
  } else if (member(m_values(TERMCOL_DESCRIPTIONS), args[G_WORDS]) > -1) {
    m = unmkmapping(TERMCOL_DESCRIPTIONS);
    msg = ({ TERMCOL_DESCRIPTIONS2DESC_DESCRIPTIONS[
                                m[0][member(m[1], args[G_WORDS])]] });
  } else if (member(m_values(TERMCOL_TECHNICAL), args[G_WORDS]) > -1) {
    m = unmkmapping(TERMCOL_TECHNICAL);
    msg = ({ TERMCOL_TECHNICAL2TECH_DESCRIPTIONS[
                                m[0][member(m[1], args[G_WORDS])]] });
  } else
    msg = ({ });

  send_message(({ M_WRITE, "Example: " }) + msg + 
               ({ "Test", M_CNTL_SEQ, TERMCOL_NORMAL, TERMCOL_DESC_NORMAL,
                  TERMCOL_TECH_NORMAL }));
  return 1;
}

