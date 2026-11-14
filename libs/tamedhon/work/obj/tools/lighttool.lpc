// lighttool von Aloy

inherit "/std/thing";

#include <properties.h>
#include <language.h>
#include <wizlevels.h>
#include <ansi.h>

int light();

void create() {
    if (!clonep(this_object()))
        return;
    ::create();

    SetProp(P_NAME, "Light-Tool");
    SetProp(P_SHORT, "Das Light-Tool");
    SetProp(P_LONG,
      "Das Lighttool gibt die Gesamthelligkeit im Raum aus.\n\n"
        "<licht/light> - Gibt Gesamthelligkeit aus."
    );
    SetProp(P_GENDER, NEUTER);
    AddId(({"lighttool","light-tool","Tool","tool","lighttool"}));
    SetProp(P_VALUE,1000);
    SetProp(P_WEIGHT,100);
    SetProp(P_NOBUY,1);
    SetProp(P_NOSELL,1);
    SetProp(P_NODROP,1);
    SetProp(P_NEVERDROP,1);
    SetProp(P_AUTOLOADOBJ,1);

    AddCmd(({"light","licht"}), "light");
}

void init() {
    if (!IS_WIZARD(this_player())) {
        write(Name()+" zerfällt in Deinen Händen zu Staub.\n");
        say(Name()+" zerfällt in "+this_player()->name(WESSEN)+" Händen.\n");
        call_out("remove",0);
        return;
    }
    ::init();
}

int light()
{
    float gesamtlicht = 0.0;
    string output = "";
    
    output += "Die Gesamthelligkeit setzt sich aus folgenden Werten zusammen: \n";
    output += "========================================================================\n";
    
    gesamtlicht += ({float})this_player()->QueryProp(P_LIGHT);
    
    if(this_player()->QueryProp(P_LIGHT) > 0)
        output += sprintf("%-68s %s\n","Spieler: ",ANSI_LYELLOW+this_player()->QueryProp(P_LIGHT)+ANSI_NORMAL);

    object *envs = all_environment(this_player());

    if(!sizeof(envs) == 0)
    {  
        for(int i=0;i < sizeof(envs);i++)
        {
            gesamtlicht += ({float})envs[i]->QueryProp(P_LIGHT);
            
            if(envs[i]->QueryProp(P_LIGHT) > 0)
                output += sprintf("%-68s %s\n",object_name(envs[i]),ANSI_LYELLOW+envs[i]->QueryProp(P_LIGHT)+ANSI_NORMAL);
      
            object *invs = deep_inventory(envs[0]);
            if(!sizeof(invs) == 0)
            {  
                for(int j=0;j < sizeof(invs);j++)
                {
                    if(!interactive(invs[j]))
                    {
                        gesamtlicht += ({float})invs[j]->QueryProp(P_LIGHT);
                        
                        if(invs[j]->QueryProp(P_LIGHT) > 0)
                            output += sprintf("%-68s %s\n",object_name(invs[j]),ANSI_LYELLOW+invs[j]->QueryProp(P_LIGHT)+ANSI_NORMAL);
                    }
                }
            }
        }
    }
    output += "========================================================================\n";
    output += sprintf("%-68s %s\n","Die Gesamthelligkeit im Raum ist: ",ANSI_LYELLOW+gesamtlicht+ANSI_NORMAL);
    write(output);
    
    return 1;
}
