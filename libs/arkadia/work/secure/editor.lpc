/*
 * /secure/editor.c
 *
 * This is the SECURITY part of the editor. It allows 'full' wizards to
 * import a file into the editor. To do this, it assumes the euid of the
 * wizard.
 *
 * The second use of this board is saving notes from boards. To do this,
 * it assumes the euid of the wizard.
 */

#pragma no_clone
#pragma no_inherit
#pragma no_shadow
#pragma resident
#pragma save_binary
#pragma strict_types

#include <filepath.h>
#include <files.h>
#include <macros.h>
#include <std.h>

/*
 * Function name: import
 * Description  : This function may be called from the editor if a wizard
 *                wants to import a file into the editor.
 * Arguments    : string file - the filename of the file to import.
 * Returns      : string      - the imported text.
 *                int 0       - in case of an error.
 */
nomask public string
import(string filename)
{
    if (!CALL_BY(EDITOR_OBJECT))
    {
	write("Illegal call. Not called by the editor!");
	return 0;
    }

    if ((!objectp(this_player())) ||
	(this_player() != this_interactive()))
    {
	write("Illegal interactive player. Cannot import.\n");
	return 0;
    }

    if (!strlen(filename))
    {
	write("No file name to import supplied. Cannot import.\n");
	return 0;
    }

    filename = FTPATH(this_interactive()->query_path(), filename);
    if (file_size(filename) <= 0)
    {
	write("No such file: " + filename + "\nCannot import.\n");
	return 0;
    }

    setuid();
    seteuid(getuid());

    /* We assume the euid of the wizard executing the command. */
    seteuid(getuid(this_interactive()));

    filename = read_file(filename);
    seteuid(0);

    return filename;
}

/*
 * Function name: board_write
 * Description  : This function can be called from a board when a wizard
 *                wants to store a message from a board in a file.
 * Arguments    : string filename - the file to store the text in.
 *                string text     - the text to store.
 * Returns      : int 1/0 - success/failure.
 */
nomask public int
board_write(string filename, string text)
{
    int result;

    if (function_exists("store_msg", previous_object()) != BOARD_OBJECT)
    {
	write("Illegal call! Not called by a bulletin board.\n");
	return 0;
    }

    if ((!objectp(this_player())) ||
	(this_player() != this_interactive()))
    {
	write("Illegal interactive player. Cannot import.\n");
	return 0;
    }

    filename = FTPATH(this_interactive()->query_path(), filename);
    if (file_size(filename) > 0)
    {
	write("File " + filename + " already exists.\n");
	return 0;
    }

    setuid();
    seteuid(getuid());

    seteuid(getuid(this_interactive()));
    if (result = write_file(filename, text))
    {
	write("Stored note in " + filename + "\n");
    }
    else
    {
	write("Failed to write file " + filename + "\n");
    }

    seteuid(0);
    return result;
}
