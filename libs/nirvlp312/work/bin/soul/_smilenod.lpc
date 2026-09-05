inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You smile and nod. :)$N$\n", "#MN# smiles and nods.  :)$N$\n");
       target("You smile and nod at #TN#. :)$N$\n", "#MN# smiles and nods at #TN#. :)$N$\n", "#MN# smiles and nods at you. :)$N$\n");
       afar("You smile and nod at #TN# from afar.  :)$N$\n", "#MN# smiles and nods at you from afar. :)$N$\n");
    }
}

int
cmd_smilenod(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
