/*-----------------------------------------------------------------------------\
| Hotarus Defines                                      (C) by Hotaru, 01.08.01 |
\-----------------------------------------------------------------------------*/

#define MyCountUp(arg) (sizeof(arg) > 1 ? \
          implode(arg[0..<2], ", ") + " und " + arg[<1] : \
          (sizeof(arg) == 0 ? "keine" : arg[0]) )
#define MyBS(arg) (strstr(arg,"$",0) == -1 ? \
          break_string(arg, 78, 0, BS_LEAVE_MY_LFS) : \
          break_string(arg[strstr(arg,"$",0)+1..], 78, \
          arg[0..strstr(arg,"$",0)-1], BS_LEAVE_MY_LFS) )
#define CutDotC(arg) (arg[<2..] == ".lpc" ? arg[0..<3] : arg)

// ASCII conversion stuff
#define asc(arg) (arg[0])
#define chr(arg) (sprintf("%c", arg))

// Master paths
#define WAY_MASTER   "/d/ebene/hotaru/master/waymaster"
#define NAME_MASTER  "/d/ebene/hotaru/master/namemaster"
#define HELP_MASTER  "/d/ebene/hotaru/master/helpmaster"
#define SOUNDEX      "/d/ebene/hotaru/master/soundex"
#define FUZZY_MASTER "/d/ebene/hotaru/master/fuzzymaster"
