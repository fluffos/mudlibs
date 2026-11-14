 /* 
  * Unbekanntes Brettspiel, keine Ahnung wer das erfunden hat...
  *
  *                 .         ,       __       oo       _+
  *        |~       /)       (+       II       ()       []  
  *     -----------------------------------------------------
  *     --     see chess.h for full header information.    --
  *
  * Tja, hier haengen alle (wirklich alle) Methodendeklarationen,
  * teilweise weil es noetig ist, teilweise nur der Vollstaendigkeit
  * halber, aufgefuehrt. 
  *
  */


// Von "aussen" aufrufbare nicht-ererbte Methoden

public void UpdateSchemes();
public int AddListener(object o);
public int RemoveListener(object o);
public string * QueryListener();
public varargs void View(int force);
public varargs void ViewFormular(int flags, int last,int nonansi);

// oeffentliche Methoden, die vom Standard-Raum vererbt werden.
/*
public void create();
public int query_prevent_shadow(); 
public int clean_up(int ref);
public int remove();
public string GetExits();
public void heart_beat();
public void BecomesNetDead(object pl);
public string short();
public string _query_int_long();
public string long();
public varargs string GetDetail(mixed key, mixed race);
public varargs string GetSound(mixed key, mixed race);
public varargs string GetSmell(mixed key, mixed race);
public varargs int PreventInsert(object ob);
*/
// Special Details

nosave string detailUhr();
nosave string detailPartie();
nosave string detailAuf();
nosave string detailFormular();
nosave string detailBefehle();

// Kommandos

nosave int cmdZug(string str);
nosave int cmdHilfe(string str);
nosave int cmdSetze(string str);
nosave int cmdStehe(string str);
nosave int cmdSpiel(string str);

// Kommando "Spiel ..."

private nosave int doSpielAnzeige(string * args);
private nosave int doSpielAufraeumen();
private nosave int doSpielAufstellen(string str);
private nosave int doSpielUnterbrechen();
private nosave int doSpielFreigeben();
private nosave int doSpielAufgeben();
private nosave int doSpielFarbe(string str);

// Hi-Level-Handhabe

private nosave void doMessage(mixed msg);
private nosave varargs int boardInit(int without, int * blitz);
private nosave int checkOnSuspend(int who);
private nosave void saveGame();
private nosave int restoreGame();
private nosave void fileGame();
private nosave varargs int endGame(int suspension);

// Lowlevel-Schach

private nosave int is_board_remis();
private nosave varargs int mate(int pl,int stalemate);
private nosave int impossible_move(int fig, int from, int to);
private nosave varargs string * getFormularLines(int flags, int lines);
private nosave int * possible_moves(int fig, int from);
private nosave int is_threated(int pos, int by_col);
private nosave int * findThreatFigure(int fig, int to);
private nosave int is_check(int pl);
private nosave varargs int deniedRochade(int pl, int which);
private nosave varargs void killRochade(int pl, int which);
private nosave mapping changeMapping(int move_int);
private nosave string parseZug(string str, int pl);
private nosave varargs void evalMove(mapping move_map, int move_int);
private nosave void finishMove(int mv);
private nosave int tryMove(string str);

// Die Schachuhr...

private nosave varargs int getTime(int pl,int single);
private nosave varargs string getClockString(int pl,int single, int flags);
private nosave void switchClock(int to);

// Schemata-Geschichten

private nosave varargs void printSample(int col, int sty, int which, int e);
private nosave string getChosenColors();
private nosave int * getPositionArray(mixed * t);
private nosave int colorChooseFail();
private nosave int colorChooseSuccess(object * pl);

// Grafik

private nosave varargs string * getTableStrings(int flags, int which);
private nosave varargs string getTitleString(int flags, int nonansi);
private nosave string getStatusString(int flags, int which);
private nosave varargs string getView(int flags, int which);
private nosave varargs string getMoveString(int i, int alg);
private nosave varargs string figName(int fig, int casus, int demon);
private nosave varargs string getBlitzString(int * blitz);
private nosave int getPlayerFlags(object pl);

// Hilfesmethoden...

nosave void cleanUp();
private nosave varargs int writelog(string file, string log_txt, 
    int total_backups, int size_to_break);
private nosave varargs int fail(string s, int damneditisnotaboutthegame);
private nosave string objectsToString(object * arr, int casus);
private nosave object * presentLivings();
private nosave void checkPlayerObjects(object o);

