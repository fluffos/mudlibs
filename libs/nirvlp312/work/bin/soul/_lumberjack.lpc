inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Who did you want to sing to?$N$\n", "0$N$\n");
       target("You sing: \"I'm a lumberjack and i'm ok, I work all night and I sleep all day!\"#RET##CTN# sings: \"#CMS#'s a lumberjack and #MS#'s ok, #MS# works all night and #MS# sleeps all day!\"\n", "#CMN# sings: \"I'm a lumberjack and i'm ok, I work all night and I sleep all day!\"#RET#You sing: \"#CMS#'s a lumberjack and #MS#'s ok, #MS# works all night and #MS# sleeps all day!\"\n", "#CMN# sings: \"I'm a lumberjack and i'm ok, I work all night and I sleep all day!\"#RET#You sing: \"#CMS#'s a lumberjack and #MS#'s ok, #MS# works all night and #MS# sleeps all day!\"\n");
       afar("You sing, from afar: \"I'm a lumberjack and i'm ok, I work all night and I sleep all day!\"#RET##CTN# sings, from afar: \"#CMS#'s a lumberjack and #MS#'s ok, #MS# works all night and #MS# sleeps all day!\"\n", "#CMN# sings, from afar: \"I'm a lumberjack and i'm ok, I work all night and I sleep all day!\"#RET#You sing, from afar: \"#CMS#'s a lumberjack and #MS#'s ok, #MS# works all night and #MS# sleeps all day!\"\n");
    }
}

int
cmd_lumberjack(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
