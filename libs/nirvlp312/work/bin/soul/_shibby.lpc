inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shibby.$N$\n", "#MN# shibbies.$N$\n");
       target("You shibby around #TN#.$N$\n", "#MN# shibbies around #TN#.$N$\n", "#MN# shibbies around you.$N$\n");
       afar("You shibby around #TN# from afar.#RET#Whew, that was a long way.$N$\n", "#MN# shibbies around you from afar.#RET#Now how da hell dat crazy fool do dat?$N$\n");
    }
}

int
cmd_shibby(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
