//master.c

//Tacitus @ LPUniversity
//07-OCT-05
//Admin command

#include <config.h>

int main(string arguments)
{
     string err = "";

     if(!adminp(previous_object())) return notify_fail("Error [master]: Access denied.\n");

     err += catch(destruct(master()));
     err += catch(destruct(find_object("/adm/obj/master/valid")));
     err += catch(load_object("/adm/obj/master/valid"));
     err += catch(load_object("/adm/obj/master"));
     err += catch(destruct(find_object(SIMUL_OB)));
     err += catch(load_object(SIMUL_OB));
     if(err && err != "000000")
     {
          write("Error [system_update]: Error when reloading system objects: " + err + "\n");
          return 1;
     }
     else
     {
          write("Success [system_update]: System objects updated succesfuly\n");
          return 1;
     }

}

string help() {
return (HIW + " SYNTAX: " + NOR + "master\n\n"
    "This command reloads core system files. No argument is taken.\n");
}
