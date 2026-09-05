inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You twirl your hands around each other and sing,#RET#\"The wheels on the bus go round and round...round and round...\"#RET#You get to ride the short bus to school!$N$\n", "#MN# twirls #MP# hands around each other and sings,#RET#\"The wheels on the bus go round and round...round and round...\"#RET##MN# gets to ride the short bus to school!$N$\n");
       target("You twirl your hands around each other and sing to #TN#,#RET#\"The wheels on the bus go round and round...round and round...\"#RET#You get to ride the short bus to school!$N$\n", "#MN# twirls #MP# hands around each other and sings to #TN#,#RET#\"The wheels on the bus go round and round...round and round...\"#RET##MN# gets to ride the short bus to school!$N$\n", "#MN# twirls #MP# hands around each other and sings to you,#RET#\"The wheels on the bus go round and round...round and round...\"#RET##MN# gets to ride the short bus to school!$N$\n");
       afar("$HC$[afar]$N$ You twirl your hands around each other and sing to #TN#,#RET#$HC$[afar]$N$ \"The wheels on the bus go round and round...round and round...\"#RET#$HC$[afar]$N$ You get to ride the short bus to school!$N$\n", "$HC$[afar]$N$ #MN# twirls #MP# hands around each other and sings to you,#RET#$HC$[afar]$N$ \"The wheels on the bus go round and round...round and round...\"#RET#$HC$[afar]$N$ #MN# gets to ride the short bus to school!$N$\n");
    }
}

int
cmd_shortbus(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
