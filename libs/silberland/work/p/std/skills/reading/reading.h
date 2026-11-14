// properties
#define BOOKMASTER "/p/std/skills/reading/bookmaster"

// (string) buch id, wie im master registriert. wenn nicht gesetzt oder 0 wird
// automatisch der filename des buchs verwendet
#define P_BOOK_ID "book_id"

// wie "schwer" ist das buch zu verstehen (-10000 superleicht, 0 normal
// 10000 unverstaendlich) (int)
#define P_BOOK_DIFFICULTY "book_difficulty"

// texte, die an den spieler beim lesen ausgegeben werden (array)
#define P_BOOK_TEXTS "book_texts"

// wie gut kann man an dem buch lernen (-10000 sehr schwer, 0 normal
// 10000 perfektes lerbuch)
#define P_BOOK_LEARN "book_learn"

// in diesem objekt wird die funktion "ReadSuccessFunc" bei leseerfolg
// aufgerufen
#define P_BOOK_SUCCESS_FUNC "book_success_func"

// in diesem objekt wird die funktion "ReadFailFunc" bei lesefehlschlag
// aufgerufen
#define P_BOOK_FAIL_FUNC "book_fail_func"

// die wahrscheinlichkeit, dass das Buch durchs Lesen zerstoert wird
// (int = prozent)
#define P_BOOK_DESTRUCT_CHANCE "book_destruct_chance"

// bis zu diesem skillwert kann man mit dem buch maximal lernen
#define P_BOOK_MAX_LEARN "book_max_learn"

// nachrichten die ausgegeben werden, wenn eine passage nicht verstanden wird (string array)
#define P_BOOK_NONREADABLE_PSSAGES "book_nonread_passages"

// nachricht, die an den spieler ausgegeben wird, wenn er das buch erfolgreich gelesen
// hat (string)
#define P_BOOK_SUCCESS_MESSAGE "book_success_message"

// nachricht fuer den spieler, wenn er das buch nicht erfolgreich lesen konnte (string)
#define P_BOOK_FAIL_MESSAGE "book_fail_message"

// return codes des master
#define BM_RET_OK 1 // genereller erflog
#define BM_RET_READ 2 // Buch bereits gelesen
#define BM_RET_FAIL 0 // genereller misserfolg
#define BM_RET_NOT_READ 0 // buch noch nicht gelesen

#define READ_OBJ(x) "/p/std/skills/reading/obj/"+x
#define READ_FUNC(x) "/p/std/skills/reading/func/"+x