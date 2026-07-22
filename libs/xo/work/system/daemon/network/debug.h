#define SEND_DEBUG( x , m) if(find_player( x )) message("debug", format_string(replace_string(sprintf("%s:\n%O",__FILE__, m ),"\n","")) + "\n", find_player(x))

// You can use set nodebug 1 to avoid seeing debug info.

#ifdef DEBUG
#define NBUG(x) SEND_DEBUG("nerd", x)
#define LABUG(x) SEND_DEBUG("lala", x)  //天哪，叫l*的太多了。
#else
#define NBUG(x)
#define LABUG(x)
#endif //DEBUG
