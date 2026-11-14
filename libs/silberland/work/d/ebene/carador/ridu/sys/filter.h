#ifndef _sys_filter_h
#define _sys_filter_h

#define F_NAME "name"
#define F_SHORT "short"
#define F_LONG "long"
#define F_ID "id"
#define F_ID_CLOSURE "id_closure"
#define F_GENDER "gender"
#define F_HIDE_INV "hide_inv"
#define F_STR "str" // new filters inserted by Ugh on Nov-11-93
#define F_INT "int"
#define F_DEX "dex"
#define F_CON "con"
#define F_MMIN "mmin"
#define F_MMOUT "mmout"
#define F_MIN "min"
#define F_MOUT "mout"
#define F_STATE "state"
#define F_ALIGNMENT "alignment"
#define F_AL_TITLE "al_title"
#define F_PRETITLE "pretitle"
#define F_TITLE "title"
#define F_NO_ARTICLE "no_article"
#define F_EXTENDED_LONG "extended_long"
#define F_DARKNESS "darkness"
#define F_BRIGHTNESS "brightness"

// Alfe 96-Mar-12
#define F_ALL_FILTERS \
({ F_NAME,F_SHORT,F_LONG,F_ID,F_ID_CLOSURE,F_GENDER,F_HIDE_INV,F_STR,F_INT, \
   F_DEX,F_CON,F_MMIN,F_MMOUT,F_MIN,F_MOUT,F_STATE,F_ALIGNMENT,F_AL_TITLE, \
   F_PRETITLE,F_TITLE,F_NO_ARTICLE,F_EXTENDED_LONG,F_DARKNESS,F_BRIGHTNESS })

#define FPRIO_POLYMORPH 10000
#define FPRIO_DISGUISE 20000
#define FPRIO_PETRIFICATION 25000
#define FPRIO_INVISIBLE 30000

#endif
