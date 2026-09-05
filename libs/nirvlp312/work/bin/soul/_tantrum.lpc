inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You throw a $HR$temper tantrum$N$, growling and kicking at everything in the room!\n", "#MN# throws a $HR$temper tantrum$N$, snarling and kicking at everything in the room!\n");
       target("You throw a $HR$temper tantrum$N$ over #TN#!\n", "#MN# throws a $HR$temper tantrum$N$ over #TN#!\n", "#MN# throws a $HR$temper tantrum$N$ over you!\n");
       afar("You throw a $HR$temper tantrum$N$ at #TN#, growling and kicking at everything from afar!\n", "#MN# throws a $HR$temper tantrum$N$, growling and kicking at everything from afar!\n");
    }
}

int
cmd_tantrum(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
