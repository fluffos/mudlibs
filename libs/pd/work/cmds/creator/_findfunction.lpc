//  _findfunction.c

#define FUNCTIONS ([ \
    ])

int cmd_findfunction(string s) {
   if(!s || s == "") return notify_fail("Syntax: <findfunction [function]>\n");
   if(!FUNCTIONS[s]) return notify_fail("Function Not Found.\n");
   write("Found in: "+FUNCTIONS[s]);
   return 1;
}

