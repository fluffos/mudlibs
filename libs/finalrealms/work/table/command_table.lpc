/* This is the table where all the command are inserted,
 * /std/commands.c uses this one for finding the commands.
 * Baldrick, aug '94.
 */

mapping query_commands()
{
    mapping list;

    list = ([
      "rearrange" : ({ "/std/commands/roller","intro" }),
      "pray" : ({"/std/commands/pray", "pray" }),
      "bury" : ({ "/std/commands/bury", "bury" }),
      "judge" : ({ "/std/commands/judge", "judge" }),
      "fix" : ({ "/std/commands/fix", "fix" }),
      "consider" : ({ "/std/commands/consider", "consider" }),
      /* Thief commands... */
      "hide" : ({ "/std/commands/hide_in_shad", "hide_in_shadows" }),
      "backstab" : ({ "/std/commands/backstab","backstab" }),
      "sneak" : ({ "/std/commands/sneak", "sneak" }),
      "steal" : ({ "/std/commands/steal", "steal" }),
      // Turn (clerics)
      "turn":({"/std/commands/turn","turn"}),
      
    ]);

    return list;

} /* query_commands */
