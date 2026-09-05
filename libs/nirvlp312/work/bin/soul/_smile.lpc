inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You smile happily.$N$\n", "#MN# smiles happily.$N$\n");
       target("You smile at #TN#.$N$\n", "#MN# smiles at #TN#.$N$\n", "#MN# smiles at you.$N$\n");
       afar("You smile at #TN# from afar.$N$\n", "#MN# smiles at you from afar.$N$\n");
    }
}

int
cmd_smile(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
