#include <mudlib.h>
#include <setbit.h>
#include <verb.h>

inherit VERB_OB;

void do_use_str(string str)
{
	object o;
	mixed ret;

	o = MYENV_OB(str);
	if(!o) return;
	ret = o->direct_use_obj();
	if(ret==1){
                o->do_use_it();
                return;
        }
        if(stringp(ret)){
                write(ret);
                return;
        }
        write("你无法使用"+o->short()+"。\n");
        return;
}
mixed * query_verb_info()
{
    return ({ ({ "STR", }) });
}

