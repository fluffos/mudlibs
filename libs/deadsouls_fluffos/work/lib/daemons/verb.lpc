/*    /lib/verb.c
 *    From the Dead Souls Mud Library
 *    An inheritable for creating verbs
 *    Created by Descartes of Borg 960116
 *    Version: @(#) verb.c 1.2@(#)
 *    Last modified: 96/12/17
 */

#include <lib.h>
#include "include/verb.h"

inherit LIB_DAEMON;
inherit LIB_HELP;

private string Verb, ErrorMessage;
private string *Synonyms, *Rules;

protected void create(){
    daemon::create();
    SetNoClean(1);
    parse_init();
    Verb = 0;
    ErrorMessage = 0;
    Rules = ({});
    Synonyms = ({});
}

nosave string SetErrorMessage(string str){ return (ErrorMessage = str); }

string GetErrorMessage(){ return ErrorMessage; }

varargs protected string *SetRules(mixed *args...){
    if( sizeof(Rules) ) error("Cannot reset rules list.");
    foreach(mixed arg in args){
        if( stringp(arg) ) Rules += ({ arg });
        else Rules += arg;
    }
    if( Verb ){
        foreach(string rule in Rules) parse_add_rule(Verb, rule);
        if( sizeof(Synonyms) ) 
            foreach(string cmd in Synonyms) parse_add_synonym(cmd, Verb);
    }
    return Rules;
}

string *GetRules(){ return copy(Rules); }

varargs protected string *SetSynonyms(mixed *args...){
    if( sizeof(Synonyms) ) error("Cannot reset synonym list.\n");
    foreach(mixed arg in args){
        if( stringp(arg) ) Synonyms += ({ arg });
        else Synonyms += arg;
    }
    if( Verb && sizeof(Rules) )
        foreach(string cmd in Synonyms) parse_add_synonym(cmd, Verb);
    return Synonyms;
}

string *GetSynonyms(){ return copy(Synonyms); }

protected string SetVerb(string str){
    if( !stringp(str) ) error("Bad argument 1 to SetVerb().\n");
    Verb = str;
    if( sizeof(Rules) )
        foreach(string rule in Rules) parse_add_rule(Verb, rule);
    if( sizeof(Synonyms) )
        foreach(string cmd in Synonyms) parse_add_synonym(cmd, Verb);
    return Verb;
}

string GetVerb(){ return Verb; }

string *GetVerbs(){ return ({ Verb }); }

