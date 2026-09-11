// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;
inherit M_GRAMMAR;

private void main(string which)
{
    mapping data;
    mixed * info;

    if ( !which )
    {
        out("你要指定一个情感动词。\n");
        return;
    }

    data = SOUL_D->query_emote(which);
    if ( !data )
    {
        out("没有这个情感动词。\n");
        return;
    }

    if ( data[""] )
    {
        info = SOUL_D->get_soul(which, "", ({ }));
        outf("%s :\n  你会看到：%s他人会看到：%s\n",
               which, info[1][0], info[1][1]);
    }

    if ( data["LIV"] )
    {
        info = SOUL_D->get_soul(which, "LIV", ({ this_object() }));
        outf("%s somebody:\n  你会看到：%s目标会看到：%s他人会看到：%s\n",
               which, info[1][0], info[1][1], info[1][2]);
    }

    if ( data["STR"] )
    {
        info = SOUL_D->get_soul(which, "STR", ({ "slowly" }));
        outf("%s slowly :\n     你会看到：%s他人会看到：%s\n",
               which, info[1][0], info[1][1]);
    }

    if ( data["LIV STR"] )
    {
        info = SOUL_D->get_soul(which, "LIV STR", ({ this_object(), "slowly" }));
        outf("%s somebody slowly :\n  你会看到：%s目标会看到：%s他人会看到：%s\n",
               which, info[1][0], info[1][1], info[1][2]);
    }
}

string query_pronoun()
{
    return "他";
}
string query_reflexive()
{
    return "他自己";
}
string query_subjective()
{
    return query_pronoun();
}
string query_objective()
{
    return "他";
}
string query_possessive()
{
    return "他的";
}
string query_named_possessive()
{
    return "某人的";
}

string short()
{
    return "某人";
}

void player_menu_entry (string s)
{
  bare_init();
  main (s);
  done_outputing();
}
