//#pragma optimize all

#ifndef __SENSIBLE_MODIFIERS__
#define nosave static
#define protected static
#endif

#include <globals.h>
void create()
{
    seteuid( ROOT_UID );
    seteuid(getuid());
    write("simul_efun ³É¹¦¼ÓÔØ.\n");
}
#include "/adm/simul_efun/atoi.c"
#include "/adm/simul_efun/chinese.c"
#include "/adm/simul_efun/gender.c"
#include "/adm/simul_efun/object.c"
#include "/adm/simul_efun/path.c"
#include "/adm/simul_efun/wizard.c"
// This must be after gender.c
#include "/adm/simul_efun/message.c"
#include "/adm/simul_efun/file.c"
// This is the utilitis
#include "/adm/simul_efun/util.c"


varargs object snoop(object who, object target) 
{
    if(!target) return efun::snoop(who);
    if(!wizardp(who)) return 0;
//    log_file("snoop", "¡¼" + ctime(time())+ "¡½" +"\t" +
//        who->query("name") + "(" + who->query("id") + ")" +" ÇÔÌý " +
//        target->query("name") + "(" + target->query("id") + ")¡£\n");
    return efun::snoop(who, target);
}

void shutdown(int etc)
{
    if( base_name(previous_object())!=NATURE_D) return 0;
    else efun::shutdown(etc);
}
void destruct(object ob)
{
        string err, name;

        if ( ob )
        {
                if ( previous_object() )
                        err = catch(ob->remove( geteuid(previous_object()) ));
                else
                        err = catch(ob->remove(0));
                if ( err )
                {
                        if ( userp(ob) && geteuid(previous_object())!=ROOT_UID )
                                return;
                }
                if (ob->query("hcloth/name"))
                {
                        name = base_name(ob);
                        rm(name + ".c");
                }
                efun::destruct(ob);
        }
}