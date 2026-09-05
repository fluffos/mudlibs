/// @addtogroup sefun
/// @{
/// @file simul_efun.c
/// @brief simulated efuns
/// @author Gwenhwyvar
/// @version 0.2.0
/// @date 2016-04-03

#include    <simul_efun.h>
#include    <simul_efun_intern.h>

#include    SEFUN_DIR "arrays"
#include    SEFUN_DIR "communication"
#include    SEFUN_DIR "driver"
#include    SEFUN_DIR "file_system"
#include    SEFUN_DIR "general"
#include    SEFUN_DIR "logging"
#include    SEFUN_DIR "math"
#include    SEFUN_DIR "objects"
#include    SEFUN_DIR "passwd"
#include    SEFUN_DIR "regex_globbing"
#include    SEFUN_DIR "room"
#include    SEFUN_DIR "security"
#include    SEFUN_DIR "strings"
#include    SEFUN_DIR "terminal"

private int startup_finished;

private void create(void)
{
    startup_finished = FALSE;

    init_object_efuns();
    init_terminal_efuns();
    initialize_regex_globbing();
}

public void done_startup(void)
{
    startup_finished = TRUE;
}

// event handler
public void event_destruct(void)
{
    if(origin() != ORIGIN_EFUN)
        return;
}

public void event_shutdown(void)
{
    if(origin() != ORIGIN_EFUN)
        return;
}

/// @}
