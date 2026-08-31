/* Do not remove the headers from this file! see /USAGE for more info. */

inherit ADMTOOL_BASE;

nomask string module_name()
{
   return "misc";
}

nomask string module_key()
{
   return "s";
}

nomask class command_info *module_commands()
{
   return ({
       new (class command_info, key
            : "h", desc
            : "rebuild help data", action
            : (
                : HELP_D->rebuild_data()
                :)),
       new (class command_info, key
            : "s", desc
            : "Autodoc Update (scan-mudlib) [lots of output spam]", action
            : (
                : DOC_D->scan_mudlib()
                :)),
       new (class command_info, key
            : "c", desc
            : "Autodoc Update (complete-rebuild) [lots of ouput spam]", action
            : (
                : DOC_D->complete_rebuild()
                :)),
       new (class command_info, key
            : "r", desc
            : "RST Update (scan-mudlib) [lots of output spam]", action
            : (
                : RST_D->scan_mudlib()
                :)),
       new (class command_info, key
            : "R", desc
            : "RST Update (complete-rebuild) [lots of ouput spam]", action
            : (
                : RST_D->complete_rebuild()
                :)),
   });
}
