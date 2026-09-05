inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You treat yourself to a nice luxurious stretch.$N$\n", "$MN$ treats $MO$self to a nice luxurious stretch.$N$\n");
       target("You have a nice stretch, hoping $TN$ will see.$N$\n", "$MN$ has a nice stretch, eyeing $TN$ the whole time.$N$\n", "$MN$ is stretching and eyeing you up.$N$\n");
       afar("From afar, you have a stretch for $TN$'s benefit.$N$\n", "From afar, $MN$ has a nice stretch for your benefit.$N$\n");
    }
}

int
cmd_stretch(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
