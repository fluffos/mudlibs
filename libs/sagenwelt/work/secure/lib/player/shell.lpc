/// @file shell.c
/// @brief basic shell handling
///
/// borrowed from lima
/// @author Rust
/// @version 0.1.0
/// @date 2016-01-29
/*
** shell.c -- shell handling for the user
**
** 95-Jul-07 Rust      :  original player shell
** 95-Jul-11 Deathblade:  created.
** 96-Jan-29 Deathblade:  moved to the user ob
** 16-Jan-29 Gwenhwyvar:  Modified for Sagenwelt
*/

#include <player/inp_sys.h>
#include <player/messages.h>

// The actuall shell object we're using
nosave private object shell_ob;

public nomask object query_shell_ob()
{
    return shell_ob;
}

protected nomask void start_shell()
{
    if(!shell_ob)
        shell_ob = new(creatorp(TO()) ? WIZ_SHELL : PLYR_SHELL);

    shell_ob->start_shell();
    update_translations();
}

protected nomask void stop_shell()
{
    if(shell_ob)
        destruct(shell_ob);
}

protected nomask void run_login_script()
{
    string login_file,
           uid;

    if(!creatorp(TO()))
        return;

    // do .login stuff
    uid = getuid(TO());
    login_file = HOME_DIR(uid) + ".login";
    if(file_size(login_file) > 0)
        map_array(explode(read_file(login_file), "\n"), (: force_me :));
}
