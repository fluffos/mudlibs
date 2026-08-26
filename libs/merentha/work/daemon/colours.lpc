// Petrarch
// Merentha Lib 1.0
// colour daemon

#include <std.h>

inherit DAEMON;

#define ANSI(x) sprintf("%c["+(x)+"m",27)

mapping ansi_set=([
"RESET":ANSI("0;37;40"),
"BOLD":ANSI(1),
"FLASH":ANSI(5),
"BLACK":ANSI(30),
"RED":ANSI(31),
"GREEN":ANSI(32),
"ORANGE":ANSI(33),
"BLUE":ANSI(34),
"MAGENTA":ANSI(35),
"CYAN":ANSI(36),
"WHITE":ANSI(37),
"BBLACK":ANSI("1;30"),
"BRED":ANSI("1;31"),
"BGREEN":ANSI("1;32"),
"BORANGE":ANSI("1;33"),
"YELLOW":ANSI("1;33"),
"BBLUE":ANSI("1;34"),
"BMAGENTA":ANSI("1;35"),
"BCYAN":ANSI("1;36"),
"BWHITE":ANSI("1;37"),
"B_BLACK":ANSI(40),
"B_RED":ANSI(41),
"B_GREEN":ANSI(42),
"B_ORANGE":ANSI(43),
"B_BLUE":ANSI(44),
"B_MAGENTA":ANSI(45),
"B_CYAN":ANSI(46),
"B_WHITE":ANSI(47)
]);

mapping query_ansi() { 
return ansi_set;
}

