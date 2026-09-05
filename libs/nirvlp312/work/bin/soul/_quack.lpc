inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go quack quack quack.$N$\n", "Quack quack goes the #MN#.$N$\n");
       target("You quack quack quack at #TN#.$N$\n", "#MN# quack quack quacks at #TN#.$N$\n", "#MN# quack quack quacks at you.$N$\n");
       afar("You make quacking noises at #TN# from afar.$N$\n", "You hear quacking noises coming from #MN# from afar.$N$\n");
    }
}

int
cmd_quack(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
