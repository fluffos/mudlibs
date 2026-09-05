inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You jump around in your birthday suit and begin to sing,#RET#\"Happy happy bday, we're so glad you came..YAY!\"$N$\n", "#CMN# jumps around in #MP# birthday suit and begins to sing,#RET#\"Happy happy bday, we're so glad you came..YAY!\"\n");
       target("You jump around #CTN# in your birthday suit and begin to sing,#RET#\"Happy happy bday, we're so glad you came..YAY!\"$N$\n", "#CMN# jumps around #CTN# in #MP# birthday suit and begins to sing,#RET#\"Happy happy bday, we're so glad you came..YAY!\"\n", "#CMN# jumps around you in #MP# birthday suit and begins to sing,#RET#\"Happy happy bday, we're so glad you came..YAY!\"\n");
       afar("$HR$[Afar]$N$ You jump around #CTN# in your birthday suit and begin to sing,#RET#\"Happy happy bday, we're so glad you came..YAY!\" (Freak!)\n", "$HR$[Afar]$N$ #CMN# jumps around you in birthday suit and begins to sing,#RET#\"Happy happy bday, we're so glad you came..YAY!\"\n");
    }
}

int
cmd_bsuit(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
