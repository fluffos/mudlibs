// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// out(f) isn't very appropriate here...
#include <mudlib.h>
#include <daemons.h>
inherit M_INPUT;
inherit CMD;
mixed parse_rule(string str)
{
    switch (str)
    {
    case "":
    case 0:
    case "0":
        return "";
    case "1":
    case "all":
        return "STR";
    default:
        return str;
    }
}
private nomask void got_message(string verb, string rule, string str)
{
    string * parts;
    if ( str == "" )
    {
        write("放弃 Addemote。\n");
        return;
    }
    if (rule=="xx")
	rule="";
    parts = explode(str, " && ");
    SOUL_D->add_emote(verb, rule, parts);
}
private nomask void got_rule(string verb, string str)
{
    string rule = parse_rule(str);
    if ( rule == "." )
    {
        write("放弃 Addemote。\n");
        return;
    }
    write("信息: ");
    modal_simple((: got_message, verb, rule :));
}
nomask private void main(string str)
{
    string rule = 0;
    string verb = str;
    if (!str)
    {
        write("用法：addemote <verb>\n");
        return;
    }
    sscanf(verb, "%s %s", verb, rule);
    if ( !rule )
    {
        write("(用 '.' 可以放弃输入)\nRule: ");
        modal_simple((: got_rule, verb :));
    }
    else
    {
        rule = parse_rule(rule);
        write("信息: ");
        modal_simple((: got_message, verb, rule :));
    }
}
