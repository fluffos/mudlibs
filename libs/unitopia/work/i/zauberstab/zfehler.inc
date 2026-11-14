// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /i/zauberstab/zfehler.inc
// Description: Ein Fehlerbrowser fuer die neue Fehler-Datenbank
// Author:      Monty (22.07.95) Rewrite Myonara (02.07.13)
// Modified:
//
// $Log: zfehler.inc,v $
// Revision 1.107  2016/07/31 01:00:03  myonara
// neue public Funktion start_menue_with_error_list
//
// Revision 1.106  2016/05/30 05:07:17  myonara
// Einen Aufruf von _total mit B_END_LINE optimieren koennen.
//
// Revision 1.105  2015/05/29 11:15:56  myonara
// Unvollst.Fehler um Debugger erweitert.
//
// Revision 1.104  2015/02/26 18:34:00  myonara
// merh Debugausgaben fuer TLE Fehlersuche.
//
// Revision 1.103  2015/02/23 18:14:48  myonara
// von single_action direkt in Zsf springen; schreiben in Datei debuggt.
//
// Revision 1.102  2015/02/14 18:37:46  myonara
// Bugfix zu "T"yp umschaltung (B_REBUILT)
//
// Revision 1.101  2015/01/24 17:56:47  myonara
// Anzeige Archivliste-total und >Kommando Archivliste.
//
// Revision 1.100  2015/01/04 12:32:25  myonara
// Bugfixes privgroups
//
// Revision 1.99  2014/10/12 11:03:17  myonara
// BugFix in zfe_abstract (Fehlerzusammenfassung)
//
// Revision 1.98  2014/08/02 16:07:41  myonara
// mail-from = EDB_H_PLAYER (also verursacher statt TI)
// Anzeige unvollst. Fehler
// Anzeige archivierter Fehler
// neue Option -zD
//
// Revision 1.97  2014/04/21 17:40:23  sorcerer
// Datentyp fuer zfehler-Mail korrigiert
//
// Revision 1.95  2014/03/12 19:55:17  myonara
// Bugfix in single_action l,z,<,>
//
// Revision 1.95  2014/03/12 19:55:17  myonara
// Kompletter Rewrite zusammen mit /apps/error_db+error_archive.
//
//


#include <editor.h>
#include <error_db.h>
#include <rtlimits.h>

#undef DEBUGGER
//#define DEBUGGER "myonara"
//#include <debug.h>
#undef DEBUG
#define DEBUG(x) ERROR_DB->debug_msg(x)

#define ZFE_OPTIONS "zfe:options"
#define ZFE_INDEX   "zfe:index"
#define ZFE_ERRNUM  "zfe:errnum"
#define ZFE_GOTO    "zfe:goto"
#define ZFE_ZSF     "zfe:abstract"
#define ZFE_Z_GESAMT "zfe:zaehler:gesamt"
#define ZFE_Z_ZUST   "zfe:zaehler:zustaendig"
#define ZFE_Z_TODO   "zfe:zaehler:todo"
#define ZFE_ZSF_TRACE   1
#define ZFE_ZSF_INFOS   2
#define ZFE_ZSF_ARCHIVE 4
#define ZFE_MORE_LINE_HF \
"-------------------------------------------------------------------------------"
#define ZFE_MORE_LINE_MI \
"...----------------------------------------------------------------------------"

#define ZFE_BHELP(x)  (HILFE_PFAD+"fbrowser"+x)

private nosave mixed * zfe_last_menues; // Zwischenvariable fuer den ed.
private nosave mixed * zfe_last_errnum; // Zwischenvariable fuer -g/-G

#define ERROR_NAMES     ([EDB_FEHLER    : "FEHLER",         \
                          EDB_IDEE      : "IDEE",           \
                          EDB_RUNTIME   : "RUNTIME ERROR",  \
                          EDB_COMPILE   : "COMPILE ERROR",  \
                          EDB_LOB       : "WUERDIGUNG",     \
                          EDB_TYPO      : "TYPO",           \
                          EDB_DETAIL    : "DETAIL"])

#define WILDCARD2REGEXP(w) ("^"+regreplace(regreplace((w),"([.^$\\\\<>|()[\\]])", \
                        "\\\\\\1",1),"\\*",".*",1)+"$")
#define WILDCARDARR2REGEXP(w) ("^("+        \
    implode(map((w),                    \
        (:                  \
            regreplace(regreplace($1,"([.^$\\\\<>|()[\\]])", "\\\\\\1",1), \
                "\\*",".*",1)           \
        :)),"|") +              \
    ")$")

nosave mixed last_zfe;

// Fuer /secure/master/log_error.inc:
nomask int get_own_rtes() { return params["own-rtes"]; }

private string format_filename(string name)
{
    string file;

    if(!name) return "-";
    if(sizeof(explode(name," "))>1) return name;

    file=map2domain(name,1);
    if(!file) return name;
    if(name[<2..<1]!=".c") file=file[0..<3];
    if(file==name)  return name;
    return name + " ("+file+")";
}

// Manche Fehlergruppen sind so voll, dass die Bearbeitung im Fehler-Browser
// die Evalgrenzen sprengt. Fehler muss man aber immer bearbeiten koennen,
// also brauchen wir hier hoehere Limits. :-(

private int do_zfe_more_action(string str, int more_line, int max_line, 
                                mixed more_id)
{
    return ::more_action(str, more_line, max_line, more_id);
}

private int zfe_more_action(string str, int more_line, int max_line, 
                                mixed more_id)
{
    return limited(#'do_zfe_more_action, ({__MAX_EVAL_COST__ * 4}),
                   str, more_line, max_line, more_id);
}

private mixed get_trace_text(int errnr, int errflag)
{
    mixed *eheader;
    mapping edata;
    
    eheader = ERROR_DB->query_error_header(errnr);
    edata = ERROR_DB->query_error_data(errnr);
    if (!pointerp(eheader) || !mappingp(edata))
    {
        errflag = 1;
        return "Fehler nicht mehr vorhanden!";
    }
    switch(eheader[EDB_H_TYPE])
    {
    case EDB_RUNTIME:
        if (!stringp(edata[EDB_E_TRACE]))
        {
            errflag = 1;
            return "Keine Trace-Infos vorhanden.";
        }
        errflag = 0;
        return explode(edata[EDB_E_TRACE],"\n");
    default:
        errflag = 1;
        return "Es gibt keine Trace zu nicht-Runtime-Fehlern.";
    }
}

private mixed get_info_text(int errnr, int errflag)
{
    string *strs;
    mixed *eheader;
    mapping info,edata;
        
    eheader = ERROR_DB->query_error_header(errnr);
    edata = ERROR_DB->query_error_data(errnr);
    if (!pointerp(eheader) || !mappingp(edata))
    {
        errflag = 1;
        return "Fehler nicht mehr vorhanden!";
    }
         
    switch(eheader[EDB_H_TYPE])
    {
    case EDB_FEHLER:
    case EDB_IDEE:
    case EDB_LOB:
    case EDB_TYPO:
    case EDB_DETAIL:
    case EDB_RUNTIME:
        info = edata[EDB_E_USER_INFO];
        break;
    case EDB_COMPILE:
        errflag = 1;
        return "Es gibt keine Debug-Infos zu Compile-Fehlern.";
    }
        
    if(!mappingp(info) || !sizeof(info))
    {
        errflag = 1;
        return "Zu diesem Fehler gibt es keine Debug-Infos.\n";
    }    
    strs = ({});
    foreach(string key:sort_array(m_indices(info),#'>))
    strs += explode(
        sprintf("%-=11s %-=66s\n", key+":",
        stringp(info[key])?info[key]:mixed2str(info[key])),
        "\n")[0..<2];
    errflag = 0;
    return strs;            
}

// Der Filename des Fehlers err
// Wenn real_file, dann die Datei auf welche sich die Zeilenangabe
// bezieht, liefern. Ansonsten den objekt-namen (ohne Endung)
private string _get_file_name(int err, int real_file)
{
    string tmp,main;
    mixed * header = ERROR_DB->query_error_header(err);

    if (!pointerp(header))
        return 0;
    tmp=header[EDB_H_FILE];

    if(!tmp) 
        return 0;
    if(real_file && sscanf(tmp,"%s (%s)",main,tmp) == 2)
    {
        main = MASTER_OB->include_file(tmp,main,0);
        if (stringp(main)) return main;
    }

    // wenn kein . am ende des filenamens vorkommt, dann einen dranhaengen!
    tmp = explode(tmp, " ")[0];
    tmp = explode(tmp, "#")[0];
    if (strstr(tmp,".",0) < strlen(tmp)-5 && real_file)
    {
        if(file_size(tmp+".c")>=0)
            tmp += ".c";
        else if(file_size(tmp+".udl")>=0)
            tmp += ".udl";
        else if(file_size(tmp)<0)
            tmp += ".c";
    }
    
    if(!sizeof(tmp))
        return tmp;

    tmp = (tmp[0] == '/') ? tmp : "/" + tmp;
    if(real_file) tmp = map2domain(tmp,1)||tmp;
    return tmp;
}

private int _is_existing_error(int num, mapping pro)
{
    mixed error = ERROR_DB->query_error_header(num);
    if (!error)
        return 0;
    error=mkmapping(error[EDB_H_DEBUGGER]);
    if (!pro) //Admin
        return 1;
    if (sizeof(({mapping})error & pro)) //Er ist zustaendig
        return 1;
    else
        return 0;
}

private int _is_still_new_error(int num)
{
    mixed error = ERROR_DB->query_error_header(num);
    if (!error)
        return 0;
    if (member(error[EDB_H_DEBUGGER],EDB_BACKUP_GROUP)!=-1)
        return 0;
    return 1;
}

private int * _query_new_wiz_errors()
{
    mixed * new = this_player()->query_new_wiz_errors();
    return new[EDB_NEW_WIZ_ERRORS]||({});
}

private mapping _query_wiedervorlage()
{
    mixed * new = this_player()->query_new_wiz_errors();
    if (sizeof(new) <= EDB_WIEDERVORLAGE)
        return ([]);
    return new[EDB_WIEDERVORLAGE]||([]);
}

private void add_wiedervorlage(int * errnum, int time)
{
    mixed * new = this_player()->query_new_wiz_errors();
    mapping wdiff;
    if (!pointerp(errnum) || !sizeof(errnum))
        return;
    if (sizeof(new) <= EDB_WIEDERVORLAGE)
    {
        new += ({ ([ time : errnum ]) });
        // TODO /i/player/wiz_soul.c anpassen
    }
    else
    {
        wdiff = new[EDB_WIEDERVORLAGE];
        if (member(wdiff,time))
            wdiff[time] = wdiff[time] - errnum + errnum;
        else
            wdiff[time] = errnum;
        new[EDB_WIEDERVORLAGE] = wdiff;
    }
    this_player()->set_new_wiz_errors(new);
}

private void remove_wiedervorlage(int * errnum)
{
    mixed * new = this_player()->query_new_wiz_errors();
    mapping wdiff;
    if (!pointerp(errnum) || !sizeof(errnum))
        return;
    if (sizeof(new) <= EDB_WIEDERVORLAGE)
    {
        return; // nichts zum loeschen da.
    }
    else
    {
        wdiff = new[EDB_WIEDERVORLAGE];
        wdiff = filter(map(wdiff, (: $2-$3 :), errnum),(: sizeof($2)>0 :) );
        new[EDB_WIEDERVORLAGE] = wdiff;
    }
    this_player()->set_new_wiz_errors(new);
}


private varargs void _update_new_wiz_errors(int *exclude, int *include)
{
    mixed * new = this_player()->query_new_wiz_errors();
    mixed * errlist;
    mapping errneu,wdiff;
    if (sizeof(new) <= EDB_WIEDERVORLAGE)
    {
        new += ({ ([ ]) });
        // TODO /i/player/wiz_soul.c anpassen
    }
    exclude ||= ({});
    include ||= ({});
    if (new[EDB_LAST_READ] < time()) // nur einmal pro Thread berechnen
    {
        errlist = ERROR_DB->query_error_list(
                        this_player()->query_real_name(),
                        ([
                        EDB_OPT_NO_EMPTY_ERR : 1,
                        EDB_OPT_NEWER_SINCE : new[EDB_LAST_READ],
                        EDB_OPT_GROUP_EXCLUDE : ({ EDB_BACKUP_GROUP }),
                        ])) || ({ });
        // DEBUG(sprintf("_update_new_wiz_errors-1:%Q %Q",new,errlist));
        errlist = map(errlist, (: $1[EDB_ERRLIST_ERRNUM] :));
        errneu = mkmapping(errlist)
               + mkmapping(
                    filter(new[EDB_NEW_WIZ_ERRORS],#'_is_still_new_error
                    ));
        wdiff = filter(new[EDB_WIEDERVORLAGE],
                (: $1 < $3 :), time());
        foreach(int t2,int *e2list : wdiff)
        {
            errneu += mkmapping(e2list);
        }
        new[EDB_WIEDERVORLAGE] -= wdiff;
        new[EDB_NEW_WIZ_ERRORS] = m_indices(errneu);
        new[EDB_LAST_READ] = time();
        // DEBUG(sprintf("_update_new_wiz_errors-2:%Q",new));
     }
     new[EDB_NEW_WIZ_ERRORS]=new[EDB_NEW_WIZ_ERRORS]
                            -exclude-include+include;
     this_player()->set_new_wiz_errors(new);
}

public string zfe_query_error_references(int errnum)
{
    mixed * new = this_player()->query_new_wiz_errors();
    string result = "";
    if (sizeof(new) <= EDB_WIEDERVORLAGE)
    {
        new += ({ ([ ]) });
        // TODO /i/player/wiz_soul.c anpassen
    }
    if (member(new[EDB_NEW_WIZ_ERRORS],errnum)!=-1)
    {
       result += "Fehler "+errnum+" ist als neu markiert. ";
    }
    mixed * eheader = ERROR_DB->query_error_header(errnum);
    if (!pointerp(eheader))
    {
        result += "Fehler in Fehlerdatenbank nicht vorhanden.";
        return result;
    }
    if (member(eheader[EDB_H_DEBUGGER],EDB_BACKUP_GROUP)!=-1)
    {
        result += "Fehler in Backupgruppe (Geloescht). ";
    }
    else
    {
        result += "Debugger: "+liste(eheader[EDB_H_DEBUGGER],", ");
    }
    return result;
}

// Erstellt die Zusatzgruppen abhaengig von den flags:
// flags & 1: private Gruppen aufdroeseln
// flags & 2: Hauptgruppe rn minus private Gruppen ermitteln
// flags & 4: lowercase-Gruppen aus dem Zauberstabmenue
// flags & 8: uppercase-Gruppen aus dem Zuaberstabmenue
private mapping provide_privgroups(int flags, mapping options)
{
    mapping zust = ([ ]),frn;
    int errnum,*errnums = ({});
    string * pg,rn = this_player()->query_real_name();
    _update_new_wiz_errors();
    if (options[EDB_OPT_NO_PRIVATES])
    {
        return zust;
    }
    if ((flags & 1) != 0)
    {
        foreach(errnum,pg : params["zfe-privgroups"] ||([]))
        {
            if (!_is_still_new_error(errnum))
            {
                m_delete(params["zfe-privgroups"],errnum);
                continue;
            }
            errnums = (errnums - ({ errnum })) + ({ errnum });
            foreach(string str : pg)
            {
                if (member(zust,str))
                {
                    zust[str] += ({ errnum });
                }
                else
                {
                    zust[str] = ({ errnum });
                }
            }
        }
    }
    if ((flags & 2) != 0)
    {
        DEBUG("provide_privgroups-2: "+rn);
        frn = ERROR_DB->query_group_list(rn,([EDB_OPT_GROUP_ONE: rn ]));
        if (sizeof(frn)) // && sizeof(errnums))
        {
            zust[rn] =  (frn[rn] - errnums) + (zust[rn]||({}));
        }
    }
    if ((flags & 4) != 0)
    {
        pg = filter(m_indices(params["zfe-groups"]||([])),
                (: lower_case($1) == $1 :));
        //pg = pg -({rn})+({rn});// Eigene Gruppe erzwingen.
        if (sizeof(pg))
        {
            DEBUG(sprintf("provide_privgroups-4 %Q",pg));
            frn = ERROR_DB->query_group_list(rn,
                    ([EDB_OPT_EXLUSIVE_GROUPS:pg]));
            if (mappingp(frn) && sizeof(frn))
            {
                zust += frn;
            }
        }
    }
    if ((flags & 8)!= 0)
    {
        pg = filter(m_indices(params["zfe-groups"]||([])),
                (: lower_case($1) != $1 :));
        if (sizeof(pg))
        {
            DEBUG(sprintf("provide_privgroups-8 %Q",pg));
            frn = ERROR_DB->query_group_list(rn,
                    ([EDB_OPT_EXLUSIVE_GROUPS:pg]));
            if (mappingp(frn) && sizeof(frn))
            {
                zust += frn;
            }
        }
    }
    DEBUG(sprintf("provide_privgroups-a:%d %Q %Q",flags,options,m_indices(zust)));
    zust = ERROR_DB->query_group_list(this_player()->query_real_name(), 
        options + ([EDB_OPT_ADD_Z_GROUP : zust]));
    DEBUG(sprintf("provide_privgroups-b:%Q",m_indices(zust)));
    return zust;
}

// aus (UNItopia)/p/Misc/i/zeitumrechnung.c entliehen und angepasst:
#define ZFE_MONATSERSTER ({ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, \
                            304, 334, 365 })
private int extract_timestamp(string datstring)
{
    int n,tag,mon,jahr,h,m,s;
  if(!stringp(datstring) ||
     (sscanf(datstring,"%d.%d.%d %d:%d:%d",tag,mon,jahr,h,m,s) < 3))
  {
      //do_warning("Falsches Format in:\n"+mixed2str(datstring)+"\n");
      return 0;
  }
  jahr=jahr % 100;
  jahr += (jahr<70?30:-70);        // Jahre seit 1970
  n +=  jahr*365 + (jahr+2)/4;     // Tage und Schalttage. Das erste Schaltjahr
                                   // ist 1972, also jahr==2
  if (!((jahr+2)%4) && mon<3) n-=1;// dann kommt der Schalttag dieses Jahres
                                   // erst noch
  //gegen RTEs:
  if(mon<1)
      mon=1;
  n += (tag+ZFE_MONATSERSTER[mon-1]-1);
  n *= 24; n+=h;
  n -= 1;                          // 1 Stunde abziehen! Es wurde am 1.1.70
                                   // um 1 Uhr angefangen zu zaehlen!
  if (mon>3 && mon<11) n-=1;       // Sommerzeit
  n *= 60; n+=m;
  n *= 60; n+=s;
  return n;
}

private int * extract_timestamps(string str)
{
    string * ts = explode(space(str),"-");
    int * result = ({ 0, 0 });
    if (sizeof(ts)>0) {
        result[0] = extract_timestamp(ts[0]);
    }
    if (sizeof(ts)>1) {
        result[1] = extract_timestamp(ts[1]);
    }
    if (result[0] == 0 && result[1] == 0)
        return 0;
    return result;
}

