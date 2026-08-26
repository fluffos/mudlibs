//exists.c

//Tacitus @ LPUniversity
//02-APR-05
//Simul-Efuns

/* Updates:

   30-JUNE-05 Gwegster - added user_exists()
*/

int directory_exists(string dirname)
{
    return (file_size(dirname) == -2);
}

int file_exists(string file)
{
    return (file_size(file) >= 0);
}

int user_exists(string user)
{
        return (file_exists("/data/users/" + user[0..0] + "/" + user + "/" + user + ".o"));
}

