/* This room now implements a simple library mechanism.
** All libfiles are collected in LIBPATH. Also there is a file 'INDEX',
** whose linetriplets each describe one libfile, the first line being the 
** libfile's keyword, the second line some sort of content description, and 
** the third the filename.
** The headlines are listed at the 'index' command, the approbiate files
** may then be more'd. 
** If a given filename doesn't begin with '/', LIBPATH will be prepended.
** The index is contained inside the room object, but will update to the
** file automagically if necessary.
*/

inherit "d/archwiz/common/std/room";
#include <properties.h>

#define LIBPATH "/d/archwiz/common/lpc/lib/"

string *index;    /* ({ headlines }) */
string *lkey;     /* ({ keywords  }) */
string *lfile;    /* ({ filenames }) */
int    *lsize;    /* ({ filesizes }) */
string *ldate;    /* ({ filedates }) */
int ix_date;

string spaces; 

/*-------------------------------------------------------------------------*/
void create() {
	
  ::create();
    
  SetIntShort("LPC Library");
  SetIntLong(
"You are in the LPC Library. The room is filled with many books and lists.\n" +
"To the east you can leave the room through a noble hallway.\n" +
"There are some addresses scribbled at the wall:\n" +
"  'ftp    nova.tat.physik.uni-tuebingen.de 4243 (134.2.62.157 4243)'\n"+
"  'ftp    ftp.cd.chalmers.se                    (129.16.79.30)'\n"+
"  'ftp    ftp.lysator.liu.se                    (130.236.254.153)'\n"+
"  'ftp    ftp.cs.tu-berlin.de                   (130.149.17.7)'\n"+
"  'ftp    ftp.tu-bs.de                          (134.169.34.15)'\n"+
"  'ftp    ftp.gmd.de                            (129.26.8.90)'\n"+
"Maybe you should type 'help library' ?\n"
             );

  AddExit("east", "/d/archwiz/common/lpc/office");
  AddRoomCmd ("help", "fhelp");
  AddRoomCmd ("index", "findex");
  AddRoomCmd ("read", "fread");
  /* SetIntLight(1); */

  index = ({ });
  lkey  = ({ });
  lfile = ({ });
  lsize = ({ });
  ldate = ({ });
  spaces = "                                                                              ";
}

/*-------------------------------------------------------------------------
** Stringformatting
*/

string ladjust (string str, int len) {
  if (strlen(str) >= len) return str;
  return (str+spaces)[0..len-1];
}

string ladjcut (string str, int len) {
  return (str+spaces)[0..len-1];
}

string radjust (string str, int len) {
  if (strlen(str) >= len) 
    return str;
  str = spaces+str;
  return str[<len..];
}

string radjcut (string str, int len) {
  str = spaces+str;
  return str[<len..];
}

string cutlen (string str, int len) {
  if (strlen(str) <= len) return str;
  return str[0..len-1];
}


/*-------------------------------------------------------------------------
** Refresh our index array if necessary 
*/

_refr_index() {
  int date, i, size;
  string line1, line2, line3, cdate, fname;
  fname = LIBPATH+"INDEX";
  if ((date = file_date(fname)) <= ix_date) return;
  ix_date = date; 
  index = ({ }); lkey = ({ }); lfile = ({ }); lsize = ({ }); ldate = ({ });
  if (file_size(fname) <= 0) return;
  i = 1;
  while (line1 = read_file (fname, i++, 1)) {
    if (line1 == "") continue;
    if (   (line2 = read_file (fname, i++, 1)) 
        && (line3 = read_file (fname, i++, 1)) ) {
        /* Remove trailing '\n' */
      line1 = line1[0..<2];
      line2 = line2[0..<2];
      line3 = line3[0..<2];
      if (line3[0] != '/') line3 = LIBPATH+line3;
      if ((size = file_size(line3)) > 0) {
        lkey  += ({ line1 });
        index += ({ line2 });
        lfile += ({ line3 });
        lsize += ({ size });
        cdate = ctime(file_date(line3));
        ldate += ({ cdate[8..9]+"-"+cdate[4..6]+"-"+cdate[20..23] });
      }
      else line2 = 0; /* Hidden flag that there has been an error. */
    }
    if (!line2 || !line3)
      write ("Warning: Bogus index at line "+(i-1)+"!\n");
  } /* while */
  if (!line1) write ("(Index refreshed.)\n");
}


/*-------------------------------------------------------------------------
/* Give some help */

fhelp(str) {
  if (!str || (str != "library" && str != "lib")) return 0;
  write (
"The library contains several articles and notes about various aspects\n"+
"of LPC. To get an overview of the existing articles, type 'index'.\n"+
"With 'index files' also the names of the libfiles are given.\n"+
"To read a specific article, type 'read [lib] <id>' where <id> is \n"+
"either the index number of the article, or the keystring printed with\n"+
"the index.\n"
        );
  return 1;
}


/*-------------------------------------------------------------------------
** Print our index 
*/

findex(str) {
  int i, size;
  if (str && str != "files") return 0;
  _refr_index();
  if (!(size = sizeof(lkey))) {
    write ("Sorry, no articles available.\n");
    return 1;
  }
  for (i = 0; i < size; i++) {
    write(radjust(""+(i+1),3)+".   "+ladjust(lkey[i],20)+"   ("+ldate[i]+", ");
    write (lsize[i]+" bytes)\n");
    write ("     "+index[i]+"\n");
    if (str) write ("     File: "+lfile[i]+"\n");
  }
  return 1;
}

 
/*-------------------------------------------------------------------------
** Print an article
*/

fread (str) {
  int ix, size;
  string key, arg;

  if (!str) return 0;
  if (!sscanf (str, "lib %s", arg)) arg = str;
  _refr_index();
  size = sizeof(lkey);
  if (sscanf (arg, "%d", ix) && arg == ""+ix) {
    if (ix < 1 || ix > size) {
      write ("Illegal article number.\n");
      return 1;
    }
    ix--;
  } else {
    ix = member(lkey, arg);
    if (ix < 0) {
      write ("Unknown keyword '"+arg+"'.\n");
      return 1;
    }
  }
  write ("--- "+lfile[ix]+"   ("+ldate[ix]+", "+lsize[ix]+" bytes) ---\n");
  this_player()->more(lfile[ix]);
  return 1;
}
