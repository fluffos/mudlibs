#ifndef _sys_filter_h
#define _sys_filter_h

#define F_NAME                  "name"
#define F_SHORT                 "short"
#define F_LONG                  "long"
#define F_ID                    "id"
#define F_ID_CLOSURE            "id_closure"
#define F_GENDER                "gender"
#define F_HIDE_INV              "hide_inv"
#define F_STR                   "str"
#define F_INT                   "int"
#define F_DEX                   "dex"
#define F_STA                   "sta"
#define F_STE                   "ste"
#define F_LUC                   "luc"
#define F_CHA                   "cha"
#define F_PIE                   "pie"
#define F_WIL                   "wil"
#define F_MAG                   "mag"
#define F_MMIN                  "mmin"
#define F_MMOUT                 "mmout"
#define F_MIN                   "min"
#define F_MOUT                  "mout"
#define F_STATE                 "state"
#define F_ALIGNMENT             "alignment"
#define F_AL_TITLE              "al_title"
#define F_PRETITLE              "pretitle"
#define F_TITLE                 "title"
#define F_NO_ARTICLE            "no_article"
#define F_EXTENDED_LONG         "extended_long"
#define F_DARKNESS              "darkness"
#define F_BRIGHTNESS            "brightness"
#define F_REGENERATION_RATE     "regeneration_rate"
#define F_REGENERATION_MODE     "regeneration_mode"
#define F_INTERVAL_BETWEEN_HEALING "interval_between_healing"
#define F_SMELL                 "smell"
#define F_TASTE                 "taste"
#define F_SOUND                 "sound"

#define F_ALL_FILTERS \
({ F_NAME, F_SHORT, F_LONG, F_ID, F_ID_CLOSURE, F_GENDER, F_HIDE_INV,   \
   F_STR, F_INT, F_DEX, F_STA, F_STE, F_LUC, F_CHA, F_PIE, F_WIL, F_MAG, \
   F_MMIN, F_MMOUT, F_MIN, F_MOUT, F_STATE, F_ALIGNMENT, F_AL_TITLE,    \
   F_PRETITLE, F_TITLE, F_NO_ARTICLE, F_EXTENDED_LONG, F_DARKNESS,      \
   F_BRIGHTNESS, F_SMELL, F_TASTE, F_SOUND, F_REGENERATION_RATE,        \
   F_INTERVAL_BETWEEN_HEALING,                                          \
   })

#define FPRIO_POLYMORPH         10000
#define FPRIO_DISGUISE          20000
#define FPRIO_PETRIFICATION     25000
#define FPRIO_INVISIBLE         30000

#endif
