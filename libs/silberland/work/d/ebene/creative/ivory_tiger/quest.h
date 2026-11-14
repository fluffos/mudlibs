// quest.h
// ivory tiger quest

#ifndef __IVORY_TIGER_QUEST_H__
#define __IVORY_TIGER_QUEST_H__

#define IV_QUEST_START   0   // Quest begonnen
#define IV_FILL_PEN      1   // Feder tunken
#define IV_GET_NOTEPAD   2   // Block holen
#define IV_COPY_BOOK     3   // Buch kopieren
#define IV_GIVE_BOOK     4   // Block Vannor geben
#define IV_GET_RAZOR     5   // Rasiermesser holen
#define IV_GET_MOSS      6   // Moos holen
#define IV_FILL_BOTTLE   7   // Flasche fuellen
#define IV_GET_YARI      8   // Yari geholt
#define IV_GET_KETTLE    9   // Kessel holen
#define IV_INSERT_MOSS  10   // Moos in Kessel
#define IV_INSERT_WATER 11   // Wasser in Kessel
#define IV_GET_LANTERN  12   // Laterne geholt
#define IV_MAKE_TINDER  13   // Zunder gebastelt
#define IV_INFLAME_COAL 14   // Kohle entzuendet
#define IV_COOK_MOSS    15   // Einheizen
#define IV_GET_POT      16   // Tiegel holen
#define IV_POWDER2POT   17   // Moospulver in Tiegel
#define IV_FAT2POT      18   // Fett in Tiegel
#define IV_MASH_HEART   19   // Eisherz zerbroeseln in Moerser
#define IV_HEART2POT    20   // Eisherzpulver in Tiegel
#define IV_GIVE_POT     21   // Tiegel an Vannor

#define IV_MAX_QUEST_FLAGS 22

// quest relevant items

#define IV_QUEST_ITEM   "iv_feathe\r"
#define IV_BEARD        "iv_bea\rd"
#define IV_RECIPE_UNID  "iv_\recipe_unid"
#define IV_RECIPE_ID    "iv_\recipe_id"
#define IV_POT          "iv_po\t"
#define IV_MOSS         "\niv_moss"
#define IV_MOSSPOWDER   "iv_moss_powde\r"
#define IV_FAT          "iv_fa\t"
#define IV_HEARTPOWDER  "iv_hea\rt_powder"
#define IV_BOTTLE       "iv_bo\ttle"
#define IV_KETTLE       "iv_ke\ttle"
#define IV_NOTEPAD      "iv_\notepad"
#define IV_LANTERN      "iv_la\ntern"
#define IV_HEART        "iv_hea\rt"
#define IV_RAZOR        "iv_\razor"
#define IV_QUEST_YARI   "iv_quest_ya\ri"

// keys

#define IV_GENERAL_KEY "iv_gene\ral_key"
#define IV_CASHIER_KEY "iv_cashie\r_key"
#define IV_AB3_KEY     "\niv_ab3_key"
#define IV_BC3_KEY     "\niv_bc3_key"
#define IV_CD3_KEY     "\niv_cd3_key"
#define IV_E5_KEY      "\niv_e5_key"
#define IV_HI4_KEY     "\niv_hi4_key"
#define IV_JK4_KEY     "\niv_jk4_key"
#define IV_L45_KEY     "\niv_l45_key"
#define IV_N34_KEY     "\niv_n34_key"
#define IV_N45_KEY     "\niv_n45_key"

// quest irrelevant items

#define IV_STATUE       "iv_s\tatue"
#define IV_LOCKPICKNOTE "iv_lockpick_\note"
#define IV_BOOZE_MUG    "\niv_booze_mug"
#define IV_TIE_PIN      "iv_tie_pi\n"
#define IV_HAIRSTYLE    "\nfrisur"
#define IV_IMBUE        "iv_im\bue"
#define IV_BALM         "iv_\balm"
#define IV_CANDY        "iv_ca\ndy"
#define IV_CANDY_SMALL  "iv_ca\ndy_small"
#define IV_SNUFFBOX     "iv_s\nuffbox"
#define IV_SNUFF        "iv_s\nuff"

// erlaubte items fuer set_flag in questobj
#define IV_ALLOWED_FILES ({\
    "/d/ebene/creative/feldlager/obj/urne",\
    "/d/dschungel/feyaria/tijara/npc/elsurion",\
    })

// miscellaneous

#define IV_QUEST "Das Vermaechtnis der Tigergilde"
#define IV_LOGQUEST(o,s) write_file(LOG(o+".log"), ctime(time())+": "+s+"\n")

#endif /* __IVORY_TIGER_QUEST_H__ */
