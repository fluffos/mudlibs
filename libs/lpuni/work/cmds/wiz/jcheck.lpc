/* jcheck.c

   Scifi@LPUniversity
   Date: August 26, 2006

   Objective: Checks if a journal has been updated 
           and prints the name of the developer.
*/

/*
   Last updated Aug 26, 2006 by Scifi
*/

#define TP this_player()
#define TPC this_player()->query("cwd")
#define TPN this_player()->query("name")
#define JPATH "/doc/journals/"

int main()
{
    string *journarr;
    mapping oldjrnl;
    mapping newjrnl;
    string mypath;
    string name;
    int ctr;
    int nomaas = 0;

    mypath = resolve_path( TPC,"~/");
    mypath = mypath + ".jlo";

    journarr = get_dir("/doc/journals/");

    newjrnl = ([]);

    if(file_exists(mypath)) oldjrnl = restore_variable( read_file(mypath));
    else oldjrnl = ([]);
    
    if(sizeof(oldjrnl) == 0) oldjrnl = ([]);

    //  Check file size diffs.
    for(ctr = 0; ctr<sizeof(journarr);ctr++)
    {
        sscanf(journarr[ctr],"journal.%s",name);
        
        if ( file_size( JPATH+journarr[ctr] ) !=
          oldjrnl[ name ] )

        {
            write(journarr[ctr]+"\n");
            nomaas = 1;
        }
    }

    if (nomaas == 0)
    write("No journals have been updated since the last time you checked.\n");

    // Check for deleted files
    for(ctr = 0; ctr < sizeof(oldjrnl); ctr++)
    {
        if (member_array(sprintf("journal.%s",keys(oldjrnl)[ctr]), journarr)
                ==-1) 
        {
            write ("Journal for "+keys(oldjrnl)[ctr]+" has been deleted\n");
        }
    }

    // saves updated journal sizes

    for(ctr = 0; ctr < sizeof(journarr); ctr++)
    {
        sscanf(journarr[ctr],"journal.%s",name);
        newjrnl[name] = file_size(JPATH+journarr[ctr]);
    }
    write_file(mypath,save_variable(newjrnl),1);

    return 1;
}
string help()
{
    return " %^BOLD%^SYNTAX:%^RESET%^ jcheck\n\n"
    "This cmd will check the /doc/journal directory for any \n"
    "file that has been changed since the last time you've \n"
    "checked.\n";
}

