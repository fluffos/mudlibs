inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Gazundheit!$N$\n", "#MN# sneezes all over the place!#RET#Yuck!$N$\n");
       target("You sneeze all over #TN#.$N$\n", "#MN# sneezes all over #TN#.$N$\n", "#MN# sneezes all over you.$N$\n");
       afar("You sneeze all over #TN# from afar.#RET#Holy distance batman!$N$\n", "#MN# sneezes all over you from afar.#RET#Holy distance batman!$N$\n");
    }
}

int
cmd_sneeze(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
