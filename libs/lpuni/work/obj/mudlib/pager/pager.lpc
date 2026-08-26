/* pager.c

 Tacitus @ LPUniversity
 04-NOV-05
 Standard file pager

 Last edited on August 15th by Parthenon

*/

#define DEF_LINESPERCYCLE 20

string *exploded;
function cb;
int currentLine = 0;
int totalLines;
int linesPerCycle = DEF_LINESPERCYCLE;
int myLinesPerCycle;
int ansi = 1;

int page(string data, string title);
int page_more();
int prompt(string arg);

varargs int page(string data, string title, function callback, int no_ansi)
{
    if(!stringp(data)) return 0;
    if(stringp(title)) write("*===| Paging: " + title + " |===*\n\n");
    if(functionp(callback)) cb = callback;
    if(no_ansi) ansi = 0;
    currentLine = 0;

    if(!this_player()->query_env("morelines"))
    myLinesPerCycle = DEF_LINESPERCYCLE;
    else
    myLinesPerCycle = to_int(this_player()->query_env("morelines"));

    linesPerCycle = myLinesPerCycle - 1;

    exploded = explode(data, "\n");
    totalLines = sizeof(exploded);
    page_more();
}

int page_more()
{
    int start, end;

    start = currentLine + 1;

    for(;currentLine < totalLines && currentLine < linesPerCycle; currentLine++)
    message((ansi ? "page" : "ignore_ansi"), exploded[currentLine] + "\n", ({ this_player() }) );

    end = currentLine;

    if(totalLines >= myLinesPerCycle)
    {
        switch(this_player()->query_env("page_display"))
        {
            case "percent" :
                write(HIW + "\n-=-= [" + (currentLine * 100 / totalLines) + "%] =-=-" + NOR + "\n");
                break;
            case "lines" :
            default :
                write(HIW + "\n-=-= [" + start + "-" + end + " of " + totalLines + "] =-=-" + NOR + "\n");
                break;
        }
    }

    if(currentLine < totalLines)
    {    
        input_to("prompt");
        return 1;
    }

    write("\n");
    evaluate(cb);
    destruct(this_object());
    return 1;
}


int prompt(string arg)
{
    switch(arg)
    {
        case "help" :
        case "h" :
        {
            write("\n\t -= File Pager Help =-\n\n");
            write("  h, help     : Display this help\n");
            write("  q, Q        : Quit\n");
            write("  n           : Goto line n\n");
            write("  s, '        : Start over\n\n");
            input_to("prompt");
            return 1;
        }
        case "q" :
        case "Q" :  evaluate(cb);  destruct(this_object()); return 1;
        case "\r" :
        case "\n" :
        case " " :
        case "" :
        case "\n\r" :
        {
            linesPerCycle += myLinesPerCycle - 1;
            break;
        }
        case "s" :
        case "'" :
        {
            write("%^ER_UP");
            linesPerCycle = myLinesPerCycle;
            currentLine = 0;
            break;
        }
        default :
        {
            if(intp(to_int(arg)))
            {
                currentLine = to_int(arg);
                linesPerCycle = to_int(arg) + myLinesPerCycle;
            }
            break;
        }
    }
    
    page_more();
}

void reset()
{
    if(!environment(this_object())) destruct(this_object());
    if(!in_input(environment(this_object()))) destruct(this_object());
}

