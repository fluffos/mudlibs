/* people.c

 Abbot @ LPUniversity
 14-JULY-2006
 Developer People Command

*/

/*  Last editted by Tacitus on October 4 */
object *addArray( object  *oldarr, object *newarr);
int sortName(object member1, object member2);

int main()
{
    string *sorted_users=({});
    object  *OAdminArr, *ODevArr,*OUserArr;
    object *OUser;

    OUser   = ({});
    OAdminArr = ({});
    ODevArr     = ({});
    OUserArr   = ({});

    printf("%-15s%-10s%-20s%-30s%s\n", "Name:", "Rank:", "IP:", "Location:", "Idle:");
    printf("%-15s%-10s%-20s%-30s%s\n", "-----", "-----", "---", "---------", "-----");

    OUser = users();
    foreach( string name in OUser )
    {
        if (  adminp(  name  ) && name->query_name() != "login" )
            OAdminArr += ({ name });
        else if ( devp(  name  )  )
            ODevArr    += ({ name });
        else 
            OUserArr   += ({ name });
    }

    OAdminArr = sort_array(OAdminArr,"sortName");
    ODevArr    = sort_array(ODevArr,     "sortName");
    OUserArr   = sort_array(OUserArr,   "sortName");

    OUser = ({});
    OUser = addArray(OUser,OAdminArr);
    OUser = addArray(OUser, ODevArr);
    OUser = addArray(OUser, OUserArr);

    foreach(object thisUser in OUser)
    {
        if(environment(thisUser))
            sorted_users += ({thisUser->query_name()});
        else
            printf("%-15s%-10s%-20s%-30s%s\n", "LOGIN", "-", query_ip_number(thisUser),
              "[No Environment]", "-");
    }


    foreach(string thisName in sorted_users)
    {
        object thisUser;
        string thisRank,thisIP,thisEnv,thisIdle;

        thisUser=find_player(thisName);

        if(objectp(environment(thisUser))) thisEnv = file_name(environment(thisUser));
        else thisEnv = "[No Environment]";

        if(adminp(thisUser)) thisRank = "Admin";
        else if(devp(thisUser)) thisRank = "Dev";


        else thisRank = "User";

        thisIdle = ""+query_idle(thisUser)/60;
        thisIP = ""+query_ip_number(thisUser);

        printf("%-15s%-10s%-20s%-30s%s\n", capitalize(thisName), thisRank, thisIP, thisEnv, thisIdle);
    }

    return 1;
}

int sortName(object member1, object member2)
{
    if ( member1->query_name()  > member2->query_name()  )    return 1;
    if ( member1->query_name() < member2->query_name() ) return -1;
    else return 0;
}

object *addArray( object  *oldArr, object *newArr)
{
    foreach( object member in newArr)
        oldArr += ({ member });
    return oldArr;
}

string help()
{
    return(HIW + " SYNTAX: " + NOR + "people\n\n"
      "This command allows you to see all users logged in. They are\n"
      "displayed with their name, rank, ip, location, and minutes of idle\n"
      "time.\n");
}
