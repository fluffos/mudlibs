#include <dirs.h>

void
log_file(string filename, string logMsg)
{
  filename = LOG_DIR "/" + filename;
  
  unguarded((: write_file($(filename), ctime(time())+": " + $(logMsg)) :), 1);
}
