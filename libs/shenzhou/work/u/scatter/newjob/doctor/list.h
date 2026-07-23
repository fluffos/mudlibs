// team list

//以下是成员名单
string *member = ({
        "buwu",
        "april",
        "yujie",
        "jiuer",
        "scatter",
        "ye feng",
        "lisser",
        "lara",
        "xrz",
	"blacko",
	"chun",
        "cac",
	"keny",
        "reader",
	"friends",

});

int is_member(object me)
{
        int i;

        for(i=0; i<sizeof(member); i++)
                if ( me->query("id") == member[i] )     return 1;     
        return 0;
}

