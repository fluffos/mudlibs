
inherit WWW_BASE;

#define FILE(X) read_file(__DIR__+"lpc/"+X+"/chapter"+\
                args["chapter"]+".html")

private string get_content( string, mapping args );

void setup() {
    set_title( mud_name()+" - LPC Manual");
    set_content( (: get_content :) );
} /* setup() */

/** ignore yes */
private varargs string copyright( int y ) {
    return "<hr size=\"1\">\n"
        "<address>\n"
        "Copyright &copy; "+( y ? y+" ": "")+
        "<a href=\"http://www.imaginary.com/~borg\">\n"
        "George Reese</a> (<a href=\"mailto:borg@imaginary.com\">"
        "borg@imaginary.com</a>)\n"
        "</address>\n"
        "<hr size=\"1\">\n";
} /* copyright() */

/** @ignore yes */
private string get_content( string, mapping args ) {
    if( mapp(args) && sizeof(args) ) {
        switch( args["content"] ) {
          case "basic" :
            if( !args["chapter"] )
                return font()+"<h3>LPC Basics</h3>\n"
                    "<p><strong>Written by Descartes of Borg - "
                    "23 April 1993.</strong></p>\n"
                    "<ul>\n"
                    "<li><a href=\"lpc.c?content=basic&chapter=0\">"
                    "Introduction</a>\n"
                    "<li><a href=\"lpc.c?content=basic&chapter=1\">"
                    "Chapter 1: Introduction to the Coding Environment</a>\n"
                    "<li><a href=\"lpc.c?content=basic&chapter=2\">"
                    "Chapter 2: The LPC Program</a>\n"
                    "<li><a href=\"lpc.c?content=basic&chapter=3\">"
                    "Chapter 3: LPC Data Types</a>\n"
                    "<li><a href=\"lpc.c?content=basic&chapter=4\">"
                    "Chapter 4: Functions</a>\n"
                    "<li><a href=\"lpc.c?content=basic&chapter=5\">"
                    "Chapter 5: The Basics of Inheritance</a>\n"
                    "<li><a href=\"lpc.c?content=basic&chapter=6\">"
                    "Chapter 6: Variable Handling</a>\n"
                    "<li><a href=\"lpc.c?content=basic&chapter=7\">"
                    "Chapter 7: Flow Control</a>\n"
                    "<li><a href=\"lpc.c?content=basic&chapter=8\">"
                    "Chapter 8: The Data Type Object</a></ul>\n"+
                    copyright(1993)+
                    "<p><a href=\"lpc.c\">Back to LPC Manual Contents</a>"
                    "</p></font>\n";
            return font()+FILE("basic")+copyright(1993)+
                "<p><a href=\"lpc.c?content=basic\">"
                "Back to Basic LPC Manual Contents</a>\n"
                "</p></font>\n";
          case "intermediate" :
            if( !args["chapter"] )
                return font()+"<h3>Intermediate LPC</h3>\n"
                    "<p><strong>Written by Descartes of Borg - "
                    "November 1993.</strong></p>\n"
                    "<ul>\n"
                    "<li><a href=\"lpc.c?content=intermediate&chapter=1\">"
                    "Chapter 1: Introduction</a>\n"
                    "<li><a href=\"lpc.c?content=intermediate&chapter=2\">"
                    "Chapter 2: The LPMud Driver</a>\n"
                    "<li><a href=\"lpc.c?content=intermediate&chapter=3\">"
                    "Chapter 3: Complex Data Types</a>\n"
                    "<li><a href=\"lpc.c?content=intermediate&chapter=4\">"
                    "Chapter 4: The LPC Pre-Compiler</a>\n"
                    "<li><a href=\"lpc.c?content=intermediate&chapter=5\">"
                    "Chapter 5: Advanced String Handling</a>\n"
                    "<li><a href=\"lpc.c?content=intermediate&chapter=6\">"
                    "Chapter 6: Intermediate Inheritance</a>\n"
                    "<li><a href=\"lpc.c?content=intermediate&chapter=7\">"
                    "Chapter 7: Debugging</a></ul>\n"+
                    copyright(1993)+
                    "<p><a href=\"lpc.c\">Back to LPC Manual Contents</a>"
                    "</p></font>\n";
            return font()+"<p>Intermediate LPC<br>\n"
                "Descartes of Borg<br>\n"
                "November 1993</p>\n"+FILE("intermediate")+copyright(1993)+
                "<p><a href=\"lpc.c?content=intermediate\">"
                "Back to Intermediate LPC Manual Contents</a>\n"
                "</p></font>\n";
          case "advanced" :
            if( !args["chapter"] )
                return font()+"<h3>Advanced LPC</h3>\n"
                    "<p><strong>Written by Descartes of Borg.</strong></p>\n"
                    "<ul>\n"
                    "<li><a href=\"lpc.c?content=advanced&chapter=1\">"
                    "Chapter 1: Introduction</a>\n"
                    "<li><a href=\"lpc.c?content=advanced&chapter=2\">"
                    "Chapter 2: Driver/Mudlib Interaction</a></ul>\n"+
                    copyright(1995)+
                    "<p><a href=\"lpc.c\">Back to LPC Manual Contents</a>"
                    "</p></font>\n";
            return font()+FILE("advanced")+copyright(1995)+
                "<p><a href=\"lpc.c?content=advanced\">"
                "Back to Advanced LPC Manual Contents</a>\n"
                "</p></font>\n";
          default :
        }
    }

    return font()+"<h3>LPC Manuals</h3>\n"
        "<ul>\n"
        "<li><a href=\"lpc.c?content=basic\">Basic Manual</a><br>\n"
        "<li><a href=\"lpc.c?content=intermediate\">Intermediate Manual</a><br>\n"
        "<li><a href=\"lpc.c?content=advanced\">Advanced Manual</a>\n"
        "</ul>\n"+copyright()+
        "<p><a href=\"secure.c\">Back to the Secure Section</a>"
        "</p></font>\n";

} /* get_content() */
