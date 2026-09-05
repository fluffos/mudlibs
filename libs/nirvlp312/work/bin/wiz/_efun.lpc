/******************************************************************************
 * File:          _efun.c
 * Author(s):     Vital@Nirvana
 * Copyright:     Copyright (c) 2004 v-Dev Code Factory
 *                All Rights Reserved.
 * Source:        9/26/05
 * Notes: 
 * Change History:
 *                 7/18/2014 - Changed to allow newer efuns on LD, and only
 *                             grab list from /doc/efun - Rumplemintz
 *****************************************************************************/
#include <ansi.h>

#ifndef __LDMUD__ /* Rumplemintz */
#define IGNORED_EFUNS ({ ".", "..", "[]", "acos", "apply",\
"asin", "assoc", "atan", "attach_erq_demon", "binary_message", "bind_lambda",\
"break_point", "call_out_info", "closurep", "cos", "crypt", "ctime", \
"debug_info", "debug_message", "deep_inventory", "disable_commands", \
"efun308", "enable_commands", "exec", "exp", "expand_define", "export_uid", \
"extern_call", "filter_mapping", "filter_objects", "floatp", "funcall", \
"functionlist", "garbage_collection", "get_error_file", "get_eval_cost", \
"get_extra_wizinfo", "get_type_info", "geteuid", "getuid", "heart_beat_info", \
"insert_alist", "intersect_alist", "intp", "lambda", "last_instructions", \
"negate", "order_alist", "parse_command", "pointerp", "printf", \
"process_string", "program_time", "query_imp_port", "query_input_pending", \
"query_load_average", "query_mud_port", "query_once_interactive", "quote", \
"referencep", "regexp", "regexplode", "rename", "rename_object", \
"replace_program", "rusage", "send_erq", "send_imp", \
"set_auto_include_string", "set_buffer_size", "set_connection_charset", \
"set_driver_hook", "set_extra_wizinfo", "set_extra_wizinfo_size", \
"set_heart_beat", "set_is_wizard", "set_modify_command", "set_prompt", \
"set_this_player", "seteuid", "sin", "slice_array", "sprintf", "sqrt", \
"strstr", "swap", "symbol_function", "symbol_variable", \
"symbolp", "tan", "to_array", "to_float", "to_int", "to_object", "to_string", \
"trace", "traceprefix", "transfer", "unbound_lambda", "unique_array" })
#else
#define IGNORED_EFUNS ({ ".", "..", "DR-driver", "LP-driver" })
#endif

status
cmd_efun(string str)
{
  string *efuns;

#ifndef __LDMUD__ /* Rumplemintz */
  efuns = get_dir("/doc/Driver/doc/efun/***");
  efuns -= IGNORED_EFUNS;
  efuns += get_dir("/doc/sfun/***");
#else
  efuns = get_dir("/doc/efun/***");
  efuns -= IGNORED_EFUNS;
#endif

  if ( !str )
  {
    int z, x, y;
    z = sizeof(efuns);
    y = 0;
    write(pad("", 75, '*') + "\n");
    for (x = 0; x < z; x++)
    {
      write(pad(efuns[x], 25));
      if (y < 2)
        y++;
      else
      {
        write("\n");
        y = 0;
      }
    }
    write("\n" + pad("", 75, '*') + "\n");
    return 1;
  }
#ifndef __LDMUD__ /* Rumplemintz */
  if ( member_array(str, efuns) != 0 )
#else
  if (member(efuns, str) != 0)
#endif
  {
    write(pad("", 75, '*') + "\n");
#ifndef __LDMUD__
    cat("/doc/Driver/doc/efun/" + str );
    cat("/doc/sfun/" + str); 
#else
    cat("/doc/efun/" + str);
#endif
    write(pad("", 75, '*') + "\n");
  }
  return 1;
}