private int * extract_numbers(string str)
{
    string * nums = explode(space(str),"-");
    int * result = ({ 0, 0 });
    int i;
    if (sizeof(nums)>0 && !str2int(nums[0],&i) )
    {
        if (sizeof(nums) == 1)
        {
            return ({ i });
        }
        result[0] = i;
    }
    if (sizeof(nums)>1 && !str2int(nums[1],&i) )
    {
        result[1] = i;
    }
    return result;
}

private int extract_xdays(string str)
{
    int i;
    if (strstr(space(str),"+")==0)
    {
        if (sizeof(space(str))>1)
        {
             if (!str2int(space(str[1..]),&i))
             {
                 str = explode(shorttimestr(time()+i*60*60*24)," ")[0];
             }
             else
             {
                 return -1;
             }
        }
        else
        {
            return -1;
        }
    }
    return extract_timestamp(str);
}

// Interne Funktion fuer get_errmsg_text
private string format_history(mixed history)
{
    string ret;

    ret = "";

    for (int i = 0; i < sizeof(history); i++)
    {
        ret += sprintf("\n%s%-10s %54s\n %=-78s\n",
            EDB_HISTORY_TYPES[history[i][EDB_EH_TYPE]],
            capitalize(history[i][EDB_EH_WIZ]||"-"),
            timestr(history[i][EDB_EH_DATE]),
            to_string(history[i][EDB_EH_INFO]||""));
    }
    return ret;
}

private void cmd_wechsle_pfad(int errnum)
{
    mixed header = ERROR_DB->query_error_header(errnum);
    string datei,*pfad;
    if (!pointerp(header))
    {
        browse_write_line(
            "Fehler inzwischen geloescht, kein Pfadwechsel moeglich.");
        return;
    }
    datei = header[EDB_H_FILE];
    if (stringp(datei) && sizeof(datei))
    {
        this_player()->cd(datei);
        browse_write_line("Pfad gesetzt.");
        return;
    }
    browse_write_line("Unbekannter Pfad.");
}

private int cmd_add_comment(int errnum, string str, mixed * menues)
{
    int ret;
    if (!str || str == "")
    {
        this_player()->mini_ed(
            function void(string *text):
            int err_num = errnum
            {
            if(text)
            {
                switch (ret = ERROR_DB->add_history(
                        err_num,
                        this_player(),
                        EDB_EHT_COMMENT,
                        implode(text,"\n")))
                {
                case NO_ERROR:
                    browse_write_line("Diesen Fehler gibt es nicht (mehr).\n");
                    break;
                case NOT_RESPONSIBLE:
                    browse_write_line("Du bist dafuer nicht zustaendig.\n");
                    break;
                case NOT_VALID: // sollte nicht auftauchen.
                    browse_write_line("Unbekannter-History-Typ.\n");
                    break;
                case ERROR_OK:
                    break;
                default:
                    browse_write_line("unbekannter Fehler "+ret+"\n");
                    break;
                }
            }
            menues[<1][B_FLAGS] |= BF_DIRTY;
            dynamic_browse(menues); // Wiedereinstieg ins Menu
            }, 0, 0, 0,
            ([ MINI_ED_WRAP_LEN: 78, MINI_ED_FORCE_WRAP: 1]));
        return -1;
    }
    else
    {
        switch (ret = ERROR_DB->add_history(
                errnum,
                this_player(),
                EDB_EHT_COMMENT,
                str))
        {
        case NO_ERROR:
            browse_write_line("Diesen Fehler gibt es nicht (mehr).\n");
            return 0;
        case NOT_RESPONSIBLE:
            browse_write_line("Du bist dafuer nicht zustaendig.\n");
            return 0;
        case NOT_VALID: // sollte nicht auftauchen.
            browse_write_line("Unbekannter-History-Typ.\n");
            return 0;
        case ERROR_OK:
            return 1;
        default:
            browse_write_line("unbekannter Fehler "+ret+"\n");
            return 0;
        }
    }
}

private int precheck_add_feedback(int errnum, int q)
{
    int ret,date;
    string origin;
    mixed * eheader = ERROR_DB->query_error_header(errnum);
    if (!pointerp(eheader))
    {
        browse_write_line("Fehler nicht (mehr) vorhanden!\n");
        return 0;
    }
    switch (eheader[EDB_H_TYPE])
    {
          case EDB_FEHLER:
          case EDB_IDEE:
          case EDB_LOB:
          case EDB_TYPO:
          case EDB_DETAIL:
             date = eheader[EDB_H_OPENED];
             origin = eheader[EDB_H_PLAYER];
             break;
          case EDB_RUNTIME:
          case EDB_COMPILE:
             browse_write_line(
                    "Mit Runtime und Compile Errors geht das nicht.\n");
             return 0;
    }
    if (guestp (origin))
    {
        browse_write_line("Mit Gaesten geht sowas nicht.\n");
        return 0;
    }
    if (!player_exists(origin))
    {
        browse_write_line("Es gibt keinen Spieler dieses Namens (mehr)\n");
        return 0;
    }
    if (q && GOETTER_REGISTER->is_wiz(origin))
    {
        browse_write_line("Der Urheber ist ein Gott, trag ihn doch einfach "
                "als Debugger ein.\n");
        return 0;
    }
    return 1;
}

private int cmd_add_feedback(int errnum, int q, string str, mixed * menues)
{
    int ret,date;
    string origin,errtext;
    mixed * eheader = ERROR_DB->query_error_header(errnum);
    mapping edata = ERROR_DB->query_error_data(errnum);
    if (!pointerp(eheader) || !mappingp(edata))
    {
        browse_write_line("Fehler nicht (mehr) vorhanden!\n");
        return 0;
    }
    switch (eheader[EDB_H_TYPE])
    {
          case EDB_FEHLER:
          case EDB_IDEE:
          case EDB_LOB:
          case EDB_TYPO:
          case EDB_DETAIL:
             date = eheader[EDB_H_OPENED];
             origin = eheader[EDB_H_PLAYER];
             errtext = edata[EDB_E_ERROR];
             break;
          case EDB_RUNTIME:
          case EDB_COMPILE:
             browse_write_line(
                    "Mit Runtime und Compile Errors geht das nicht.\n");
             return 0;
    }
    if (guestp (origin))
    {
        browse_write_line("Mit Gaesten geht sowas nicht.\n");
        return 0;
    }
    if (!player_exists(origin))
    {
        browse_write_line("Es gibt keinen Spieler dieses Namens (mehr)\n");
        return 0;
    }
    if (q && GOETTER_REGISTER->is_wiz(origin))
    {
        browse_write_line("Der Urheber ist ein Gott, trag ihn doch einfach "
                "als Debugger ein.\n\n");
        return 0;
    }
    // Objekt    : /obj/fackel#1398257 ("fackel")
    // in Fehler zu "fackel"
    // verwandeln:
    if (errtext)
    {
        string *lines = explode(errtext,"\n");
        for(int i=0; i<sizeof(lines); i++)
        {
            if(lines[i][0..12] == "Objekt    : /")
            {
                int a,z;
                a = strstr (lines[i],"(\"");
                z = strstr (lines[i],"\")");
                if (a>0 && z>0)
                lines[i] = "Fehler zu: "+capitalize(lines[i][a+2..z-1]);
            }
            else if(lines[i][0..11] == "V-Item    : ")
            {
                int a = strstr(lines[i],". ");
                if(a>0)
                 lines[i] = "Zum Detail: "+lines[i][12..a+1]
                            +capitalize(lines[i][a+2..<1]);
                else
                 lines[i] = "Zum Detail: "+capitalize(lines[i][12..<1]);
            }
            else
                break;
       }
       errtext = implode(lines,"\n");
    }


    if (!str || str == "")
    {
        this_player()->mini_ed(
            function void(string *text):
            int err_num = errnum
            {
            if(text)
            {
                switch (ret = ERROR_DB->add_history(
                        err_num,
                        this_player(),
                        q?EDB_EHT_QUESTION:EDB_EHT_FEEDBACK,
                        implode(text,"\n")))
                {
                case NO_ERROR:
                    browse_write_line("Diesen Fehler gibt es nicht (mehr).\n");
                    break;
                case NOT_RESPONSIBLE:
                    browse_write_line("Du bist dafuer nicht zustaendig.\n");
                    break;
                case NOT_VALID: // sollte nicht auftauchen.
                    browse_write_line("Unbekannter-History-Typ.\n");
                    break;
                case ERROR_OK:
                   ERROR_DB->add_feedback(origin,
                       (["date_err":date,
                         "date_fb":time(),
                         "text":errtext,
                         "fb":implode(text,"\n"),
                         "nr":err_num,
                         "typ":q ? "r" : "f",
                         "by":this_player()->query_real_name(),
                         "objekt":"" // TODO EDB_F_OBJECT_CLEARTEXT
                       ]));
                if (q)
                    browse_write_line ("Rueckfrage an Spieler eingetragen.\n"
                           "Wird der Fehler geloescht, so wird auch die "
                           "Rueckfrage geloescht.\n");
                else browse_write_line ("Feedback an Spieler eingetragen.\n"
                            "Hinweis: Ein Feedback wird nicht geloescht, "
                            "wenn der Fehler geloescht wird.\n"
                            "         Der Fehler kann also ruhig geloescht "
                            "werden, wenn er bearbeitet wurde.\n");
                    break;
                default:
                    browse_write_line("unbekannter Fehler "+ret+"\n");
                    break;
                }
            }
            menues[<1][B_FLAGS] |= BF_DIRTY;
            dynamic_browse(menues); // Wiedereinstieg ins Menu
            }, 0, 0, 0,
            ([ MINI_ED_WRAP_LEN: 78, MINI_ED_FORCE_WRAP: 1]));
        return -1;
    }
    else
    {
        switch (ret = ERROR_DB->add_history(
                errnum,
                this_player(),
                q?EDB_EHT_QUESTION:EDB_EHT_FEEDBACK,
                str))
        {
        case NO_ERROR:
            browse_write_line("Diesen Fehler gibt es nicht (mehr).\n");
            return 0;
        case NOT_RESPONSIBLE:
            browse_write_line("Du bist dafuer nicht zustaendig.\n");
            return 0;
        case NOT_VALID: // sollte nicht auftauchen.
            browse_write_line("Unbekannter-History-Typ.\n");
            return 0;
        case ERROR_OK:
                ERROR_DB->add_feedback(origin,
                       (["date_err":date,
                         "date_fb":time(),
                         "text":errtext,
                         "fb":str,
                         "nr":errnum,
                         "typ":q ? "r" : "f",
                         "by":this_player()->query_real_name(),
                         "objekt":"" // TODO EDB_F_OBJECT_CLEARTEXT
                       ]));
                if (q)
                    browse_write_line ("Rueckfrage an Spieler eingetragen.\n"
                           "Wird der Fehler geloescht, so wird auch die "
                           "Rueckfrage geloescht.\n");
                else browse_write_line ("Feedback an Spieler eingetragen.\n"
                            "Hinweis: Ein Feedback wird nicht geloescht, "
                            "wenn der Fehler geloescht wird.\n"
                            "         Der Fehler kann also ruhig geloescht "
                            "werden, wenn er bearbeitet wurde.\n");
            return 1;
        default:
            browse_write_line("unbekannter Fehler "+ret+"\n");
            return 0;
        }
    }
}

private int cmd_add_debugger(int * errnums, string str)
{
    string * strs, name;
    mixed *debugger,*pdebugger;
    int size;
    object ob;
    mixed * tmp2;
    mapping zaehler = ([ ]);

    zaehler[ZFE_Z_GESAMT] = sizeof(errnums);
    errnums = ERROR_DB->precheck_responsible(errnums,0);
    if (!(zaehler[ZFE_Z_ZUST] = sizeof(errnums)))
    {
        if (zaehler[ZFE_Z_GESAMT] <= 1)
        {
            browse_write_line("Nicht zustaendig fuer diesen Fehler.");
        }
        else
        {
            browse_write_line("Nicht zustaendig fuer diese "
                    +zaehler[ZFE_Z_GESAMT]+" Fehler.");
        }
        return B_DONE;
    }

    strs = regexplode(str,"[ ,;]")-({""," ",",",";"});
    debugger = ({ });
    pdebugger = ({ });
    name = this_player()->query_real_name() + ":";
    foreach(string deb:strs)
    {
        string vdeb;
        if (deb == EDB_BACKUP_GROUP)
        {
            browse_write_line(
                    "Die Backupgruppe kann nicht hinzugefuegt werden.");
            browse_write_line("Dafuer gibt es das Loeschen (l).");
            return B_DONE;
        } 
        else if ( deb == name[..<2])
            pdebugger += ({ ({ deb, 0 }) });
        else if ( !strstr(lower_case(deb), name))
            pdebugger += ({ ({ name+deb[sizeof(name)..<1], 0 }) });
        else if(vdeb = ERROR_DB->valid_debugger( deb ) )
            debugger += ({ ({vdeb, 0}) });
        else
        {
            // ok, war kein debugger direkt
            //  schauen, ob ein Objekt gemeint ist
            if ( ob = search_object( deb ) )
                debugger += map( MASTER_OB->query_debugger(
                    deb = object_name( ob )), (: ({$1,$2}) :), deb);

            // Vielleicht ist new Datei angegeben?
            else if ( sizeof( tmp2 = expand_wildcards( deb ))  &&
                  !catch( size = file_size( tmp2[0]))  &&
                  (size > 0 || size == FSIZE_DIR))
                debugger += map( MASTER_OB->query_debugger(deb = tmp2[0]),
                    (: ({$1,$2}) :), deb);
            else
            {
                browse_write_line(
                    "a {<gott>|<domain>|<bereich>|Root|Objekt|Datei}\n");
                return B_DONE;
            }
        }
    }
    if (sizeof(pdebugger))
    {
        mapping privgroups = params["zfe-privgroups"] || ([]);
        debugger = filter(debugger, (: $1[0][0] != $2 :), name[..<2]);
        //debugger = (debugger - ({ name[..<2] }) ) + ({ name[..<2] }) ;
        int changeflag = 0;
        int debflag;
        pdebugger = map(pdebugger, (: $1[0] :));
        foreach (int errnum : errnums)
        {
            string * pg = privgroups[errnum] || ({});
            if (!sizeof(pg))
            {
                pdebugger = pdebugger;// -({ name[..<2] }) + ({ name[..<2] });
            }
            if (sizeof(pg & pdebugger) == sizeof(pdebugger))
            {
                continue; // nichts zu tun, da pdebugger schon enthalten
            }
            if (!ERROR_DB->is_active_debugger(errnum,name[..<2]))
            {
                debflag = 1;
            }
            pg = pg - pdebugger + pdebugger;
            privgroups[errnum] = pg;
            changeflag = 1;
        }
        if (changeflag)
        {
            set_param("zfe-privgroups", privgroups);
        }
        if (debflag)
        {
            debugger += ({ ({ name[..<2], 0 }) });
        }
    }
    if (sizeof(debugger))
    {
        strs = map(debugger, (: $1[0] :));
        errnums = ERROR_DB->precheck_add_debugger(errnums,strs);
        if (!(zaehler[ZFE_Z_TODO] = sizeof(errnums)))
        {
            browse_write_line("Die ausgewaehlten Fehler haben schon die "
                    "angegebenen Debugger.");
            return B_REBUILT;
        }
        ERROR_DB->exec_add_debugger(errnums,strs);
        if (zaehler[ZFE_Z_TODO] == zaehler[ZFE_Z_GESAMT])
        {
            browse_write_line("Zustaendigkeiten fuer alle "
                    +zaehler[ZFE_Z_GESAMT]+" Fehler geaendert.");
        }
        else
        {
            browse_write_line("Zustaendigkeiten fuer "+zaehler[ZFE_Z_TODO]
                              +" von "+zaehler[ZFE_Z_GESAMT]+" geaendert.");
        }
        return B_REBUILT;
    }
    return B_REBUILT;
}

private int cmd_replace_file(int * errnums, string obfile)
{
    object ob;
    mixed tmp2;
    int size;
    string str,name, *debugger=({});

    mapping zaehler = ([ ]);

    zaehler[ZFE_Z_GESAMT] = sizeof(errnums);
    errnums = ERROR_DB->precheck_responsible(errnums,0);
    if (!(zaehler[ZFE_Z_ZUST] = sizeof(errnums)))
    {
        if (zaehler[ZFE_Z_GESAMT] <= 1)
        {
            browse_write_line("Nicht zustaendig fuer diesen Fehler.");
        }
        else
        {
            browse_write_line("Nicht zustaendig fuer diese "
                    +zaehler[ZFE_Z_GESAMT]+" Fehler.");
        }
        return B_DONE;
    }

    if (ob=search_object(obfile)) {
        str=object_name(ob);
        debugger+=map(MASTER_OB->query_debugger(
            name=object_name(ob)), (: ({$1,$2}) :), name);
    }
    // Vielleicht ist new Datei angegeben?
    else if (sizeof(tmp2=expand_wildcards(obfile))  &&
                  !catch(size=file_size(tmp2[0]))  &&
                  (size>0 || size==FSIZE_DIR)) {
        str=tmp2[0];
        debugger+=map(MASTER_OB->query_debugger(name = tmp2[0]),
                      (: ({$1,$2}) :), name);
    }
    else
    {
        browse_write_line("A {Objekt|Datei}\n");
        return B_DONE;
    }
    cmd_add_debugger(errnums, implode(map(debugger,(:$1[0]:)),","));
    ERROR_DB->exec_reassign_file(errnums, name);
    return B_REBUILT;
}

private int cmd_delete_error(int * errnums)
{
    mapping zaehler = ([ ]);
    zaehler[ZFE_Z_GESAMT] = sizeof(errnums);
    errnums = ERROR_DB->precheck_responsible(errnums,1);
    if (!(zaehler[ZFE_Z_ZUST] = sizeof(errnums)))
    {
        if (zaehler[ZFE_Z_GESAMT] <= 1)
        {
            browse_write_line("Nicht zustaendig fuer diesen Fehler.");
        }
        else
        {
            browse_write_line("Nicht zustaendig fuer diese "
                    +zaehler[ZFE_Z_GESAMT]+" Fehler.");
        }
        return B_DONE;
    }
    errnums = ERROR_DB->exec_delete_error(errnums);
    zaehler[ZFE_Z_TODO] = sizeof(errnums);
    if (zaehler[ZFE_Z_TODO] == zaehler[ZFE_Z_GESAMT])
    {
        browse_write_line("Loeschvorgang fuer alle "+zaehler[ZFE_Z_GESAMT]
                +" Fehler erfolgreich.");
    }
    else
    {
        browse_write_line("Loeschvorgang fuer "+zaehler[ZFE_Z_TODO]
                          +" von "+zaehler[ZFE_Z_GESAMT]+" erfolgreich.");
    }
    return B_REBUILT;
}

