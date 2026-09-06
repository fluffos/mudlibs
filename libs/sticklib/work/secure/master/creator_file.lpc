
#pragma save_types

#define MASTER_OB "/secure/master"
#define ROOT_UID "root"
#define BACKBONE_UID "backbone"

/*
 * Function name:   creator_file
 * Description:     Gives the name of the creator of a file. This is a
 *                  direct function of the file_name().
 * Returns:         Name of the creator
 */
nomask string
creator_file(string str)
{
    string *xstr;

    xstr = explode(str + "/", "/");

    /*
     * No objects in /
     */
    if (sizeof(xstr) < 2) return 0;

    switch (xstr[0])
    {
	/*
	 * Independent wizards (old style): Return the name of the wizard.
	 */
    case "players":
	if (sizeof(xstr) >= 3) return xstr[1];
	return 0;
	/*
	 * Independent coders and domains: return coder / domain name.
	 */
    case "u":
	if (sizeof(xstr) >= 4) return xstr[2];
	return 0;

	/*
	 * /secure or /bin return root uid.
	 */
    case "secure":
    case "bin":
	return ROOT_UID;

	/*
	 * No cloning or loading from /ftp.
	 */
    case "ftp":
	return 0;
    }
    /*
     * All else: return backbone uid.
     */
    return BACKBONE_UID;
}
