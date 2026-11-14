// SQL Master (c) 2026 Aloy
// führt queries aus, erstellt db grundstruktur und pflegt updates ein

#define ROOT            "/p/daemon/sql/"
#define UPDATES         ROOT"updates/"
#define SQL             ROOT"sql"

#define SQL_LOG_FILE	"SQL"

#ifndef DATE
#define DATE            ctime(time())[4..15]
#endif