private int cmd_hide_debugger(int * errnums, string zust)
{
    string zreg, nzreg,pzreg, pnzreg;
    string rn = this_player()->query_real_name();
    int changeflag = 0, exitflag = 0;
    mapping zaehler = ([ ]);
    if(stringp(zust) && sizeof(zust))
    {
        string *z,*nz,*pz,*pnz;

        z=regexplode(zust,"[ ,;]")-({""," ",",",";"});

        nz = map(z, (: !strstr($1,"!") && $1[1..<1] :)) - ({0});
        z = filter(z, #'strstr, "!");
        pz = filter(z,   (: strstr($1,$2)==0 :), rn);
        pnz = filter(nz, (: strstr($1,$2)==0 :), rn);
        z -= pz;
        nz -= pnz;
        
        zreg = WILDCARDARR2REGEXP(z);
        nzreg = WILDCARDARR2REGEXP(nz);
        pzreg = WILDCARDARR2REGEXP(pz);
        pnzreg = WILDCARDARR2REGEXP(pnz);
    }
    else
    {
        browse_write_line("Kein Pattern fuer 'v'");
        return B_DONE;
    }

    zaehler[ZFE_Z_GESAMT] = sizeof(errnums);
    errnums = ERROR_DB->precheck_responsible(errnums,0);
    if (!(zaehler[ZFE_Z_ZUST] = sizeof(errnums)))
    {
        if (zaehler[ZFE_Z_GESAMT] <= 1)
        {
            browse_write_line("Nicht zustaendig fuer diesen Fehler.");
        }
        else
        {
            browse_write_line("Nicht zustaendig fuer diese "
                    +zaehler[ZFE_Z_GESAMT]+" Fehler.");
        }
        return B_DONE;
    }
    if (pzreg != "^()$")
    {
        mapping privgroups = params["zfe-privgroups"] || ([]);
        
        foreach (int errnum : errnums)
        {
            string* pg = privgroups[errnum]; // -({rn})+({rn});
            string * debs = regexp(pg||({}),pzreg);
            debs -= regexp(debs,pnzreg);
            if (pg==0 && pzreg=="^("+rn+")$")
            {
                pg = ({});
            }
            else if (sizeof(debs) == 0) 
            {
                exitflag++;
                continue;
            }
            pg -= debs;
            if (sizeof(pg)==0) // || sizeof(debs)==sizeof(privgroups[errnum]))
            {
                m_delete(privgroups, errnum);
                ERROR_DB->exec_hide_debugger(({errnum}),
                    WILDCARDARR2REGEXP(({rn})),"^()$");
            }
            else
            {
                privgroups[errnum] = pg; //-({rn});
            }
            changeflag++;
        }
        if (changeflag)
        {
            set_param("zfe-privgroups", privgroups);
        }
    }
    errnums = ERROR_DB->exec_hide_debugger(errnums,zreg,nzreg);
    zaehler[ZFE_Z_TODO] = sizeof(errnums); //+changeflag;
    if (zaehler[ZFE_Z_TODO] >= zaehler[ZFE_Z_GESAMT])
    {
        browse_write_line("Zustaendigkeiten fuer alle "+zaehler[ZFE_Z_GESAMT]
                +" Fehler geaendert.");
    }
    else
    {
        browse_write_line("Zustaendigkeiten fuer "+zaehler[ZFE_Z_TODO]
                          +" von "+zaehler[ZFE_Z_GESAMT]+" geaendert.");
    }
    return B_REBUILT;
}

private void search_f_object(string was, mapping opt)
{
    mixed ob;
    string file;

    if (ob = search_object(was,1))
    {
        if (mappingp(ob) && (file = funcall((ob)["environment"])))
            file = explode(to_string(file),"#")[0];
        else
        {
            if (mappingp(ob))
                ob = environment(this_player());
            file = explode(object_name(ob),"#")[0];
        }
    }
    else 
    {
        if (was[0] == '/')
            file = was;
        else
            file = (strlen(
                    file=(string)this_player()->query_current_path()) > 1 ?
                    (file + "/") : file) + was;
        file=domain2map(file)||file;
    }
    if(file[<2..] == ".c")
    {
        opt["o"] = file;
        opt["f"] = ({file[0..<3]});
    }
    else
    {
        opt["o"] = file + ".c";
        opt["f"] = ({file});
    }
}

// ---------------------------------------------------------------------------
public int start_menu_with_error_list(int* errnums)
{
    mapping options=([]);
    if (!pointerp(errnums) || !sizeof(errnums))
        return 0;
    options[EDB_OPT_ERRNUMS] = errnums;
    dynamic_browse( ([
            B_TYPE: "zfe_top_groups",
            B_FLAGS : BF_DIRTY, // das reload uebernimmt Hierachy&Co
            ZFE_OPTIONS : options ]) );
    return 1;
}
// ---------------------------------------------------------------------------

// Die add_action
int limited_z_fehler(string str)
{
    int i,*timestamps,flag_neu;
    mixed pro;
    mixed *new;
    mapping opt, add_groups, options;
    int * errnums; // Angegebene Fehlernummern.
    string * bereiche,*tmp_args; // angegebene Bereiche

    SECURE;
    HELP("zfehler");

    options = ([ ]);
    
    if (str != 0 && str != "" && space(str) != "-g")
    {
        flag_neu = 1;
    }

    opt = getopt(str,(["o":"%s", "s":0, "f":"%s", "v":"%s","w":"%s",
                       "e":"%s", "A":"\"%s\"", "d":0, "D":0, "z":0, "t":0, 
                       "m":0,
                       "g":0, "G":0, "a":"%s", "b":"%d", "h":"%d", "z":"%s",
                       "i":0, "l":0, "r":0, "c":0, "n":0, "S":0, "E":"%s",
                       "x":"%s", "W": 0,  ]),
                 GO_ERRS);
    if (!opt)
        opt = ([]);

    if ((opt["t"] + opt["m"] + opt["i"] + opt["l"] + opt["r"] + opt["c"]) > 1)
        FAIL("Die Optionen -t, -i, -l, -m, -r und -c "
                "koennen leider nicht zusammen benutzt werden.");

    if (opt["S"])
    {
      set_param("zfe-s",!params["zfe-s"]);
      if(params["zfe-s"])
          browse_write_line("Option -s aktiviert.\n");
      else
          browse_write_line("Option -s "+(opt["s"]?"zukuenftig ":"")
                +"deaktiviert.\n");
      if(!sizeof(opt-(["S"])))
          return 1;
    }

    if (opt["G"])
    {
      set_param("zfe-g",!params["zfe-g"]);
      if(params["zfe-g"])
          browse_write_line("Option -g aktiviert.\n");
      else
          browse_write_line("Option -g "+(opt["g"]?"zukuenftig ":"")
                    +"deaktiviert.\n");
      if(!sizeof(opt-(["S","G"])))
          return 1;
    }
    if (sizeof(opt["e"]))
    {
        options[EDB_OPT_EXLUSIVE_GROUPS] = opt["e"];
        options[EDB_OPT_NO_PRIVATES] = 1;
    }
    else
    {    
        options[EDB_OPT_EXLUSIVE_GROUPS] = ({ });
    }
    if (opt["args"])
    {
        tmp_args = ({ });
        for (i = sizeof(opt["args"]) ; i--; )
        {
            tmp_args += regexplode(opt["args"][i],"[ ,]");
        }
        tmp_args -= ({ " ", "," });
        errnums = ({ });
        bereiche = ({ });
        foreach(string argstr : tmp_args)
        {
            if(!str2int(argstr, &i))
            {
                errnums += ({ i });
            }
            else
            {
                bereiche += ({ argstr });
            }
        }
        if (sizeof(errnums))
        {
            options[EDB_OPT_ERRNUMS] = errnums;
        }
        if (sizeof(bereiche))
        {
            options[EDB_OPT_EXLUSIVE_GROUPS] += bereiche;
        }
    }
    if (!sizeof(options[EDB_OPT_EXLUSIVE_GROUPS]))
    {
        m_delete(options,EDB_OPT_EXLUSIVE_GROUPS);
    }

    // TODO opt["o"] objektstring...(Entfaellt??)

    if(opt["g"])
        opt["g"] = !params["zfe-g"];
    else
        opt["g"] = params["zfe-g"];
    if (!flag_neu && pointerp(zfe_last_errnum) && opt["g"])
    {
        // Letzten Fehler anspringen
        zfe_last_errnum[<1][B_FLAGS] |= BF_DIRTY;
        dynamic_browse(zfe_last_errnum);
        return 1;
    }

    if (sizeof(opt["z"]))
    {
        opt["z"] = opt["z"][0];
        if (sizeof(opt["z"]) >= 2)
        {
            if (opt["z"][0..0]=="d")
            {
                int t;
                if (!str2int(opt["z"][1..], &t) && t > 0)
                {
                    options[EDB_OPT_NEWER_SINCE] = time() - t*60*60*24;
                }
                else
                {
                    FAIL("Falsches Format Option z "
                        "(-zd<tage>\n");
                }
            }
            else if (opt["z"][0..0]=="D")
            {
                int t;
                if (!str2int(opt["z"][1..], &t) && t > 0)
                {
                    options[EDB_OPT_CREATED_SINCE] = time() - t*60*60*24;
                }
                else
                {
                    FAIL("Falsches Format Option D "
                        "(-zD<tage>\n");
                }
            }
            else
            {
                timestamps = extract_timestamps(opt["z"][1..]);
                if (timestamps==0)
                    FAIL("Falsches Format Option z "
                        "(-ze<von>-<bis> oder -za<von>-<bis>)\n");
                switch (opt["z"][0..0])
                {
                case "a":
                    if (timestamps[0])
                        options[EDB_OPT_NEWER_SINCE] = timestamps[0];
                    if (timestamps[1])
                        options[EDB_OPT_NEWER_BEFORE] = timestamps[1];
                    break;
                case "e":
                    if (timestamps[0])
                        options[EDB_OPT_CREATED_SINCE] = timestamps[0];
                    if (timestamps[1])
                        options[EDB_OPT_CREATED_BEFORE] = timestamps[1];
                    break;
                default:
                    FAIL("Falsches Format Option z "
                        "(-ze<von>-<bis> oder -za<von>-<bis>)\n");
                }
            }
        }
        else
        {
            FAIL("Falsches Format Option z "
                    "(-ze<von>-<bis> oder -za<von>-<bis>) oder -zd<tage>\n");
        }
    }

    if (opt["w"])
    {
        options[EDB_OPT_ZUSTAENDIGER] = opt["w"][0];
        options[EDB_OPT_NO_PRIVATES] = 1;
    }
    if (sizeof(opt["E"]))
    {
        options[EDB_OPT_GROUP_EXCLUDE] =
            regexplode(opt["E"][0],"[,;]")-({",",";",""});
    }
    else
    {
        options[EDB_OPT_GROUP_EXCLUDE] = ({});
    }
    if (sizeof(opt["a"]))
        opt["a"] = opt["a"][0];
    if (opt["a"])
    {
        if (!regexp(({"dummy"}),opt["a"]))
            FAIL("Fehler in der Regexp. '"+opt["a"]+"' fuer Option a\n");
        else
        {
            options[EDB_OPT_GROUP_PATTERN] = opt["a"];
            options[EDB_OPT_GROUP_ALL] = 1;
        }
    }
    if (sizeof(opt["x"]))
    {
        if (strstr(opt["x"][0],",")!=-1)
        {
            opt["x"] = regexplode(opt["x"][0],",")-({"",","});;
        }
        opt["x"] = WILDCARDARR2REGEXP(opt["x"]);
    }
    if (opt["x"])
    {
        if (!regexp(({"dummy"}),opt["x"]))
            FAIL("Fehler in der Regexp. '"+opt["x"]+"' fuer Option x\n");
        else
            options[EDB_OPT_GROUP_EXCLUDE_PATTERN] = opt["x"];
    }
    if (opt["d"])
        options[EDB_OPT_GROUP_ALL] = 1;
    if (opt["b"])
    {
        switch (opt["b"][0])
        {
        case 0:
            break; // Unsortiert...
        case 1:
            options[EDB_OPT_SORT_OPEN_ASC] = 1;
            break;
        case 2:
            options[EDB_OPT_SORT_OPEN_DESC] = 1;
            break;
        case 3:
            options[EDB_OPT_SORT_CHANGE_ASC] = 1;
            break;
        case 4:
            options[EDB_OPT_SORT_CHANGE_DESC] = 1;
            break;
        default:
            FAIL("Falsche Zahl "+opt["b"][0]+" (1-4) fuer Option b\n");
        }
    }
    else
    {
        options[EDB_OPT_SORT_OPEN_ASC] = 1; // Default
    }
    if (opt["h"])
    {
        switch (opt["h"][0])
        {
        case 1:
            options[EDB_OPT_HIERACHY_1] = 1;
            break;
        case 2:
            options[EDB_OPT_HIERACHY_2] = 1;
            break;
        case 3:
            options[EDB_OPT_HIERACHY_3] = 1;
            break;
        case 9:
            options[EDB_OPT_HIERACHY_9] = 1;
            break;
        default:
            FAIL("Falsche Zahl "+opt["h"][0]+" (1-3,9) fuer Option h\n");
        }
    }
    else
    {
        options[EDB_OPT_HIERACHY_2] = 1; // Default.
    }


    if (opt["t"])
        options[EDB_OPT_ERROR_TYPE] = EDB_TYPO;
    else if (opt["m"])
        options[EDB_OPT_ERROR_TYPE] = EDB_FEHLER;
    else if (opt["i"])
        options[EDB_OPT_ERROR_TYPE] = EDB_IDEE;
    else if (opt["D"])
        options[EDB_OPT_ERROR_TYPE] = EDB_DETAIL;
    else if (opt["l"])
        options[EDB_OPT_ERROR_TYPE] = EDB_LOB;
    else if (opt["r"])
        options[EDB_OPT_ERROR_TYPE] = EDB_RUNTIME;
    else if (opt["c"])
        options[EDB_OPT_ERROR_TYPE] = EDB_COMPILE;

    if (params["zfe-s"] || opt["f"] || opt["v"] || opt["s"]
            || options[EDB_OPT_ERROR_TYPE])
        options[EDB_OPT_NO_EMPTY_ERR] = 1;
    if (opt["o"])
        search_f_object(opt["o"][0],opt);
    if (opt["f"])
        opt["f"] = opt["f"][0];
    if (opt["v"])
        opt["v"] = lower_case(opt["v"][0]);
    if (opt["f"])
    {
        if (!regexp(({"dummy"}),opt["f"]))
          FAIL("Fehler in der Regexp. '"+opt["f"]+"' fuer den Dateinamen\n");
        else
          options[EDB_OPT_FILE_PATTERN] = opt["f"];
    }
    if (opt["v"])
    {
        if (!regexp(({"dummy"}),opt["v"]))
          FAIL("Fehler in der Regexp. '"+opt["v"]+"' fuer den Verursacher\n");
        else
          options[EDB_OPT_VERURSACHER_PATTERN] = opt["v"];
    }
//pro = ERROR_DB->query_wiz_projects(this_player()->query_real_name(),0,0,0,0);
//pro = mkmapping(pro)+mkmapping(map(pro,(:explode($1,":")[0]:)));
//pro += params["zfe-groups"];
    DEBUG(sprintf("opt-1"));
    pro = m_indices(ERROR_DB->query_group_list(
                        this_player()->query_real_name(),([])));
    pro = mkmapping(pro)+mkmapping(map(pro,(:explode($1,":")[0]:)));
    pro += params["zfe-groups"];

    new = this_player()->query_new_wiz_errors();
    new[EDB_NEW_WIZ_ERRORS] =
      filter(new[EDB_NEW_WIZ_ERRORS],#'_is_existing_error,pro);
    this_player()->set_new_wiz_errors(new);
    _update_new_wiz_errors();
    if (opt["n"])
    {
        options[EDB_OPT_ONLY_NEW_ERR] = 1;
    }
    options[EDB_OPT_NEW_ERRNUMS] = new[EDB_NEW_WIZ_ERRORS];
    if (opt["W"])
    {
        options[EDB_OPT_WIEDERVORLAGE] = _query_wiedervorlage();
    }
    if (opt["A"])
    {
        options[EDB_OPT_ARCHIVE_PATTERN] = opt["A"][0];
        dynamic_browse( ([
                B_TYPE : "zfe_archive_list",
                ZFE_OPTIONS : options ]) );
        return 1;
    }
    // start_browser...
    dynamic_browse( ([
            B_TYPE: "zfe_top_groups",
            B_FLAGS : BF_DIRTY, // das reload uebernimmt Hierachy&Co
            ZFE_OPTIONS : options ]) );
    return 1;
}

int z_fehler(string str)
{
    return limited(#'limited_z_fehler, ({__MAX_EVAL_COST__ * 4}), str);
    //return limited_z_fehler(str);
}

// Formatfunktionen:
private string format_ultra_short_time(int time)
{
    string tmp;

    tmp = shorttimestr(time);
    return tmp[0..4] + " " + tmp[9..13];
}

// ---------------------------------------------------------------------------
// Menubloecke:
// - zfe_top_groups   : auf Toplevel konsolidierte Gruppenansicht
// - zfe_groups       : Gruppenansicht
// - zfe_errlist      : Fehlerliste
// - zfe_single       : Fehlereinzelanzeige

static mixed zfe_top_groups_init(mapping old);
static mixed zfe_groups_init(mapping old);
static mixed zfe_errlist_init(mapping old);
static mixed zfe_single_init(mapping old);
static mixed zfe_wiedervorlage_init(mapping old);
static int zfe_archive_list_total(mapping menue);
static mixed zfe_archive_list_init(mapping old);
static mixed zfe_archive_single_init(mapping old);

// Spezialfunktion fuer Befehl "n" naechster neuer Fehler
static int zfe_groups_next_new(mixed menues, int start_from)
{
    mixed * data = menues[<1][B_DATA];
    int ix;
    for (ix= start_from; ix < sizeof(data); ix++)
    {
        if (data[ix][2] > 0 ) 
            return ix;
    }
    return -1;
}

static int zfe_errlist_next_new_error(mixed menues,int start_from)
{
    mixed * data = menues[<1][B_DATA];
    int ix;
    int * newerrs = _query_new_wiz_errors();
    for (ix=start_from;ix < sizeof(data);ix++)
    {
        if (member(newerrs,data[ix][EDB_ERRLIST_ERRNUM])>-1) 
            return ix;
    }
    return -1;
}

static mixed zfe_search_next_new_error(mixed oldmenues)
{
    int flag_erster = 1;
    int start_from = -1;
    int neu_index = -1;
    mixed menues = deep_copy(oldmenues);
    mixed menue;
    _update_new_wiz_errors();
    while ( 1 )
    {
        switch (menues[<1][B_TYPE])
        {
        case "zfe_top_groups":
            if (start_from == -1)
            {
                start_from = menues[<1][B_CURRENT_LINE];
            }
            neu_index = zfe_groups_next_new(menues, start_from);
            if (neu_index == -1)
            {
                if (flag_erster)
                {
                    menue = zfe_groups_init(menues[<1]);
                    if (mappingp(menue)) 
                    {
                        if (sizeof(menues)>2) 
                        {
                            menues = menues[..<2] + ({ menue });
                        } 
                        else
                        {
                            menues = ({ menue });
                        }
                        flag_erster = 0;
                        start_from = 0;
                        continue;
                    }
                }
            }
            else
            {
                mixed options = deep_copy(menues[<1][ZFE_OPTIONS]);
                DEBUG(sprintf("<n> menues %Q",menues));
                string prefix = menues[<1][B_DATA][neu_index][0];
                options[EDB_OPT_GROUP_PREFIX] = prefix;
                if (options[EDB_OPT_HIERACHY_3])
                {
                    menue = zfe_groups_init( ([ B_TYPE : "zfe_groups",
                                ZFE_INDEX : neu_index+1,
                                ZFE_OPTIONS : options ]) );
                    if (mappingp(menue))
                    {
                        menues += ({ menue });
                        flag_erster = 0;
                        start_from = 0;
                        continue;
                    }
                    else
                    {
                        browse_write_line("Neuer Fehler nicht gefunden.");
                        return B_QUIT;
                    }
                }
                else if (options[EDB_OPT_HIERACHY_9])
                {
                    if (sizeof(prefix) && prefix[<1] == '*')
                    {
                        menue = zfe_top_groups_init( ([ 
                                B_TYPE : "zfe_top_groups",
                                ZFE_INDEX : neu_index+1,
                                ZFE_OPTIONS : options ]) );
                    }
                    else
                    {
                        menue = zfe_errlist_init( ([ 
                                B_TYPE : "zfe_errlist",
                                ZFE_INDEX : neu_index + 1,
                                ZFE_OPTIONS : options ]) );
                    }
                    if (mappingp(menue))
                    {
                        menues += ({ menue });
                        flag_erster = 0;
                        start_from = 0;
                        continue;
                    }
                    else
                    {
                        browse_write_line("Neuer Fehler nicht gefunden.");
                        return B_QUIT;
                    }
                }
            }
            if (sizeof(menues)>2)
            {
                flag_erster = 1;
                start_from = menues[<1][ZFE_INDEX];
                menues = menues[..<2];
                continue;
            }
            browse_write_line("Kein neuer Fehler gefunden.");
            return B_DONE;
        case "zfe_groups":
            if (start_from == -1)
            {
                start_from = menues[<1][B_CURRENT_LINE];
            }
            neu_index = zfe_groups_next_new(menues, start_from);
            if (neu_index == -1)
            {
                if (flag_erster)
                {
                    menue = zfe_groups_init(menues[<1]);
                    if (mappingp(menue)) 
                    {
                        if (sizeof(menues)>2) 
                        {
                            menues = menues[..<2] + ({ menue });
                        } 
                        else
                        {
                            menues = ({ menue });
                        }
                        flag_erster = 0;
                        start_from = 0;
                        continue;
                    }
                }
            }
            else
            {
                mixed options = deep_copy(menues[<1][ZFE_OPTIONS]);
                options[EDB_OPT_GROUP_ONE] = menues[<1][B_DATA][neu_index][0];
                menue = zfe_errlist_init( ([ B_TYPE : "zfe_errlist",
                        ZFE_INDEX : neu_index+1,
                        ZFE_OPTIONS : options ]) );
                if (mappingp(menue))
                {
                    menues += ({ menue });
                    flag_erster = 0;
                    start_from = 0;
                    continue;
                }
                else
                {
                    browse_write_line("Kein neuen Fehler gefunden.");
                    return B_QUIT;
                }
            }
            if (sizeof(menues)>2)
            {
                flag_erster = 1;
                start_from = menues[<1][ZFE_INDEX];
                menues = menues[..<2];
                continue;
            }
            browse_write_line("Kein neuer Fehler gefunden.");
            return B_DONE;
        case "zfe_errlist":
            if (start_from == -1)
            {
                start_from = menues[<1][B_CURRENT_LINE];
            }
            neu_index = zfe_errlist_next_new_error(menues,start_from);
            if (neu_index == -1)
            {
                if (flag_erster)
                {
                    menue = zfe_errlist_init(menues[<1]);
                    if (mappingp(menue)) 
                    {
                        if (sizeof(menues)>2) 
                        {
                            menues = menues[..<2] + ({ menue });
                        } 
                        else
                        {
                            menues = ({ menue });
                        }
                        flag_erster = 0;
                        start_from = 0;
                        continue;
                    }
                }
            }
            else
            {
                int errnum = menues[<1][B_DATA][neu_index][EDB_ERRLIST_ERRNUM];
                mixed options = deep_copy(menues[<1][ZFE_OPTIONS]);
                menues += ({ ([ B_TYPE : "zfe_single",
                                ZFE_OPTIONS : options,
                                ZFE_INDEX: neu_index + 1,
                                ZFE_ERRNUM: errnum ]) });
                return menues;
            }
            if (sizeof(menues)>2)
            {
                flag_erster = 1;
                start_from = menues[<1][ZFE_INDEX];
                menues = menues[..<2];
                continue;
            }
            browse_write_line("Kein neuer Fehler gefunden.");
            return B_DONE;
        case "zfe_single":
            start_from = menues[<1][ZFE_INDEX];
            menues = menues[..<2];
            continue;
        case "zfe_wiedervorlage":
        case "zfe_archive_list":
        case "zfe_archive_single":
        default:
            browse_write_line("Kein _neuer_ Fehler verfuegbar.");
            return B_DONE;
        }
        
    }
}

// ---------------------------------------------------------------------------
static int zfe_top_groups_total(mapping menue)
{
    return sizeof(menue[B_DATA]);
}

static mixed zfe_top_groups_init(mapping old)
{
    old[B_HELP] = ([ B_TYPE : B_DYNAMICMORE,
                         B_FILE : ZFE_BHELP("_topgroups"),
                         B_PROMPT : "Hilfe zu Gruppenhierachie",
                      ]);
    zfe_last_errnum = 0;
    if (old[B_FLAGS] & BF_DIRTY)
        return old;
    DEBUG("zfe_top_groups_init");
    _update_new_wiz_errors();
    int * newerrs = _query_new_wiz_errors();
    mapping options = deep_copy(old[ZFE_OPTIONS]);
    options[EDB_OPT_NEW_ERRNUMS] = newerrs; // aktuell halten
    options[EDB_OPT_ADD_W_GROUP] = provide_privgroups(7,options);
    options[EDB_OPT_ADD_S_GROUP] = provide_privgroups(8,options);
    mapping zust = ERROR_DB->query_main_groups(
            this_player()->query_real_name(),
            options);
    old[ZFE_OPTIONS] = options;
    mixed * data = map(sort_array(m_indices(zust),#'>),
        (: ({ $1, sizeof($2[$1]),sizeof($2[$1] & $3) }) :),zust,newerrs );
    if (sizeof(data)==0)
    {
        return B_REBUILT;
        browse_write_line("Keine Daten in dieser Ansicht.");
        return B_QUIT;
    }
    if (data[0][0] == "/w/*") // Subgruppen korrigieren
    {
        mapping pzust = options[EDB_OPT_ADD_W_GROUP];
        mapping sammel = ([ ]);
        foreach(string pzus,int * perrnums : pzust)
        {
            sammel += mkmapping(perrnums);
        }
        data[0][1] = sizeof(sammel);
        data[0][2] = sizeof(m_indices(sammel) & newerrs);
    }
    old[B_DATA] = data;
    old[B_START_LINE] = 0;
    old[B_HEADER_LINES] = ({ ZFE_MORE_LINE_HF, ZFE_MORE_LINE_HF,
                             ZFE_MORE_LINE_MI, ZFE_MORE_LINE_MI });
    return old;
}

static mixed zfe_top_groups_reload(mixed menues)
{
    mixed menue = menues[<1];
    mapping options = deep_copy(menue[ZFE_OPTIONS]);
    DEBUG("zfe_top_groups_reload");
    if (options[EDB_OPT_WIEDERVORLAGE])
    {
        menue = zfe_wiedervorlage_init( ([
                  B_TYPE: "zfe_wiedervorlage",
                  ZFE_OPTIONS: options ]));
        if (mappingp(menue))
        {
            return ({ menue });
        }
        else
        {
            browse_write_line("Keine Daten in dieser Anzeige.");
            return B_QUIT;
        }
    }
    if (options[EDB_OPT_ERRNUMS])
    {
        menue = zfe_errlist_init( ([
                  B_TYPE: "zfe_errlist",
                  ZFE_OPTIONS : options ])) ;
        if (mappingp(menue))
        {
            if (sizeof(options[EDB_OPT_ERRNUMS])==1)
            {
                mapping submenue = zfe_single_init(
                          ([ B_TYPE : "zfe_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: 1,
                            ZFE_ERRNUM: options[EDB_OPT_ERRNUMS][0] ]));
                if (!mappingp(submenue)) return ({ menue });
                return ({ menue , submenue });
            }
            return ({ menue });
        }
        else
        {
            browse_write_line("Keine Daten in dieser Anzeige.");
            return B_QUIT;
        }
    }
    if (options[EDB_OPT_HIERACHY_1])
    {
        menue = zfe_errlist_init( ([
                  B_TYPE: "zfe_errlist",
                  ZFE_OPTIONS : options ]));
        if (mappingp(menue))
        {
            return ({ menue });
        }
        else
        {
            browse_write_line("Keine Daten in dieser Anzeige.");
            return B_QUIT;
        }
    }
    if (options[EDB_OPT_HIERACHY_2])
    {
        menue = zfe_groups_init( ([
                  B_TYPE: "zfe_groups",
                  ZFE_OPTIONS : options ]));
        if (mappingp(menue))
        {
            return ({ menue });
        }
        else
        {
            browse_write_line("Keine Daten in dieser Anzeige.");
            return B_QUIT;
        }
    }
    menue[B_FLAGS] &= ~BF_DIRTY;
    menue = zfe_top_groups_init(menue);
    if (!mappingp(menue))
    {
        if (menue == B_REBUILT)
        {
            if (sizeof(menues)>1)
            {
                // RELOAD des uebergeordneten Menus notwendig??
                menues = menues[..<2];
                menues[<1][B_FLAGS] |= BF_DIRTY;
                return menues;
            }
            else
            {
                browse_write_line(
                        "Keine Fehler (mehr) in der Gruppenhierachie.");
                return B_QUIT;
            }
        }
        return menue; // B_QUIT...
    }
    menues[<1] = menue;
    return menues;
}

static mixed zfe_top_groups_search_forward(mapping menue)
{
    if (!mappingp(menue) )
        return 0;
    int start = menue[B_CURRENT_LINE]+1;
    mixed * content = menue[B_DATA];
    int end = sizeof(content);
    int i;
    string search = menue[B_SEARCH_STRING];
    if (start > sizeof(content) || !stringp(search) || !sizeof(search))
        return 0;
    if (start < 0)
        start = 0;
    if (end <= start) 
        return 0;
    for (i=start; i < end ;i++)
    {
         if (strstr( sprintf("%3d: %4d %c %s", i+1, content[i][1],
                        content[i][2]?'+':' ', content[i][0]), search)!=-1)
         {
             menue[B_CURRENT_LINE] = i;
             return menue;
         }
    }
    return 0; // nicht gefunden
}

static string * zfe_top_groups_display(mapping menue)
{
    if (!mappingp(menue) )
        return 0;
    int start = menue[B_CURRENT_LINE];
    int end = start + menue[B_NUM_LINES];
    mixed * content = menue[B_DATA];
    string * result = ({ });
    if (start > sizeof(content))
        return 0;
    if (end >= sizeof(content))
        end = sizeof(content)-1;
    if (start < 0)
        start = 0;
    if (end < start) return 0;
    for(int i = start;i<=end;i++)
        result += ({
                sprintf("%3d: %4d %c %s", i+1, content[i][1],
                        content[i][2]?'+':' ', content[i][0])
                });
    return result;
}

static string zfe_top_groups_prompt(mapping menue)
{
    if (member(menue[ZFE_OPTIONS],EDB_OPT_GROUP_PREFIX)) 
    {
        return "Gruppenhierachie "
            +menue[ZFE_OPTIONS][EDB_OPT_GROUP_PREFIX]
            +" [z,q]";
    }
    return "Gruppenhierachie [z,q]";
}

static mixed zfe_top_groups_action(string str, mapping * menues)
{
    int i;
    mapping menue = menues[<1];
    mapping options = deep_copy(menue[ZFE_OPTIONS]);
    string prefix;
    str = space(str);
    switch (str)
    {
    case "":
    case "d":
    case "u":
    case "<":
        return B_NOTHING;
    case ">":
        menue[B_CURRENT_LINE] = max(0,
                sizeof(menue[B_DATA])-menue[B_NUM_LINES]+1);
        menues[<1] = menue;
        return menues;
    case "n":
        return zfe_search_next_new_error(menues);
    case "z":
        if (sizeof(menues)>1) {
            menues = menues[..<2];
            menues[<1][B_FLAGS] |= BF_DIRTY;
        } else {
            browse_write_line("Es geht nicht weiter zurueck.\n");
            menues[<1][B_FLAGS] |= BF_NO_DISPLAY;
        }
        return menues;
    default:
        if (sscanf(str,"%d",i)==1 && i > 0 && i <= sizeof(menue[B_DATA]))
        {
            prefix = menue[B_DATA][i-1][0];
            options[EDB_OPT_GROUP_PREFIX] = prefix;
            if (options[EDB_OPT_HIERACHY_3])
            {
                return menues + ({ ([ B_TYPE : "zfe_groups",
                            ZFE_INDEX : i,
                            ZFE_OPTIONS : options ]) });
            }
            else if (options[EDB_OPT_HIERACHY_9])
            {
                if (prefix == "/w/*")
                {
                    return menues + ({ ([ B_TYPE : "zfe_groups",
                            ZFE_INDEX : i,
                            ZFE_OPTIONS : options ]) });
                }
                else if (prefix[<1] == '*')
                {
                    return menues + ({ ([ B_TYPE : "zfe_top_groups",
                            ZFE_INDEX : i,
                            ZFE_OPTIONS : options ]) });
                }
                else
                {
                    return menues + ({ ([ B_TYPE : "zfe_errlist",
                            ZFE_INDEX : i,
                            ZFE_OPTIONS : options ]) });
                }
            }
        }
    }
    return B_NOTHING;
}

// ---------------------------------------------------------------------------
//---- zfe_groups ----
static int zfe_groups_total(mapping menue)
{
    return sizeof(menue[B_DATA]);
}

static mixed zfe_groups_init(mapping old)
{
    if (old[B_FLAGS] & BF_DIRTY)
        return old;
    DEBUG("zfe_groups_init-1");
    zfe_last_errnum = 0;
    _update_new_wiz_errors();
    int * newerrs = _query_new_wiz_errors();
    mapping options = deep_copy(old[ZFE_OPTIONS]);
    options[EDB_OPT_NEW_ERRNUMS] = newerrs; // aktuell halten
    options[EDB_OPT_ADD_W_GROUP] = provide_privgroups(7,options);
    options[EDB_OPT_ADD_S_GROUP] = provide_privgroups(8,options);
    DEBUG("zfe_groups_init-2");
    mapping zust = ERROR_DB->query_group_list(
            this_player()->query_real_name(),
            options);
    if (options[EDB_OPT_GROUP_PREFIX] == "/w/*")
    {
        string rn = this_player()->query_real_name();
        // Ergaenzung privater Gruppen:
        zust -= ([ rn ]);
        zust += filter(options[EDB_OPT_ADD_W_GROUP],
                    (: strstr($1,$3)==0 :), rn);
    } else if (member(options,EDB_OPT_HIERACHY_2))
    {
        string rn = this_player()->query_real_name();
        // Ergaenzung privater Gruppen
        zust -= ([ rn ]);
        zust += options[EDB_OPT_ADD_W_GROUP];
    }
    mixed * data = map(sort_array(m_indices(zust),#'>),
        (: ({ $1, sizeof($2[$1]),sizeof($2[$1] & $3) }) :),zust,newerrs );
    if (!sizeof(data))
    {
        return B_REBUILT;
        if (member(old[ZFE_OPTIONS],EDB_OPT_ONLY_NEW_ERR))
        {
            browse_write_line("Es liegen keine neuen Fehler mehr vor.");
        }
        else
        {
            browse_write_line("Es liegen keine Fehler in dieser Auswahl vor.");
        }
        return B_QUIT;
    }
    old[B_HELP] = ([ B_TYPE : B_DYNAMICMORE,
                         B_FILE : ZFE_BHELP("_groups"),
                         B_PROMPT : "Hilfe zur Gruppenuebersicht",
                      ]);
    old[ZFE_OPTIONS] = options;
    old[B_DATA] = data;
    old[B_START_LINE] = 0;
    old[B_HEADER_LINES] = ({ ZFE_MORE_LINE_HF, ZFE_MORE_LINE_HF,
                             ZFE_MORE_LINE_MI, ZFE_MORE_LINE_MI });
    return old;
}

static mixed zfe_groups_reload(mixed menues)
{
    mixed menue = menues[<1];
    menue[B_FLAGS] &= ~BF_DIRTY;
    DEBUG("zfe_groups_reload");
    menue = zfe_groups_init(menue);
    if (mappingp(menue))
    {
        menues[<1] = menue;
        return menues;
    }
    if (menue == B_REBUILT)
    {
        if (sizeof(menues)>1)
        {
            // RELOAD des uebergeordneten Menus notwendig??
            menues = menues[..<2];
            menues[<1][B_FLAGS] |= BF_DIRTY;
            return menues;
        }
        else
        {
            browse_write_line("Keine Fehler (mehr) in der Gruppenuebersicht.");
            return B_QUIT;
        }
    }    
    return menue;
}

static mixed zfe_groups_search_forward(mapping menue)
{
    if (!mappingp(menue) )
        return 0;
    int start = menue[B_CURRENT_LINE]+1;
    mixed * content = menue[B_DATA];
    int end = sizeof(content);
    int i;
    string search = menue[B_SEARCH_STRING];
    if (start > sizeof(content) || !stringp(search) || !sizeof(search))
        return 0;
    if (start < 0)
        start = 0;
    if (end <= start) 
        return 0;
    for (i=start; i < end ;i++)
    {
         if (strstr( sprintf("%3d: %4d %c %s", i+1, content[i][1],
                        content[i][2]?'+':' ', content[i][0]), search)!=-1)
         {
             menue[B_CURRENT_LINE] = i;
             return menue;
         }
    }
    return 0; // nicht gefunden
}

static string * zfe_groups_display(mapping menue)
{
    if (!mappingp(menue) )
        return 0;
    int start = menue[B_CURRENT_LINE];
    int end = start + menue[B_NUM_LINES];
    mixed * content = menue[B_DATA];
    string * result = ({ });
    if (start > sizeof(content))
        return 0;
    if (end >= sizeof(content))
        end = sizeof(content)-1;
    if (start < 0)
        start = 0;
    if (end < start) return 0;
    for(int i = start;i<=end;i++)
        result += ({
                sprintf("%3d: %4d %c %s", i+1, content[i][1],
                        content[i][2]?'+':' ', content[i][0])
                });
    return result;
}

static string zfe_groups_prompt(mapping menue)
{
    if (member(menue[ZFE_OPTIONS],EDB_OPT_GROUP_PREFIX)) 
    {
        return "Gruppenuebersicht "
            +menue[ZFE_OPTIONS][EDB_OPT_GROUP_PREFIX]
            +" [z,q]";
    }
    return "Gruppenuebersicht [z,q]";
}

static mixed zfe_groups_action(string str, mapping * menues)
{
    int i;
    mapping menue = menues[<1];
    mapping options = deep_copy(menue[ZFE_OPTIONS]);
    str = space(str);
    switch (str)
    {
    case "":
    case "d":
    case "u":
    case "<":
        return B_NOTHING;
    case ">":
        menue[B_CURRENT_LINE] = max(0,
                        sizeof(menue[B_DATA])-menue[B_NUM_LINES]+1);
        menues[<1] = menue;
        return menues;
    case "n":
        return zfe_search_next_new_error(menues);
    case "z":
        if (sizeof(menues)>1) {
            menues = menues[..<2];
            menues[<1][B_FLAGS] |= BF_DIRTY;
        } else {
            browse_write_line("Es geht nicht weiter zurueck.\n");
            menues[<1][B_FLAGS] |= BF_NO_DISPLAY;
        }
        return menues;
    default:
        if (sscanf(str,"%d",i)==1 && i > 0 && i <= sizeof(menue[B_DATA]))
        {
            options[EDB_OPT_GROUP_ONE] = menue[B_DATA][i-1][0];
            menues += ({ ([ B_TYPE : "zfe_errlist",
                            ZFE_INDEX : i,
                            ZFE_OPTIONS : options ]) });
            return menues;
        }
    }
    return B_NOTHING;
}

// ---------------------------------------------------------------------------
// --- zfe_wiedervorlage ---- Gruppenanzeige der Wiedervorlage
static int zfe_wiedervorlage_total(mapping menue)
{
    return sizeof(menue[B_DATA]);
}

static mixed zfe_wiedervorlage_init(mapping old)
{
    DEBUG("zfe_wiedervorlage_init");
    zfe_last_errnum = 0;
    mapping wv = copy(_query_wiedervorlage());
    mapping options = deep_copy(old[ZFE_OPTIONS]);
    mapping zust;
    wv[0] = _query_new_wiz_errors();
    options[EDB_OPT_WIEDERVORLAGE] = wv;
    old[B_HELP] = ([ B_TYPE : B_DYNAMICMORE,
                         B_FILE : ZFE_BHELP("_wiedervorlage"),
                         B_PROMPT : "Hilfe zur Wiedervorlagenansicht",
                      ]);
    zust = ERROR_DB->query_wiedervorlage("Wiedervorlage", options);
    if (!sizeof(filter(zust,(:sizeof($2)>0:))))
    {
        browse_write_line("Keine neuen Fehler und keine Wiedervorlage.");
        return B_QUIT;
    }

    mixed * data = map(sort_array(m_indices(zust),#'>),
        (: ({ $1, sizeof($2[$1]) }) :),zust );
    old[ZFE_OPTIONS][EDB_OPT_NEW_ERRNUMS] = _query_new_wiz_errors();
    old[B_DATA] = data;
    old[B_START_LINE] = 0;
    old[B_HEADER_LINES] = ({ ZFE_MORE_LINE_HF, ZFE_MORE_LINE_HF,
                             ZFE_MORE_LINE_MI, ZFE_MORE_LINE_MI });

    return old;
}

static mixed zfe_wiedervorlage_reload(mixed menues)
{
    mixed menue = menues[<1];
    DEBUG("zfe_wiedervorlage_reload");
    menue = zfe_wiedervorlage_init(menue);
    if (mappingp(menue))
    {
        menues[<1] = menue;
        return menues;
    }
    return menue; // B_QUIT o.ae.
}

static string * zfe_wiedervorlage_display(mapping menue)
{
    if (!mappingp(menue) )
        return 0;
    int start = menue[B_CURRENT_LINE];
    int end = start + menue[B_NUM_LINES];
    mixed * content = menue[B_DATA];
    string * result = ({ });
    if (start > sizeof(content))
        return 0;
    if (end >= sizeof(content))
        end = sizeof(content)-1;
    if (start < 0)
        start = 0;
    if (end < start) return 0;
    for(int i = start;i<=end;i++)
        result += ({
                sprintf("%3d: %4d %s", i+1, content[i][1],
                        (content[i][0]==0) ?
                           "Neu":
                           "Wiedervorlage am "
                           +explode(shorttimestr(content[i][0])," ")[0]
                        )
                });
    return result;
    return 0;
}

static string zfe_wiedervorlage_prompt(mapping menue)
{
    return "Wiedervorlage-Uebersicht [z,q]";
}

static mixed zfe_wiedervorlage_action(string str, mapping * menues)
{
    mapping menue = menues[<1];
    mapping options = deep_copy(menue[ZFE_OPTIONS]);
    int i;
    switch (str)
    {
    case "": break;
    case "z":
        if (sizeof(menues)>1) {
            menues = menues[..<2];
            menues[<1][B_FLAGS] |= BF_DIRTY;
        } else {
            browse_write_line("Es geht nicht weiter zurueck.\n");
            menues[<1][B_FLAGS] |= BF_NO_DISPLAY;
        }
        return menues;
    default:
        if (sscanf(str,"%d",i)==1 && i > 0 && i <= sizeof(menue[B_DATA]))
        {
            options[EDB_OPT_GROUP_ONE] = menue[B_DATA][i-1][0];
            menues += ({ zfe_errlist_init (([ B_TYPE : "zfe_errlist",
                            ZFE_INDEX : i,
                            ZFE_OPTIONS : options ])) });
            return menues;
        }
    }
    return B_NOTHING;
}

// ---------------------------------------------------------------------------


//---- errlist ----
static int zfe_errlist_total(mapping menue)
{
    return sizeof(menue[B_DATA]);
}

static mixed zfe_errlist_init(mapping old)
{
    mixed errlist;
    mapping options = deep_copy(old[ZFE_OPTIONS]);
    if (old[B_FLAGS] & BF_DIRTY) return old;
    DEBUG("zfe_errlist_init");
    zfe_last_errnum = 0;
    _update_new_wiz_errors();
    int * newerrs = _query_new_wiz_errors();
    options[EDB_OPT_NEW_ERRNUMS] = newerrs; // aktuell halten
    options[EDB_OPT_ADD_W_GROUP] = provide_privgroups(7,options);
    options[EDB_OPT_ADD_S_GROUP] = provide_privgroups(8,options);

    string who = old[ZFE_OPTIONS][EDB_OPT_GROUP_ONE] || "";
    string rn = this_player()->query_real_name();
    old[B_HELP] = ([ B_TYPE : B_DYNAMICMORE,
                         B_FILE : ZFE_BHELP("_errlist"),
                         B_PROMPT : "Hilfe zur Fehlerliste",
                      ]);
    if (options[EDB_OPT_WIEDERVORLAGE])
    {
        errlist = ERROR_DB->query_error_list(
            "Wiedervorlage",options);
    }
    else if (old[ZFE_OPTIONS][EDB_OPT_ERRNUMS])
    {
        errlist = ERROR_DB->query_error_list(
            "Fehlernummern",options);
    }
    else if (who == rn || !strstr(who, rn+":"))
    {
        mapping privgroups = params["zfe-privgroups"] || ([]);
        errlist = ERROR_DB->query_error_list(rn,
                options+([EDB_OPT_GROUP_ONE:rn])
                ) || ({ });
        if (who == rn)
        {
            errlist = filter(errlist,
            (:
                string *pg = $2[$1[EDB_ERRLIST_ERRNUM]];
                return !sizeof(pg) || member (pg,$3)>=0;
            :), privgroups, rn);
        }
        else
        {
            errlist = filter(errlist,
                (: member($2[$1[EDB_ERRLIST_ERRNUM]]||({}), $3)>=0 :),
                privgroups, who);
        }
    }
    else
    {
        errlist = ERROR_DB->query_error_list(rn,options);
    }
    if (!pointerp(errlist) || sizeof(errlist) < 1)
    {
        //browse_write_line("Keine Fehler (mehr) in der Fehlerliste.");
        return B_REBUILT;
    }
    old[B_DATA] = errlist;
    old[B_START_LINE] = 0;
    old[B_HEADER_LINES] = ({ ZFE_MORE_LINE_HF, ZFE_MORE_LINE_HF,
                             ZFE_MORE_LINE_MI, ZFE_MORE_LINE_MI });
    old[ZFE_OPTIONS] = options;
    return old;
}

static mixed zfe_errlist_reload(mixed menues)
{
    DEBUG("zfe_errlist_reload");

    menues[<1][B_FLAGS] &= ~BF_DIRTY;
    mixed menue = zfe_errlist_init(menues[<1]);
    if (mappingp(menue))
    {
        menue[B_FLAGS] &= ~BF_DIRTY; // Dirty flag loeschen.
        menues[<1] = menue;
        return menues;
    }
    if (menue == B_REBUILT)
    {
        if (sizeof(menues)>1)
        {
            // RELOAD des uebergeordneten Menus notwendig??
            menues = menues[..<2];
            menues[<1][B_FLAGS] |= BF_DIRTY;
            return menues;
        }
        else
        {
            browse_write_line("Keine Fehler (mehr) in der Fehlerliste.");
            return B_QUIT;
        }
    }
    if (menue == B_QUIT)
    {
        return B_QUIT;
    }
    return B_QUIT;
}

static mixed zfe_errlist_search_forward(mapping menue)
{
    if (!mappingp(menue) )
        return 0;
    int * newerrs = _query_new_wiz_errors();
    int start = menue[B_CURRENT_LINE] + 1;
    mixed * content = menue[B_DATA];
    int end = sizeof(content);
    int i;
    string search = menue[B_SEARCH_STRING];
    if (start > sizeof(content) || !stringp(search) || !sizeof(search))
        return 0;
    if (start < 0)
        start = 0;
    if (end <= start) 
        return 0;
    int err_n = strlen(to_string(sizeof(content)));
    string errformat = " %"+err_n+"d: %s %c %c %-10s %-="+(49-err_n)+"s\n";
    for (i=start; i < end ;i++)
    {
        string  onerow = sprintf(errformat,
                    i+1,
                    format_ultra_short_time(content[i][EDB_ERRLIST_TIME]),
                    member(newerrs,content[i][EDB_ERRLIST_ERRNUM])>-1?'+':' ',
                    content[i][EDB_ERRLIST_TYPE][0],
                    content[i][EDB_ERRLIST_PLAYER]||"",
                    content[i][EDB_ERRLIST_FILE]||"");
         if (strstr( onerow, search)!=-1)
         {
             menue[B_CURRENT_LINE] = i;
             return menue;
         }
    }
    return 0; // nicht gefunden
}

private string * format_errlist(int start, int delta,
                                mixed * content, int counter)
{
    string * result = ({ });
    string errformat,onerow;
    int start2,end,err_n,i,sumlines,linecount;
    int * newerrs = _query_new_wiz_errors();

    if (delta >= 0)
    {
        start2 = start;
        end = start + delta;
    }
    else
    {
        start2 = start + delta;
        end = start;
    }
    if (start2 > sizeof(content))
        return 0;
    if (end >= sizeof(content))
        end = sizeof(content)-1;
    if (start2 < 0)
        start2 = 0;
    if (end < start2) return 0;

    err_n = strlen(to_string(sizeof(content)));
    errformat = " %"+err_n+"d: %s %c %c %-10s %-="+(49-err_n)+"s\n";
    counter = 0;
    sumlines = 0;
    if (delta >= 0)
    {
        for(i = start2;i<=end;i++)
        {
            onerow = sprintf(errformat,
                    i+1,
                    format_ultra_short_time(content[i][EDB_ERRLIST_TIME]),
                    member(newerrs,content[i][EDB_ERRLIST_ERRNUM])>-1?'+':' ',
                    content[i][EDB_ERRLIST_TYPE][0],
                    content[i][EDB_ERRLIST_PLAYER]||"",
                    content[i][EDB_ERRLIST_FILE]||"");
            linecount = sizeof(explode(onerow,"\n"))-1;
            if (sumlines + linecount > delta)
                break;
            sumlines += linecount;
            result += ({ onerow });
            counter++;
        }
    }
    else
    {
        for(i = end;i>=start2;i--) // Rueckwaerts iterieren
        {
            onerow = sprintf(errformat,
                    i+1,
                    format_ultra_short_time(content[i][EDB_ERRLIST_TIME]),
                    member(newerrs,content[i][EDB_ERRLIST_ERRNUM])==-1?'+':' ',
                    content[i][EDB_ERRLIST_TYPE][0],
                    content[i][EDB_ERRLIST_PLAYER]||"",
                    content[i][EDB_ERRLIST_FILE]||"");
            linecount = sizeof(explode(onerow,"\n"));
            if (sumlines + linecount > -delta)
                break;
            sumlines += linecount;
            result = ({ onerow }) + result; // Rueckwaerts sammeln
            counter++;
        }
    }
    return result;
}

static string * zfe_errlist_display(mapping menue)
{
    int counter = 0;
    if (!mappingp(menue) )
        return 0;
    return format_errlist(menue[B_CURRENT_LINE],menue[B_NUM_LINES],
                          menue[B_DATA], &counter);
}

static string zfe_errlist_prompt(mapping menue)
{
    string str = "Fehlerliste ";
    int flag_num = 0;
    if (menue[ZFE_OPTIONS][EDB_OPT_WIEDERVORLAGE])
    {
        str += "(Wiedervorlage) ";
        flag_num = 1;
    }
    else if (menue[ZFE_OPTIONS][EDB_OPT_ERRNUMS])
    {
        str += "(Fehlernummern) ";
    }
    if (member(menue[ZFE_OPTIONS],EDB_OPT_GROUP_ONE)
          && menue[ZFE_OPTIONS][EDB_OPT_GROUP_ONE] != 0) 
    {
        if (flag_num)
        {
            if (menue[ZFE_OPTIONS][EDB_OPT_GROUP_ONE] == 0)
            {
                str+= "Neu";
            }
            else
            {
                str += "am "
                    +  shorttimestr(menue[ZFE_OPTIONS][EDB_OPT_GROUP_ONE]);
            }
        }
        else 
        {
            str += menue[ZFE_OPTIONS][EDB_OPT_GROUP_ONE];
        }
    }    
    return str + " [z,q]";
}

static mixed zfe_errlist_action(string str, mapping * menues)
{
    int i,errnum,linecounter,start,ret;
    int *params,*errnums;
    mapping menue = menues[<1];
    mapping options = deep_copy(menue[ZFE_OPTIONS]);
    string * spar;
    str = space(str);
    if (str == "") str = " ";
    switch (str[0..0])
    {
    case " ":
    case "d":
        if (!format_errlist(start=menue[B_CURRENT_LINE],menue[B_NUM_LINES],
                          menue[B_DATA],&linecounter) || linecounter == 0)
        {
             start = sizeof(menue[B_DATA]);
             browse_write_line("Ende der Daten erreicht.");
        }
        else
        {
            start += linecounter;
        }
        menue[B_CURRENT_LINE] = start;
        menues[<1] = menue;
        return menues;
    case "u":
        if (!format_errlist(start=menue[B_CURRENT_LINE],-menue[B_NUM_LINES],
                          menue[B_DATA],&linecounter) || linecounter == 0)
        {
             start = 0;
             browse_write_line("Anfang der Daten erreicht.");
        }
        else
        {
            start -= linecounter;
        }
        menue[B_CURRENT_LINE] = start;
        menues[<1] = menue;
        return menues;
    case "<":
        menue[B_CURRENT_LINE] = 0;
        menues[<1] = menue;
        return menues;
    case ">":
        start = sizeof(menue[B_DATA]) - 1;
        if (!format_errlist(start,-menue[B_NUM_LINES],
                          menue[B_DATA],&linecounter) || linecounter == 0)
        {
             start = 0;
             browse_write_line("Ende der Daten erreicht.");
        }
        else
        {
            start -= linecounter;
        }
        menue[B_CURRENT_LINE] = start;
        menues[<1] = menue;
        return menues;
    case "n":
        return zfe_search_next_new_error(menues);
    case "m":
        if (sizeof(str)>1)
        {
            params = extract_numbers(str[1..]);
            if (sizeof(params)==1)
            {
                if (params[0] > 0 && params[0] <= sizeof(menue[B_DATA]))
                {
                    errnum = menue[B_DATA][params[0]-1][EDB_ERRLIST_ERRNUM];
                    _update_new_wiz_errors( ({errnum}) );
                    menue[B_FLAGS] |= BF_DIRTY;
                    menues[<1] = menue;
                    return menues;
                }
            } else if (sizeof(params)==2 && params[0] > 0
                      && params[0] <= params[1]
                      && params[1] <= sizeof(menue[B_DATA]) )
            {
                _update_new_wiz_errors( map(
                    menue[B_DATA][(params[0]-1)..(params[1]-1)],
                    (: $1[EDB_ERRLIST_ERRNUM] :)));
                menue[B_FLAGS] |= BF_DIRTY;
                menues[<1] = menue;
                return menues;
            }
        }
        browse_write_line("Falsche Parameter: m <nr>|(<von>-<bis>)");
        return menues;
    case "N":
        if (sizeof(str)>1)
        {
            params = extract_numbers(str[1..]);
            if (sizeof(params)==1)
            {
                if (params[0] > 0 && params[0] <= sizeof(menue[B_DATA]))
                {
                    errnum = menue[B_DATA][params[0]-1][EDB_ERRLIST_ERRNUM];
                    _update_new_wiz_errors( 0, ({errnum}) );
                    menue[B_FLAGS] |= BF_DIRTY;
                    menues[<1] = menue;
                    return menues;
                }
            } else if (sizeof(params)==2 && params[0] > 0 && params[1] > 0
                      && params[0] <= params[1]
                      && params[1] <= sizeof(menue[B_DATA]) )
            {
                _update_new_wiz_errors( 0, map(
                    menue[B_DATA][(params[0]-1)..(params[1]-1)],
                    (: $1[EDB_ERRLIST_ERRNUM] :)));
                menue[B_FLAGS] |= BF_DIRTY;
                menues[<1] = menue;
                return menues;
            }
        }
        browse_write_line("Falsche Parameter: N <nr>|(<von>-<bis>)");
        return B_DONE;
    case "a": // add_debugger
        if (sizeof(str)>1)
        {
            spar = explode(space(str[1..])," ");
            if (sizeof(spar)<2)
            {
                browse_write_line("Syntax: a <von>-<bis> [Bereich|Gott...]");
                return B_DONE;
            }
            params = extract_numbers(spar[0]);
            errnums = ({ });
            if (sizeof(params)==1)
            {
                if (params[0] > 0 && params[0] <= sizeof(menue[B_DATA]))
                {
                    errnum = menue[B_DATA][params[0]-1][EDB_ERRLIST_ERRNUM];
                    errnums = ({errnum});
                }
            }
            else if (sizeof(params)==2 && params[0] > 0 && params[1] > 0
                      && params[0] <= params[1]
                      && params[1] <= sizeof(menue[B_DATA]) )
            {
                errnums = map(
                    menue[B_DATA][(params[0]-1)..(params[1]-1)],
                    (: $1[EDB_ERRLIST_ERRNUM] :));
            }
            if (sizeof(errnums) <= 0)
            {
                browse_write_line("Keine Fehlernummern gefunden.");
                return B_DONE;
            }
            str = implode(spar[1..]," ");
            return cmd_add_debugger(errnums, str);
        }
        browse_write_line("Syntax: a <von>-<bis> [Bereich|Gott...]");
        return B_DONE;
    case "A":
    if (sizeof(str)>1)
        {
            spar = explode(space(str[1..])," ");
            if (sizeof(spar)<2)
            {
                browse_write_line("Syntax: A <von>-<bis> [Objekt|Datei]");
                return B_DONE;
            }
            params = extract_numbers(spar[0]);
            errnums = ({ });
            if (sizeof(params)==1)
            {
                if (params[0] > 0 && params[0] <= sizeof(menue[B_DATA]))
                {
                    errnum = menue[B_DATA][params[0]-1][EDB_ERRLIST_ERRNUM];
                    errnums = ({errnum});
                }
            }
            else if (sizeof(params)==2 && params[0] > 0 && params[1] > 0
                      && params[0] <= params[1]
                      && params[1] <= sizeof(menue[B_DATA]) )
            {
                errnums = map(
                    menue[B_DATA][(params[0]-1)..(params[1]-1)],
                    (: $1[EDB_ERRLIST_ERRNUM] :));
            }
            if (sizeof(errnums) <= 0)
            {
                browse_write_line("Keine Fehlernummern gefunden.");
                return B_DONE;
            }
            str = implode(spar[1..]," ");
            return cmd_replace_file(({menues[<1][ZFE_ERRNUM]}), str);
        }
        browse_write_line("Syntax: A <von>-<bis> [Objekt|Datei]");
        return B_DONE;
    case "v": // hide_debugger
        if (sizeof(str)>1)
        {
            spar = explode(space(str[1..])," ");
            if (sizeof(spar)<2)
            {
                browse_write_line("Syntax: v <von>-<bis> [Bereich|Gott...]");
                return B_DONE;
            }
            params = extract_numbers(spar[0]);
            errnums = ({ });
            if (sizeof(params)==1)
            {
                if (params[0] > 0 && params[0] <= sizeof(menue[B_DATA]))
                {
                    errnum = menue[B_DATA][params[0]-1][EDB_ERRLIST_ERRNUM];
                    errnums = ({errnum});
                }
            }
            else if (sizeof(params)==2 && params[0] > 0 && params[1] > 0
                      && params[0] <= params[1]
                      && params[1] <= sizeof(menue[B_DATA]) )
            {
                errnums = map(
                    menue[B_DATA][(params[0]-1)..(params[1]-1)],
                    (: $1[EDB_ERRLIST_ERRNUM] :));
            }
            if (sizeof(errnums) <= 0)
            {
                browse_write_line("Keine Fehlernummern gefunden.");
                return B_DONE;
            }
            str = implode(spar[1..]," ");
            return cmd_hide_debugger(errnums, str);
        }
        browse_write_line("Syntax: v <von>-<bis> [Bereich|Gott...]");
        return B_DONE;
    case "l":
        if (sizeof(str)>1)
        {
            params = extract_numbers(space(str[1..]));
            errnums = ({ });
            if (sizeof(params)==1)
            {
                if (params[0] > 0 && params[0] <= sizeof(menue[B_DATA]))
                {
                    errnum = menue[B_DATA][params[0]-1][EDB_ERRLIST_ERRNUM];
                    errnums = ({errnum});
                }
            }
            else if (sizeof(params)==2 && params[0] > 0 && params[1] > 0
                      && params[0] <= params[1]
                      && params[1] <= sizeof(menue[B_DATA]) )
            {
                errnums = map(
                    menue[B_DATA][(params[0]-1)..(params[1]-1)],
                    (: $1[EDB_ERRLIST_ERRNUM] :));
            }
            if (sizeof(errnums) <= 0)
            {
                browse_write_line("Keine Fehlernummern gefunden.");
                return B_DONE;
            }
            return cmd_delete_error(errnums);
        }
        browse_write_line("Syntax: l <von>-<bis>");
        return B_DONE;
    case "w": // wiedervorlage
        if (sizeof(str)>1)
        {
            spar = explode(space(str[1..])," ");
            if (sizeof(spar)!=2)
            {
                browse_write_line("Syntax: w <von>-<bis> +<tage>");
                return B_DONE;
            }
            params = extract_numbers(spar[0]);
            errnums = ({ });
            if (sizeof(params)==1)
            {
                if (params[0] > 0 && params[0] <= sizeof(menue[B_DATA]))
                {
                    errnum = menue[B_DATA][params[0]-1][EDB_ERRLIST_ERRNUM];
                    errnums = ({errnum});
                }
            }
            else if (sizeof(params)==2 && params[0] > 0 && params[1] > 0
                      && params[0] <= params[1]
                      && params[1] <= sizeof(menue[B_DATA]) )
            {
                errnums = map(
                    menue[B_DATA][(params[0]-1)..(params[1]-1)],
                    (: $1[EDB_ERRLIST_ERRNUM] :));
            }
            if (sizeof(errnums) <= 0)
            {
                browse_write_line("Keine Fehlernummern gefunden.");
                return B_DONE;
            }
            ret = extract_xdays(spar[1]);
            if (ret > time())
            {
                add_wiedervorlage(errnums,ret);
                browse_write_line("Wiedervorlage gesetzt.");
            }
            else
            {
                browse_write_line(wrap("Datum muss entweder in der "
                    "Zukunft liegen, oder wird in +<tagen> angegeben."));
            }
            return menues;
        }
        browse_write_line("Syntax: w <von>-<bis> +<tage>");
        return B_DONE;
    case "W":
        if (sizeof(str)>1)
        {
            params = extract_numbers(str[1..]);
            errnums = ({ });
            if (sizeof(params)==1)
            {
                if (params[0] > 0 && params[0] <= sizeof(menue[B_DATA]))
                {
                    errnum = menue[B_DATA][params[0]-1][EDB_ERRLIST_ERRNUM];
                    errnums = ({errnum});
                }
            }
            else if (sizeof(params)==2 && params[0] > 0 && params[1] > 0
                      && params[0] <= params[1]
                      && params[1] <= sizeof(menue[B_DATA]) )
            {
                errnums = map(
                    menue[B_DATA][(params[0]-1)..(params[1]-1)],
                    (: $1[EDB_ERRLIST_ERRNUM] :));
            }
            if (sizeof(errnums) <= 0)
            {
                browse_write_line("Keine Fehlernummern gefunden.");
                return B_DONE;
            }
            remove_wiedervorlage(errnums);
            browse_write_line("Fehler aus allen Wiedervorlagen entfernt.");
            return menues;
        }
        browse_write_line("W von-bis (zum loeschen der Wiedervorlage von bis)");
        return menues;
    case "z":
        if (sizeof(menues)>1) {
            menues = menues[..<2];
            menues[<1][B_FLAGS] |= BF_DIRTY;
        } else {
            browse_write_line("Es geht nicht weiter zurueck.\n");
            menues[<1][B_FLAGS] |= BF_NO_DISPLAY;
        }
        return menues;
    case "Z": // Z [-t] [-i] <nr>-[<nr>]
        if (sizeof(str)<2)
        {
            browse_write_line("Syntax: Z [-t] [-i] <nr>-[<nr>]");
            return B_DONE;
        }
        spar = explode(lower_case(space(str[1..]))," ") - ({""," "});
        ret =  (member(spar, "-t")!= -1) ? ZFE_ZSF_TRACE :0;
        ret |= (member(spar, "-i")!= -1) ? ZFE_ZSF_INFOS :0;
        if (ret)
        {
            spar -= ({ "-t", "-i" });
        }
        if (sizeof(spar) != 1)
        {
            browse_write_line("Syntax: Z [-t] [-i] <nr>-[<nr>]");
            return B_DONE;
        }
        params = extract_numbers(str[1..]);
        errnums = ({ });
        if (sizeof(params)==1)
        {
            if (params[0] > 0 && params[0] <= sizeof(menue[B_DATA]))
            {
                errnum = menue[B_DATA][params[0]-1][EDB_ERRLIST_ERRNUM];
                errnums = ({errnum});
            }
        }
        else if (sizeof(params)==2 && params[0] > 0 && params[1] > 0
                  && params[0] <= params[1]
                  && params[1] <= sizeof(menue[B_DATA]) )
        {
            errnums = map(
                menue[B_DATA][(params[0]-1)..(params[1]-1)],
                (: $1[EDB_ERRLIST_ERRNUM] :));
        }
        if (sizeof(errnums) <= 0)
        {
            browse_write_line("Keine Fehlernummern gefunden.");
            return B_DONE;
        }
        return menues + ({ ([  B_TYPE : "zfe_abstract",
                               ZFE_OPTIONS : options,
                               ZFE_ERRNUM : errnums,
                               ZFE_ZSF : ret,
                        ]) });
    default:
        if (sscanf(str,"%d",i)==1 && i > 0 && i <= sizeof(menue[B_DATA]))
        {
            errnum = menue[B_DATA][i-1][EDB_ERRLIST_ERRNUM];
            menues += ({ ([ B_TYPE : "zfe_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: i,
                            ZFE_ERRNUM: errnum ]) });
            return menues;
        }
    }
    return B_NOTHING;
}

// ---------------------------------------------------------------------------
// --- zfe_single ---- Einzelanzeige eines Fehlers.

private string _format_runtime_subtypes(mixed * subtype)
{
    string result = "";
    string rformat = "%-=12s %-=66s\n";
    int first = 1;
    if (!pointerp(subtype) || !sizeof(subtype))
        return "";
    foreach(mapping suberr: subtype)
    {
        if (first)
        {
            first = 0;
        }
        else 
        {
            result += "\nDatum:       "+timestr(suberr[EDB_E_DATE])+"\n";
        }
        if (suberr[EDB_E_COMMAND] && space(suberr[EDB_E_COMMAND])!="")
            result += sprintf(rformat,"Kommando:",suberr[EDB_E_COMMAND]);
        result += sprintf(rformat,"Verursacher:",
                    suberr[EDB_E_WHO]?suberr[EDB_E_WHO]:"Niemand");
        if (suberr[EDB_E_FIRSTROOM])
            result += sprintf(rformat,"Erster Raum:",suberr[EDB_E_FIRSTROOM]);
        result += "Was:         "+({"Runtime-Fehler","Heart-Beat-Fehler",
                "Benutzerdefiniert (do_error)"})[suberr[EDB_E_SUBTYPE]]+"\n";
    }
    return result;
}

// Hier wird die lange Ausgabe eines Fehlers berechnet
//  excl wird an update_new_wiz_errors weitergeleitet (eval-sparend)
// war private varargs string get_msg_text(int err, mixed *m, int *excl)
private varargs string get_errmsg_text(int err, int errnum)
{
    string out, tmp_fe, tmp_co;
    int what, pos;
    mapping privgroups;
    string *pg;
    string *debugger;
    mixed * eheader;
    mapping edata;

    eheader = ERROR_DB->query_error_header(errnum);
    edata = ERROR_DB->query_error_data(errnum);
    if (!pointerp(eheader))
        return "[Kein Fehler gefunden]\n";

    privgroups = params["zfe-privgroups"] || ([]);
    pg = privgroups[errnum];

    what = eheader[EDB_H_TYPE];
    out = sprintf("%-12s %-27s %38s\n",
            to_string(err) + ":",
            ERROR_NAMES[what] + " ("+ errnum + "):",
            timestr(eheader[EDB_H_OPENED]));
    
    if (!mappingp(edata))
    {
        debugger = eheader[EDB_H_DEBUGGER];
        out = sprintf("%sZustaendig:  %-=66s\n",
                out, implode(debugger,", ") );
        return "Unvollstaendiger Fehler, bitte loeschen:\n"+out;
    }

    if (err)
        _update_new_wiz_errors(({errnum}));
    else
        pg = ({});

    debugger = eheader[EDB_H_DEBUGGER];
    if(sizeof(pg))
    {
        string rn = this_player()->query_real_name();
        if(member(debugger, rn)>=0)
            debugger = debugger - ({rn}) + pg;
    }

    switch (what)
    {
        case EDB_FEHLER:
        case EDB_IDEE:
        case EDB_LOB:
        case EDB_TYPO:
        case EDB_DETAIL:
/*
-------------------------------------------------------------------------------
nr:           FEHLER/IDEE (<Fehlernummer>)                              <Datum>
Urheber:      <Name>, (z.Zt in <Umgebung>)
Zustaendig:   <Wiz-Liste>
File:         <Filename>
              (<Fehlerfeedbackobjektname>)

<Fehlertext> ....
-------------------------------------------------------------------------------
*/
            out = sprintf("%sUrheber:     %s (z.Zt. in %s)\n"
                "Zustaendig:  %-=66s\nFile:        %-=66s\n\n%s%s",
                out,
                CAP(eheader[EDB_H_PLAYER]||"-"),
                edata[EDB_E_ROOM]||"dem Nirwana!",
                implode(debugger,", "),
                (format_filename(eheader[EDB_H_FILE])||"-")+
                (edata[EDB_E_OBJ] ? edata[EDB_E_OBJ] : ""),
                edata[EDB_E_ERROR],
                format_history(edata[EDB_E_HISTORY]));
            break;
        case EDB_RUNTIME:
/*
-------------------------------------------------------------------------------
nr:           RUNTIME/HEARTBEAT ERROR (<Fehlernummer>)                  <Datum>
Zustaendig:   <Wiz-Liste>
Objekt:       <fehlerobjekt>
File:         <filename>
Zeile:        <Zeile>
Fehler:       <Fehlermeldung>
             -------------------------
<Liste der Fehler: Datum - ausloesendes Kommando - ausloesendes Objekt>
-------------------------------------------------------------------------------
*/
            if ((pos = strstr(edata[EDB_E_ERROR], "Kommentar:")) != -1)
            {
                tmp_fe = edata[EDB_E_ERROR][0..(pos - 1)];
                tmp_co = edata[EDB_E_ERROR][pos..<1];
            }
            else
            {
                tmp_fe = (edata[EDB_E_ERROR][<1] == '\n' ?
                edata[EDB_E_ERROR][0..<2] : edata[EDB_E_ERROR]);
                tmp_co = "";
            }
            out = sprintf("%s\nZustaendig:  %-=66s\nObjekt:      %s\n"
                "File:        %s\nZeile:       %d\nFehler:      %-=66s\n"
                "%s%s%s",
                out[0..<2],
                implode(debugger,", "),
                format_filename(edata[EDB_E_OBJ]),
                format_filename(MASTER_OB->add_slash(edata[EDB_E_FILE]))||"-",
                edata[EDB_E_LINE],
                tmp_fe,
                _format_runtime_subtypes(({edata}) 
                                        + (edata[EDB_E_SUBERRORS]||({})) ),
                tmp_co,
                format_history(edata[EDB_E_HISTORY]));
        break;
/*
-------------------------------------------------------------------------------
nr:           COMPILE ERROR (<Fehlernummer>)                            <Datum>
Zustaendig:   <Wiz-Liste>
File:         <filename>
Fehler:       <Fehlermeldung>
-------------------------------------------------------------------------------
*/
        case EDB_COMPILE:
            out = sprintf("%s\nZustaendig:  %-=66s\nFile:        %s\n"
                    "Fehler:      %-=66s\n%s",
                    out[0..<2],
                    implode(debugger,", "),
                    format_filename(edata[EDB_E_FILE]||"-"),
                    edata[EDB_E_ERROR],
                    format_history(edata[EDB_E_HISTORY]));
    }
    return out[..<2];
}

public string zfe_get_errmsg(int errnum)
{
    return get_errmsg_text(0,errnum);
}

static int zfe_single_total(mapping menue)
{
    return sizeof(menue[B_DATA]);
}

static mixed zfe_single_init(mapping old)
{
    DEBUG("zfe_single_init");
    zfe_last_errnum = 0;
    if ( (old[B_FLAGS]&BF_NO_DISPLAY) == 0)
    {
        old[B_DATA] = explode(get_errmsg_text(
                    old[ZFE_INDEX],old[ZFE_ERRNUM]),"\n");
    }
    old[B_START_LINE] = 0;
    old[B_HEADER_LINES] = ({ ZFE_MORE_LINE_HF, ZFE_MORE_LINE_HF,
                             ZFE_MORE_LINE_MI, ZFE_MORE_LINE_MI });
    old[B_HELP] = ([ B_TYPE : B_DYNAMICMORE,
                         B_FILE : ZFE_BHELP("_single"),
                         B_PROMPT : "Hilfe zur Fehleranzeige",
                      ]);
    return old;
}

static mixed zfe_single_reload(mixed menues)
{
    int index,errnum,end;
    mapping options;
    mixed data;

    DEBUG("zfe_single_reload");
    switch (menues[<1][ZFE_GOTO]||"")
    {
    case "+":
        if (sizeof(menues)>1)
        {
            if (menues[<2][B_TYPE] == "zfe_errlist")
            {
                index = menues[<1][ZFE_INDEX] + 1;
                end = sizeof(menues[<2][B_DATA]);
                if (index <= end)
                {
                    errnum = menues[<2][B_DATA][index-1][EDB_ERRLIST_ERRNUM];
                    options = deep_copy(menues[<1][ZFE_OPTIONS]);
                    return menues[..<2] + ({ zfe_single_init(([
                            B_TYPE : "zfe_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: index,
                            ZFE_ERRNUM: errnum ])) });

                }
                else
                {
                    browse_write_line("Letzten Fehler in dieser "
                            "Anzeige erreicht.");
                    return B_DONE;
                }
            }
            else if (menues[<2][B_TYPE] == "zfe_archive_list")
            {
                index = menues[<1][ZFE_INDEX] + 1;
                end = zfe_archive_list_total(menues[<2]);
                if (index <= end)
                {
                    data = ERROR_ARCHIVE->get_errorlist(
                         index-1,1,menues[<1][ZFE_OPTIONS]);
                    if (sizeof(data)!=1) return B_NOTHING;
                    errnum = data[0][0];
                    options = deep_copy(menues[<1][ZFE_OPTIONS]);
                    if (ERROR_DB->query_error_header(errnum)) 
                    {
                        return menues[..<2] + ({ zfe_single_init(([
                            B_TYPE : "zfe_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: index,
                            ZFE_ERRNUM: errnum ])) });
                    }
                    else
                    {
                        return menues[..<2] + ({ zfe_archive_single_init(([
                            B_TYPE : "zfe_archive_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: index,
                            ZFE_ERRNUM: errnum ])) });
                    }
                }
                else
                {
                    browse_write_line("Letzten Fehler in dieser "
                            "Anzeige erreicht.");
                    return B_DONE;
                }
             }
         }
         break;
    case "-":
        if (sizeof(menues)>1)
        {
            if (menues[<2][B_TYPE] == "zfe_errlist")
            {
                index = menues[<1][ZFE_INDEX] - 1;
                if (index > 0)
                {
                    errnum = menues[<2][B_DATA][index-1][EDB_ERRLIST_ERRNUM];
                    options = deep_copy(menues[<1][ZFE_OPTIONS]);
                    return menues[..<2] + ({ zfe_single_init(([
                            B_TYPE : "zfe_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: index,
                            ZFE_ERRNUM: errnum ])) });
                }
                else
                {
                    browse_write_line("Ersten Fehler in dieser "
                            "Anzeige erreicht.");
                    return B_DONE;
                }
            }
            else if (menues[<2][B_TYPE] == "zfe_archive_list")
            {
                index = menues[<1][ZFE_INDEX] - 1;
                if (index > 0)
                {
                    data = ERROR_ARCHIVE->get_errorlist(
                         index-1,1,menues[<1][ZFE_OPTIONS]);
                    if (sizeof(data)!=1) return B_NOTHING;
                    errnum = data[0][0];
                    options = deep_copy(menues[<1][ZFE_OPTIONS]);
                    if (ERROR_DB->query_error_header(errnum)) 
                    {
                        return menues[..<2] + ({ zfe_single_init(([
                            B_TYPE : "zfe_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: index,
                            ZFE_ERRNUM: errnum ])) });
                    }
                    else
                    {
                        return menues[..<2] + ({ zfe_archive_single_init(([
                            B_TYPE : "zfe_archive_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: index,
                            ZFE_ERRNUM: errnum ])) });
                    }
                }
                else
                {
                    browse_write_line("Ersten Fehler in dieser "
                            "Anzeige erreicht.");
                    return B_DONE;
                }
             }
         }
         break;
    case "l":
        if (sizeof(menues)>1)
        {
            if (menues[<2][B_TYPE] == "zfe_errlist")
            {
                index = menues[<1][ZFE_INDEX] - 1;
                if (index > 0)
                {
                    errnum = menues[<2][B_DATA][index-1][EDB_ERRLIST_ERRNUM];
                    options = deep_copy(menues[<1][ZFE_OPTIONS]);
                    return menues[..<2] + ({ zfe_single_init(([
                            B_TYPE : "zfe_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: index,
                            ZFE_ERRNUM: errnum ])) });
                }
                else
                {
                    browse_write_line("Ersten Fehler in dieser "
                            "Anzeige erreicht.");
                    return B_DONE;
                }
            }
            else if (menues[<2][B_TYPE] == "zfe_archive_list")
            {
                index = menues[<1][ZFE_INDEX] - 1;
                if (index > 0)
                {
                    data = ERROR_ARCHIVE->get_errorlist(
                         index-1,1,menues[<1][ZFE_OPTIONS]);
                    if (sizeof(data)!=1) return B_NOTHING;
                    errnum = data[0][0];
                    options = deep_copy(menues[<1][ZFE_OPTIONS]);
                    if (ERROR_DB->query_error_header(errnum)) 
                    {
                        return menues[..<2] + ({ zfe_single_init(([
                            B_TYPE : "zfe_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: index,
                            ZFE_ERRNUM: errnum ])) });
                    }
                    else
                    {
                        return menues[..<2] + ({ zfe_archive_single_init(([
                            B_TYPE : "zfe_archive_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: index,
                            ZFE_ERRNUM: errnum ])) });
                    }
                }
                else
                {
                    browse_write_line("Ersten Fehler in dieser "
                            "Anzeige erreicht.");
                    return B_DONE;
                }
             }
         }
        break;
        default:
            data = zfe_single_init(menues[<1]);
            if (mappingp(data))
            {
                menues[<1] = data;
                return menues;
            }
            else
            {
                return data; // B_QUIT & Co.
            }
    }
    menues[<1][B_FLAGS] &= ~BF_DIRTY;
    return menues;
}

static mixed zfe_single_search_forward(mapping menue)
{
    if (!mappingp(menue) )
        return 0;
    int start = menue[B_CURRENT_LINE]+1;
    mixed * content = menue[B_DATA];
    int end = sizeof(content);
    int i;
    string search = menue[B_SEARCH_STRING];
    if (start > sizeof(content) || !stringp(search) || !sizeof(search))
        return 0;
    if (start < 0)
        start = 0;
    if (end <= start) 
        return 0;
    for (i=start; i < end ;i++)
    {
         if (strstr( content[i], search)!=-1)
         {
             menue[B_CURRENT_LINE] = i;
             return menue;
         }
    }
    return 0; // nicht gefunden
}

static string * zfe_single_display(mapping menue)
{
    if (!mappingp(menue) )
        return 0;
    int start = menue[B_CURRENT_LINE];
    int end = start + menue[B_NUM_LINES];
    string * content = menue[B_DATA];
    if (start > sizeof(content))
        return 0;
    if (end >= sizeof(content))
        end = sizeof(content)-1;
    if (start < 0)
        start = 0;
    if (end < start)
        return 0;
    return content[start..end];
}

static string zfe_single_prompt(mapping menue)
{
    return "Fehleranzeige "+menue[ZFE_ERRNUM]+" [?,+,-,n,...,z,q]";
}

static mixed zfe_single_action(string str, mapping * menues)
{
    int ret,errnum;
    string name,*spar;
    object ob;
    mixed err,data;
    mapping options = deep_copy(menues[<1][ZFE_OPTIONS]);
    str = space(str);
    if (str=="") return B_NOTHING; // evtl anpassen.
    switch (str[0..0])
    {
    case "+":
    case "-":
        if (sizeof(str)>1)
        {
            browse_write_line(
                    "+/-   (ohne Parameter: vor/zurueck navigieren)");
            return B_DONE;
        }
            menues[<1][ZFE_GOTO] = str;
            menues[<1][B_FLAGS] |= BF_DIRTY;
            return menues;
    case "<":
            menues[<1][B_CURRENT_LINE] = 0;
            menues[<1][B_FLAGS] |= BF_DIRTY;
            return menues;
    case ">":
            menues[<1][B_CURRENT_LINE] = max(0,
                sizeof(menues[<1][B_DATA])-menues[<1][B_NUM_LINES]);
            menues[<1][B_FLAGS] |= BF_DIRTY;
            return menues;
    case "n":
        if (sizeof(str)>1)
        {
            browse_write_line(
                    "n   (ohne Parameter: naechst neuen Fehler zeigen)");
            return B_DONE;
        }
        return zfe_search_next_new_error(menues);
    case "M":
        if (sizeof(str)>1)
        {
            browse_write_line("M   (ohne Parameter: Mail an dich schicken)");
            return B_DONE;
        }
        err = ERROR_DB->query_error_header(menues[<1][ZFE_ERRNUM]);
        if (!pointerp(err)) 
        {
            browse_write_line("Fehler geloescht.");
            return B_DONE;
        }
        data = menues[<1][B_DATA];
        MAILD->zfehler(err[EDB_H_PLAYER] || this_player()->query_real_name(),
                       err[EDB_H_DEBUGGER],
                       err[EDB_H_OPENED],
                       implode(data, "\n")+"\n",
                       err[EDB_H_TYPE]);
        browse_write_line("Mail wurde (nur) an Dich geschickt.");
        return B_DONE;
    case "i":
        if (sizeof(str)>1)
        {
            browse_write_line("i   (ohne Parameter: debuginfo anzeigen)");
            return B_DONE;
        }
        errnum = menues[<1][ZFE_ERRNUM];
        data = get_info_text(errnum, &ret);
        if (ret)
        {
            browse_write_line(data);
            return B_DONE;
        }
        else
        {
            return menues + ({ ([ B_TYPE : B_STATICMORE,
                                  B_PROMPT : "Debuginfo zu "+errnum,
                                  B_DATA : data,
                  B_HEADER_LINES :  ({ ZFE_MORE_LINE_HF, ZFE_MORE_LINE_HF,
                                       ZFE_MORE_LINE_MI, ZFE_MORE_LINE_MI }),
                            ]) });
        }
    case "t":
        if (sizeof(str)>1)
        {
            browse_write_line("t   (ohne Parameter: trace anzeigen)");
            return B_DONE;
        }
        errnum = menues[<1][ZFE_ERRNUM];
        data = get_trace_text(errnum, &ret);
        if (ret)
        {
            browse_write_line(data);
            return B_DONE;
        }
        else
        {
            return menues + ({ ([ B_TYPE : B_STATICMORE,
                                  B_PROMPT : "Trace zu "+errnum,
                                  B_DATA : data,
                  B_HEADER_LINES :  ({ ZFE_MORE_LINE_HF, ZFE_MORE_LINE_HF,
                                       ZFE_MORE_LINE_MI, ZFE_MORE_LINE_MI }),
                            ]) });
        }
    case "T":
        if (sizeof(str)>1 && str[1] != ' ')
        {
            browse_write_line("T fehler|idee|typo|wuerdigung");
            return B_DONE;
        }
        if (sizeof(str)<2 || sizeof(str = space(str[1..])) < 1)
        {
            browse_write_line("T fehler|idee|typo|wuerdigung");
            return B_DONE;
        }
        browse_write_line(
                ERROR_DB->exec_change_error_type(
                    menues[<1][ZFE_ERRNUM],
                    lower_case(str[0..0])
                ));
        return B_REBUILT;
    case "c": // Kommentar
        if (sizeof(str)>1 && str[1] != ' ')
        {
            browse_write_line("c Kommentar oder nur c fuer einen Editor");
            return B_DONE;
        }
        switch( cmd_add_comment(menues[<1][ZFE_ERRNUM],
                (sizeof(str)>1)?trim(str[1..]):0,menues))
        {
        case -1: // Editor
            return B_QUIT;
        default:
        case 0:  // Fehler
            return B_DONE;
        case 1:  // Erfolgreich eingegeben
            menues[<1][B_FLAGS] |= BF_DIRTY;
            return menues;
        }
    case "f":  // Feedback
    case "F":  // Rueckfrage
        if (sizeof(str)>1 && str[1] != ' ')
        {
            browse_write_line("f/F Feedback oder nur f/F fuer einen Editor");
            return B_DONE;
        }
        switch( precheck_add_feedback(menues[<1][ZFE_ERRNUM],str[0..0]=="F"))
        {
        case 1: break;
        default: return B_DONE; // Fehlercode
        }
        switch( cmd_add_feedback(menues[<1][ZFE_ERRNUM],str[0..0]=="F",
                (sizeof(str)>1)?trim(str[1..]):0,menues))
        {
        case -1: // Editor
            return B_QUIT;
        default:
        case 0:  // Fehler
            return B_DONE;
        case 1:  // Erfolgreich eingegeben
            menues[<1][B_FLAGS] |= BF_DIRTY;
            return menues;
        }
    case "e":
    case "E":
        ret = (str[0] == 'E');
        name = 0;
        if (sizeof(str)>1 && str[1] != ' ')
        {
            browse_write_line("e datei oder nur e fuer aktuelle Datei.");
            return B_DONE;
        }
        if (sizeof(str)>1)
        {
            name = space(str[1..]);
            if (name=="") name = 0;
        }
        if (!name)
        {
            name = _get_file_name(menues[<1][ZFE_ERRNUM],1);
        }
        if (!name)
        {
            browse_write_line("Keine Datei angegeben");
            return B_DONE;
        }
        else if (file_size(name) < 0)
        {
            browse_write_line("Datei "+name+" nicht gefunden.");
            return B_DONE;
        }
        if (ret)
        {
            if (this_player()->webmud_editfile(name))
                return B_NOTHING;
            
        // lambda, damit keine Parameter uebergeben werden.
            if(edit_file(name, function void(string *buffer,int esc_key)
                {
                    menues[<1][B_FLAGS] |= BF_DIRTY;
                    dynamic_browse(menues); // Wiedereinstieg ins Menu
                })<1)
                return B_NOTHING;
        }
        else
        {
            zfe_last_menues = menues;
            this_player()->notify_ed_enter(1);
            ed(name,"zfe_ed_continue_browse");
        }
        return B_QUIT;
    case "m":
        if (sizeof(str)>1)
        {
            browse_write_line(
                    "m       (ohne Parameter markiert als gelesen)\n");
            return B_DONE;
        }
        _update_new_wiz_errors( ({menues[<1][ZFE_ERRNUM]}) );
        return B_REBUILT;
    case "N":
        if (sizeof(str)>1)
        {
            browse_write_line(
                    "N       (ohne Parameter markiert ungelesen)\n");
            return B_DONE;
        }
        _update_new_wiz_errors( 0, ({menues[<1][ZFE_ERRNUM]}) );
        browse_write_line("Fehler als ungelesen markiert.");
        return B_DONE;
    case "a":
        if (sizeof(str)>1 && str[1] != ' ')
        {
            browse_write_line(
                    "a {<gott>|<domain>|<bereich>|Root|Objekt|Datei}\n");
            return B_DONE;
        }
        if (sizeof(str)>1)
        {
            str = trim(str[1..]);
        }
        else
        {
            str = "";
        }
        if (str=="")
        {
            browse_write_line(
                    "a {<gott>|<domain>|<bereich>|Root|Objekt|Datei}\n");
            return B_DONE;
        }
        return cmd_add_debugger(({menues[<1][ZFE_ERRNUM]}), str);
    case "l":
        if (sizeof(str)>1)
        {
            browse_write_line(
                    "l fuer aktuellen Fehler loeschen.\n");
            return B_DONE;
        }
        ret = cmd_delete_error(({menues[<1][ZFE_ERRNUM]}));
        if (ret == B_REBUILT)
        {
            menues[<1][ZFE_GOTO] = "l";
            menues[<1][B_FLAGS] |= BF_DIRTY;
            return menues;        
        }
        return ret;
    case "A":
        if (sizeof(str)>1 && str[1] != ' ')
        {
            browse_write_line(
                    "A {Objekt|Datei}\n");
            return B_DONE;
        }
        if (sizeof(str)>1)
        {
            str = trim(str[1..]);
        }
        else
        {
            str = "";
        }
        if (str=="")
        {
            browse_write_line(
                    "A {Objekt|Datei}\n");
            return B_DONE;
        }
        return cmd_replace_file(({menues[<1][ZFE_ERRNUM]}), str);
    case "v":
        if (sizeof(str)>1 && str[1] != ' ')
        {
            browse_write_line(
                    "v {<gott>|<domain>|<bereich>|Root|Objekt|Datei}\n");
            return B_DONE;
        }
        if (sizeof(str)>1)
        {
            str = trim(str[1..]);
        }
        else
        {
            str = "";
        }
        if (str=="")
        {
            browse_write_line(
                    "v {<gott>|<domain>|<bereich>|Root|Objekt|Datei}\n");
            return B_DONE;
        }
        return cmd_hide_debugger(({menues[<1][ZFE_ERRNUM]}), str);
    case "w":
        if (sizeof(str)>1 && str[1] != ' ')
        {
            browse_write_line(
                    "w {+tage|dd.mm.jjjj}  (Datum in der Zukunft)\n");
            return B_DONE;
        }
        if (sizeof(str)>1)
        {
            ret = extract_xdays(space(str[1..]));
            if (ret > time())
            {
                add_wiedervorlage(({menues[<1][ZFE_ERRNUM]}),ret);
                browse_write_line("Wiedervorlage gesetzt.");
            }
            else
            {
                browse_write_line(wrap("Datum liegt entweder in der "
                    "Zukunft, oder wird in +<tagen> angegeben."));

            }
            return B_DONE;
        }
        return B_NOTHING;
    case "W":
        if (sizeof(str)>1)
        {
            browse_write_line(
                    "W     (ohne Parameter loescht alle Wiedervorlagen)\n");
            return B_DONE;
        }
        remove_wiedervorlage(({menues[<1][ZFE_ERRNUM]}) );
        browse_write_line("Fehler aus allen Wiedervorlagen entfernt.");
        return B_DONE;
    case "Z": // Z [-t] [-i]
        spar = explode(lower_case(space(str[1..]))," ") - ({""," "});
        ret =  (member(spar, "-t")!= -1) ? ZFE_ZSF_TRACE :0;
        ret |= (member(spar, "-i")!= -1) ? ZFE_ZSF_INFOS :0;
        if (ret)
        {
            spar -= ({ "-t", "-i" });
        }
        return menues + ({ ([  B_TYPE : "zfe_abstract",
                               ZFE_OPTIONS : options,
                               ZFE_ERRNUM : ({ menues[<1][ZFE_ERRNUM] }),
                               ZFE_ZSF : ret,
                        ]) });
    case "z":
        if (sizeof(str)>1)
        {
            browse_write_line(
                    "z       (ohne Parameter kehrt eine Menuebene zurueck)\n");
            return B_DONE;
        }
        if (sizeof(menues)>1)
        {
            int zix = menues[<1][ZFE_INDEX];
            menues = menues[..<2];
            menues[<1][B_CURRENT_LINE] = zix-1;
            menues[<1][B_FLAGS] |= BF_DIRTY;
        }
        else
        {
            browse_write_line("Es geht nicht weiter zurueck.\n");
            menues[<1][B_FLAGS] |= BF_NO_DISPLAY;
        }
        return menues;
    case "q":
        if (sizeof(str)>1)
        {
            browse_write_line(
                    "q       (ohne Parameter verlaesst die zfe menus)\n");
            return B_DONE;
        }
        zfe_last_errnum = menues; // Option -g
        return B_QUIT;
    case "p":
        if (sizeof(str)>1)
        {
            browse_write_line(
                    "p       (ohne Parameter setzt den aktuellen Pfad (cd))\n");
            return B_DONE;
        }
        cmd_wechsle_pfad(menues[<1][ZFE_ERRNUM]);
        return B_DONE;
    case "s":
    case "S":
        if (sizeof(str)>1)
        {
            browse_write_line(
                    "s/S       (ohne Parameter zeigt Sourcedatei)\n");
            return B_DONE;
        }
        name = _get_file_name(menues[<1][ZFE_ERRNUM],1);
        if (!stringp(name))
        {
            browse_write_line("Keine Referenzdatei vorhanden!");
            return B_DONE;
        } 
        else
        {
            mixed * header = ERROR_DB->query_error_header(
                                       menues[<1][ZFE_ERRNUM]);
            int l_end = header[EDB_H_LINE];
            int l_begin = l_end - 1;
            if (l_begin < 1) l_begin = 1;
            if(str[0]=='s')
            {
              err=read_file(name,l_begin,3);
              if(!err) 
              {
                  browse_write_line(wrap("Konnte die Datei '"+name
                                 +"' nicht einlesen."));
                  return B_DONE;
              }
              
              browse_write_line(ZFE_MORE_LINE_HF + "File:   " + name 
                   + "  Zeile: " + (l_end)
                   + "\n\n" + err + "\n" + ZFE_MORE_LINE_HF);
              return B_DONE;
            }
            else
            {
              return menues + ({([ B_TYPE : B_DYNAMICMORE,
                                   B_FILE : name,
                                   B_CURRENT_LINE : l_begin ]) });
            }
        }
        return B_DONE;
    case "g":
    case "G":
        if (sizeof(str)>1)
        {
            browse_write_line(
                    "g/G       (ohne Parameter zgehezu aktuellem Raum.)\n");
            return B_DONE;
        }
        if (wizardshellp(this_player()))
        {
            browse_write_line("Von der Wizardshell nicht verfuegbar!");
            return B_DONE;
        }
        else if (str[0] == 'G')
        {
            mapping edata = ERROR_DB->query_error_data(
                                  menues[<1][ZFE_ERRNUM]);
            if (!mappingp(edata))
            {
                browse_write_line("Fehler nicht mehr vorhanden!");
                return B_DONE;
            }
            name = edata[EDB_E_ROOM];
            if (!stringp(name))
            {
                browse_write_line("Kein Raum vorhanden.");
                return B_DONE;
            }
        } 
        else 
        {
            name = _get_file_name(menues[<1][ZFE_ERRNUM],1);
            if (!stringp(name))
            {
                browse_write_line("Keine Referenzdatei vorhanden!");
                return B_DONE;
            }
        }
        if ((err = catch(ob=touch(name))) || !ob)
        {
            browse_write_line(wrap("File " + name 
                   + " konnte nicht geladen werden" +
                   (err ? ": " + mixed2str(err) : ".")));
            return B_DONE;
        }
        if (!ob->query_room())
        {
            browse_write_line("File " + name + " ist kein Raum.");
            return B_DONE;
        }
        if (this_player()->move(ob, MOVE_MAGIC) != MOVE_OK)
        {
            browse_write_line("Bewegung nicht erlaubt.");
        }
        return B_DONE;
    }
    return B_NOTHING;
}

void zfe_ed_continue_browse()
{
    if (zfe_last_menues)
    {
        zfe_last_menues[<1][B_FLAGS]|=BF_DIRTY;
        dynamic_browse(deep_copy(zfe_last_menues));
        zfe_last_menues = 0;
    }
}

// ---------------------------------------------------------------------------
static int zfe_archive_list_total(mapping menue)
{
    return ({int})ERROR_ARCHIVE->get_errorlist(0,0,menue[ZFE_OPTIONS]);
}

static mixed zfe_archive_list_init(mapping old)
{
    DEBUG("zfe_archive_list_init");
    zfe_last_errnum = 0;
    old[B_START_LINE] = 0;
    old[B_HEADER_LINES] = ({ ZFE_MORE_LINE_HF, ZFE_MORE_LINE_HF,
                             ZFE_MORE_LINE_MI, ZFE_MORE_LINE_MI });
    old[B_HELP] = ([ B_TYPE : B_DYNAMICMORE,
                         B_FILE : ZFE_BHELP("_archive_list"),
                         B_PROMPT : "Hilfe zur Archivliste",
                      ]);
    return old;
}

static mixed zfe_archive_list_reload(mixed menues)
{
    DEBUG("zfe_archive_list_reload");
    mixed menue = menues[<1];
    menue = zfe_archive_list_init(menue);
    if (mappingp(menue))
    {
        menue[B_FLAGS] &= ~ BF_DIRTY;
        menues[<1] = menue;
        return menues;
    }
    return menue; // B_QUIT u.ae.
}

static string * zfe_archive_list_display(mapping menue)
{
    mixed * data = ERROR_ARCHIVE->get_errorlist(
                 menue[B_CURRENT_LINE],
                 menue[B_NUM_LINES],
                 menue[ZFE_OPTIONS]);
    string * list = ({});
    int i;
    // ({ ({ errnum, opend, changed }), ... })
    i = menue[B_CURRENT_LINE];
    foreach (mixed * erra : data)
    {
        list += ({ sprintf("%4d %s %6d %s %s",
                      ++i, 
                      pointerp(ERROR_DB->query_error_header(erra[0]))?"+":"-",
                      erra[0],
                      shorttimestr(erra[1]),
                      shorttimestr(erra[2]) ) });
    }
    return list;
}

static string zfe_archive_list_prompt(mapping menue)
{
    return sprintf("Archivliste %d/%d [z,q]", menue[B_CURRENT_LINE],
            menue[B_END_LINE]);
}

static mixed zfe_archive_list_action(string str, mapping * menues)
{
    mixed * data;
    int i,errnum,ret,*params,*errnums;
    int total = zfe_archive_list_total(menues[<1]);
    string * spar;
    mapping menue = menues[<1];
    mapping options = deep_copy(menues[<1][ZFE_OPTIONS]);
    str = space(str);
    if (str == "") return B_NOTHING;
    switch (str[0..0])
    {
    case "Z": // Z [-t] [-i] <nr>-[<nr>]
        if (sizeof(str)<2)
        {
            browse_write_line("Syntax: Z [-t] [-i] <nr>-[<nr>]");
            return B_DONE;
        }
        spar = explode(lower_case(space(str[1..]))," ") - ({""," "});
        ret =  (member(spar, "-t")!= -1) ? ZFE_ZSF_TRACE :0;
        ret |= (member(spar, "-i")!= -1) ? ZFE_ZSF_INFOS :0;
        if (ret)
        {
            spar -= ({ "-t", "-i" });
        }
        if (sizeof(spar) != 1)
        {
            browse_write_line("Syntax: Z [-t] [-i] <nr>-[<nr>]");
            return B_DONE;
        }
        params = extract_numbers(str[1..]);
        errnums = ({ });
        if (sizeof(params)==1)
        {
            if (params[0] > 0 && params[0] <= sizeof(menue[B_DATA]))
            {
                errnum = menue[B_DATA][params[0]-1][EDB_ERRLIST_ERRNUM];
                errnums = ({errnum});
            }
        }
        else if (sizeof(params)==2 && params[0] > 0 && params[1] > 0
                  && params[0] <= params[1]
                  && params[1] <= sizeof(menue[B_DATA]) )
        {
            errnums = map(
                menue[B_DATA][(params[0]-1)..(params[1]-1)],
                (: $1[EDB_ERRLIST_ERRNUM] :));
        }
        if (sizeof(errnums) <= 0)
        {
            browse_write_line("Keine Fehlernummern gefunden.");
            return B_DONE;
        }
        return menues + ({ ([  B_TYPE : "zfe_abstract",
                               ZFE_OPTIONS : options,
                               ZFE_ERRNUM : errnums,
                               ZFE_ZSF : ret | ZFE_ZSF_ARCHIVE,
                        ]) });
    case "z":
        if (sizeof(menues)>1)
        {
            menues = menues[..<2];
            menues[<1][B_FLAGS] |= BF_DIRTY;
        }
        else
        {
            browse_write_line("Es geht nicht weiter zurueck.\n");
            menues[<1][B_FLAGS] |= BF_NO_DISPLAY;
        }
        return menues;
    case ">":
        menues[<1][B_CURRENT_LINE] = max(total - menues[<1][B_NUM_LINES],
                                                 menues[<1][B_START_LINE]);
        menues[<1][B_FLAGS] |= BF_DIRTY;
        return menues;
    case "": 
    default:
        if (sscanf(str,"%d",i)==1 && i > 0 
                && i <= total)
        {
            data = ERROR_ARCHIVE->get_errorlist(i-1,1,options);
            if (sizeof(data)!=1) return B_NOTHING;
            errnum = data[0][0];
            if (ERROR_DB->query_error_header(errnum)) 
            {
                menues += ({ ([ B_TYPE : "zfe_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: i,
                            ZFE_ERRNUM: errnum ]) });
            }
            else
            {
                menues += ({ ([ B_TYPE : "zfe_archive_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: i,
                            ZFE_ERRNUM: errnum ]) });
            }
            return menues;
        }
    }
    return B_NOTHING;
}

// ---------------------------------------------------------------------------
static int zfe_archive_single_total(mapping menue)
{
    return sizeof(menue[B_DATA]);
}

static mixed zfe_archive_single_init(mapping old)
{
    DEBUG("zfe_archive_single_init");
    zfe_last_errnum = 0;
    string text = ERROR_ARCHIVE->get_errtext(old[ZFE_ERRNUM]);
    old[B_DATA] = ({"Archivierter Fehler:"}) + explode(text,"\n");
    old[B_START_LINE] = 0;
    old[B_HEADER_LINES] = ({ ZFE_MORE_LINE_HF, ZFE_MORE_LINE_HF,
                             ZFE_MORE_LINE_MI, ZFE_MORE_LINE_MI });
    old[B_HELP] = ([ B_TYPE : B_DYNAMICMORE,
                         B_FILE : ZFE_BHELP("_archive_single"),
                         B_PROMPT : "Hilfe zur archivierten Fehleranzeige",
                      ]);
    return old;
}

static mixed zfe_archive_single_reload(mixed menues)
{
    int index,errnum,end;
    mapping options = deep_copy(menues[<1][ZFE_OPTIONS]);
    mixed * data;
    DEBUG("zfe_archive_single_reload");

    switch (menues[<1][ZFE_GOTO]||"")
    {
    case "+":
        if (sizeof(menues)>1)
        {
            if (menues[<2][B_TYPE] == "zfe_archive_list")
            {
                index = menues[<1][ZFE_INDEX] + 1;
                end = zfe_archive_list_total(menues[<2]);
                if (index <= end)
                {
                    data = ERROR_ARCHIVE->get_errorlist(index-1,1,options);
                    if (sizeof(data)!=1) return B_NOTHING;
                    errnum = data[0][0];
                    if (ERROR_DB->query_error_header(errnum)) 
                    {
                        return menues[..<2] + ({ zfe_single_init(([
                            B_TYPE : "zfe_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: index,
                            ZFE_ERRNUM: errnum ])) });
                    }
                    else
                    {
                        return menues[..<2] + ({ zfe_archive_single_init(([
                            B_TYPE : "zfe_archive_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: index,
                            ZFE_ERRNUM: errnum ])) });
                    }
                }
             }
        }
        break;
    case "-":
        if (sizeof(menues)>1)
        {
            if (menues[<2][B_TYPE] == "zfe_archive_list")
            {
                index = menues[<1][ZFE_INDEX] - 1;
                if (index > 0)
                {
                    data = ERROR_ARCHIVE->get_errorlist(index-1,1,options);
                    if (sizeof(data)!=1) return B_NOTHING;
                    errnum = data[0][0];
                    if (ERROR_DB->query_error_header(errnum)) 
                    {
                        return menues[..<2] + ({ zfe_single_init(([
                            B_TYPE : "zfe_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: index,
                            ZFE_ERRNUM: errnum ])) });
                    }
                    else
                    {
                        return menues[..<2] + ({ zfe_archive_single_init(([
                            B_TYPE : "zfe_archive_single",
                            ZFE_OPTIONS : options,
                            ZFE_INDEX: index,
                            ZFE_ERRNUM: errnum ])) });
                    }
                }
             }
         }
         break;
    default:
            if (sizeof(menues)>1)
                {
                    return menues[..<2] + ({ 
                        zfe_archive_single_init( menues[<1]) });
                }
                else
                {
                    return ({ zfe_archive_single_init( menues[<1]) });
                }
    }
    menues[<1][B_FLAGS] &= ~BF_DIRTY;
    return menues;
}

static mixed zfe_archive_single_search_forward(mapping menue)
{
    if (!mappingp(menue) )
        return 0;
    int start = menue[B_CURRENT_LINE]+1;
    mixed * content = menue[B_DATA];
    int end = sizeof(content);
    int i;
    string search = menue[B_SEARCH_STRING];
    if (start > sizeof(content) || !stringp(search) || !sizeof(search))
        return 0;
    if (start < 0)
        start = 0;
    if (end <= start) 
        return 0;
    for (i=start; i < end ;i++)
    {
         if (strstr( content[i], search)!=-1)
         {
             menue[B_CURRENT_LINE] = i;
             return menue;
         }
    }
    return 0; // nicht gefunden
}

static string * zfe_archive_single_display(mapping menue)
{
    if (!mappingp(menue) )
        return 0;
    int start = menue[B_CURRENT_LINE];
    int end = start + menue[B_NUM_LINES];
    string * content = menue[B_DATA];
    if (start > sizeof(content))
        return 0;
    if (end >= sizeof(content))
        end = sizeof(content)-1;
    if (start < 0)
        start = 0;
    if (end < start)
        return 0;
    return content[start..end];
}

static string zfe_archive_single_prompt(mapping menue)
{
    return "Archivierter Fehler "+menue[ZFE_ERRNUM]+" [M,w,+,-,z,q]";
}

static mixed zfe_archive_single_action(string str, mapping * menues)
{
    int ret,errnum,*times;
    string * data;
    string name;
    str = space(str);
    if (str=="") return B_NOTHING; // evtl anpassen.
    switch (str[0..0])
    {
    case "M":
        errnum = menues[<1][ZFE_ERRNUM];
        name = ERROR_ARCHIVE->get_errtext(errnum);
        times =  ERROR_ARCHIVE->get_timestamps(errnum);
        if (!name || !sizeof(times))
        {
            browse_write_line("Kein Fehler vorhanden, Mail nicht versand.");
        }
        data = explode(name,"\n");
        ret = times[0];
        MAILD->zfehler(this_player()->query_real_name(),
                       0,ret,data,EDB_ARCHIVE);
        browse_write_line("Mail wurde (nur) an Dich geschickt.");
        return B_DONE;
    case "w":
        if (sizeof(str)<2)
        {
            browse_write_line("Syntax: w <datei>");
            return B_DONE;
        }
        data = this_player()->compose_path(space(str[1..]),LAST);
        name = "/"+implode(data,"/");
        ret = write_file(name,implode(menues[<1][B_DATA],"\n"), 0);
        // immer datei Anhaengen.
        if (ret)  
            browse_write_line("Datei "+name+" geschrieben.");
        else
            browse_write_line("Datei "+name
                              +" konnte nicht beschrieben werden.");
        return B_DONE;
    case "q":
        zfe_last_errnum = menues;  // Option -g / -G
        return B_QUIT;
    case "z":
        if (sizeof(menues)>1)
        {
            menues = menues[..<2];
            menues[<1][B_FLAGS] |= BF_DIRTY;
        }
        else
        {
            browse_write_line("Es geht nicht weiter zurueck.\n");
            menues[<1][B_FLAGS] |= BF_NO_DISPLAY;
        }
        return menues;
    case "+":
    case "-":
            menues[<1][ZFE_GOTO] = str;
            menues[<1][B_FLAGS] |= BF_DIRTY;
            return menues;
    }
    return B_NOTHING;
}

// ---------------------------------------------------------------------------
static int zfe_abstract_total(mapping menue)
{
    return sizeof(menue[B_DATA]);;
}

static mixed zfe_abstract_init(mapping old)
{
    if (old[B_FLAGS] & BF_DIRTY) return old;
    DEBUG("zfe_abstract_init");

    mapping options = deep_copy(old[ZFE_OPTIONS]);
    int * errnums = old[ZFE_ERRNUM];
    int flags = old[ZFE_ZSF], ix =0, ret;
    string str,*data, *alldata;
    mixed eheader;
    mapping edata;
    alldata = ({ ZFE_MORE_LINE_HF });

    // TODO Groessenbegrenzung Arrays beruecksichtigen
    foreach (int errnum : errnums)
    {
        edata = 0;
        if (!pointerp(eheader = ERROR_DB->query_error_header(errnum)))
        {
            if (flags & ZFE_ZSF_ARCHIVE)
            {
                str = ERROR_ARCHIVE->get_errtext(errnum);
                if (stringp(str))
                {
                    alldata += explode(str,"\n") + ({ ZFE_MORE_LINE_HF });
                    continue;
                }
            }
            alldata += ({ "Kein Eintrag zu Fehlernummer "+errnum+".",
                         ZFE_MORE_LINE_HF});
            continue;
        }
        alldata += explode(get_errmsg_text(++ix,errnum),"\n");
        if (flags & ZFE_ZSF_INFOS)
        {
            data = get_info_text(errnum, &ret);
            if (ret)
            {
                alldata += ({ZFE_MORE_LINE_MI, data});
            }
            else
            {
                alldata +=  ({ZFE_MORE_LINE_MI }) + data;
            }
        }
        if (flags & ZFE_ZSF_TRACE)
        {
            data = get_trace_text(errnum, &ret);
            if (ret)
            {
                alldata += ({ZFE_MORE_LINE_MI, data});
            }
            else
            {
                alldata +=  ({ZFE_MORE_LINE_MI }) + data;
            }
        }
        alldata += ({ ZFE_MORE_LINE_HF });
    }
    
    old[B_DATA] = alldata;
    
    old[B_START_LINE] = 0;
    old[B_HEADER_LINES] = ({ "", "",
                             ZFE_MORE_LINE_MI, ZFE_MORE_LINE_MI });
    old[B_HELP] = ([ B_TYPE : B_DYNAMICMORE,
                         B_FILE : ZFE_BHELP("_abstract"),
                         B_PROMPT : "Hilfe zur Fehlerzusammenfassung",
                      ]);
    return old;
}

static mixed zfe_abstract_reload(mixed menues)
{
    mapping menue = menues[<1];
    DEBUG("zfe_abstract_reload");
    menue[B_FLAGS] &= ~BF_DIRTY;
    menue = zfe_abstract_init(menue);
    if (!mappingp(menue))
    {
        return menue;
    }
    menues[<1] = menue;
    return menues;
}

static string * zfe_abstract_display(mapping menue)
{
    if (!mappingp(menue) )
        return 0;
    int start = menue[B_CURRENT_LINE];
    int end = start + menue[B_NUM_LINES];
    string * content = menue[B_DATA];
    if (start > sizeof(content))
        return 0;
    if (end >= sizeof(content))
        end = sizeof(content)-1;
    if (start < 0)
        start = 0;
    if (end < start)
        return 0;
    return content[start..end];
}

static string zfe_abstract_prompt(mapping menue)
{
    return "Fehlerzusammenfassung [?,w,M,z,q]";
}

static mixed zfe_abstract_action(string str, mapping * menues)
{
    string name, * data;
    int ret;
    if ( (str=space(str))=="") return B_NOTHING;
    switch (str[0..0])
    {
    case "w":
        if (sizeof(str)<2)
        {
            browse_write_line("Syntax: w <datei>");
            return B_DONE;
        }
        data = this_player()->compose_path(space(str[1..]),LAST);
        name = "/"+implode(data,"/"); 
        ret = write_file(name,implode(menues[<1][B_DATA],"\n"), 0);
        // immer datei Anhaengen.
        if (ret)  
            browse_write_line("Datei "+name+" geschrieben.");
        else
            browse_write_line("Datei "+name
                              +" konnte nicht beschrieben werden.");
        return B_DONE;
    case "M":
        data = menues[<1][B_DATA];
        ret = time();
        MAILD->zfehler(this_player()->query_real_name(),
                       0,ret,data,EDB_ERRLIST);
        browse_write_line("Mail wurde (nur) an Dich geschickt.");
        return B_DONE;
    }
    return B_NOTHING;
}

#if 0
// ---------------------------------------------------------------------------
static int zfe_top_groups_total(mapping menue)
{
    return 0;
}

static mixed zfe_top_groups_init(mapping old)
{
    return old;
}

static mixed zfe_top_groups_reload(mixed menues)
{
    return menues;
}

static string * zfe_top_groups_display(mapping menue)
{
    return 0;
}

static string zfe_top_groups_prompt(mapping menue)
{
    return "[z,q]";
}

static mixed zfe_top_groups_action(string str, mapping * menues)
{
    return B_NOTHING;
}
#endif

