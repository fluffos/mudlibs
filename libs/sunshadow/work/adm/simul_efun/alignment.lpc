/*
** alignment.c
**
** Contains all functions for checking alignment.
**
** -- Tlaloc -- 9.18.21
**
*/

#define SHORT_ALIGN ({ "LG", "LN", "LE", "NG", "TN", "NE", "CG", "CN", "CE" })
#define LONG_ALIGN ({ "Lawful Good", "Lawful Neutral", "Lawful Evil", "Neutral Good", "True Neutral", "Neutral Evil", "Chaotic Good", "Chaotic Neutral", "Chaotic Evil" })

int is_good(object ob)
{
    int align = ob->query_alignment();
    
    if(align == 1 || align == 4 || align == 7)
        return 1;
    
    return 0;
}

int is_neutral(object ob)
{
    int align = ob->query_alignment();
    
    if(align == 2 || align == 5 || align == 8)
        return 1;
    
    return 0;
}

int is_evil(object ob)
{
    int align = ob->query_alignment();
    
    if(align == 3 || align == 6 || align == 9)
        return 1;
    
    return 0;
}

int is_lawful(object ob)
{
    int align = ob->query_alignment();
    
    if(align == 1 || align == 2 || align == 3)
        return 1;
    
   return 0;
}

int is_chaotic(object ob)
{
    int align = ob->query_alignment();
    
    if(align == 7 || align == 8 || align == 9)
        return 1;
    
    return 0;
}

int opposed_alignment(object me, object you)
{
    string *opposed;
    int my_align, your_align;
    
    if(!me || !you)
        return 0;
    
    my_align = me->query_true_align();
    your_align = you->query_true_align();
    
    if(my_align == 5 || your_align == 5)
        return 0;
    
    //If you're the polar opposite
    if(my_align - (10 - your_align) == 0)
        return 2;
    
    opposed = ({ "000", "78936", "789", "78914", "369", "000", "147", "12369", "123", "12347" });
    
    if(strsrch(opposed[my_align], your_align + "") >= 0)
        return 1;
    
    return 0;
}

string *short_alignment(int *align)
{
    string *short_align = ({  });
    
    if(!pointerp(align))
        return ({  });
    
    if(!sizeof(align))
        return ({  });
    
    foreach(int x in align)
        short_align += ({ SHORT_ALIGN[x - 1] });
    
    return short_align;
}

string *long_alignment(int *align)
{
    string *long_align = ({  });
    
    if(!pointerp(align))
        return ({  });
    
    if(!sizeof(align))
        return ({  });
    
    foreach(int x in align)
        long_align += ({ LONG_ALIGN[x - 1] });
    
    return long_align;
}