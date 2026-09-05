inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You turn pasty white and emit: \"Word Homes.\"\n", "#MN# turns pasty white and emits: \"Word Homes.\"\n");
       target("You turn to #TN# and emit in a high, nasal voice: \"WORD HOMES!\"\n", "#MN# turns to #TN# and emits in a high, nasal voice: \"WORD HOMES!\"\n", "#MN# turns to you and emits in a high nasal voice: \"WORD HOMES!\"\n");
       afar("In the most whitebread voice possible, you emit to #TN# from afar: \"WORD UP HOMES!\"\n", "From afar, #MN# emits to you in the most whitebread voice possible: \"WORD UP HOMES!\"\n");
    }
}

int
cmd_word(string arg)
{
  if((string)this_player()->query_guild_name()=="bard") return 0;
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
