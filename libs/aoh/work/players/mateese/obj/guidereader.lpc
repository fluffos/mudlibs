/* Guide Reader -- Mateese, 10-Dec-92
**
** To reduce the copyright problems with the online copy of the Guide,
** it is accessible only through this object.
** The files are expected in the directory ~<my_euid>/secure/guide<number>/,
** with <number> ranging from 1 to 5.
** The files themselves are named 'prolog', 'ch<no>' and 'epilog', with <no>
** ranging from 1 upwards.
*/

#include <config.h>

#define ME this_object()
#define COUNTBOOKS 5

create () {
  if (member(file_name(ME), '#') != -1 || !seteuid(getuid(ME)))
    destruct (ME); 
}

clean_up (int is_papa) {
  if (!is_papa) destruct (ME);
  return 1;
}

CountBooks () { return COUNTBOOKS; }

ReadTitle (int book) {
  if (book < 1 || book > COUNTBOOKS)
    return "A wrongness in the space-time continuum";
  return ({ "The Hitch Hiker's Guide to the Galaxy"
          , "The Restaurant at the End of the Universe"
          , "Life, Universe, and Everything"
          , "So long and thanks for all the fish"
          , "Mostly Harmless"  /* Thanks, Jhary! */
          })[book-1];
}

ReadProlog (int buch) {
  string name;
  name = WPATH+geteuid(ME)+"/secure/guide"+buch+"/prolog";
  if (file_size (name) > 0) return read_file (name);
  return 0;
}

ReadChapter (int buch, int chapter) {
  string name;
  name = WPATH+geteuid(ME)+"/secure/guide"+buch+"/ch"+chapter;
  if (file_size (name) > 0) return read_file (name);
  return 0;
}

ReadEpilog (int buch) {
  string name;
  name = WPATH+geteuid(ME)+"/secure/guide"+buch+"/epilog";
  if (file_size (name) > 0) return read_file (name);
  return 0;
}
