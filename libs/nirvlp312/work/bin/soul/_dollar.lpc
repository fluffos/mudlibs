inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Your eyes light up, and you say, \"I'll buy that for a dollar!\"$N$\n", "$MN$'s eyes light up, and $MS$ says, \"I'll buy that for a dollar!\"$N$\n");
       target("You grab $TN$, and excitedly tell $TO$, \"I'll buy that for a dollar!\"$N$\n", "$MN$ grabs $TN$, and excitedly tells $TO$, \"I'll buy that for a dollar!\"$N$\n", "$MN$ grabs you, and excitedly tells you, \"I'll buy that for a dollar!\"$N$\n");
       afar("From afar, you inform $TN$, \"I'll buy that for a dollar!\"$N$\n", "From afar, $MN$ informs you, \"I'll buy that for a dollar!\"$N$\n");
    }
}

int
cmd_dollar(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
