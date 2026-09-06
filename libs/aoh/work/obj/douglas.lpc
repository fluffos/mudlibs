/* Douglas Adams  (Mateese, 10-Dec-92)
**
** Douglas Adams sits in a separee of the Restaurant in the Middle of
** Nowhere and reads from his books.
**
** [01-Feb-97] Moved the Guide data from ~mateese into ~patchman. [Mateese]
*/

#include <properties.h>   /* for the property names */

#define GUIDEOBJ "/players/patchman/obj/guidereader"
#define ME this_object()
#define PL this_player()

#define PUTTES_SAY /* puttes say() can't handle more than 256 chars */

#define TIME_READ 20  /* min seconds between two readings */
#define LINES_READ 5  /* Lines to read per reading */
#define LINES_MAX 10

inherit "/std/npc";

nosave string *text;
nosave int actline, book, chapter, lastline;

string start_new_book();

/*-------------------------------------------------------------------------*/
void create () {

  ::create();

    /* Initialize Name = Short and Long description */
  SetName ("Douglas");
  SetLong (
 "This is Douglas, a well known author from another dimension.\n"
+"He is a tall man, with curly dark hair. Obviously he's having\n"
+"a good time sitting here, drinking his beer and reading from\n"
+"his books.\n"
          );
  SetRace ("human");
  SetGender (1);
  SetWimpy (QueryMaxHP());
  SetGoChance(0);
  SetWeight (75000);
  book = random(({int})GUIDEOBJ->CountBooks())+1;
  if (start_new_book())
  {
    chapter = random(20)-1;
    call_out ("read_on", TIME_READ);
  }
}

/* Ignore and stop any attacks against us */
varargs int Defend (int dam, int dam_type) {
  if (PL) {
    PL->StopAttack();
    write (" but Douglas backs off\n"
           +"and bellows: 'No fighting here!'. Ashamed you turn away.\n");
    tell_room (environment(ME), " but Douglas backs off\n"
               +"and bellows: 'No fighting here!'. Ashamed turns "
               +(({string})PL->QueryName())+" away.\n", ({ PL }));
  }
  return 0;
}

int QueryNoGet() { return 1; }

int clean_up (int is_papa) {
  if (!is_papa) ::remove();
  return 1;
}

/*-------------------------------------------------------------------------*/
string start_new_book() {
  int cbooks;
  string ftext;

  cbooks = ({int})GUIDEOBJ->CountBooks();
  book = (book % cbooks) + 1; /* *grin* */
  say ("Douglas drops a book and takes another one.\n");
  say ("\nDouglas announces: ``"+(({string})GUIDEOBJ->ReadTitle (book))+"''\n");
  if (ftext = ({string})GUIDEOBJ->ReadProlog (book)) {
    chapter = 0;
    say ("\nDouglas says: -- Prolog --\n");
    return ftext;
  }
  if (ftext = ({string})GUIDEOBJ->ReadChapter (book, 1)) {
    chapter = 1;
    say ("\nDouglas says: -- Chapter 1 --\n");
    return ftext;
  }
  say ("Douglas looks puzzled on unexpectetly empty pages.\n");
  return 0;
}

void read_on () {
  int line, nolines;
  string out;

  remove_call_out ("read_on");
  if (!text || actline >= sizeof(text)) { /* Load next chapter */
    string ftext;
    int what;
    while (!ftext) {
      if (++chapter < 1) ftext = start_new_book();
      else if (ftext = ({string})GUIDEOBJ->ReadChapter (book, chapter))
        say ("\nDouglas says: -- Chapter "+chapter+" --\n");
      else if (ftext = ({string})GUIDEOBJ->ReadEpilog (book))
        say ("\nDouglas says: -- Epilog --\n");
      else ftext = start_new_book();
    }
    actline = 0; text = explode (ftext, "\n"); lastline = sizeof(text);
  }
  while (actline < lastline && text[actline] == "") actline++;
  if (actline >= lastline) read_on();
  line = (line = actline + LINES_READ-1) < lastline ? line : lastline-1;
  if (text[line] == "" || text[line-1] == "")
    while (line > actline && text[line] == "") line--;
  else {
    int line2;
    line2 = line;
    while (line2 < lastline && line2 < actline + LINES_MAX
           && text[line2] != "") line2++;
    if (line2 < lastline) line2--;
    if (line2 - actline + 1 <= LINES_MAX) line = line2;
  }
  if (line >= lastline) line = lastline-1;
  if (random(100) < 10)
    out = ({ "Douglas empties his beer and reads on:\n"
           , "Douglas downs another arcturan mega-ale and reads on:\n"
           , "A mug of romulan ale pours down Douglas' throat, "
            +"then he reads on:\n"
           , "After catching breath, Douglas reads on:\n"
           , "Douglas turns a page and reads on:\n"
	    })[random(4)];
  else out = "Douglas reads on:\n";
  if ((nolines = line - actline - LINES_READ) < 0) nolines = 0;
#ifndef PUTTES_SAY
  efun::say ( out+"  "+(implode (text[actline..line], "\n  ")) + "\n");
  actline = line+1;
#else
  efun::say (out);
  while (actline <= line) efun::say ("  "+text[actline++]+"\n");
#endif
  call_out ("read_on", TIME_READ + nolines * 5);
}

/*************************************************************************/
