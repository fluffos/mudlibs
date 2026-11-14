/* 
** init() Meldungen                               2001-07-05 Orw@Silberland
**
** Update              Version   Comments
** ------------------------------------------------------------------------
** 0000-00-00            1.0     Release
**
**
*/


#define HALLO_MENSCH  \
 ({ "Hallo, wie gehts " \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"Frau":"Herr") \
    +" Mensch?", \
    "Hi, was fuehrt Dich zu mir, Mensch" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +"?", \
    "Oh, ein" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"e":"") \
    +" Mensch" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"enfrau":"") \
    +"!", \
    "Ich gruesse Dich, Bewohner" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +" von Midas!" });

#define HALLO_ELF \
 ({ "Hallo, wie gehts " \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"Frau":"Herr") \
    +" Elf?", \
    "Hi, was fuehrt Dich zu mir, Elf" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +"?", \
    "Oh, was macht ein" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"e":"") \
    +" Elf" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +" hier, soweit weg von " \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"ihrem":"seinem") \
    +"Volk?", \
    "Ich gruesse Dich, Bewohner" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +" von Elessar!" });

#define HALLO_ZWERG \
 ({ "Hallo, wie gehts " \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"Frau":"Herr") \
    +" Zwerg?", \
    "Hi, was fuehrt Dich zu mir, Zwerg" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +"?", \
    "Oh, ein" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"e":"") \
    +" Zwerg" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +"!", \
    "Ich gruesse Dich, Bewohner" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +" von Felonia!" });

#define HALLO_HOBBIT \
 ({ "Hallo, wie gehts " \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"Frau":"Herr") \
    +" Hobbit?", \
    "Hi, was fuehrt Dich zu mir, Hobbit" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"frau":"") \
    +"?", \
    "Oh, ein" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"e":"") \
    +" Hobbit" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"maedchen":"bursche") \
    +"!", \
    "Ich gruesse Dich, Bewohner" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +" von Derlim!" });

#define HALLO_FEE \
 ({ "Hallo, wie gehts kleine Fee?", \
    "Hi, was fuehrt Dich zu mir, kleine Fee?", \
    "Sei gegruesst, kleine zierliche Fee!", \
    "Hui, was macht eine kleine flatternde Fee hier in dieser Gegend?" });

#define HALLO_DUNKELELF \
 ({ "Hallo, wie gehts " \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"Frau":"Herr") \
    +" Dunkelelf?", \
    "Hi, was fuehrt Dich zu mir, finster" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"e":"er") \
    +" Dunkelelf" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +"?", \
    "Ich gruesse Dich, daemonisch" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"e":"er") \
    +" " \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"Priesterin":"Krieger") \
    +" der Unterwelt!", \
    "Ich gruesse Dich, daemonisch" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"e":"er") \
    +" Bewohner" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +" von Dhrkion!" });

#define HALLO_TROLL \
 ({ "Hallo, wie gehts " \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"Frau":"Herr") \
    +" Troll?", \
    "Hi, was fuehrt Dich zu mir, riesig" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"e":"er") \
    +" Troll" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +"?", \
    "Wow, bist Du gross, " \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"Frau":"Herr") \
    +" Troll!", \
    "Ich gruesse Dich, riesig" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"e":"er") \
    +" Bewohner" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +" des Silbergebirges!" });

#define HALLO_OGER \
 ({ "Hallo, wie gehts " \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"Frau":"Herr") \
    +" Oger?", \
    "Hi, was fuehrt Dich zu mir, hungrig" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"e":"er") \
    +" Oger" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"frau":"") \
    +"?", \
    "Friss mich nicht auf, " \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"Frau":"Herr") \
    +" Oger!", \
    "Ich gruesse Dich, gefraessig" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"e":"er") \
    +" Untertan" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"in":"") \
    +" Grimows!" });

#define HALLO_MY_RACE \
 ({ "Hallo, wie gehts "+TPN+"?", \
    "Hi, was fuehrt Dich zu mir, "+TPN+"?", \
    "Schoen Dich zu sehen, "+TPN+"!", \
    "Oh, "+TPN+" besucht mich!",\
    "Gruess Dich, "+TPN+"!", \
    "Hi, "+TPN+"!", \
    "Hui, da kommt ja "+TPN+"!", \
    "Sei gegruesst, "+TPN+"!", \
    "Was machst Du denn hier, "+TPN+"?", \
    "Hallo, "+TPN+"!" });

#define HALLO_DEFAULT \
 ({ "So Eine" \
    +(((int)this_player()->QueryProp(P_GENDER)==FEMALE)?"":"n") \
    +" wie Dich, hab ich noch nie gesehen! " \
    "Wer oder Was bist Du?" });

