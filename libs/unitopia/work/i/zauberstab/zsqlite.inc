// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/i/zauberstab/zsqlite.inc
// Description:	Eine Nachempfindung des sqlite-Kommandozeilentools.
// Author:	Menaures (05.08.2007)
//
// $Log: zsqlite.inc,v $
// Revision 1.2  2007/08/19 15:27:16  menaures
// schema
//
// Revision 1.1  2007/08/06 13:41:51  menaures
// Erste Version mit Grundfunktionalitaet
//

#include <input_to.h>
#include <strings.h>

mapping sqlite;

private void sqlite_command(string str);
private void sqlite_print(mixed * result);

private varargs void z_sqlite_prompt(string str, string buffer)
{
    /* Abbruch: */
    if(member((["**","~q"]), str))
    {
        sl_close();
        return;
    }

    /* Befehlsauswertung: */
    if(!buffer && strlen(str) && str[0] == '.')
    {
        sqlite_command(str[1..]);
        return;
    }

    /* SQL-Query: */
    buffer = (buffer || "") + str;
    buffer = trim(buffer, TRIM_RIGHT, " \t\n");

    if(strlen(buffer))
    {
        if(buffer[<1] != ';')
        {
            /* Eingabe eines mehrzeiligen Befehls. */
            input_to(#'z_sqlite_prompt, INPUT_PROMPT|INPUT_APPEND, "   ...> ", buffer+"\n");
            return;
        }

        /* Query ausfuehren: */
        string error;
        mixed * result;

        error = catch(result = sl_exec(buffer); nolog);

        if(error)
            write(error);

        if(result)
            sqlite_print(result);
    }

    /* Neuer Prompt: */
    input_to(#'z_sqlite_prompt, INPUT_PROMPT|INPUT_APPEND, "sqlite> ");
}

int z_sqlite(string str)
{
    mapping opt;
    string error, file, *files;
    string usage = "zsqlite [-f] [-i] <datei>\n";

    SECURE;
    HELP("zsqlite");

    sqlite = params["zsqlite"];

    if(!mappingp(sqlite))
    {
        sqlite = ([:1]);
        set_param("zsqlite", sqlite);
    }

    /* Falls vorher etwas schief ging: */
    error = catch(sl_close(); nolog);

    if(!error)
        write("Alte Datenbank war noch aktiv. Closed.\n");

    if(!str)
        FAIL(usage);

    opt = getopt(str, (["f":0, "i":0]), GO_FAILS);

    if(!opt)
        return 0;

    if(sizeof(opt["args"]) == 0)
        FAIL("Parameter <datei> fehlt.\n"+usage);

    files = expand_wildcards(implode(opt["args"], " "));

    if(sizeof(files) != 1)
        FAIL("Es kann nur eine Datei angegeben werden.\n"+usage);

    file = files[0];

    if(!opt["f"] && file[<3..] != ".db")
        FAIL("zsqlite: Datei ist keine Datenbank (*.db).\n"
             "         Benutze -f um sie dennoch zu laden.\n");

    if(!opt["i"] && file_time(file) == -1)
        FAIL("zsqlite: Datei existiert nicht.\n"
             "         Benutze -i um sie zu erstellen.\n");

    error = catch(sl_open(file); nolog);

    if(error)
        FAIL(error);

    write("SQL abschliessen mit ;, Abbruch mit ~q, Hilfe mit '.help'.\n");
    input_to(#'z_sqlite_prompt, INPUT_PROMPT|INPUT_APPEND, "sqlite> ");

    return 1;
}

private void sqlite_command(string str)
{
    string cmd, arg;
    mixed * r;

    str = trim(str, TRIM_LEFT);

    if(member(str, ' ') > 1)
    {
        cmd = str[0..member(str, ' ')-1];
        arg = str[member(str, ' ')+1..];
    }

    else
    {
        cmd = str;
        arg = "";
    }

    switch(cmd)
    {
        default:
            write("Unbekannter Befehl "+cmd+".\n"
                  "Hilfe gibts mit '.help', Ende mit '.quit'.\n");
            break;

        case "spaltentrenner":
        case "separator":
            sqlite["separator"] = arg;
            write("Separator auf '"+arg+"' gesetzt.\n");
            break;

        case "tabellen":
        case "tables":
            r = sl_exec("SELECT name FROM sqlite_master "
                        "WHERE type IN ('table','view') AND name NOT LIKE 'sqlite_%' "
                        "UNION ALL "
                        "SELECT name FROM sqlite_temp_master "
                        "WHERE type IN ('table','view') "
                        "ORDER BY 1");
            sqlite_print(r);
            break;

        case "schema":
            r = sl_exec("SELECT sql||';' FROM sqlite_master "
                        "WHERE sql NOT NULL AND type=='table' "
                        "ORDER BY name");
            sqlite_print(r);
            break;

        case "show":
            write("Spaltentrenner ist '"+(sqlite["separator"]||"|")+"'.\n");
            break;

        case "hilfe":
        case "help":
            write(
".help                  Diese Meldung anzeigen.\n"
".quit                  Programm beenden.\n"
".schema                Die CREATE Befehle anzeigen.\n"
".separator STRING      Spaltentrenner auf STRING setzen.\n"
".show                  Aktuelle Einstellungen anzeigen.\n"
".tables                Tabellen auflisten.\n");
            break;

        case "databases":
        case "dump":
        case "echo":
        case "explain":
        case "header":
        case "headers":
        case "indices":
        case "mode":
        case "nullvalue":
        case "output":
        case "prompt":
        case "read":
        case "timeout":
        case "width":
            write("Befehl "+cmd+" ist noch nicht implementiert.\n");
            break;

        case 0:
        case "exit":
        case "quit":
        case "ende":
            sl_close();
            return;
    }

    set_param("zsqlite", sqlite);    
    input_to(#'z_sqlite_prompt, INPUT_PROMPT|INPUT_APPEND, "sqlite> ");
}

private void sqlite_print(mixed * result)
{
    switch(sqlite["mode"])
    {
        case 0:
        default:
            result = map(result, #'map, #'to_string);
            result = map(result, #'implode, sqlite["separator"] || "|");
    }

    this_player()->more(result, 0, 0, M_AUTO_END);
}

/* --- End of file. --- */
