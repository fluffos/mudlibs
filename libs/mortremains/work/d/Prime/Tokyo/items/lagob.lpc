
#include <mudlib.h>
#include "/u/d/dalceon/mydefines.h"

inherit OBJECT;

int lagging;
int free;
void lag_cmds();
string *tmp_cmds;
string *force_cmds;
void create(){
    lagging = 0;
    tmp_cmds = ({});
    force_cmds = ({});
    free = 0;
    seteuid(getuid());
    set("id", ({ "lag object", "object"}) );
    set("short", "lag object");
    set("long", "The thing that makes you lag.\n");
    set("invisible", 1);
}

void init()
{
   add_action("make_lag","");
}

int make_lag ( string str ) {
    if(free) return 0;
    if(!str) str = "";
    if(lagging) {
       string full_cmd;
       tell_object(DALCEON, "You are LAGGING!!\n");
       full_cmd = query_verb() +" "+str;
       tmp_cmds += ({ full_cmd });
       return 1;  //so player gets nothing;
    }
    else {
       tell_object(DALCEON, "Starting to LAG!!\n");
       lagging = 1;
       call_out("lag_cmds", random(30));
       return 0;
    }
}

void lag_cmds(){
     tell_object(DALCEON, "You are RELEASING!!\n");
     force_cmds = tmp_cmds;
     tmp_cmds = ({});
     lagging = 0; //want release commands so I can force them.
     for(int i =0;i<sizeof(force_cmds);i++){ 
        free = 1;
        TP->force_me(force_cmds[i]);
     }
     free = 0;
     force_cmds = ({});
}

void set_lagging() {
      lagging = 1;
}


