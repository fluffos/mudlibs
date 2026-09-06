/*----------------------------------------------------------------------*/
/* The Xtool - Copyright 1992 by Hyp                                    */
/*                                                                      */
/* File: xtool.lib.h                                                    */
/*----------------------------------------------------------------------*/

#include "dependencies.h"

#if MUD_NF
inherit "/obj/tool/xtool/xtool.lib";
#endif
#if MUD_MG || MUD_BB || MUD_TM
inherit "players/hyp/tool/xtool/xtool.lib";
#endif
#if MUD_TA
inherit "w/hyp/tool/xtool/xtool.lib";
#else
#endif

#define NEW_ALIST ({({}),({})})

mixed *remove_alist(mixed key, mixed *alist);
string short_path(string file);
string long_path(string file);
string pure_object_name(object obj);
string source_object_name(object obj);
string *old_explode(string str, string del);
string *new_explode(string str, string del);
string *strip_explode(string str, string del);
string *long_get_dir(string pat, int all);
int string_compare(string str1, string str2);
string string_replace(string str, string old, string new);
string lit_string(string str);
string mixed_to_string(mixed mix, int level);
int is_player(object obj);
int is_not_player(object obj);
int is_living(object obj);
int is_not_living(object obj);
int is_netdead(object obj);
int is_alive(object obj);
int is_snoopee(object who);
int is_nosnoop(object who);
int is_invis(object who);
int is_visib(object who);
