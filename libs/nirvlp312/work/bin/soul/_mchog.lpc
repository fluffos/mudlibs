inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("In a menacing fashion, you chog to the room.$N$\n", "In a menacing fashion, #CMN# chogs to the room.$N$\n");
       target("In a menacing fashion, you chog at #CTN#.$N$\n", "In a menacing fashion, #CMN# chogs at #CTN#.$N$\n", "In a menacing fashion, #CMN# chogs at you.$N$\n");
       afar("$HW$[$HY$afar$HW$]$N$ In a menacing fashion, you chog at #CTN#.$N$\n", "$HW$[$HY$afar$HW$]$N$ In a menacing fashion, #CMN# chogs at you.$N$\n");
    }
}

int
cmd_mchog(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
