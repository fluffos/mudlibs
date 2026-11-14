#include "../def.h"

#define MAGIERNAME "yara"
#define GEBIET "cocktailbar"

#undef LOG
#define LOG "wiz/yara/cocktailbar/"

#define debugMsg(str) if(find_player("yara")) \
                        tell_object(find_player("yara"), \
                                    "<DEBUG: "+(TO->Name(RAW)+">"||"Unbekannt>")+" "+str+"\n"); \
                      log_file("wiz/yara/debug.log", \
                                 ctime()+": "+("<"+TO->Name(RAW)+">"||"<Unbekannt>")+" "+str+"\n")