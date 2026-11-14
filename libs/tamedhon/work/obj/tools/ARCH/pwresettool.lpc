// passwort reset tool von Aloy

inherit "/std/thing";

#include <properties.h>
#include <language.h>
#include <wizlevels.h>
#include <config.h>

/* Variablen des secure save file */
int level;
string password, name, shell;
int loginfails;
mixed *domains;
int creation_date;

int pwreset(string str);

void create() {
    if (!clonep(this_object()))
        return;
    ::create();

    SetProp(P_NAME, "Passwort-Reset-Tool");
    SetProp(P_SHORT, "Das Passwort-Reset-Tool");
    SetProp(P_LONG,
      "Das Passwort-Reset-Tool kann das Passwort eines Spielers auf 'neues_passwort' resetten.\n\n"
        "<pwreset 'spieler'>"
    );
    SetProp(P_GENDER, NEUTER);
    AddId(({"prt","pwresettool","passwort-reset-tool","Tool","tool","prttool"}));
    SetProp(P_VALUE,0);
    SetProp(P_WEIGHT,0);
    SetProp(P_NOBUY,1);
    SetProp(P_NOSELL,1);
    SetProp(P_NODROP,1);
    SetProp(P_NEVERDROP,1);
    SetProp(P_AUTOLOADOBJ,1);

    AddCmd(({"pwreset"}), "pwreset");
}

void init() {
    if (!IS_ARCH(this_player())) {
        write(Name()+" zerfällt in Deinen Händen zu Staub.\n");
        say(Name()+" zerfällt in "+this_player()->name(WESSEN)+" Händen.\n");
        call_out("remove",0);
        return;
    }
    ::init();
}

int pwreset(string str)
{
    write("Pfad: /"+__MASTER_OBJECT__->secure_savefile(str)+"\n");
    restore_object("/"+__MASTER_OBJECT__->secure_savefile(str));
    write("Passwort alt: "+password+"\n");

    password = "iO1o3Zfxylg3U";

    save_object("/"+SECURESAVEPATH+str[0..0]+"/"+str);
    "/secure/master"->RemoveFromCache(str);
    restore_object("/"+__MASTER_OBJECT__->secure_savefile(str));
    write("Passwort neu: "+password+" => 'neues_passwort'\n");

    level = 0;
    password = "";
    name = "";
    shell = "";
    loginfails = 0;
    creation_date = 0;

    return 1;
}
