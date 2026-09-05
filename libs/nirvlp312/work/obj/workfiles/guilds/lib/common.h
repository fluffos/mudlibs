/*
 * common.h
 *
 * Some quick little macros for my code.
 */
#define QRD            query_root_dir()
#define extendRoot(x)  QRD+x+"/"
#define PO             previous_object()
#define TP             this_player()
#define TO     this_object()
#define ENV    environment()
#define RN     query_real_name()
#define ERN    (string)ENV->RN

#define V_TESTING

void tell_v(string msg) { tell_object(find_player("vertebraker"), msg); }
