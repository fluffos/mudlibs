int main(string fac) {
    int factor;
    switch(fac)
    {
    case "EET":
	factor = 0;
	break;
    case "CET":
	factor = -3600;
	break;
    case "GMT":
	factor = -7200;
	break;
    case "AST":
	factor = -21600;
	break;
    case "EST":
	factor = -25200;
	break;
    case "CST":
	factor = -28800;
	break;
    case "MST":
	factor = -32400;
	break;
    case "PST":
	factor = -36000;
	break;
    case "YST":
	factor = -39600;
	break;
    case "ALST":
	factor = -43200;
	break;
    case "BST":
	factor = -46800;
	break;
    default:
	factor = 0;
	break;
    }
    write(ctime((time()+factor))+"\n");
    return 1;
}

query_author ()
{
  return "madrid";
}

query_synopsis ()
{
  return "date [timezone]";
}

query_help ()
{
  return "Will tell you current date. The default timezone is EET "
       + "(Eastern Europe Time) and by specifying timezone you can "
       + "get the date of other timezone. The available timzones "
       + "are: EET, CET, GMT, AST, EST, CST, MST, TST, YST, ALST "
       + "and BST.";
}

query_example ()
{
  return "date CST";
}

query_see_also ()
{
  return "age(1)";
}

query_position ()
{
  return POS_RESTING;
}

