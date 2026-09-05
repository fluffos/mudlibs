inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You congratulate yourself.#RET#Cocky bastard.$N$\n", "#MN# congratulates #MO#self.#RET#Cocky bastard.$N$\n");
       target("You congratulate #TN#.$N$\n", "#MN# congratulates #TN#.$N$\n", "#MN# congratulates you.$N$\n");
       afar("You congratulate #TN# from afar.$N$\n", "#MN# congratulates you from afar.$N$\n");
    }
}

int
cmd_congrat(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
